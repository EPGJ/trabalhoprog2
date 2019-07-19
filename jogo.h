/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   jogo.h
 * Author: elias
 *
 * Created on 20 de Junho de 2018, 14:44
 */

#ifndef JOGO_H
#define JOGO_H
#include"tabuleiro.h"
#include"still_lifes.h"
#include"estatisticas.h"
#include"configuracoes.h"

typedef struct{
    tTabuleiro tabuleiro, tabuleiroDeComparacao, ghost;
    tConfiguracao configuracoes;
    tStill_lifes still_lifes;
    tEstatistica estatisticas;
}tJogo;

void criaJogo(tJogo *jogo, char *diretorio);
void comecaJogo(tJogo *jogo);


#endif /* JOGO_H */

