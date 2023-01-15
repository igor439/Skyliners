#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

typedef struct peca Peca;
typedef struct jogador Jogador;

void render( Peca** tab);
Jogador** criarjogadores();
Peca** init(void);
int vista (int vista, Peca** tab);
int validarJogada(Jogador** jogadores,Peca** tab, int jogada, int jogadordadez);
void PrintJ (Jogador** jogadores, int jgRef, Peca** tab);
void vencedor (Jogador** jogador, Peca** tab);

#endif