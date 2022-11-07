#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include <windows.h>
#include <string.h>
#include"jogo.h"



int main(){

    bool start = true;
    char check;

    Peca** tab = Init();

    
    Jogador** jog1 = Criarjogadores(0,"norte");
    Jogador** jog2 = Criarjogadores(1, "sul");
    Jogador** jog3 = Criarjogadores(2, "leste");
    Jogador** jog4 = Criarjogadores(3, "oeste");
   

 

    Jogador** rodada[4];
    rodada[0] = jog1; //norte
    rodada[1] = jog4; //oeste
    rodada[2] = jog2; //sul
    rodada[3] = jog3; //leste


    

    int p = 0, temp, r = 0, finish = -2;
    bool vez = false;

    while (start)
    {
       

        if( r > 3 && !vez)
        {
            r = 0;
        }

        if (finish == r)
        {
            break;
        }

        system("cls");
        Render(tab);

        PrintJ(rodada[r]);

        char check[2];
        int len = 0;
        int p1 = 1;
        bool validn = true;

        while (validn)
        {
            printf("Escolha uma jogada: ");
            scanf("%s",check);

            
            
            if (check[0] > 0 && check[1] == 0)
            {
                p = check[0] - '0';
                if(p >= 0 && p <= 7)
                {
                    validn = false;
                }

            }
            else
            {
                printf("Escolha uma jogada valida\n");
                check[1] = '\n';
                validn = true;
            }
                
        }
       
        
        





        if( p == 0)
        {
            break;
        }

        char xy[4];
        xy[3] = '\n';
        int x, y, valid = 0;
        bool con = true;

        if(p <= 3) 
        {
            while (valid != 1)
            {
                /* code */
            
            
                while (con)
                {
                    printf("Escolha a coordenada ");
                    scanf("%s",xy);
                    x = xy[0] - '0';
                    y = xy[1];

                    
                    
                    if ((x > 0 && x < 6) && xy[3] == '\n' && ((y > 64 && y < 70) || (y > 96 && y < 102)))
                    {
                        con = false;
                    }
                    else
                    {
                        printf("As coodenadas devem ter dois caracteres com numero de 1 a 5 seguido de uma letra 'a' a 'e'  2\n");
                        xy[3] = '\n';
                        con = true;
                    }
                        
                }
            
                int c, peca;
                if(y > 64 && y < 70)
                {
                    c = y - 65;
                } 
                else
                {
                    c = y - 97;
                }


                x = x - 1;
            
                valid = FazerJogada(p,rodada[r],tab,x,c);
                if (valid == -1)
                {
                    con = true;
                }

                if (valid > 0)
                {
                    valid = PorpecaA(tab, x, c, p);
                    system("cls");
                    Render(tab);
                    vez = false;
                    r++;
                }
                else if (p == 1 && valid == 0) 
                {
                    valid = PorpecaA(tab, x, c, p);
                    if (valid == 0)
                    {
                        con = true;
                    }
            
                    system("cls");
                    Render(tab);
                    if (finish == -2)
                    {
                        finish = r;
                    }
                    vez = false;
                    r++;
                }
            
            }
                
                
                    
                    
                
                
        

        }
        else
        {
            system("cls");
            vista (p, tab);
            vez = true;
        }

        
    }

    int ranking[4][4];
    int points[4];
    int win = 0;
    int emp[2] = {0, 0};
    int cont = 0;
    int comp = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ranking[i][j] = 0;
        }
        
    }

    for (int i = 4; i <= 7; i++)
    {
        points[cont] = vista (i, tab);
        printf("pontos = %d",points[cont]);
        cont++;
    }
    
    for (int i = 0; i < 4; i++)
    {
        comp = points[i];
        ranking[i][i] = 0;


        for (int j = i + 1; j < 4; j++)
        {
            if (comp > points[j])
            {
                ranking[i][j] = 1;
            }
            else if (comp < points[j])
            {
                ranking[i][j] = 0;
                ranking[j][i] = 1;
            }
            else
            {
                ranking[i][j] = 0;
            }
            
            
        }
        
    }


    for (int i = 0; i < 4; i++)
    {
        win = 0;

        for (int j = 0; j < 4; j++)
        {
            win = win + ranking[i][j];
        }

        points[i] = win;
        
    }

   

    comp = points[0];
    cont = 0;
    for (int i = 1; i < 4; i++)
    {
        if (comp < points[i])
        {
            win = i;
        }
        else if (comp == points[i])
        {
            emp[cont] = i;
            cont++;
            emp[cont] = comp; 
        }
        
        comp = points[i];
        
    }

    if (emp[0] != 0 && (emp[0] >= win))
    {
        win = emp[0] + emp[1];

        if (win == 2 || win == 1)
        {
            vista(4,tab);
            printf("Vencedor: NORTE");
        }
        else if (win == 4 || win == 5)
        {
            vista(7,tab);
            printf("Vencedor: OESTE");
        }
        else if (win == 3 && (emp[0] == 0 || emp[1] == 0))
        {
            vista(4,tab);
            printf("Vencedor: NORTE");
        }
        else if (win == 3 && (emp[0] == 2 || emp[1] == 2))
        {
            vista(5,tab);
            printf("Vencedor: SUL");
        }
        else
        {
            vista(6,tab);
            printf("Vencedor: LESTE");
        }
        
        
    }
    else
    {
        switch (win)
        {
        case 0:
            vista(4,tab);
            printf(" é o vencedor");
            break;
        case 1:
            vista(5,tab);
            printf("é o vencedor");
            break;
        case 2:
            vista(6,tab);
            printf("é o vencedor");
            break;
        case 3:
            vista(7,tab);
            printf("é o vencedor");
            break;
        }
        
    }
    
    
    
    
    
    



}
