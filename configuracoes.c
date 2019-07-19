/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "configuracoes.h"
#include<stdio.h>
#include<stdlib.h>
#define tamMaxTabuleiro 2500
#define tamMaxDiretorio 1000

void leConfiguracoes(tConfiguracao *configuracoes, char *diretorio){
    FILE *file;
    char enderecoArquivo[1013], texto[1000];
    int contador=0, i=0,p, contadorGeracoes=0;   
    
    sprintf(enderecoArquivo, "%s/config.txt", diretorio);
    
    file = fopen(enderecoArquivo, "r");
    if(file == NULL){
        printf("\nNao foi possivel abrir o arquivo no endereco: '%s'\nVerifique se o endereco foi digitado corretamente e tente novamente\n\n", enderecoArquivo);
        exit(0);
    }
    sscanf(diretorio,"%s",configuracoes->diretorio);
    while(!feof(file)){
        contador++;
        fscanf(file, "%[^ \n]", texto);
        fscanf(file,"%*c");     
        
        if(contador == 1){
            sscanf(texto, "shape=%d,%d", &configuracoes->quantidadeColunas, &configuracoes->quantidadeLinhas);
        }
        
        if(contador == 2){
            sscanf(texto,"max_gen=%d", &configuracoes->quantidadeGeracoes);
        }
        i=0;
        if(contador == 3){
            i++;
            if(i == 1){
                fscanf(file, "%[^ \n]", texto); // retira o "start:" lendo a quantidade de celulas vivas inicialmente 
                fscanf(file,"%*c");
                sscanf(texto, "%d", &configuracoes->quantidadeCelulasVivasInicialmente);
            }
            for(p=0; p < configuracoes->quantidadeCelulasVivasInicialmente; p++){
                fscanf(file,"%[^ \n]", texto);
                fscanf(file,"%*c");               
                sscanf(texto,"%d,%d", &configuracoes->celulasVivasInicialmente[p][0],&configuracoes->celulasVivasInicialmente[p][1]);
            }

        }
        i =0;
        if(contador>3){
            if(feof(file)) break; 

            for(p=1;p<=2;p++){
                if(p==1){
                    fscanf(file, "%[^ ]", texto);
                    fscanf(file, "%*c");
                    sscanf(texto, "%d:", &configuracoes->geracao[contadorGeracoes].geracao);
                }
                if(p==2){
                    fscanf(file,"%[^ \n]", texto);
                    fscanf(file, "%*c");                  
                    sscanf(texto, "%d", &configuracoes->geracao[contadorGeracoes].quantidadeCelulas);
                }
            }
                for(p=0;p<configuracoes->geracao[contadorGeracoes].quantidadeCelulas; p++){                
                fscanf(file,"%[^ \n]", texto);
                fscanf(file, "%*c");               
                sscanf(texto, "%d,%d", &configuracoes->geracao[contadorGeracoes].celula[p][0],&configuracoes->geracao[contadorGeracoes].celula[p][1]);
                }
                contadorGeracoes++;
            }      
        }
    configuracoes->quantidadeGeracoesATrocar = contadorGeracoes;
    fclose(file);    
    }

int quantidadeGeracoesATrocar(tConfiguracao *configuracoes){
    return configuracoes->quantidadeGeracoesATrocar;
}
void atribuiAJOValorDaAbscissaDaCelula(tConfiguracao *configuracoes,int *j,int geracao,int p,int idAbscissa){
    *j = configuracoes->geracao[geracao].celula[p][0];
}
void atribuiAIOValorDaOrdenadaDaCelula(tConfiguracao *configuracoes,int *i,int geracao,int p,int idOrdenada){
    *i = configuracoes->geracao[geracao].celula[p][1];
}
int quantidadeCelulasDaGeracao(tConfiguracao *configuracoes,int geracao){
    return configuracoes->geracao[geracao].quantidadeCelulas;
}
int retornaGeracao(tConfiguracao *configuracoes, int i){
    return configuracoes->geracao[i].geracao;
}
int quantidadeLinhasConfiguracao(tConfiguracao *configuracoes){
    return configuracoes->quantidadeLinhas;
}
int quantidadeColunasConfiguracao(tConfiguracao *configuracoes){
    return configuracoes->quantidadeColunas;
}
                                                                               



