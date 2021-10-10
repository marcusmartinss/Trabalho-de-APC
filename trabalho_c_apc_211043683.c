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

typedef struct reserva RESERVA;
struct reserva
{
    char num_res[9];
    char cpf[14];
    char nome[100];
    char sexo;
    int nasc_dia;
    int nasc_mes;
    int nasc_ano;
    int status_res;
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
    int  status_voo;
};

void menu_cadastrarvoo()
{
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Cadastrar voo                        |\n");
    printf("    |______________________________________|\n\n");
}

void menu_cadastrarreserva()
{
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Cadastrar reserva                    |\n");
    printf("    |______________________________________|\n\n");
}

// Função do layout do menu principal do programa.
int menu(int repeat)
{   
    int num_menu;
        do
        {    
            repeat = 0;

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

            if (num_menu >= 1 && num_menu <= 9)
            {
                switch (num_menu)
                {
                    case 1:
                        system("cls");
                        repeat = 0;
                        break;
                    case 2: 
                        system("cls");
                        repeat = 0;
                        break;
                    case 3:
                        system("cls");
                        repeat = 0;
                        break;
                    case 4:
                        system("cls");
                        repeat = 0;
                        break;
                    case 5:
                        system("cls");
                        repeat = 0;
                        break;
                    case 6:
                        system("cls");
                        repeat = 0;
                        break;
                    case 7:
                        system("cls");
                        repeat = 0;
                        break;
                    case 8:
                        system("cls");
                        repeat = 0;
                        break;
                    case 9:
                        system("cls");
                        printf("Obrigado pela preferencia, volte sempre!\n");
                        repeat = 0;
                        break;
                }
            }
            else
            {
                repeat = 1;
                system("cls");
                printf("\n\n             ERRO: Valor invalido!\n\n");
            }
        }while(repeat == 1);

 return num_menu;
}

// Função Cadastrar voo.
void cadastrar_voo(int repeat)
{
    DATA  *data;
    FILE  *arquivo;
    VOO   dados_voo;

    time_t segundos;
    time(&segundos);
    data = localtime(&segundos);

    char separador[3];
    char teste_numvoo[8];
    int  contador_teste = 0;

    repeat = 1;

    arquivo = fopen("dados_GalaticBirds.dat", "a+b");

    system("cls");

    if (arquivo == NULL)
    {
        printf("         ERRO! Nao foi possivel ler os dados.\n");
        exit(1);
    }
    else
    {  
        system("cls");
        do
        {
            menu_cadastrarvoo();

            printf("             Insira o numero do voo:\n");
            printf("                  "); scanf( "%s", teste_numvoo);
            system("cls");


            strupr(teste_numvoo);

            while( fread(&dados_voo, 1, sizeof(struct voo), arquivo) )
            {
                if( strcmp(dados_voo.num_voo, teste_numvoo) == 0 )
                {
                    contador_teste++;
                }
            }

            if ( contador_teste != 0 )
            {
                repeat = 1;
                system("cls");
                printf("\n         ERRO! Este numero de voo ja existe.\n");
            }
            else
            {
                strcpy(dados_voo.num_voo, teste_numvoo);

                if (dados_voo.num_voo[0] == 'J' && dados_voo.num_voo[1] == 'E' && dados_voo.num_voo[2] == 'B' && dados_voo.num_voo[3] == '-' && (dados_voo.num_voo[4] >= '0' && dados_voo.num_voo[4] <= '9') && (dados_voo.num_voo[5] >= '0' && dados_voo.num_voo[5] <= '9') && (dados_voo.num_voo[6] >= '0' && dados_voo.num_voo[6] <= '9') && (dados_voo.num_voo[7] >= '0' && dados_voo.num_voo[7] <= '9'))
                {
                    repeat = 0;
                    do
                    {   
                        menu_cadastrarvoo();
                        printf("   Insira a capacidade maxima de passageiros:\n");
                        printf("                      "); scanf("%d", &dados_voo.max_passageiros);

                        if (dados_voo.max_passageiros < 20 || dados_voo.max_passageiros > 100)
                        {
                            repeat = 1;
                            system("cls");
                            printf("\n         ERRO! O valor inserido nao eh permitido.\n");
                        }
                        else
                        {
                            system("cls");
                            do
                            {
                                menu_cadastrarvoo();
                                printf("             Insira a data do voo:\n");
                                printf("                  "); scanf( "%d%c%d%c%d", &dados_voo.dia, &separador[0], &dados_voo.mes, &separador[1], &dados_voo.ano);

                                if ((separador[0] == '/' && separador[1] == '/') || (separador[0] == '-' && separador[1] == '-'))
                                {
                                    if ((dados_voo.ano >= (data -> tm_year + 1909)) && (dados_voo.ano <= (data -> tm_year + 1911)))
                                    {
                                        if ((dados_voo.mes >= 1 && dados_voo.mes <= 12) && (dados_voo.dia >= 1 && dados_voo.dia <= 31))
                                        {
                                            if ((dados_voo.ano == (data -> tm_year + 1909) && (dados_voo.mes >= data -> tm_mon + 1)) || (dados_voo.ano != (data -> tm_year + 1909)))
                                            {
                                                if (((dados_voo.dia >= 1 && dados_voo.dia <= 31) && (dados_voo.mes == 1 || dados_voo.mes == 3 || dados_voo.mes == 5 || dados_voo.mes == 7 || dados_voo.mes == 8 || dados_voo.mes == 10 || dados_voo.mes == 12)) || ((dados_voo.dia >= 1 && dados_voo.dia <= 30) && (dados_voo.mes == 4 || dados_voo.mes == 6 || dados_voo.mes == 9 || dados_voo.mes == 11)) || (dados_voo.dia <= 28 && dados_voo.mes == 2) || (((dados_voo.dia == 29 && dados_voo.mes == 2 && dados_voo.ano % 400 == 0)) || (dados_voo.ano % 4 == 0 && dados_voo.ano % 100 != 0)))
                                                {
                                                    if (((dados_voo.dia >= data -> tm_mday) && (dados_voo.ano == data -> tm_year + 1909) && (dados_voo.mes == data -> tm_mon + 1)) || (dados_voo.mes > data -> tm_mon + 1) || (dados_voo.ano != (data -> tm_year + 1909)))
                                                    {
                                                        system("cls");
                                                        do
                                                        {
                                                            menu_cadastrarvoo();
                                                            printf("            Insira o horario do voo:\n");
                                                            printf("                  ");scanf("%d%c%d", &dados_voo.horas, &separador[2], &dados_voo.minutos);
                                                            
                                                            if (dados_voo.horas <= 23 && dados_voo.horas >= 0 && dados_voo.minutos >= 0 && dados_voo.minutos <=59)
                                                            {
                                                                if (separador[2] == ':')
                                                                {
                                                                    if ( ( (dados_voo.dia == data -> tm_mday) && (dados_voo.mes == data -> tm_mon + 1) && (dados_voo.ano == data -> tm_year + 1909) && ((((dados_voo.horas * 60) + dados_voo.minutos ) - ( ((data -> tm_hour) * 60) + (data -> tm_min))) > 60)) || (dados_voo.ano != data -> tm_year + 1909) || ((dados_voo.ano == data -> tm_year + 1909) && (dados_voo.mes > data -> tm_mon + 1)) || ((dados_voo.ano == data -> tm_year + 1909) && (dados_voo.mes == data -> tm_mon + 1) && ((dados_voo.dia > data -> tm_mday))) )
                                                                    {
                                                                        if (((dados_voo.horas == data -> tm_hour) && (dados_voo.minutos <= data -> tm_min)) || (dados_voo.horas < data -> tm_hour))
                                                                        {
                                                                            repeat = 0;
                                                                            dados_voo.status_voo = 1;
                                                                            fflush(stdin);
                                                                            fwrite(&dados_voo, sizeof(VOO), 1, arquivo);
                                                                            fclose(arquivo);
                                                                            system("cls");
                                                                        }
                                                                        else
                                                                        {
                                                                            repeat = 1;
                                                                            system("cls");
                                                                            printf("         ERRO! O voo nao pode ser cadastrado\n         neste horario.\n\n");
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        repeat = 1;
                                                                        system("cls");
                                                                        printf("         ERRO! O voo nao pode ser cadastrado\n         neste horario.\n\n");
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    repeat = 1;
                                                                    system("cls");
                                                                    printf("         ERRO! O formato inserido esta incorreto.\n\n");
                                                                }
                                                            }
                                                            else
                                                            {
                                                                repeat = 1;
                                                                system("cls");
                                                                printf("         ERRO! O horario inserido nao existe.\n\n");
                                                            }
                                                            
                                                        }while(repeat == 1);
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
                                                    repeat = 1;
                                                    system("cls");
                                                    printf("         ERRO! A data inserida nao eh valida.\n\n");
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
                                else{
                                    repeat = 1;
                                    system("cls");
                                    printf("         \nERRO! A formato da data\n         inserida esta incorreto.\n\n");
                                }
                            }while(repeat == 1);
                        }
                    }while(repeat == 1);
                }
            }
        }while(repeat == 1);
    }
}

// Função Cadastrar reserva.
int cadastrar_reserva(int repeat)
{
    RESERVA dados_reserva;
    repeat = 1;

    menu_cadastrarreserva();

    printf("         Insira o numero da reserva:\n");
    printf("                 "); scanf("%s", dados_reserva.num_res);

    do
    {    
        if (dados_reserva.num_res[0] == 'G' && dados_reserva.num_res[1] == 'B' && dados_reserva.num_res[2] == '-' && dados_reserva.num_res[3] >= 0 && dados_reserva.num_res[3] <= 9 && dados_reserva.num_res[4] >= 0 && dados_reserva.num_res[4] <= 9 && dados_reserva.num_res[5] >= 0 && dados_reserva.num_res[5] <= 9 && dados_reserva.num_res[6] >= 0 && dados_reserva.num_res[6] <= 9 && dados_reserva.num_res[7] >= 0 && dados_reserva.num_res[7] <= 9 && dados_reserva.num_res[8] >= 0 && dados_reserva.num_res[8] <= 9)
        {
            /* if()
             * Testar se já existe no arquivo.
             * 
             * 
             * 
             * 
             * 
            */

            do
            {
                menu_cadastrarreserva();

                printf("         Insira o CPF:\n");
                printf("         "); scanf("%s", dados_reserva.cpf);

                if( (dados_reserva.cpf[0] - '0') >= 0 && (dados_reserva.cpf[0] - '0') <= 9 && (dados_reserva.cpf[1] >= 0 - '0') && (dados_reserva.cpf[1] - '0') <= 9 && (dados_reserva.cpf[2] - '0') >= 0 && (dados_reserva.cpf[2] - '0') <= 9 && dados_reserva.cpf[3] == '.' && (dados_reserva.cpf[4] - '0') >= 0 && (dados_reserva.cpf[4] - '0') <= 9 (dados_reserva.cpf[5] - '0') >= 0 && (dados_reserva.cpf[5] - '0') <= 9 && (dados_reserva.cpf[6] - '0') >= 0 && (dados_reserva.cpf[6] - '0') <= 9 && dados_reserva.cpf[7] == '.' && (dados_reserva.cpf[8] - '0') >= 0 && (dados_reserva.cpf[8] - '0') <= 9 && (dados_reserva.cpf[9] - '0') >= 0 && (dados_reserva.cpf[9] - '0') <= 9 && (dados_reserva.cpf[10] - '0') >= 0 && (dados_reserva.cpf[10] - '0') <= 9 && dados_reserva.cpf[11] == '-' && (dados_reserva.cpf[12] - '0') >= 0 && (dados_reserva.cpf[12] - '0') <= 9 && (dados_reserva.cpf[13] - '0') >= 0 && (dados_reserva.cpf[13] - '0') <= 9)
                {
                    
                }
                else
                {
                    repeat = 1;
                    printf("         ERRO! O formato do CPF esta errado.")
                }

            }while(repeat == 1);


        }
        else
        {
            repeat = 1;
            system("cls");
            printf("       ERRO! Formato do numero de reserva incorreto.\n");
        } 

    }while(repeat == 1);
    
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
            if (num_menu >= 1 && num_menu <= 8)
            {
                switch(num_menu)
                {
                    case 1:
                        cadastrar_voo(repeat);
                        repeat = 1;
                        system("cls");
                        printf("         Voo cadastrado com sucesso!\n\n");
                        break;
                    case 2:
                        cadastrar_reserva(repeat);
                        repeat = 1;
                        system("cls");
                        break;
                    case 3:
                        consultar_voo(repeat);
                        repeat = 1;
                        system("cls");
                        break;
                    case 4:
                        consultar_reserva();
                        repeat = 1;
                        system("cls");
                        break;
                    case 5:
                        consultar_passageiro();
                        repeat = 1;
                        system("cls");
                        break;
                    case 6:
                        cancelar_voo();
                        repeat = 1;
                        system("cls");
                        break;
                    case 7:
                        cancelar_reserva();
                        repeat = 1;
                        system("cls");
                        break;
                    case 8:
                        excluir_voo();
                        repeat = 1;
                        system("cls");
                        break;
                }
            }
        }
    }while(repeat == 1);

 return 0;
}