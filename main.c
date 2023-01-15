#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include <windows.h>
#include <ctype.h> 
#include <string.h>
#include"jogo.h"


int main(){

    bool jogando = true;
    int jogadordadez = 0;
    int ganhar = -2;
    int fimDeRodada = -2;
    char jogada;
    char esperar;
    Peca** tab = init();
    Jogador** jg =  criarjogadores();


    
    

   while (jogando)
   {

        if(jogadordadez == 4){
            jogadordadez = 0;
        }

        

        system("cls");
    
        render(tab);
        PrintJ(jg,jogadordadez,tab);

        printf("\n");
      
        printf("Qual sua jogada? ");
        jogada = getchar();

        



        switch (jogada - 48)
        {
            case 0:
                jogando = false;
                break;

            case 1:

                

                if(!(ganhar = validarJogada(jg,tab,jogada - 48,jogadordadez))){
                    jogadordadez++;
                }

                if(ganhar == -1 && fimDeRodada == -2){
                    fimDeRodada = 3;
                    jogadordadez++;
              
                }
                else if(ganhar == -1 && fimDeRodada != -2){
                    jogadordadez++;
                }

                if(fimDeRodada == jogadordadez - 1){
                    jogando = false;
                    system("cls");
                    render(tab);
                    
                    break;
                        
                }
            
            
                break;

            case 2:


               
               if(!validarJogada(jg,tab,jogada - 48,jogadordadez)){
                    jogadordadez++;
                }

                if(fimDeRodada == jogadordadez - 1){
                    system("cls");
                    render(tab);
                    jogando = false;
                    break;
                        
                }


                break;

            case 3:

                if(!validarJogada(jg,tab,jogada - 48,jogadordadez)){
                    jogadordadez++;
                }

                if(fimDeRodada == jogadordadez - 1){
                    jogando = false;
                    system("cls");
                    render(tab);
                    break;
                        
                }


                break;

            case 4:
            
                vista(jogada - 48, tab);
                while((esperar=getchar()) != EOF && esperar != '\n');
                getchar();
                break;
                

            case 5:
                vista (jogada - 48, tab);
                while((esperar=getchar()) != EOF && esperar != '\n');
                getchar();
                break;

            case 6:
                vista(jogada - 48, tab);
                while((esperar=getchar()) != EOF && esperar != '\n');
                getchar();
                break;

            case 7:
                vista(jogada - 48, tab);
                while((esperar=getchar()) != EOF && esperar != '\n');
                getchar();
                break;
            
            default:
                
                break;
        }

     
            

       
        
    }

    vencedor(jg,tab);

    
   

}


