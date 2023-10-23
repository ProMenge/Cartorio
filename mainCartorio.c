#include <stdio.h> //Biblioteca de comunicacao com usuario
#include <stdlib.h> //Biblioteca de alocacao de espaco de memoria
#include <locale.h> //Biblioteca de alocacao de texto
#include <string.h> //biblioteca responsável por cuidar das strings


int registro(){ //Função de registrar usuários no banco 

    char cpf[40];
    char nome [50];
    char sobrenome[40];
    char cargo [30];
    char arquivo [40];

    printf("Digite o CPF a ser cadastrado:");
    scanf("%s", cpf); // %s salva o valor na variavel referenciada

    strcpy(arquivo, cpf); //Copia o cpf no arquivo 

    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo 
    fprintf(file,cpf); //salva o valor da varieavel
    fclose(file);  //fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);

    system("pause");
   
    
}

int consulta(){ //Função de consulta de usuários no abnco

    char cpf[40];
    char  conteudo[200];

    setlocale(LC_ALL, "Portuguese"); //definindo lingua

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf); // %s salva o valor na variavel referenciada

    FILE *file; //acesso ao arquivo 
    file = fopen(cpf, "r"); //abre o arquivo cuja o nome é cpf e le ele r=read

    if(file == NULL){

        printf("Não foi possível abrir o arquivo, não localizamos o arquivo");
    }
    while(fgets(conteudo, 200, file) != NULL){  //vai buscar informação enquanto (fgets busca o arquivo) estiver escrevendo dentro de conteudo até 200 carcteres de dentro do file 

        printf("\n Essas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }



    system("pause");
    
}

int deletar(){ //Função de apagar usuários do banco

    char cpf[40];

    setlocale(LC_ALL, "Portuguese"); //definindo lingua

    printf("Digite o CPF do usuário a ser apagado: ");
    scanf("%s", cpf); // %s salva o valor na variavel referenciada


  

    FILE *file;
    file = fopen(cpf, "r"); //Abre e le o arquivo de nome "cpf"


    if(file == NULL){
        printf("Arquivo inexistente - usuário não encontrado e portantando não foi apagado. \n");
        system("pause");
        return 1; // retorna 1 indicando que o arquivo não foi encontrado
    } else {
        fclose(file); // Fecha o arquivo antes de removê-lo
        remove(cpf); // remove o arquivo
        printf("Usuário removido com sucesso. \n");
        system("pause");
        return 0; // retorna 0 indicando que o arquivo foi removido com sucesso
    }
    


}



int main(){

    int opcao=0; //definição de variavel
    int laco=1;


    for(laco=1; laco=1;){


        system("cls");
    
        setlocale(LC_ALL, "Portuguese"); //definindo lingua


        printf("##### Cartorio da EBAC ##### \n\n");        // inicio menu
        printf("Escolha a opcao desejada no menu\n\n");
        printf("\t 1 - Registrar nomes \n");
        printf("\t 2 - Consultar nomes \n");
        printf("\t 3 - Deletar nomes \n");
        printf("\t 4 - Sair do sistema  \n \n");                // final do menu

        printf("Digite a opção:");      //armazenando escolha do usuário

        scanf("%d", &opcao);

        system("cls");

        switch (opcao)
        {
            case 1:
            registro();
            break;

            case 2:
            consulta();
            break;

            case 3:
            deletar();
            break;

            case 4:
            printf("Obrigado por utilizar o sistema. \n \n");
            return 0;
            break;

            default:
            printf("Opção indisponível \n\n");
            system("pause");
            break;

        
        }

        printf("\n \n Esse Software é de livre uso dos alunos");


    }

}