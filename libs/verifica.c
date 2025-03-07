#include "verifica.h"

int verifica_numero_voo(const char *num_voo)
{
    return (num_voo[0] == 'J' && num_voo[1] == 'E' &&
            num_voo[2] == 'B' && num_voo[3] == '-' &&
            num_voo[4] >= '0' && num_voo[4] <= '9' &&
            num_voo[5] >= '0' && num_voo[5] <= '9' &&
            num_voo[6] >= '0' && num_voo[6] <= '9' &&
            num_voo[7] >= '0' && num_voo[7] <= '9');
}

int verifica_voo_existente(const char *num_voo)
{
    FILE *ler_voo;
    VOO ler_dados_voo;
    int existe = 0;

    ler_voo = fopen("dados_voos_GB.bin", "rb");
    if (ler_voo == NULL) return 0;

    while (fread(&ler_dados_voo, sizeof(ler_dados_voo), 1, ler_voo))
    {
        if (strcmp(ler_dados_voo.num_voo, num_voo) == 0)
        {
            existe = 1;
            break;
        }
    }

    fclose(ler_voo);

 return existe;
}

int verifica_capacidade_passageiros(int capacidade) {
    return (capacidade >= 20 && capacidade <= 100);
}

int verifica_data_voo(int dia, int mes, int ano)
{
    time_t segundos;
    struct tm *data_atual;
    
    time(&segundos);
    data_atual = localtime(&segundos);
    
    int ano_min = data_atual->tm_year + 1909;
    int ano_max = data_atual->tm_year + 1911;

    if (ano < ano_min || ano > ano_max) return 0;
    if (mes < 1 || mes > 12) return 0;
    if (dia < 1 || dia > 31) return 0;

    // Verifica meses com menos de 31 dias
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return 0;

    if (mes == 2)
    {
        int bissexto = ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));

        if (dia > (bissexto ? 29 : 28)) return 0;
    }

    return 1;
}

int verifica_horario_voo(int horas, int minutos) {
    return (horas >= 0 && horas <= 23 && minutos >= 0 && minutos <= 59);
}

int existe_reserva( int existe, char num_res[] ) // Funcao que verifica a existencia de reservas no arquivo
{
    FILE    *ler_reservas;
    RESERVA reservas;

    ler_reservas = fopen("dados_reservas_GB.bin", "rb");

    existe = 0;

    while( fread(&reservas, sizeof(reservas), 1, ler_reservas) )
    {
        if(strcmp(reservas.num_res, num_res) == 0) // Assim que eh lida a primeira reserva, a funcao 
        {                                          // retorna que existem reservas no arquivo.
            existe = 1;
            break;
        }
    }
    fclose(ler_reservas);

 return existe;
}

int existe_voo( int existe, char num_voo[] ) // Funcao que verifica a existencia de voos no arquivo
{
    FILE *ler_voos;
    VOO   voos;

    ler_voos = fopen("dados_voos_GB.bin", "rb");

    existe = 0;
    fflush(stdin);

    while( fread( &voos, sizeof(voos), 1, ler_voos ) ) // Assim que eh lida o primeiro voo, a funcao
    {                                                  // retorna que existem voos.
        if( strcmp( voos.num_voo, num_voo ) == 0 )
        {
            existe = 1;
            break;
        }
    }
    fclose(ler_voos);

 return existe;
}

int qtd_reservas_ativas( char num_voo[] ) // Funcao que retorna a quantidade de reservas ativas em um certo
{
    FILE    *ler_reservas;
    RESERVA  reservas;

    ler_reservas = fopen("dados_reservas_GB.bin", "rb");

    int num_pass = 0;

    while( fread( &reservas, sizeof(reservas), 1, ler_reservas ) )
    {
        if( strcmp( reservas.res_numvoo, num_voo) == 0 ) // A cada reserva ativa que esta cadastrada no voo
        {                                                // eh contabilizado e no final retornada a quantidade
            if( reservas.status_res == 1 )               // de passageiros naquele voo.
            {
                num_pass++;
            }
        }
    }
    fclose(ler_reservas);

 return num_pass;
}

int existe_cpf_voo( int existe, char cpf[], char num_voo[] ) // Funcao que verifica se certo cpf ja possui reserva ativa no voo
{
    FILE *ler_reservas;
    RESERVA reservas;

    ler_reservas = fopen("dados_reservas_GB.bin", "rb");
    existe = 0;

    while( fread(&reservas, sizeof(reservas), 1, ler_reservas))
    {
        if( (strcmp(reservas.cpf, cpf) == 0) && (strcmp(reservas.res_numvoo, num_voo) == 0))
        {
            existe = 1;
            break;
        }
    }
    fclose(ler_reservas);

 return existe;
}

int max_pass( char num_voo[] ) // Funcao que retorna a quantidade maxima de reservas possiveis
{
    FILE *ler_voos;
    VOO voos;

    ler_voos = fopen("dados_voos_GB.bin", "rb");

    int maxp;

    while( fread( &voos, sizeof(voos), 1, ler_voos ) ) // Procura o voo desejado e retorna o
    {                                                  // maximo de passageiros deste
        if( strcmp(voos.num_voo, num_voo) == 0 )
        {
            maxp = voos.max_passageiros;
        }
    }
    fclose(ler_voos);
    
 return maxp;
}

int status_voo( char num_voo[] ) // Funcao que retorna o status do voo
{
    FILE *ler_voos;
    VOO voos;

    int status = 0;

    ler_voos = fopen("dados_voos_GB.bin", "rb");

    fflush(stdin);

    while( fread( &voos, sizeof(voos), 1, ler_voos ) ) // Procura o status do voo desejado
    {                                                  // no arquivo e o retorna
        if( strcmp( voos.num_voo, num_voo ) == 0 )
        {
            status = voos.status_voo;
        }
    }
    fclose(ler_voos);

 return status;
}

int qtd_voos_ativos() // Funcao que retorna a quantidade de voos com status ativo
{
    FILE *ler_voos;
    VOO voos;

    int qtd = 0;

    ler_voos = fopen("dados_voos_GB.bin", "rb");

    fflush(stdin);

    while( fread( &voos, sizeof(voos), 1, ler_voos ) ) // Procura voos com status ativo e os
    {                                                  // contabiliza, retornando a quantidade
        if( voos.status_voo == 1 )
        {
            qtd++;
        }
    }
    fclose(ler_voos);

 return qtd;
}

int qtd_voos_total() // Funcao que retorna a quantidade total de voos 
{
    FILE *ler_voos;
    VOO voos;

    int qtd = 0;

    ler_voos = fopen("dados_voos_GB.bin", "rb");

    fflush(stdin);

    while( fread( &voos, sizeof(voos), 1, ler_voos ) ) // Procura a quantidade total de voos
    {                                                  // seja ativos ou cancelados, e a retorna
        qtd++;
    }
    fclose(ler_voos);

 return qtd;
}

int comparar_data_hora_voo( char num_voo[] ) // Funcão que retorna se um certo voo ja decolou ou nao (ja = 0, nao = 1)
{
    FILE  *ler_voos;
    VOO   voos;
    DATA  *data;

    time_t segundos;
    time(&segundos);
    data = localtime(&segundos);

    int data_hora_correta = 0;

    ler_voos = fopen("dados_voos_GB.bin", "rb");

    // Ocorre a verificacao da data atual correspondente
    // a nove anos no futuro, o ano de 2030

    while( fread( &voos, sizeof(voos), 1, ler_voos ) )
    {
        if( strcmp( voos.num_voo, num_voo ) == 0 )
        {
            if ( ( voos.ano == (data -> tm_year + 1909) && (voos.mes >= data -> tm_mon + 1) ) || (voos.ano != (data -> tm_year + 1909) ) ) // O voo deve ser entre 2030 e 2032
            {   // O dia deve ser maior no mes, que o atual se estiver no mesmo mes
                // Ou o mes de ser maior que o atual se no mesmo ano
                // Ou o ano diferente do atual
                if ( ( (voos.dia >= data -> tm_mday) && (voos.ano == data -> tm_year + 1909) && (voos.mes == data -> tm_mon + 1) ) || ( (voos.mes > data -> tm_mon + 1) && (voos.ano == data -> tm_year + 1909) )  || (voos.ano != (data -> tm_year + 1909) ) ) 
                {
                    // Se no mesmo dia, no mesmo mes e no mesmo ano, o horario deve ser maior que o atual
                    if ( ( (voos.dia == data -> tm_mday) && (voos.mes == data -> tm_mon + 1) && (voos.ano == data -> tm_year + 1909) && ((((voos.horas * 60) + voos.minutos ) - ( ((data -> tm_hour) * 60) + (data -> tm_min))) > 0)) || (voos.ano != data -> tm_year + 1909) || ((voos.ano == data -> tm_year + 1909) && (voos.mes > data -> tm_mon + 1)) || ((voos.ano == data -> tm_year + 1909) && (voos.mes == data -> tm_mon + 1) && ((voos.dia > data -> tm_mday))) )
                    {

                        if( ( ( voos.dia == data -> tm_mday && voos.mes == data -> tm_mon) && ( (voos.horas == data -> tm_hour) && (voos.minutos <= data -> tm_min) ) ) || ( ( voos.dia == data -> tm_mday && voos.mes == data -> tm_mon) && (voos.horas < data -> tm_hour) ) || (voos.dia != data -> tm_mday || voos.mes != data -> tm_mon || voos.ano != data -> tm_year) )
                        {
                            data_hora_correta = 1;
                        }
                    }
                }
            }
        }
    }

    fclose(ler_voos);

 return data_hora_correta;
}

int valida_cpf(char cpf[])
{
    int correto = 0;
    int digito_val;

    // Transforma o caracter em inteiro e realiza as operacoes necessarias
    digito_val = ( ( ( (cpf[0] - '0') * 10) + ( (cpf[1] - '0') * 9) + ( (cpf[2] - '0') * 8) + ( (cpf[4] - '0') * 7) + ( (cpf[5] - '0') * 6) + ( (cpf[6] - '0') * 5) + ( (cpf[8] - '0') * 4) + ( (cpf[9] - '0') * 3) + ( (cpf[10] - '0') * 2) ) % 11);
    
    // Verifica o penultimo digito
    if( ( (digito_val == 0 || digito_val == 1) && cpf[12] == '0') || ( (cpf[12] - '0') == ( 11 - digito_val ) ) ) 
    {
        digito_val = ( ( ( (cpf[0] - '0') * 11) + ( (cpf[1] - '0') * 10) + ( (cpf[2] - '0') * 9) + ( (cpf[4] - '0') * 8) + ( (cpf[5] - '0') * 7) + ( (cpf[6] - '0') * 6) + ( (cpf[8] - '0') * 5) + ( (cpf[9] - '0') * 4) + ( (cpf[10] - '0') * 3) + ( (cpf[12] - '0') * 2) ) % 11);

        // Verifica o ultimo digito
        if( ( (digito_val == 0 || digito_val == 1) && cpf[13] == '0') || ( (cpf[13] - '0') == ( 11 - digito_val ) ) )
        {
            correto = 1;
        }
        else
        {
            correto = 0;
        }
    }
    else
    {
        correto = 0;
    }

 return correto;
}