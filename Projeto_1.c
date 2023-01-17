#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por registro
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registry() //func�o para cadastrar usu�rios
{
	setlocale(LC_ALL, "Portuguese");
	
	 int k = 0;

	//in�cio de cria��o de vari�veis	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis 
	
	printf("Digite o CPF a ser cadastrado: "); //coleta de informa��o 
	scanf("%s", cpf);//%s refere-se a string
		
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
		
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//abre um arquivo com o nome do arquivo(cpf) "w" escreve arquivo - write
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //adiciona as informa��es
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
		
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
		
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
		
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
		
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
		
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
		
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
		
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
		
}

int search() //fun��o para localizar usu�rio
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //l� o arquivo
	
	if(file == NULL) //verifica a exist�ncia do arquivo
	{
		printf("N�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}

int delet() // fun��o para deletar usu�rio
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);

	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //verifica a exist�ncia do arquivo
	{
		printf("Arquivo n�o encontrado.\n\n");
		system("pause");
	}
	
	if(file != NULL) //se existir, fecha o arquivo e logo depois deleta
	{
		fclose(file);
		remove(cpf); //colocando aqui, a mensagem de n�o encontrado n�o aparece, apenas se n�o existir mesmo o arquivo anteriormente
		printf("Arquivo deletado com suce�o.\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao = 0; //definindo a vari�vel de op��o
	int i = 1;
	
	char senhadigitada[10] = "";
	int comparacao;//vari�vel para comparar strings
	
	printf("### Cart�rio da EBAC ###\n\n"); //tela de login
	printf("Login de administrador.\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //comaprando senha digitada com a senha cadastrada
	
	if(comparacao ==0)
	{
		system("cls");
		for(i = 1; i = 1;)
		{
			system("cls");
			
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
			
			
			printf("### Cart�rio da EBAC ###\n\n"); //nome do menu - in�cio
			
			printf("Escolha a op��o desejada no menu: \n\n");
			
			printf("\t1 - Resgistrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair\n\n");
			printf("Op��o: "); //final do menu
			
			scanf("%d", &opcao); //input da vari�vel no console
			
			system("cls"); //limpando o console
			
			switch(opcao)//in�cio da valida��o da vari�vel
			{
				case 1:
					registry();// chamada das fun��es
					break;
					
				case 2:
					search();
					break;
				
				case 3:
					delet();
					break;
				
				case 4:
					exit(0);
					break;
					
				default:
					printf("Voc� escolheu uma op��o inv�lida.\n\n");
					system("pause");
					break; //final da valida��o da vari�vel
			}
		}
	}
	
	else
	{
		printf("Senha incorreta!");
	}
}
