/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"tabuleiro.h"
#include"ghost.h"
#include<stdio.h>
#include<stdlib.h>
#define tamMaxTabuleiro 2500
#define tamMaxDiretorio 1000

void mataCelulas(tTabuleiro *tabuleiro){
    int i, j;
    for(i=0;i<tabuleiro->quantidadeLinhas;i++){
        for(j=0;j<tabuleiro->quantidadeColunas;j++){
            tabuleiro->celula[i][j]=0;
        }
    }
}
void ressucitaCelulasMarcadas(tTabuleiro *tabuleiro,tConfiguracao *configuracoes){
    int p, i,j;
    for(p=0; p < configuracoes->quantidadeCelulasVivasInicialmente; p++){
        j = configuracoes->celulasVivasInicialmente[p][0];// pega coluna
        i = configuracoes->celulasVivasInicialmente[p][1];// pega linha
        tabuleiro->celula[i][j]=1;
    }
}
void ressucitaCelula(tTabuleiro *tabuleiro,int linha,int coluna){
    tabuleiro->celula[linha][coluna]=1;
}
void mataCelula(tTabuleiro *tabuleiro,int linha,int coluna){
    tabuleiro->celula[linha][coluna]=0;
}
int estaViva(tTabuleiro *tabuleiro,int linha,int coluna){
    return tabuleiro->celula[linha][coluna];
}
int quantidadeLinhas(tTabuleiro *tabuleiro){
    return tabuleiro->quantidadeLinhas;
}
int quantidadeColunas(tTabuleiro *tabuleiro){
    return tabuleiro->quantidadeColunas;
}

void criaTabuleiro(tTabuleiro *tabuleiro,tConfiguracao *configuracoes,tTabuleiro *ghost){
    tabuleiro->quantidadeColunas = configuracoes->quantidadeColunas;
    tabuleiro->quantidadeLinhas = configuracoes->quantidadeLinhas;
    
    leQuantidadeLinhasEColunasGhost(ghost,configuracoes->quantidadeLinhas,configuracoes->quantidadeColunas);
   
    mataCelulas(tabuleiro);
    mataCelulas(ghost);
    
    ressucitaCelulasMarcadas(tabuleiro,configuracoes);
    ressucitaCelulasMarcadas(ghost,configuracoes);
    
}
void imprimeTabuleiro(tTabuleiro *tabuleiro){   
    int i, j;
    for(i=0;i<tabuleiro->quantidadeLinhas;i++){
        for(j=0;j<tabuleiro->quantidadeColunas;j++){
            if(tabuleiro->celula[i][j]==0) printf("-");
            else printf("O");
        }
        printf("\n");
    }   
}

