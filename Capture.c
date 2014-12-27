MAI
===
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int form[1000][1000];
int a,b,c,d,i,j;
char *args[100];

void exclusion(int argc);
void assig();
void desig();
void settick(int vpr, int otv);
void present();

int main(int argc, char *argv[]){
	int k;
	
	for (k=1;k<argc-1;k++)
		args[k]=argv[k];
		
	exclusion(argc);
	assig();
	desig();
	for (k=5;k<argc;k++)
		settick(k-4,atoi(argv[k]));
	present();
}

void exclusion(int argc){
	if (argc == 1) {
		printf("\nПравило заполнения аргументов: (ширина ячейки) (высота ячейки) (количество столбцов) (количество строк) (ответы)\n\n");
		exit(1);
	}
	else if (atoi(args[4]) != argc-5) {
		printf("\nВсего вопросов %d, а вы ввели %d ответов\n\n",atoi(args[4]),argc-5);
		exit(1);
	}
	for (i=5;i<argc-1;i++) 
		if (atoi(args[3]) < atoi(args[i]) || atoi(args[i]) < 1){
			printf("\nВсего вариантов ответа %d, а вы ввели ответ %d\n\n",atoi(args[3]),atoi(args[i]));
			exit(1);
		}
	if (atoi(args[1]) < 3 || atoi(args[2]) < 3) {
		printf("\nРазмер ячейки не может быть меньше 3х\n\n");
		exit(1);
	}
}

void assig(){
	c=atoi(args[1]);
	d=atoi(args[2]);
	a=(atoi(args[1])+1)*atoi(args[3])+1;
	b=(atoi(args[2])+1)*atoi(args[4])+1;
}

void desig(){
	for (i=1;i<b+1;i=i+d+1)
		for (j=1;j<a+1;j++)
			form[i][j]=1;
			
	for (j=1;j<a+1;j=j+c+1)
		for (i=1;i<b+1;i++)
			form[i][j]=1;
}

void settick(int vpr, int otv){
	int m,n;
	m=3+((c+1)*(otv-1));
	n=3+((d+1)*(vpr-1));
	for (i=0;i<d-2;i++)
		for (j=0;j<c-2;j++)
			form[n+i][m+j]=1;
}

void present(){
	printf("P1\n");
	printf("%d %d\n",a,b);
	for (i=1;i<b+1;i++){
		for (j=1;j<a+1;j++){
			printf("%d",form[i][j]);
		}
		printf("\n");
	}
}


Budnik A.N.
