#include <iostream>

using namespace std;

int main() {
 int alunos, matricula,produtos, qtd, qtdp=0, ganhador, qtdl=0;
 float promocao, preco=0, comp=0, mult, res, desconto, compant;

for(alunos=10;alunos>=1; alunos--){
  cout << "\nDigite sua matrícula: \n";
  cin >> matricula; 
ganhador = matricula;
  if(matricula>0){

    cout << "\nGanhou a promoção dos 10 primeiros\n";
    promocao = 10;
  }
   do{
     cout << "Digite o código do seu produto: \n";
     cin >> produtos;

   if(produtos>0){
      cout << "Digite o preço unitario do produto:\n";
      cin >> preco;

      cout << "Digite quantos produtos você levara:\n";
     cin >> qtd;
     res = mult;
     mult = qtd*preco;
     qtdp++;
     if(qtdp>1){
     comp= res + mult;
     }else{
       comp = mult;
     }
   }

 }while(produtos>0);

if(comp>=50){
     cout << "Ganhou a promocao dos 50\n"; 
     promocao =20;
     desconto = comp * 0.2;
      compant = desconto;
   }else{
     desconto = comp*0.1;
      compant = desconto;
   }
    if(desconto > compant ){
     ganhador= matricula;
}
 cout << "O valor total da compra foi: " << comp << " Seu desconto para a proxima compra sera de " << desconto << " reais\n";
 cout << "\nCompra finalizada com sucesso\n";
 mult=0;
 res=0;
 
  }

  cout <<"A matricula do aluno que ganhou maior desconto foi: " << ganhador;
}
