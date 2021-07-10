# Trabalho-1
Repositório contendo as especificações do Trabalho 1 da disciplina de LP1

# Documento de Especificação

Leia o documento de especificação contido em [Especificação do Trabalho 1](https://docs.google.com/document/d/1nwQxiP9YQzU3O-H4YQMqWRtylqO1AOke8y1rQF7cPEc/edit?usp=sharing). Preencha o autor.md com as informações relativas ao grupo/autor.

# Como compilar

Para compilar o projeto, primeiramente você deve criar um arquivo para compilação, criaremos o arquivo build no qual guardaremos o projeto compilado usando os seguintes comandos:

```
mkdir build
cd build
cmake ..
cmake --build .
```

# Como executar

A compilação gera um executável com o nome KenoGame dentro da pasta build, __no windows__ esse executável fica na pasta Debug. Logo após a compilação, para executar o programa gerado com um arquivo qualquer use os comandos:

No linux:
```
./KenoGame CaminhoDoArquivo/nomeDoArquivo.dat
```
No windows:
```
.\Debug\KenoGame.exe CaminhoDoArquivo\nomeDoArquivo.dat
```

# Como executar com os arquivos de testes

Para executar com os arquivos de testes pre-feitos, basta usar os comandos:

No linux:
```
./KenoGame ../data/nomeDoArquivoTeste.dat
```
No windows:
```
.\Debug\KenoGame.exe ..\data\nomeDoArquivoTeste.dat
```

Os arquivos testes disponíveis e seus comportamentos esperados são:
ap_inv.dat -> faz uma aposta de valor zero, esperando uma mensagem de aposta inválida
empate.dat -> roda um jogo aonde o jogador não ganha nem perde
ganha.dat -> roda um jogo aonde o jogador ganha
mu_num.dat -> faz a escolha de spots maior do que o permitido(15) e recebe a mensagem de número de spots maior do que o máximo
num_rep.dat -> faz a escolha de um número repetido e recebe a mensagem de número repetido
perde.dat -> roda um jogo aonde o jogador perde

Todos os arquivos que emitem uma mensagem de erro acima citados encerram o jogo ao imprimir a mensagem

# Limitações ou funcionalidades não implementadas

Primeiramente o programa não organiza os resultados de forma crescente ou decrescente o que pode dificultar a visualização do jogador sobre o jogo, também não há nenhum tratamento de erro se por um acaso o arquivo não for enviado da forma correta ou se for enviado com um caractere estranho