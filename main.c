#include "gamb.c"

int main(){

    srand(time(NULL));

    do{

        roleta[0][0] = 1;
        roleta[0][1] = 1;
        roleta[0][2] = 1;

        roleta[1][0] = 2;
        roleta[1][1] = 2;
        roleta[1][2] = 2;

        roleta[2][0] = 2;
        roleta[2][1] = 2;
        roleta[2][2] = 2;

        menu();

        scanf("%d",&op);

        if(op == 1 && dinheiro > preco) continue;
        else if(op == 2) preco += round(preco / 2);
        else if(op == 3) rodando = 0;

        

    } while(rodando);

    return 0;
}