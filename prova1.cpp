#include <iostream>
using namespace std;

int main() {
  char comeco; // variavel para iniciar o jogo
  int jogadaA, jogadaB;
  int pontoA=0, pontoB=0;

  // Abertura do jogo
   cout << "-----Vamos jogar Pedra Papel e Tesoura-----\n";
   cout<<"              Vamos começar?\n";
   cout << "--------------------------------------------\n";
   cout << "         Digite s(sim) ou n(nao):\n";
   cin >> comeco;
   
  switch(comeco){
   
   case 's':
   //O usuario quer jogar
   cout << "Vamos comecar\n";
   
  //Selecionando a jogada do primeiro jogador 
  cout << "Jogador A digite sua jogada(pedra-0, papel-1, tesoura-2)\n";
  cin >> jogadaA;

  //Selecionando a jogada do segundo  jogador 
  cout << "Jogador B digite sua jogada(pedra-0, papel-1, tesoura-2)\n";
  cin >> jogadaB;

  if((jogadaB!=0 && jogadaB!=1 && jogadaB!=2)|| (jogadaA!=0 && jogadaA!=1 && jogadaA!=2)){
    
    cout << "Jogada invalida reinicie o jogo\n";
      // primeira partida
  }else{
    //jogada A = pedra, jogada B = papel
   if(jogadaA==0 && jogadaB==1){
      cout << "Jogador B ganhou\n";
      pontoA += 10;
      pontoB -= 1;
      cout << "\nPontos do jogador A: " << pontoA;
      cout << "\nPontos do jogador B: " << pontoB;
   }else{
     //jogada A = pedra, jogada B = tesoura
     if(jogadaA==0 && jogadaB==2){
        cout << "Jogador A ganhou\n";
        pontoA -=1;
        pontoB +=10;
        cout << "\nPontos do jogador A: " << pontoA;
        cout << "\nPontos do jogador B: " << pontoB;
     }else{
      //jogada A = pedra, jogada B = pedra 
       if(jogadaA==0 && jogadaB==0){
         cout <<"Empate";
        pontoA -=5;
        pontoB -=5;
        cout << "\nPontos do jogador A: " << pontoA;
        cout << "\nPontos do jogador B: " << pontoB;
       }else{
         //jogada A = papel , jogada B =  tesoura
         if(jogadaA==1 && jogadaB==2){
          cout << "Jogador B ganhou";
          pontoA-=1;
          pontoB+=10;
          cout << "\nPontos do jogador A: " << pontoA;
          cout << "\nPontos do jogador B: " << pontoB;
         }else{
            //jogada A = papel , jogada B =  tesoura
           if(jogadaA==1 && jogadaB==1){
               cout <<"Empate";
               pontoA -=5;
               pontoB -=5;
               cout << "\nPontos do jogador A: " << pontoA;
              cout << "\nPontos do jogador B: " << pontoB;
           }else{
              //jogada A = papel , jogada B =  tesoura
             if(jogadaA==2 && jogadaB==2){
                cout <<"Empate";
               pontoA -=5;
               pontoB -=5;
               cout << "\nPontos do jogador A: " << pontoA;
              cout << "\nPontos do jogador B: " << pontoB;
             }else{
               //jogada A = papel, jogada B = 0
               if(jogadaA==1 && jogadaB==0){
               cout << "Jogador B ganhou\n";
               pontoA += 10;
               pontoB -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
                //jogada A = papel, jogada B = tesoura
               if(jogadaA==1 && jogadaB==2){
               cout << "Jogador B ganhou\n";
               pontoB += 10;
               pontoA -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
               if(jogadaA==3 && jogadaB==3){
                cout <<"Empate";
               pontoA -=5;
               pontoB -=5;
               cout << "\nPontos do jogador A: " << pontoA;
              cout << "\nPontos do jogador B: " << pontoB;
              }else{
                //jogada A = papel, jogada B = tesoura
               if(jogadaA==1 && jogadaB==2){
               cout << "Jogador B ganhou\n";
               pontoB += 10;
               pontoA -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
               if(jogadaA==2 && jogadaB==0){
               cout << "Jogador B ganhou\n";
               pontoB += 10;
               pontoA -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
               if(jogadaA==1 && jogadaB==0){
               cout << "Jogador A ganhou\n";
               pontoA += 10;
               pontoB -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
                if(jogadaA==2 && jogadaB==1){
               cout << "Jogador A ganhou\n";
               pontoA += 10;
               pontoB -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }
           }
         }
           }
         }
       }
     }
   }
  }
     cout<<"\n------------------------------------------\n";
     cout << "\nVamos para a segunda rodada\n";

 //Selecionando a jogada do primeiro jogador 
  cout << "Jogador A digite sua jogada(pedra-0, papel-1, tesoura-2)\n";
  cin >> jogadaA;

  //Selecionando a jogada do segundo  jogador 
  cout << "Jogador B digite sua jogada(pedra-0, papel-1, tesoura-2)\n";
  cin >> jogadaB;

      if((jogadaB!=0 && jogadaB!=1 && jogadaB!=2)|| (jogadaA!=0 && jogadaA!=1 && jogadaA!=2)){
    
    cout << "Jogada invalida reinicie o jogo\n";
      // segunda partida
  }else{
    //jogada A = pedra, jogada B = papel
   if(jogadaA==0 && jogadaB==1){
      cout << "Jogador B ganhou\n";
      pontoA += 10;
      pontoB -= 1;
      cout << "\nPontos do jogador A: " << pontoA;
      cout << "\nPontos do jogador B: " << pontoB;
   }else{
     //jogada A = pedra, jogada B = tesoura
     if(jogadaA==0 && jogadaB==2){
        cout << "Jogador A ganhou\n";
        pontoA -=1;
        pontoB +=10;
        cout << "\nPontos do jogador A: " << pontoA;
        cout << "\nPontos do jogador B: " << pontoB;
     }else{
      //jogada A = pedra, jogada B = pedra 
       if(jogadaA==0 && jogadaB==0){
         cout <<"Empate";
        pontoA -=5;
        pontoB -=5;
        cout << "\nPontos do jogador A: " << pontoA;
        cout << "\nPontos do jogador B: " << pontoB;
       }else{
         //jogada A = papel , jogada B =  tesoura
         if(jogadaA==1 && jogadaB==2){
          cout << "Jogador B ganhou";
          pontoA-=1;
          pontoB+=10;
          cout << "\nPontos do jogador A: " << pontoA;
          cout << "\nPontos do jogador B: " << pontoB;
         }else{
           if(jogadaA==1 && jogadaB==1){
               cout <<"Empate";
               pontoA -=5;
               pontoB -=5;
               cout << "\nPontos do jogador A: " << pontoA;
              cout << "\nPontos do jogador B: " << pontoB;
           }else{
             if(jogadaA==2 && jogadaB==2){
                cout <<"Empate";
               pontoA -=5;
               pontoB -=5;
               cout << "\nPontos do jogador A: " << pontoA;
              cout << "\nPontos do jogador B: " << pontoB;
             }else{
                //jogada A = papel, jogada B = tesoura
               if(jogadaA==1 && jogadaB==2){
               cout << "Jogador B ganhou\n";
               pontoB += 10;
               pontoA -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
               if(jogadaA==3 && jogadaB==3){
                cout <<"Empate";
               pontoA -=5;
               pontoB -=5;
               cout << "\nPontos do jogador A: " << pontoA;
              cout << "\nPontos do jogador B: " << pontoB;
              }else{
                //jogada A = papel, jogada B = tesoura
               if(jogadaA==1 && jogadaB==2){
               cout << "Jogador B ganhou\n";
               pontoB += 10;
               pontoA -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
               if(jogadaA==2 && jogadaB==0){
               cout << "Jogador B ganhou\n";
               pontoB += 10;
               pontoA -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
               if(jogadaA==1 && jogadaB==0){
               cout << "Jogador A ganhou\n";
               pontoA += 10;
               pontoB -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
                if(jogadaA==2 && jogadaB==1){
               cout << "Jogador A ganhou\n";
               pontoA += 10;
               pontoB -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }
           }
            }
            }
         }
       }
     }
   }
  }
    cout<<"\n-------------------------------------------\n";
    cout << "Vamos para a terceira rodada\n";
     //Selecionando a jogada do primeiro jogador 
  cout << "Jogador A digite sua jogada(pedra-0, papel-1, tesoura-2)\n";
  cin >> jogadaA;

  //Selecionando a jogada do segundo  jogador 
  cout << "Jogador B digite sua jogada(pedra-0, papel-1, tesoura-2)\n";
  cin >> jogadaB;

      if((jogadaB!=0 && jogadaB!=1 && jogadaB!=2)|| (jogadaA!=0 && jogadaA!=1 && jogadaA!=2)){
    
    cout << "Jogada invalida reinicie o jogo\n";
      // segunda partida
  }else{
    //jogada A = pedra, jogada B = papel
   if(jogadaA==0 && jogadaB==1){
      cout << "Jogador B ganhou\n";
      pontoA += 10;
      pontoB -= 1;
      cout << "\nPontos do jogador A: " << pontoA;
      cout << "\nPontos do jogador B: " << pontoB;
   }else{
     //jogada A = pedra, jogada B = tesoura
     if(jogadaA==0 && jogadaB==2){
        cout << "Jogador A ganhou\n";
        pontoA -=1;
        pontoB +=10;
        cout << "\nPontos do jogador A: " << pontoA;
        cout << "\nPontos do jogador B: " << pontoB;
     }else{
      //jogada A = pedra, jogada B = pedra 
       if(jogadaA==0 && jogadaB==0){
         cout <<"Empate";
        pontoA -=5;
        pontoB -=5;
        cout << "\nPontos do jogador A: " << pontoA;
        cout << "\nPontos do jogador B: " << pontoB;
       }else{
         //jogada A = papel , jogada B =  tesoura
         if(jogadaA==1 && jogadaB==2){
          cout << "Jogador B ganhou";
          pontoA-=1;
          pontoB+=10;
          cout << "\nPontos do jogador A: " << pontoA;
          cout << "\nPontos do jogador B: " << pontoB;
         }else{
           //jogada A =papel, jogada B = papel
           if(jogadaA==1 && jogadaB==1){
               cout <<"Empate";
               pontoA -=5;
               pontoB -=5;
               cout << "\nPontos do jogador A: " << pontoA;
              cout << "\nPontos do jogador B: " << pontoB;
           }else{
             //jogada A = tesoura, jogada B = tesoura
             if(jogadaA==2 && jogadaB==2){
                cout <<"Empate";
               pontoA -=5;
               pontoB -=5;
               cout << "\nPontos do jogador A: " << pontoA;
              cout << "\nPontos do jogador B: " << pontoB;
             }else{
               //jogada A = pedra, jogada B = pedra
               if(jogadaA==0 && jogadaB==0){
                cout <<"Empate";
               pontoA -=5;
               pontoB -=5;
               cout << "\nPontos do jogador A: " << pontoA;
              cout << "\nPontos do jogador B: " << pontoB;
              }else{
                //jogada A = papel, jogada B = tesoura
               if(jogadaA==1 && jogadaB==2){
               cout << "Jogador B ganhou\n";
               pontoA += 10;
               pontoB -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
               //jogada A = tesoura, jogada B = pedra
               if(jogadaA==2 && jogadaB==0){
               cout << "Jogador B ganhou\n";
               pontoB += 10;
               pontoA -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
               //jogada A = papel, jogada B = pedra
               if(jogadaA==1 && jogadaB==0){
               cout << "Jogador A ganhou\n";
               pontoA += 10;
               pontoB -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }else{
               //jogada A = tesoura, jogada B = papel
                if(jogadaA==2 && jogadaB==1){
               cout << "Jogador A ganhou\n";
               pontoA += 10;
               pontoB -= 1;
               cout << "\nPontos do jogador A: " << pontoA;
               cout << "\nPontos do jogador B: " << pontoB;
             }
           }
         }
       }
     }
   }
  }

  

   break;

   case 'n':
   // O usuario nao quer jogar
   cout << "Que pena, nos vemos na proxima";

   system("PAUSE");
   break;

   default:
   cout <<"Opcao invalida";
   }
  }
  }
   }
  }
  }
}
  }
  }
}
}
  }
  }
}
 if(pontoA > 0 && pontoB > 0){
     cout << "\nAs duas pontuacoes sao positivas";
   }else{
     if(pontoA < 0 && pontoB < 0){
       cout << "\nAs duas pontuacoes sao negativas";
     }else{
       if(pontoA > 0 && pontoB < 0){
         cout << "\nA pontuacao do jogador A eh positiva e ado jogador B eh negativa";
       }else{
         if(pontoA < 0 && pontoB > 0){
         cout << "\nA pontuacao do jogador B eh positiva e ado jogador A eh negativa";
       }
     }
   }
  }
  }
}