/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"jogo.h"
#include"configuracoes.h"
#include"tabuleiro.h"
#include"simulacao.h"
#include"ghost.h"
#include"still_lifes.h"
void criaJogo(tJogo *jogo, char *diretorio){  
    leConfiguracoes(&jogo->configuracoes, diretorio);
    criaTabuleiro(&jogo->tabuleiro,&jogo->configuracoes,&jogo->ghost);
    jogo->tabuleiroDeComparacao = jogo->tabuleiro; // inicia o tabuleiro de comparação com o tabuleiro construido  
}


void comecaJogo(tJogo *jogo){
    iniciaSimulacao(&jogo->tabuleiro,&jogo->configuracoes,&jogo->tabuleiroDeComparacao,&jogo->estatisticas,&jogo->still_lifes,&jogo->ghost);
    geraArquivoDeStill_lifes(&jogo->still_lifes,&jogo->configuracoes);
    geraArquivoGhost(&jogo->ghost, &jogo->configuracoes);
}

