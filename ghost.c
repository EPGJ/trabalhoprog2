/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"ghost.h"
#include<stdio.h>

void leQuantidadeLinhasEColunasGhost(tTabuleiro *ghost,int quantidadeLinhas,int quantidadeColunas){
    ghost->quantidadeLinhas=quantidadeLinhas;
    ghost->quantidadeColunas=quantidadeColunas;
}

void geraArquivoGhost(tTabuleiro *ghost,tConfiguracao *configuracoes){
    FILE *file;
    int i,j;
    char enderecoArquivo[1050];
    sprintf(enderecoArquivo,"%s/saida/ghost.txt", configuracoes->diretorio);
    file=fopen(enderecoArquivo, "w");
    for(i=0;i<quantidadeLinhasConfiguracao(configuracoes);i++){
        for(j=0;j<quantidadeColunasConfiguracao(configuracoes);j++){
            if(ghost->celula[i][j])fprintf(file,"O");
            else fprintf(file,"-");
        }
        fprintf(file,"\n");
    }
}

