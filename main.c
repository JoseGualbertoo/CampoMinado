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
/*
Função que diz se um par de coordenadas é válido ou não
1 - é valido
0 - não é válido
*/
int coordenadaEhValida(int l, int c){
    if(l>=0 && l<tam && c>=0 && c<tam){
        return 1;
    }else{
        return 0;
    }

}


/*
Função que retorna a quantidade de bombas na vizinhança de l e c
n - quantidade de bombas
*/
int quantBombasVizinhas(int l, int c){
    /*l-1 e c
      l+1 e c
      l e c+1
      l e c-1
    */
   int quantidade = 0;
   if(coordenadaEhValida(l-1, c) && jogo[l-1][c].eBomba){
     quantidade++;   
   }
   if(coordenadaEhValida(l+1, c) && jogo[l+1][c].eBomba){
     quantidade++;   
   }
   if(coordenadaEhValida(l, c+1) && jogo[l][c+1].eBomba){
     quantidade++;   
   }
   if(coordenadaEhValida(l, c-1) && jogo[l][c-1].eBomba){
     quantidade++;   
   }
   return quantidade;
}

//procediemnto para contar as bombas vizinhas
void contarBombas(){
    for(l=0; l<tam; l++){
        for(c=0;c<tam;c++){
            jogo[l][c].vizinhos = quantBombasVizinhas(l,c);
        }
    }
}

//procedimento para imprimir o jogo
void imprimir(){
    printf("\n\n\t    ");
    for(l = 0; l < tam; l++)
        printf(" %d  ", l);//indices da coluna
        printf("\n\t   -----------------------------------------\n");
    for(l=0; l<tam; l++){
    	printf("\t %d |",l); 
        for(c=0;c<tam;c++){
            if(jogo[l][c].estaAberta){
                if(jogo[l][c].eBomba)
                    printf(" * ");
                 else
                    printf("%d", jogo[l][c].vizinhos);
            }
            else
                printf("   ");
            printf("|");
        }
        printf("\n\t   -----------------------------------------\n");
    }
}
//procedimento para abrir a coordenada digitada pelu usuário
void abrirCelula(int l, int c){
	if(coordenadaEhValida(l,c)==1 && jogo[l][c].estaAberta == 0);
	jogo[l][c].estaAberta = 1;
	if(jogo[l][c].vizinhos == 0){
		/*
		l- e c acima
		l+ e c abaixo
		l e c+1 direita
		l e c-1 esquerda
		*/
		abrirCelula(l-1, c);
		abrirCelula(l+1, c);
		abrirCelula(l, c+1);
		abrirCelula(l, c-1); 
	}
}

//procedimento jogar que faz a leitura das coordendas
void jogar(){
	int linha, coluna;
	
	do{
		printf("\nDigite as coordendas de linha e coluna: ");
		scanf("%d%d, &linha, &coluna");
		
		if(coordenadaEhValida(linha, coluna)==)
			printf("\nCoordenada invalida!");
	}while(coordenadaEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1);
	
	abrirCelula(linha, coluna);
}

   int main(){ 
    inicializarJogo();
    sortearBombas(10);
    contarBombas();
    printf("\n\t\t\tCAMPO MINADO");
    imprimir();
    
    return 0;
 }