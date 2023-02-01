#include <stdio.h> //biblioteca do cominica��o com o usu�rio (biblioteca que ultiliza somente texto)
#include <stdlib.h> //biblioteca de aloca�ao de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //bib�ioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{	

	setlocale(LC_ALL, "Portuguese");

	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a informa��o do usu�rio
	scanf("%s", cpf); //"%s" refere-se a string
	
	printf("\n\n");
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings (copiou o CPF para inserir o nome do arquivo {CPF = arquivo})
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //o "w" serve para criar o arquivo e escever nele (write)
	fprintf(file, "("); //descri��o da informa��o
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a"); // o "a" serve para atualizar e inserir dados no arquivo
	fprintf(file,") ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Solicita a informa��o do usu�rio
	scanf("%s",nome); //Armazena a informa��o do usu�rio
	
	printf("\n\n");
	
	file = fopen(arquivo, "a"); //Abre o arquivo ("a" escreve no arquivo)
	fprintf(file,nome); //Escreve a informa��o salva na vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Solicita a informa��o do usu�rio
	scanf("%s",sobrenome); //Armazena a informa��o do usu�rio
	
	printf("\n\n");
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file, sobrenome); //Escreve a informa��o salva na vari�vel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," - ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //Solicita a informa��o do usu�rio
	scanf("%s", cargo); //Armazena a informa��o do usu�rio
	
	printf("\n\n");
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,cargo); //Escreve a informa��o salva na vari�vel
	fclose(file);

	printf("Cadastro realizado com sucesso!\n\n");
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r"); //o "r" serve para ler(read) e consultar informa��es no arquivo
	
	if(file == NULL) //Validando se a infoma��o foi encontrada no arquivo n�o � nula
	{
		printf("N�o foi poss�vel abrir o arquivo, CPF n�o localizado.\n\n");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL) //Salvando na vari�vel "conteudo" as informa��es que est�o dentro do arquivo
	{
		printf("Essas s�o as informa��es do usu�rio:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\n");
		printf("CPF n�o localizado no sistema\n\n");
		system("pause");
	}

	else
	{		
		remove(cpf);
		printf("\n");
		printf("Arquivo deletado com sucesso\n\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //Definindo vari�veis ("int" � porque � uma variavel de n�mero inteiro)
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	 system("cls");

	 setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	 
	 printf("###Cart�rio da EBAC###\n\n"); //in�cio do menu
	 printf("Escolha a op��o desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");
	 printf("Op��o: "); //fim do menu
	 
	  scanf("%d", &opcao); //armazenando a escolha do usu�rio ("%d" para armezenar uma vari�vel de tipo inteiro)
	 
	  system("cls"); //respons�vel por limpar a tela
	 
	 
	 switch(opcao) //inicio da sele��o
	   {
	 	 case 1:
	     registro(); //chamada de fun��es
		 break;
		 
		 case 2:
		 consulta(); //chamada de fun��es
	 	 break;
	 	 
	 	 case 3:
	 	 deletar(); //chamada de fun��es
	 	 break;
	 	 
	 	 default:
	 	 printf("Essa op��o n�o est� dispon�vel\n\n");
	 	 system("pause");
		 break;
		 
		}//fim da sele��o
	 
    }
}
