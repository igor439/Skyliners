#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include "jogo.h"

struct peca
{
    int andar;
    int teto;
    int parque;
    
    Peca* p;
};


struct jogador
{
    int ID;
    int numAndar;
    int numParque;
    int numTeto;
    char* name;
    Peca* pjInicio;
};


Peca** Init(void);

int PorpecaA(Peca** tab, int l, int c, int tipo, Peca* peca);

void Render(Peca** tab){


    printf("===============================================================================================\n");
    printf("|                                 JOGADAS DISPONIVEIS                                          |\n");
    printf("|  1 : Andar   2 : Parque    3 : Teto                                                          |\n");
    printf("|  4 : Visão Norte    5 : Visão Sul      6 : Visão Leste     7 : Visão Oeste               |\n");
    printf("|                                                                                              |\n");
    printf("|  0 : Sair do jogo                                                                            |\n");
    printf("===============================================================================================\n");


    
    printf ("         ");
    printf ("          Norte\n");
    
    
    for (int i = 0; i < 5; i++)
    {
        printf ("         ");
        printf ("+");
        
        for (int j = 0; j < 5; j++)
        {
            printf ("----");
            if (j % 5 == 0);
            {
                printf ("+");
            }
	    }
        
        printf ("\n");
        if (i == 2)
        {
            printf ("  Oeste  ");
            printf ("|");
        }
        else
        {
            printf ("         ");
            printf ("|");
        }
        
        
        for (int l = 0; l < 5; l++)
        {
            if(tab[i][l].parque == 0 && tab[i][l].andar == 0)
            {
                printf ("    ");
            }
            else if (tab[i][l].parque == 1) 
            {
                printf ("[ 1]");
            }
            else if (tab[i][l].teto == 1)
            {
                printf("( %d)", tab[i][l].andar);
            }
            else
            {
                printf("  %d ", tab[i][l].andar);
            }	
            
            if (l % 5 == 0);
            {
                printf ("|");
            }
        }
        
        //letras do lado direito do tabuleiro
        
        printf (" %c", i + 97);
        if (i == 2)
        {
            printf ("  Leste  ");
        }
        printf ("\n");
    }
    
    // ultima linha do tabuleiro
    printf ("         ");
    printf ("+");
    
    for (int j = 0; j < 5; j++)
    {
        printf ("----");
        if (j % 5 == 0);
        {
            printf ("+");
        }
    }
    
    //numeros de baixo do tabuleiro
    printf ("\n");
    printf ("           ");
    
    for (int j = 0; j < 5; j++)
    {
        printf (" %d  ", j + 1);
        if (j % 5 == 0);
        {
            printf (" ");
        }
    }
    
    printf ("\n");
    printf ("         ");
    printf ("          Sul\n");


}

Peca** Init(void) {
    
    Peca** tab = (Peca**) malloc(5*sizeof(Peca*));

    if (tab == NULL)
    {
        printf("Não fo posivel alocar memória");
        exit(1);
    }
    

    for (int i = 0; i < 5; i++)
    {
        tab[i] = (Peca*) malloc(5*sizeof(Peca));

        if (tab[i] == NULL)
        {
            printf("Não foi possivel alocar memória");
            exit(1);
        }

        for (int j = 0; j < 5; j++)
        {
            tab[i][j].parque = 0;
            tab[i][j].teto = 0;
            tab[i][j].andar = 0;
            tab[i][j].p = NULL;
        }
        


        
    }

    tab[2][2].parque = 1;
    tab[2][2].andar = 1;



    srand(time(NULL));

    int l[6];
    int c[6];

    for (int i = 0; i < 6; i++)
    {
        int x =  rand() % 4;
        if (x > 0) 
        {
            l[i] = x;
        }
        else
        {
            l[i] = 1;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        int x =  rand() % 4;
        if (x > 0) 
        {
            c[i] = x;
        }
        else
        {
            c[i] = 1;
        }

        if(c[i] == 2 && l[i] == 2)
        {
            while (c[i] == 2 || c[i] == 0)
            {
                c[i] = rand() % 4;
            }
            
        }
    }
    int n;
    for (int i = 0; i < 6; i++)
    {
        Peca* nova = (Peca*) malloc(sizeof(Peca));

        if (nova == NULL)
        {
            printf("Não foi possivel alocar memoria");
            exit(1);
        }
            

        nova->andar = 1;
        nova->teto = 0;
        nova->parque = 0;
        nova->p = NULL;
        
        n = PorpecaA(tab, l[i], c[i], 1, nova);
    }

    if (n == 0)
    {
        printf("\n  Não foi possivel por as peças \n");
        exit(1);
    }
    
    


    return tab;
    

}
// Atualçiaza os parametros no jogo.h
Jogador** Criarjogadores() {

    char **jgNomes = (char**) malloc(4*sizeof(char*));
    jgNomes[0] = "Sul";
    jgNomes[1] = "Oeste";
    jgNomes[2] = "Norte";
    jgNomes[3] = "Leste";

    Jogador** jog = (Jogador**) malloc(4*sizeof(Jogador*));

    if (jog == NULL)
    {
        printf("Não foi possivel alocar memória");
        exit(1);
    }

    for (int i = 0; i < 4; i++){

        jog[i] = (Jogador*) malloc(sizeof(Jogador));

        if (jog[i] == NULL)
        {
            printf("Não foi possivel alocar memória");
            exit(1);
        }

        (jog[i])->numAndar = 12;
        (jog[i])->numParque = 1;
        (jog[i])->numTeto = 2;
        (jog[i])->name = jgNomes[i];
    
        


        Peca* parque = (Peca*) malloc(sizeof(Peca));

        if (parque == NULL)
        {
            printf("Não foi possivel alocar memória");
            exit(1);
        }  

        parque->parque = 1;
        parque->andar = 0;
        parque->teto = 0;
        parque->p = NULL;

        (jog[i])->pjInicio = parque;

        for (int j = 0; j < 14; j++)
        {
            if (j < 2)
            {
                Peca* nova = (Peca*) malloc(sizeof(Peca));

                if (nova == NULL)
                {
                    printf("Não foi possivel alocar memoria");
                    exit(1);
                }
                    

                nova->andar = 0;
                nova->teto = 1;
                nova->parque = 0;
                nova->p = NULL;

                Peca* aux1 = (jog[i])->pjInicio;
                Peca* aux2 = (jog[i])->pjInicio;

                while (aux2 != NULL)
                {
                    aux1 = aux2;
                    aux2 = aux1->p;
                }

                aux1->p = nova;

            }
            else if (j >= 2)
            {
                Peca* nova = (Peca*) malloc(sizeof(Peca));

                if (nova == NULL)
                {
                    printf("Não foi possivel alocar memoria");
                    exit(1);
                }
                    

                nova->andar = 1;
                nova->teto = 0;
                nova->parque = 0;
                nova->p = NULL;

                Peca* aux1 = (jog[i])->pjInicio;
                Peca* aux2 = (jog[i])->pjInicio;

                while (aux2 != NULL)
                {
                    aux1 = aux2;
                    aux2 = aux1->p;
                }

                aux1->p = nova;
            }
            
        }

    }
    

    return jog;
    

}


int PorpecaA(Peca** tab, int l, int c, int tipo, Peca* peca ) 
{

    if(tipo <= 0 || tipo > 3)
    {
        printf("uso invalido");
        exit(1);
    }

    if (tipo == 1 && peca->andar == 1)
    {
        if (tab[l][c].parque == 1)
        {
            printf("Movimnto inválido, andares não podem sobrepôr parques\n");
            Sleep(2000);
            return 0;
        }

        if (tab[l][c].teto == 1)
        {
            printf("Movimnto inválido, andares não podem  sobrepôr tetos\n");
            Sleep(2000);
            return 0;
        }

        if(tab[l][c].p == NULL)
        {
                
            tab[l][c].andar = 1;
            tab[l][c].p = peca;

        }
        else if(tab[l][c].p != NULL)
        {
            Peca* aux1 = tab[l][c].p;
            Peca* aux2 = tab[l][c].p;

            while (aux2 != NULL)
            {
                aux1 = aux2;
                aux2 = aux1->p;
            }

            aux1->p = peca;
            tab[l][c].andar++;
        } 
    }
    else if (tipo == 2 && peca->parque == 1)
    {
        if (tab[l][c].andar == 0 && tab[l][c].teto == 0)
        {
            tab[l][c].parque = 1;
            tab[l][c].andar = 1;
            tab[l][c].p = peca;
        }
        else
        {
            printf("Parques só podem ser colocados no chão\n");
            Sleep(2000);
            return 0;
        }
        
    }
    else if (tipo == 3 && peca->teto == 1)
    {
        if (tab[l][c].andar > 0 && tab[l][c].parque == 0)
        {


            Peca* aux1 = tab[l][c].p;
            Peca* aux2 = tab[l][c].p;

            while (aux2 != NULL)
            {
                aux1 = aux2;
                aux2 = aux1->p;
            }

            aux1->p = peca;
                        
            tab[l][c].teto = 1;
            tab[l][c].andar++; 

        }
        else
        {
            printf("Tetos não podem ser colocados no chão ou em cima de parques");
            return 0;
        }
        
        
    }
    else{
        
        printf("Peça e jogada não se correspondem, falha de implementação");
    }

    
    return 1;

}


void torre(char ** grafico,  int pontos, int pespectiva, int fatiaA, int fatiaB){

    int corretor = 0;

    corretor = pontos;
    if (corretor >= 5){
        corretor = 4;
    }

    
    
    for (int i = 0; i < corretor; i++){
        
        for(int j = fatiaA + pespectiva; j <= fatiaB - pespectiva; j++){

            grafico[i][j] = '#';
        }

    
    }

   
    
}


int vista (int vista, Peca** tab) 
{





    char** grafico;

    grafico = malloc(5*sizeof(char*));

    if(grafico ==  NULL){
        printf("não foi poddivel alocar memoria");
        exit(1);
    }


    

    for (int i = 0; i < 5; i++){

        grafico[i] = malloc(60*sizeof(char));

        if(grafico[i] ==  NULL){
        printf("não foi poddivel alocar memoria");
        exit(1);
        }

        for (int j = 0; j < 60; j++){
            grafico[i][j] = ' ';
        }
    }


    int fatiaA = 1;
    int fatiaB = 11;


    if(vista == 4){

        for (int i = 0; i < 5; i++){

            int maior = 0;

            for (int j = 0; j < 5; j++){


                if( maior < tab[j][i].andar){

                    

                    maior = tab[j][i].andar;
                    torre(grafico,maior,j, fatiaA ,fatiaB);
                    
                    

                }

                


            }


            fatiaA = fatiaB + 1;
            fatiaB = fatiaB + 10;
            
         

        }

    }else if (vista == 5){




        for (int i = 0; i < 5; i++){

            int maior = 0;

            for (int j = 4; j >= 0; j--){


                if( maior < tab[j][i].andar){

                    

                    maior = tab[j][i].andar;
                    
                    torre(grafico,maior,4-j, fatiaA ,fatiaB);
                    
                    

                }

                


            }


            fatiaA = fatiaB + 1;
            fatiaB = fatiaB + 10;
            
         

        }




    }
    else if(vista == 6){


        for (int i = 0; i < 5; i++){

            int maior = 0;

            for (int j = 4; j >= 0; j--){


                if( maior < tab[i][j].andar){

                    

                    maior = tab[i][j].andar;
                    
                    torre(grafico,maior,4-j, fatiaA ,fatiaB);
                    
                    

                }

                


            }


            fatiaA = fatiaB + 1;
            fatiaB = fatiaB + 10;
            
         

        }


    }
    else if(vista == 7){

        for (int i = 0; i < 5; i++){

            int maior = 0;

            for (int j = 0; j < 5; j++){


                if( maior < tab[i][j].andar){

                    

                    maior = tab[i][j].andar;
                    
                    torre(grafico,maior,j, fatiaA ,fatiaB);
                    
                    

                }

                


            }


            fatiaA = fatiaB + 1;
            fatiaB = fatiaB + 10;
            
         

        }

    }


    if(vista == 6 || vista == 4){

        for (int i = 4; i >= 0; i--){

        
            for (int j = 60; j >= 0; j--){
                printf( "%c", grafico[i][j]);
            }
            
            printf("\n");
        }


    }
    else{

        for (int i = 4; i >= 0; i--){

        
            for (int j = 0; j < 60; j++){
                printf( "%c", grafico[i][j]);
            }
            
            printf("\n");
        }


    }
    
    

    for (int j = 0; j < 60; j++){
        printf( "=");
    }

  







}

void PrintJ (Jogador** jogadores, int jgRef){

    printf("\n%s\n", (jogadores[jgRef])->name);
    printf("Andar: %d\n", (jogadores[jgRef])->numAndar);
    printf("Parque: %d\n", (jogadores[jgRef])->numParque);
    printf("Teto: %d\n", (jogadores[jgRef])->numTeto);


}

int FazerJogada (Jogador** jogadores,Peca** tab, int l, int c, int tipo, int jgRef){

    if (jgRef < 0 && jgRef > 3){
        printf("Uso inválido,jogador ref incorreta");
        exit(1);
    }

    if (tipo == 1){

        if(jogadores[jgRef]->numAndar == 0)
        {
            printf("Jogador não possui a peça");
            return 1;
        }

        Peca* jgPecaRef = jogadores[jgRef]->pjInicio;
        Peca* jgPecaRefAux = jgPecaRef;

        while (jgPecaRefAux->andar != 1)
        {
            jgPecaRef = jgPecaRefAux;
            jgPecaRefAux = jgPecaRef->p;
            

        }


        if (jgPecaRefAux->p == NULL){
            jgPecaRef->p = NULL;
            PorpecaA(tab, l, c, tipo, jgPecaRefAux);
        }
        else{

            jgPecaRef->p = jgPecaRefAux->p;
            jgPecaRefAux->p == NULL;
            PorpecaA(tab, l, c, tipo, jgPecaRefAux);

        }
    

    }
    else if (tipo ==  2){


        if(jogadores[jgRef]->numTeto == 0)
        {
            printf("Jogador não possui a peça");
            return 1;
        }

        Peca* jgPecaRef = jogadores[jgRef]->pjInicio;
        Peca* jgPecaRefAux = jgPecaRef;

        while (jgPecaRefAux->teto != 1)
        {
            jgPecaRef = jgPecaRefAux;
            jgPecaRefAux = jgPecaRef->p;
            

        }


        if (jgPecaRefAux->p == NULL){
            jgPecaRef->p = NULL;
            PorpecaA(tab, l, c, tipo, jgPecaRefAux);
        }
        else{

            jgPecaRef->p = jgPecaRefAux->p;
            jgPecaRefAux->p == NULL;
            PorpecaA(tab, l, c, tipo, jgPecaRefAux);

        }

    }
    else{

        if(jogadores[jgRef]->numTeto == 0)
        {
            printf("Jogador não possui a peça");
            return 1;
        }

        Peca* jgPecaRef = jogadores[jgRef]->pjInicio;
        Peca* jgPecaRefAux = jgPecaRef;

        while (jgPecaRefAux->teto != 1)
        {
            jgPecaRef = jgPecaRefAux;
            jgPecaRefAux = jgPecaRef->p;
            

        }


        if (jgPecaRefAux->p == NULL){
            jgPecaRef->p = NULL;
            PorpecaA(tab, l, c, tipo, jgPecaRefAux);
        }
        else{

            jgPecaRef->p = jgPecaRefAux->p;
            jgPecaRefAux->p == NULL;
            PorpecaA(tab, l, c, tipo, jgPecaRefAux);

        }

    }

}