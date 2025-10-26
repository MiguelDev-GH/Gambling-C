#include "gamb.h"

void rolar(){
    int random;
    
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            random = rand() % chanceQntd;
            roleta[i][j] = chances[random];
        }
    }


}

void verificarGanhos(){

    multiplicadorDeGanho = 1;
    dinheiroAGanhar = 0;

    for(int i = 0;i < 3;i++){
        if(roleta[i][0] == roleta[i][1] && roleta[i][1] == roleta[i][2]){
            multiplicadorDeGanho += 0.5;
            dinheiroAGanhar += valor3x;
        } 

        if(roleta[0][i] == roleta[1][i] && roleta[1][i] == roleta[2][i]){
            multiplicadorDeGanho += 0.5;
            dinheiroAGanhar += valor3x;
        } 
    }

    dinheiro += ceil(multiplicadorDeGanho) * dinheiroAGanhar;
    
    if(multiplicadorDeGanho != 1){
        printf("\nGanho: %d\n",dinheiroAGanhar);
        printf("Multiplicador: %.2fx\n",multiplicadorDeGanho);
        printf("Total: %.0f\n",ceil(multiplicadorDeGanho) * dinheiroAGanhar);
    }

    printf("\n");

}

void menu(){

    LIMPAR;

    rolar();

    printf("-----------------------\n\n");

    printf("Custo para jogar: $ %d\n",preco);
    
    for(int i = 0;i<3;i++){

        printf(">       ");

        for(int j = 0;j<3;j++){
            printf("%d ",roleta[i][j]);
        }

        printf("       <");

            printf("\n");
    }

    verificarGanhos();
    printf("$ %d\n",dinheiro);

    printf("\n1- Apostar\n");
    printf("2- Aumentar\n");
    printf("3- Sair\n");

}