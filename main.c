#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include <windows.h>
#include <string.h>
#include"jogo.h"



int main(){

    Peca** tab = Init();

    Render(tab);

    Jogador** jg =  Criarjogadores();
    
    PrintJ(jg,0);

    printf("==========================NORTE========================");
    printf("\n");
    vista (4,tab);
    printf("\n");

    printf("==========================SUL========================");
    printf("\n");
    vista (5,tab);


}
