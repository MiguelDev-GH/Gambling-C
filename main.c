#include "gamb.c"

//TÁ TUDO ERRADO POR ENQT MDS

int main(){

    srand(time(NULL));

    do{

        menu();

        scanf("%d",&op);

        if(op == 1 && dinheiro > preco) continue;
        else if(op == 2) preco += round(preco / 2);
        else if(op == 3) rodando = 0;

    } while(rodando);

    return 0;
}