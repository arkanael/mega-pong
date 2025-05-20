
# Mega Pong para Sega Genesis

Este é um projeto desenvolvido em c utilizando o Sega Genesis Development Kit (SGDK) para o Sega Genesis/Mega Drive, seguindo o tutorial disponível em [ohsat.com](https://www.ohsat.com/tutorial/megapong/megapong-1/).

## Sobre

Este projeto é um remake do clássico jogo Pong, adaptado para o console Sega Genesis. O objetivo principal é servir como um recurso educacional para aprender os fundamentos do desenvolvimento de jogos com o SGDK (Sega Genesis Development Kit). Ele oferece uma introdução prática às técnicas de programação e aos conceitos essenciais para criar jogos no Sega Genesis.

## Funcionalidades

* Movimentação do paddle do jogador.
* Colisão da bola com as bordas da tela.
* Implementação básica da lógica do jogo.

## Como Construir e Executar

### Pré-requisitos

* SGDK (Sega Genesis Development Kit) instalado e configurado.
* Um ambiente de desenvolvimento compatível com SGDK.

### Construção

1. Clone este repositório:

    ```bash
    git clone <URL do repositório>
    cd mega-pong
    ```

2. Navegue até o diretório do projeto no terminal.

3. Execute o comando `make` para compilar o jogo.

    ```bash
    make
    ```

### Execução

1. Após a compilação, um arquivo ROM (`.bin`) será gerado no diretório `out`.
2. Use um emulador de Sega Genesis (como BlastEm, Gens KMod, ou RetroArch) para executar a ROM.

## Controles

* **Direcional Esquerda/Direita:** Move o paddle do jogador horizontalmente.

## Estrutura do Código

* `src/`: Contém o código fonte do jogo.
  * `main.c`: Arquivo principal que inicializa o jogo e contém o loop principal.
* `res/`: Contém os recursos do jogo, como imagens e tilesets.
* `Makefile`: Arquivo de configuração para o processo de build.

## Créditos

* Tutorial original: [ohsat.com](https://www.ohsat.com/tutorial/megapong/megapong-1/)
* SGDK (Sega Genesis Development Kit)

## Licença

Este projeto está sob a licença MIT. Veja o arquivo `LICENSE` para mais detalhes.