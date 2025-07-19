#include "menu.h"
#include "ui_menu.h"

void Menu::atualizarTemporizador()
{
    // Se o tempo zerar, então volta para a janela de login
    if(segundosRestantes <= 0){
        close();
    }

    // Atualiza temporizador da tela
    int minRestantes = segundosRestantes / 60;
    int segRestantes = segundosRestantes % 60;

    QString tempoRestante = "00:00";

    tempoRestante[0] = QChar('0' + (minRestantes / 10));
    tempoRestante[1] = QChar('0' + (minRestantes % 10));
    tempoRestante[3] = QChar('0' + (segRestantes / 10));
    tempoRestante[4] = QChar('0' + (segRestantes % 10));

    ui->tempo->setText(tempoRestante);

    // Atualiza os segundos restantes da janela de menu
    segundosRestantes--;
}

Menu::Menu(QWidget *parent, QString usuario)
    : QDialog(parent)
    , ui(new Ui::Menu)
    , tempo(nullptr)
    , segundosRestantes(TEMPO_LIMITE) // duracao maxima da sessao: 30 minutos = 60 * 30 = 1800 segundos
{
    this->usuario = usuario;
    ui->setupUi(this);

    // temporizador
    tempo = new QTimer();
    connect(tempo, SIGNAL(timeout()), this, SLOT(atualizarTemporizador()));
    tempo->start(1000);

    // outros
    layout = new QVBoxLayout(ui->WidgetContainer);
    ui->WidgetContainer->setLayout(layout);
    setWindowTitle("Menu");
    setMouseTracking(true); // importante para o temporizador da janela
    ui->stackedWidget->setCurrentIndex(0);
    configurarWidgets();
}

Menu::~Menu()
{
    if(tempo != nullptr){
        delete tempo;
        tempo = nullptr;
    }

    if(layout != nullptr){
        delete layout;
        layout = nullptr;
    }

    delete ui;
}

// implementa o setMaxLenght do QLineEdit no QTextEdit
void Menu::limitarTexto()
{
    auto *edit = qobject_cast<QTextEdit*>(sender());
    if (!edit)
        return;

    const int max = 100;

    QString texto = edit->toPlainText();

    if(texto.size() > max){
        // Apaga tudo que esta alem do tamanho maximo
        texto = texto.left(max);

        // Temporariamente bloquear sinais para evitar loop infinito
        edit->blockSignals(true);
        edit->setPlainText(texto);
        edit->blockSignals(false);

        // move o cursor no fim
        QTextCursor cursor = edit->textCursor();
        cursor.movePosition(QTextCursor::End);
        edit->setTextCursor(cursor);
    }
}

// Configura o widget referente a opcao adicionar conta (AC)
void Menu::configurarAC()
{
    ui->TituloAC->setMaxLength(20);
    ui->TituloAC->setPlaceholderText("Máximo de 20 caracteres.");
    // De acordo com as diretrizes do NIST, uma senha deve ter ate 64 caracteres
    ui->SenhaAC->setMaxLength(64);
    ui->SenhaAC->setPlaceholderText("Máximo de 64 caracteres.");
    // --
    connect(ui->DescricaoAC, SIGNAL(textChanged()), this, SLOT(limitarTexto()));
    ui->DescricaoAC->setPlaceholderText("Máximo de 100 caracteres.");

    // limpo o combo box para caso de atualizar o BD
    ui->TagAC->clear();

    // preenche o combo box com as tags existentes
    ConexaoBD* conexao = ConexaoBD::getInstancia();
    std::vector<QString> tags = conexao->getTags(usuario);
    size_t tam = tags.size();
    for(size_t i = 0; i < tam; i++)
        ui->TagAC->addItem(tags[i]);
}

// Configura o widget referente a opcao editar conta (EC)
void Menu::configurarEC()
{
    ui->TituloEC->setMaxLength(20);
    ui->TituloEC->setPlaceholderText("Máximo de 20 caracteres.");
    // De acordo com as diretrizes do NIST, uma senha deve ter ate 64 caracteres
    ui->SenhaEC->setMaxLength(64);
    ui->SenhaEC->setPlaceholderText("Máximo de 64 caracteres.");
    // --
    connect(ui->DescricaoEC, SIGNAL(textChanged()), this, SLOT(limitarTexto()));
    ui->DescricaoEC->setPlaceholderText("Máximo de 100 caracteres.");

    ConexaoBD* conexao = ConexaoBD::getInstancia();

    // limpo as caixas de texto
    ui->TituloEC->clear();
    ui->SenhaEC->clear();
    ui->DescricaoEC->clear();

    // limpo os combos box's para caso haja atualizacoes no banco de dados
    ui->SelecTituloEC->clear();
    ui->SelecTagEC->clear();
    ui->TagEC->clear();

    // Preencho os combos box's das tags existentes
    ui->SelecTagEC->addItem("Selecione uma tag:");

    std::vector<QString> tags = conexao->getTags(usuario);
    size_t tam = tags.size();
    for(size_t i = 0; i < tam; i++){
        ui->SelecTagEC->addItem(tags[i]);
        ui->TagEC->addItem(tags[i]);
    }

    // Preencho o combo box do titulo das contas
    ui->SelecTituloEC->addItem("Selecione um título de uma conta:");

    std::vector<QString> titulos = conexao->getTituloContas(usuario);
    tam = titulos.size();
    for(size_t i = 0; i < tam; i++){
        ui->SelecTituloEC->addItem(titulos[i]);
    }
}

// Configura o widget referente a opcao remover conta (RC)
void Menu::configurarRC()
{
    ConexaoBD* conexao = ConexaoBD::getInstancia();

    // limpo as caixas de texto
    ui->TituloRC->clear();
    ui->SenhaRC->clear();
    ui->DescricaoRC->clear();
    ui->TagRC->clear();

    // limpo os combos box's para caso haja atualizacoes no banco de dados
    ui->SelecTituloRC->clear();
    ui->SelecTagRC->clear();

    // Preencho o combo box das tags existentes
    ui->SelecTagRC->addItem("Selecione uma tag:");

    std::vector<QString> tags = conexao->getTags(usuario);
    size_t tam = tags.size();
    for(size_t i = 0; i < tam; i++){
        ui->SelecTagRC->addItem(tags[i]);
    }

    // Preencho o combo box do titulo das contas
    ui->SelecTituloRC->addItem("Selecione um título de uma conta:");

    std::vector<QString> titulos = conexao->getTituloContas(usuario);
    tam = titulos.size();
    for(size_t i = 0; i < tam; i++){
        ui->SelecTituloRC->addItem(titulos[i]);
    }
}

// Configura o widget referente a opcao adicionar tag (AT)
void Menu::configurarAT()
{
    ConexaoBD* conexao = ConexaoBD::getInstancia();

    // limpo o combo box para caso haja atualizacoes no banco de dados
    ui->TagsExistentes->clear();
    ui->NomeTagNova->clear();

    // preencho o combo box com as tags existentes
    std::vector<QString> tags = conexao->getTags(usuario);
    size_t tam = tags.size();
    for(size_t i = 0; i < tam; i++)
        ui->TagsExistentes->addItem(tags[i]);
}

// Configura o widget referente a opcao remover tag (RT)
void Menu::configurarRT()
{
    ConexaoBD* conexao = ConexaoBD::getInstancia();

    // limpo o combo box para caso haja atualizacoes no banco de dados
    ui->SelecTagRT->clear();

    // preencho o texto padrao do combo box
    ui->SelecTagRT->addItem("Selecione uma tag");

    // preencho o combo box com as tags existentes
    std::vector<QString> tags = conexao->getTags(usuario);
    size_t tam = tags.size();
    for(size_t i = 0; i < tam; i++)
        ui->SelecTagRT->addItem(tags[i]);
}

void Menu::configurarWidgets()
{
    configurarAC();
    configurarEC();
    configurarRC();
    configurarAT();
    configurarRT();
}

// cria uma senha aleatoria a partir das preferencias do usuario
void Menu::gerarSenha()
{
    QString senha;
    senha.clear();

    // aleatorizacao melhor que rand
    std::random_device rd;
    std::mt19937 gen(rd());

    int numCaracteres = ui->spinBox->value();

    std::string caracteresPossiveis;
    caracteresPossiveis.clear();

    // Monto o alfabeto completo

    if (ui->checkBoxabc->isChecked()) {
        for (char c = 'a'; c <= 'z'; c++) {
            caracteresPossiveis.push_back(c);
        }
    }

    if (ui->checkBoxABC->isChecked()) {
        for (char c = 'A'; c <= 'Z'; c++) {
            caracteresPossiveis.push_back(c);
        }
    }

    if (ui->checkBox123->isChecked()) {
        for (char c = '0'; c <= '9'; c++) {
            caracteresPossiveis.push_back(c);
        }
    }

    if (ui->checkBoxExtras->isChecked()) {
        std::string especiais = "!@#$%^&*()_+-=[]{}<>?";
        caracteresPossiveis += especiais;
    }

    // Verifica se há algo para sortear
    if (caracteresPossiveis.empty()) {
        ui->SenhaGerada->setText("Nenhuma opção selecionada!");
        return;
    }

    // Sorteia os caracteres
    std::uniform_int_distribution<> dis(0, caracteresPossiveis.size() - 1);

    for (int i = 0; i < numCaracteres; i++) {
        char c = caracteresPossiveis[dis(gen)];
        senha.append(QChar(c));
    }

    ui->SenhaGerada->setText(senha);
}

void Menu::mouseMoveEvent(QMouseEvent *event)
{
    segundosRestantes = TEMPO_LIMITE;
}

void Menu::mousePressEvent(QMouseEvent *event)
{
    segundosRestantes = TEMPO_LIMITE;
}

void Menu::keyPressEvent(QKeyEvent *event)
{
    segundosRestantes = TEMPO_LIMITE;
}

void Menu::keyReleaseEvent(QKeyEvent *event)
{
    segundosRestantes = TEMPO_LIMITE;
}

void Menu::on_comboBox_activated(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

// Botao confirmar de adicionar conta (AC)
void Menu::on_BotaoConfirmarAC_clicked()
{
    // Verifico os campos
    if(ui->TituloAC->text().isEmpty()){
        QMessageBox::warning(this, "Erro", "Campo título não preenchido");
        return;
    }
    else if(ui->SenhaAC->text().isEmpty()){
        QMessageBox::warning(this, "Erro", "Campo senha não preenchido");
        return;
    }

    // Verifico se o titulo existe no BD
    ConexaoBD* conexao = ConexaoBD::getInstancia();
    if(conexao->existeTituloConta(usuario, ui->TituloAC->text())){
        QMessageBox::warning(this, "Erro", "Título ja existe em outra conta");
        return;
    }

    // Adiciono no banco de dados
    if(!conexao->adicionarConta(usuario, ui->TituloAC->text(), ui->SenhaAC->text(), ui->DescricaoAC->toPlainText(), ui->TagAC->currentText())){
        QMessageBox::warning
            (
                this,
                "Erro",
                "Não foi possível adicionar conta"
                );
    }
    else{
        QMessageBox::information
            (
                this,
                "Sucesso",
                "Adicionada conta " + ui->TituloAC->text()
                );

        configurarWidgets();
    }
}

// Botao confirmar de editar conta (EC)
void Menu::on_BotaoConfirmaEC_clicked()
{
    // Verifico o comboBox do titulo das contas
    if(ui->SelecTituloEC->currentIndex() <= 0){
        QMessageBox::warning(this, "Erro", "Nenhuma conta foi selecionada");
        return;
    }
    // Verifico os campos obrigatorios
    if(ui->TituloEC->text().isEmpty()){
        QMessageBox::warning(this, "Erro", "Campo título não preenchido");
        return;
    }
    if(ui->SenhaEC->text().isEmpty()){
        QMessageBox::warning(this, "Erro", "Campo senha não preenchido");
        return;
    }

    // altero o BD
    ConexaoBD* conexao = ConexaoBD::getInstancia();
    if(!conexao->editarConta(
        usuario,
        ui->SelecTituloEC->currentText(),
        ui->TituloEC->text(),
        ui->SenhaEC->text(),
        ui->DescricaoEC->toPlainText(),
        ui->TagEC->currentText())){
        QMessageBox::warning(this, "Erro", "Não foi possível editar conta");
    }
    else{
        QMessageBox::information(this, "Sucesso", "Conta editada");
        configurarWidgets();
    }
}

// Botao confirmar de remover conta (RC)
void Menu::on_BotaoConfirmaRC_clicked()
{
    // Verifico o comboBox do titulo das contas
    if(ui->SelecTituloRC->currentIndex() <= 0){
        QMessageBox::warning(this, "Erro", "Nenhuma conta foi selecionada");
        return;
    }

    ConexaoBD* conexao = ConexaoBD::getInstancia();
    if(!conexao->removerConta(usuario, ui->TituloRC->text())){
        QMessageBox::warning(this, "Erro", "Não foi possível remover conta");
    }
    else{
        QMessageBox::information(this, "Sucesso", "Conta removida");
        configurarWidgets();
    }
}


void Menu::on_spinBox_valueChanged(int arg1)
{
    gerarSenha();
}


void Menu::on_checkBoxabc_stateChanged(int arg1)
{
    gerarSenha();
}


void Menu::on_checkBoxABC_stateChanged(int arg1)
{
    gerarSenha();
}


void Menu::on_checkBox123_stateChanged(int arg1)
{
    gerarSenha();
}


void Menu::on_checkBoxExtras_stateChanged(int arg1)
{
    gerarSenha();
}


void Menu::on_toolButton_clicked()
{
    QString senha = ui->SenhaGerada->text();

    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(senha);
}


void Menu::on_toolButton_2_clicked()
{
    QMessageBox::information
    (
        this,
        "Informação",
        "A seleção do número de caracteres tem que ser, no mínimo, 1, e, no máximo, 64."
    );
}


void Menu::on_BotaoConfirmarAT_clicked()
{
    // Verifico campo
    if(ui->NomeTagNova->text().isEmpty()){
        QMessageBox::warning(this, "Erro", "Campo nome da tag não preenchido");
        return;
    }

    // Verifico se a tag existe
    ConexaoBD* conexao = ConexaoBD::getInstancia();
    std::vector<QString> tags = conexao->getTags(usuario);
    size_t tam = tags.size();
    for(size_t i = 0; i < tam; i++){
        if(tags[i] == ui->NomeTagNova->text()){
            QString saida = "Tag " + ui->NomeTagNova->text() + " já existe";
            QMessageBox::warning(this, "Erro", saida);
            return;
        }
    }

    // Adiciono tag no banco de dados e atualizo os widgets afetados pela tag
    if(!conexao->adicionarTag(usuario, ui->NomeTagNova->text())){
        QMessageBox::warning
        (
            this,
            "Erro",
            "Não foi possível adicionar nova tag"
        );
    }
    else{
        QMessageBox::information
        (
            this,
            "Sucesso",
            "Adicionado tag " + ui->NomeTagNova->text()
        );

        configurarWidgets();
    }
}


void Menu::on_BotaoConfirmaRT_clicked()
{
    // Verifico se foi selecionada uma tag
    if(ui->SelecTagRT->currentIndex() <= 0){
        QMessageBox::warning(this, "Erro", "Não foi selecionada uma tag");
        return;
    }

    QString nomeTag = ui->SelecTagRT->currentText();

    // Removo a tag e atualizo os widgets que são afetados por ela
    ConexaoBD* conexao = ConexaoBD::getInstancia();
    if(!conexao->removerTag(usuario, ui->SelecTagRT->currentText())){
        QMessageBox::warning
            (
                this,
                "Erro",
                "Não foi possível remover tag"
                );
    }
    else{
        QMessageBox::information
            (
                this,
                "Sucesso",
                "Removido tag " + nomeTag
                );

        configurarWidgets();
    }
}


void Menu::on_SelecTituloEC_textActivated(const QString &arg1)
{
    if(ui->SelecTituloEC->currentIndex() <= 0){
        ui->TituloEC->clear();
        ui->SenhaEC->clear();
        ui->DescricaoEC->clear();
        return;
    }

    ConexaoBD* conexao = ConexaoBD::getInstancia();

    ui->TituloEC->setText(arg1);
    ui->SenhaEC->setText(conexao->getSenhaConta(usuario, arg1));
    ui->DescricaoEC->setText(conexao->getDescricao(usuario, arg1));
    ui->TagEC->setCurrentText(conexao->getTag(usuario, arg1));
}


void Menu::on_SelecTituloRC_textActivated(const QString &arg1)
{
    if(ui->SelecTituloRC->currentIndex() <= 0){
        ui->TituloRC->clear();
        ui->SenhaRC->clear();
        ui->DescricaoRC->clear();
        ui->TagRC->clear();
        return;
    }

    ConexaoBD* conexao = ConexaoBD::getInstancia();

    ui->TituloRC->setText(arg1);
    ui->SenhaRC->setText(conexao->getSenhaConta(usuario, arg1));
    ui->DescricaoRC->setText(conexao->getDescricao(usuario, arg1));
    ui->TagRC->setText(conexao->getTag(usuario, arg1));
}


void Menu::on_SelecTagMC_textActivated(const QString &arg1)
{
    ui->SelecTagMC->clear();
    ui->SelecTagMC->addItem("Selecione um título de uma conta:");

    ConexaoBD* conexao = ConexaoBD::getInstancia();
    std::vector<Conta> contas;

    // Texto padrao, entao sem filtro
    if(ui->SelecTagMC->currentIndex() <= 0){
        contas = conexao->getContas(usuario);
    }
    // filtro os titulos com a tag selecionada
    else{
        contas = conexao->getContas(usuario, arg1);
    }

    // mostro as contas com o titulo selecionado

    // mas antes devo deletar as contas que ja foram incluidas no layout anteriormente
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr)
    {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater(); // remove da ui e agenda para destruição segura
        }
        delete item; // remove o layout item em si
    }

    // incluio as novas contas selecionadas
    size_t tam = contas.size();
    for(int i = 0; i < tam; i++)
        layout->addWidget(new ContaWidget(contas[i], this));
}


void Menu::on_SelecTagEC_textActivated(const QString &arg1)
{
    // Seguranca
    ui->TituloEC->clear();
    ui->SenhaEC->clear();
    ui->DescricaoEC->clear();
    ui->TagEC->clear();

    ui->SelecTituloEC->clear();
    ui->SelecTituloEC->addItem("Selecione um título de uma conta:");

    ConexaoBD* conexao = ConexaoBD::getInstancia();
    std::vector<QString> titulos;

    // Texto padrao, entao sem filtro
    if(ui->SelecTagEC->currentIndex() <= 0){
        titulos = conexao->getTituloContas(usuario);
    }
    // filtro os titulos com a tag selecionada
    else{
        titulos = conexao->getTituloContas(usuario, arg1);
    }

    size_t tam = titulos.size();
    for(size_t i = 0; i < tam; i++)
        ui->SelecTituloEC->addItem(titulos[i]);
}


void Menu::on_SelecTagRC_textActivated(const QString &arg1)
{
    // Seguranca
    ui->TituloRC->clear();
    ui->SenhaRC->clear();
    ui->DescricaoRC->clear();
    ui->TagRC->clear();

    ui->SelecTituloRC->clear();
    ui->SelecTituloRC->addItem("Selecione um título de uma conta:");

    ConexaoBD* conexao = ConexaoBD::getInstancia();
    std::vector<QString> titulos;

    // Texto padrao, entao sem filtro
    if(ui->SelecTagRC->currentIndex() <= 0){
        titulos = conexao->getTituloContas(usuario);
    }
    else{
        // filtro os titulos com a tag selecionada
        titulos = conexao->getTituloContas(usuario, arg1);
    }

    size_t tam = titulos.size();
    for(size_t i = 0; i < tam; i++)
        ui->SelecTituloRC->addItem(titulos[i]);
}

