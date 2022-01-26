/*
OBS: A partir da linha 348 é mais ctr c e ctrl v para fazer as 4 pessoas, o resto do código é uma réplica 
da primeira linha até a 348, só mudam as variáveis para fazer o registro

Questão : Na Escola Agrícola de Judiaí foi criada uma sorveteria e está com a necessidade
de conseguir gerenciar melhor suas vendas, com isso foi feito um pedido a coordenação de informática
parar criar um sistema para fazer esse gerenciamento das vendas,a coordenação propôs este desafio
a um aluno (você), sobre a orientação da porfessora Alessandra para desenvolver este sistema,
com isso você deverá desenvolver este sistema para fazer o registro das vendas da sorveteria, 
contendo o nome do comprador, nome do curso, sua matricula, se o comprador não for aluno 
informar o cargo, os produtos nos quais ele comprou, o nome dos produtos selecionados
na tabela de preços(o comprador escolhe N produtos) e sabor de cada produto,o preco total gasto pelo cliente. 
Como forma de retirbuir o trabalho do aluno desenvolvedor e da professroa orientadora 
que desenvolveram o sistema a sorveteria mandou integrar ao sistema uma promoção para os dois, 
a partir da matricula e da data de compra, caso o mês seja par os dois tem 2.5% de desconto, caso ímpar ganharam 5% de 
desconto, caso a matricula e o mes sejam pares o desconto aumentará para 7% ou o mês ímpar e a data também ganharam 10% de desconto,
senão ganharam o desconto apenas do mês. Como promoção a sorveteria também distribui uma cartilha quadrada de dimensões 3x3, como 
um jogo da velha que o cliente preenche conforme for ele compre os produtos, a cada produto um quadrado é preenchido e caso ele 
complete uma linha da cartilha, o cliente ganhará 3% de desconto, caso ele complete a cartilha inteira ele ganha 10% de desconto. 
A cada produto ele ganha mais um ponto na cartilham e se o valro da sua compra final for maior que 20 reis ele terá um qaudrado
preenchido. O preenchimento da diagonal não conta como promoção, pois quem preenche a ficha é o sistema e o mesmo preenche
automaticamente, desta forma ele só preenche a linha seguinte, depois de preencher a linha anterior, assim só prenechendo as diagonais
no final, não contando como promoção.
O sistema deverá atender 4 pessoas uma seguida da outra.
OBS : O sistema deve atender todos os cursos técnicos e os seguintes cargos: Professor(a),Merendeiro(a), ASG ,Pedagogo(a), Psiologo(a)
Tabela de preços dos produtos:
 Sorvete  (R$ 6.50)
 Milk Shake (R$ 10.20)
 Picole (R$ 2.10)
 Torta (R$ 13.70)

 Tabela de preços dos sabores
  Morango (1.30)
  Chocolate (1.50)
  Limao (1.90)
  Maracuja (2.50)
*/

#include<iostream>
#include<string.h>
using namespace std;

int main(){
struct  Aluno{
    string nome;
    int idade;
    char serie;
    int matricula;
    char curso[2];
    int dia;
    int mes;
    int ano;
};

bool sair=0, desenvolvedor;
int aux=0;
char resp;
int cont, quantidade;
Aluno compra1, compra2, compra3, compra4; 
string nomeP, nomeA;
int pontosCartilha=0;

nomeP = "Alessandra";
cout << "Digite o nome do aluno desenvolvedor:";
getline(cin, nomeA);
while(!sair){
char Cartilha[3][3] {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char Cartilha2[3][3] {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
string nomeC;
float desconto;
cout << "\n_________________________________\n";
cout << "|\t  Sorveteira EAJ\t|";
cout << "\n|_______________________________|\n";

cout << "\nOla cliente 1 seja bem vindo, digite seu nome:";
if(aux>0){// A leitura anterior é deum tipo diferente,então o getchar se faz necessário apenas na segunda execução do laço e não na primeira
getchar();
}
getline(cin,compra1.nome);

cout << "\nOla " << compra1.nome<< ", digite a sua idade: ";
cin >> compra1.idade;

while (compra1.idade < 0 || compra1.idade >= 110){
    cout << "\nIdade invalida, digite novamente: ";
    cin >> compra1.idade;
}
cout << "\nVoce eh aluno? Digte 's' para sim e 'n' para nao\n";
cin >> resp;
// Caso a respota digitada não seja s (sim) ou n(não)
while(resp != 's'  && resp != 'n'){
    cout << "\nOpcao invalida, digite novamente:";
    cin >> resp;
}
if(resp=='s'){
nomeC = "Aluno(a)";

cout << "\nDigite o nome do seu curso: \n";
cout << "Informatica - IF\n";
cout << "Agroindustria - AI\n";
cout << "Agropecuaria - AP\n";
cout << "Aquicultura - AQ\n";
cout << "Cozinha - CZ\n";
cin >> compra1.curso;
while ((compra1.curso[0] != 'I' && compra1.curso[1] != 'F') && 
(compra1.curso[0] != 'A'&& compra1.curso[1] != 'I') && (compra1.curso[0] != 'A' &&
 compra1.curso[1] != 'P') && (compra1.curso[0] != 'A'&& compra1.curso[1] != 'Q') &&
 (compra1.curso[0] != 'C'&& compra1.curso[1] != 'Z')){ // Caso o curso digitado não exista

  cout << "Curso invalido\n";
  cin >> compra1.curso;
}


cout << "\nDigite a serie que voce esta no ensino medio: \n";// Pergunta a série do aluno
cout << "1 - Primeiro Ano\n";
cout << "2 - Segundo  Ano\n";
cout << "3 - Terceiro Ano\n";
cin >> compra1.serie;

while (compra1.serie !='1'&& compra1.serie !='2' && compra1.serie !='3'){// Caso a série digitada não exista na escola
    cout << "\nEsta serie nao existe na escola, digite novamente:";
    cin >> compra1.serie;
}
}else if(resp=='n'){
    cout << "Digite seu cargo\n";

    cout << "\nDigite o nome do seu curso: \n";// Seleciona os cargos cadastrados no sistema
cout << "Professor(a) - PR\n";
cout << "Merendeiro(a)- MD\n";
cout << "ASG - AS\n";
cout << "Pedagogo(a) - PG\n";
cout << "Psiologo(a) - PC\n";
cin >> compra1.curso;

while((compra1.curso[0] != 'P' && compra1.curso[1] != 'R') && (compra1.curso[0] != 'M' && compra1.curso[1] != 'D') // Caso o cargo digitado não exist ano sistema
&& (compra1.curso[0] != 'A' && compra1.curso[1] != 'S') && (compra1.curso[0] != 'P' && compra1.curso[1] != 'G') 
&& (compra1.curso[0] != 'P' && compra1.curso[1] != 'C')){
    cout << "Cargo invalido, digite novamente";
    cin >> compra1.curso;
}
}
// Verifica o cargo do funcionario a partir da sigla
if(compra1.curso[0] == 'P' && compra1.curso[1] == 'R'){
    nomeC = "Professor(a)";
}else if(compra1.curso[0] == 'M' && compra1.curso[1] == 'D'){
    nomeC = "Merendeiro(a)";
}else if(compra1.curso[0] == 'A' && compra1.curso[1] == 'S'){
    nomeC= "ASG";
}else if(compra1.curso[0] == 'P' && compra1.curso[1] == 'G'){
   nomeC = "Pedagogo(a)";
}else if(compra1.curso[0] == 'P' && compra1.curso[1] == 'C'){
      nomeC = "Paicologo(a)";
}
cout << "\nDigite o numero da sua matricula: ";// Saber a mtricula do aluno ou funcionario
cin >> compra1.matricula;
cout << "\nDigite o dia de hoje: ";
cin>> compra1.dia;
while(compra1.dia > 31 || compra1.dia <=0){
    cout << "\nDia invalida, digite novamente";
    cin >> compra1.dia;
}
cout << "\nDigite o mes: ";
cin>> compra1.mes;
while(compra1.mes > 12 || compra1.mes <= 0){
    cout << "\nDia invalida, digite novamente";
    cin >> compra1.mes;
}
cout << "\nDigite o ano : ";
cin>> compra1.ano;


cout << "\nDigite quantos produtos deseja comprar: \n";
cin >> quantidade;
string nomeProduto[quantidade];
string nomeSabor[quantidade];
float preco[quantidade];
float precoTotal=0;
// Preenchendo a cartilha

if(quantidade <=3){// Caso a quantidade de produtos for menor ou igual a 3, apenas os quadrados da primeira linha serão preenchidos e de acordo com a quantidade de produtos
for (int c = 0; c < quantidade; c++){
    Cartilha[0][c]= 'x';
}
}else if(quantidade <= 6){// Caso a quantidade de produtos for menor ou igual a 6, somente a primeira e segunda linha serão preenchidas de acordo com a quantidade de produtos
   for (int c = 0; c < 3; c++){
       Cartilha[0][c]= 'x';
} 
 for(int c=0; c < quantidade - 3; c++){
     Cartilha[1][c]='x';
 }
}else{// Senão, quer dizer que ou a quantidade de produtos é igual a quantidade de quandrados da cratilha ou maior, então devem ser preenchidos todos os quadrados
    for (int l = 0; l < 3; l++){
   for (int c = 0; c < 3; c++){
       Cartilha[l][c]= 'x';
    }
}
}
 for (int l = 0; l < 3; l++){
   for (int c = 0; c < 3; c++){
    Cartilha2[l][c] = Cartilha[l][c];// Atribuindo os quadrados preenchidos da cartilha original, na cartilha que será mostrada
   }
 }
for(cont= 0; cont < quantidade; cont++){

 cout << "\nDigite o produto que deseja selecionarna tabela a seguir: \n";// Saber o produto desejado
 cout << "Sorvete  (R$ 6.50) \n";
 cout << "Milk Shake  (R$ 10.20)\n";
 cout << "Picole (R$ 2.10)\n";
 cout << "Torta (R$ 13.70)\n";
 cout << "\nDigite o nome do produto: ";
 getchar();
 getline(cin, nomeProduto[cont]);

 while(nomeProduto[cont]!= "Sorvete" && nomeProduto[cont] != "Milk Shake" && nomeProduto[cont] != "Picole" && nomeProduto[cont]!= "Torta"){// Caso o produto escolgido não esteja cadastrado no sistema
     cout << "Produto invalido, digite novamente: ";
     getline(cin, nomeProduto[cont]);
 }
 // Atribuição do preço do produto
 if(nomeProduto[cont] == "Sorvete"){
     preco[cont] = 6.5;
 }else if(nomeProduto[cont] == "Milk Shake"){
     preco[cont] = 10.2;
 }else if(nomeProduto[cont] == "Picole"){
    preco[cont] = 2.1;
 }else if(nomeProduto[cont] == "Torta"){
     preco[cont] = 13.7;
 }

 cout << "\nDigite o sabor do produto, a partir da tabela a seguir:\n";// Saber a cobertura
  cout <<"Morango (1.30)\n";
 cout << "Chocolate (1.50)\n";
 cout << "Limao (1.90)\n";
 cout << "Maracuja (2.50)\n";
 cout << "\nDigite o sabor: ";
 getline(cin, nomeSabor[cont]);

 while(nomeSabor[cont] != "Morango"  && nomeSabor[cont] != "Chocolate" && nomeSabor[cont] != "Limao" &&  nomeSabor[cont] != "Maracuja"){// Caso a cobertura digitada não esteja cadastrada no sistema
     cout << "Sabor invalido, digte novamente: ";
 getline(cin, nomeSabor[cont]);
 }
 // Formação do preço unitário do produto
 if(nomeSabor[cont] == "Morango"){
    preco[cont] += 1.3;
 }else if(nomeSabor[cont] == "ChocoLate"){
     preco[cont] += 1.5;
 }else if(nomeSabor[cont] ==  "Limao"){
     preco[cont] += 1.9;
 }else if(nomeSabor[cont] == "Maracuja"){
     preco[cont] += 2.5;
 }
 precoTotal += preco[cont];// Formação do preço total da compra

 if(cont+1 == quantidade){// Se estiver na última execução do laço, fazer o condicional para verficar se o cliente é um desenvolvedor
 
 if((compra1.nome == nomeA && compra1.curso[0] == 'I' && compra1.curso[1]=='F')||
  (compra1.nome == nomeP && compra1.curso[0]=='P' && compra1.curso[1]=='R')){ //Verifica se o cliente que está fazendo a compra é um desenvolvedor do sistema 
     
     if(compra1.mes%2==0 && compra1.matricula%2==0){// Se o mês é par e a matricula par, aplica 7% de desconto
         desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
          desconto = 7;

     }else if(compra1.mes%2!=0 && compra1.matricula%2!=0){//Se o mês é ímpar e a matricula ímpar, aplica 10% de desconto
          desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
          desconto = 10;

     }else if(compra1.mes%2==0){// Se apenas o mês é par, aplicar 2.5% de desconto
            desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
              desconto = 2.5;
     }else{// Senão é porque o mês é ímpar, aplicar 5% de desconto
          desconto = 5;
          desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
     }
           precoTotal = precoTotal - (precoTotal*desconto)/100;
}else{
             desenvolvedor = 0; // Quer dizer que cliente do momento não é desenvolvedor do sistema
}
 }

 if(precoTotal > 20){
      for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
             if(Cartilha[l][c]==' ' && ( Cartilha[l][c-1]=='x' || Cartilha[l-1][c]=='x')){// Usando vizinhança de 4, para poder preencher os quadrados na cartilha
                    Cartilha2[l][c]='x';
                    cout << l << endl;
                    cout << c << endl;
                    c=3;
                    l=3;
             }
         }
     }
 }
}
  for(int l=0; l < 3; l++){ // Vendo o desconto da cartilha, olhando quais linhas estão preenchidas
         for(int c=0; c<3; c++){
               if(Cartilha2[l][c]=='x'){
                  pontosCartilha++;
            }
         }
  }
// Mostrando dados dos clientes
cout << "\n >>> Dados do comprador <<< \n";
cout << "\nNome do "<< nomeC << "..............................." << compra1.nome;
cout << "\nIdade do " << nomeC<< ".............................." << compra1.idade;
cout << "\nMaticula do " << nomeC <<"..........................." << compra1.matricula;
cout << "\nData............................................." << compra1.dia << "/" << compra1.mes << "/" << compra1.ano;
if (nomeC=="Aluno(a)"){// Caso seja um aluno, mostrar a serie e o curso
cout << "\nSerie do aluno.............................." << compra1.serie << ". Ano";
cout << "\nTurma do "<< nomeC << "..............................." << compra1.curso << endl;
}else{// Se não, é um funcionário da escola, mostrar a sigla e o nome do cargo exercido
    cout << "\nCargo.............................." << compra1.curso[0] << compra1.curso[1] << " - " << nomeC << endl;
}
for (cont = 0; cont < quantidade; cont++){// Mostrando dados dos produtos
    cout << endl;
cout << cont +1 << ". Pedido do(a) " << nomeC << "................................" << nomeProduto[cont] << endl;
cout << cont + 1 << ". Sabor escolhido........................" << nomeSabor[cont] << endl;
cout << "Preco unitario do produto......................" << preco[cont] << endl;
}
if(pontosCartilha ==3){
    precoTotal = precoTotal - (precoTotal*3)/100;
    cout << "O clinte completou uma linha da cartilha, ganhou 3% de desconto\n";
}else if(pontosCartilha ==6){
  precoTotal = precoTotal - (precoTotal*6)/100;
   cout << "O clinte completou duas linhas da cartilha, ganhou 6% de desconto\n";
}else if(pontosCartilha ==9){
 precoTotal = precoTotal - (precoTotal*10)/100;
  cout << "O clinte completou todas as linhas da cartilha, ganhou 10% de desconto\n";
}
cout << "Preco total da compra.........................." << precoTotal << endl;
if(desenvolvedor){
    cout << "O cliente eh desenvolvedor do sistema, com isso ganhou um desconto de " << desconto << "%";
}

cout << "\n >>> Cartilha de desconto <<< \n";
  for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
             cout << Cartilha2[l][c];
         }
         cout << endl;
  }
//Retirando valro de variáveis para a próxima execução do próximo cliente
  for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
                 Cartilha[l][c] = ' ';
                  Cartilha2[l][c]= ' ';
         }
  }
 pontosCartilha =0;
cout << "\nOla cliente 2 seja bem vindo, digite seu nome:";
getline(cin,compra2.nome);

cout << "\nOla " << compra2.nome<< ", digite a sua idade: ";
cin >> compra2.idade;

while (compra2.idade < 0 || compra2.idade >= 110){
    cout << "\nIdade invalida, digite novamente: ";
    cin >> compra2.idade;
}
cout << "\nVoce eh aluno? Digte 's' para sim e 'n' para nao\n";
cin >> resp;
// Caso a respota digitada não seja s (sim) ou n(não)
while(resp != 's'  && resp != 'n'){
    cout << "\nOpcao invalida, digite novamente:";
    cin >> resp;
}
if(resp=='s'){
nomeC = "Aluno(a)";

cout << "\nDigite o nome do seu curso: \n";
cout << "Informatica - IF\n";
cout << "Agroindustria - AI\n";
cout << "Agropecuaria - AP\n";
cout << "Aquicultura - AQ\n";
cout << "Cozinha - CZ\n";
cin >> compra2.curso;
while ((compra2.curso[0] != 'I' && compra2.curso[1] != 'F') && 
(compra2.curso[0] != 'A'&& compra2.curso[1] != 'I') && (compra2.curso[0] != 'A' &&
 compra2.curso[1] != 'P') && (compra2.curso[0] != 'A'&& compra2.curso[1] != 'Q') &&
 (compra2.curso[0] != 'C'&& compra2.curso[1] != 'Z')){ // Caso o curso digitado não exista

  cout << "Curso invalido\n";
  cin >> compra2.curso;
}


cout << "\nDigite a serie que voce esta no ensino medio: \n";// Pergunta a série do aluno
cout << "1 - Primeiro Ano\n";
cout << "2 - Segundo  Ano\n";
cout << "3 - Terceiro Ano\n";
cin >> compra2.serie;

while (compra2.serie !='1'&& compra2.serie !='2' && compra2.serie !='3'){// Caso a série digitada não exista na escola
    cout << "\nEsta serie nao existe na escola, digite novamente:";
    cin >> compra2.serie;
}
}else if(resp=='n'){
    cout << "Digite seu cargo\n";

    cout << "\nDigite o nome do seu curso: \n";// Seleciona os cargos cadastrados no sistema
cout << "Professor(a) - PR\n";
cout << "Merendeiro(a)- MD\n";
cout << "ASG - AS\n";
cout << "Pedagogo(a) - PG\n";
cout << "Psiologo(a) - PC\n";
cin >> compra2.curso;

while((compra2.curso[0] != 'P' && compra2.curso[1] != 'R') && (compra2.curso[0] != 'M' && compra2.curso[1] != 'D') // Caso o cargo digitado não exist ano sistema
&& (compra2.curso[0] != 'A' && compra2.curso[1] != 'S') && (compra2.curso[0] != 'P' && compra2.curso[1] != 'G') 
&& (compra2.curso[0] != 'P' && compra2.curso[1] != 'C')){
    cout << "Cargo invalido, digite novamente";
    cin >> compra2.curso;
}
}
// Verifica o cargo do funcionario a partir da sigla
if(compra2.curso[0] == 'P' && compra2.curso[1] == 'R'){
    nomeC = "Professor(a)";
}else if(compra2.curso[0] == 'M' && compra2.curso[1] == 'D'){
    nomeC = "Merendeiro(a)";
}else if(compra2.curso[0] == 'A' && compra2.curso[1] == 'S'){
    nomeC= "ASG";
}else if(compra2.curso[0] == 'P' && compra2.curso[1] == 'G'){
   nomeC = "Pedagogo(a)";
}else if(compra2.curso[0] == 'P' && compra2.curso[1] == 'C'){
      nomeC = "Psicologo(a)";
}
cout << "\nDigite o numero da sua matricula: ";// Saber a mtricula do aluno ou funcionario
cin >> compra2.matricula;
cout << "\nDigite o dia de hoje: ";
cin>> compra2.dia;
while(compra2.dia > 31 || compra2.dia <=0){
    cout << "\nDia invalida, digite novamente";
    cin >> compra2.dia;
}
cout << "\nDigite o mes: ";
cin>> compra2.mes;
while(compra2.mes > 12 || compra2.mes <= 0){
    cout << "\nDia invalida, digite novamente";
    cin >> compra2.mes;
}
cout << "\nDigite o ano : ";
cin>> compra2.ano;


cout << "\nDigite quantos produtos deseja comprar: \n";
cin >> quantidade;
string nomeProduto2[quantidade];
string nomeSabor2[quantidade];
float preco2[quantidade];
float preco2Total=0;
// Preenchendo a cartilha

if(quantidade <=3){// Caso a quantidade de produtos for menor ou igual a 3, apenas os quadrados da primeira linha serão preenchidos e de acordo com a quantidade de produtos
for (int c = 0; c < quantidade; c++){
    Cartilha[0][c]= 'x';
}
}else if(quantidade <= 6){// Caso a quantidade de produtos for menor ou igual a 6, somente a primeira e segunda linha serão preenchidas de acordo com a quantidade de produtos
   for (int c = 0; c < 3; c++){
       Cartilha[0][c]= 'x';
} 
 for(int c=0; c < quantidade - 3; c++){
     Cartilha[1][c]='x';
 }
}else{// Senão, quer dizer que ou a quantidade de produtos é igual a quantidade de quandrados da cratilha ou maior, então devem ser preenchidos todos os quadrados
    for (int l = 0; l < 3; l++){
   for (int c = 0; c < 3; c++){
       Cartilha[l][c]= 'x';
    }
}
}
 for (int l = 0; l < 3; l++){
   for (int c = 0; c < 3; c++){
    Cartilha2[l][c] = Cartilha[l][c];// Atribuindo os quadrados preenchidos da cartilha original, na cartilha que será mostrada
   }
 }
for(cont= 0; cont < quantidade; cont++){

 cout << "\nDigite o produto que deseja selecionarna tabela a seguir: \n";// Saber o produto desejado
 cout << "Sorvete  (R$ 6.50) \n";
 cout << "Milk Shake  (R$ 10.20)\n";
 cout << "Picole (R$ 2.10)\n";
 cout << "Torta (R$ 13.70)\n";
 cout << "\nDigite o nome do produto: ";
  getchar();
 getline(cin, nomeProduto2[cont]);

 while(nomeProduto2[cont]!= "Sorvete" && nomeProduto2[cont] != "Milk Shake" && nomeProduto2[cont] != "Picole" && nomeProduto2[cont]!= "Torta"){// Caso o produto escolgido não esteja cadastrado no sistema
     cout << "Produto invalido, digite novamente: ";
     getline(cin, nomeProduto2[cont]);
 }
 // Atribuição do preço do produto
 if(nomeProduto2[cont] == "Sorvete"){
     preco2[cont] = 6.5;
 }else if(nomeProduto2[cont] == "Milk Shake"){
     preco2[cont] = 10.2;
 }else if(nomeProduto2[cont] == "Picole"){
    preco2[cont] = 2.1;
 }else if(nomeProduto2[cont] == "Torta"){
     preco2[cont] = 13.7;
 }

 cout << "\nDigite o sabor do produto, a partir da tabela a seguir:\n";// Saber a cobertura
  cout <<"Morango (1.30)\n";
 cout << "Chocolate (1.50)\n";
 cout << "Limao (1.90)\n";
 cout << "Maracuja (2.50)\n";
 cout << "\nDigite o sabor: ";

 getline(cin, nomeSabor2[cont]);

 while(nomeSabor2[cont] != "Morango"  && nomeSabor2[cont] != "Chocolate" && nomeSabor2[cont] != "Limao" &&  nomeSabor2[cont] != "Maracuja"){// Caso a cobertura digitada não esteja cadastrada no sistema
     cout << "Sabor invalido, digte novamente: ";
 getline(cin, nomeSabor2[cont]);
 }
 // Formação do preço unitário do produto
 if(nomeSabor2[cont] == "Morango"){
    preco2[cont] += 1.3;
 }else if(nomeSabor2[cont] == "ChocoLate"){
     preco2[cont] += 1.5;
 }else if(nomeSabor2[cont] ==  "Limao"){
     preco2[cont] += 1.9;
 }else if(nomeSabor2[cont] == "Maracuja"){
     preco2[cont] += 2.5;
 }
 preco2Total += preco2[cont];// Formação do preço total da compra

 if(cont+1 == quantidade){// Se estiver na última execução do laço, fazer o condicional para verficar se o cliente é um desenvolvedor
 
 if((compra2.nome == nomeA && compra2.curso[0] == 'I' && compra2.curso[1]=='F')||
  (compra2.nome == nomeP && compra2.curso[0]=='P' && compra2.curso[1]=='R')){ //Verifica se o cliente que está fazendo a compra é um desenvolvedor do sistema 
     
     if(compra2.mes%2==0 && compra2.matricula%2==0){// Se o mês é par e a matricula par, aplica 7% de desconto
         desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
          desconto = 7;

     }else if(compra2.mes%2!=0 && compra2.matricula%2!=0){//Se o mês é ímpar e a matricula ímpar, aplica 10% de desconto
          desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
          desconto = 10;

     }else if(compra2.mes%2==0){// Se apenas o mês é par, aplicar 2.5% de desconto
            desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
              desconto = 2.5;
     }else{// Senão é porque o mês é ímpar, aplicar 5% de desconto
          desconto = 5;
          desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
     }
           preco2Total = preco2Total - (preco2Total*desconto)/100;
}else{
             desenvolvedor = 0; // Quer dizer que cliente do momento não é desenvolvedor do sistema
}
 }

 if(preco2Total > 20){
      for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
             if(Cartilha[l][c]==' ' && ( Cartilha[l][c-1]=='x' || Cartilha[l-1][c]=='x')){// Usando vizinhança de 4, para poder preencher os quadrados na cartilha
                    Cartilha2[l][c]='x';
                    cout << l << endl;
                    cout << c << endl;
                    c=3;
                    l=3;
             }
         }
     }
 }
}
 pontosCartilha=0;
  for(int l=0; l < 3; l++){ // Vendo o desconto da cartilha, olhando quais linhas estão preenchidas
         for(int c=0; c<3; c++){
               if(Cartilha2[l][c]=='x'){
                  pontosCartilha++;
            }
         }
  }
// Mostrando dados dos clientes
cout << "\n >>> Dados do comprador <<< \n";
cout << "\nNome do "<< nomeC << "..............................." << compra2.nome;
cout << "\nIdade do " << nomeC<< ".............................." << compra2.idade;
cout << "\nMaticula do " << nomeC <<"..........................." << compra2.matricula;
cout << "\nData............................................." << compra2.dia << "/" << compra2.mes << "/" << compra2.ano;
if (nomeC=="Aluno(a)"){// Caso seja um aluno, mostrar a serie e o curso
cout << "\nSerie do aluno.............................." << compra2.serie << ". Ano";
cout << "\nTurma do "<< nomeC << "..............................." << compra2.curso << endl;
}else{// Se não, é um funcionário da escola, mostrar a sigla e o nome do cargo exercido
    cout << "\nCargo.............................." << compra2.curso[0] << compra2.curso[1] << " - " << nomeC << endl;
}
for (cont = 0; cont < quantidade; cont++){// Mostrando dados dos produtos
    cout << endl;
cout << cont +1 << ". Pedido do(a) " << nomeC << "................................" << nomeProduto2[cont] << endl;
cout << cont + 1 << ". Sabor escolhido........................" << nomeSabor2[cont] << endl;
cout << "Preco unitario do produto......................" << preco2[cont] << endl;
}
if(pontosCartilha ==3){
    preco2Total = preco2Total - (preco2Total*3)/100;
    cout << "O clinte completou uma linha da cartilha, ganhou 3% de desconto\n";
}else if(pontosCartilha ==6){
  preco2Total = preco2Total - (preco2Total*6)/100;
   cout << "O clinte completou duas linhas da cartilha, ganhou 6% de desconto\n";
}else if(pontosCartilha ==9){
 preco2Total = preco2Total - (preco2Total*10)/100;
  cout << "O clinte completou todas as linhas da cartilha, ganhou 10% de desconto\n";
}
cout << "Preco total da compra.........................." << preco2Total << endl;
if(desenvolvedor){
    cout << "O cliente eh desenvolvedor do sistema, com isso ganhou um desconto de " << desconto << "%";
}

cout << "\n >>> Cartilha de desconto <<< \n";
  for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
             cout << Cartilha2[l][c];
         }
         cout << endl;
  }
//Retirando valor de variáveis para a próxima execução do próximo cliente
  for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
                 Cartilha[l][c] = ' ';
                  Cartilha2[l][c]= ' ';
         }
  }
   desconto=0;

pontosCartilha =0;
cout << "\nOla cliente 3 seja bem vindo, digite seu nome:";
// A leitura anterior é deum tipo diferente,então o getchar se faz necessário apenas na segunda execução do laço e não na primeira
getline(cin,compra3.nome);

cout << "\nOla " << compra3.nome<< ", digite a sua idade: ";
cin >> compra3.idade;

while (compra3.idade < 0 || compra3.idade >= 110){
    cout << "\nIdade invalida, digite novamente: ";
    cin >> compra3.idade;
}
cout << "\nVoce eh aluno? Digte 's' para sim e 'n' para nao\n";
cin >> resp;
// Caso a respota digitada não seja s (sim) ou n(não)
while(resp != 's'  && resp != 'n'){
    cout << "\nOpcao invalida, digite novamente:";
    cin >> resp;
}
if(resp=='s'){
nomeC = "Aluno(a)";

cout << "\nDigite o nome do seu curso: \n";
cout << "Informatica - IF\n";
cout << "Agroindustria - AI\n";
cout << "Agropecuaria - AP\n";
cout << "Aquicultura - AQ\n";
cout << "Cozinha - CZ\n";
cin >> compra3.curso;
while ((compra3.curso[0] != 'I' && compra3.curso[1] != 'F') && 
(compra3.curso[0] != 'A'&& compra3.curso[1] != 'I') && (compra3.curso[0] != 'A' &&
 compra3.curso[1] != 'P') && (compra3.curso[0] != 'A'&& compra3.curso[1] != 'Q') &&
 (compra3.curso[0] != 'C'&& compra3.curso[1] != 'Z')){ // Caso o curso digitado não exista

  cout << "Curso invalido\n";
  cin >> compra3.curso;
}


cout << "\nDigite a serie que voce esta no ensino medio: \n";// Pergunta a série do aluno
cout << "1 - Primeiro Ano\n";
cout << "2 - Segundo  Ano\n";
cout << "3 - Terceiro Ano\n";
cin >> compra3.serie;

while (compra3.serie !='1'&& compra3.serie !='2' && compra3.serie !='3'){// Caso a série digitada não exista na escola
    cout << "\nEsta serie nao existe na escola, digite novamente:";
    cin >> compra3.serie;
}
}else if(resp=='n'){
    cout << "Digite seu cargo\n";

    cout << "\nDigite o nome do seu curso: \n";// Seleciona os cargos cadastrados no sistema
cout << "Professor(a) - PR\n";
cout << "Merendeiro(a)- MD\n";
cout << "ASG - AS\n";
cout << "Pedagogo(a) - PG\n";
cout << "Psiologo(a) - PC\n";
cin >> compra3.curso;

while((compra3.curso[0] != 'P' && compra3.curso[1] != 'R') && (compra3.curso[0] != 'M' && compra3.curso[1] != 'D') // Caso o cargo digitado não exist ano sistema
&& (compra3.curso[0] != 'A' && compra3.curso[1] != 'S') && (compra3.curso[0] != 'P' && compra3.curso[1] != 'G') 
&& (compra3.curso[0] != 'P' && compra3.curso[1] != 'C')){
    cout << "Cargo invalido, digite novamente";
    cin >> compra3.curso;
}
}
// Verifica o cargo do funcionario a partir da sigla
if(compra3.curso[0] == 'P' && compra3.curso[1] == 'R'){
    nomeC = "Professor(a)";
}else if(compra3.curso[0] == 'M' && compra3.curso[1] == 'D'){
    nomeC = "Merendeiro(a)";
}else if(compra3.curso[0] == 'A' && compra3.curso[1] == 'S'){
    nomeC= "ASG";
}else if(compra3.curso[0] == 'P' && compra3.curso[1] == 'G'){
   nomeC = "Pedagogo(a)";
}else if(compra3.curso[0] == 'P' && compra3.curso[1] == 'C'){
      nomeC = "Psicologo(a)";
}
cout << "\nDigite o numero da sua matricula: ";// Saber a mtricula do aluno ou funcionario
cin >> compra3.matricula;
cout << "\nDigite o dia de hoje: ";
cin>> compra3.dia;
while(compra3.dia > 31 || compra3.dia <=0){
    cout << "\nDia invalida, digite novamente";
    cin >> compra3.dia;
}
cout << "\nDigite o mes: ";
cin>> compra3.mes;
while(compra3.mes > 12 || compra3.mes <= 0){
    cout << "\nDia invalida, digite novamente";
    cin >> compra3.mes;
}
cout << "\nDigite o ano : ";
cin>> compra3.ano;


cout << "\nDigite quantos produtos deseja comprar: \n";
cin >> quantidade;
string nomeProduto3[quantidade];
string nomeSabor3[quantidade];
float preco3[quantidade];
float preco3Total=0;
// Preenchendo a cartilha

if(quantidade <=3){// Caso a quantidade de produtos for menor ou igual a 3, apenas os quadrados da primeira linha serão preenchidos e de acordo com a quantidade de produtos
for (int c = 0; c < quantidade; c++){
    Cartilha[0][c]= 'x';
}
}else if(quantidade <= 6){// Caso a quantidade de produtos for menor ou igual a 6, somente a primeira e segunda linha serão preenchidas de acordo com a quantidade de produtos
   for (int c = 0; c < 3; c++){
       Cartilha[0][c]= 'x';
} 
 for(int c=0; c < quantidade - 3; c++){
     Cartilha[1][c]='x';
 }
}else{// Senão, quer dizer que ou a quantidade de produtos é igual a quantidade de quandrados da cratilha ou maior, então devem ser preenchidos todos os quadrados
    for (int l = 0; l < 3; l++){
   for (int c = 0; c < 3; c++){
       Cartilha[l][c]= 'x';
    }
}
}
 for (int l = 0; l < 3; l++){
   for (int c = 0; c < 3; c++){
    Cartilha2[l][c] = Cartilha[l][c];// Atribuindo os quadrados preenchidos da cartilha original, na cartilha que será mostrada
   }
 }
for(cont= 0; cont < quantidade; cont++){

 cout << "\nDigite o produto que deseja selecionarna tabela a seguir: \n";// Saber o produto desejado
 cout << "Sorvete  (R$ 6.50) \n";
 cout << "Milk Shake  (R$ 10.20)\n";
 cout << "Picole (R$ 2.10)\n";
 cout << "Torta (R$ 13.70)\n";
 cout << "\nDigite o nome do produto: ";
 getchar();
 getline(cin, nomeProduto3[cont]);

 while(nomeProduto3[cont]!= "Sorvete" && nomeProduto3[cont] != "Milk Shake" && nomeProduto3[cont] != "Picole" && nomeProduto3[cont]!= "Torta"){// Caso o produto escolgido não esteja cadastrado no sistema
     cout << "Produto invalido, digite novamente: ";
     getline(cin, nomeProduto3[cont]);
 }
 // Atribuição do preço do produto
 if(nomeProduto3[cont] == "Sorvete"){
     preco3[cont] = 6.5;
 }else if(nomeProduto3[cont] == "Milk Shake"){
     preco3[cont] = 10.2;
 }else if(nomeProduto3[cont] == "Picole"){
    preco3[cont] = 2.1;
 }else if(nomeProduto3[cont] == "Torta"){
     preco3[cont] = 13.7;
 }

 cout << "\nDigite o sabor do produto, a partir da tabela a seguir:\n";// Saber a cobertura
  cout <<"Morango (1.30)\n";
 cout << "Chocolate (1.50)\n";
 cout << "Limao (1.90)\n";
 cout << "Maracuja (2.50)\n";
 cout << "\nDigite o sabor: ";

 getline(cin, nomeSabor3[cont]);

 while(nomeSabor3[cont] != "Morango"  && nomeSabor3[cont] != "Chocolate" && nomeSabor3[cont] != "Limao" &&  nomeSabor3[cont] != "Maracuja"){// Caso a cobertura digitada não esteja cadastrada no sistema
     cout << "Sabor invalido, digte novamente: ";
 getline(cin, nomeSabor3[cont]);
 }
 // Formação do preço unitário do produto
 if(nomeSabor3[cont] == "Morango"){
    preco3[cont] += 1.3;
 }else if(nomeSabor3[cont] == "ChocoLate"){
     preco3[cont] += 1.5;
 }else if(nomeSabor3[cont] ==  "Limao"){
     preco3[cont] += 1.9;
 }else if(nomeSabor3[cont] == "Maracuja"){
     preco3[cont] += 2.5;
 }
 preco3Total += preco3[cont];// Formação do preço total da compra

 if(cont+1 == quantidade){// Se estiver na última execução do laço, fazer o condicional para verficar se o cliente é um desenvolvedor
 
 if((compra3.nome == nomeA && compra3.curso[0] == 'I' && compra3.curso[1]=='F')||
  (compra3.nome == nomeP && compra3.curso[0]=='P' && compra3.curso[1]=='R')){ //Verifica se o cliente que está fazendo a compra é um desenvolvedor do sistema 
     
     if(compra3.mes%2==0 && compra3.matricula%2==0){// Se o mês é par e a matricula par, aplica 7% de desconto
         desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
          desconto = 7;

     }else if(compra3.mes%2!=0 && compra3.matricula%2!=0){//Se o mês é ímpar e a matricula ímpar, aplica 10% de desconto
          desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
          desconto = 10;

     }else if(compra3.mes%2==0){// Se apenas o mês é par, aplicar 2.5% de desconto
            desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
              desconto = 2.5;
     }else{// Senão é porque o mês é ímpar, aplicar 5% de desconto
          desconto = 5;
          desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
     }
           preco3Total = preco3Total - (preco3Total*desconto)/100;
}else{
             desenvolvedor = 0; // Quer dizer que cliente do momento não é desenvolvedor do sistema
}
 }

 if(preco3Total > 20){
      for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
             if(Cartilha[l][c]==' ' && ( Cartilha[l][c-1]=='x' || Cartilha[l-1][c]=='x')){// Usando vizinhança de 4, para poder preencher os quadrados na cartilha
                    Cartilha2[l][c]='x';
                    cout << l << endl;
                    cout << c << endl;
                    c=3;
                    l=3;
             }
         }
     }
 }
}
 pontosCartilha=0;
  for(int l=0; l < 3; l++){ // Vendo o desconto da cartilha, olhando quais linhas estão preenchidas
         for(int c=0; c<3; c++){
               if(Cartilha2[l][c]=='x'){
                  pontosCartilha++;
            }
         }
  }
// Mostrando dados dos clientes
cout << "\n >>> Dados do comprador <<< \n";
cout << "\nNome do "<< nomeC << "..............................." << compra3.nome;
cout << "\nIdade do " << nomeC<< ".............................." << compra3.idade;
cout << "\nMaticula do " << nomeC <<"..........................." << compra3.matricula;
cout << "\nData............................................." << compra3.dia << "/" << compra3.mes << "/" << compra3.ano;
if (nomeC=="Aluno(a)"){// Caso seja um aluno, mostrar a serie e o curso
cout << "\nSerie do aluno.............................." << compra3.serie << ". Ano";
cout << "\nTurma do "<< nomeC << "..............................." << compra3.curso << endl;
}else{// Se não, é um funcionário da escola, mostrar a sigla e o nome do cargo exercido
    cout << "\nCargo.............................." << compra3.curso[0] << compra3.curso[1] << " - " << nomeC << endl;
}
for (cont = 0; cont < quantidade; cont++){// Mostrando dados dos produtos
    cout << endl;
cout << cont +1 << ". Pedido do(a) " << nomeC << "................................" << nomeProduto3[cont] << endl;
cout << cont + 1 << ". Sabor escolhido........................" << nomeSabor3[cont] << endl;
cout << "Preco unitario do produto......................" << preco3[cont] << endl;
}
if(pontosCartilha ==3){
    preco3Total = preco3Total - (preco3Total*3)/100;
    cout << "O clinte completou uma linha da cartilha, ganhou 3% de desconto\n";
}else if(pontosCartilha ==6){
  preco3Total = preco3Total - (preco3Total*6)/100;
   cout << "O clinte completou duas linhas da cartilha, ganhou 6% de desconto\n";
}else if(pontosCartilha ==9){
 preco3Total = preco3Total - (preco3Total*10)/100;
  cout << "O clinte completou todas as linhas da cartilha, ganhou 10% de desconto\n";
}
cout << "preco2 total da compra.........................." << preco3Total << endl;
if(desenvolvedor){
    cout << "O cliente eh desenvolvedor do sistema, com isso ganhou um desconto de " << desconto << "%";
}

cout << "\n >>> Cartilha de desconto <<< \n";
  for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
             cout << Cartilha2[l][c];
         }
         cout << endl;
  }
//Retirando valro de variáveis para a próxima execução do próximo cliente
  for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
                 Cartilha[l][c] = ' ';
                  Cartilha2[l][c]= ' ';
         }
  }
   desconto=0;

   //Retirando valor de variáveis para a próxima execução do próximo cliente
  for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
                 Cartilha[l][c] = ' ';
                  Cartilha2[l][c]= ' ';
         }
  }
   desconto=0;

pontosCartilha =0;
cout << "\nOla cliente 4 seja bem vindo, digite seu nome:";
// A leitura anterior é deum tipo diferente,então o getchar se faz necessário apenas na segunda execução do laço e não na primeira
getline(cin,compra4.nome);

cout << "\nOla " << compra4.nome<< ", digite a sua idade: ";
cin >> compra4.idade;

while (compra4.idade < 0 || compra4.idade >= 110){
    cout << "\nIdade invalida, digite novamente: ";
    cin >> compra4.idade;
}
cout << "\nVoce eh aluno? Digte 's' para sim e 'n' para nao\n";
cin >> resp;
// Caso a respota digitada não seja s (sim) ou n(não)
while(resp != 's'  && resp != 'n'){
    cout << "\nOpcao invalida, digite novamente:";
    cin >> resp;
}
if(resp=='s'){
nomeC = "Aluno(a)";

cout << "\nDigite o nome do seu curso: \n";
cout << "Informatica - IF\n";
cout << "Agroindustria - AI\n";
cout << "Agropecuaria - AP\n";
cout << "Aquicultura - AQ\n";
cout << "Cozinha - CZ\n";
cin >> compra4.curso;
while ((compra4.curso[0] != 'I' && compra4.curso[1] != 'F') && 
(compra4.curso[0] != 'A'&& compra4.curso[1] != 'I') && (compra4.curso[0] != 'A' &&
 compra4.curso[1] != 'P') && (compra4.curso[0] != 'A'&& compra4.curso[1] != 'Q') &&
 (compra4.curso[0] != 'C'&& compra4.curso[1] != 'Z')){ // Caso o curso digitado não exista

  cout << "Curso invalido\n";
  cin >> compra4.curso;
}


cout << "\nDigite a serie que voce esta no ensino medio: \n";// Pergunta a série do aluno
cout << "1 - Primeiro Ano\n";
cout << "2 - Segundo  Ano\n";
cout << "3 - Terceiro Ano\n";
cin >> compra4.serie;

while (compra4.serie !='1'&& compra4.serie !='2' && compra4.serie !='3'){// Caso a série digitada não exista na escola
    cout << "\nEsta serie nao existe na escola, digite novamente:";
    cin >> compra4.serie;
}
}else if(resp=='n'){
    cout << "Digite seu cargo\n";

    cout << "\nDigite o nome do seu curso: \n";// Seleciona os cargos cadastrados no sistema
cout << "Professor(a) - PR\n";
cout << "Merendeiro(a)- MD\n";
cout << "ASG - AS\n";
cout << "Pedagogo(a) - PG\n";
cout << "Psiologo(a) - PC\n";
cin >> compra4.curso;

while((compra4.curso[0] != 'P' && compra4.curso[1] != 'R') && (compra4.curso[0] != 'M' && compra4.curso[1] != 'D') // Caso o cargo digitado não exist ano sistema
&& (compra4.curso[0] != 'A' && compra4.curso[1] != 'S') && (compra4.curso[0] != 'P' && compra4.curso[1] != 'G') 
&& (compra4.curso[0] != 'P' && compra4.curso[1] != 'C')){
    cout << "Cargo invalido, digite novamente";
    cin >> compra4.curso;
}
}
// Verifica o cargo do funcionario a partir da sigla
if(compra4.curso[0] == 'P' && compra4.curso[1] == 'R'){
    nomeC = "Professor(a)";
}else if(compra4.curso[0] == 'M' && compra4.curso[1] == 'D'){
    nomeC = "Merendeiro(a)";
}else if(compra4.curso[0] == 'A' && compra4.curso[1] == 'S'){
    nomeC= "ASG";
}else if(compra4.curso[0] == 'P' && compra4.curso[1] == 'G'){
   nomeC = "Pedagogo(a)";
}else if(compra4.curso[0] == 'P' && compra4.curso[1] == 'C'){
      nomeC = "Psicologo(a)";
}
cout << "\nDigite o numero da sua matricula: ";// Saber a mtricula do aluno ou funcionario
cin >> compra4.matricula;
cout << "\nDigite o dia de hoje: ";
cin>> compra4.dia;
while(compra4.dia > 31 || compra4.dia <=0){
    cout << "\nDia invalida, digite novamente";
    cin >> compra4.dia;
}
cout << "\nDigite o mes: ";
cin>> compra4.mes;
while(compra4.mes > 12 || compra4.mes <= 0){
    cout << "\nDia invalida, digite novamente";
    cin >> compra4.mes;
}
cout << "\nDigite o ano : ";
cin>> compra4.ano;


cout << "\nDigite quantos produtos deseja comprar: \n";
cin >> quantidade;
string nomeProduto4[quantidade];
string nomeSabor4[quantidade];
float preco4[quantidade];
float preco4Total=0;
// Preenchendo a cartilha

if(quantidade <=3){// Caso a quantidade de produtos for menor ou igual a 3, apenas os quadrados da primeira linha serão preenchidos e de acordo com a quantidade de produtos
for (int c = 0; c < quantidade; c++){
    Cartilha[0][c]= 'x';
}
}else if(quantidade <= 6){// Caso a quantidade de produtos for menor ou igual a 6, somente a primeira e segunda linha serão preenchidas de acordo com a quantidade de produtos
   for (int c = 0; c < 3; c++){
       Cartilha[0][c]= 'x';
} 
 for(int c=0; c < quantidade - 3; c++){
     Cartilha[1][c]='x';
 }
}else{// Senão, quer dizer que ou a quantidade de produtos é igual a quantidade de quandrados da cratilha ou maior, então devem ser preenchidos todos os quadrados
    for (int l = 0; l < 3; l++){
   for (int c = 0; c < 3; c++){
       Cartilha[l][c]= 'x';
    }
}
}
 for (int l = 0; l < 3; l++){
   for (int c = 0; c < 3; c++){
    Cartilha2[l][c] = Cartilha[l][c];// Atribuindo os quadrados preenchidos da cartilha original, na cartilha que será mostrada
   }
 }
for(cont= 0; cont < quantidade; cont++){

 cout << "\nDigite o produto que deseja selecionarna tabela a seguir: \n";// Saber o produto desejado
 cout << "Sorvete  (R$ 6.50) \n";
 cout << "Milk Shake  (R$ 10.20)\n";
 cout << "Picole (R$ 2.10)\n";
 cout << "Torta (R$ 13.70)\n";
 cout << "\nDigite o nome do produto: ";
getchar();
 getline(cin, nomeProduto4[cont]);

 while(nomeProduto4[cont]!= "Sorvete" && nomeProduto4[cont] != "Milk Shake" && nomeProduto4[cont] != "Picole" && nomeProduto4[cont]!= "Torta"){// Caso o produto escolgido não esteja cadastrado no sistema
     cout << "Produto invalido, digite novamente: ";
     getline(cin, nomeProduto4[cont]);
 }
 // Atribuição do preço do produto
 if(nomeProduto4[cont] == "Sorvete"){
     preco4[cont] = 6.5;
 }else if(nomeProduto4[cont] == "Milk Shake"){
     preco4[cont] = 10.2;
 }else if(nomeProduto4[cont] == "Picole"){
    preco4[cont] = 2.1;
 }else if(nomeProduto4[cont] == "Torta"){
     preco4[cont] = 13.7;
 }

 cout << "\nDigite o sabor do produto, a partir da tabela a seguir:\n";// Saber a cobertura
  cout <<"Morango (1.30)\n";
 cout << "Chocolate (1.50)\n";
 cout << "Limao (1.90)\n";
 cout << "Maracuja (2.50)\n";
 cout << "\nDigite o sabor: ";

 getline(cin, nomeSabor4[cont]);

 while(nomeSabor4[cont] != "Morango"  && nomeSabor4[cont] != "Chocolate" && nomeSabor4[cont] != "Limao" &&  nomeSabor4[cont] != "Maracuja"){// Caso a cobertura digitada não esteja cadastrada no sistema
     cout << "Sabor invalido, digte novamente: ";
 getline(cin, nomeSabor4[cont]);
 }
 // Formação do preço unitário do produto
 if(nomeSabor4[cont] == "Morango"){
    preco4[cont] += 1.3;
 }else if(nomeSabor4[cont] == "ChocoLate"){
     preco4[cont] += 1.5;
 }else if(nomeSabor4[cont] ==  "Limao"){
     preco4[cont] += 1.9;
 }else if(nomeSabor4[cont] == "Maracuja"){
     preco4[cont] += 2.5;
 }
 preco4Total += preco4[cont];// Formação do preço total da compra

 if(cont+1 == quantidade){// Se estiver na última execução do laço, fazer o condicional para verficar se o cliente é um desenvolvedor
 
 if((compra4.nome == nomeA && compra4.curso[0] == 'I' && compra4.curso[1]=='F')||
  (compra4.nome == nomeP && compra4.curso[0]=='P' && compra4.curso[1]=='R')){ //Verifica se o cliente que está fazendo a compra é um desenvolvedor do sistema 
     
     if(compra4.mes%2==0 && compra4.matricula%2==0){// Se o mês é par e a matricula par, aplica 7% de desconto
         desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
          desconto = 7;

     }else if(compra4.mes%2!=0 && compra4.matricula%2!=0){//Se o mês é ímpar e a matricula ímpar, aplica 10% de desconto
          desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
          desconto = 10;

     }else if(compra4.mes%2==0){// Se apenas o mês é par, aplicar 2.5% de desconto
            desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
              desconto = 2.5;
     }else{// Senão é porque o mês é ímpar, aplicar 5% de desconto
          desconto = 5;
          desenvolvedor = 1; // Quer dizer que cliente do momento é desenvolvedor do sistema
     }
           preco4Total = preco4Total - (preco4Total*desconto)/100;
}else{
             desenvolvedor = 0; // Quer dizer que cliente do momento não é desenvolvedor do sistema
}
 }

 if(preco4Total > 20){
      for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
             if(Cartilha[l][c]==' ' && ( Cartilha[l][c-1]=='x' || Cartilha[l-1][c]=='x')){// Usando vizinhança de 4, para poder preencher os quadrados na cartilha
                    Cartilha2[l][c]='x';
                    cout << l << endl;
                    cout << c << endl;
                    c=3;
                    l=3;
             }
         }
     }
 }
}

  for(int l=0; l < 3; l++){ // Vendo o desconto da cartilha, olhando quais linhas estão preenchidas
         for(int c=0; c<3; c++){
               if(Cartilha2[l][c]=='x'){
                  pontosCartilha++;
            }
         }
  }
// Mostrando dados dos clientes
cout << "\n >>> Dados do comprador <<< \n";
cout << "\nNome do "<< nomeC << "..............................." << compra4.nome;
cout << "\nIdade do " << nomeC<< ".............................." << compra4.idade;
cout << "\nMaticula do " << nomeC <<"..........................." << compra4.matricula;
cout << "\nData............................................." << compra4.dia << "/" << compra4.mes << "/" << compra4.ano;
if (nomeC=="Aluno(a)"){// Caso seja um aluno, mostrar a serie e o curso
cout << "\nSerie do aluno.............................." << compra4.serie << ". Ano";
cout << "\nTurma do "<< nomeC << "..............................." << compra4.curso << endl;
}else{// Se não, é um funcionário da escola, mostrar a sigla e o nome do cargo exercido
    cout << "\nCargo.............................." << compra4.curso[0] << compra4.curso[1] << " - " << nomeC << endl;
}
for (cont = 0; cont < quantidade; cont++){// Mostrando dados dos produtos
    cout << endl;
cout << cont +1 << ". Pedido do(a) " << nomeC << "................................" << nomeProduto4[cont] << endl;
cout << cont + 1 << ". Sabor escolhido........................" << nomeSabor4[cont] << endl;
cout << "Preco unitario do produto......................" << preco4[cont] << endl;
}
if(pontosCartilha ==3){
    preco4Total = preco4Total - (preco4Total*3)/100;
    cout << "O clinte completou uma linha da cartilha, ganhou 3% de desconto\n";
}else if(pontosCartilha ==6){
  preco4Total = preco4Total - (preco4Total*6)/100;
   cout << "O clinte completou duas linhas da cartilha, ganhou 6% de desconto\n";
}else if(pontosCartilha ==9){
 preco4Total = preco4Total - (preco4Total*10)/100;
  cout << "O clinte completou todas as linhas da cartilha, ganhou 10% de desconto\n";
}
cout << "Preco total da compra.........................." << preco4Total << endl;
if(desenvolvedor){
    cout << "O cliente eh desenvolvedor do sistema, com isso ganhou um desconto de " << desconto << "%";
}

cout << "\n >>> Cartilha de desconto <<< \n";
  for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
             cout << Cartilha2[l][c];
         }
         cout << endl;
  }
//Retirando valro de variáveis para a próxima execução do próximo cliente
  for(int l=0; l < 3; l++){
         for(int c=0; c<3; c++){
                 Cartilha[l][c] = ' ';
                  Cartilha2[l][c]= ' ';
         }
  }
   desconto=0;

cout << "\nDeseja sair do sistema? 1 - sim, 0 - nao\n";
cin >> sair;
aux++;
system("cls");// Limapar a tela para ficar o sistema ficar um pouco melhor em relação a estética

}
 cout << "\nFim de programa\n";
system("pause");
}