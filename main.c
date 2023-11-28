#include <stdio.h>
#include <locale.h>
//DECLARAÇÃO DA STRUCT
typedef struct{
    int id;
    char date[10];
    char combustivel[10];
    char tipo[10];
    int quantLitro;
    float precoLitro;
} Combustivel;

//DECLARAÇÃO DAS FUNÇÕES
void mostraMenu();
void inicializaVetor(Combustivel combustiveis[]);
void cadastraCombustivel(Combustivel *combustivel, int ultimoValor);
void listaCombustivel(Combustivel combustiveis[]);
void alteraCombustivel(Combustivel *combustivel);
void deletaCombustivel(Combustivel *combustivel);
int achaUltimoValor(Combustivel combustiveis[]);

Combustivel *achaPosicao(Combustivel combustiveis[]);
Combustivel *achaCombustivel(Combustivel combustiveis[],int id);

//FUNÇÃO PRINCIPAL
int main()
{

    setlocale(LC_ALL,"");
    //COMEÇO DA DECLARAÇÃO DAS VARIÁVEIS
    int opcao,id_combustivel;
    Combustivel combustiveis[100];
    //FIM DA DECLARAÇÃO DAS VARIÁVEIS
    inicializaVetor(combustiveis);

    while(1){
        mostraMenu();
        scanf("%i",&opcao);

        if(opcao == 1)
        {
            Combustivel *valor = achaPosicao(combustiveis);
            cadastraCombustivel(valor,achaUltimoValor(combustiveis));         
        }else if(opcao == 2)
        {
            printf("Digite o ID do Combustivel: ");
            scanf("%i",&id_combustivel);
            alteraCombustivel(achaCombustivel(combustiveis,id_combustivel));
        }else if(opcao == 3)
        {
            printf("Digite o ID do Combustivel: ");
            scanf("%i",&id_combustivel);
            deletaCombustivel(achaCombustivel(combustiveis,id_combustivel));
        }
        else if(opcao == 4)
        {
            listaCombustivel(combustiveis);
        }else if(opcao == 99){
            break;
        }
    }
    return 0;
}


//IMPLEMENTAÇÃO DAS FUNÇÕES
void mostraMenu()
{
    printf("=======================================\n");
    printf("Sistema de Gerenciamento de Combustivel\n");
    printf("=======================================\n");
    printf("Digite uma opcao\n");

    printf("1 - Cadastrar\n");
    printf("2 - Alterar\n");
    printf("3 - Excluir\n");
    printf("4 - Listar(Relatorio)\n");
    printf("99 - Sair\n");
}

void inicializaVetor( Combustivel combustiveis[])
{
    for(int i = 0; i < 100; i++)
    {
        combustiveis[i].id = 0;

    }
}

void cadastraCombustivel(Combustivel *combustivel,int ultimoValor)
{
    combustivel->id = ultimoValor + 1; 
    printf("Digite a data no formato dd/mm/yyyy: ");
    scanf("%s",&combustivel->date);
    printf("Digite o nome de combustivel(Gasolina/Alcool/Diesel): ");
    scanf("%s",&combustivel->combustivel);
    printf("Digite o tipo de combustivel(Comum/Aditivada): ");
    scanf("%s",&combustivel->tipo);
    printf("Digite o preço do Litro: ");
    scanf("%f",&combustivel->precoLitro);
    getchar();
    printf("Digite a quantidade de Litros: ");
    scanf("%i",&combustivel->quantLitro);

    printf("Combustivel cadastrado com o id %i!\n",combustivel->id);
}

Combustivel *achaPosicao(Combustivel combustiveis[])
{
    for(int i = 0; i < 100; i ++)
    {
        if(combustiveis[i].id == 0) return &combustiveis[i];
        
    }
}

void listaCombustivel(Combustivel combustiveis[])
{
    printf("==================================================================\n");
    printf("|    ID     |    NOME     |    TIPO   |   PRECO   |  QUANTIDADE   |\n");
    printf("==================================================================\n");
    for(int i = 0; i < 100; i++)
    {
        if(combustiveis[i].id != 0)
        {
            printf("\t%i\t", combustiveis[i].id);
            printf("%s\t",   combustiveis[i].combustivel);
            printf("%s\t",   combustiveis[i].tipo);
            printf("%f\t",   combustiveis[i].precoLitro);
            printf("%i\t\n", combustiveis[i].quantLitro);
        }
        
    }
}

int achaUltimoValor(Combustivel combustiveis[])
{
    int ultimoValor = 0;
    for(int i = 0; i < 100; i++)
    {
        if( i != 0)
        {
            if(combustiveis[i].id > combustiveis[i-1].id) ultimoValor = combustiveis[i].id;
        }
    }
    return ultimoValor;

}

Combustivel *achaCombustivel(Combustivel combustiveis[], int id)
{
    for(int i = 0; i < 100; i++)
    {
        if(id == combustiveis[i].id){
            return &combustiveis[i];
        }
    }
}

void alteraCombustivel(Combustivel *combustivel)
{
    printf("Digite a data no formato dd/mm/yyyy: ");
    scanf("%s",&combustivel->date);
    printf("Digite o nomne de combustivel(Gasolina/Alcool/Diesel): ");
    scanf("%s",&combustivel->combustivel);
    printf("Digite o tipo de combustivel(Comum/Aditivada): ");
    scanf("%s",&combustivel->tipo);
    printf("Digite o preço do Litro: ");
    scanf("%f",&combustivel->precoLitro);
    getchar();
    printf("Digite a quantidade de Litros: ");
    scanf("%i",&combustivel->quantLitro);

    printf("Combustivel alterado!\n");
}

void deletaCombustivel(Combustivel *combustivel)
{
    combustivel->id                = 0;
    combustivel->date[0]           = '\0';
    combustivel->combustivel[0]    = '\0';
    combustivel->precoLitro        = 0.0;
    combustivel->quantLitro        = 0;
    combustivel->tipo[0]           = '\0';

    printf("Combustível deletado.\n");

}