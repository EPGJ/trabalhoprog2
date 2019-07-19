/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   criaJogo.h
 * Author: elias
 *
 * Created on 8 de Junho de 2018, 17:10
 */

#ifndef TABULEIRO_H
#include"configuracoes.h"
#define TABULEIRO_H
#define tamMaxTabuleiro 2500
#define tamMaxDiretorio 1000



typedef struct{
    int quantidadeLinhas, quantidadeColunas;
    int celula[tamMaxTabuleiro][tamMaxTabuleiro]; //Adimitirá dois valores: 1 para vivo e 0 para morto
}tTabuleiro;
void mataCelulas(tTabuleiro *tabuleiro);
void ressucitaCelulasMarcadas(tTabuleiro *tabuleiro,tConfiguracao *configuracoes);
void ressucitaCelula(tTabuleiro *tabuleiro,int linha,int coluna);
void mataCelula(tTabuleiro *tabuleiro,int linha,int coluna);
int estaViva(tTabuleiro *tabuleiro, int linha,int coluna);
void iniciaTabuleiro(tTabuleiro *tabuleiro);
void criaTabuleiro(tTabuleiro *tabuleiro,tConfiguracao *configuracoes,tTabuleiro *ghost);
void imprimeTabuleiro(tTabuleiro *tabuleiro);
int quantidadeLinhas(tTabuleiro *tabuleiro);
int quantidadeColunas(tTabuleiro *tabuleiro);


#endif /* TABULEIRO_H */
