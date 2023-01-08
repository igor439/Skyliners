#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

typedef struct peca Peca;
typedef struct jogador Jogador;

void Render( Peca** tab);
Jogador** Criarjogadores();
Peca** Init(void);
int PorpecaA(Peca** tab, int l, int c, int tipo, Peca* peca);
int vista (int vista, Peca** tab);
int FazerJogada (Jogador** jogadores,Peca** tab, int l, int c, int tipo, int jgRef);
void PrintJ (Jogador** jogador, int ref);
#endif