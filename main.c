#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "processo.h"

//10 quantidade de processos dentro do arquivo "TJDFT_amostra"
//1048576 quantidade de processos dentro do arquivo "TJDFT_filtrado"
// 2529658 no filtrado


int main() {
    // Variáveis 
    char linha[1024];
    char cabecalho[1000];
    int i = 0;
    
    // Abertura do arquivo CSV 
    FILE *arquivo;
    arquivo = fopen("TJDFT_filtrado.csv", "r");
    
    // Teste de falha de abertura
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    
    // Conta o tanto de processos
    int totalProcessos = contarProcessos(arquivo);
    printf("O arquivo possui %d processos.\n", totalProcessos);

    // Cria vetor para guardar os processos
    Processo *processos = malloc(sizeof(Processo) * totalProcessos);

    // Lê e ignora o cabeçalho
    fgets(cabecalho, sizeof(cabecalho), arquivo);
    

    // Lê a linha inteira do processo e salva o processo em um vetor
    while (fgets(linha, sizeof(linha), arquivo) && i <= totalProcessos) {
        linha[strcspn(linha, "\n")] = 0;  // remove o \n 
        processos[i] = lerProcesso(linha); // salva o processo em um vetor
        i++;
    }

    // o id_ultimo_oj a partir de id_processo
    int id = 323961078; // id_processo de exemplo
    int ultimoOrgao = buscarUltimoOj(processos, totalProcessos, id);
    printf("Ultimo orgao julgador do id %d: %d\n", id, ultimoOrgao);

    // o id_processo do processo com dt_recebimento mais antigo
    int total_processos = i; // i é o número de processos lidos
    int id_antigo = processoMaisAntigo(processos, total_processos);
    printf("O processo com dt_recebimento mais antigo tem id_processo = %d\n", id_antigo);

    
    printf("Violencia Domestica: %d\n", contarViolenciaDomestica(processos, i)); // quantos processos estão relacionadas a causas de violência doméstica
    printf("Feminicidio: %d\n", contarFeminicidio(processos, i)); // quantos processos estão relacionadas a causas de feminicídio
    printf("Ambiental: %d\n", contarAmbiental(processos, i)); //  quantos processos estão relacionadas a causas ambientais
    printf("Quilombolas: %d\n", contarQuilombolas(processos, i)); // quantos processos estão relacionadas a causas de quilombolas
    printf("Indigenas: %d\n", contarIndigenas(processos, i)); // quantos processos estão relacionadas a causas indígenas
    printf("Infancia e Juventude: %d\n", contarInfancia(processos, i)); // quantos processos envolve causas relacionadas a infância e juventude

    // o número de dias entre dt_recebimento e dt_resolvido
    int diasEntre = DiasEntreDatas(processos, totalProcessos, id);
    printf("Dias entre datas do processo: %d\n", diasEntre);

    // o percentual de cumprimento da meta 1
    double meta1;
    meta1 = Meta1(processos, total_processos);
    printf("Porcentagem de cumprimento da meta1 do tribunal: %.2lf%%\n", meta1);


    // gerar um arquivo CSV com todos os processos julgados (mérito) na Meta 1
    int contador;
    contador = ExportarProcessosJulgado(processos, total_processos, "Processos_julgados.csv");
    if (contador == 0) {
        printf("Nenhum arquivo foi julgado!");
    } else {
        printf("total de arquivos julgados(Merito) e salvos no arquivo csv: %d", contador);
    }

    free(processos);

    return 0;
}