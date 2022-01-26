/*
Questão 1: Na Escola Agrícola de Judiaí foi criada uma sorveteria e está com a necessidade
de conseguir gerenciar melhor suas vendas, com isso foi feito um pedido a coordenação de informática
parar criar um sistema para fazer esse gerenciamento das vendas,a coordenação propôs este desafio
a um aluno (você), sobre a orientação da porfessora Alessandra para desenvolver este sistema,
com isso você deverá desenvolver este sistema para fazer o registro das vendas da sorveteria, 
contendo o nome do comprador, nome do curso, sua matricula, se o comprador não for aluno 
informar o cargo, os produtos nos quais ele comprou, o nome dos produtos selecionados
na tabela de preços(o comprador escolhe a quantidade de  produtos que desejar, porém pode escolher apenas um total de 9)
e sabor de cada produto, o preço unitario de cada produto,o preco total gasto pelo cliente. Como forma de retirbuir 
o trabalho do aluno desenvolvedor e da professroa orientadora que desenvolveram o sistema, a sorveteria mandou 
integrar ao sistema uma promoção para os dois, a partir da matricula e da data de compra, caso o mês seja par 
os dois tem 2.5% de desconto, caso ímpar ganharam 5% de desconto, caso a matricula e o mes sejam pares o desconto aumentará para 7% ou o mês ímpar e a data também ganharam 10% de desconto,
senão ganharam o desconto apenas do mês. Como promoção a sorveteria também distribui uma cartilha quadrada de dimensões 3x3, como 
um jogo da velha que o cliente preenche conforme for ele compre os produtos, a cada produto um quadrado é preenchido e caso ele 
complete uma linha da cartilha, o cliente ganhará 3% de desconto, caso ele complete a cartilha inteira ele ganha 10% de desconto. 
A cada produto ele ganha mais um ponto na cartilha e se o valor da sua compra final for maior que 20 reais ele terá um qaudrado
preenchido.
O sistema deverá atender uma quantidade N de pessoas, sendo N um número digitado pelo usuário.
OBS : O sistema deve atender todos os cursos técnicos e os seguintes cargos: Professor,Merendeiro, ASG ,Pedagogo, Psiologo
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

Nesta nova versão do sistema da sorveteria da EAJ, foram fetas diversas mudanças em relação a estrura
do código, no sistema anterior não eram utilizadas funções nem os vetores de registro, o que aumentava muito a quantidade
de linhas do algoritmo, dificultando a manutenção do sistema pelos desenvolvedores e um pouco da interpretação do código
, desta maneira reduzindo mais da metade da quantidade de linhas da versão anterior, alguns condicionais estão mias simples, 
para um melhor entendimento do sistema. Com outras possibilidades de uso pelo usário, já que agora o usuário pode colocar uma
quantidade N de pessoas para o algoritimo atender, sem que seja necessário apenas 4 pessoas. Porém com uma quantidade 
limitada de pedidos, podendo apenas comprar 9 produtos no total, mas com a liberdade de escolher a quantidade de produtos.
*/
#include<iostream>
#include<string.h>
using namespace std;
void mostra();
struct Aluno{ // Questão 2:
    string nome;
    int idade;
    char serie = '0';
    int matricula;
    int data[3];
    float precoTotal=0;
    string nomeProduto[9];
    string nomeSabor[9];
    float precoUnitario[9];
    string cargo;
};

struct desconto{
    float Preco_Total;
    int pontosCartilha=0;
};

string ChecaCargo(); // Questão 4
int* checaData(int data[3],bool anoB); // Questão 5
void Vendas(float *precoTotal, float *precoUnitario, string *nomeProd, string *nomeSab); //Questão 6
desconto Promocao(desconto produto);// Questão 7
int Cartilha(int qtd, float preco);// Não é um questão, mas necessária para o funcionamento do sistema
void Desconto(string nome, string curso, float *Preco, int *data, int matricula);// Não é um questão, mas necessária para o funcionamento do sistema

string nomeDesA, nomeDesP = "Alessandra";
bool desenvolvedor;
int main(){
int qtd;
bool sair=0, aluno;

cout << "\nDigite o nome do desenvolvedor: ";
getline(cin, nomeDesA);

while (!sair){// Enquanto o usuário desejar não sair do sistema ele continuará executando.
cout << "\nDigite a quantidade de clientes: ";
cin >> qtd;
Aluno cliente[qtd]; // Questão 3:

int qtdProdutos;
bool bissexto, vez=1;
int *data;
desconto Prom, precoFinal;
    for (int i = 0; i < qtd; i++){
        cout << "\n_________________________________\n";
        cout << "|\t  Sorveteira EAJ\t|";
        cout << "\n|_______________________________|\n";

        cout << "\nOla cliente " << (i + 1) << ", digite seu nome: ";
        if(i==0)
        getchar();
        getline(cin,cliente[i].nome);
        cout << "\nDigite sua matricula: ";
        cin >> cliente[i].matricula;
        cout << "\nOla " << cliente[i].nome << ", digite sua idade: ";
        cin >> cliente[i].idade;

        while (cliente[i].idade <=0 || cliente[i].idade >= 130){ // se a idade for menor ou igual a 0 ou a idade for uma valor muito alto, é preciso digitar novamente
            cout << "\nIdade invalida, digite novamente: ";
            cin >> cliente[i].idade; 
        }
        cliente[i].cargo = ChecaCargo(); // Chamada de função para verificar se é um aluno (informar o curso) ou um funcionário (informar a função)

        if( cliente[i].cargo == "Informatica" || cliente[i].cargo == "Agroindustria" ||  cliente[i].cargo == "Aquicultura" ||  cliente[i].cargo == "Agropecuaria" ||  cliente[i].cargo == "Cozinha"){
            // se a variável que recebeu o retorno for de um curso da escola, perguntar a série do aluno
            cout << "\nDigite sua serie: ";
            aluno = 1; // Verifica se é um aluno
            cin >> cliente[i].serie;
            
            while (cliente[i].serie != '1' && cliente[i].serie != '2' && cliente[i].serie != '3'){// Caso a série não seja válida no sistema
                cout << "\nSerie invalida, digite novamente: ";
                cin >> cliente[i].serie;
            }
        }else{ 
        aluno = 0; // Verifica se não é um aluno
    }

  cout << "\nDigite a data de hoje: ";
    for (int c = 0; c < 3; c++){// Ler a data, na sequência de dia, mês e ano.
    if(c==0)
      cout << "\nDia: ";
    else if(c==1)
      cout << "\nMes: ";
    else
      cout << "\nAno: ";
        cin >> cliente[i].data[c]; 
    }
    cout << "\nO ano eh bissexto? Digite 1 para sim e 0 para nao";
    cin >> bissexto;// Verifica se o ano é bissexto para a verficar se a data está correta.

        data = checaData(cliente[i].data, bissexto); // Função que verifica se a data estar correta, pois como o desconto do desenvolvedor é feito com o uso da data, a mesma tem que estar correta
    
        cout << "\nDigite a quantidade de produtos que ira comprar (Atencao : voce so pode comprar ate 9 produtos): ";
        cin >> qtdProdutos;

       while (qtdProdutos > 9 || qtdProdutos <= 0){// se a quantidade de produtos for mario que a da máxima permitida do sistema ou a menor que a miníma permitida
             cout << "\nQuantidade de produtos invalida, digite novamente: ";
             cin >> qtdProdutos;
       }
    
        for (int j = 0; j < qtdProdutos; j++){// Laço para vender os produtos
            cout << "\nDigite o nome do produto " << (j+1) << ", de acordo com a tabela a seguir: \n";
            cout << "Sorvete  (R$ 6.50) \n";
            cout << "Milk Shake  (R$ 10.20)\n";
            cout << "Picole (R$ 2.10)\n";
            cout << "Torta (R$ 13.70)\n";
            cout << "Obs: O nome do produto deve ser digitado exatamente como esta na tabela acima\n";
            if(j==0)
            getchar();
            getline(cin, cliente[i].nomeProduto[j]);

            cout << "\nDigite o sabor do produto " << (j+1) << ", de acordo com a tabela a seguir: \n";
            cout <<"Morango (1.30)\n";
            cout << "Chocolate (1.50)\n";
            cout << "Limao (1.90)\n";
            cout << "Maracuja (2.50)\n";
            cout << "Obs: O nome do sabor deve ser digitado exatamente como esta na tabela acima\n";
            getline(cin, cliente[i].nomeSabor[j]);   
           
            Vendas(&cliente[i].precoTotal, &cliente[i].precoUnitario[j], &cliente[i].nomeProduto[j], &cliente[i].nomeSabor[j]);// Função que verificar por passagem de referência, se o produto e o sabor digitado estão cadastrados no sistema
        }
        
        Prom.pontosCartilha = Cartilha(qtdProdutos, cliente[i].precoTotal);// Função para atribuir a pintuação da cartilha 
        Desconto(cliente[i].nome, cliente[i].cargo, &cliente[i].precoTotal, cliente[i].data, cliente[i].matricula);// Função que verifica se o cliente é um desenvolvedor do sistema
        Prom.Preco_Total = cliente[i].precoTotal;// Registro que recebeu a pontuação da cartilha, recebendo o preço total para ser usado na próxima função
        precoFinal = Promocao(Prom);// Aplicação da promoção da Cartilha, a partir da função e o registro Prom
        
       cout << "\n>>>>> Dados da Compra <<<<<\n";// Mostrando os dados da compra
       cout << "\nNome do cliente................" << cliente[i].nome;
       cout << "\nIdade do cliente..............." << cliente[i].idade; 
       cout << "\nMatricula do cliente..........." << cliente[i].matricula;
       if(aluno)// se for aluno, mostrar como curso
       cout << "\nCurso do cliente..............." << cliente[i].cargo;
       else// se for funcionário, mostra ro cargo
       cout << "\nCargo do cleinte..............." << cliente[i].cargo;
       if(cliente[i].serie !='0')// Se for um alunoa série vai ser diferente de 0, então msotrar a série
       cout << "\n\nSerie do cliente..............." << cliente[i].serie;
       for (int mostrar = 0; mostrar < qtdProdutos; mostrar++){// Mostrandos o preco unitario de cada produto
           cout << "\nNome do produto " << (mostrar + 1) << ".........................." << cliente[i].nomeProduto[mostrar];
           cout << "\nNome do sabor do produto " << (mostrar + 1) << "................." << cliente[i].nomeSabor[mostrar];
           cout << "\nPreco Unitario do produto " << (mostrar + 1) <<"................." << cliente[i].precoUnitario[mostrar];
       }
         cout << "\nPreco Total da compra.................." << precoFinal.Preco_Total;// Mostrando o preço total da compra
         cout << "\nO cliente ganhou......................." << precoFinal.pontosCartilha << " ponto(s) na cartilha"; 
         if(desenvolvedor)
         cout << "\nO cliente eh um desenvolvedor do sistema";
         cout << "\nData da compra..............";
        for (int l = 0; l < 3; l++){
              if(l < 2)
                  cout << *(data+l) << "/";
              else
              cout << *(data+l) << endl;
        }
    }
    
   cout << "\nDeseja sair do sistema? Digite 1 para sim e 0 para nao: ";
   cin >> sair;
  
  }
     system("cls");
     cout << "\nFim de programa\n";
     system("pause");
}
string ChecaCargo(){// Função que determina se o cliente é um aluno (determina o curso) ou um funcionário (determina o cargo)
string cargo;
    char resp;
    cout << "\nVoce eh aluno? Digite 's' para sim e 'n' para nao: ";
    cin >> resp;
    while (resp != 's' && resp != 'n'){
        cout << "\nResposta invalida, digite novamente: ";
        cin >> resp;
    }
    getchar();
    if (resp=='s'){
       cout << "\nCursos cadastrados no sistema: \n";
       cout << "Informatica\n";
       cout << "Agroindustria\n";
       cout << "Agropecuaria\n";
       cout << "Aquicultura\n";
       cout << "Cozinha\n"; 
       cout << "Obs: Digite o curso da mesma forma que esta sendo mostrado na tabela\n";
       cout << "\nDigite o nome do seu curso: \n";
       getline(cin, cargo);

        while (cargo != "Informatica" && cargo != "Agroindustria" && cargo != "Agropecuaria" && cargo != "Aquicultura" && cargo != "Cozinha"){
        cout << "\nCurso nao cadastrado no sistema, digite novamente: ";
        getline(cin, cargo);
    }
    }else{
       cout << "\nCargos cadastrados no sistema: \n";
       cout << "Professor\n";
       cout << "Merendeiro\n";
       cout << "ASG\n";
       cout << "Pedagogo\n";
       cout << "Psicologo\n";   
       cout << "Obs: Digite o cargo da mesma forma que esta sendo mostrado na tabela: \n";
       cout << "\nDigite o nome do seu cargo: \n";// Seleciona os cargos cadastrados no sistema
       getline(cin, cargo);

      while (cargo != "Professor" && cargo != "Merendeiro" && cargo != "ASG" && cargo != "Pedagogo" && cargo != "Psicologo"){
        cout << "\nCargo nao cadastrado no sistema, digite novamente: ";
        getline(cin, cargo);
    }

    }
    
        return cargo;
}


int* checaData(int data[3],bool anoB){// Função que observa se a data digitada é correta

    for(int i=0; i < 3; i++){
        if(i==0){
            while(data[i] > 31 || data[i] <= 0){
               cout << "\nDia digitada eh invalido, digite novamente: ";
                cout << "\nDia: ";
                cin >> data[i];
            }
        }else if(i==1){
            while (data[i] < 0 || data[i] > 12){
                cout << "\nMes invalido digite novamente: ";
                cin >> data[i];
            }
            
            while (data[i]== 2 && anoB && (data[i-1] <= 0 || data[i-1] > 29)){
                      cout << "\nDia digitada eh invalido, digite novamente: ";
                     cout << "\nDia: ";
                    cin >> data[i];
            }
            while (data[i] == 2 && !anoB && (data[i-1] <= 0 || data[i-1] > 28)){
                 cout << "\nDia digitada eh invalido, digite novamente: ";
                     cout << "\nDia: ";
                    cin >> data[i];
            }
            while ((data[i]==1 || data[i]==3 || data[i]==5 || data[i]==7 || data[i]==8 || data[i]==10 || data[i==12]) && (data[i-1] <= 0 || data[i-1] > 31)){
                    cout << "\nDia digitada eh invalido, digite novamente: ";
                    cout << "\nDia: ";
                    cin >> data[i];
            }
            while ((data[i]==4 || data[i]==6 || data[i]==9 || data[i]==11) && (data[i-1] > 30 || data[i-1] <= 0)){
                    cout << "\nDia digitada eh invalido, digite novamente: ";
                    cout << "\nDia: ";
                    cin >> data[i];
            }
            
            }else if(i==2){
                while(data[i] < 2021){
                 cout << "\nAno invalido, digite novamente: ";
                  cin >> data[i];
                }
            }
    }
    return data;
}


void Vendas(float *precoTotal, float *precoUnitario, string *nomeProd, string *nomeSab){// Função que verifica se os produtos digitados estão no sistema, se estiverem atribui o preço, senão é necessário digitar o produto novamente
   
   while(*nomeProd!= "Sorvete" && *nomeProd != "Milk Shake" && *nomeProd != "Picole" && *nomeProd != "Torta"){// Caso o produto escolgido não esteja cadastrado no sistema
      cout << "Produto invalido, digite novamente: ";
      getline(cin, *nomeProd);
  }
  // Atribuição do preço do produto
  if(*nomeProd == "Sorvete"){
      *precoUnitario = 6.5;
  }else if(*nomeProd == "Milk Shake"){
         *precoUnitario = 10.2;
  }else if(*nomeProd == "Picole"){
     *precoUnitario = 2.1;
  }else if(*nomeProd == "Torta"){
      *precoUnitario = 13.7;
 }
   
    while(*nomeSab != "Morango"  && *nomeSab != "Chocolate" && *nomeSab != "Limao" &&  *nomeSab!= "Maracuja"){// Caso a cobertura digitada não esteja cadastrada no sistema
     cout << "Sabor invalido, digte novamente: ";
     getline(cin, *nomeSab);
  }
//Formação do preço unitário do produto
  if(*nomeSab == "Morango"){
     *precoUnitario += 1.3;
  }else if(*nomeSab == "Chocolate"){
      *precoUnitario += 1.5;
  }else if(*nomeSab ==  "Limao"){
      *precoUnitario += 1.9;
  }else if(*nomeSab == "Maracuja"){
      *precoUnitario += 2.5;
  }
  *precoTotal += *precoUnitario;// Formação do preço total da compra

}

int Cartilha(int qtd, float preco){// Função qeu atribui a pontuação da cartilha
 int pontos=0;
 char Cartilha[3][3] {' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' '};
 char Cartilha2[3][3] {' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' '};

if(qtd <=3){// Caso a quantidade de produtos for menor ou igual a 3, apenas os quadrados da primeira linha serão preenchidos e de acordo com a quantidade de produtos
 for (int c = 0; c < qtd; c++){
     Cartilha[0][c]= 'x';
 }
 }else if(qtd <= 6){// Caso a quantidade de produtos for menor ou igual a 6, somente a primeira e segunda linha serão preenchidas de acordo com a quantidade de produtos
    for (int c = 0; c < 3; c++){
        Cartilha[0][c]= 'x';
 } 
  for(int c=0; c < 3; c++){
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

  if(preco > 20){
       for(int l=0; l < 3; l++){
          for(int c=0; c<3; c++){
              if(Cartilha[l][c]==' ' && ( Cartilha[l][c-1]=='x' || Cartilha[l-1][c]=='x')){// Usando vizinhança de 4, para poder preencher os quadrados na cartilha
                     Cartilha2[l][c]='x';
                     c=3;
                     l=3;
              }
          }
      }
  }
 
   for(int l=0; l < 3; l++){ // Vendo o desconto da cartilha, olhando quais linhas estão preenchidas
          for(int c=0; c<3; c++){
                if(Cartilha2[l][c]=='x'){
                   pontos++;
             }
          }
   }

cout << "\nCartilha de desconto: \n";
for (int l = 0; l < 3;l++){
    for (int c = 0; c < 3; c++){
       cout << Cartilha2[l][c];        
    }
    cout << endl;
}

 return pontos;   
}

desconto Promocao(desconto produto){// Função que atribui o desconto da cartilha
  if(produto.pontosCartilha ==3){
     produto.Preco_Total = produto.Preco_Total - (produto.Preco_Total *3)/100;
     cout << "O clinte completou uma linha da cartilha, ganhou 3% de desconto\n";
 }else if(produto.pontosCartilha <=8 && produto.pontosCartilha > 6){
   produto.Preco_Total = produto.Preco_Total - (produto.Preco_Total *6)/100;
    cout << "O clinte completou duas linhas da cartilha, ganhou 6% de desconto\n";
 }else if(produto.pontosCartilha <=9 && produto.pontosCartilha > 6){
  produto.Preco_Total = produto.Preco_Total - (produto.Preco_Total *10)/100;
   cout << "O clinte completou todas as linhas da cartilha, ganhou 10% de desconto\n";
 }
    return produto;
}
void Desconto(string nome, string curso, float *Preco, int *data, int matricula){// Função que verifica se o cliente é um desenvolvedor do sistema, se sim atribui os descontos a partir da matricula e a data
   float promocao;
    if( (nome == nomeDesA &&curso == "Informatica" ) || (nome == nomeDesP && curso == "Professor") ){//Verifica se o cliente que está fazendo a compra é um desenvolvedor do sistema 
     
      if(data[1]%2==0 && matricula%2==0){// Se o mês é par e a matricula par, aplica 7% de desconto
         promocao = 7;
         desenvolvedor = 1;
      }else if(data[1]%2!=0 && matricula%2!=0){//Se o mês é ímpar e a matricula ímpar, aplica 10% de desconto
           promocao = 10; // Quer dizer que cliente do momento é desenvolvedor do sistema
          desenvolvedor = 1;
      }else if(data[1]%2==0){// Se apenas o mês é par, aplicar 2.5% de desconto
             promocao = 2.5; // Quer dizer que cliente do momento é desenvolvedor do sistema
             desenvolvedor = 1;
      }else{// Senão é porque o mês é ímpar, aplicar 5% de desconto
           promocao= 5; 
           desenvolvedor = 1;// Quer dizer que cliente do momento é desenvolvedor do sistema
      }
            *Preco = *Preco - (*Preco * promocao)/100;
    }else{
        desenvolvedor = 0;
    }
  }