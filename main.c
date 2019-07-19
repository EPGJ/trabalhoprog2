/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: elias
 *
 * Created on 8 de Junho de 2018, 16:02
 */
#include"jogo.h"
#include"tabuleiro.h"
#include"configuracoes.h"
#include"simulacao.h"
#include"still_lifes.h"
#include <stdio.h>


tJogo jogo;
int main(int argc, char** argv) {
    char diretorio[tamMaxDiretorio];
    
    if(argc<=1){
        printf("ERRO! O diretorio de arquivos de configuracao nao foi informado!\n");
        return 0;
    }
    
    sscanf(argv[1], "%s", diretorio);
    criaJogo(&jogo,diretorio);
    comecaJogo(&jogo);
    
    return 0;
}
