/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   still_lifes.h
 * Author: elias
 *
 * Created on 18 de Junho de 2018, 20:04
 */

#ifndef STILL_LIFES_H
#define STILL_LIFES_H
#define qtdStill_lifes 5

typedef struct{
    int quantidadeETipo[qtdStill_lifes][2]; // a posição 0 vai pegar o tipo e a posicao 1 vai pegar a quantidade
}tStill_lifes;
void contaStill_lifes(tTabuleiro *tabuleiro,tStill_lifes *still_lifes,int contaGeracao);
int maiorStill_life(tStill_lifes *still_lifes, int a);
int ehMaiorStill_life(tStill_lifes *still_lifes, int a,int b);
void geraArquivoDeStill_lifes(tStill_lifes *still_lifes,tConfiguracao *configuracoes);
#endif /* STILL_LIFES_H */

