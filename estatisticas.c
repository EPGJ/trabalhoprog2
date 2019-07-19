/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"estatisticas.h"
#include<stdio.h>

void pegaDadosGeracao(tEstatistica *estatisticas,int geracao,int quantidadeCelulasVivas,int quantidadeCelulasMortas){
    estatisticas->geracaoEQuantidade[geracao][0]=geracao;
    estatisticas->geracaoEQuantidade[geracao][1]=quantidadeCelulasVivas;
    estatisticas->mediaCelulasVivas+=(float)quantidadeCelulasVivas;
    
    if(geracao ==0){
        estatisticas->geracaoMaiorQtdCelulasMortas = geracao;
        estatisticas->maiorQtdCelulasMortas = quantidadeCelulasMortas;
        
        estatisticas->geracaoMaiorQtdCelulasVivas=geracao;
        estatisticas->maiorQtdCelulasVivas = quantidadeCelulasVivas;      
    }
    else{
        if(estatisticas->maiorQtdCelulasMortas<quantidadeCelulasMortas){
            estatisticas->geracaoMaiorQtdCelulasMortas = geracao;
            estatisticas->maiorQtdCelulasMortas = quantidadeCelulasMortas;
        }
        if(estatisticas->maiorQtdCelulasMortas==quantidadeCelulasMortas&&estatisticas->geracaoMaiorQtdCelulasMortas>geracao){
            estatisticas->geracaoMaiorQtdCelulasMortas = geracao;
        }
        
        if(estatisticas->maiorQtdCelulasVivas<quantidadeCelulasVivas){
            estatisticas->geracaoMaiorQtdCelulasVivas=geracao;
            estatisticas->maiorQtdCelulasVivas = quantidadeCelulasVivas;
        }
        if(estatisticas->maiorQtdCelulasVivas==quantidadeCelulasVivas&&estatisticas->geracaoMaiorQtdCelulasVivas>geracao){
            estatisticas->geracaoMaiorQtdCelulasVivas = geracao;
        }
    }
}
int maior(tEstatistica *estatisticas, int a, int b){
    int i,maiorx[2],idMaior=a;
    maiorx[0] = estatisticas->geracaoEQuantidade[a][0];
    maiorx[1] = estatisticas->geracaoEQuantidade[a][1];
    for(i=a;i<b;i++){
        if(maiorx[1]<estatisticas->geracaoEQuantidade[i][1]){
            maiorx[0] = estatisticas->geracaoEQuantidade[i][0];
            maiorx[1] = estatisticas->geracaoEQuantidade[i][1];
            idMaior = i;
        }
        if(maiorx[1]==estatisticas->geracaoEQuantidade[i][1]&&maiorx[0]>estatisticas->geracaoEQuantidade[i][0]){
            maiorx[0] = estatisticas->geracaoEQuantidade[i][0];
            maiorx[1] = estatisticas->geracaoEQuantidade[i][1];
            idMaior = i;
        }
    }
    return idMaior;
}
int ehMaior(tEstatistica *estatisticas , int a,int b){
    if(estatisticas->geracaoEQuantidade[a][1]>estatisticas->geracaoEQuantidade[b][1]){     
            return 1;       
    }
    else if(estatisticas->geracaoEQuantidade[a][1]==estatisticas->geracaoEQuantidade[b][1]&&estatisticas->geracaoEQuantidade[a][0]<estatisticas->geracaoEQuantidade[b][0]){
        return 1;
    }
    
    return 0;
}
void ordenaListaECriaArquivoDeEstatisticas(tEstatistica *estatisticas,tConfiguracao *configuracoes){
    int i,idx,idMaior,maiorx[2];
    char enderecoArquivo[1017];
    FILE * file;
    sprintf(enderecoArquivo, "%s/saida/stats.txt", configuracoes->diretorio);
    file = fopen(enderecoArquivo,"w");
    for(i=0;i<configuracoes->quantidadeGeracoes;i++){
        if(i==0){
            fprintf(file,"A media de celulas vivas ao longo das geracoes foi %.2f.\n",estatisticas->mediaCelulasVivas);
            fprintf(file,"A maior quantidade de celulas vivas foi de %d na geracao %d.\n",estatisticas->maiorQtdCelulasVivas,estatisticas->geracaoMaiorQtdCelulasVivas);
            fprintf(file,"A maior quantidade de celulas mortas foi de %d na geracao %d.\n",estatisticas->maiorQtdCelulasMortas,estatisticas->geracaoMaiorQtdCelulasMortas);
            fprintf(file,"Lista de geracoes ordenada pela quantidade de celulas vivas:\n");
        }
        idx = maior(estatisticas, i+1, configuracoes->quantidadeGeracoes);
        if(!ehMaior(estatisticas, i, idx)){
            if(i != configuracoes->quantidadeGeracoes -1){
                maiorx[0]=estatisticas->geracaoEQuantidade[i][0];
                maiorx[1]=estatisticas->geracaoEQuantidade[i][1];
                estatisticas->geracaoEQuantidade[i][0]=estatisticas->geracaoEQuantidade[idx][0];
                estatisticas->geracaoEQuantidade[i][1]=estatisticas->geracaoEQuantidade[idx][1];
                estatisticas->geracaoEQuantidade[idx][0]=maiorx[0];
                estatisticas->geracaoEQuantidade[idx][1]=maiorx[1];
            }        
        }
        fprintf(file," - Geracao %d: %d celulas\n",estatisticas->geracaoEQuantidade[i][0],estatisticas->geracaoEQuantidade[i][1]);
    }

    
    fclose(file);
}
