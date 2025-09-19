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
    int id_ultimo_oj;
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
int contarProcessos(FILE *arquivo);
int buscarUltimoOj(Processo processos[], int total, int id_processo);
int processoMaisAntigo(Processo processos[], int n);
void contarCausas(Processo processos[], int n);
int DiasEntreDatas(Processo *processos, int id_processo, int total);



#endif

/*O código-fonte a ser construído deve ser capaz de determinar:

o percentual de cumprimento da meta 1;
e gerar um arquivo CSV com todos os processos julgados (mérito) na Meta 1.
*/