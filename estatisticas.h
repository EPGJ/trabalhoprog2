/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estatisticas.h
 * Author: elias
 *
 * Created on 20 de Junho de 2018, 16:00
 */

#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H
#include"configuracoes.h"

typedef struct{
    float mediaCelulasVivas;
    int geracaoMaiorQtdCelulasVivas, maiorQtdCelulasVivas;
    int geracaoMaiorQtdCelulasMortas, maiorQtdCelulasMortas;
    int geracaoEQuantidade[numeroMaximoGeracao][2];//armazenará a geracao e a quantidade de celulas vivas
}tEstatistica;

void pegaDadosGeracao(tEstatistica *estatisticas,int geracao,int quantidadeCelulasVivas,int quantidadeCelulasMortas);
int maior(tEstatistica *estatisticas, int a, int b);
int ehMaior(tEstatistica *estatisticas , int a,int b);
void ordenaListaECriaArquivoDeEstatisticas(tEstatistica *estatisticas,tConfiguracao *configuracoes);
#endif /* ESTATISTICAS_H */

