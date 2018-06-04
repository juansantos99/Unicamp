#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#define TAM 1000

typedef struct Contato{

    char nome[102];
    char telefone[22];
    char email[52];
    char sexo;
    int idade;
    float peso;
    float altura;
    int vazio; //VAZIO = 0 e DISPONIVEL = 1.
}Registros;

Registros registros[1000];

void cadastrar();
void excluir();
void consultar();
void visualizar();
//void zerar(); //excluir contato

int main() {

    int opcao = -999; //opcao para selecao da agenda, qual menu selecionar
    for (int i = 0; i < 1000; i++) {
		registros[i].vazio = 0;
    }
    
    while (opcao!=0) {

    printf("****MENU AGENDA ELETRONICA****\n");
    printf("1: Adicionar contato\n");
    printf("2: Excluir contato\n");
    printf("3: Pesquisar contato\n");
    printf("4: Visualizar todos os contatos\n");
    printf("0: Sair!\n");

    scanf ("%d", &opcao);
    //__fpurge(stdin);
    getchar();

    if(opcao == 1){
			cadastrar();
		} else if (opcao == 2) {
			excluir();
		} else if (opcao == 3) {
			consultar();
		} else if (opcao == 4) {
			visualizar();
		} else if (opcao == 0) {
			break;
		} else {
			printf("****Opcao Invalida, tentar novamente****\n");
		}
	}
	return 0;
}

void cadastrar (){ //cadastrando o contato

  int pos;
	for (pos = 0; pos < 1000; pos++) {
		if (registros[pos].vazio == 0) {
			break;
		}
	}

  //printf("Valor de pos: %d\n", pos);
  printf("****ADICIONAR CONTATO****\n");

  printf("Digite o nome:\n");
  fgets(registros[pos].nome,102,stdin);

  printf("Digite o telefone (formato: (XX) XXXX-XXXX):\n");
  fgets(registros[pos].telefone,22,stdin);

  printf("Digite e-mail:\n");
  fgets (registros[pos].email,52,stdin);

  printf("Digite o sexo:\n");
  //fgets (registros[pos].sexo, 1, stdin);
  registros[pos].sexo = getchar();

  printf("Digite a idade:\n");
  //fgets (registros[pos].idade, 3, stdin);
  scanf("%d", &registros[pos].idade);

  printf("Digite o peso:\n");
  //fgets(registros[pos].peso, 3, stdin);
  scanf("%f", &registros[pos].peso);

  printf("Digite a altura:\n");
  //fgets(registros[pos].altura, 3, stdin);
  scanf("%f", &registros[pos].altura);

  registros[pos]. vazio = 1;

}

void excluir(){

	int cont;
	char nome[102];
	printf("****EXCLUIR CONTATO****\n");
	printf("Digite o nome da exclusao:\n");
	fgets(nome, 102, stdin);

	for (cont = 0; cont < 1000; cont++) {
		if (strcmp(nome, registros[cont].nome) == 0){
			if (registros[cont].vazio == 1) {
				registros[cont].vazio = 0;
				break;
			}
		}

		if (cont == 999){
			if(strcmp(nome, registros[cont].nome) != 0){
				printf("****Nome nao encontrado!****\n");
			}
		}
	}
}

void consultar(){

	int cont;
	char nome[102];
	printf("****PESQUISAR CONTATO****\n");
	printf("Digite o nome da busca:\n");
	fgets(nome, 102, stdin);

	for (cont = 0; cont < 1000; cont++) {
		if (strcmp(nome, registros[cont].nome) == 0){
			if (registros[cont].vazio == 1) {
				printf("%s", registros[cont].nome);
				printf("%s", registros[cont].telefone);
				printf("%s", registros[cont].email);
				printf("%c\n", registros[cont].sexo);
				printf("%d\n", registros[cont].idade);
				printf("%.2f\n", registros[cont].peso);
				printf("%.2f\n", registros[cont].altura);
				break;
			}
		}

		if (cont == 999){
			if(strcmp(nome, registros[cont].nome) != 0){
				if(registros[cont].vazio != 1){
					printf("****Nome nao encontrado!****\n");
				}
			}
		}
	}
}

void visualizar(){
	printf("****VISUALIZAR TODOS OS CONTATOS****\n");
	int x, v, tamanho = 0;
 	char auxi[102];
	for (int i = 0, count = 0; i < 1000; i++) {
		if (registros[i].vazio == 1) {
			tamanho++;
		}
		if (registros[i].vazio != 1) {
			count++;
		}
		if (count == 1000 && registros[i]. vazio != 1) {
			printf("****Agenda Vazia!****\n");
		}
	}
	char vauxi[tamanho][102];
	for (int p = 0, pv = 0; p < 1000; p++) {
		if (registros[p].vazio == 1) {
			strcpy(vauxi[pv], registros[p].nome);
			pv++;
		}
	}
 	for (x = 0; x < tamanho; x++) {
		for (v = 0; v < tamanho-1; v++) {
			if(strcmp(vauxi[v], vauxi[v+1]) > 0){
				strcpy(auxi, vauxi[v+1]);
				strcpy(vauxi[v+1], vauxi[v]);
				strcpy(vauxi[v], auxi);
			}
		}
	}
	for (int a = 0; a < tamanho; a++) {
		for (int b = 0; b < 1000; b++) {
			if (strcmp(registros[b].nome, vauxi[a]) == 0) {
				printf("%s", registros[b].nome);
				printf("%s", registros[b].telefone);
				printf("%s", registros[b].email);
				printf("%c\n", registros[b].sexo);
				printf("%d\n", registros[b].idade);
				printf("%.2f\n", registros[b].peso);
				printf("%.2f\n", registros[b].altura);
				break;
			}
		}
	}
}
