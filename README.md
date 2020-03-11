# Rastros
Rastros game built in C

Projeto desenvolvido no âmbito da unidade curricular Laboratórios de Informática II do curso de 
Engenharia Informática da Universidade do Minho.

## Etapas de desenvolvimento:
- [x] Guião 1
- [x] Guião 2
- [x] Guião 3
- [x] Guião 4
- [x] Guião 5
### Relatório Guião 5  

Tendo por base as orientações definidas pelos docentes, a realização do guião 5 consistiu nas seguintes fases:
#### 1. Estrutura do projeto
   - __Camada de dados;__
     - Declarou-se o tipo ```enum CASA``` que serve para atribuir o estado _{ Vazio, Branca ou Preta }_ a cada ```CASA``` do tabuleiro.
     - ```struct COORDENADA``` que contém a linha e coluna (representada numa matriz);
     - ```struct JOGADA``` contem duas COORDENADAs. Representando o jogador1 e jogador2;
     - ```struct ESTADO``` que contém:
       - o tabuleiro do jogo (array bidimensional de ```CASA```);
       - ```COORDENADA``` última jogada;
       - ```JOGADAS``` array de JOGADA - é-lhe atribuido o histório de jogadas;
       - ```int``` número de jogadas efetuadas até ao momento;
       - ```int``` jogador que irá efetuar a jogada;
       - ```BOT``` dados do tipo ```enum { NO, YES } BOT``` permite definir se está a jogar contra um BOT;
       - ```int``` nível do jogo no caso de se encontrar a jogar contra BOT.
   - __Lógica do programa;__
     - Nesta camada, pode-se encontrar as funções que são utilizadas pelo interpretador:
       - ```int jogar (ESTADO *state, COORDENADA c)```
         - Efetua uma jogada: atualiza o estado do programa utilizando a coordenada indicada.
         - Comando: coordenada ##
       - ```int gravarJogo (ESTADO *state, char *nomeFicheiro)```
         - Grava o estado do jogo num determinado ficheiro nomeFicheiro.
         - Comando: ```gr nome_do_ficheiro```
       - ```int lerJogo (ESTADO *e, char *nomeFicheiro)```
         - Lê o estado de um jogo a partir de um ficheiro nomeFicheiro.
         - Comando: ```ler nome_do_ficheiro```
       - ```int lerMovimentos (ESTADO *e)```
         - Apresenta os movimentos do jogo.
         - Comando: ```movs```
       - ```void mostraPos(ESTADO *state, char *pos)```
         - Imprime o tabuleiro numa determinada altura _pos_ do jogo.
         - Comando: ```pos posicao_desejada```
   - __Camada de interface.__
     - Interpretador
       - Módulo que permite ao utilizador interagir com o programa através de comandos pré-definidos.
       - Os comandos possíveis encontram-se descritos no ponto anterior.
#### 2. Desenvolvimento
Por forma a otimizar a relação do programador com o programa, começou-se por definir alguns **macros**.
Para tal, criou-se um módulo designado *globals*. Posteriormente, criou-se uma pasta *modules*.
Dentro desta, pode-se encontrar os **módulos** que trazem funcionalidade ao programa. 
Estes estão em conformidade com a estrutura do projeto apresentada, sendo os seguintes:
- Interface;
- Lógica;
- Interpretador.  

A maior dificuldade ocorreu durante esta fase inicial do projeto, 
em que se procurou definir a melhor hierarquia de ficheiros possível que permitisse criar módulos facilmente reutilizáveis
e fácil de efetuar *debugging*.


- [x] Guião 6
- [ ] Guião 7
- [ ] Guião 8


## Informação sobre os autores

### Turno Prático
PL6

### Autores:  
- **_62608_** __Marco António Gonçalves de Sousa__  
- **_93271_** __José Alberto Ferreira Malheiro__  
- **_93198_** __Mariana Rocha Marques__
