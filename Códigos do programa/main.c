#include <stdio.h>
#include <stdlib.h>
#define LINE 200 //CONSTANTE.

char nome[LINE][50]; //MATRIZ
int num[LINE], cpf[LINE]; //VETORES

int op, esc, LINHA, condSair; //VARIÁVEIS GLOBAIS

void cadastrar(); //PROTÓTIPO DA FUNÇÃO CADASTRO
void listar(); //PROTÓTIPO DA FUNÇÃO LISTAR
void buscar(); //PROTÓTIPO DA FUNÇÃO BUSCAR
void alterar();//PROTÓTIPO DA FUNÇÃO ALTERAR
void remover();//PROTÓTIPO DA FUNÇÃO REMOVER

void menu (){// FUNÇÃO MENU
	printf ("\n\tMENU\n\n");
	printf ("1. Cadastrar\n");
	printf ("2. Listar\n");
	printf ("3. Buscar\n");
	printf ("4. Alterar\n");
	printf ("5. Remover\n");
	printf ("6. Sair\n");

}
int main (void){ //INÍCIO MAIN
    do{
        system("cls"); //LIMPA A TELA DEPOIS DAS OPÇÕES SELECIONADAS
        menu();
        printf("\nEscolha uma opcao!\n");
        scanf("%d", &esc);
        switch(esc){
            case 1:
                cadastrar();
                break;
            case 2:
                listar();
                break;
            case 3:
                buscar();
                break;
            case 4:
                alterar();
                break;
            case 5:
                remover();
                getchar(); // PARA SEGURAR A IMAGEM NA TELA
                getchar();
                break;
            case 6:
                printf("\nVoce escolheu SAIR. Deseja mesmo encerrar o programa?");
                printf("\nSe sim, digite 1!");
                printf("\nSe nao, digite 0!\n");
                scanf("%d", &condSair);
                if (condSair==1){
                    system("exit");
                }else{
                    if (condSair==0){
                    main();}}
                break;
            default:
                printf("\nOpcao invalida!");
                printf("\nDigite um caractere valido!\n");
                getchar();
                getchar();

                break;
        }
    }while(esc!=6);
} // FIM DO MAIN

void cadastrar(int condCadastrar){ // FUNÇÂO CADASTRO
    static int linha;
    system("cls"); // FAZ LIMPAR A TELA
    printf("\n\tCadastrar\n");
    do{
       printf("\nNome: ");
       fflush(stdin); // COMANDO PARA LER OS ESPAÇOS
       scanf("%[^\n]s", &nome[linha]);
       printf("\nNumero: ");
       scanf("%d", &num[linha]);
       printf("\nCPF: ");
       scanf("%d", &cpf[linha]);
       printf("\nInformacoes do cadastro:\n");
       printf("\nNome: %s\nNumero: %d\nCPF: %d\n", nome[linha], num[linha], cpf[linha]);
       printf("\nDeseja armazenar o cadastro acima?");
       printf("\nSe sim, tecle 1!");
       printf("\nCaso nao queira, tecle 0!\n");
       scanf("%d", &condCadastrar);
       switch (condCadastrar){
            case 1:
                printf("\nCadastro concluido!\n");
                break;
            case 0:
                memset(&cpf[linha],0,sizeof(cpf[linha]));
                memset(&nome[linha],0,sizeof(nome[linha]));
                memset(&num[linha],0,sizeof(num[linha]));
                break;
            default:
                printf("\nOpcao invalida!\n");}
       printf("\nDigite 1 para continuar cadastrando ou 0 para voltar ao menu.\n");
       scanf("%d", &op);
       linha+=1;
    }while(op==1);
    LINHA = linha;
} //FIM DA FUNÇÃO CADASTRO

void listar(){ //INÍCIO DA FUNÇÃO LISTAR
    system("cls");
    int i;
    if (LINHA>0){
        printf("\nLista de cadastros:\n");
        for (i=0;i<LINHA;i++){
            if (cpf[i]>0){ // PERCORRE TODAS AS LINHAS DA MATRIZ E DOS VETORES
                printf("\nNome: %s\nNumero: %d\nCPF: %d\n", nome[i], num[i], cpf[i]);}
    }
    printf("\nDigite qualquer tecla para voltar ao menu!\n");
    getchar();
    getchar();
    }else{
        printf("\nNenhum cadastro encontrado!\n");
        printf("\nDigite qualquer tecla para voltar ao menu!\n");

    }system("pause");
}  //FIM DA FUNÇÃO LISTAR

void buscar(int pesquisaCPF){ // FUNÇÃO BUSCAR
    system("cls");
    printf("\n\tBuscar\n");
    int i;
    do{
        printf("\nDigite o CPF da pessoa cadastrada que deseja buscar!\n");
        scanf("%d", &pesquisaCPF);
        for (i=0;i<LINE;i++){
            if (pesquisaCPF==cpf[i]){
                printf("\nInformacoes do cadastro:\n");
                printf("\nNome: %s\nNumero: %d\nCPF: %d\n", nome[i], num[i], cpf[i]);}
        }
        printf("\nDigite 1 para continuar ou 0 voltar ao menu.\n");
        scanf("%d", &op);
    }while(op==1);
} // FIM DA FUNÇÃO BUSCAR

void alterar(){ // INÍCIO DA FUNÇÃO ALTERAR
    system("cls");
    do{
    printf("\n\tAlterar\n");
    static int linha;
    int i, condAlterar, alterarcpf;
    printf("\nDigite o CPF do cadastro que deseja alterar!\n");
    scanf("%d", &alterarcpf);
    for (i=0;i<LINHA;i++){
        if (alterarcpf==cpf[i]){
        printf("\nInformacoes do cadastro:\n");
        printf("\nNome: %s\nNumero: %d\nCPF: %d\n", nome[i], num[i], cpf[i]);
        printf("\nTem certeza que deseja alterar o dadastro acima?");
        printf("\nSe sim, tecle 1!");
        printf("\nCaso nao, tecle 0!\n");
        scanf("%d", &condAlterar);
            switch(condAlterar){
            case 1:
                printf("\nNovo nome: ");
                fflush(stdin);
                scanf("%[^\n]s", &nome[i]);
                printf("\nNovo numero: ");
                scanf("%d", &num[i]);
                printf("\nNovo CPF: ");
                scanf("%d", &cpf[i]);
                printf("\nCadastro Alterado!\n");
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;}
        }
    }
    printf("\nDigite 1 para continuar ou 0 para voltar ao menu.\n");
    scanf("%d", &op);
    }while(op==1);
} //FIM DA FUNÇÃO ALTERAR

void remover(int removercpf){ // INÍCIO DA FUNÇÃO REMOVER
    system("cls");
    do{
    int i, condRemover;
    printf("\nDigite o CPF do cadastro que deseja remover!!\n");
    scanf("%d", &removercpf);
    for (i=0;i<LINHA;i++){
        if (removercpf==cpf[i]){
            printf("\nInformacoes do cadastro:\n");
            printf("\nNome: %s\nNumero: %d\nCPF: %d\n", nome[i], num[i], cpf[i]);
            printf("\nTem certeza que deseja excluir o dadastro acima?");
            printf("\nSe sim, tecle 1!");
            printf("\nCaso nao, tecle 0!\n");
            scanf("%d", &condRemover);
            switch(condRemover){
            case 1:
                memset(&cpf[i],0,sizeof(cpf[i]));
                memset(&nome[i],0,sizeof(nome[i]));
                memset(&num[i],0,sizeof(num[i]));
                printf("\nCadastro excluido!\n");
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;}
        }
    }
    printf("\nDigite 1 para continuar ou 0 para voltar ao menu.\n");
    scanf("%d", &op);
    }while(op==1);
} // FIM DA FUNÇÃO REMOVER
