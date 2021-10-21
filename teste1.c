#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NUMVOO 9    // Tamanho vetor do número do voo

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

int main()
{
    VOO   dados_voo;

    FILE *ler_voo;

    ler_voo = fopen("dados_voos_GB.bin", "rb");

    while( fread( &dados_voo, sizeof( dados_voo ), 1,  ler_voo ) )
    {
        printf("%s\n", dados_voo.num_voo);
        printf("%d/%d/%d\n", dados_voo.dia, dados_voo.mes, dados_voo.ano);
        printf("%d:%d\n", dados_voo.horas, dados_voo.minutos);
        printf("%d\n\n", dados_voo.status_voo);
    }
 return 0;
}