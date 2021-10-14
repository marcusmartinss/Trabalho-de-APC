// Marcus Vinicius Paiva Martins - 211043683
// Algumas funções ainda são protótipos, por favor desconsiderá-las.
// As funções estão funcionando mas ainda vou adicionar algumas coisas nas mesmas para otimização e melhorar a UX
// Alguns textos estarão desalinhados em relação ao menu e estes detalhes serão corrigidos posteriormente
// Alguns comentários fica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_NUMVOO 9    // Tamanho vetor do número do voo
#define TAM_NUMRES 10   // Tamanho do vetor do número de reserva
#define TAM_CPF 15      // Tamanho do vetor de CPF
#define TAM_NOME 100    // Tamanho máximo permitido para um nome

typedef struct tm DATA;
struct DATA
{
    int tm_sec;   // Indica os segundos entre 0 e 59
    int tm_min;   // Indica os minutos entre 0 e 59
    int tm_hour;  // Indica as horas entre 0 e 24
    int tm_mday;  // Indica o dia do mês entre 1 e 31
    int tm_mon;   // Indica os meses do ano entre 0 e 11
    int tm_year;  // Indica o ano a partir de 1900
    int tm_wday;  // Indica o dia da semana de 0 (domingo) até 6 (sábado)
    int tm_yday;  // Indica o dia do ano entre 1 e 365
    int tm_isdst; // Indica horário de verão em booleanos
};

typedef struct reserva RESERVA;
struct reserva
{
    char num_res[TAM_NUMRES];       // String do número de reserva
    char res_numvoo[TAM_NUMVOO];    // String para o número de um voo para uma certa reserva
    char cpf[TAM_CPF];              // String para o CPF da pessoa fazendo a reserva
    char nome[TAM_NOME];            // String do nome da pessoa
    char sexo;                      // Caracter que indica o sexo da pessoa a fazer a reserva
    int  nasc_dia;                  // Inteiro para o dia de nascimento do passageiro
    int  nasc_mes;                  // Inteiro para o mes de nascimento do passageiro
    int  nasc_ano;                  // Inteiro para o ano de nascimento do passageiro
    int  status_res;                // Inteiro indicando o status da reserva em booleanos
};

typedef struct voo VOO;
struct voo
{
    char num_voo[TAM_NUMVOO];       // String para o número do voo a ser cadastrado
    int  max_passageiros;           // Número máximo de passageiros no voo
    int  dia;                       // Dia do voo
    int  mes;                       // Mes do voo
    int  ano;                       // Ano do voo
    int  horas;                     // Hora do voo
    int  minutos;                   // Minutos do voo
    int  status_voo;                // Status do voo em booleanos
};

void menu_cadastrarvoo() // Cabeçalho usado durante o cadastro do voo
{
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Cadastrar voo                        |\n");
    printf("    |______________________________________|\n\n");

}

void menu_cadastrarreserva() // Cabeçalho usado durante o cadastro da reserva
{
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Cadastrar reserva                    |\n");
    printf("    |______________________________________|\n\n");
}

void menu_consultar_voo() // Cabeçalho usado durante a consulta do voo
{
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Consultar voo                        |\n");
    printf("    |______________________________________|\n\n");  
}

void menu_consultar_reserva1() // Cabeçalho usado durante a consulta de uma reserva
{
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Consultar reserva                    |\n");
    printf("    |______________________________________|\n\n");                      
}

char menu_consultar_reserva2(int repeat) // Menu de escolha para qual modo será consultado um passageiro
{
    char opcao_consult;
    do
    {
        repeat = 0;

        printf("     ______________________________________\n");
        printf("    |            Galactic Birds            |\n");
        printf("    |    'Sua confianca sob nossas asas'   |\n");
        printf("    |--------------------------------------|\n");
        printf("    | Consultar passageiro                 |\n");
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
        printf("                      "); scanf("%c", &num_menu);   // É lido um número na forma de  caracter para economizar memória e 
     //                                                             // evitar loops infinitos, caso, por acidente, seja inserido outro valor.
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

// Função Cadastrar voo.
void cadastrar_voo(int repeat, int existe, char *num_voo, VOO dados_voo) // Reutilizam-se as variáveis de repetição, existência, a string do
{                                                                        // número de voo, e a struct dos dados do voo;
    FILE  *ler_voo, *add_voo; 
    DATA  *data;

    ler_voo = fopen("dados_voos_GB.bin", "rb");
    add_voo = fopen("dados_voos_GB.bin", "ab");

    time_t segundos;
    time(&segundos);
    data = localtime(&segundos);

    int i = 0;
    int j = 0;
    char separador[3];

    existe = 0;
    repeat = 1;

    system("cls");

    if (ler_voo == NULL || add_voo == NULL)
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
            printf("                  "); scanf("%s", num_voo);
            system("cls");

            strupr(num_voo); // Nomes, números de voo e reserva serão sempre todos maiúsculos para facilitar a padronização e verificação
            existe = 0;

            // Verificação do formato do número de voo
            if (num_voo[0] == 'J' && num_voo[1] == 'E' && num_voo[2] == 'B' && num_voo[3] == '-' && (num_voo[4] - '0' >=  0 && num_voo[4] - '0' <= 9) && (num_voo[5] - '0' >= 0 && num_voo[5] - '0' <= 9) && ( num_voo[6] - '0' >= 0 && num_voo[6] - '0' <= 9) && ( num_voo[7] - '0' >= 0 && num_voo[7] - '0' <= 9) )
            {
                existe = 0;
                while( fread(&dados_voo, sizeof(dados_voo), 1, ler_voo) ) // Verificação se já existe o número de voo inserido já existe
                {
                    if( strcmp(dados_voo.num_voo, num_voo) == 0)
                    {
                        existe = 1;
                        break;
                    }
                }

                if ( existe == 1 ) // Se for repetido, é pedido um novo número
                {
                    system("cls");
                    repeat = 1;
                    printf("\n         ERRO! Este numero de voo ja existe.\n");

                }
                else // Se não for, o número do voo é passado para a struct
                {
                    fclose(ler_voo);
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
                                printf("             Insira a data do voo:\n"); // Separadores são apenas para verificar o formato e não são levados a struct
                                printf("                  "); scanf( "%d%c%d%c%d", &dados_voo.dia, &separador[0], &dados_voo.mes, &separador[1], &dados_voo.ano);

                                if ((separador[0] == '/' && separador[1] == '/') || (separador[0] == '-' && separador[1] == '-'))   // A data pode ser inserida no formato
                                {                                                                                                   // dd-mm-aaaa ou dd/mm/aaaa
                                    if ((dados_voo.ano >= (data -> tm_year + 1909)) && (dados_voo.ano <= (data -> tm_year + 1911)))
                                    {
                                        if ((dados_voo.mes >= 1 && dados_voo.mes <= 12) && (dados_voo.dia >= 1 && dados_voo.dia <= 31)) // Ocorre a verificação da data atual correspondente                                                                                                                                        // a 
                                        {                                                                                               // a nove anos no futuro, o ano de 2030
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
                                                                if (separador[2] == ':')        // Verificação dos horários, ainda correspondentes ao atual horário.
                                                                {
                                                                    if ( ( (dados_voo.dia == data -> tm_mday) && (dados_voo.mes == data -> tm_mon + 1) && (dados_voo.ano == data -> tm_year + 1909) && ((((dados_voo.horas * 60) + dados_voo.minutos ) - ( ((data -> tm_hour) * 60) + (data -> tm_min))) > 60)) || (dados_voo.ano != data -> tm_year + 1909) || ((dados_voo.ano == data -> tm_year + 1909) && (dados_voo.mes > data -> tm_mon + 1)) || ((dados_voo.ano == data -> tm_year + 1909) && (dados_voo.mes == data -> tm_mon + 1) && ((dados_voo.dia > data -> tm_mday))) )
                                                                    {
                                                                        if ( ( dados_voo.dia == data -> tm_mday && dados_voo.mes == data -> tm_mon) && ((dados_voo.horas == data -> tm_hour) && (dados_voo.minutos <= data -> tm_min)) || ( dados_voo.dia == data -> tm_mday && dados_voo.mes == data -> tm_mon) && (dados_voo.horas < data -> tm_hour)  || (dados_voo.dia != data -> tm_mday || dados_voo.mes != data -> tm_mon || dados_voo.ano != data -> tm_year) )
                                                                        {
                                                                            repeat = 0;
                                                                            dados_voo.status_voo = 1;
                                                                            fflush(stdin);
                                                                            fwrite(&dados_voo, sizeof(VOO), 1, add_voo);
                                                                            fclose(add_voo);
                                                                            system("cls");
                                                                        }
                                                                        else
                                                                        {
                                                                            // Caso alguma das condições não forem satisfeitas, a tela será limpa, aparecerá um mensagem de erro, e pedirá inserção dos dados novamente.
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
int cadastrar_reserva(int repeat, int existe, char *num_voo, char *num_res, VOO dados_voo, RESERVA dados_reserva)
{
    FILE *ler_reservas, *add_reserva;
    FILE *ler_voos;
    DATA    *data;
    time_t  segundos;

    ler_reservas = fopen("dados_reservas_GB.bin", "rb");
    add_reserva = fopen("dados_reservas_GB.bin", "ab");

    ler_voos = fopen("dados_voos_GB.bin", "rb");
    
    time(&segundos);
    data = localtime(&segundos);

    int  i = 0;
    int  j = 0;
    char cpf[15];
    char nome[TAM_NOME];
    char separador[2];

    existe = 0;
    repeat = 1;

    if(ler_reservas == NULL || add_reserva == NULL || ler_voos == NULL)
    {
        printf("     ERRO! Um dos arquivos nao pode ser aberto.");
        exit(1);
    }
    else
    {
        system("cls");
        do
        {
            num_res[0] = '\0';
            repeat = 0;

            menu_cadastrarreserva();
            fflush(stdin);
            printf("         Insira o numero da reserva:\n");
            printf("                 ");scanf("%s", num_res); 

            strupr(num_res);

            if (num_res[0] == 'G' && num_res[1] == 'B' && num_res[2] == '-' && num_res[3] - '0' >= 0 && num_res[3] - '0' <= 9 && num_res[4] - '0' >= 0 && num_res[4] - '0' <= 9 && num_res[5] - '0' >= 0 && num_res[5] - '0' <= 9 && num_res[6] - '0' >= 0 && num_res[6] - '0' <= 9 && num_res[7] - '0' >= 0 && num_res[7] - '0' <= 9 && num_res[8] - '0' >= 0 && num_res[8] - '0' <= 9)
            {
                existe = 0;

                while( fread(&dados_reserva, sizeof(dados_reserva), 1, ler_reservas) )
                {
                    if(strcmp(dados_reserva.num_res, num_res) == 0)
                    {
                        existe = 1;   
                        break;
                    }

                }

                if( existe == 1)
                {
                    repeat = 1;
                    system("cls");
                    printf("    ERRO! O numero de reserva ja existe.\n");
                }
                else
                {
                    repeat = 0;
                    system("cls");
                    fclose(ler_reservas);
                    strcpy(dados_reserva.num_res, num_res);

                    do
                    {
                        num_voo[0] = '\0';
                        repeat = 0;

                        menu_cadastrarreserva();
                        fflush(stdin);
                        printf("    Insira o numero do voo:\n");
                        printf("    ");scanf("%s", num_voo);

                        strupr(num_voo);


                        if (num_voo[0] == 'J' && num_voo[1] == 'E' && num_voo[2] == 'B' && num_voo[3] == '-' && (num_voo[4] - '0' >=  0 && num_voo[4] - '0' <= 9) && (num_voo[5] - '0' >= 0 && num_voo[5] - '0' <= 9) && ( num_voo[6] - '0' >= 0 && num_voo[6] - '0' <= 9) && ( num_voo[7] - '0' >= 0 && num_voo[7] - '0' <= 9) )
                        {
                            existe = 0; 

                            while( fread(&dados_voo, sizeof(dados_voo), 1, ler_voos) )
                            {
                                if(strcmp(dados_voo.num_voo, num_voo) == 0)
                                {
                                    existe = 1;
                                    break;
                                }
                            }

                            if(existe == 0)
                            {
                                repeat = 1;
                                system("cls");
                                printf("    ERRO! O voo nao existe.\n");
                            }
                            else
                            {
                                system("cls");
                                fclose(ler_voos);
                                strcpy(dados_reserva.res_numvoo, num_voo);

                                existe = 0;
                                do
                                {
                                    cpf[0] = '\0';
                                    menu_cadastrarreserva();
                                    fflush(stdin);
                                    printf("         Insira o CPF:\n");
                                    printf("         "); scanf("%s", cpf);

                                    if( (cpf[0] - '0') >= 0 && (cpf[0] - '0') <= 9 && (cpf[1] >= 0 - '0') && (cpf[1] - '0') <= 9 && (cpf[2] - '0') >= 0 && (cpf[2] - '0') <= 9 && cpf[3] == '.' && (cpf[4] - '0') >= 0 && (cpf[4] - '0') <= 9 && (cpf[5] - '0') >= 0 && (cpf[5] - '0') <= 9 && (cpf[6] - '0') >= 0 && (cpf[6] - '0') <= 9 && cpf[7] == '.' && (cpf[8] - '0') >= 0 && (cpf[8] - '0') <= 9 && (cpf[9] - '0') >= 0 && (cpf[9] - '0') <= 9 && (cpf[10] - '0') >= 0 && (cpf[10] - '0') <= 9 && cpf[11] == '-' && (cpf[12] - '0') >= 0 && (cpf[12] - '0') <= 9 && (cpf[13] - '0') >= 0 && (cpf[13] - '0') <= 9)
                                    {
                                        existe = 0;
                                        while( fread(&dados_reserva, sizeof(dados_reserva), 1, ler_reservas))
                                        {
                                            if( (strcmp(dados_reserva.cpf, cpf) == 0) && (strcmp(dados_reserva.res_numvoo, num_voo) == 0))
                                            {
                                                existe = 1;
                                                break;
                                            }
                                        }
                                        
                                        if(existe == 1)
                                        {
                                            repeat = 1;
                                            system("cls");
                                            printf("ERRO! O CPF ja esta cadastrado no voo.\n");
                                        }
                                        else
                                        {
                                            system("cls");
                                            strcpy(dados_reserva.cpf, cpf);
                                            do
                                            {
                                                nome[0] = '\0';

                                                repeat = 0;
                                                menu_cadastrarreserva();
                                                fflush(stdin);
                                                printf("      Insira o nome completo:\n"); 
                                                scanf("%[^\n]s", nome);
                                                
                                                strupr(nome);
                                                
                                                for(i = 0; i < strlen(nome) - 1; i++)
                                                {
                                                    if ( ! ((int)nome[i] >= 65 && (int)nome[i] <= 90 || (int)nome[i] == 32))
                                                    {
                                                        repeat = 1;
                                                        system("cls");
                                                        printf("ERRO! O nome inserido nao eh valido.\n\n");
                                                        break;
                                                    }
                                                }

                                                if (repeat == 0)
                                                {
                                                    system("cls");
                                                    fclose(ler_reservas);
                                                    fflush(stdout);
                                                    existe = 0;
                                                    while( fread(&dados_reserva, sizeof(dados_reserva), 1, ler_reservas))
                                                    {
                                                        if( (strcmp(dados_reserva.nome, nome) == 0) && (strcmp(dados_reserva.res_numvoo, num_voo) == 0) )
                                                        {
                                                            existe = 1;
                                                            break;
                                                        }
                                                    }

                                                    if(existe == 1)
                                                    {
                                                        repeat = 1;
                                                        system("cls");
                                                        printf("ERRO! A pessoa ja tem reserva no voo.\n");
                                                    }
                                                    else
                                                    {
                                                        system("cls");
                                                        existe = 0;
                                                        fclose(ler_reservas);
                                                        strcpy(dados_reserva.nome, nome);
                                                        do
                                                        {
                                                            repeat = 0;
                                                            menu_cadastrarreserva();

                                                            fflush(stdin);
                                                            printf("    Insira o sexo (M/F):\n");
                                                            printf("             ");scanf("%c", &dados_reserva.sexo);

                                                            if(dados_reserva.sexo == 'm')
                                                            {
                                                                dados_reserva.sexo = 'M';
                                                            }
                                                            else
                                                            {
                                                                if(dados_reserva.sexo == 'f')
                                                                {
                                                                    dados_reserva.sexo = 'F';
                                                                }
                                                            }

                                                            if( dados_reserva.sexo != 'M' || dados_reserva.sexo != 'F')
                                                            {
                                                                system("cls");
                                                                do
                                                                {
                                                                    repeat = 0;
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
                                                                                fwrite(&dados_reserva, sizeof(dados_reserva), 1, add_reserva);
                                                                                fclose(add_reserva);
                                                                                fclose(ler_reservas);
                                                                                system("cls");
                                                                            }
                                                                            else
                                                                            {
                                                                                repeat = 1;
                                                                                system("cls");
                                                                                printf("    ERRO! O dia inserido não existe.\n");
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                                repeat = 1;
                                                                                system("cls");
                                                                                printf("    ERRO! O ano inserido não existe.\n");
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        repeat = 1;
                                                                        system("cls");
                                                                        printf("    ERRO! Formato de data incorretol.");
                                                                    }

                                                                }while(repeat == 1);
                                                            }
                                                            else
                                                            {
                                                                repeat = 1;
                                                                system("cls");
                                                                printf("    ERRO! Insira um caracter valido.\n");
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
                                        system("cls");
                                        printf("         ERRO! O formato do CPF esta errado.\n");
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
            else
            {
                repeat = 1;
                system("cls");
                printf("       ERRO! Formato do numero de reserva incorreto.\n");
            }
               
        }while(repeat == 1);

    }

 return 0;
}

// Função Consultar voo.
void consultar_voo(int repeat, int existe, char *num_voo, VOO dados_voo, RESERVA dados_reserva)
{
    FILE *ler_voos;
    FILE *ler_dados_res, *ler_reservas;
    
    int total_pass = 0;
    int max_pass;
    char dia[3], mes[3], ano[5];
    char confirm;

    ler_voos = fopen("dados_voos_GB.bin", "rb");
    ler_dados_res = fopen("dados_reservas_GB.bin", "rb");
    ler_reservas = fopen("dados_reservas_GB.bin", "rb");

    do
    {
        existe = 0;
        repeat = 0;
        num_voo[0] = '\0';

        menu_consultar_voo();
        fflush(stdin);
        printf("   Insira o numero do voo desejado:\n");
        printf("  ");scanf("%s", num_voo);

        strupr(num_voo);

        while( fread(&dados_reserva, sizeof(dados_reserva), 1, ler_dados_res) )
        {
            if( (strcmp(dados_reserva.res_numvoo, num_voo) == 0) && (dados_reserva.status_res == 1) )
            {
                total_pass++;
                existe = 1;
            }
        }
        fclose(ler_dados_res);

        while( fread(&dados_voo, sizeof(dados_voo), 1, ler_voos))
        {
            if(strcmp(dados_voo.num_voo, num_voo) == 0)
            {
                max_pass = dados_voo.max_passageiros;

                if(dados_voo.dia < 10)
                {
                    dia[0] = '0'; dia[1] = dados_voo.dia - '0';
                }
                else
                {
                    strcpy(dia, dados_voo.dia);
                }

                if(dados_voo.mes < 10)
                {
                    mes[0] = '0'; mes[1] = dados_voo.mes - '0';
                }
                else
                {
                    strcpy(dia, dados_voo.mes);
                }
                
                strcpy(ano, (dados_voo.ano - '0'));
            }
        }
        fclose(ler_voos);
            
        if(existe == 1)
        {
            repeat = 0;
            menu_consultar_voo();
            
            printf("     ______________________________________\n");
            printf("    |              %s                |\n", num_voo);
            printf("    |--------------------------------------|\n");
            printf("    | Data    : %d/%d/%d                 |\n", dados_voo.dia, dados_voo.mes, dados_voo.ano);
            printf("    | Ocupacao: %.2f%%                      |\n", ((100.0 *total_pass)/max_pass));
            printf("    |______________________________________|\n\n");

            printf("    PASSAGEIROS:\n\n");

            while( fread(&dados_reserva, sizeof(dados_reserva), 1, ler_reservas) )
            {
                if( (strcmp(dados_reserva.res_numvoo, num_voo) == 0) && (dados_reserva.status_res == 1))
                {
                    printf("    %s\n", dados_reserva.nome);
                }
            }
            printf("\n");
            system("pause");
        }
        else
        {
            do
            {
                confirm = '\0';
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
    FILE *ler_reservas, *ler_voos;

    struct reserva res_consultares;
    struct voo voo_consultares;

    char nome_pass[100];
    char confirm;
    
    ler_reservas = fopen("dados_reservas_GB", "rb");

    ler_voos = fopen("dados_voos_GB", "rb");

    do
    {
        menu_consultar_reserva1();

        printf("   Insira o nome completo do passageiro:\n");
        printf("  ");scanf("%[^\n]s", nome_pass);

        strupr(nome_pass);

        while(&res_consultares, sizeof(res_consultares), 1, ler_reservas)
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
            printf("     %s\n", nome_pass);
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
int cancelar_voo(VOO dados_voo)
{
    FILE *ler_voo;
    ler_voo = fopen("dados_voo_GB.bin", "rb");
    while(fread(&dados_voo, sizeof(struct voo), 1, ler_voo))
    {
        printf("%s\n%d\n%d/%d/%d\n%d:%d\n%d\n", dados_voo.num_voo, dados_voo.max_passageiros, dados_voo.dia, dados_voo.mes, dados_voo.ano, dados_voo.horas, dados_voo.minutos, dados_voo.status_voo);
    }
    fclose(ler_voo);
    system("pause");
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
    VOO   dados_voo;
    RESERVA dados_reserva;
    
    int existe = 0;
    int repeat = 1;
    char num_menu;
    char num_res[TAM_NUMRES];
    char num_voo[TAM_NUMVOO];

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
                        cadastrar_voo(repeat, existe, num_voo, dados_voo);
                        repeat = 1;
                        system("cls");
                        printf("         Voo cadastrado com sucesso!\n\n");
                        break;
                    case '2':
                        cadastrar_reserva(repeat, existe, num_voo, num_res, dados_voo, dados_reserva);
                        repeat = 1;
                        system("cls");
                        break;
                    case '3':
                        consultar_voo(repeat, existe, num_voo, dados_voo, dados_reserva);
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
                        cancelar_voo(dados_voo);
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
