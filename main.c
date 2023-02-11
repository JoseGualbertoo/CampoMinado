#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

/*teste*/

    typedef struct CampoMinado
    {
        int eBomba;
        int estaAberta;
        int vizinhos;
    }Celula;

Celula jogo[10][10];
int l,c,tam = 10;
//procedimento para inicializar a matriz jogo

void inicializarJogo(){
for(l=0; l<tam; l++){
    for(c=0;c<tam;c++){
        jogo[l][c].eBomba = 0;
        jogo[l][c].estaAberta = 0;
        jogo[l][c].vizinhos = 0;
    }
}
}

//procedimento para sortear n bombas
void sortearBombas(int n){
    int i;
    srand(time(NULL));
    for(i =1; i <n; i++){
        l = rand() % tam;
        c = rand() % tam;
        if(jogo[l][c].eBomba == 0)
            jogo[l][c].eBomba =1;
        else
            i--;
    }

}
   int main(){ 
    inicializarJogo();
    sortearBombas(10);
    return 0;
 }
