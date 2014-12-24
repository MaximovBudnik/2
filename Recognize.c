MAI
===
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;
int tb[1000][1000];
int otvet[100];
int x,y,h,g,kvp,itv,i,j;

void tbbuild();
void recognize();
void chekmark();
void otvprint();
void tbshow();

int main(int argc, char *argv[]){
	file = fopen(argv[1], "r");
	tbbuild();
	recognize();
	chekmark();
	otvprint();

}

void tbbuild(){
	char ch[2];
	i = 1;
	y = 1;
	while (!feof(file))
     {
	fgets(ch, 2, file);

		if (ch[0] == '\n')
		{
			y++;
			if (x<i) x=i;
			i=1;
		}
	if (ch[0] == '1' && y>=3)
		{
			tb[y-2][i] = 1;
			i++;
		}
	
	if (ch[0] == '0' && y>=3)
		{
		tb[y-2][i] = 0;
		i++;
		}
	ch[0] = 0;
     }
	y=y-3;
	x=x-1;
     }

void recognize(){
	for (i=1,j=0;j<2;i++){
		if (tb[2][i] == 1) j++;
		if (tb[2][i] == 0) h++;
	}
	for (i=1,j=0;j<2;i++){
		if (tb[i][2] == 1) j++;
		if (tb[i][2] == 0) g++;
	}
	itv=(x-1)/(h+1);
	kvp=(y-1)/(g+1);
}

void chekmark(){
	int vpr,otv;
	for (vpr=1;vpr<kvp+1;vpr++){
		for (otv=1;otv<itv+1;otv++){
			if ((tb[((1+g)/2+1)+(1+g)*(vpr-1)][((1+h)/2+1)+(1+h)*(otv-1)]) == 1) otvet[vpr]=otv;
		}
	}
}

void otvprint(){
	for (i=1;i<kvp+1;i++)
		printf("%d\n",otvet[i]);
}

void tbshow(int y, int x){
	for (i=1;i<y+1;i++){
		for (j=1;j<x+1;j++){
			printf("%d",tb[i][j]);
		}
		printf("\n");
	}
}

Budnik A.N.
