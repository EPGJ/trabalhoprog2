/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   simulacao.h
 * Author: elias
 *
 * Created on 12 de Junho de 2018, 18:17
 */

#ifndef SIMULACAO_H
#define SIMULACAO_H
#include"tabuleiro.h"
#include"still_lifes.h"
#include"estatisticas.h"
int ehGeracaoDeTroca(int geracao, tConfiguracao *configuracoes);
int quantidadeVizinhosVivos(tTabuleiro *tabuleiro, int linha, int coluna);
void aplicaRegras(tTabuleiro *tabuleiro, int linha,int coluna,tTabuleiro *tabuleiroAnterior,int quantidade,tTabuleiro *ghost);
void trocaEstadoCelulasMarcadas(int geracao, tConfiguracao *configuracoes, tTabuleiro *tabuleiro,tTabuleiro *ghost);
int quantidadeCelulasVivasNoTabuleiro(tTabuleiro *tabuleiro);
void pegaDadosGeracao(tEstatistica *estatisticas,int geracao,int quantidadeCelulasVivas,int quantidadeCelulasMortas);
void imprimeDadosDaGeracao(tTabuleiro *tabuleiro, int geracao,tEstatistica *estatisticas);
int maior(tEstatistica *estatisticas, int a, int b);
int ehMaior(tEstatistica *estatisiticas , int a,int b);
void ordenaListaECriaArquivoDeEstatisticas(tEstatistica *estatisticas,tConfiguracao *configuracoes);
void iniciaSimulacao(tTabuleiro *tabuleiro, tConfiguracao *configuracoes, tTabuleiro *tabuleiroAnterior,tEstatistica *estatisticas,tStill_lifes *still_lifes,tTabuleiro *ghost);



#endif /* SIMULACAO_H */
