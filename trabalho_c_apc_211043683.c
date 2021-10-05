#include <stdio.h>
#include <stdlib.h>

typedef struct data DATA;
struct data
{
    int dia;
    int mes;
    int ano;
};

typedef struct voo VOO;
struct voo
{
    char num_voo[9];
    int  max_passageiros;
    int  dia;
    int  mes;
    int  ano;
    int  status;
};

// Função do layout do menu principal do programa.
int menu(int repeat)
{   
    int num_menu;

    do
    {
        printf("     ______________________________________\n");
        printf("    |            Galactic Birds            |\n");
        printf("    |    'Sua confianca sob nossas asas'   |\n");
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
                break;
            case 2: 
                repeat = 0;
                system("cls");
                break;
            case 3:
                repeat = 0;
                system("cls");
                break;
            case 4:
                repeat = 0;
                system("cls");
                break;
            case 5:
                repeat = 0;
                system("cls");
                break;
            case 6:
                repeat = 0;
                system("cls");
                break;
            case 7:
                repeat = 0;
                system("cls");
                break;
            case 8:
                repeat = 0;
                system("cls");
                break;
            case 9:
                repeat = 0;
                system("cls");
                printf("Obrigado pela preferencia, volte sempre!\n");
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
void cadastrar_voo(int repeat)
{
    FILE *arquivo;
    DATA data_voo;
    VOO  voo;

    char separador[3];

    repeat = 1;

    arquivo = fopen("dados_GalaticBirds.dat", "a+b");

    system("cls");

    if (arquivo == NULL)
    {
        printf("    ERRO! Nao foi possivel ler os dados.\n");
        exit(1);
    }
    else
    {  
        do
        {
            fflush(stdin);
            printf("     ______________________________________\n");
            printf("    |            Galactic Birds            |\n");
            printf("    |    'Sua confianca sob nossas asas'   |\n");
            printf("    |--------------------------------------|\n");
            printf("    | Cadastrar voo                        |\n");
            printf("    |______________________________________|\n\n");

            printf("             Insira o número do voo:\n");
            printf("                  "); scanf( "%s", &voo.num_voo[9]);

            if (voo.num_voo[0] != 'J' || voo.num_voo[1] != 'E' || voo.num_voo[2] != 'B' || voo.num_voo[3] != '-' || (voo.num_voo[4] < '0' || voo.num_voo[4] > '9') || (voo.num_voo[5] < '0' || voo.num_voo[5] > '9') || (voo.num_voo[6] < '0' || voo.num_voo[6] > '9') || (voo.num_voo[7] < '0' || voo.num_voo[7] > '9') || (voo.num_voo[8] != '\0' ))
            {
                repeat = 1;
                system("cls");
                printf("\n    ERRO! Formato do numero de voo incorreto.\n");
            }
            else
            {
                repeat = 0;
                do
                {
                    system("cls");

                    printf("     ______________________________________\n");
                    printf("    |            Galactic Birds            |\n");
                    printf("    |    'Sua confianca sob nossas asas'   |\n");
                    printf("    |--------------------------------------|\n");
                    printf("    | Cadastrar voo                        |\n");
                    printf("    |______________________________________|\n\n");

                    printf("   Insira a capacidade maxima de passageiros:\n");
                    printf("                      "); scanf("%d", &voo.max_passageiros);

                    if (voo.max_passageiros < 20 || voo.max_passageiros > 100)
                    {
                        repeat = 1;
                        system("cls");
                        printf("\n    ERRO! O valor inserido não é permitido.\n");
                    }
                    else
                    {
                        system("cls");

                        printf("     ______________________________________\n");
                        printf("    |            Galactic Birds            |\n");
                        printf("    |    'Sua confianca sob nossas asas'   |\n");
                        printf("    |--------------------------------------|\n");
                        printf("    | Cadastrar voo                        |\n");
                        printf("    |______________________________________|\n\n");

                        printf("             Insira a data do voo:\n");
                    }
                }while(repeat == 1);
            }
        }while(repeat = 1);
                    
            printf("     ______________________________________\n");
            printf("    |            Galactic Birds            |\n");
            printf("    |    'Sua confianca sob nossas asas'   |\n");
            printf("    |--------------------------------------|\n");
            printf("    | Cadastrar voo                        |\n");
            printf("    |______________________________________|\n\n");

            printf("             Insira a data do voo:\n");
            printf("                  "); scanf( "%d%c%d%c%d", &data_voo.dia, &separador[0],         &data_voo.mes, &separador[1], &data_voo.ano);

            if ((separador[0] == '/' && separador[1] == '/') || (separador[0] == '/' && separador[1] == '/'))
            {
                if(data_voo.ano >= 2030 && data_voo.ano <= 2032)
                {
                    if (data_voo.mes >= 1 && data_voo.mes <= 12)
                    {
                        if ((data_voo.dia >= 1 && data_voo.dia <= 31) && (data_voo.mes == 1 || data_voo.mes == 3 || data_voo.mes == 5 || data_voo.mes == 7 || data_voo.mes == 8 || data_voo.mes == 10 || data_voo.mes == 12))
                        {
                            repeat = 0;
                            fwrite(&data_voo.dia, sizeof(int), 1, arquivo);
                            fwrite(&data_voo.mes, sizeof(int), 1, arquivo);
                            fwrite(&data_voo.ano, sizeof(int), 1, arquivo);
                        }
                        else
                        {
                            if ((data_voo.dia <= 28 & data_voo.dia <= 30) && (data_voo.mes == 4 || data_voo.mes == 6 || data_voo.mes == 9 || data_voo.mes == 11))
                            {
                                repeat = 0;
                                fwrite(&data_voo.dia, sizeof(int), 1, arquivo);
                                fwrite(&data_voo.mes, sizeof(int), 1, arquivo);
                                fwrite(&data_voo.ano, sizeof(int), 1, arquivo);
                            }
                            else
                            {
                                if (data_voo.dia <= 28 && data_voo.mes == 2)
                                {
                                    repeat = 0;
                                    fwrite(&data_voo.dia, sizeof(int), 1, arquivo);
                                    fwrite(&data_voo.mes, sizeof(int), 1, arquivo);
                                    fwrite(&data_voo.ano, sizeof(int), 1, arquivo);
                                }
                                else
                                {
                                    if ((data_voo.dia == 29 && data_voo.mes == 2) && ((data_voo.ano % 400 == 0) || (data_voo.ano % 4 == 0 && data_voo.ano % 100 != 0)))
                                    {
                                        repeat = 0;
                                        fwrite(&data_voo.dia, sizeof(int), 1, arquivo);
                                        fwrite('/', sizeof(char), 1, arquivo);
                                        fwrite(&data_voo.mes, sizeof(int), 1, arquivo);
                                        fwrite('/', sizeof(char), 1, arquivo);
                                        fwrite(&data_voo.ano, sizeof(int), 1, arquivo);
                                    }
                                    else
                                    {
                                        system("cls");
                                        printf("\n ERRO! A data inserida está incorreta.\n\n");
                                        repeat = 1;
                                    }   
                                }   
                            }       
                        }
                    }
                }
            }
            else
            {
                system("cls");
                printf("\nERRO! O formato inserido está incorreto.\n\n");
            }

        } 

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

// Função principal do programa.
int main()
{

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
                    cadastrar_voo(repeat);
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