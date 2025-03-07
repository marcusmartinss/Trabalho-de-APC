#ifndef STRUCTS_H
#define STRUCTS_H

#include "consts.h" // Inclui as constantes definidas
#include <time.h>   // Biblioteca para manipulação de datas e horários

// Definição da estrutura para manipulação de datas (substituindo struct tm, padrão da biblioteca time.h)
typedef struct tm DATA;
struct DATA
{
    int tm_sec;     // Segundos (0 a 59)
    int tm_min;     // Minutos (0 a 59)
    int tm_hour;    // Horas (0 a 24)
    int tm_mday;    // Dia do mês (1 a 31)
    int tm_mon;     // Mês (0 a 11)
    int tm_year;    // Ano (a partir de 1900)
    int tm_wday;    // Dia da semana (0 = domingo até 6 = sábado)
    int tm_yday;    // Dia do ano (1 a 365)
    int tm_isdst;   // Indica horário de verão (0 = não, 1 = sim)
};

// Estrutura para armazenar informações de uma reserva
typedef struct reserva RESERVA;
struct reserva
{
    char num_res[TAM_NUMRES];       // Número de reserva
    char res_numvoo[TAM_NUMVOO];    // Número do voo associado à reserva
    char cpf[TAM_CPF];              // CPF do passageiro
    char nome[TAM_NOME];            // Nome do passageiro
    char sexo;                      // Sexo do passageiro ('M' ou 'F')
    int  nasc_dia;                  // Dia de nascimento do passageiro
    int  nasc_mes;                  // Mês de nascimento do passageiro
    int  nasc_ano;                  // Ano de nascimento do passageiro
    int  status_res;                // Status da reserva (1 = ativa, 0 = cancelada)
};

// Estrutura para armazenar informações de um voo
typedef struct voo VOO;
struct voo
{
    char num_voo[TAM_NUMVOO];       // Número do voo
    int  max_passageiros;           // Número máximo de passageiros
    int  dia;                       // Dia do voo
    int  mes;                       // Mês do voo
    int  ano;                       // Ano do voo
    int  horas;                     // Horário (horas)
    int  minutos;                   // Horário (minutos)
    int  status_voo;                // Status do voo (1 = ativo, 0 = cancelado)
};

#endif // STRUCTS_H
