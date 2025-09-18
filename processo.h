#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct {
    int id_processo;
    char numero_sigilo[50];
    char sigla_grau[4];
    char procedimento[100];
    char ramo_justica[50];
    char sigla_tribunal[10];
    int id_tribunal;
    int recurso;
    char id_ultimo_oj[50];
    char dt_recebimento[11];
    int id_ultima_classe;
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigenas;
    int flag_infancia;
    char decisao[100];
    char dt_resolvido[11];
    int cnm1;
    int primeirasentm1;
    int baixm1;
    int decm1;
    int mpum1;
    int julgadom1;
    int desm1;
    int susm1;
} Processo;


// Função: lerProcesso transforma uma linha CSV em struct Processo
Processo lerProcesso(char *linha);

#endif
