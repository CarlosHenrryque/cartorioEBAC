#include <stdio.h> //Biblioteca de comunica��o com usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistemas
{
	//nin�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [100];
	//final da cria��o de vari�veis/strings
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); //%s difere-se a strings
	
	strcpy(arquivo,cpf); // Respons�vel por copiar os valores da string
	
	FILE *file; //Cria o arquivo na base de dados
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file, ","); //Separa��o dos dados por "," (V�rgula)
	fclose(file); //Fechar o arquivo
	
	printf("Digite o nome a ser Cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",nome); //%s difere-se a strings
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file,nome); //Abrindo o arquivo e atribuindo a v�riavel nome
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file, ","); //Separa��o dos dados por "," (V�rgula)
	fclose(file); //Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",sobrenome); //%s difere-se a strings
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file,sobrenome); //Abrindo o arquivo e atribuindo a v�riavel sobrenome
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file, ","); //Separa��o dos dados por "," (V�rgula)
	fclose(file); //Fechando o arquivo
	
	printf("Digite o cargo a ser Cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cargo); //%s difere-se a strings
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file,cargo); //Abrindo o arquivo e atribuindo a v�riavel cargo
	fclose(file); //Fechando o arquivo
	
	system("pause"); // Pausando o programa
}

int consulta() //Criando uma inst�ncia com o nome de consulta
{
	//nin�cio da cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[100];
	//final da cria��o de vari�veis/strings
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); //%s difere-se a strings
  	
	FILE *file; //Cria o arquivo na base de dados
	file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa "pesquisar"
  	
	if(file == NULL) //Fun��o para se n�o encontrar a informa��o desejada retornar mensagem de erro
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //Mensagem de erro retornada ao usu�rio
	}
	
	while(fgets(conteudo, 100, file) != NULL) //Fun��o para se  encontrar a informa��o desejada retornar mensagem descrita no (printf)
	{	
		printf("\nEssas s�o as informa��es do usu�rio: "); //Mensagem retornada ao usu�rio
		printf("%s",conteudo); //%s difere-se a strings
		printf("\n\n"); //Pulando linhas cada "\n" � uma linha
	}
  	
system ("pause"); //Pausando o programa
}


int deletar() //Criando uma inst�ncia com o nome de deletar
{
	//nin�cio da cria��o de vari�veis/strings
	char cpf[40]; 
	//final da cria��o de vari�veis/strings
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); //%s difere-se a strings
	
	remove(cpf); //Removendo as infroma��es do banco de dados
	
	FILE *file; //abrir o arquivo na base de dados
	file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa "pesquisar"
	
	if(file == NULL) //Fun��es informando o que fazer caso n�o encontre o usu�rio
	{
		printf("Usu�rio n�o encontrado na base de dados!.\n\n"); //Mensagem retornada ao usu�rio
		system("pause"); //Pausando o programa
	}
}

int main() //Definindo v�ri�veis
	{
	int opcao=0; //Definindo v�ri�veis
	int laco=1; //Definindo v�ri�veis
	
	for(laco=1;laco=1;) //definindo la�o de repeti��o
	{
		system("cls"); //limpando a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
		
		printf("\t### Cart�rio da EBAC ###\n\n"); //In�cio do Menu.
		printf("Escolha a op��o desejada do menu:\n\n"); //Menu
		printf("\t1 - Registrar nomes\n\n"); //Op�o 1 do menu
		printf("\t2 - Consultar nomes\n\n"); //Op�o 2 do menu
		printf("\t3 - Deletar nomes\n\n"); //Op�o 3 do menu
		printf("\t4 - Sair do sistema\n\n"); //Op��o de sair do sistema
		printf("Op��o:  "); //fim do menu
		
		scanf("%d",&opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //limpando a tela
		
		switch(opcao) //In�cio da sele��o do Menu
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
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default: 
			printf("Essa op��o n�o est� dispon�vel!\n\n"); //Mensagem retornada ao usu�rio caso o mesmo n�o selecione uma op��o v�lida
			system("pause"); //Pausando o programa
			break; //Finalizando o programa			
		}
	}
}
