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
int PorpecaA(Peca** tab, int l, int c, int peca);

void Render(Peca** tab){


    printf("===============================================================================================\n");
    printf("|                                 jOGADAS DISPONIVEIS                                          |\n");
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
            if(tab[l][i].parque == 0 && tab[l][i].andar == 0)
            {
                printf ("    ");
            }
            else if (tab[l][i].parque == 1) 
            {
                printf ("[ 1]");
            }
            else if (tab[l][i].teto == 1)
            {
                printf("( %d)", tab[l][i].andar);
            }
            else
            {
                printf("  %d ", tab[l][i].andar);
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
        n = PorpecaA(tab, l[i], c[i], 1);
    }

    if (n == 0)
    {
        printf("\n  Não foi possivel por as peças \n");
        exit(1);
    }
    
    


    return tab;
    

}

Jogador** Criarjogadores(int jID, char namej[]) {

    int Id = jID;

    Jogador** jog = (Jogador**) malloc(sizeof(Jogador*));

    if (jog == NULL)
    {
        printf("Não foi possivel alocar memória");
        exit(1);
    }

    (*jog) = (Jogador*) malloc(sizeof(Jogador));

    if ((*jog) == NULL)
    {
        printf("Não foi possivel alocar memória");
        exit(1);
    }

    (*jog)->ID = Id;
    (*jog)->numAndar = 12;
    (*jog)->numParque = 1;
    (*jog)->numTeto = 2;
    (*jog)->name = (char*) namej;
    


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

    (*jog)->pjInicio = parque;

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

            Peca* aux1 = (*jog)->pjInicio;
            Peca* aux2 = (*jog)->pjInicio;

            while (aux2 != NULL)
            {
                aux1 = aux2;
                aux2 = aux1->p;
            }

            aux1->p = nova;

        }
        else if (j > 2)
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

            Peca* aux1 = (*jog)->pjInicio;
            Peca* aux2 = (*jog)->pjInicio;

            while (aux2 != NULL)
            {
                aux1 = aux2;
                aux2 = aux1->p;
            }

            aux1->p = nova;
        }
        
    }

    return jog;
    

}


int PorpecaA(Peca** tab, int c, int l, int peca) 
{

    if(peca <= 0 || peca > 3)
    {
        printf("uso invalido");
        exit(1);
    }

    if (peca == 1)
    {
        if (tab[c][l].parque == 1)
        {
            printf("Movimnto inválido, andares não podem sobrepôr parques\n");
            Sleep(2000);
            return 0;
        }

        if (tab[c][l].teto == 1)
        {
            printf("Movimnto inválido, amadres não podem  sobrepôr tetos\n");
            Sleep(2000);
            return 0;
        }

        if(tab[c][l].p == NULL && tab[c][l].andar == 0)
        {
            tab[c][l].andar = 1;
        }
        else if(tab[c][l].p == NULL && tab[c][l].andar == 1)
        {
            Peca* nova = (Peca*) malloc(sizeof(Peca));
            if (nova == NULL)
            {
                printf("Não fi possivel alocar memoria");
                exit(1);
            }
            
            nova->andar = 1;
            nova->parque = 0;
            nova->teto = 0;
            nova->p = NULL;

            tab[c][l].p = nova;
            tab[c][l].andar++;
        }  
        else
        {
            Peca* nova = (Peca*) malloc(sizeof(Peca));
            if (nova == NULL)
            {
                printf("Não fi possivel alocar memoria");
                exit(1);
            }

            nova->andar = 1;
            nova->parque = 0;
            nova->teto = 0;

            nova->p = tab[c][l].p;
            tab[c][l].p = nova;
            tab[c][l].andar++;
        } 
    }
    else if (peca == 2)
    {
        if (tab[c][l].andar == 0 && tab[c][l].teto == 0)
        {
            tab[c][l].parque = 1;
            tab[c][l].andar = 1;
        }
        else
        {
            printf("Parques só podem ser colocados no chão\n");
            Sleep(2000);
            return 0;
        }
        
    }
    else
    {
        if (tab[c][l].andar > 0 && tab[c][l].parque == 0)
        {
            Peca* nova = (Peca*) malloc(sizeof(Peca));
            if (nova == NULL)
            {
                printf("não foi possivel alocar memoria");
                exit(1);
            }

            nova->andar = 0;
            nova->parque = 1;
            nova->teto = 0;
            
            nova->p = tab[c][l].p;
            tab[c][l].p = nova;
            tab[c][l].andar++; 
            tab[c][l].teto = 1;
        }
        else
        {
            printf("Tetos não podem ser colocados no chão ou em cima de parques");
            return 0;
        }
        
        
    }
    
    
    return 1;

}

int vista (int p, Peca** tab) 
{
    
    char img[20][45];
    int y = 19, x = 0;
    int base = 8;
    int indx, indy;
    int maior = 0;
    int altura;
    int pespec = 0;
    int pontos = 0;

    for (int  i = 0; i < 20; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            img[i][j] = ' ';
        }
        
    }


    if (p == 5)
    {
        indy = 0;
        indx = 4;
    }
    else
    {
        indy = 4;
        indx = 0;

        if (p == 7)
        {
            indy = 0;
            indx = 0;
        }
        else if (p == 6)
        {
            indy = 4;
            indx = 4;
        }
        
        
    }

    if (p == 4 || p == 5)
    {
       
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {

                
                if (maior <  tab[indy][indx].andar)
                {
                   if (maior == 0)
                   {
                       pontos++;
                   }
                   else
                   {
                       pontos--;
                       pontos = pontos + 2;
                   }
                   

                    altura = maior;
                    maior = tab[indy][indx].andar;

                    altura = maior - altura;

                    for (int h = 0; h < altura; h++)
                    {
                        
                        int cont = 0;
                        
                        for (int v = 0; v < pespec; v++)
                        {
                            img[y][x] = ' ';
                            x++;
                            cont++;
                        }

                        for (int l = 0; l < base; l++)
                        {
                            img[y][x] = '#';
                            x++;
                            cont++;
                        }
                        
                        y--;
                        x = x - cont;

                    }
                     
                }

                if (p == 5)
                {
                    if (indx == 0)
                    {
                        indx = 5;
                    }
                    
                    indx--;
                }
                else
                {
                    if (indx == 4)
                    {
                        indx =  -1;
                    }
                    
                    indx++;
                 
                }
                if (pespec < 4)
                {
                    pespec++;
                }
                base = base - 2;
                if (base == 0 )
                {
                    base = 1;
                }
                
                
                
            }

            if (p == 4)
            {
                indy--;
                y = 19;
                x = x + 9;
                maior = 0;
                base = 8;
                pespec = 0;
               
            }
            else
            {
                indy++;
                y = 19;
                x = x + 9;
                maior = 0;
                base = 8;
                pespec = 0;
                
            }
            
            
        }
        
    }
    else
    {
       for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
   
                if (maior <  tab[indy][indx].andar)
                {
                    altura = maior;
                    maior = tab[indy][indx].andar;

                    altura = maior - altura;
                    pontos++;
                   

                    for (int h = 0; h < altura; h++)
                    {
                        
                        int cont = 0;
                        
                        for (int v = 0; v < pespec; v++)
                        {
                            img[y][x] = ' ';
                            x++;
                            cont++;
                        }

                        for (int l = 0; l < base; l++)
                        {
                            img[y][x] = '#';
                            x++;
                            cont++;
                        }
                        
                        y--;
                        x = x - cont;

                    }
                     
                }

                if (p == 6)
                {
                    if (indy == 0)
                    {
                        indy = 5;
                    }
                    
                    indy--;
                }
                else
                {
                    if (indy == 4)
                    {
                        indy =  -1;
                    }
                    
                    indy++;
                 
                }
                if (pespec < 4)
                {
                    pespec++;
                }
                base = base - 2;
                if (base == 0 )
                {
                    base = 1;
                }
                
                
                
            }

            if (p == 7)
            {
                indx++;
                y = 19;
                x = x + 9;
                maior = 0;
                base = 8;
                pespec = 0;
               
            }
            else
            {
                indx--;
                y = 19;
                x = x + 9;
                maior = 0;
                base = 8;
                pespec = 0;
                
            }
            
            
        }
    }
    
    
    

    

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            printf("%c",img[i][j]);
        }
        printf("\n");
        
    }

    printf("-=============================================\n");
    switch (p)
        {
        case 4:
            printf("NORTE ");
            break;
        case 5:
            printf("SUL ");
            break;
        case 6:
            printf("LESTE ");
            break;
        case 7:
            printf("OESTE ");
            break;
        }
    
    Sleep(3000);

    return pontos;
    
}

int FazerJogada (int p, Jogador** jogador,Peca** tab, int c, int l) {

    Peca* aux1 = (*jogador)->pjInicio;
    Peca* aux2 = NULL;

   

    if (p == 1)
    {
        if ((*jogador)->numAndar == 0)
        {
            printf("Você não tem mais dessa peça");
            Sleep(2000);
            return -1;
        }

         if (tab[c][l].parque == 1)
        {
            printf("Movimnto inválido, andares não podem sobrepôr parques\n");
            Sleep(2000);
            return -1;
        }

        if (tab[c][l].teto == 1)
        {
            printf("Movimnto inválido, amadres não podem  sobrepôr tetos\n");
            Sleep(2000);
            return -1;
        }

        if (aux1 != NULL && aux1->andar == 1)
       {
           (*jogador)->pjInicio = aux1->p;
           (*jogador)->numAndar--;
           free(aux1);
           return (*jogador)->numAndar;

       }

       while (aux1 != NULL && aux1->andar != 1)
       {
           aux2 = aux1;
           aux1 = aux2->p;
       }

       aux2->p = aux1->p;


       (*jogador)->numAndar--;
       free(aux1);
       return (*jogador)->numAndar;

         

    }
    else if (p == 2)
    {
        if ((*jogador)->numParque == 0)
        {
            printf("Você não tem mais dessa peça");
            Sleep(2000);
            return  -1;
        }
        if (tab[c][l].andar != 0 && tab[c][l].teto != 0)
        {
            printf("Parques só podem ser colocados no chão\n");
            Sleep(2000);
            return -1;
        }
       if (aux1 !=  NULL && aux1->parque == 1)
       {
           (*jogador)->pjInicio = aux1->p;
           free(aux1);
           (*jogador)->numParque--;
       

          return 1;
       }
        
    }
    else if (p == 3)
    {
        if ((*jogador)->numTeto == 0)
        {
            printf("Você não tem mais dessa peça");
            Sleep(2000);
            return -1;
        }

        if (tab[c][l].andar > 0 && tab[c][l].parque == 1)
        {
            printf("Tetos não podem ser colocados no chão ou em cima de parques");
            return -1;
        }
        

        
        if (aux1 !=  NULL && aux1->teto == 1)
        {
            (*jogador)->pjInicio = aux1->p;

            (*jogador)->numTeto--;
            free(aux1);
            return 1;
        }

        while (aux1 != NULL && (aux1->andar != 1 && aux1->parque != 0 && aux1->teto != 1))
        {
            aux2 = aux1;
            aux1 = aux2->p;
        }

        aux2->p = aux1->p;

        (*jogador)->numTeto--;
        free(aux1);
        return 1;
    }

}

void PrintJ (Jogador** jogador) {



    printf("\n%s\n", (*jogador)->name);
    printf("Andar: %d\n", (*jogador)->numAndar);
    printf("Parque: %d\n", (*jogador)->numParque);
    printf("Teto: %d\n", (*jogador)->numTeto);


}

