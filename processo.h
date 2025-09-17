#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct {
    int id_processo;
    int numero_sigiloso;
    char sigla_grau[2];
    char procedimento[50];
    char ramo_justica[50];
    char sigla_tribunal[10];
    int id_tribunal;
    int recurso;
    char id_ultimo_oj[50];
    char data_recebimento[10];
    int id_ultima_classe;
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigena;
    int flag_infancia;
    char decisao[100];
    char data_resolvimenento[10];
    int cnm1;
    int primeirasentm1;
    int baixm1;
    int decm1;
    int mpum1;
    int julgadom1;
    int desm1;
    int susm1;
} Processo;

//Funções:
int lerProcesso(Processo **vetor, int *n);

#endif