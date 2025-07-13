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
    setWindowTitle("Menu");
    setMouseTracking(true); // importante para o temporizador da janela
    ui->stackedWidget->setCurrentIndex(0);
    configurarAC();
}

Menu::~Menu()
{
    if(tempo != nullptr){
        delete tempo;
        tempo = nullptr;
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
}

// Configura o widget referente a opcao adicionar conta (AC)
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

    // preencho o combo box com as tags existentes
    std::vector<QString> tags = conexao->getTags(usuario);
    size_t tam = tags.size();
    for(size_t i = 0; i < tam; i++)
        ui->TagsExistentes->addItem(tags[i + 1]);
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
}

// Botao confirmar de editar conta (EC)
void Menu::on_BotaoConfirmaEC_clicked()
{
    // Verifico o comboBox do titulo das contas
    if(ui->SelecTituloEC->currentIndex() == 0){
        QMessageBox::warning(this, "Erro", "Nenhuma conta foi selecionada");
        return;
    }
    // Verifico os campos
    if(ui->TituloAC->text().isEmpty()){
        QMessageBox::warning(this, "Erro", "Campo título não preenchido");
        return;
    }
    else if(ui->SenhaAC->text().isEmpty()){
        QMessageBox::warning(this, "Erro", "Campo senha não preenchido");
        return;
    }
}

// Botao confirmar de remover conta (RC)
void Menu::on_BotaoConfirmaRC_clicked()
{
    // Verifico o comboBox do titulo das contas
    if(ui->SelecTituloEC->currentIndex() == 0){
        QMessageBox::warning(this, "Erro", "Nenhuma conta foi selecionada");
        return;
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

    // Adiciono tag no banco de dados e atualizo os widgets afetados pela tag
    ConexaoBD* conexao = ConexaoBD::getInstancia();
    if(!conexao->adicionarTag(usuario, ui->NomeTagNova->text())){
        QMessageBox::warning
        (
            this,
            "Erro",
            "Não foi possível adicionar nova tag. \nTente novamente mais tarde."
        );
    }
    else{
        QMessageBox::information
        (
            this,
            "Sucesso",
            "Adicionado tag " + ui->NomeTagNova->text()
        );

        configurarAT();
        configurarAC();
        configurarEC();
        configurarRT();
    }
}


void Menu::on_BotaoConfirmaRT_clicked()
{
    // Verifico se foi selecionada uma tag
    if(ui->SelecTagRT->currentIndex() == 0){
        QMessageBox::warning(this, "Erro", "Não foi selecionada uma tag");
        return;
    }


}

