/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   configuracoes.h
 * Author: elias
 *
 * Created on 11 de Junho de 2018, 17:55
 */

#ifndef CONFIGURACOES_H
#define CONFIGURACOES_H
#define maxQtdVivasInicialmente 2500
#define limiteGeracoes 200
#define maximaGeracao 1000
#define maxQtdTrocas 100
#define tamMaxDiretorio 1000
#define numeroMaximoGeracao 1000

typedef struct{
    int quantidadeCelulas,geracao;
    int celula[maxQtdTrocas][2];
    /*as posições do vetor coluna se referem as coordenadas da celula
     * 0° ordenada 1° abscissa.
     */
}tGeracao;


typedef struct{
    int quantidadeLinhas, quantidadeColunas, quantidadeGeracoes, quantidadeCelulasVivasInicialmente;
    int celulasVivasInicialmente[maxQtdVivasInicialmente][2]; 
/*A posição equivalente a linha, nesse caso ocupada por maxQtsVivasInicialmente correspondera a quantidade de 
* celulas vivas inicialmente a escolha do tamanho limite é para que cubra todas as possibilidades
* possiveis(todas as celulas podem estar inicialmente vivas). A posição equivalete a colunas
* adimitira duas posições, representando as coordenadas da celula.*/
    tGeracao geracao[limiteGeracoes];
    char diretorio[tamMaxDiretorio];
    int quantidadeArgumentos;
    int quantidadeGeracoesATrocar;
}tConfiguracao;

void leConfiguracoes(tConfiguracao *configuracoes, char *diretorio);
int quantidadeGeracoesATrocar(tConfiguracao *configuracoes);
void atribuiAJOValorDaAbscissaDaCelula(tConfiguracao *configuracoes,int *j,int geracao,int p,int idAbscissa);//idAbscissa = 0
void atribuiAIOValorDaOrdenadaDaCelula(tConfiguracao *configuracoes,int *i,int geracao,int p,int idOrdenada);//idOrdenada =1
int retornaGeracao(tConfiguracao *configuracoes, int i);
int quantidadeCelulasDaGeracao(tConfiguracao *configuracoes,int geracao);
int quantidadeLinhasConfiguracao(tConfiguracao *configuracoes);
int quantidadeColunasConfiguracao(tConfiguracao *configuracoes);
#endif /* CONFIGURACOES_H */
