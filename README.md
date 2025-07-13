<h1>Gerenciador_de_senhas</h1>

<p>Sistema que permite guardar senhas em um cofre seguro com criptografia e função hash.</p> <br>
<p>Baseado em C e C++ principalmente.</p><br>
<p>
  Compilado via QtCreator 16.0.1 (community) com Qt 6.9.0.<br>
  Informações sensíveis como senha principal (que acessa o cofre) e senhas de subcontas (guardadas no cofre) são hasheadas e criptografadas respectivamente.<br>
  Dados são registrados no Banco de Dados SQLite.<br>
  Função hash e criptografia simétrica são importados da biblioteca externa libsodium.<br>
</p>

<h2>Desafios atuais:</h2>
<ul>
  <li>Terminar as funções do gerenciador;
  <li>Permitir uso multiusuário;
</ul>
