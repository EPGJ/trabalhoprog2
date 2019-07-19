/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"tabuleiro.h"
#include"estatisticas.h"
#include<stdio.h>
#include"still_lifes.h"
void contaStill_lifes(tTabuleiro *tabuleiro,tStill_lifes *still_lifes, int contaGeracao){
    int i,j,permissaoBlock, contadorBlock=0,permissaoBeehive,permissaoLoaf,permissaoBoat, permissaoTub;   
    int contadorBeehive=0, contadorLoaf=0, contadorBoat=0,contadorTub=0;
    for(i=0;i<quantidadeLinhas(tabuleiro);i++){
        for(j=0;j<quantidadeColunas(tabuleiro);j++){
            permissaoBlock=0; permissaoBeehive=0;permissaoLoaf=0; permissaoBoat=0;permissaoTub=0;
//        verifica se é block.    
          if(i<=quantidadeLinhas(tabuleiro)-4 && j<=quantidadeColunas(tabuleiro)-4){
//              verifica primeira linha
              if(!estaViva(tabuleiro,i,j)) permissaoBlock++;
              if(!estaViva(tabuleiro,i,j+1)) permissaoBlock++;
              if(!estaViva(tabuleiro,i,j+2)) permissaoBlock++;
              if(!estaViva(tabuleiro,i,j+3)) permissaoBlock++;
//              verifica segunda linha
              if(!estaViva(tabuleiro,i+1,j)) permissaoBlock++;
              if(estaViva(tabuleiro,i+1,j+1)) permissaoBlock++;
              if(estaViva(tabuleiro,i+1,j+2)) permissaoBlock++;
              if(!estaViva(tabuleiro,i+1,j+3)) permissaoBlock++;
//              verifica terceira linha
              if(!estaViva(tabuleiro,i+2,j)) permissaoBlock++;
              if(estaViva(tabuleiro,i+2,j+1)) permissaoBlock++;
              if(estaViva(tabuleiro,i+2,j+2)) permissaoBlock++;
              if(!estaViva(tabuleiro,i+2,j+3)) permissaoBlock++;
//              verifica quarta linha
              if(!estaViva(tabuleiro,i+3,j)) permissaoBlock++;
              if(!estaViva(tabuleiro,i+3,j+1)) permissaoBlock++;
              if(!estaViva(tabuleiro,i+3,j+2)) permissaoBlock++;
              if(!estaViva(tabuleiro,i+3,j+3)) permissaoBlock++;
              if(permissaoBlock == 16) {
                  contadorBlock++;
              }
          } 
//          verifica se é beehive.
          if(i<=quantidadeLinhas(tabuleiro)-5 && j<=quantidadeColunas(tabuleiro)-6){
//              verifica primeira linha.
              if(!estaViva(tabuleiro,i,j)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i,j+1)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i,j+2)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i,j+3)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i,j+4)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i,j+5)) permissaoBeehive++;
//              verifica segunda linha
              if(!estaViva(tabuleiro,i+1,j)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+1,j+1)) permissaoBeehive++;
              if(estaViva(tabuleiro,i+1,j+2)) permissaoBeehive++;
              if(estaViva(tabuleiro,i+1,j+3)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+1,j+4)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+1,j+5)) permissaoBeehive++;
//              verifica terceira linha
              if(!estaViva(tabuleiro,i+2,j)) permissaoBeehive++;
              if(estaViva(tabuleiro,i+2,j+1)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+2,j+2)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+2,j+3)) permissaoBeehive++;
              if(estaViva(tabuleiro,i+2,j+4)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+2,j+5)) permissaoBeehive++;
//              verifica quarta linha.
              if(!estaViva(tabuleiro,i+3,j)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+3,j+1)) permissaoBeehive++;
              if(estaViva(tabuleiro,i+3,j+2)) permissaoBeehive++;
              if(estaViva(tabuleiro,i+3,j+3)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+3,j+4)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+3,j+5)) permissaoBeehive++;
//              verifica quinta linha.
              if(!estaViva(tabuleiro,i+5,j)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+5,j+1)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+5,j+2)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+5,j+3)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+5,j+4)) permissaoBeehive++;
              if(!estaViva(tabuleiro,i+5,j+5)) permissaoBeehive++;
              
              if(permissaoBeehive == 30) contadorBeehive++;
          }
//          verifica se é loaf
          if(i<=tabuleiro->quantidadeLinhas-6 && j<=tabuleiro->quantidadeColunas-6){
//              verifica a primeira linha
              if(!estaViva(tabuleiro,i,j)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i,j+1)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i,j+2)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i,j+3)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i,j+4)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i,j+5)) permissaoLoaf++;
//              verifica a segunda linha
              if(!estaViva(tabuleiro,i+1,j)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+1,j+1)) permissaoLoaf++;
              if(estaViva(tabuleiro,i+1,j+2)) permissaoLoaf++;
              if(estaViva(tabuleiro,i+1,j+3)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+1,j+4)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+1,j+5)) permissaoLoaf++;
//              verifica a terceira linha
              if(!estaViva(tabuleiro,i+2,j)) permissaoLoaf++;
              if(estaViva(tabuleiro,i+2,j+1)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+2,j+2)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+2,j+3)) permissaoLoaf++;
              if(estaViva(tabuleiro,i+2,j+4)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+2,j+5)) permissaoLoaf++;
//              verifica a quarta linha.
              if(!estaViva(tabuleiro,i+3,j)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+3,j+1)) permissaoLoaf++;
              if(estaViva(tabuleiro,i+3,j+2)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+3,j+3)) permissaoLoaf++;
              if(estaViva(tabuleiro,i+3,j+4)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+3,j+5)) permissaoLoaf++;
//              verifica a quinta linha.
              if(!estaViva(tabuleiro,i+4,j)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+4,j+1)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+4,j+2)) permissaoLoaf++;
              if(estaViva(tabuleiro,i+4,j+3)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+4,j+4)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+4,j+5)) permissaoLoaf++;
//              verifica a sexta linha.
              if(!estaViva(tabuleiro,i+5,j)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+5,j+1)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+5,j+2)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+5,j+3)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+5,j+4)) permissaoLoaf++;
              if(!estaViva(tabuleiro,i+5,j+5)) permissaoLoaf++;
              
              if(permissaoLoaf == 36){
                  contadorLoaf++;  
              }
          }
//          verifica se é boat ou tub
          if(i<=tabuleiro->quantidadeLinhas-5 && j<=tabuleiro->quantidadeColunas-5){
//              verifica se é boat
//              verifica a primeira linha.
              if(!estaViva(tabuleiro,i,j)) permissaoBoat++;
              if(!estaViva(tabuleiro,i,j+1)) permissaoBoat++;
              if(!estaViva(tabuleiro,i,j+2)) permissaoBoat++;
              if(!estaViva(tabuleiro,i,j+3)) permissaoBoat++;
              if(!estaViva(tabuleiro,i,j+4)) permissaoBoat++;
//              verifica a segunda linha.
              if(!tabuleiro->celula[i+1][j])permissaoBoat++;
              if(tabuleiro->celula[i+1][j+1])permissaoBoat++;
              if(tabuleiro->celula[i+1][j+2])permissaoBoat++;
              if(!tabuleiro->celula[i+1][j+3])permissaoBoat++;
              if(!tabuleiro->celula[i+1][j+4])permissaoBoat++;
//              verifica a terceira linha.
              if(!estaViva(tabuleiro,i+2,j)) permissaoBoat++;
              if(estaViva(tabuleiro,i+2,j+1)) permissaoBoat++;
              if(!estaViva(tabuleiro,i+2,j+2)) permissaoBoat++;
              if(estaViva(tabuleiro,i+2,j+3)) permissaoBoat++;
              if(!estaViva(tabuleiro,i+2,j+4)) permissaoBoat++;
//              verifica a quarta linha.
              if(!estaViva(tabuleiro,i+3,j)) permissaoBoat++;
              if(!estaViva(tabuleiro,i+3,j+1)) permissaoBoat++;
              if(estaViva(tabuleiro,i+3,j+2)) permissaoBoat++;
              if(!estaViva(tabuleiro,i+3,j+3)) permissaoBoat++;
              if(!estaViva(tabuleiro,i+3,j+4)) permissaoBoat++;
//              verifica a quinta linha.
              if(!estaViva(tabuleiro,i+4,j)) permissaoBoat++;
              if(!estaViva(tabuleiro,i+4,j+1)) permissaoBoat++;
              if(!estaViva(tabuleiro,i+4,j+2)) permissaoBoat++;
              if(!estaViva(tabuleiro,i+4,j+3)) permissaoBoat++;
              if(!estaViva(tabuleiro,i+4,j+4)) permissaoBoat++;
              
              if(permissaoBoat == 25) contadorBoat++;
              
              
//              verifica se é Tub.
//              verifica a primeira linha.
              if(!estaViva(tabuleiro,i,j)) permissaoTub++;
              if(!estaViva(tabuleiro,i,j+1)) permissaoTub++;
              if(!estaViva(tabuleiro,i,j+2)) permissaoTub++;
              if(!estaViva(tabuleiro,i,j+3)) permissaoTub++;
              if(!estaViva(tabuleiro,i,j+4)) permissaoTub++;
//              verifica a segunda linha.
              if(!estaViva(tabuleiro,i+1,j)) permissaoTub++;
              if(!estaViva(tabuleiro,i+1,j+1)) permissaoTub++;
              if(estaViva(tabuleiro,i+1,j+2)) permissaoTub++;
              if(!estaViva(tabuleiro,i+1,j+3)) permissaoTub++;
              if(!estaViva(tabuleiro,i+1,j+4)) permissaoTub++;
//              verifica a terceira linha.
              if(!estaViva(tabuleiro,i+2,j)) permissaoTub++;
              if(estaViva(tabuleiro,i+2,j+1)) permissaoTub++;
              if(!estaViva(tabuleiro,i+2,j+2)) permissaoTub++;
              if(estaViva(tabuleiro,i+2,j+3)) permissaoTub++;
              if(!estaViva(tabuleiro,i+2,j+4)) permissaoTub++;
//              verifica a quarta linha.
              if(!estaViva(tabuleiro,i+3,j)) permissaoTub++;
              if(!estaViva(tabuleiro,i+3,j+1)) permissaoTub++;
              if(estaViva(tabuleiro,i+3,j+2)) permissaoTub++;
              if(!estaViva(tabuleiro,i+3,j+3)) permissaoTub++;
              if(!estaViva(tabuleiro,i+3,j+4)) permissaoTub++;
//              verifica a quinta linha.
              if(!estaViva(tabuleiro,i+4,j)) permissaoTub++;
              if(!estaViva(tabuleiro,i+4,j+1)) permissaoTub++;
              if(!estaViva(tabuleiro,i+4,j+2)) permissaoTub++;
              if(!estaViva(tabuleiro,i+4,j+3)) permissaoTub++;
              if(!estaViva(tabuleiro,i+4,j+4)) permissaoTub++;

              if(permissaoTub == 25) contadorTub++;
             
          }
            
            
        }
    }
    if(contaGeracao == 0){
        still_lifes->quantidadeETipo[0][0] = 0;
        still_lifes->quantidadeETipo[0][1] = contadorBeehive;
        
        still_lifes->quantidadeETipo[1][0] = 1;
        still_lifes->quantidadeETipo[1][1] = contadorBlock;
        
        still_lifes->quantidadeETipo[2][0] = 2;
        still_lifes->quantidadeETipo[2][1] = contadorBoat;
        
        still_lifes->quantidadeETipo[3][0] = 3;
        still_lifes->quantidadeETipo[3][1] = contadorLoaf;
        
        still_lifes->quantidadeETipo[4][0] = 4;
        still_lifes->quantidadeETipo[4][1] = contadorTub;

    }
    else{
        still_lifes->quantidadeETipo[0][0] = 0;
        still_lifes->quantidadeETipo[0][1] += contadorBeehive;
        
        still_lifes->quantidadeETipo[1][0] = 1;
        still_lifes->quantidadeETipo[1][1] += contadorBlock;
        
        still_lifes->quantidadeETipo[2][0] = 2;
        still_lifes->quantidadeETipo[2][1] += contadorBoat;
        
        still_lifes->quantidadeETipo[3][0] = 3;
        still_lifes->quantidadeETipo[3][1] += contadorLoaf;
        
        still_lifes->quantidadeETipo[4][0] = 4;
        still_lifes->quantidadeETipo[4][1] += contadorTub;
    }
}

int maiorStill_life(tStill_lifes *still_lifes, int a){
    int i,maiorx[2],idMaior=a;
    maiorx[0]= still_lifes->quantidadeETipo[a][0];
    maiorx[1]= still_lifes->quantidadeETipo[a][1];
    for(i=a;i<qtdStill_lifes;i++){
        if(maiorx[1]<still_lifes->quantidadeETipo[i][1]){
            maiorx[0]=still_lifes->quantidadeETipo[i][0];
            maiorx[1]=still_lifes->quantidadeETipo[i][1]; 
            idMaior = i;
        }
        if(maiorx[1]==still_lifes->quantidadeETipo[i][1]&&maiorx[0]>still_lifes->quantidadeETipo[i][0]){
            maiorx[0]=still_lifes->quantidadeETipo[i][0];
            maiorx[1]=still_lifes->quantidadeETipo[i][1];             
            idMaior = i;
        }
    }
    return idMaior;
}
int ehMaiorStill_life(tStill_lifes *still_lifes, int a,int b){
    if(still_lifes->quantidadeETipo[a][1]>still_lifes->quantidadeETipo[b][1]){
        return 1;
    }
    if(still_lifes->quantidadeETipo[a][1]==still_lifes->quantidadeETipo[b][1]&&still_lifes->quantidadeETipo[a][0]<still_lifes->quantidadeETipo[b][0]){
        return 1;
    }
    return 0;
}

void geraArquivoDeStill_lifes(tStill_lifes *still_lifes, tConfiguracao *configuracoes){
    FILE *file;
    char enderecoArquivo[1023];
    sprintf(enderecoArquivo, "%s/saida/still_lifes.txt", configuracoes->diretorio);
    file = fopen(enderecoArquivo,"w");
    
    
    int i, maiorx[2],idx;
    char  linha[20];
    maiorx[0] = still_lifes->quantidadeETipo[0][0];
    maiorx[1] = still_lifes->quantidadeETipo[0][1];
    for(i=0;i<qtdStill_lifes;i++){

        idx = maiorStill_life(still_lifes,i+1);
        
        if(!ehMaiorStill_life(still_lifes,i,idx)){
            if(i!=qtdStill_lifes-1){
                maiorx[0]= still_lifes->quantidadeETipo[i][0];
                maiorx[1]= still_lifes->quantidadeETipo[i][1];

                still_lifes->quantidadeETipo[i][0] = still_lifes->quantidadeETipo[idx][0];
                still_lifes->quantidadeETipo[i][1] = still_lifes->quantidadeETipo[idx][1];

                still_lifes->quantidadeETipo[idx][0] = maiorx[0];
                still_lifes->quantidadeETipo[idx][1] = maiorx[1];  
            }
        }
        else{

        }
        switch(still_lifes->quantidadeETipo[i][0]){
            case 0:
                sprintf(linha, " - Beehive: %d",still_lifes->quantidadeETipo[i][1]);              
            break;
            
            case 1:
                sprintf(linha, " - Block: %d",still_lifes->quantidadeETipo[i][1]);
            break;
            
            case 2:
                sprintf(linha, " - Boat: %d",still_lifes->quantidadeETipo[i][1]);
            break;
            case 3:
                sprintf(linha, " - Loaf: %d",still_lifes->quantidadeETipo[i][1]);
            break;
            
            case 4:
                sprintf(linha, " - Tub: %d",still_lifes->quantidadeETipo[i][1]);
            break;            
        }
        fprintf(file, "%s\n", linha);
    }
    
    fclose(file);
}

