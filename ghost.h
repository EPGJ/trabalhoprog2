/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ghost.h
 * Author: elias
 *
 * Created on 19 de Junho de 2018, 21:55
 */

#ifndef GHOST_H
#define GHOST_H
#include"tabuleiro.h"

void ressucitaCelula(tTabuleiro *tabuleiro,int linha,int coluna);
void leQuantidadeLinhasEColunasGhost(tTabuleiro *ghost,int quantidadeLinhas,int quantidadeColunas);
void geraArquivoGhost(tTabuleiro *ghost,tConfiguracao *configuracoes);

#endif /* GHOST_H */

