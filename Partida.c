#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define estrutura
typedef struct
{
    char nome[256];      // nome do time;
    int partidasGanha;   // numero de partidas ganhas;
    int partidasEmpate;  // numero de partidas emmpatadas;
    int partidasDerrota; // numero de partida perdidasa;
    int pontuacao;       // total da pontuacao ;
    int saldoGols;       // saldo de gols (gols marcados - gols sofridos);
} Time;

// define estrutura
typedef struct
{
    Time *time1;   // ponteiro para o primeiro time;
    Time *time2;   // ponteiro para o segundo time;
    int golsTime1; // gols do primeiro time;
    int golsTime2; // gols do segundo time;
} Partida;

// carrega os times de um arquivo e retornar um vetor de times;
Time *carregarTimes(char *nomeArquivo, int nTimes)
{
    char linha[256];
    FILE *arqTimes;
    Time *times;
    int contTimes = 0;

    // abre o arquivo de times em modo de leitura;
    arqTimes = fopen(nomeArquivo, "rt");
    // aloca dinamicamente memoria para o vetor de times;
    times = (Time *)calloc(nTimes, sizeof(Time));

    // le o arquivo ate o final;
    while (fgets(linha, sizeof(linha), arqTimes) != NULL)
    {

        // remove a quebra de linha no final de cada linha lida;
        linha[strcspn(linha, "\n")] = '\0';

        // ignora linhas que começam com '#';
        if (linha[0] != '#')
        {
            // copia o nome do time para o vetor de times;
            strcpy(times[contTimes].nome, linha);
            contTimes += 1; // incrementa o contador de times;
        }
    }
    return times; // retorna o vetor de times carregado;
}

// busca um time pelo nome em um vetor de times;
Time *buscarTime(char *nome, int nTimes, Time *times)
{
    // percorre o vetor de times procurando pelo nome do time;
    for (int i = 0; i < nTimes; i++)
    {
        if (strcmp(times[i].nome, nome) == 0)
        {
            return &times[i]; // retorna o ponteiro para o time encontrado;
        }
    }
    return NULL; // retorna NULL caso o time não seja encontrado;
}

// carrega as partidas de um arquivo;
Partida *carregarPartidas(char *nomeArquivo, int nTimes, Time *times)
{

    char linha[256];      // variavel para armazenar cada linha lida do arquivo;
    char sTime1[256];     // nome do primeiro time;
    char sTime2[256];     // nome do segundo time;
    char sGolsTime1[256]; // gols do primeiro time como string;
    char sGolsTime2[256]; // gols do segundo time como string;

    Time *time1;   // ponteiro para o primeiro time;
    Time *time2;   // ponteiro para o segundo time;
    int golsTime1; // gols do primeiro time;
    int golsTime2; // gols do segundo time;

    FILE *arqPartidas;    // ponteiro para o arquivo de partidas;
    Partida *partidas;    // ponteiro para o vetor de partidas;
    int contPartidas = 0; // contador de partidas carregadas;

    // formula para calcular o numero total de partidas em um campeonato de todos contra todos;
    int nPartidas = (nTimes * (nTimes - 1)) / 2;
    char *token; // variavel auxiliar para dividir a linha;

    // abre o arquivo de partidas em modo de leitura;
    arqPartidas = fopen(nomeArquivo, "rt");
    // aloca dinamicamente memoria para o vetor de partidas;
    partidas = (Partida *)calloc(nPartidas, sizeof(Partida));

    // le cada linha do arquivo ate o final;
    while (fgets(linha, sizeof(linha), arqPartidas) != NULL)
    {

        // remove a quebra de linha no final de cada linha lida;
        linha[strcspn(linha, "\n")] = '\0';

        // ignora linhas que começam com '#';
        if (linha[0] != '#')
        {
            // divide a linha em tokens para extrair informacoes sobre os times e os gols;
            token = strtok(linha, " ");
            strcpy(sTime1, token); // nome do primeiro time;
            token = strtok(NULL, " ");
            strcpy(sGolsTime1, token); // gols do primeiro time;
            strtok(NULL, " ");         // ignora o "x";
            token = strtok(NULL, " ");
            strcpy(sGolsTime2, token); // gols do segundo time;
            token = strtok(NULL, " ");
            strcpy(sTime2, token); // nome do segundo time;

            // busca os times no vetor de times usando a função buscarTime;
            time1 = buscarTime(sTime1, nTimes, times);
            time2 = buscarTime(sTime2, nTimes, times);

            // converte os gols de string para inteiro;
            golsTime1 = atoi(sGolsTime1);
            golsTime2 = atoi(sGolsTime2);

            // preenche a estrutura da partida com os dados extraidos;
            partidas[contPartidas].time1 = time1;
            partidas[contPartidas].time2 = time2;
            partidas[contPartidas].golsTime1 = golsTime1;
            partidas[contPartidas].golsTime2 = golsTime2;

            contPartidas += 1; // incrementa o contador de partidas;
        }
    }

    return partidas; // retorna o vetor de partidas carregado;
}

// gera a classificacao final do campeonato;
void atualizarPontuacao(Partida *partidas, int nPartidas)
{
    for (int i = 0; i < nPartidas; i++)
    {
        int golsTime1 = partidas[i].golsTime1;
        int golsTime2 = partidas[i].golsTime2;

        // atualiza saldo de gols;
        partidas[i].time1->saldoGols += (golsTime1 - golsTime2);
        partidas[i].time2->saldoGols += (golsTime2 - golsTime1);

        // verifica o resultado da partida e atualiza a pontuacao;
        if (golsTime1 > golsTime2) // vitoria do time1;
        {
            partidas[i].time1->pontuacao += 3;
            partidas[i].time1->partidasGanha += 1;
            partidas[i].time2->partidasDerrota += 1;
        }
        else if (golsTime1 < golsTime2) // vitoria do time2;
        {
            partidas[i].time2->pontuacao += 3;
            partidas[i].time2->partidasGanha += 1;
            partidas[i].time1->partidasDerrota += 1;
        }
        else // empate;
        {
            partidas[i].time1->pontuacao += 1;
            partidas[i].time2->pontuacao += 1;
            partidas[i].time1->partidasEmpate += 1;
            partidas[i].time2->partidasEmpate += 1;
        }
    }
}

// gera a classificacao final do campeonato;
void gerarClassificacao(Time *times, int nTimes)
{
    // ordena os times pela pontuacao e, em caso de empate, pelo saldo de gols;
    for (int i = 0; i < nTimes - 1; i++)
    {
        for (int j = i + 1; j < nTimes; j++)
        {
            if (times[i].pontuacao < times[j].pontuacao || (times[i].pontuacao == times[j].pontuacao && times[i].saldoGols < times[j].saldoGols))
            {
                // troca os times de lugar;
                Time temp = times[i];
                times[i] = times[j];
                times[j] = temp;
            }
        }
    }

    // tenta abrir o arquivo de classificacao para escrita;
    FILE *arqClassificacao = fopen("classificacao.txt", "wt");
    
    if (arqClassificacao == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar a classificacao.\n");
        exit(1); // encerra o programa se não for possível abrir o arquivo;
    }

    // salva a classificacao final em um arquivo;
    for (int i = 0; i < nTimes; i++)
    {
        fprintf(arqClassificacao, "%i - %s: %i pontos, Saldo de Gols: %i\n",  i + 1, times[i].nome, times[i].pontuacao, times[i].saldoGols);
    }

    fclose(arqClassificacao); 
}
int main()
{
    int nTimes = 10;                             // numero de times no campeonato;
    int nPartidas = (nTimes * (nTimes - 1)) / 2; // numero de partidas;
    Time *times;                                 // ponteiro para o vetor de times;
    Partida *partidas;                           // ponteiro para o vetor de partidas;

    // carrega os times do arquivo "times.txt";
    times = carregarTimes("times.txt", nTimes);

    // carrega as partidas do arquivo "partidas.txt";
    partidas = carregarPartidas("partidas.txt", nTimes, times);

    // atualiza a pontuacao e o saldo de gols após cada partida;
    atualizarPontuacao(partidas, nPartidas);

    // gera a calssificacao final e salva em um arquivo "classificacao.txt";
    gerarClassificacao(times, nTimes);

    return 0;
}
