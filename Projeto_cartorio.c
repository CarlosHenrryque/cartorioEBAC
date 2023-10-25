#include <stdio.h> //Biblioteca de comunicação com usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistemas
{
	//ninício da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [100];
	//final da criação de variáveis/strings
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cpf); //%s difere-se a strings
	
	strcpy(arquivo,cpf); // Responsável por copiar os valores da string
	
	FILE *file; //Cria o arquivo na base de dados
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file, ","); //Separação dos dados por "," (Vírgula)
	fclose(file); //Fechar o arquivo
	
	printf("Digite o nome a ser Cadastrado: "); //Coletando informação do usuário
	scanf("%s",nome); //%s difere-se a strings
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file,nome); //Abrindo o arquivo e atribuindo a váriavel nome
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file, ","); //Separação dos dados por "," (Vírgula)
	fclose(file); //Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",sobrenome); //%s difere-se a strings
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file,sobrenome); //Abrindo o arquivo e atribuindo a váriavel sobrenome
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file, ","); //Separação dos dados por "," (Vírgula)
	fclose(file); //Fechando o arquivo
	
	printf("Digite o cargo a ser Cadastrado: "); //Coletando informação do usuário
	scanf("%s",cargo); //%s difere-se a strings
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa acessar arquivo e alterar
	fprintf(file,cargo); //Abrindo o arquivo e atribuindo a váriavel cargo
	fclose(file); //Fechando o arquivo
	
	system("pause"); // Pausando o programa
}

int consulta() //Criando uma instância com o nome de consulta
{
	//ninício da criação de variáveis/strings
	char cpf[40];
	char conteudo[100];
	//final da criação de variáveis/strings
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário
	scanf("%s",cpf); //%s difere-se a strings
  	
	FILE *file; //Cria o arquivo na base de dados
	file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa "pesquisar"
  	
	if(file == NULL) //Função para se não encontrar a informação desejada retornar mensagem de erro
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //Mensagem de erro retornada ao usuário
	}
	
	while(fgets(conteudo, 100, file) != NULL) //Função para se  encontrar a informação desejada retornar mensagem descrita no (printf)
	{	
		printf("\nEssas são as informações do usuário: "); //Mensagem retornada ao usuário
		printf("%s",conteudo); //%s difere-se a strings
		printf("\n\n"); //Pulando linhas cada "\n" é uma linha
	}
  	
system ("pause"); //Pausando o programa
}


int deletar() //Criando uma instância com o nome de deletar
{
	//ninício da criação de variáveis/strings
	char cpf[40]; 
	//final da criação de variáveis/strings
	printf("Digite o CPF do usuário a ser deletado: "); //Coletando informação do usuário
	scanf("%s",cpf); //%s difere-se a strings
	
	remove(cpf); //Removendo as infromações do banco de dados
	
	FILE *file; //abrir o arquivo na base de dados
	file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa "pesquisar"
	
	if(file == NULL) //Funções informando o que fazer caso não encontre o usuário
	{
		printf("Usuário não encontrado na base de dados!.\n\n"); //Mensagem retornada ao usuário
		system("pause"); //Pausando o programa
	}
}

int main() //Definindo váriáveis
	{
	int opcao=0; //Definindo váriáveis
	int laco=1; //Definindo váriáveis
	
	for(laco=1;laco=1;) //definindo laço de repetição
	{
		system("cls"); //limpando a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
		
		printf("\t### Cartório da EBAC ###\n\n"); //Início do Menu.
		printf("Escolha a opção desejada do menu:\n\n"); //Menu
		printf("\t1 - Registrar nomes\n\n"); //Opão 1 do menu
		printf("\t2 - Consultar nomes\n\n"); //Opão 2 do menu
		printf("\t3 - Deletar nomes\n\n"); //Opão 3 do menu
		printf("\t4 - Sair do sistema\n\n"); //Opção de sair do sistema
		printf("Opção:  "); //fim do menu
		
		scanf("%d",&opcao); //Armazenando a escolha do usuário
		
		system("cls"); //limpando a tela
		
		switch(opcao) //Início da seleção do Menu
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
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default: 
			printf("Essa opção não está disponível!\n\n"); //Mensagem retornada ao usuário caso o mesmo não selecione uma opção válida
			system("pause"); //Pausando o programa
			break; //Finalizando o programa			
		}
	}
}
