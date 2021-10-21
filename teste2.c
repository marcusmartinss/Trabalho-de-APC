#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NUMVOO 9    // Tamanho vetor do número do voo
#define TAM_NUMRES 10   // Tamanho do vetor do número de reserva
#define TAM_CPF 15      // Tamanho do vetor de CPF
#define TAM_NOME 100    // Tamanho máximo permitido para um nome

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


int main()
{
    RESERVA dados_reserva;

    FILE *ler_reserva;

    ler_reserva = fopen("dados_reservas_GB.bin", "rb");

    while( fread( &dados_reserva, sizeof( dados_reserva ), 1, ler_reserva ) )
    {
        printf("%s\n", dados_reserva.num_res);
        printf("%s\n", dados_reserva.res_numvoo);
        printf("%s\n", dados_reserva.cpf);
        printf("%s\n", dados_reserva.nome);
        printf("%c\n", dados_reserva.sexo);
        printf("%d/%d/%d\n", dados_reserva.nasc_dia, dados_reserva.nasc_mes, dados_reserva.nasc_ano);
        printf("%d\n\n", dados_reserva.status_res);
    }

/*while( fread( &dados_voo, sizeof( dados_voo ), 1,  ler_voo ) )
    {
        printf("%s\n", dados_voo.num_voo);
        printf("%d/%d/%d\n", dados_voo.dia, dados_voo.mes, dados_voo.ano);
        printf("%d:%d\n", dados_voo.horas, dados_voo.minutos);
        printf("%d\n\n", dados_voo.status_voo);
    }
*/
}