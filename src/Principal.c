#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "Pilha.h"

//movimentos: 2^nDiscos - 1

void inicializar(int ndisc, Pilha *A) {
	while(ndisc > 0) {
		empilhar(A, ndisc);
		ndisc--;	
	}
}

int iniciarJogo (Pilha *A, Pilha *B, Pilha *C) {
	int movimento, jogadas = 0;
	int discos = tamanho(A);
	bool sair = false;
	
	while(!sair) {
	    printf("Selecione uma opção para mover o disco\n\n");
	    printf(" Para A->B, digite 1\n");
	    printf(" Para A->C, digite 2\n");
	    printf(" Para B->A, digite 3\n");
	    printf(" Para B->C, digite 4\n");
	    printf(" Para C->A, digite 5\n");
	    printf(" Para C->B, digite 6\n");
	    printf("\n Digite 0 para sair\n\n");
	    scanf("%d", &movimento );
	    
	    if(movimento == 0) {
	    	sair = true;
		}
	    else if((movimento < 1) || (movimento > 6)) {
	        printf("Opção inválida!\n\n");
	    }
	    
	    switch(movimento) {
	    case 1:
	        if(tamanho(A) == 0) {
	            printf("Movimento não permitido! Torre A vazia\n");
	            break;
	        }
	        else if((topo(A) > topo(B)) && (tamanho(B) != 0)) {
	            printf("Movimento não permitido! Topo de B é menor\n");
	            break;
	        }
	        else {
	            empilhar(B, desempilhar (A));
	            imprimir(B);
	            jogadas++;
	            system("pause");
	            }
	        break;
	
	    case 2:
	        if(tamanho(A) == 0) {
	            printf("Operação não permitida! Torre A vazia\n");
	            system("pause");
	            break;
	        }
	        else if((topo(A) > topo(C))  &&   (tamanho(C) != 0)) {
	           printf("Movimento não permitido! Topo de C é menor\n");
	           system("pause");
	           break;
	        }
	        else {
	        	empilhar(C, desempilhar (A));
	        	imprimir(C);
	        	jogadas++;
	        	system("pause");
	        	break;
			}
	        
	    case 3:
	        if(tamanho(B) == 0) {
	            printf("Operação não permitida! Torre B vazia\n");
	            system("pause");
	            break;
	        }
	        else if((topo(B) > topo(A)) &&  (tamanho(A) != 0)) {
	            printf("Movimento não permitido! Topo de A é menor\n");
	            system("pause");
	            break;
	        }
	        else {
	        	empilhar(A, desempilhar (B));
	        	imprimir(A);
	        	jogadas++;
	       		system("pause");
	        	break;
			}
			
	    case 4:
	        if(tamanho(B) == 0) {
	            printf("Operação não permitida! Torre B vazia\n");
	            system("pause");
	            break;
	        }
	        else if((topo(B) > topo(C)) &&  (tamanho(C) != 0)) {
	            printf("Movimento não permitido! Topo de C é menor\n");
	            system("pause");
	            break;
	        }
	        else {
	        	empilhar(C, desempilhar (B));
	        	imprimir(C);
	        	jogadas++;
	   			system("pause");
	        	break;
			}
			
	    case 5:
	        if(tamanho(C) == 0) {
	            printf("Operação não permitida! Torre C vazia\n");
	            system("pause");
	            break;
	        }
	        else if((topo(C) > topo(A)) &&   (tamanho(A) != 0)) {
	            printf("Movimento não permitido! Topo de A é menor\n");
	            system("pause");
	            break;
	        }
	        else {
	        	empilhar(A, desempilhar (C));
	        	imprimir(A);
	        	jogadas++;
	        	system("pause");
	        	break;
			}
			
	    case 6:
	        if(tamanho(C) == 0) {
	            printf("Operação não permitida! Torre C vazia\n");
	            break;
	        }
	        else if((topo(C) > topo(B))  &&  (tamanho(B) != 0)) {
	            printf("Movimento não permitido! Topo de B é menor\n");
	            system("pause");
	            break;
	        }
	        else {
	        	empilhar(B, desempilhar (C));
	        	imprimir(B);
	        	jogadas++;
	        	system("pause");
	        	break;
			}
	    }
	    if(tamanho(C) == discos) {
			sair = true;
			printf("\nParabéns! você teminou em %d jogadas\n", jogadas);
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	Pilha * A = criar();
	Pilha * B = criar();
	Pilha * C = criar();
	
	int discos;
	
	printf("Com quantos discos voce quer jogar?\n");
	scanf("%d", &discos);
	
	if(discos <= 1) {
		printf("Quantidade de discos inválida!\n");
		return 0;
	}
		
	inicializar(discos, A);
	system("cls");
	iniciarJogo(A, B, C);	

	
	destruir(A);
	destruir(B);
	destruir(C);
	system("pause");
	return 0;
}
