 Em março de 2021, como um exercício da disciplina de estrutura de dados, o professor propôs fazermos o jogo Skyliners (2015), uma versão simplificada, para exercitarmos os usos das estruturas pilha e lista.
 
 Este é esse projeto, porém refeito.
 
 As regras do jogo são simples, existem 3 tipos de peças: andar, parque e teto. O objetivo do jogo é conseguir ver o máximo de prédios possíveis de sua perspectiva, local em que se senta na mesa nomeados pelas quatro direções norte, sul, leste e oeste. Andares podem ser colocados um acima do outro com o objetivo de construir os edifícios. Parques só podem ser colocados no chão e andares não podem ser adicionados. Tetos, só podem ser colocados sobre andares e não podem mais receber andares.
 
 Cada edifício contado na vista conta um ponto. Em caso de empate, a prioridade é a ordem do jogo, sul,oeste, norte e leste.
 
 Aqui, para além da estruturas de dados, seguem demonstradas maneiras de generalizar código,simplificação e como a visão matemática contribui para construir a vista na perspectiva de cada jogador usando '#'.
 
 Segue o exemplo do tabuleiro e a vista Sul e Leste:
 
>In March 2021, as an exercise for the data struct class, the teacher proposed that we make the game Skyliners (2015), a simplified version, to exercise the data structures stack and list.
 
>This is that project, but redone
 
>The rules are simple, and there are 3 types of pieces: floor(andar), park(parque) and roof(teto). The goal of the game is to see as many buildings as possible from your perspective, the place where you sit at the table named by the four directions norte, sul, leste and oeste. Floors can be put on top of each other to build the buildings. Parks only can be put on the ground and it can not receive any floor on the top. Roof can only be put on top of the floor and it can no longer receive  floors anymore.
 
>Each build in the view counts as a score. In case of draw, the priority is by the gaming order and it is sul,oeste, norte e leste.
 
>Here, beyond the data structure, are shared ways to generalize code and simplify and more importantly  how the mathematical perspective helps to build each player's perspective view using '#' caractere.

>Here is an example of the board and the Sul and Leste views:


```


                 Norte
         +----+----+----+----+----+
         |( 7)|  4 |    |    |  2 | a
         +----+----+----+----+----+
         |    |  1 |    |  1 |    | b
         +----+----+----+----+----+
  Oeste  |[ 1]|  2 |[ 1]|  1 |    | c  Leste
         +----+----+----+----+----+
         |    |  1 |  4 |  2 |    | d
         +----+----+----+----+----+
         |  2 |    |  1 |    |  1 | e
         +----+----+----+----+----+
            1    2    3    4    5
                   Sul



() indica um edifício com um teto    /*() indicates a building with a roof */

[] indica um parque                  /*[] indicates a park */

Os números representam os andares e/ou os níveis de altura   

/*The numbers represents how many floors the build has and/or how high it is.*/


SUL:


     ###
     ###
     ###
     ###        ##     ########
     ###        ##     ########
 ###########  ######   ########  ########     ##
 ########### ######## ########## ######## ##########        
============================================================
10 pontos /*score*/

LESTE:





                                                            
                                                    ###
                                                    ###     
                                                    ###
                    ######                         #####    
                    ######                         #####
            ##     ########    ####             ########### 
        ########## ########  ########  ######## ###########
============================================================
9 pontos /*score*/

```

Para desenhar estas vistas podemos pensar em funções do tipo z = u(x,y) tais que dadas as coordenadas no tabuleiro (x,y) temos de volta a altura do edifício nestas coordenadas, z. Assim, a vista na perspectiva do jogador é a sobreposição dos gráficos visto através do plano x0z ou y0z quando fixamos uma das coordenadas e variamos a outra em um dos sentidos(crescendo ou decrescendo os valores). Ilustramos usando o exemplo acima.

>To draw these views we can think about functions of the type of z = u(x,y) such that given x and y, coordinates of the board, we have a building's height in those coordinates, z.  Therefore, the view from the player perspective is the overlay of graphs of the function seen through the x0z plane or y0z plane when we fix one of the variables(or coordinates)and vary the other  in a linear way(increase or decrease the values). We illustrate this using the example above.

```

 y                Norte
 ^       +----+----+----+----+----+
 |       |( 7)|  4 |    |    |  2 | a
 |       +----+----+----+----+----+
 |       |    |  1 |    |  1 |    | b        
 |       +----+----+----+----+----+
 | Oeste |[ 1]|  2 |[ 1]|  1 |    | c  Leste
 |       +----+----+----+----+----+
 |       |    |  1 |  4 |  2 |    | d
 |       +----+----+----+----+----+
 |       |  2 |    |  1 |    |  1 | e
 |       +----+----+----+----+----+
 |            1    2    3    4    5
 |                  Sul
 |
 -------------------------------------> x



SUL:


     ###
     ###
     ###
     ###        ##     ########
     ###        ##     ########
 ###########  ######   ########  ########     ##
 ########### ######## ########## ######## ##########        
============================================================
10 pontos

Vista x0z sobrepondo os gráficos para cada x dado fixo e variando y de 0 a 5

/* View x0z by overlaying the graphs for each fixed x and varying y from 0 to 5 */

LESTE:





                                                            
                                                    ###
                                                    ###     
                                                    ###
                    ######                         #####    
                    ######                         #####
            ##     ########    ####             ########### 
        ########## ########  ########  ######## ###########
============================================================
9 pontos
Vista y0z sobrepondo os gráficos para cada y dado fixo e variando x de 5 a 0.

/* View y0z by overlaying the graphs for each fixed x and varying y from 5 to 0 */

```
 
Ainda seguindo a caracterização da nossa função, os pilares feitos  de '#' diminuem a espessura conforme se afastam da vista do jogador. O que corrobora com o fenômeno da perspectiva. E isto é incorporado naturalmente na adaptação para o código e na representação de sobreposição proposta. O jogo acaba na rodada em que um dos jogadores zera o número de andares disponíveis para ele.

>Still in a characterization of our function, the pillars made of '#' who form our buildings , decrease in thickness as they move away from the player's view. What agree with the perspective phenomenon. And this is incorporated naturally into the adaptation to the code and the proposed overlay representation. The game ends in the round in which one of the players resets the number of floors available to him.
