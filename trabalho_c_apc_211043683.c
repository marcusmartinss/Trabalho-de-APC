#include <stdio.h>
#include <locale.h>

// Função do layout do menu principal do programa.
int menu(int repeat)
{   
    setlocale(LC_ALL, "Portuguese");
    int num_menu;

    do
    {
        printf("     ______________________________________\n");
        printf("    |            Galactic Birds            |\n");
        printf("    |    'Sua confiança sob nossas asas'   |\n");
        printf("    |--------------------------------------|\n");
        printf("    | Menu de reservas espaciais           |\n");
        printf("    |--------------------------------------|\n");
        printf("    | 1) Cadastrar voo.                    |\n");
        printf("    | 2) Cadastrar reserva.                |\n");
        printf("    | 3) Consulta voo.                     |\n");
        printf("    | 4) Consultar reserva.                |\n");
        printf("    | 5) Consultar passageiro.             |\n");
        printf("    | 6) Cancelar voo.                     |\n");
        printf("    | 7) Cancelar reserva.                 |\n");
        printf("    | 8) Excluir voo.                      |\n");
        printf("    | 9) Sair do programa.                 |\n");
        printf("    |______________________________________|\n\n");

        printf("           Qual menu deseja acessar?\n");   
        printf("                      "); scanf("%d", &num_menu);

        switch (num_menu)
        {
            case 1:
                repeat = 0;
                system("cls");
                return num_menu;
                break;
            case 2: 
                repeat = 0;
                system("cls");
                return num_menu;
                break;
            case 3:
                repeat = 0;
                system("cls");
                return num_menu;
                break;
            case 4:
                repeat = 0;
                system("cls");
                return num_menu;
                break;
            case 5:
                repeat = 0;
                system("cls");
                return num_menu;
                break;
            case 6:
                repeat = 0;
                system("cls");
                return num_menu;
                break;
            case 7:
                repeat = 0;
                system("cls");
                return num_menu;
                break;
            case 8:
                repeat = 0;
                system("cls");
                return num_menu;
                break;
            case 9:
                repeat = 0;
                system("cls");
                return num_menu;
                break;
            default:
                system("cls");
                printf("\n\n            ERRO: Valor invalido!\n\n");
                repeat = 1;
        }

    } while (repeat == 1);

 return num_menu;
}


// Função Cadastrar voo.
void cadastrar_voo()
{
    FILE *arquivo;
    DATA data_voo;

    arquivo = fopen("dados_GalaticBirds.bin", "a+b");

    if (arquivo == NULL)
    {
        printf("ERRO! Não foi possível ler os dados.\n");
    }
    else
    {   
        fflush(stdin);
        printf("     ______________________________________\n");
        printf("    |            Galactic Birds            |\n");
        printf("    |    'Sua confianca sob nossas asas'   |\n");
        printf("    |--------------------------------------|\n");
        printf("    | Cadastrar voo                        |\n");
        printf("    |______________________________________|\n");
        printf("             Insira a data do voo:\n");
        printf("                    "); ("%d/%d/%d", &data_voo.dia, &data_voo.mes, &data_voo.ano);

        fclose(arquivo);

    }
    
    system("cls");
}


// Função Cadastrar reserva.
int cadastrar_reserva()
{
 return 0;
}


// Função Consultar voo.
int consultar_voo()
{
 return 0;
}


// Função Consultar reserva.
int consultar_reserva()
{
 return 0;
}


// Função Consultar passageiro.
int consultar_passageiro()
{
 return 0;
}


// Função Cancelar voo.
int cancelar_voo()
{
 return 0;
}


// Função Cancelar reserva.
int cancelar_reserva()
{
 return 0;
}


// Função Excluir voo.
int excluir_voo()
{
 return 0;
}

typedef struct data DATA;
struct data
{
    int dia;
    int mes;
    int ano;
};

// Função principal do programa.
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int num_menu, repeat = 1;

    do
    {
        num_menu = menu(repeat);

        if ( num_menu == 9)
        {
            repeat =  0;
        }
        else
        {
            switch(num_menu)
            {
                case 1:
                    cadastrar_voo();
                    break;
                case 2:
                    cadastrar_reserva();
                    break;
                case 3:
                    consultar_voo();
                    break;
                case 4:
                    consultar_reserva();
                    break;
                case 5:
                    consultar_passageiro();
                    break;
                case 6:
                    cancelar_voo();
                    break;
                case 7:
                    cancelar_reserva();
                    break;
                case 8:
                    excluir_voo();
                    break;
            }
        }
    }
    while(repeat == 1);

 return 0;
}