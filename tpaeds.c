#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1003

void ImprimeMatriz(int **MX, int m, int n) {
	int i = 0, j = 0;
	FILE *arq;

	arq = fopen("dados.txt","r");

	printf("\n");
	printf("\n");
	printf("\n");

	for(i = 0; i < n-2; i++)
		printf("___");

	for(i = 0; i < m; i++){
		printf("\n");
		printf("| ");

	for(j = 0; j < n; j++)
		if(MX[i][j] == 1)
			printf("✺ ");
		else if(MX[i][j] == 0)
			printf("  ");
		printf("|");		
	}

	printf("\n");

	for(i = 0; i < n-2; i++)
		printf("___");

	printf("\n");
	printf("\n");
	
	fclose(arq);
}

void VerificaVizinho(int **MA, int **MB, int m, int n) {
	int i = 0, j = 0, k, cont = 0;
	FILE *arq;
	arq = fopen("dados.txt", "r");

	for(i = 0; i < m; i++){		
		for(j = 0; j < n; j++)
			MB[i][j] = 0;
	}

		for(i = 0; i<m ; i++){
				cont = 0;
		    for(j = 0; j<n ; j++){
		            cont = 0;
					if((i-1)>=0){
		                    if((j-1)>=0)
		                            cont+=MA[i-1][j-1];
		            	cont+=MA[i-1][j];
		                    if((j+1)<n)
		                            cont+=MA[i-1][j+1];
		            }
		            if((i+1)<n){
		                    if((j-1)>=0)
		                            cont+=MA[i+1][j-1];
		                    cont+=MA[i+1][j];
		                    if((j+1)<n)
		                            cont+=MA[i+1][j+1];
		            }
					
		            if((j-1)>=0)
		                    cont+=MA[i][j-1];
		            if((j+1)<n)
		                    cont+=MA[i][j+1];

		            MB[i][j] = cont;
			}
		}
			for(i = 0; i<m ; i++){
				for(j = 0; j<n ; j++){
		            if(MA[i][j] == 1){	
						if(MB[i][j] > 3)
							MA[i][j] = 0;
						else if(MB[i][j] == 2)
							MA[i][j] = 1;
						else if(MB[i][j] == 3)
							MA[i][j] = 1;
						else if(MB[i][j] < 2)
							MA[i][j] = 0;
					}
					else if(MA[i][j] == 0){
						if(MB[i][j] == 3)
							MA[i][j] = 1;
						else
							MA[i][j] = 0;
					}
		    	}      
			}

	fclose(arq);
}

void GravaMatriz(int **MX, int m, int n) {
	int i = 0, j = 0;
	FILE *arq;

	arq = fopen("dados.txt", "w");

	fprintf(arq, "%d,%d\n", m, n);

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++)
			fprintf(arq,"%d ", MX[i][j]);
		fprintf(arq,"\n");
	}

	fclose(arq);
}


int main() {
	int i = 0, j = 0, k, **MA, **MB, m, n;
	char op = '?';
	FILE *arq;
	
	printf("\n");
	printf("\t\t #### JOGO DA VIDA ####\n\n");
	printf("\tO Jogo da Vida foi criado pelo matematico britanico\n");
	printf("\tJohn Horton Conway em 1970.\n");
	printf("\tO objetivo do jogo eh reproduzir, atraves de regras simples,\n");
	printf("\tas alteracoes e mudancas em grupos de seres vivos.\n");
	printf("\tA primeira geracao de celulas ira ser mostrada a seguir : \n");

	arq = fopen("dados.txt","r");
	if (arq == NULL) {
		printf("Erro ao abrir o arquivo de dados\n");
		return 1;
	}

	fscanf(arq, "%d,%d\n", &m, &n);

	MA = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < m; i++)
		MA[i] = (int*)malloc(n*sizeof(int));

	MB = (int**)malloc(m*sizeof(int*));
	for (j = 0; j < m; j++)
		MB[j] = (int*)malloc(n*sizeof(int));

	for(i = 0; i < m; i++){		
		for(j = 0; j < n; j++)
			fscanf(arq,"%d ", &MA[i][j]);
	}

	ImprimeMatriz(MA,m,n);
		
	printf("Deseja imprimir a proxima geracao? <S> ou <N> : ");
			
	while(op != 'N') 	{
		scanf("%c", &op);
		op = toupper(op);

		if(op == 'N'){
			GravaMatriz(MA,m,n);
			printf("\n\t#### Jogo encerrado! ####\n\n");
			break;
		}
	
		else if(op == 'S'){
			VerificaVizinho(MA,MB,m,n);
			ImprimeMatriz(MA,m,n);
			GravaMatriz(MA,m,n);
			printf("\n");
			printf("Deseja imprimir a proxima geracao? <S> ou <N> : ");
		}	
	}
	
	fclose(arq);
	for(i = 0; i < m; i++)
		free(MA[i]);
	free(MA);
	for(i = 0; i < m; i++)
		free(MB[i]);
	free(MB);
		
	return 0;
}