// Marcus Vinicius Paiva Martins - 211043683

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>

#include "../libs/verifica.h"
#include "../libs/structs.h"
#include "../libs/consts.h"
#include "../libs/menu.h"

// Como strupr não está disponível para todos compiladores, decidi criá-la
void strupr(char *str)
{
    while (*str)
    {
        *str = toupper((unsigned char) *str); // Converte cada caractere para maiúsculo
        str++;
    }
}

// Funcao Cadastrar voo.
void cadastrar_voo(int repeat, int existe, char num_voo[], VOO ler_dados_voo, VOO escrever_dados_voo)
{
    FILE *ler_voo, *add_voo;
    char separador[3];

    ler_voo = fopen("dados_voos_GB.bin", "rb");
    add_voo = fopen("dados_voos_GB.bin", "ab");

    if (ler_voo == NULL || add_voo == NULL) {
        system("cls || clear");
        printf("\n     ERRO! Nao foi possivel ler os dados.\n");
        menu_cadastrarvoo();
        exit(1);
    }

    system("cls || clear");
    do {
        repeat = 0;
        menu_cadastrarvoo();

        printf("       Insira o numero do voo (JEB-XXXX):\n");
        fflush(stdin);
        printf("                  ");
        scanf("%[^\n]s", num_voo);
        system("cls || clear");

        strupr(num_voo);  // Convertendo para maiúsculas

        if (!verifica_numero_voo(num_voo)) {
            printf("\n     ERRO! Formato do numero do voo incorreto.\n");
            repeat = 1;
        } else if (verifica_voo_existente(num_voo)) {
            printf("\n     ERRO! Este numero de voo ja existe.\n");
            repeat = 1;
        } else {
            fclose(ler_voo);
            strcpy(escrever_dados_voo.num_voo, num_voo);

            do {
                repeat = 0;
                menu_cadastrarvoo();

                printf("    Insira a capacidade maxima de passageiros:\n              (Min: 20 / Max: 100)\n");
                fflush(stdin);
                printf("                      ");
                scanf("%d", &escrever_dados_voo.max_passageiros);

                if (!verifica_capacidade_passageiros(escrever_dados_voo.max_passageiros)) {
                    printf("\n     ERRO! O valor inserido nao eh permitido.\n");
                    repeat = 1;
                } else {
                    do {
                        menu_cadastrarvoo();
                        printf("       Insira a data do voo (dd/mm/aaaa):\n");
                        printf("                  ");
                        scanf("%d%c%d%c%d", &escrever_dados_voo.dia, &separador[0], &escrever_dados_voo.mes, &separador[1], &escrever_dados_voo.ano);

                        if ((separador[0] == '/' && separador[1] == '/') || (separador[0] == '-' && separador[1] == '-')) {
                            if (!verifica_data_voo(escrever_dados_voo.dia, escrever_dados_voo.mes, escrever_dados_voo.ano)) {
                                printf("\n     ERRO! A data inserida nao eh valida.\n");
                                repeat = 1;
                            } else {
                                do {
                                    menu_cadastrarvoo();
                                    printf("        Insira o horario do voo (hh:mm):\n");
                                    printf("                  ");
                                    scanf("%d%c%d", &escrever_dados_voo.horas, &separador[2], &escrever_dados_voo.minutos);

                                    if (separador[2] != ':' || !verifica_horario_voo(escrever_dados_voo.horas, escrever_dados_voo.minutos)) {
                                        printf("\n     ERRO! O horario inserido nao existe.\n");
                                        repeat = 1;
                                    } else {
                                        escrever_dados_voo.status_voo = 1;
                                        fwrite(&escrever_dados_voo, sizeof(VOO), 1, add_voo);
                                        fclose(add_voo);

                                        system("cls || clear");
                                        menu_cadastrarvoo();
                                        printf("           Voo cadastrado com sucesso!\n");
                                        system("pause");
                                    }
                                } while (repeat == 1);
                            }
                        } else {
                            printf("\n     ERRO! O formato da data esta incorreto.\n");
                            repeat = 1;
                        }
                    } while (repeat == 1);
                }
            } while (repeat == 1);
        }
    } while (repeat == 1);
}

// Funcao Cadastrar reserva.
void cadastrar_reserva(int repeat, int existe, char num_res[], char num_voo[], RESERVA ler_dados_reserva, RESERVA escrever_dados_reserva)
{
    FILE    *ler_reservas, *add_reserva;
    FILE    *ler_voos;
    DATA    *data;

    ler_reservas = fopen("../data/dados_reservas_GB.bin", "rb");
    add_reserva  = fopen("../data/dados_reservas_GB.bin", "ab");

    ler_voos     = fopen("../data/dados_voos_GB.bin", "rb");
    
    time_t segundos;
    time(&segundos);
    data = localtime(&segundos);

    int ocupmax_voo; // Variaveis para receber valores de funcoes modularizadas
    int ocup_reservas = 0;
    int status;
    int data_hora_ok = 0;
    int cpf_valido = 0;

    int  i = 0; // Variaveis gerais utilizadas
    char cpf[TAM_CPF];
    char nome[TAM_NOME];
    char separador[2];

    existe = 0;
    repeat = 1;

    if(ler_reservas == NULL || add_reserva == NULL || ler_voos == NULL)
    {
        system("cls || clear");
        printf("\n     ERRO! Nao foi possivel ler os dados.\n");
        exit(1);
    }
    else
    {
        if( qtd_voos_ativos() > 0)
        {
            system("cls || clear");
            do
            {
                
                repeat = 0;

                menu_cadastrarreserva();
                fflush(stdin);
                printf("     Insira o numero da reserva (GB-XXXXXX):\n");
                printf("                 ");scanf("%[^\n]s", num_res); 

                strupr(num_res);
                
                existe = existe_reserva( existe, num_res );

                // Verificacao do formato de reserva
                if (num_res[0] == 'G' && num_res[1] == 'B' && num_res[2] == '-' && num_res[3] - '0' >= 0 && num_res[3] - '0' <= 9 && num_res[4] - '0' >= 0 && num_res[4] - '0' <= 9 && num_res[5] - '0' >= 0 && num_res[5] - '0' <= 9 && num_res[6] - '0' >= 0 && num_res[6] - '0' <= 9 && num_res[7] - '0' >= 0 && num_res[7] - '0' <= 9 && num_res[8] - '0' >= 0 && num_res[8] - '0' <= 9)
                {

                    if( existe == 1)
                    {
                        repeat = 1;
                        system("cls || clear");
                        printf("\n     ERRO! O numero de reserva ja existe.\n");
                        menu_cadastrarreserva();
                        system("pause");
                        system("cls || clear");
                    }
                    else
                    {
                        repeat = 0;
                        system("cls || clear");
                        fclose(ler_reservas);
                        strcpy(escrever_dados_reserva.num_res, num_res);

                        do
                        {
                            repeat = 0;

                            menu_cadastrarreserva();
                            fflush(stdin);
                            printf("       Insira o numero do voo (JEB-XXXX):\n");
                            printf("                    ");scanf("%[^\n]s", num_voo);

                            strupr(num_voo);

                            // Verificacao do formato de voo
                            if (num_voo[0] == 'J' && num_voo[1] == 'E' && num_voo[2] == 'B' && num_voo[3] == '-' && (num_voo[4] - '0' >=  0 && num_voo[4] - '0' <= 9) && (num_voo[5] - '0' >= 0 && num_voo[5] - '0' <= 9) && ( num_voo[6] - '0' >= 0 && num_voo[6] - '0' <= 9) && ( num_voo[7] - '0' >= 0 && num_voo[7] - '0' <= 9) )
                            {
                                existe = existe_voo( existe, num_voo ); 

                                if(existe == 0)
                                {
                                    repeat = 1;
                                    system("cls || clear");
                                    printf("\n     ERRO! O voo nao existe.\n");

                                }
                                else
                                {
                                    status = status_voo( num_voo );

                                    if( status == 1) // Se o status do voo for ativo, sera
                                    {                // possivel cadastrar uma reserva no mesmo
                                        data_hora_ok = comparar_data_hora_voo( num_voo );

                                        if( data_hora_ok == 1 ) // Se o voo ainda nao houver decolado,
                                        {                       // sera possivel cadastrar uma reserva
                                            system("cls || clear");
                                            fclose(ler_voos);
                                            
                                            strcpy(escrever_dados_reserva.res_numvoo, num_voo);

                                            ocup_reservas = qtd_reservas_ativas( num_voo );
                                            
                                            ocupmax_voo = max_pass( num_voo );

                                            if ( ocup_reservas == ocupmax_voo ) // Se o voo estiver na ocupacao maxima
                                            {                                   // nao eh possivel cadastrar reservas
                                                system("cls || clear");
                                                repeat = 0;
                                                menu_cadastrarreserva();
                                                printf("\n      ERRO! O voo esta na sua capacidade maxima\n");
                                                system("pause");

                                            }
                                            else
                                            {
                                                system("cls || clear");
                                                do
                                                {
                                                    menu_cadastrarreserva();
                                                    fflush(stdin);
                                                    printf("         Insira o CPF (XXX.XXX.XXX-XX):\n");
                                                    printf("                 "); scanf("%[^\n]s", cpf);

                                                    if( (cpf[0] - '0') >= 0 && (cpf[0] - '0') <= 9 && (cpf[1] - '0') >= 0 && (cpf[1] - '0') <= 9 && (cpf[2] - '0') >= 0 && (cpf[2] - '0') <= 9 && cpf[3] == '.' && (cpf[4] - '0') >= 0 && (cpf[4] - '0') <= 9 && (cpf[5] - '0') >= 0 && (cpf[5] - '0') <= 9 && (cpf[6] - '0') >= 0 && (cpf[6] - '0') <= 9 && cpf[7] == '.' && (cpf[8] - '0') >= 0 && (cpf[8] - '0') <= 9 && (cpf[9] - '0') >= 0 && (cpf[9] - '0') <= 9 && (cpf[10] - '0') >= 0 && (cpf[10] - '0') <= 9 && cpf[11] == '-' && (cpf[12] - '0') >= 0 && (cpf[12] - '0') <= 9 && (cpf[13] - '0') >= 0 && (cpf[13] - '0') <= 9)
                                                    {
                                                        cpf_valido = valida_cpf(cpf);
                                                        if( cpf_valido )
                                                        {
                                                            existe = existe_cpf_voo( existe, cpf, num_voo );
                                                            
                                                            if(existe == 1) // Se alguem estiver reservado no voo com
                                                            {               // o mesmo CPF nao sera possivel continuar
                                                                repeat = 0;
                                                                system("cls || clear");
                                                                printf("\n     ERRO! O CPF ja esta cadastrado no voo.\n");
                                                                menu_cadastrarreserva();
                                                                system("pause");
                                                            }
                                                            else
                                                            {
                                                                system("cls || clear");
                                                                strcpy(escrever_dados_reserva.cpf, cpf);
                                                                do
                                                                {
                                                                    nome[0] = '\0';

                                                                    repeat = 0;
                                                                    menu_cadastrarreserva();
                                                                    fflush(stdin);
                                                                    printf("            Insira o nome completo:\n"); 
                                                                    printf("      ");scanf("%[^\n]s", nome);
                                                                    
                                                                    strupr(nome);
                                                                    
                                                                    for(i = 0; i < (strlen(nome)); i++)
                                                                    {   // O programa nao aceita caracteres diferentes de letras e espacos para o nome
                                                                        if  ( ! ( ( (int)nome[i] >= 65 && (int)nome[i] <= 90 ) || ( (int)nome[i] == 32 ) ) )
                                                                        {
                                                                            repeat = 1;
                                                                            system("cls || clear");
                                                                            printf("\n     ERRO! O nome inserido nao eh valido.\n");
                                                                            break;
                                                                        }
                                                                    }

                                                                    if (repeat == 0)
                                                                    {
                                                                        system("cls || clear");
                                                                        fclose(ler_reservas);
                                                                        fflush(stdout);
                                                                        existe = 0;
                                                                        while( fread(&ler_dados_reserva, sizeof(ler_dados_reserva), 1, ler_reservas))
                                                                        {
                                                                            if( (strcmp(ler_dados_reserva.nome, nome) == 0) && (strcmp(ler_dados_reserva.res_numvoo, num_voo) == 0) && ler_dados_reserva.status_res == 1 )
                                                                            {
                                                                                existe = 1;
                                                                                break;
                                                                            }
                                                                        }

                                                                        if(existe == 1) // Se uma pessoa com mesmo nome, nome mesmo voo e com reserva ativa estiver cadastrada
                                                                        {               // nao sera possivel completar a reserva
                                                                            repeat = 0;
                                                                            system("cls || clear");
                                                                            printf("\n     ERRO! A pessoa ja tem reserva no voo.\n");
                                                                            menu_cadastrarreserva();
                                                                            system("pause");
                                                                        }
                                                                        else
                                                                        {
                                                                            system("cls || clear");
                                                                            existe = 0;
                                                                            fclose(ler_reservas);
                                                                            strcpy(escrever_dados_reserva.nome, nome);
                                                                            do
                                                                            {
                                                                                repeat = 0;
                                                                                menu_cadastrarreserva();

                                                                                fflush(stdin);
                                                                                printf("              Insira o sexo (M/F):\n");
                                                                                printf("                       ");scanf("%c", &escrever_dados_reserva.sexo);

                                                                                if(escrever_dados_reserva.sexo == 'm')
                                                                                {
                                                                                    escrever_dados_reserva.sexo = 'M';
                                                                                }
                                                                                else
                                                                                {
                                                                                    if(escrever_dados_reserva.sexo == 'f')
                                                                                    {
                                                                                        escrever_dados_reserva.sexo = 'F';
                                                                                    }
                                                                                }

                                                                                if( escrever_dados_reserva.sexo != 'M' || escrever_dados_reserva.sexo != 'F')
                                                                                {
                                                                                    system("cls || clear");
                                                                                    do
                                                                                    {
                                                                                        repeat = 0;
                                                                                        menu_cadastrarreserva();

                                                                                        printf("    Insira a data de nascimento (dd/mm/aaaa):\n");
                                                                                        printf("                   ");scanf("%d%c%d%c%d", &escrever_dados_reserva.nasc_dia, &separador[0], &escrever_dados_reserva.nasc_mes, &separador[1], &escrever_dados_reserva.nasc_ano);

                                                                                        if ((separador[0] == '/' && separador[1] == '/') || (separador[0] == '-' && separador[1] == '-'))
                                                                                        {
                                                                                            // Permitidas somente pessoas com no maximo 130 anos e minimo zero anos.
                                                                                            if ( ( (escrever_dados_reserva.nasc_ano >= (data -> tm_year + 1779)) && (escrever_dados_reserva.nasc_ano <= (data -> tm_year + 1909) ) ) )
                                                                                            {
                                                                                                if ( ( (escrever_dados_reserva.nasc_ano == (data -> tm_year + 1909) ) && (escrever_dados_reserva.nasc_mes < (data -> tm_mon + 1909) ) ) || ( escrever_dados_reserva.nasc_ano < (data -> tm_year + 1909) ) )
                                                                                                {
                                                                                                    if ( ((escrever_dados_reserva.nasc_dia >= 1 && escrever_dados_reserva.nasc_dia <= 31) && (escrever_dados_reserva.nasc_mes == 1 || escrever_dados_reserva.nasc_mes == 3 || escrever_dados_reserva.nasc_mes == 5 || escrever_dados_reserva.nasc_mes == 7 || escrever_dados_reserva.nasc_mes == 8 || escrever_dados_reserva.nasc_mes == 10 || escrever_dados_reserva.nasc_mes == 12)) || ((escrever_dados_reserva.nasc_dia >= 1 && escrever_dados_reserva.nasc_dia <= 30) && (escrever_dados_reserva.nasc_mes == 4 || escrever_dados_reserva.nasc_mes == 6 || escrever_dados_reserva.nasc_mes == 9 || escrever_dados_reserva.nasc_mes == 11)) || (escrever_dados_reserva.nasc_dia <= 28 && escrever_dados_reserva.nasc_mes == 2) || (((escrever_dados_reserva.nasc_dia == 29 && escrever_dados_reserva.nasc_mes == 2 && escrever_dados_reserva.nasc_ano % 400 == 0)) || (escrever_dados_reserva.nasc_ano % 4 == 0 && escrever_dados_reserva.nasc_ano % 100 != 0)))
                                                                                                    {
                                                                                                        repeat = 0;
                                                                                                        escrever_dados_reserva.status_res = 1;
                                                                                                        
                                                                                                        fwrite(&escrever_dados_reserva, sizeof(escrever_dados_reserva), 1, add_reserva);
                                                                                                        fclose(add_reserva);
                                                                                                        fclose(ler_reservas);

                                                                                                        // Mensagem de cadastro concluido
                                                                                                        system("cls || clear");
                                                                                                        menu_cadastrarreserva();
                                                                                                        printf("         Reserva cadastrada com sucesso!\n");
                                                                                                        system("pause");

                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                        repeat = 1;
                                                                                                        system("cls || clear");
                                                                                                        printf("\n    ERRO! A data inserida nao existe.\n");
                                                                                                    }
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    repeat = 1;
                                                                                                    system("cls || clear");
                                                                                                    printf("\n     ERRO! A data inserida nao eh valida.\n");
                                                                                                }
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                repeat = 1;
                                                                                                system("cls || clear");
                                                                                                printf("\n     ERRO! O ano inserido nao eh valido.\n");
                                                                                            }
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            repeat = 1;
                                                                                            system("cls || clear");
                                                                                            printf("\n     ERRO! Formato de data incorreto.\n");
                                                                                        }

                                                                                    }while(repeat == 1);
                                                                                }
                                                                                else
                                                                                {
                                                                                    repeat = 1;
                                                                                    system("cls || clear");
                                                                                    printf("\n     ERRO! Insira um caracter valido.\n");
                                                                                }

                                                                            }while(repeat == 1);
                                                                        }
                                                                    }

                                                                }while(repeat == 1);
                                                            }
                                                        }
                                                        else
                                                        {
                                                            repeat = 1;
                                                            system("cls || clear");
                                                            printf("\n     ERRO! O numero de CPF esta incorreto.\n");
                                                        }
                                                    }
                                                    else
                                                    {
                                                        repeat = 1;
                                                        system("cls || clear");
                                                        printf("\n     ERRO! O formato do CPF esta incorreto.\n");
                                                    }
                                    
                                                }while(repeat == 1);
                                            }
                                        }
                                        else
                                        {
                                            repeat = 0;
                                            system("cls || clear");
                                            printf("\n     ERRO! Este voo ja partiu.\n");
                                            menu_cadastrarreserva();
                                            system("pause");
                                        }
                                    }
                                    else
                                    {
                                        repeat = 0;
                                        system("cls || clear");
                                        printf("\n     ERRO! O voo esta cancelado.\n");
                                        menu_cadastrarreserva();
                                        system("pause");
                                    }
                                }
                            }
                            else
                            {
                                repeat = 1;
                                system("cls || clear");
                                printf("\n     ERRO! Formato do numero do voo incorreto.\n");
                            }
                        }while(repeat == 1);
                    }
                }   
                else
                {
                    repeat = 1;
                    system("cls || clear");
                    printf("\n     ERRO! Formato do numero de reserva incorreto.\n");
                }

            }while(repeat == 1);
        }
        else
        {
            printf("\n     ERRO! Nao existem voos cadastrados ou ativos.\n");
            menu_cadastrarreserva();
            system("pause");
        }
    }

}

// Funcao Consultar voo.
void consultar_voo ( int existe, char num_voo[], VOO ler_dados_voo, RESERVA ler_dados_reserva)
{
    FILE *ler_voos;
    FILE *ler_dados_res, *ler_reservas;
    
    int total_pass = 0;
    int max_pass;
    int contador_voos;

    ler_voos = fopen("../data/dados_voos_GB.bin", "rb");
    ler_dados_res = fopen("../data/dados_reservas_GB.bin", "rb");
    ler_reservas = fopen("../data/dados_reservas_GB.bin", "rb");

    contador_voos = qtd_voos_total();

    if(contador_voos > 0)
    {
        menu_consultar_voo();
        fflush(stdin);
        printf("       Insira o numero do voo (JEB-XXXX):\n");
        printf("                  ");scanf("%[^\n]s", num_voo);

        strupr(num_voo);

        total_pass = qtd_reservas_ativas( num_voo );

        existe = existe_voo( existe, num_voo );

        if(existe == 1)
        {
            while( fread(&ler_dados_voo, sizeof(ler_dados_voo), 1, ler_voos))
            {
                if(strcmp(ler_dados_voo.num_voo, num_voo) == 0)
                {
                    max_pass = ler_dados_voo.max_passageiros; // Eh utilizado o maximo de passageiros e a quantidade 
//                                                            // de reservas ativas para fazer a porcentagem ocupacao
                    system("cls || clear");
                    menu_consultar_voo();
                    
                        printf("     ______________________________________\n");
                        printf("    |              %s                |\n", num_voo);
                        printf("    |--------------------------------------|\n");

                    if(ler_dados_voo.dia < 10 && ler_dados_voo.mes < 10) // Ajuste nas datas por estarem em formato inteiro
                    {
                        printf("    | Data    : 0%d/0%d/%d               |\n", ler_dados_voo.dia, ler_dados_voo.mes, ler_dados_voo.ano);
                    }
                    else
                    {
                        if(ler_dados_voo.dia < 10 && ler_dados_voo.mes >= 10)
                        {
                            printf("    | Data    : 0%d/%d/%d                |\n", ler_dados_voo.dia, ler_dados_voo.mes, ler_dados_voo.ano);
                        }
                        else
                        {
                            if(ler_dados_voo.dia >= 10 && ler_dados_voo.mes < 10)
                            {
                                printf("    | Data    : %d/0%d/%d                |\n", ler_dados_voo.dia, ler_dados_voo.mes, ler_dados_voo.ano);
                            }
                            else
                            {
                                if(ler_dados_voo.dia >= 10 && ler_dados_voo.mes >= 10)
                                {
                                    printf("    | Data    : %d/%d/%d                 |\n", ler_dados_voo.dia, ler_dados_voo.mes, ler_dados_voo.ano);
                                }
                            }
                        }
                    }

                    if(ler_dados_voo.horas < 10 && ler_dados_voo.minutos < 10) // Ajuste no horario por estarem em formato inteiro
                    {
                        printf("    | Horario : 0%d:0%d                  |\n", ler_dados_voo.horas, ler_dados_voo.minutos);
                    }
                    else
                    {
                        if(ler_dados_voo.horas < 10 && ler_dados_voo.minutos >= 10)
                        {
                            printf("    | Horario : 0%d:%d                    |\n", ler_dados_voo.horas, ler_dados_voo.minutos);
                        }
                        else
                        {
                            if(ler_dados_voo.horas >= 10 && ler_dados_voo.minutos < 10)
                            {
                                printf("    | Horario : %d:0%d                    |\n", ler_dados_voo.horas, ler_dados_voo.minutos);
                            }
                            else
                            {
                                if(ler_dados_voo.horas >= 10 && ler_dados_voo.minutos >= 10)
                                {
                                    printf("    | Horario : %d:%d                      |\n", ler_dados_voo.horas, ler_dados_voo.minutos);
                                }
                            }
                        }
                    }

                    if(ler_dados_voo.status_voo == 1)
                    {
                        printf("    | Status  : ATIVO                      |\n");
                    }
                    else
                    {
                        printf("    | Status  : CANCELADO                  |\n");
                    }
                    
                    printf("    | Ocupacao: %.2f%%                      |\n", ((100.0 * total_pass)/max_pass));
                    printf("    |______________________________________|\n\n");
                    

                    printf("     PASSAGEIROS:\n\n");

                    if( total_pass > 0 ) // Se houverem passageiros no voo, estes serao escritos. Caso nao, aparecera a mensagem de que nao existem.
                    {
                        while( fread(&ler_dados_reserva, sizeof(ler_dados_reserva), 1, ler_reservas) )
                        {
                            if( (strcmp(ler_dados_reserva.res_numvoo, num_voo) == 0) && (ler_dados_reserva.status_res == 1))
                            {
                                printf("     - [%s] %s\n", ler_dados_reserva.num_res, ler_dados_reserva.nome);
                            }
                        }
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        printf("     Nao existem passageiros registrados ou ativos neste voo.\n\n");
                        system("pause");
                    }
                }
            }
            
        }
        else
        {
            system("cls || clear");
            printf("\n     ERRO! Voo nao encontrado.\n");
            menu_consultar_voo();
            system("pause");
        }  

        fclose(ler_reservas);
        fclose(ler_voos);
        fclose(ler_dados_res);
    }
    else
    {
        system("cls || clear");
        printf("\n     ERRO! Nao existem voos para serem consultados\n");
        menu_consultar_voo();
        system("pause");
    }

}

int qtd_reservas_total() // Retorna a quantidade de reservas ativas e canceladas
{
    FILE *ler_reservas;
    RESERVA reservas;

    int qtd = 0;

    ler_reservas = fopen("dados_reservas_GB.bin", "rb");

    fflush(stdin);

    while( fread( &reservas, sizeof(reservas), 1, ler_reservas ) ) // Le no arquivo todas reservas sem distincao de status, as conta e retorna
    {
        if( reservas.sexo == 'M' || reservas.sexo == 'F') 
        {
            qtd++;
        }
    }
    fclose(ler_reservas);

 return qtd;
}

// Funcao Consultar reserva.
void consultar_reserva( int existe, RESERVA ler_dados_reserva )
{
    FILE *ler_reservas;

    int total_reservas;
    char num_res[TAM_NUMRES];

    total_reservas = qtd_reservas_total();

    if( total_reservas > 0 )
    {
        ler_reservas = fopen("dados_reservas_GB.bin", "rb");
        existe = 0;

        menu_consultar_reserva();
        printf("     Insira o numero da reserva (GB-XXXXXX):\n");
        fflush(stdin);
        printf("                 ");scanf("%[^\n]s", num_res);

        strupr(num_res);
        system("cls || clear");

        existe = existe_reserva ( existe, num_res );

        if( existe == 1 )
        {
            while( fread( &ler_dados_reserva, sizeof(ler_dados_reserva), 1, ler_reservas) ) // Eh procurada a reserva e mostrada seus detalhes
            {
                if ( strcmp(ler_dados_reserva.num_res, num_res) == 0 )
                {
                    existe = 1;

                    menu_consultar_reserva();
                    printf("     --------------------------------------\n");
                    printf("    |              %s               |\n", num_res);
                    printf("     --------------------------------------\n\n");

                    if(ler_dados_reserva.status_res == 1)
                    {
                        printf("     STATUS     :    ATIVA\n");
                    }
                    else
                    {
                        printf("     STATUS     :    CANCELADA\n\n");
                    }
                    printf("     PASSAGEIRO :    %s\n", ler_dados_reserva.nome);
                    if(ler_dados_reserva.sexo == 'F')
                    {
                        printf("     SEXO       :    FEMININO\n");
                    }
                    else
                    {
                        printf("     SEXO       :    MASCULINO\n");
                    }

                    printf("     CPF        :    %s\n", ler_dados_reserva.cpf);

                    if( ler_dados_reserva.nasc_dia < 10 && ler_dados_reserva.nasc_mes < 10)
                    {
                        printf("     DATA NASC. :    0%d/0%d/%d\n\n", ler_dados_reserva.nasc_dia, ler_dados_reserva.nasc_mes, ler_dados_reserva.nasc_ano);
                    }
                    else
                    {
                        if( ler_dados_reserva.nasc_dia < 10 && ler_dados_reserva.nasc_mes >= 10)
                        {
                            printf("     DATA NASC. :    0%d/%d/%d\n\n", ler_dados_reserva.nasc_dia, ler_dados_reserva.nasc_mes, ler_dados_reserva.nasc_ano);
                        }
                        else
                        {
                            if( ler_dados_reserva.nasc_dia >= 10 && ler_dados_reserva.nasc_mes < 10)
                            {
                                printf("     DATA NASC. :    %d/0%d/%d\n\n", ler_dados_reserva.nasc_dia, ler_dados_reserva.nasc_mes, ler_dados_reserva.nasc_ano);
                            }
                            else
                            {
                                printf("     DATA NASC. :    %d/%d/%d\n\n", ler_dados_reserva.nasc_dia, ler_dados_reserva.nasc_mes, ler_dados_reserva.nasc_ano);
                            }
                        }
                    }
                    fclose(ler_reservas);
                    system("pause");

                    break;
                }
            }
        }
        else
        {
            system("cls || clear");
            printf("\n     ERRO! A reserva nao existe.\n");
            menu_cadastrarreserva();
            system("pause");
        }
    }
    else
    {
        system("cls || clear");
        printf("\n     Nao existem reservas a serem consultadas.\n");
        menu_cadastrarreserva();
        system("pause");
    }
 
}

int existe_passageiro( int existe, char nome_pass[], RESERVA ler_dados_reserva ) // Funcao que retorna a existencia de um certo passageiro
{
    FILE *ler_reservas;

    ler_reservas = fopen( "dados_reservas_GB.bin", "rb" );

    while( fread( &ler_dados_reserva, sizeof(ler_dados_reserva), 1, ler_reservas ) )
    {
        if( strcmp( ler_dados_reserva.nome, nome_pass ) == 0 ) // Se o passageiro existir, eh retornado 1, se nao, eh retornado 0
        {
            existe = 1;
            break;
        }
        else
        {
            existe = 0;
        }
    }
    fclose(ler_reservas);

 return existe;
}

void escrever_reservas( char nome_pass[] ) // Escreve cada reserva de um certo passageiro e seus detalhes
{
    FILE *ler_reservas;
    RESERVA reservas;

    ler_reservas = fopen( "dados_reservas_GB.bin", "rb" );

    if(ler_reservas != NULL)
    {
        while( fread( &reservas, sizeof(reservas), 1, ler_reservas ) )
        {
            if( strcmp( reservas.nome, nome_pass ) == 0 )
            {   
                printf("     Numero da reserva:  %s\n", reservas.num_res);
                if( reservas.status_res == 1 )
                {
                    printf("     Status da reserva:  ATIVA\n\n");
                }
                else
                {
                    printf("     Status da reserva:  CANCELADA\n\n");
                }
                
                printf("     Numero do voo:  %s\n\n", reservas.res_numvoo);

                printf("   ------------------------------------------\n");
                
                /*  if( reservas.sexo == 'F')
                    {
                        printf("     SEXO:   FEMININO\n");
                    }
                    else
                    {
                        printf("     SEXO:   MASCULINO\n");
                    }

                    if( reservas.nasc_dia < 10 )
                    {
                        printf("     Data de nasc.: 0%d/", reservas.nasc_dia);
                    }
                    else
                    {
                        printf("     Data de nasc.: %d/", reservas.nasc_dia);
                    }

                    if( reservas.nasc_mes < 10 )
                    {
                        printf("0%d/", reservas.nasc_mes);
                    }
                    else
                    {
                        printf("%d/", reservas.nasc_mes);
                    }

                    printf("%d\n", reservas.nasc_ano);
                */
            }
        }
    }
    else
    {
        system("cls || clear");
        printf("     ERRO! Nao foi possivel ler os dados.\n");
        system("pause");
    }

}

void consultar_passageiro_nominal( int existe, RESERVA ler_dados_reserva) // Consulta o passageiro pelo seu nome 
{
    char nome_pass[TAM_NOME];

    existe = 0;

    menu_consultar_passageiro();

    printf("      Insira o nome completo do passageiro:\n");
    printf("      "); scanf(" %[^\n]s", nome_pass);

    strupr(nome_pass);

    existe = existe_passageiro( existe, nome_pass, ler_dados_reserva );
    
    if(existe == 1)
    {
        system("cls || clear");
        menu_consultar_passageiro();
        printf("     ~ %s ~\n", nome_pass);
        printf("   ------------------------------------------\n");

        escrever_reservas(nome_pass); // O cabecalho com nome eh fixo e depois sao escritas as reservas do passageiro

        system("pause");
    }
    else
    {
        system("cls || clear");
        printf("\n     ERRO! Pessoa nao encontrada.\n");
        menu_consultar_passageiro();
        system("pause");
    }
    
}

// Funcao Consultar passageiro.
void consultar_passageiro( int existe, RESERVA ler_dados_reserva)
{
    int existem_passageiros;

    existem_passageiros = qtd_reservas_total(); // Caso existam passageiros vao ser seguidas as funcoes anteriores
//                                              // caso contrario nao sera possivel consultar passageiros
    if( existem_passageiros > 0 )
    {
        system("cls || clear");
        consultar_passageiro_nominal( existe, ler_dados_reserva );
    }
    else
    {
        printf("\n     ERRO! Nao existem passageiros cadastrados.\n");
        menu_consultar_passageiro();
        system("pause");
    }

}

int voo_ativo(num_voo)
{
    FILE *ler_voos;
    VOO voos;

    int status;

    ler_voos = fopen("dados_voos_GB.bin", "rb");

    while( fread( &voos, sizeof(voos), 1, ler_voos ) )
    {
        if( strcmp(voos.num_voo, num_voo) == 0 )
        {
            status = voos.status_voo;
        }
    }
    fclose(ler_voos);

 return status;
}

// Funcao Cancelar voo.
void cancelar_voo(int existe, char num_voo[])
{
    FILE   *ler_voos, *ler_reservas;
    FILE   *reescrever_voos, *reescrever_reservas;
    VOO     voos;
    RESERVA reservas;

    int data_hora_ok = 0;
    int existem_voos = 0;
    int ativo;
    
    existem_voos = qtd_voos_ativos();

    existe = 0;
    if( existem_voos > 0 ) // Se existem voos ativos, sera possivel cancelar algum
    {
        ler_voos = fopen( "dados_voos_GB.bin", "r+b" );
        ler_reservas = fopen( "dados_reservas_GB.bin", "r+b" );

        reescrever_voos = fopen( "tmpdados_voos_GB.bin", "wb" );
        reescrever_reservas = fopen( "tmpdados_reservas_GB.bin", "wb" );

        if( ler_voos != NULL && ler_reservas != NULL && reescrever_voos != NULL && reescrever_reservas != NULL )
        {
            menu_cancelarvoo();
            fflush(stdin);
            printf("      Qual voo deseja cancelar? (JEB-XXXX)\n");
            printf("                  ");scanf("%[^\n]s", num_voo);

            strupr(num_voo);

            existe = existe_voo( existe, num_voo );

            if( existe == 1 )
            {
                data_hora_ok = comparar_data_hora_voo( num_voo ); // Se a data e hora atual antecederem o voo, sera possivel cancela-lo

                if( data_hora_ok == 1 )
                {
                    ativo = voo_ativo(num_voo); // Se o voo estiver ativo sera possível cancela-lo

                    if( ativo )
                    {
                        while( fread( &voos, sizeof(voos), 1, ler_voos ) ) // Procura o voo, muda o status e o escreve no arquivo temporario,
                        {                                                  // os demais arquivos serao enviados normalmente
                            if( strcmp( voos.num_voo, num_voo ) == 0 )
                            {
                                voos.status_voo = 0;
                                fwrite( &voos, sizeof(voos), 1, reescrever_voos );
                            }
                            else
                            {
                                fwrite( &voos, sizeof(voos), 1, reescrever_voos );
                            }
                        }

                        if( qtd_reservas_total() > 0 )
                        {
                            while( fread( &reservas, sizeof(reservas), 1, ler_reservas ) ) // As reservas deste voo serao canceladas e
                            {                                                              // passadas para o outro arquivo, as demais
                                if( strcmp( reservas.res_numvoo, num_voo ) == 0 )          // passarao sem alteracoes
                                {
                                    reservas.status_res = 0;
                                    fwrite( &reservas, sizeof(reservas), 1, reescrever_reservas );
                                }
                                else
                                {
                                    fwrite( &reservas, sizeof(reservas), 1, reescrever_reservas );
                                }
                            }
                        }

                        fclose( ler_voos );
                        fclose( ler_reservas );
                        fclose( reescrever_voos );
                        fclose( reescrever_reservas ); // Sao fechados todos arquivos

                        ler_voos = fopen( "tmpdados_voos_GB.bin", "rb" );
                        ler_reservas = fopen( "tmpdados_reservas_GB.bin", "rb" );

                        reescrever_voos = fopen( "dados_voos_GB.bin", "wb" );
                        reescrever_reservas = fopen( "dados_reservas_GB.bin", "wb" ); // Inverte-se os modos de abertura de cada aquivo

                        while( fread( &reservas, sizeof(reservas), 1, ler_reservas ) ) // Sao passados os dados do arquivo temporario
                        {                                                              // para o principal
                            fwrite( &reservas, sizeof(reservas), 1, reescrever_reservas );
                        }

                        while( fread( &voos, sizeof(voos), 1, ler_voos ) )
                        {
                            fwrite( &voos, sizeof(voos), 1, reescrever_voos );
                        }

                        fclose( ler_voos );
                        fclose( ler_reservas );
                        fclose( reescrever_voos );
                        fclose( reescrever_reservas ); // Fecham-se todos arquivos

                        remove("tmpdados_voos_GB.bin");
                        remove("tmpdados_reservas_GB.bin"); // Apaga os arquivos temporarios

                        system("cls || clear");
                        menu_cancelarvoo();
                        printf("           Voo cancelado com sucesso!\n");
                        system("pause");

                    }
                    else
                    {
                        system("cls || clear");
                        printf("\n     ERRO! Este voo ja esta cancelado.\n");
                        menu_cancelarvoo();
                        system("pause");
                    }
                }
                else
                {
                    system("cls || clear");
                    printf("\n     ERRO! Este voo ja partiu.\n");
                    menu_cancelarvoo();
                    system("pause");
                }
            }
            else
            {
                system("cls || clear");
                printf("\n     ERRO! O voo nao existe.\n");
                menu_excluirvoo();
                system("pause");
            }
        }
        else
        {
            system("cls || clear");
            printf("\n     ERRO! Nao foi possivel ler os dados.\n");
            menu_excluirvoo();
            system("pause");
        }
    }
    else
    {
        system("cls || clear");
        printf("\n     ERRO! Nao existem voos cadastrados.\n");
        menu_excluirvoo();
        system("pause");
    }
}

int num_reservas_ativas() // Retorna a quantidade total de reservas ativas em todos voos
{
    FILE *ler_reservas;
    RESERVA reservas;

    int num_reservas = 0;

    ler_reservas = fopen("dados_reservas_GB.bin", "rb");

    while( fread( &reservas, sizeof(reservas), 1, ler_reservas ) ) // Procura no arquivo de reservas as reservas com status 1
    {
        if(reservas.status_res == 1)
        {
            num_reservas++;
        }
    }

 return num_reservas;
}

int reserva_ativa(char num_res[])
{
    FILE *ler_reservas;
    RESERVA reservas;

    int status;

    ler_reservas = fopen("dados_reservas_GB.bin", "rb");

    while( fread( &reservas, sizeof(reservas), 1, ler_reservas ) )
    {
        if( strcmp(reservas.num_res, num_res) == 0 )
        {
            status = reservas.status_res;
        }
    }
    fclose(ler_reservas);

 return status;
}

// Funcao Cancelar reserva.
int cancelar_reserva( int existe, char num_voo[], char num_res[] )
{
    FILE *ler_reservas;
    FILE *reescrever_reservas;

    RESERVA reservas;

    int  existem_reservas = 0;
    int  existem_voos = 0;
    int  ativa;

    existem_reservas = num_reservas_ativas();

    if( existem_reservas > 0 )
    {
        existem_voos = qtd_voos_ativos();

        if( existem_voos > 0 )
        {
            ler_reservas = fopen( "dados_reservas_GB.bin", "rb" );
            reescrever_reservas = fopen( "tmpdados_reservas_GB.bin", "wb" );

            if( ler_reservas != NULL && reescrever_reservas != NULL )
            {
                menu_cancelarreserva();
                printf("    Qual reserva deseja cancelar? (GB-XXXXXX)\n");
                fflush(stdin);
                printf("                 ");scanf("%[^\n]s", num_res);

                strupr(num_res);

                existe = existe_reserva( existe, num_res ); // Se a reserva existir, sera possivel continuar

                if( existe == 1 )
                {
                    ativa = reserva_ativa(num_res);

                    if( ativa )
                    {
                        while( fread( &reservas, sizeof(reservas), 1, ler_reservas ) ) // Eh passado para o outro arquivo a reserva com status
                        {                                                              // cancelado e as demais passadas normalmente
                            if( strcmp( reservas.num_res, num_res ) == 0 )
                            {
                                reservas.status_res = 0;
                                fwrite( &reservas, sizeof(reservas), 1, reescrever_reservas );
                            }
                            else
                            {
                                fwrite( &reservas, sizeof(reservas), 1, reescrever_reservas );
                            }
                        }

                        fclose( ler_reservas );
                        fclose( reescrever_reservas ); // Fecha-se os arquivos

                        ler_reservas = fopen( "tmpdados_reservas_GB.bin", "rb" );
                        reescrever_reservas = fopen( "dados_reservas_GB.bin", "wb" ); // Inverte-se o modo de abertura dos arquivos

                        while( fread( &reservas, sizeof(reservas), 1, ler_reservas ) )
                        {
                            fwrite( &reservas, sizeof(reservas), 1, reescrever_reservas ); // Passa todos dados do temporario para o principal
                        }

                        fclose( ler_reservas );
                        fclose( reescrever_reservas ); // Fecha-se novamente os arquivos 

                        remove("tmpdados_reservas_GB.bin"); // Apaga o arquivo temporario

                        system("cls || clear");
                        menu_cancelarreserva();
                        printf("         Reserva cancelada com sucesso!\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls || clear");
                        printf("\n     ERRO! A reserva ja esta cancelada.\n");
                        menu_cancelarreserva();
                        system("pause");
                    }
                }
                else
                {
                    system("cls || clear");
                    printf("\n     ERRO! A reserva nao existe.\n");
                    menu_cancelarreserva();
                    system("pause");
                }
            }
            else
            {
                system("cls || clear");
                printf("\n     ERRO! Nao foi possivel ler os dados.\n");
                menu_cancelarreserva();
                system("pause");
            }
        }
        else
        {
            system("cls || clear");
            printf("\n     ERRO! Nao existem voos cadastrados ou ativos.\n");
            menu_cancelarreserva();
            system("pause");
        }
    }
    else
    {
        system("cls || clear");
        printf("\n     ERRO! Nao existem reservas cadastradas ou ativas.\n");
        menu_cancelarreserva();
        system("pause");
    }

 return 0;
}


// Funcao Excluir voo.
void excluir_voo( int existe )
{
    FILE   *ler_voos, *ler_reservas;
    FILE   *reescrever_voos, *reescrever_reservas;
    VOO     voos;
    RESERVA reservas;

    int existem_voos = 0;
    char num_voo[TAM_NUMVOO];
    
    existem_voos = qtd_voos_total(); // Retorna a quantidade total de voos ativos e inativos

    existe = 0;
    if( existem_voos > 0 )
    {
        ler_voos = fopen( "dados_voos_GB.bin", "r+b" );
        reescrever_voos = fopen( "tmpdados_voos_GB.bin", "wb" );

        reescrever_reservas = fopen( "tmpdados_reservas_GB.bin", "wb" );
        ler_reservas = fopen( "dados_reservas_GB.bin", "r+b" );

        if( ler_voos != NULL && ler_reservas != NULL && reescrever_voos != NULL && reescrever_reservas != NULL )
        {
            menu_excluirvoo();
            fflush(stdin);
            printf("       Qual voo deseja excluir? (JEB-XXXX)\n");
            printf("                  ");scanf("%[^\n]s", num_voo);

            strupr(num_voo);

            existe = existe_voo( existe, num_voo ); // Verifica se o voo existe no arquivo

            if( existe == 1 )
            {
                while( fread( &voos, sizeof(voos), 1, ler_voos ) ) // Passara para o outro arquivo todos 
                {                                                  // os voos, exceto o escolhido
                    if( strcmp( voos.num_voo, num_voo ) != 0 )
                    {
                        fwrite( &voos, sizeof(voos), 1, reescrever_voos );
                    }
                }

                while( fread( &reservas, sizeof(reservas), 1, ler_reservas ) ) // Passara para o outro arquivo todas 
                {                                                              // as reservas, exceto a escolhida
                    if( strcmp( reservas.res_numvoo, num_voo ) != 0 )
                    {
                        fwrite( &reservas, sizeof(reservas), 1, reescrever_reservas );
                    }
                }

                fclose( ler_voos );
                fclose( ler_reservas );
                fclose( reescrever_voos );
                fclose( reescrever_reservas ); // Fecha todos arquivos

                ler_voos = fopen( "tmpdados_voos_GB.bin", "rb" );
                reescrever_voos = fopen( "dados_voos_GB.bin", "wb" );

                ler_reservas = fopen( "tmpdados_reservas_GB.bin", "rb" );
                reescrever_reservas = fopen( "dados_reservas_GB.bin", "wb" ); // Inverte o modo de abertura dos arquivos

                while( fread( &reservas, sizeof(reservas), 1, ler_reservas ) ) // Passa todas reservas do arquivo temporario
                {                                                              // para o principal, apagando os que estao la dentro ("wb")
                    fwrite( &reservas, sizeof(reservas), 1, reescrever_reservas );
                }

                while( fread( &voos, sizeof(voos), 1, ler_voos ) )     // Passa todos voos do arquivo temporario para o principal,
                {                                                      // removendo os dados anteriores, ("wb")
                    fwrite( &voos, sizeof(voos), 1, reescrever_voos );
                }

                fclose( ler_voos );
                fclose( ler_reservas );
                fclose( reescrever_voos ); 
                fclose( reescrever_reservas ); // Fecha todos arquivos

                remove("tmpdados_voos_GB.bin");
                remove("tmpdados_reservas_GB.bin"); // Apaga os arquivos temporarios

                system("cls || clear");
                menu_excluirvoo();
                printf("            Voo excluido com sucesso!\n");
                system("pause");
                
            }
            else
            {
                system("cls || clear");
                printf("\n     ERRO! O voo nao existe.\n");
                menu_excluirvoo();
                system("pause");
            }
        }
        else
        {
            system("cls || clear");
            printf("\n     ERRO! Nao foi possivel ler os dados.\n");
            menu_excluirvoo();
            system("pause");
        }
    }
    else
    {
        system("cls || clear");
        printf("\n     ERRO! Nao existem voos cadastrados.\n");
        menu_excluirvoo();
        system("pause");
    }

}

// Funcao principal do programa.
int main()
{
    VOO     ler_dados_voo, escrever_dados_voo;
    RESERVA ler_dados_reserva, escrever_dados_reserva;
    
    int existe = 0;
    int repeat = 1;
    char num_menu;
    char num_voo[TAM_NUMVOO];
    char num_res[TAM_NUMRES];
    
    do
    {
        num_menu = menu(repeat); // Modulariza para o menu e retorna o valor selecionado nele

        if (num_menu == '9')
        {
            repeat =  0;
        }
        else
        {
            if ( (int)num_menu >= 49 && (int)num_menu <= 56 ) // O valor retornado deve ser entre 1 e 9, direcionando para os menus 1
            {
                switch(num_menu)
                {
                    case '1':
                        cadastrar_voo ( repeat, existe, num_voo, ler_dados_voo, escrever_dados_voo );
                        repeat = 1;
                        system ("cls || clear");
                        break;
                    case '2':
                        cadastrar_reserva ( repeat, existe, num_res, num_voo, ler_dados_reserva, escrever_dados_reserva );
                        repeat = 1;
                        system ("cls || clear");
                        break;
                    case '3':
                        consultar_voo ( existe, num_voo, ler_dados_voo, ler_dados_reserva );
                        repeat = 1;
                        system ("cls || clear");
                        break;
                    case '4':
                        consultar_reserva ( existe, ler_dados_reserva );
                        repeat = 1;
                        system ("cls || clear");
                        break;
                    case '5':
                        consultar_passageiro ( existe, ler_dados_reserva );
                        repeat = 1;
                        system ("cls || clear");
                        break;
                    case '6':
                        cancelar_voo ( existe, num_voo);
                        repeat = 1;
                        system ("cls || clear");
                        break;
                    case '7':
                        cancelar_reserva ( existe, num_voo, num_res );
                        repeat = 1;
                        system ("cls || clear");
                        break;
                    case '8':
                        excluir_voo ( existe );
                        repeat = 1;
                        system ("cls || clear");
                        break;
                }
            }
        }
    }while(repeat == 1);

 return 0;
}
