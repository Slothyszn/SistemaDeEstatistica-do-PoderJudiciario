#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "processo.h"

// Salva as linhas dos processos na struct
Processo lerProcesso(char *linha) {
    Processo p;

    sscanf(linha, "%d;%49[^;];%3[^;];%99[^;];%49[^;];%9[^;];%d;%d;%d;%10[^;];%d;%d;%d;%d;%d;%d;%d;%99[^;];%10[^;];%10[^;];%10[^;];%10[^;];%10[^;];%10[^;];%10[^;];%10[^;];%10[^;]",
           &p.id_processo, p.numero_sigilo, p.sigla_grau, p.procedimento, p.ramo_justica, p.sigla_tribunal,
           &p.id_tribunal, &p.recurso, &p.id_ultimo_oj, p.dt_recebimento, &p.id_ultima_classe,
           &p.flag_violencia_domestica, &p.flag_feminicidio, &p.flag_ambiental, &p.flag_quilombolas,
           &p.flag_indigenas, &p.flag_infancia, p.decisao, p.dt_resolvido,
           p.cnm1, p.primeirasentm1, p.baixm1, p.decm1, p.mpum1, p.julgadom1, p.desm1, p.susm1);

    return p;
}

//o número de processos presentes na base de dados
int contarProcessos(FILE *arquivo) {
    char linha[1024];
    int contador = 0;

    // Pula o cabeçalho
    fgets(linha, sizeof(linha), arquivo);

    // Conta as linhas seguintes
    while (fgets(linha, sizeof(linha), arquivo)) {
        contador++;
    }

    // Volta o ponteiro do arquivo para o início
    rewind(arquivo);

    return contador;
}

//busca o id_ultimo_oj a partir de id_processo.
int buscarUltimoOj(Processo *processos,int totalProcessos, int id_processo) {
    int i = 0;
    for (i = 0; i < totalProcessos; i++) {
        if (processos[i].id_processo == id_processo) {
            return processos[i].id_ultimo_oj;
        }
    }

    return -1;
}

//o id_processo do processo com dt_recebimento mais antigo;
int processoMaisAntigo(Processo processos[], int n) {
    if (n == 0) return -1; // caso não haja processos

    int idx = 0; // assume o primeiro como mais antigo

    for (int i = 1; i < n; i++) {
        if (strcmp(processos[i].dt_recebimento, processos[idx].dt_recebimento) < 0) {
            idx = i;
        }
    }

    return processos[idx].id_processo;
}

int contarViolenciaDomestica(Processo processos[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (processos[i].flag_violencia_domestica) cont++;
    }
    return cont;
}

int contarFeminicidio(Processo processos[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (processos[i].flag_feminicidio) cont++;
    }
    return cont;
}

int contarAmbiental(Processo processos[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (processos[i].flag_ambiental) cont++;
    }
    return cont;
}

int contarQuilombolas(Processo processos[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (processos[i].flag_quilombolas) cont++;
    }
    return cont;
}

int contarIndigenas(Processo processos[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (processos[i].flag_indigenas) cont++;
    }
    return cont;
}

int contarInfancia(Processo processos[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (processos[i].flag_infancia) cont++;
    }
    return cont;
}

//o número de dias entre dt_recebimento e dt_resolvido

int DiasEntreDatas(Processo *processos, int totalProcessos,int id_processo){
    int dt_recebimento, dt_resolvido, i;
    for (i = 0; i < totalProcessos; i++) {
        if (processos[i].id_processo == id_processo) {
            struct tm inicio = {0}, fim = {0};
            sscanf(processos[i].dt_recebimento, "%d-%d-%d", &inicio.tm_year, &inicio.tm_mon, &inicio.tm_mday);
            sscanf(processos[i].dt_resolvido, "%d-%d-%d", &fim.tm_year, &fim.tm_mon, &fim.tm_mday);
            inicio.tm_year -= 1900; fim.tm_year -= 1900;
            inicio.tm_mon -= 1; fim.tm_mon -= 1;
            return (int)(difftime(mktime(&fim), mktime(&inicio)) / (60*60*24));
        }
    }

    return -1;
}


double Meta1(Processo *processos, int totalProcessos) {
    double julgadom1 = 0, cnm1 = 0, desm1 = 0, susm1 = 0, meta1Resultado;
    int i;
    for (i = 0; i < totalProcessos; i++) {
        julgadom1 += atof(processos[i].julgadom1);
        cnm1 += atof(processos[i].cnm1);
        desm1 += atof(processos[i].desm1);
        susm1 += atof(processos[i].susm1);
    }

    double divisor;
    divisor = cnm1 + desm1 - susm1;
    if (divisor == 0) { 
        return 0.0;
    }

    meta1Resultado = (julgadom1 / divisor) * 100;;

    return meta1Resultado;
}


int ExportarProcessosJulgado(Processo *processos, int totalProcessos, char *nomeArquivo) {
    FILE *arquivoSalvamento;
    arquivoSalvamento = fopen(nomeArquivo, "w");

    if (!arquivoSalvamento) {
        printf("Erro ao criar arquivo %s\n", nomeArquivo);
        exit(0);
    }

    fprintf(arquivoSalvamento, "id_processo;numero_sigilo;sigla_grau;procedimento;ramo_justica;sigla_tribunal;id_tribunal;recurso;id_ultimo_oj;dt_recebimento;id_ultima_classe;flag_violencia_domestica;flag_feminicidio;flag_ambiental;flag_quilombolas;flag_indigenas;flag_infancia;decisao;dt_resolvido;cnm1;primeirasentm1;baixm1;decm1;mpum1;julgadom1;desm1;susm1\n");
    
    int i, j = 0;
    for (i = 0; i < totalProcessos; i++) {
        if (atof(processos[i].julgadom1) > 0) {
            fprintf(arquivoSalvamento, "%d;%s;%s;%s;%s;%s;%d;%d;%d;%s;%d;%d;%d;%d;%d;%d;%d;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
                processos[i].id_processo,
                processos[i].numero_sigilo,
                processos[i].sigla_grau,
                processos[i].procedimento,
                processos[i].ramo_justica,
                processos[i].sigla_tribunal,
                processos[i].id_tribunal,
                processos[i].recurso,
                processos[i].id_ultimo_oj,
                processos[i].dt_recebimento,
                processos[i].id_ultima_classe,
                processos[i].flag_violencia_domestica,
                processos[i].flag_feminicidio,
                processos[i].flag_ambiental,
                processos[i].flag_quilombolas,
                processos[i].flag_indigenas,
                processos[i].flag_infancia,
                processos[i].decisao,
                processos[i].dt_resolvido,
                processos[i].cnm1,
                processos[i].primeirasentm1,
                processos[i].baixm1,
                processos[i].decm1,
                processos[i].mpum1,
                processos[i].julgadom1,
                processos[i].desm1,
                processos[i].susm1
            );

            j++;
        }
    }
    
    fclose(arquivoSalvamento);

    return j;
}