# 🗝️ Gerenciador de Senhas

Sistema que permite guardar senhas em um cofre seguro com criptografia e função hash.

## 🔧 Tecnologias utilizadas

- C++ (com Qt 6)
- SQLite (armazenamento local)
- Libsodium (criptografia simétrica e hash seguro)

## 🔒 Segurança

- A **senha principal** (usada para abrir o cofre) é **hasheada**.
- As **senhas das contas** são **criptografadas**.
- Todas as credenciais são armazenadas em **SQLite** de forma segura.

---

## 🚀 Como compilar e executar no Windows 64 bits

### 📦 Requisitos

- **Qt 6.9.0** com o kit **MinGW 13.1.0 64-bit**
- **CMake 3.31.5 ou superior**
- **MinGW** incluso no kit ou instalado separadamente

### 📥 Passo a passo de compilação

1. Crie a pasta `libsodium` na raiz do projeto.
   - Exemplo: `C:\Gerenciador_de_senhas\libsodium`
2. Baixe a versão:  
   [libsodium-1.0.18-mingw.tar.gz](https://download.libsodium.org/libsodium/releases/)
3. Extraia o conteúdo da pasta `libsodium-win64` e copie os arquivos para a pasta `libsodium` criada acima.
4. Abra o **terminal do Qt** e execute os seguintes comandos:

```bash
cd C:\Gerenciador_de_senhas
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
windeployqt Gerenciador_de_senhas.exe
Gerenciador_de_senhas.exe
```

Após isso, será possível executar o gerenciador diretamente pelo .exe ou pelo QtCreator via "cmakelist.txt".
