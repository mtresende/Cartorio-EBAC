#include <stdio.h> //biblioteca do cominicação com o usuário (biblioteca que ultiliza somente texto)
#include <stdlib.h> //biblioteca de alocaçao de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //bibçioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{	

	setlocale(LC_ALL, "Portuguese");

	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a informação do usuário
	scanf("%s", cpf); //"%s" refere-se a string
	
	printf("\n\n");
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings (copiou o CPF para inserir o nome do arquivo {CPF = arquivo})
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //o "w" serve para criar o arquivo e escever nele (write)
	fprintf(file, "("); //descrição da informação
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a"); // o "a" serve para atualizar e inserir dados no arquivo
	fprintf(file,") ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Solicita a informação do usuário
	scanf("%s",nome); //Armazena a informação do usuário
	
	printf("\n\n");
	
	file = fopen(arquivo, "a"); //Abre o arquivo ("a" escreve no arquivo)
	fprintf(file,nome); //Escreve a informação salva na variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Solicita a informação do usuário
	scanf("%s",sobrenome); //Armazena a informação do usuário
	
	printf("\n\n");
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file, sobrenome); //Escreve a informação salva na variável
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," - ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //Solicita a informação do usuário
	scanf("%s", cargo); //Armazena a informação do usuário
	
	printf("\n\n");
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,cargo); //Escreve a informação salva na variável
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
	file = fopen(cpf,"r"); //o "r" serve para ler(read) e consultar informações no arquivo
	
	if(file == NULL) //Validando se a infomação foi encontrada no arquivo não é nula
	{
		printf("Não foi possível abrir o arquivo, CPF não localizado.\n\n");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL) //Salvando na variável "conteudo" as informações que estão dentro do arquivo
	{
		printf("Essas são as informações do usuário:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\n");
		printf("CPF não localizado no sistema\n\n");
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
	int opcao=0; //Definindo variáveis ("int" é porque é uma variavel de número inteiro)
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	 system("cls");

	 setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	 
	 printf("###Cartório da EBAC###\n\n"); //início do menu
	 printf("Escolha a opção desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");
	 printf("Opção: "); //fim do menu
	 
	  scanf("%d", &opcao); //armazenando a escolha do usuário ("%d" para armezenar uma variável de tipo inteiro)
	 
	  system("cls"); //responsável por limpar a tela
	 
	 
	 switch(opcao) //inicio da seleção
	   {
	 	 case 1:
	     registro(); //chamada de funções
		 break;
		 
		 case 2:
		 consulta(); //chamada de funções
	 	 break;
	 	 
	 	 case 3:
	 	 deletar(); //chamada de funções
	 	 break;
	 	 
	 	 default:
	 	 printf("Essa opção não está disponível\n\n");
	 	 system("pause");
		 break;
		 
		}//fim da seleção
	 
    }
}
