 Em março de 2021, como um exercício da disciplina de estrutura de dados, o professor propôs fazermos o jogo Skyliners (2015), uma versão simplificada, para exercitarmos os usos das estruturas pilha e lista.
 
 Este é esse projeto, porém refeito.
 
 As regras do jogo são simples, existem 3 tipos de peças: andar, parque e teto. O objetivo do jogo é conseguir ver o máximo de prédios possíveis de sua perspectiva, local em que se senta na mesa nomeados pelas quatro direções norte, sul, leste e oeste. Andares podem ser colocados um acima do outro com o objetivo de construir os edifícios. Parques só podem ser colocados no chão e andares não podem ser adicionados. Tetos, só podem ser colocados sobre andares e não podem mais receber andares.
 
 Cada edifício contado na vista conta um ponto. Em caso de empate, a prioridade é a ordem do jogo, sul,oeste, norte e leste.
 
 Aqui, para além da estruturas de dados, seguem demonstradas maneiras de generalizar código,simplificação e como a visão matemática contribui para construir a vista na perspectiva de cada jogador usando '#'.
 
 Segue o exemplo do tabuleiro e a vista Sul e Leste:


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

() indica um edifício com um teto
[] indica um parque
Os números representam os andares e/ou os níveis de altura


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


Para desenhar estas vistas podemos pensar em funções do tipo z = u(x,y) tais que dadas as coordenadas no tabuleiro (x,y) temos de volta a altura do edifício nestas coordenadas, z. Assim, a vista na perspectiva do jogador é a sobreposição dos gráficos visto através do plano x0z ou y0z quando fixamos uma das coordenadas e variamos a outra em um dos sentidos(crescendo ou decrescendo os valores). Ilustramos usando o exemplo acima.



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
 
Ainda seguindo a caracterização da nossa função, os pilares feitos  de '# diminuem a espessura conforme se afastam da vista do jogador. O que corrobora com o fenômeno da perspectiva. E isto é incorporado naturalmente na adaptação para o código e na representação de sobreposição proposta.
