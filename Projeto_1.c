#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por registro
#include <string.h> //biblioteca responsável por cuidar das strings

int registry() //funcão para cadastrar usuários
{
	setlocale(LC_ALL, "Portuguese");
	
	 int k = 0;

	//início de criação de variáveis	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis 
	
	printf("Digite o CPF a ser cadastrado: "); //coleta de informação 
	scanf("%s", cpf);//%s refere-se a string
		
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
		
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//abre um arquivo com o nome do arquivo(cpf) "w" escreve arquivo - write
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //adiciona as informações
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

int search() //função para localizar usuário
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //lê o arquivo
	
	if(file == NULL) //verifica a existência do arquivo
	{
		printf("Não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}

int delet() // função para deletar usuário
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);

	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //verifica a existência do arquivo
	{
		printf("Arquivo não encontrado.\n\n");
		system("pause");
	}
	
	if(file != NULL) //se existir, fecha o arquivo e logo depois deleta
	{
		fclose(file);
		remove(cpf); //colocando aqui, a mensagem de não encontrado não aparece, apenas se não existir mesmo o arquivo anteriormente
		printf("Arquivo deletado com suceço.\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao = 0; //definindo a variável de opção
	int i = 1;
	
	char senhadigitada[10] = "";
	int comparacao;//variável para comparar strings
	
	printf("### Cartório da EBAC ###\n\n"); //tela de login
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
			
			
			printf("### Cartório da EBAC ###\n\n"); //nome do menu - inï¿½cio
			
			printf("Escolha a opção desejada no menu: \n\n");
			
			printf("\t1 - Resgistrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair\n\n");
			printf("Opção: "); //final do menu
			
			scanf("%d", &opcao); //input da variável no console
			
			system("cls"); //limpando o console
			
			switch(opcao)//início da validação da variável
			{
				case 1:
					registry();// chamada das funções
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
					printf("Você escolheu uma opção inválida.\n\n");
					system("pause");
					break; //final da validação da variável
			}
		}
	}
	
	else
	{
		printf("Senha incorreta!");
	}
}
