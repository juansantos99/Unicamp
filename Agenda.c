#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#define TAM 1000

struct Contato{

    char nome[102];
    char telefone[18];
    char email[102];
    char sexo;
    int idade;
    float peso;
    float altura;
    int vazio; //VAZIO = 0 e DISPONIVEL = 1.
}registros[TAM];

void cadastrar();
void excluir();
void consultar();
void visualizar();
void sair();
int verifica_pos();
void inicializar();
//void zerar(); //excluir contato
//int verifica_cod(int cod);



int main() {

  inicializar();

  int opcao = 0; //opcao para selecao da agenda, qual menu selecionar

  do{

    printf("****MENU AGENDA ELETRONICA****\n");
    printf("1: Adicionar contato\n");
    printf("2: Excluir contato\n");
    printf("3: Pesquisar contato\n");
    printf("4: Visualizar todos os contatos\n");
    printf("Sair!\n");

    scanf ("%d", &opcao);
    __fpurge(stdin);

    switch(opcao){

      case 1:
        cadastrar();
        break;


      case 2:
        excluir();
      break;


      case 3:
        consultar();
      break;


      /*case 4:
        visualizar();
      break;*/

      case 0:
        system("pause");
      break;
    }

  }while(opcao !=5);

  return 0;
}

void cadastrar (int pos){ //cadastrando o contato

  pos = verifica_pos();

  printf("Valor de pos: %d\n", pos);

  printf("Digite o nome: ");
  fgets(registros[pos].nome, 102, stdin);

  printf("Digite o telefone (formato: (XX) XXXX-XXXX): ");
  fgets(registros[pos].telefone, 18, stdin);

  printf("Digite o e-mail: ");
  fgets (registros[pos].email, 102, stdin);

  printf("Digite o sexo: ");
  //fgets (registros[pos].sexo, 1, stdin);
  scanf("%c", &registros[pos].sexo);

  printf("Digite a idade: ");
  //fgets (registros[pos].idade, 3, stdin);
  scanf("%d", &registros[pos].idade);

  printf("Digite o peso: ");
  //fgets(registros[pos].peso, 3, stdin);
  scanf("%f", &registros[pos].peso);

  printf("Digite a altura: ");
  //fgets(registros[pos].altura, 3, stdin);
  scanf("%f", &registros[pos].altura);

  registros[pos].vazio = 1;

}

void inicializar(){

    int cont = 0;

    while (cont < 1000) {
        registros[cont].vazio = 0;
        cont++;
    }

}

int verifica_pos() { //verificando posicao do vetor

  int cont = 0;

  while (cont<=1000) {

        if (registros[cont].vazio == 0)
           return(cont);

        cont++;
  }

}

void excluir(){

  int cont = 0;
  char nome[102];
  printf("****EXCLUIR CONTATO****\n");
  printf("Digite o nome da exclusao:\n");
  fgets(nome, 102, stdin);

  while (cont < 1000){

        if (strcmp(nome, registros[cont].nome) == 0){
           if (registros[cont].vazio == 1) {
              registros[cont].vazio = 0;
              printf("\nExclusao feita com sucesso\n");
              break;
           }
        }

        cont++;

        if (cont > 1000)
           printf("****Nome nao encontrado!****\n");

  }


}

void consultar(){

  int cont = 0;
  char nome[102];

  printf("****PESQUISAR CONTATO****\n");
  printf("Digite o nome da busca:\n");
  fgets (nome, 102, stdin);

  while (cont<=1000){

        if (strcmp(nome, registros[cont].nome) == 0){
           if (registros[cont].vazio == 1) {
              printf("%s\n", registros[cont].nome);
              printf("%s\n", registros[cont].telefone);
              printf("%s\n", registros[cont].email);
              printf("%c\n", registros[cont].sexo);
              printf("%d\n", registros[cont].idade);
              printf("%.2f\n", registros[cont].peso);
              printf("%.2f\n", registros[cont].altura);
              break;
           }
        }

        cont++;

        if (cont > 1000)
           printf("****Nome nao encontrado!****\n");

  }
}
