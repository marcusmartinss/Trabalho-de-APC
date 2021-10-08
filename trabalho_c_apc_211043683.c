#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct tm DATA;
struct DATA
    {
    int tm_sec; //representa os segundos de 0 a 59
    int tm_min; //representa os minutos de 0 a 59
    int tm_hour; //representa as horas de 0 a 24
    int tm_mday; //dia do mês de 1 a 31
    int tm_mon; //representa os meses do ano de 0 a 11
    int tm_year; //representa o ano a partir de 1900
    int tm_wday; //dia da semana de 0 (domingo) até 6 (sábado)
    int tm_yday; // dia do ano de 1 a 365
    int tm_isdst; //indica horário de verão se for diferente de zero
    };

typedef struct reserva RESEVA;
struct reserva
{

};

typedef struct voo VOO;
struct voo
{
    char num_voo[8];
    int  max_passageiros;
    int  dia;
    int  mes;
    int  ano;
    int  horas;
    int  minutos;
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
    DATA  *data;
    FILE  *arquivo;
    VOO   voo;

    time_t segundos;
    time(&segundos);
    data = localtime(&segundos);

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
        system("cls");
        do
        {
            printf("     ______________________________________\n");
            printf("    |            Galactic Birds            |\n");
            printf("    |    'Sua confianca sob nossas asas'   |\n");
            printf("    |--------------------------------------|\n");
            printf("    | Cadastrar voo                        |\n");
            printf("    |______________________________________|\n\n");

            printf("             Insira o numero do voo:\n");
            printf("                  "); scanf( "%s", voo.num_voo);
            system("cls");

            strupr(voo.num_voo);

            if (voo.num_voo[0] == 'J' && voo.num_voo[1] == 'E' && voo.num_voo[2] == 'B' && voo.num_voo[3] == '-' && (voo.num_voo[4] >= '0' && voo.num_voo[4] <= '9') && (voo.num_voo[5] >= '0' && voo.num_voo[5] <= '9') && (voo.num_voo[6] >= '0' && voo.num_voo[6] <= '9') && (voo.num_voo[7] >= '0' && voo.num_voo[7] <= '9'))
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
                        do
                        {

                            printf("     ______________________________________\n");
                            printf("    |            Galactic Birds            |\n");
                            printf("    |    'Sua confianca sob nossas asas'   |\n");
                            printf("    |--------------------------------------|\n");
                            printf("    | Cadastrar voo                        |\n");
                            printf("    |______________________________________|\n\n");

                            printf("             Insira a data do voo:\n");
                            printf("                  "); scanf( "%d%c%d%c%d", &voo.dia, &separador[0], &voo.mes, &separador[1], &voo.ano);

                            if ((separador[0] == '/' && separador[1] == '/') || (separador[0] == '-' && separador[1] == '-'))
                            {
                                if((voo.ano >= (data -> tm_year + 1909)) && (voo.ano <= (data -> tm_year + 1911)))
                                {
                                    if((voo.mes >= 1 && voo.mes <= 12) && (voo.dia >= 1 && voo.dia <= 31))
                                    {
                                        if ((voo.ano == (data -> tm_year + 1909) && (voo.mes >= data -> tm_mon + 1)) || (voo.ano != (data -> tm_year + 1909)))
                                        {
                                            if ((voo.dia >= 1 && voo.dia <= 31) && (voo.mes == 1 || voo.mes == 3 || voo.mes == 5 || voo.mes == 7 || voo.mes == 8 || voo.mes == 10 || voo.mes == 12) )
                                            {
                                                if(((voo.dia >= data -> tm_mday) && (voo.ano == data -> tm_year + 1909) && (voo.mes == data -> tm_mon + 1)) || (voo.mes > data -> tm_mon + 1) || (voo.ano != (data -> tm_year + 1909)))
                                                {
                                                    repeat = 0;
                                                    voo.status = 1;
                                                    fflush(stdin);
                                                    fwrite(&voo, sizeof(voo), 1, arquivo);
                                                    fclose(arquivo);
                                                }
                                                else
                                                {
                                                    repeat = 1;
                                                    system("cls");
                                                    printf("\n        ERRO! Nao eh possivel inserir\n         cadastrar um voo neste dia.\n\n");
                                                }
                                            }
                                            else
                                            {
                                                if( (voo.dia >= 1 && voo.dia <= 30) && (voo.mes == 4 || voo.mes == 6 || voo.mes == 9 || voo.mes == 11) ) 
                                                {
                                                    if(((voo.dia >= data -> tm_mday) && (voo.ano == data -> tm_year + 1909) && (voo.mes == data -> tm_mon + 1)) || (voo.mes > data -> tm_mon + 1) || (voo.ano != (data -> tm_year + 1909)))
                                                    {
                                                        repeat = 0;
                                                        voo.status = 1;
                                                        fflush(stdin);
                                                        fwrite(&voo, sizeof(voo), 1, arquivo);
                                                        fclose(arquivo);
                                                    }
                                                    else
                                                    {
                                                        repeat = 1;
                                                        system("cls");
                                                        printf("\n         ERRO! Nao eh possivel inserir\n         cadastrar um voo neste dia.\n\n");
                                                    }
                                                }
                                                else
                                                {
                                                    if (voo.dia <= 28 && voo.mes == 2)
                                                    {
                                                        if(((voo.dia >= data -> tm_mday) && (voo.ano == data -> tm_year + 1909) && (voo.mes == data -> tm_mon + 1)) || (voo.mes > data -> tm_mon + 1) || (voo.ano != (data -> tm_year + 1909)))
                                                        {
                                                            
                                                            validar_hora(repeat);
                                                            
                                                            repeat = 0;
                                                            voo.status = 1;
                                                            fflush(stdin);
                                                            fwrite(&voo, sizeof(voo), 1, arquivo);
                                                            fclose(arquivo);
                                                        }    
                                                        else
                                                        {
                                                            repeat = 1;
                                                            system("cls");
                                                            printf("\n         ERRO! Nao eh possivel inserir\n         cadastrar um voo neste dia.\n\n");
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if ((voo.dia == 29 && voo.mes == 2) && ((voo.ano % 400 == 0) || (voo.ano % 4 == 0 && voo.ano % 100 != 0)))
                                                        {
                                                            if(((voo.dia >= data -> tm_mday) && (voo.ano == data -> tm_year + 1909) && (voo.mes == data -> tm_mon + 1)) || (voo.mes > data -> tm_mon + 1) || (voo.ano != (data -> tm_year + 1909)))
                                                            {
                                                                repeat = 0;
                                                                voo.status = 1;
                                                                fflush(stdin);
                                                                fwrite(&voo, sizeof(voo), 1, arquivo);
                                                                fclose(arquivo);
                                                            }
                                                            else
                                                            {
                                                                repeat = 1;
                                                                system("cls");
                                                                printf("         \nERRO! A data inserida esta incorreta.\n\n");
                                                            }
                                                        }
                                                        else
                                                        {
                                                            repeat = 1;
                                                            system("cls");
                                                            printf("         \nERRO! A data inserida esta incorreta.\n\n");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            repeat = 1;
                                            system("cls");
                                            printf("\n         ERRO! Nao eh possivel inserir\n         cadastrar um voo nesta data.\n\n");
                                        }
                                    }
                                    else
                                    {
                                        repeat = 1;
                                        system("cls");
                                        printf("\n         ERRO! A data inserida esta incorreta.\n\n");
                                    }
                                }
                                else
                                {
                                    repeat = 1;
                                    system("cls");
                                    printf("\n         ERRO! Nao eh possivel inserir\n         cadastrar um voo neste ano.\n\n");
                                }
                            }
                            else
                            {
                                repeat = 1;
                                system("cls");
                                printf("         \nERRO! A formato da data\n         inserida esta incorreto.\n\n");
                            }
                        }while(repeat == 1);
                    }
                }while(repeat == 1);
            }
        }while(repeat == 1);
    }
}

int validar_hora(int repeat)
{
    DATA  *data;
    VOO   voo;

    repeat = 1;

    do
    {
        printf("     ______________________________________\n");
        printf("    |            Galactic Birds            |\n");
        printf("    |    'Sua confianca sob nossas asas'   |\n");
        printf("    |--------------------------------------|\n");
        printf("    | Cadastrar voo                        |\n");
        printf("    |______________________________________|\n\n");

        printf("            Insira o horário do voo:\n");
        printf("                  ");scanf("%d:%d", &voo.horas, &voo.minutos);

        if((voo.dia >= data -> tm_mday) && (voo.mes == data -> tm_mon + 1) && (voo.ano == data -> tm_year + 1909) && (voo.horas >= data -> tm_hour - 2))
        {

        }
    }while(repeat == 1);
}

// Função Cadastrar reserva.
int cadastrar_reserva()
{
 return 0;
}


// Função Consultar voo.
int consultar_voo(int repeat)
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
                    system("cls");
                    break;
                case 2:
                    cadastrar_reserva();
                    system("cls");
                    break;
                case 3:
                    consultar_voo(repeat);
                    system("cls");
                    break;
                case 4:
                    consultar_reserva();
                    system("cls");
                    break;
                case 5:
                    consultar_passageiro();
                    system("cls");
                    break;
                case 6:
                    cancelar_voo();
                    system("cls");
                    break;
                case 7:
                    cancelar_reserva();
                    system("cls");
                    break;
                case 8:
                    excluir_voo();
                    system("cls");
                    break;
            }

        }
    }while(repeat == 1);

 return 0;
}