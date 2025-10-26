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

int linhaVenceu(int row) {
    return (roleta[row][0] == roleta[row][1] && roleta[row][1] == roleta[row][2]);
}

int colunaVenceu(int col) {
    return (roleta[0][col] == roleta[1][col] && roleta[1][col] == roleta[2][col]);
}

int verificarPadraoEspecial(){
    if(roleta[0][1] == roleta[1][0] && roleta[1][0] == roleta[1][2] && roleta[1][2] == roleta[2][1]){
        return 1;
    }
    return 0; // Padrão não encontrado
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

    if(verificarPadraoEspecial()){
        multiplicadorDeGanho += 1;
        dinheiroAGanhar += valor4x;
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

    for(int r = 0;r<10;r++){

        LIMPAR;

        printf("-----------------------\n\n");

        printf("Custo para jogar: $ %d\n\n",preco);

        rolar();
    
        for(int i = 0;i<3;i++){ // i é a linha (row)

            printf(">       ");

            for(int j = 0;j<3;j++){ // j é a coluna (col)

                if(verificarPadraoEspecial() || linhaVenceu(i) || colunaVenceu(j)){
                    if(verificarPadraoEspecial()) {
                        printf(COR_CIANO "%d " COR_RESET, roleta[i][j]);
                    } else{
                        printf(COR_VERMELHO "%d " COR_RESET, roleta[i][j]);
                    }
                } else {
                    printf("%d ",roleta[i][j]);
                }
            }

            printf("       <");
            printf("\n");

        }

        Sleep(r*(r*5));

    }

    verificarGanhos();
    printf("$ %d\n",dinheiro);

    printf("\n1- Apostar\n");
    printf("2- Aumentar\n");
    printf("3- Sair\n");

}