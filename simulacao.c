/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"simulacao.h"
#include"still_lifes.h"
#include"estatisticas.h"
#include"tabuleiro.h"
#include"ghost.h"
#include<stdio.h>
#include<stdlib.h>

int ehGeracaoDeTroca(int geracao, tConfiguracao *configuracoes){
    int i,geracaoDeTroca;
    for(i=0;i<quantidadeGeracoesATrocar(configuracoes); i++){
        geracaoDeTroca = retornaGeracao(configuracoes, i);
        if(geracao==geracaoDeTroca) {
            return 1;
        }
        
    }
    return 0;
}

void trocaEstadoCelulasMarcadas(int geracao, tConfiguracao *configuracoes,tTabuleiro *tabuleiro,tTabuleiro *ghost){
    int p, i,j;
    for(p=0; p<quantidadeCelulasDaGeracao(configuracoes,geracao); p++){
        
        atribuiAJOValorDaAbscissaDaCelula(configuracoes,&j,geracao,p,0);
        atribuiAIOValorDaOrdenadaDaCelula(configuracoes,&i,geracao,p,1);
        
        if(estaViva(tabuleiro,i,j)){
            mataCelula(tabuleiro, i ,j);
        }
        else{
            ressucitaCelula(tabuleiro, i ,j);
            ressucitaCelula(ghost, i ,j);


        }
    }
}
int quantidadeVizinhosVivos(tTabuleiro *tabuleiro, int linha, int coluna){
    int quantidade=0;
    
    if(linha == 0){
        if(coluna==0){
            if(estaViva(tabuleiro,linha,coluna+1)) quantidade++;
            if(estaViva(tabuleiro,linha+1,coluna+1))quantidade++;
            if(estaViva(tabuleiro,linha+1,coluna))quantidade++;
        }
        else{
            if(coluna == (quantidadeColunas(tabuleiro))-1){
                if(estaViva(tabuleiro,linha,coluna-1)) quantidade++;
                if(estaViva(tabuleiro,linha+1,coluna-1))quantidade++;
                if(estaViva(tabuleiro,linha+1,coluna))quantidade++;
            }
            else{
                if(estaViva(tabuleiro,linha,coluna-1))quantidade++;
                if(estaViva(tabuleiro,linha,coluna+1))quantidade++;
                if(estaViva(tabuleiro,linha+1,coluna-1))quantidade++;
                if(estaViva(tabuleiro,linha+1,coluna+1))quantidade++;
                if(estaViva(tabuleiro,linha+1,coluna))quantidade++;
            }
        }//fim else do if(coluna==0)
    }//fim if(linha ==0)
    
    if(linha == (quantidadeLinhas(tabuleiro))-1){
        if(coluna == (quantidadeColunas(tabuleiro))-1){
            if(estaViva(tabuleiro,linha,coluna-1))quantidade++;
            if(estaViva(tabuleiro,linha-1,coluna-1))quantidade++;
            if(estaViva(tabuleiro,linha-1,coluna))quantidade++;
        }
        else{
            if(coluna == 0){
                if(estaViva(tabuleiro,linha,coluna+1))quantidade++;
                if(estaViva(tabuleiro,linha-1,coluna+1))quantidade++;
                if(estaViva(tabuleiro,linha-1,coluna))quantidade++; 
            }
            else{
                if(estaViva(tabuleiro,linha,coluna-1))quantidade++;
                if(estaViva(tabuleiro,linha,coluna+1))quantidade++;
                if(estaViva(tabuleiro,linha-1,coluna-1))quantidade++;
                if(estaViva(tabuleiro,linha-1,coluna))quantidade++;
                if(estaViva(tabuleiro,linha-1,coluna+1))quantidade++;
            }
        }//fim else do if(couna == quantidade colunas)
    }// fim if(linha==quantidade linhas)
    
    if(linha>0 && linha< (quantidadeLinhas(tabuleiro))-1){
        if(coluna == 0){
            if(estaViva(tabuleiro,linha-1,coluna))quantidade++;
            if(estaViva(tabuleiro,linha-1,coluna+1))quantidade++;
            if(estaViva(tabuleiro,linha,coluna+1))quantidade++;
            if(estaViva(tabuleiro,linha+1,coluna+1))quantidade++;
            if(estaViva(tabuleiro,linha+1,coluna))quantidade++;
        }
        if(coluna == (quantidadeColunas(tabuleiro))-1){
            if(estaViva(tabuleiro,linha-1,coluna))quantidade++;
            if(estaViva(tabuleiro,linha-1,coluna-1))quantidade++;
            if(estaViva(tabuleiro,linha,coluna-1))quantidade++;
            if(estaViva(tabuleiro,linha+1,coluna-1))quantidade++;
            if(estaViva(tabuleiro,linha+1,coluna))quantidade++;
        }
        if(coluna>0 && coluna< (quantidadeColunas(tabuleiro))-1){
            if (estaViva(tabuleiro,linha-1,coluna-1))quantidade++;
            if (estaViva(tabuleiro,linha-1,coluna))quantidade++;
            if (estaViva(tabuleiro,linha-1,coluna+1))quantidade++;
            if (estaViva(tabuleiro,linha,coluna-1))quantidade++;
            if (estaViva(tabuleiro,linha,coluna+1))quantidade++;
            if (estaViva(tabuleiro,linha+1,coluna-1))quantidade++;
            if (estaViva(tabuleiro,linha+1,coluna))quantidade++;
            if (estaViva(tabuleiro,linha+1,coluna+1))quantidade++;
        }
    }
    return quantidade;
}
    
void aplicaRegras(tTabuleiro *tabuleiro, int i,int j, tTabuleiro *tabuleiroAnterior,int quantidade,tTabuleiro *ghost){
    if(quantidade<2 && estaViva(tabuleiroAnterior,i,j)) mataCelula(tabuleiro, i ,j);
    else{
        if((quantidade == 3||quantidade==2) && estaViva(tabuleiroAnterior,i,j)){
            ressucitaCelula(tabuleiro, i ,j);
            ressucitaCelula(ghost, i ,j);
            
        }
        else{
            if(quantidade>3 && estaViva(tabuleiroAnterior,i,j)) mataCelula(tabuleiro, i ,j);
            else{
                if(quantidade==3 && !estaViva(tabuleiroAnterior,i,j)){
                    ressucitaCelula(tabuleiro, i ,j);
                    ressucitaCelula(ghost, i ,j);
                    
                }
            
            }
        }
    }
}

int quantidadeCelulasVivasNoTabuleiro(tTabuleiro *tabuleiro){
    int i,j,quantidade=0;
    for(i=0;i<quantidadeLinhas(tabuleiro);i++){
        for(j=0;j<quantidadeColunas(tabuleiro);j++){
            if(estaViva(tabuleiro,i,j))quantidade++;
        }
    }
    return quantidade;
}



void imprimeDadosDaGeracao(tTabuleiro *tabuleiro, int geracao,tEstatistica *estatisticas){
    int quantidadeCelulasVivas, quantidadeCelulasMortas;
    quantidadeCelulasVivas = quantidadeCelulasVivasNoTabuleiro(tabuleiro);
    quantidadeCelulasMortas = (quantidadeLinhas(tabuleiro)*quantidadeColunas(tabuleiro)) - quantidadeCelulasVivas;
    pegaDadosGeracao(estatisticas, geracao, quantidadeCelulasVivas, quantidadeCelulasMortas);
    printf("Geracao: %d\nN. celulas vivas: %d\nN. celulas mortas: %d\n",geracao,quantidadeCelulasVivas,quantidadeCelulasMortas);
}


void iniciaSimulacao(tTabuleiro *tabuleiro, tConfiguracao *configuracoes,tTabuleiro *tabuleiroAnterior,tEstatistica *estatisticas,tStill_lifes *still_lifes,tTabuleiro *ghost){
    int contaGeracao=0,i,j,quantidadeVizinhosV, p=0;
    estatisticas->mediaCelulasVivas=0;
    for(contaGeracao=0;contaGeracao<configuracoes->quantidadeGeracoes;contaGeracao++){
        if(ehGeracaoDeTroca(contaGeracao,configuracoes)){
            trocaEstadoCelulasMarcadas(p, configuracoes, tabuleiro,ghost);
            p++;
        }
        *tabuleiroAnterior = *tabuleiro;
        
        if(!contaGeracao){
            contaStill_lifes(tabuleiro,still_lifes,contaGeracao);
            imprimeDadosDaGeracao(tabuleiro,contaGeracao,estatisticas);
            imprimeTabuleiro(tabuleiro);
        }
        else{
           for(i=0;i<tabuleiro->quantidadeLinhas;i++){
                for(j=0;j<tabuleiro->quantidadeColunas; j++){
                    quantidadeVizinhosV = quantidadeVizinhosVivos(tabuleiroAnterior,i,j);
                    aplicaRegras(tabuleiro,i,j,tabuleiroAnterior,quantidadeVizinhosV,ghost);
                }
            }
           contaStill_lifes(tabuleiro,still_lifes,contaGeracao);
           imprimeDadosDaGeracao(tabuleiro,contaGeracao,estatisticas);
           imprimeTabuleiro(tabuleiro);
        }      
    }   
    estatisticas->mediaCelulasVivas/=contaGeracao;
    ordenaListaECriaArquivoDeEstatisticas(estatisticas,configuracoes);  
}