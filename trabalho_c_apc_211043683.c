#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_NUMVOO 8
#define TAM_NUMRES 9

typedef struct tm DATA;
struct DATA
{
    int tm_sec;   //representa os segundos de 0 a 59
    int tm_min;   //representa os minutos de 0 a 59
    int tm_hour;  //representa as horas de 0 a 24
    int tm_mday;  //dia do mês de 1 a 31
    int tm_mon;   //representa os meses do ano de 0 a 11
    int tm_year;  //representa o ano a partir de 1900
    int tm_wday;  //dia da semana de 0 (domingo) até 6 (sábado)
    int tm_yday;  // dia do ano de 1 a 365
    int tm_isdst; //indica horário de verão se for diferente de zero
};

typedef struct reserva RESERVA;
struct reserva
{
    char num_res[TAM_NUMRES];
    char res_numvoo[TAM_NUMVOO];
    char cpf[14];
    char nome[100];
    char sexo;
    int  nasc_dia;
    int  nasc_mes;
    int  nasc_ano;
    int  status_res;
};

typedef struct voo VOO;
struct voo
{
    char num_voo[TAM_NUMVOO];
    int  max_passageiros;
    int  ocupados;
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

void menu_consultar_voo()
{
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Consultar voo                        |\n");
    printf("    |______________________________________|\n\n");  
}

void menu_consultar_reserva1()
{
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Consultar reserva                    |\n");
    printf("    |______________________________________|\n\n");                      
}

char menu_consultar_reserva2(int repeat)
{
    char opcao_consult;
    do
    {
        repeat = 0;

        printf("     ______________________________________\n");
        printf("    |            Galactic Birds            |\n");
        printf("    |    'Sua confianca sob nossas asas'   |\n");
        printf("    |--------------------------------------|\n");
        printf("    | Consultar reserva                    |\n");
        printf("    |--------------------------------------|\n");
        printf("    | 1) Consultar por nome                |\n");
        printf("    | 2) Consultar por CPF                 |\n");
        printf("    |______________________________________|\n\n");

        printf("               Digite sua opcao: \n");
        printf("                       "); opcao_consult = getchar();

        if(opcao_consult != '1' && opcao_consult != '2')
        {
            repeat = 1;
            printf("\n              ERRO! Opcao invalida.\n");
        }

    }while(repeat == 1);

 return opcao_consult;
}

// Função do layout do menu principal do programa.
char menu(int repeat)
{
    char num_menu;

    do
    {
        repeat = 0;
        fflush(stdin);

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
        printf("                      "); scanf("%c", &num_menu);

        if ( (int)num_menu >= 49 && (int)num_menu <= 57 )
        {
            switch (num_menu)
            {
                case '1':
                    system("cls");
                    repeat = 0;
                    break;
                case '2':
                    system("cls");
                    repeat = 0;
                    break;
                case '3':
                    system("cls");
                    repeat = 0;
                    break;
                case '4':
                    system("cls");
                    repeat = 0;
                    break;
                case '5':
                    system("cls");
                    repeat = 0;
                    break;
                case '6':
                    system("cls");
                    repeat = 0;
                    break;
                case '7':
                    system("cls");
                    repeat = 0;
                    break;
                case '8':
                    system("cls");
                    repeat = 0;
                    break;
                case '9':
                    system("cls");
                    printf("\n\n    Obrigado pela preferencia, volte sempre!\n");
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

int verif_voo(FILE *arquivo_voo, VOO dados_voo, char *num_voo)
{
    int existe = 0;
    int j;

    while( fread(&dados_voo, sizeof(dados_voo), 1, arquivo_voo) )
    {
        for(j = 4; j < (strlen(dados_voo.num_voo) - 1); j++)
        {
            if( (dados_voo.num_voo[j] == num_voo[j]))
            {
                existe = 1;
            }
            else
            {
                existe = 0;
                break;
            }
        }
        if (existe == 1)
        {
            break;
        }
    }
 return existe;
}

// Função Cadastrar voo.
void cadastrar_voo(int repeat, int existe, char *num_voo, FILE *arquivo_voo, VOO dados_voo)
{
    DATA  *data;

    time_t segundos;
    time(&segundos);
    data = localtime(&segundos);

    int i = 0;
    int j = 0;
    char separador[3];
    // char comp_numvoo[8];

    existe = 0;
    repeat = 1;

    system("cls");

    if (arquivo_voo == NULL)
    {
        printf("      ERRO! Nao foi possivel ler os dados.\n");
        exit(1);
    }
    else
    {
        system("cls");
        do
        {
            repeat = 0;

            menu_cadastrarvoo();

            printf("         Insira o numero do voo:\n");
            fflush(stdin);
            printf("                  "); scanf("%[^\n]s", &num_voo);
            
            system("cls");

            strupr(num_voo);

            existe = 0;

            if (num_voo[0] == 'J' && num_voo[1] == 'E' && num_voo[2] == 'B' && num_voo[3] == '-' && (num_voo[4] - '0' >=  0 && num_voo[4] - '0' <= 9) && (num_voo[5] - '0' >= 0 && num_voo[5] - '0' <= 9) && ( num_voo[6] - '0' >= 0 && num_voo[6] - '0' <= 9) && ( num_voo[7] - '0' >= 0 && num_voo[7] - '0' <= 9) )
            {
                while( fread(&dados_voo, sizeof(dados_voo), 1, arquivo_voo) )
                {
                    for(j = 4; j < (strlen(dados_voo.num_voo) - 1); j++)
                    {
                        if( (dados_voo.num_voo[j] == num_voo[j]))
                        {
                            existe = 1;
                        }
                        else
                        {
                            existe = 0;
                            break;
                        }
                    }
                    if (existe == 1)
                    {
                        break;
                    }
                }

                if ( existe == 1 )
                {
                    system("cls");
                    repeat = 1;
                    printf("\n         ERRO! Este numero de voo ja existe.\n");

                }
                else
                {
                    strcpy(dados_voo.num_voo, num_voo);
                    do
                    {
                        repeat = 0;

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
                                                                        if ( ( dados_voo.dia == data -> tm_mday && dados_voo.mes == data -> tm_mon) && ((dados_voo.horas == data -> tm_hour) && (dados_voo.minutos <= data -> tm_min)) || ( dados_voo.dia == data -> tm_mday && dados_voo.mes == data -> tm_mon) && (dados_voo.horas < data -> tm_hour)  || (dados_voo.dia != data -> tm_mday || dados_voo.mes != data -> tm_mon || dados_voo.ano != data -> tm_year) )
                                                                        {
                                                                            repeat = 0;
                                                                            dados_voo.status_voo = 1;
                                                                            dados_voo.ocupados = 0;
                                                                            fflush(stdin);
                                                                            fwrite(&dados_voo, sizeof(VOO), 1, arquivo_voo);
                                                                            fclose(arquivo_voo);
                                                                            system("cls");
                                                                        }
                                                                        else
                                                                        {
                                                                            repeat = 1;
                                                                            system("cls");
                                                                            printf("         ERRO! O voo nao pode ser cadastrado\n         neste horario.\n\n");
                                                                            printf("1\n");
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        repeat = 1;
                                                                        system("cls");
                                                                        printf("         ERRO! O voo nao pode ser cadastrado\n         neste horario.\n\n");
                                                                        printf("2\n");
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
            else
            {
                repeat = 1;
                system("cls");
                printf("       ERRO! Formato do numero do voo incorreto.\n");
            }

        }while(repeat == 1);
    }
}

// Função Cadastrar reserva.
int cadastrar_reserva(int repeat, int existe, char *num_voo, char *num_res, FILE *arquivo_voo, FILE *arquivo_res, VOO dados_voo, RESERVA dados_reserva)
{
    DATA    *data;
    time_t  segundos;
    
    time(&segundos);
    data = localtime(&segundos);

    int  i = 0;
    int  j = 0;
    char separador[2];

    existe = 0;
    repeat = 1;

    if(arquivo_res == NULL)
    {
        printf("     ERRO! O arquivo nao pode ser aberto.");
        exit(1);
    }
    else
    {
        do
        {
            repeat = 0;

            menu_cadastrarreserva();
            fflush(stdin);
            printf("         Insira o numero da reserva:\n");
            printf("                 ");scanf("%s", num_res); 

            strupr(num_res);

            if (num_res[0] == 'G' && num_res[1] == 'B' && num_res[2] == '-' && num_res[3] - '0' >= 0 && num_res[3] - '0' <= 9 && num_res[4] - '0' >= 0 && num_res[4] - '0' <= 9 && num_res[5] - '0' >= 0 && num_res[5] - '0' <= 9 && num_res[6] - '0' >= 0 && num_res[6] - '0' <= 9 && num_res[7] - '0' >= 0 && num_res[7] - '0' <= 9 && num_res[8] - '0' >= 0 && num_res[8] - '0' <= 9)
            {
                printf("0");
                while( fread(&dados_reserva, sizeof(dados_reserva), 1, arquivo_res) )
                {
                    printf("1");
                    for(j = 3; j < (strlen(dados_reserva.num_res) - 1); j++)
                    {   
                        printf("2");
                        if( (dados_reserva.num_res[j] == num_res[j]))
                        {
                            printf("3");
                            existe = 1;
                        }
                        else
                        {
                            printf("4");
                            existe = 0;
                            break;
                        }
                    }
                    if(existe == 1)
                    {
                        break;
                    }
                }

                if( existe == 1)
                {
                    repeat = 1;
                    printf("    ERRO! O numero de reserva ja existe.\n");
                }
                else
                {
                    existe = 0;
                    fclose(arquivo_res);
                    do
                    {
                        repeat = 0;
                        menu_cadastrarreserva();
                        fflush(stdin);
                        printf("    Insira o numero do voo:\n");
                        printf("    ");scanf("%s", num_voo);

                        strupr(num_voo);


                        if (num_voo[0] == 'J' && num_voo[1] == 'E' && num_voo[2] == 'B' && num_voo[3] == '-' && (num_voo[4] - '0' >=  0 && num_voo[4] - '0' <= 9) && (num_voo[5] - '0' >= 0 && num_voo[5] - '0' <= 9) && ( num_voo[6] - '0' >= 0 && num_voo[6] - '0' <= 9) && ( num_voo[7] - '0' >= 0 && num_voo[7] - '0' <= 9) )
                        {
                            printf("0");
                            existe = 0;  //dados_reserva.res_numvoo
                            while( fread(&dados_voo, sizeof(dados_voo), 1, arquivo_voo) )
                            {
                                printf("1");
                                for(j = 4; j < (strlen(dados_voo.num_voo) - 1); j++)
                                {
                                    printf("2");
                                    if( (dados_voo.num_voo[j] == num_voo[j]))
                                    {
                                        existe = 1;
                                    }
                                    else
                                    {
                                        existe = 0;
                                        break;
                                    }
                                }

                                if (existe == 1)
                                {
                                    break;
                                }
                            }

                            if(existe == 0)
                            {
                                repeat = 1;
                                printf("    ERRO! O voo nao existe.\n");
                            }
                            else
                            {
                                strcpy(dados_reserva.res_numvoo, num_voo);
                                fclose(arquivo_voo);

                                existe = 0;
                                do
                                {
                                    menu_cadastrarreserva();
                                    fflush(stdin);
                                    printf("         Insira o CPF:\n");
                                    printf("         "); scanf("%s", dados_reserva.cpf);

                                    if( (dados_reserva.cpf[0] - '0') >= 0 && (dados_reserva.cpf[0] - '0') <= 9 && (dados_reserva.cpf[1] >= 0 - '0') && (dados_reserva.cpf[1] - '0') <= 9 && (dados_reserva.cpf[2] - '0') >= 0 && (dados_reserva.cpf[2] - '0') <= 9 && dados_reserva.cpf[3] == '.' && (dados_reserva.cpf[4] - '0') >= 0 && (dados_reserva.cpf[4] - '0') <= 9 && (dados_reserva.cpf[5] - '0') >= 0 && (dados_reserva.cpf[5] - '0') <= 9 && (dados_reserva.cpf[6] - '0') >= 0 && (dados_reserva.cpf[6] - '0') <= 9 && dados_reserva.cpf[7] == '.' && (dados_reserva.cpf[8] - '0') >= 0 && (dados_reserva.cpf[8] - '0') <= 9 && (dados_reserva.cpf[9] - '0') >= 0 && (dados_reserva.cpf[9] - '0') <= 9 && (dados_reserva.cpf[10] - '0') >= 0 && (dados_reserva.cpf[10] - '0') <= 9 && dados_reserva.cpf[11] == '-' && (dados_reserva.cpf[12] - '0') >= 0 && (dados_reserva.cpf[12] - '0') <= 9 && (dados_reserva.cpf[13] - '0') >= 0 && (dados_reserva.cpf[13] - '0') <= 9)
                                    {
                                        do
                                        {
                                            repeat = 0;
                                            menu_cadastrarreserva();
                                            fflush(stdin);
                                            printf("      Insira o nome completo:\n"); 
                                            scanf("%[^\n]s", &dados_reserva.nome);
                                            
                                            strupr(dados_reserva.nome);

                                            printf("1");
                                            
                                            for(i = 0; i < strlen(dados_reserva.nome) - 1; i++)
                                            {
                                                printf("2");
                                                if ( ! ((int)dados_reserva.nome[i] >= 65 && (int)dados_reserva.nome[i] <= 90 ||  (int)dados_reserva.nome[i] == 32) )
                                                {
                                                    repeat = 1;
                                                    //system("cls");
                                                    printf("ERRO! O nome inserido nao eh valido.\n\n");
                                                    break;
                                                }
                                            }

                                            if (repeat == 0)
                                            {
                                                do
                                                {
                                                    repeat = 0;
                                                    menu_cadastrarreserva();

                                                    printf("    Insira o sexo (M/F):\n");
                                                    printf("             ");scanf("%c", dados_reserva.sexo);

                                                    if(dados_reserva.sexo - '0' == 109)
                                                    {
                                                        dados_reserva.sexo = 'M';
                                                    }
                                                    else
                                                    {
                                                        if(dados_reserva.sexo - '0' == 102)
                                                        {
                                                            dados_reserva.sexo = 'F';
                                                        }
                                                    }

                                                    if( dados_reserva.sexo - '0' == 77 || dados_reserva.sexo - '0' == 70 || dados_reserva.sexo - '0' == 109 || dados_reserva.sexo - '0' == 102)
                                                    {
                                                        repeat = 0;

                                                        do
                                                        {
                                                            repeat = 0;
                                                            //system("cls");
                                                            menu_cadastrarreserva();

                                                            printf("    Insira a data de nascimento:\n");
                                                            printf("             ");scanf("%d%c%d%c%d", &dados_reserva.nasc_dia, &separador[0], &dados_reserva.nasc_mes, &separador[1], &dados_reserva.nasc_ano);

                                                            if ((separador[0] == '/' && separador[1] == '/') || (separador[0] == '-' && separador[1] == '-'))
                                                            {
                                                                // Permitidas somente pessoas com no máximo 130 anos e minimo zero anos.
                                                                if ( (dados_reserva.nasc_ano >= (data -> tm_year + 1779)) && (dados_reserva.nasc_ano <= (data -> tm_year + 1909)))
                                                                {
                                                                    if ( ((dados_reserva.nasc_dia >= 1 && dados_reserva.nasc_dia <= 31) && (dados_reserva.nasc_mes == 1 || dados_reserva.nasc_mes == 3 || dados_reserva.nasc_mes == 5 || dados_reserva.nasc_mes == 7 || dados_reserva.nasc_mes == 8 || dados_reserva.nasc_mes == 10 || dados_reserva.nasc_mes == 12)) || ((dados_reserva.nasc_dia >= 1 && dados_reserva.nasc_dia <= 30) && (dados_reserva.nasc_mes == 4 || dados_reserva.nasc_mes == 6 || dados_reserva.nasc_mes == 9 || dados_reserva.nasc_mes == 11)) || (dados_reserva.nasc_dia <= 28 && dados_reserva.nasc_mes == 2) || (((dados_reserva.nasc_dia == 29 && dados_reserva.nasc_mes == 2 && dados_reserva.nasc_ano % 400 == 0)) || (dados_reserva.nasc_ano % 4 == 0 && dados_reserva.nasc_ano % 100 != 0)))
                                                                    {
                                                                        repeat = 0;
                                                                        dados_reserva.status_res = 1;
                                                                        fflush(stdin);
                                                                        fwrite(&dados_reserva, sizeof(dados_reserva), 1, arquivo_res);
                                                                        fclose(arquivo_res);
                                                                        system("cls");
                                                                    }
                                                                    else
                                                                    {
                                                                        repeat = 1;
                                                                        //system("cls");
                                                                        printf("    ERRO! O dia inserido não existe.\n");
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                        repeat = 1;
                                                                        //system("cls");
                                                                        printf("    ERRO! O ano inserido não existe.\n");
                                                                }
                                                            }
                                                            else
                                                            {
                                                                repeat = 1;
                                                                //system("cls");
                                                                printf("    ERRO! Formato de data incorretol.");
                                                            }

                                                        }while(repeat == 1);
                                                    }
                                                    else
                                                    {
                                                        repeat = 1;
                                                        //system("cls");
                                                        printf("    ERRO! Insira um caracter valido.\n");
                                                    }

                                                }while(repeat == 1);
                                            }

                                        }while(repeat == 1);
                                    }
                                    else
                                    {
                                        repeat = 1;
                                        //system("cls");
                                        printf("         ERRO! O formato do CPF esta errado.");
                                    }
                    
                                }while(repeat == 1);
                            }
                        }
                        else
                        {
                            repeat = 1;
                            //system("cls");
                            printf("       ERRO! Formato do numero do voo incorreto.\n");
                        }
                    }while(repeat == 1);
                }
            }   
            else
            {
                repeat = 1;
                //system("cls");
                printf("       ERRO! Formato do numero de reserva incorreto.\n");
            }
               
        }while(repeat == 1);

    }

 return 0;
}

void listar_pass(char *num_voo, FILE *arquivo_res, RESERVA dados_reserva)
{
    while( fread(&dados_reserva, sizeof(dados_reserva), 1, arquivo_res) )
    {
        if(dados_reserva.res_numvoo == num_voo)
        {
            printf("%s\n", dados_reserva.nome);
            
        }
    }
}

// Função Consultar voo.
void consultar_voo(int repeat, int existe, char *num_voo, FILE *arquivo_voo, FILE *arquivo_res, VOO dados_voo, RESERVA dados_reserva)
{

    int i;
    char confirm;

    do
    {
        menu_consultar_voo();
        fflush(stdin);
        printf("   Insira o numero do voo desejado:\n");
        printf("  ");scanf("%s", num_voo);

        strupr(num_voo);

        while( fread(&dados_voo, sizeof(dados_voo), 1, arquivo_voo) )
        {
            for(i = 0; i < (strlen(dados_voo.num_voo) - 1); i++)
            {
                if( (num_voo[i] == dados_voo.num_voo[i]))
                {
                    existe = 1;
                }
                else
                {
                    existe = 0;
                    break;
                }
            }
            if (existe == 1)
            {
                break;
            }
        }
            
        if(existe == 1)
        {
            repeat = 0;
            menu_consultar_voo(); //JEB-0001
            
            printf("     ______________________________________\n");
            printf("    |              %s                |\n", num_voo);
            printf("    |--------------------------------------|\n");
            printf("    | Ocupacao: %.2f%%                      |\n", 100.*dados_voo.ocupados/dados_voo.max_passageiros);
            printf("    |______________________________________|\n");

            listar_pass(num_voo, arquivo_res, dados_reserva);
            
            system("pause");
        }
        else
        {
            do
            {
                printf("\nERRO! Voo nao encontrado.\n");
                menu_consultar_voo();
                printf("Deseja tentar novamente? [S ou N]\n");
                confirm = getchar();
                switch(confirm)
                {
                    case 'S':
                    {
                        repeat = 1;
                        break;
                    }
                    case 's':
                    {
                        repeat = 1;
                        break;
                    }
                    case 'N':
                    {
                        repeat = 0;
                        break;
                    }
                    case 'n':
                    {
                        repeat = 0;
                        break;
                    }
                    default:
                    {
                        printf("\nERRO! Valor inserido esta incorreto.");
                        break;
                    }
                }
            }while(confirm != 'S' || confirm != 's' || confirm != 'N' || confirm != 'n' );
        }

    }while(repeat == 1);    

}

void consultar_reserva_nominal(int repeat, int existe)
{
    FILE *arquivo_res, *arquivo_voo;
    struct reserva res_consultares;
    struct voo voo_consultares;

    char nome_pass[100];
    char confirm;
    
    do
    {
        menu_consultar_reserva1();

        printf("   Insira o nome completo do passageiro:\n");
        printf("  ");scanf("%[^\n]s", nome_pass);

        strupr(nome_pass);

        while(&res_consultares, sizeof(res_consultares), 1, arquivo_res)
        {
            if( strcmp(res_consultares.nome, nome_pass) == 0)
            {
                existe = 1;
                break;
            }
            else
            {
                existe = 0;
            }
        }

        if(existe == 1)
        {
            menu_consultar_reserva1();
            printf("     %s\n", res_consultares.nome);
            printf("     ");
            system("pause");
        }
        else
        {
            printf("\nERRO! Pessoa nao encontrada.\n");

            do
            {
                menu_consultar_reserva1();
                printf("Deseja tentar novamente? [S ou N]\n");
                confirm = getchar();
                switch(confirm)
                {
                    case 'S':
                    {
                        repeat = 1;
                        break;
                    }
                    case 's':
                    {
                        repeat = 1;
                        break;
                    }
                    case 'N':
                    {
                        repeat = 0;
                        break;
                    }
                    case 'n':
                    {
                        repeat = 0;
                        break;
                    }
                    default:
                    {
                        printf("\nERRO! Valor inserido esta incorreto.");
                        break;
                    }
                }
            }while(confirm != 'S' || confirm != 's' || confirm != 'N' || confirm != 'n' );
        }

    }while(repeat == 1);
    
}

void consultar_reserva_cpf(int repeat, int existe)
{
    ;
}

// Função Consultar reserva.
int consultar_reserva(int repeat, int existe)
{
    char opcao;
    opcao = menu_consultar_reserva2(repeat);

    do
    {
        switch(opcao)
        {
        case '1':
            consultar_reserva_nominal(repeat, existe);
            repeat = 0;
            break;
        
        case '2':
            consultar_reserva_cpf(repeat, existe);
            repeat = 0;
            break;
        
        default:
            repeat = 1;
            break;
        }
    }while(repeat == 1);
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
    FILE  *arquivo_voo, *arquivo_res;
    VOO   dados_voo;
    RESERVA dados_reserva;
    
    int existe = 0;
    int repeat = 1;
    char num_menu;
    char num_res[TAM_NUMRES];
    char num_voo[TAM_NUMVOO];

    arquivo_voo = fopen("dados_voos_GB.bin", "a+b");

    arquivo_res = fopen("dados_reservas_GB.bin", "a+b");

    do
    {
        num_menu = menu(repeat);

        if (num_menu == '9')
        {
            repeat =  0;
        }
        else
        {
            if ( (int)num_menu >= 49 && (int)num_menu <= 56 )
            {
                switch(num_menu)
                {
                    case '1':
                        cadastrar_voo(repeat, existe, num_voo, arquivo_voo, dados_voo);
                        repeat = 1;
                        system("cls");
                        printf("         Voo cadastrado com sucesso!\n\n");
                        break;
                    case '2':
                        cadastrar_reserva(repeat, existe, num_voo, num_res, arquivo_res, arquivo_voo, dados_voo, dados_reserva);
                        repeat = 1;
                        system("cls");
                        break;
                    case '3':
                        consultar_voo(repeat, existe, num_voo, arquivo_res, arquivo_voo, dados_voo, dados_reserva);
                        repeat = 1;
                        system("cls");
                        break;
                    case '4':
                        consultar_reserva(repeat, existe);
                        repeat = 1;
                        system("cls");
                        break;
                    case '5':
                        consultar_passageiro();
                        repeat = 1;
                        system("cls");
                        break;
                    case '6':
                        cancelar_voo();
                        repeat = 1;
                        system("cls");
                        break;
                    case '7':
                        cancelar_reserva();
                        repeat = 1;
                        system("cls");
                        break;
                    case '8':
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
