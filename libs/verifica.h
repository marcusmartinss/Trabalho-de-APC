#ifndef VERIFICA_H
#define VERIFICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"

// Função para verificar formato do número do voo
int verifica_numero_voo(const char *num_voo);

// Função para verificar se o número do voo já existe
int verifica_voo_existente(const char *num_voo);

// Função para verificar a capacidade de passageiros
int verifica_capacidade_passageiros(int capacidade);

// Função para validar a data do voo
int verifica_data_voo(int dia, int mes, int ano);

// Função para validar o horário do voo
int verifica_horario_voo(int horas, int minutos);


int existe_reserva(int existe, char num_res[]);

int existe_voo(int existe, char num_voo[]);

int qtd_reservas_ativas(char num_voo[]);

int existe_cpf_voo(int existe, char cpf[], char num_voo[]);

int max_pass(char num_voo[]);

int status_voo(char num_voo[]);

int qtd_voos_ativos();

int qtd_voos_total();

int comparar_data_hora_voo(char num_voo[]);

int valida_cpf(char cpf[]);

#endif
