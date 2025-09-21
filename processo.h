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
    char cnm1[10];
    char primeirasentm1[10];
    char baixm1[10];
    char decm1[10];
    char mpum1[10];
    char julgadom1[10];
    char desm1[10];
    char susm1[10];
} Processo;


// Função: lerProcesso transforma uma linha CSV em struct Processo
Processo lerProcesso(char *linha);
int contarProcessos(FILE *arquivo);
int buscarUltimoOj(Processo processos[], int total, int id_processo);
int processoMaisAntigo(Processo processos[], int n);
int contarViolenciaDomestica(Processo processos[], int n);
int contarFeminicidio(Processo processos[], int n);
int contarAmbiental(Processo processos[], int n);
int contarQuilombolas(Processo processos[], int n);
int contarIndigenas(Processo processos[], int n);
int contarInfancia(Processo processos[], int n);
int DiasEntreDatas(Processo *processos, int id_processo, int total);
double Meta1(Processo *processos, int totalProcessos);
int ExportarProcessosJulgado(Processo *processos, int totalProcessos, char *nomeArquivo);



#endif