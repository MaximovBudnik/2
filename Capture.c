MAI
===
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tbl[1000][1000];
int a,b,c,d,i,f;
char *args[100];

void exeptions(int argc);
void prisv();
void tblconstruct();
void setmrk(int vpr, int otv);
void tblshow();

int main(int argc, char *argv[]){
	int k;
	
	for (k=1;k<argc-1;k++)
		args[k]=argv[k];
		
	exeptions(argc);
	prisv();
	tblconstruct();
	for (k=5;k<argc;k++)
		setmrk(k-4,atoi(argv[k]));
	tblshow();
}

void exeptions(int argc){
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

void prisv(){
	c=atoi(args[1]);
	d=atoi(args[2]);
	a=(atoi(args[1])+1)*atoi(args[3])+1;
	b=(atoi(args[2])+1)*atoi(args[4])+1;
}

void tblconstruct(){
	for (i=1;i<b+1;i=i+d+1)
		for (f=1;f<a+1;f++)
			tbl[i][j]=1;
			
	for (f=1;f<a+1;f=f+c+1)
		for (i=1;i<b+1;i++)
			tbl[i][f]=1;
}

void setmrk(int vpr, int otv){
	int m,n;
	m=3+((c+1)*(otv-1));
	n=3+((d+1)*(vpr-1));
	for (i=0;i<d-2;i++)
		for (f=0;f<c-2;f++)
			tbl[n+i][m+f]=1;
}

void tblshow(){
	printf("P1\n");
	printf("%d %d\n",a,b);
	for (i=1;i<b+1;i++){
		for (f=1;f<a+1;f++){
			printf("%d",tbl[i][f]);
		}
		printf("\n");
	}
}

Maksimov A.N.
