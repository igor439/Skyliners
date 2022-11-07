#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

typedef struct peca Peca;
typedef struct jogador Jogador;
typedef struct Jogador** JogadorPP;

void Render( Peca** tab);
Jogador** Criarjogadores(int jID, char name[]);
Peca** Init(void);
int PorpecaA(Peca** tab, int l, int c, int peca);
int vista (int p, Peca** tab);
int FazerJogada (int p, Jogador** jogador,Peca** tab, int c, int l);
void PrintJ (Jogador** jogador);
#endif