MAI
===
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;
char ha[1000][10000];
int hb[1000][1000];
int hc[1000][1000];
int hd[1000][1000];
int he[1000][1000];
int hf[1000][1000];
int r,z,i,j; 

void recog(); 
void givcol(); 
void grad(); 
void bin(); 
void show();

int main(int argc, char *argv[])
{
	file = fopen(argv[1], "r");
	recog();
	givcol();
	grad();
	bin();
	show();
}

void bin()
{
	for(j=4;j<z;j++)
		for(i=1;i<r;i++)
		{
			if (he[j][i]>atoi(ha[3])/3) hf[j-3][i]=0;
			else hf[j-3][i]=1;
		}
}

void grad()
{
	for(j=4;j<z;j++)
		for(i=1;i<r;i++)
			he[j][i]=(hb[j][i]+hc[j][i]+hd[j][i])/3;
}

void recog()
{
	z=1;
	while (fgets(ha[z], 1000, file))
	{
		z++;
	}
}

void givcol()
{
	char *buf;
	int d=1;
	r=1;
	i=1;

	for(j=1;j<z;j++)
	{
		buf = strtok(ha[j], " ");
		while (buf != NULL)
		{
			if (d==1) {hb[j][i] = atoi(buf); d++;}
			else if (d==2) {hc[j][i] = atoi(buf); d++;}
			else if (d==3) {hd[j][i] = atoi(buf); d=1; i++;}
			if (r<i) r=i;
			buf=strtok(NULL," ");
		}
		d=1;
		i=1;
	}
}




void show()
{
	printf("P1\n");
	printf("%d %d\n", z-4, r-1);
	for(j=1;j<z-3;j++){
		for(i=1;i<r;i++)
		{
			printf("%d ",hf[j][i]);
		}
	printf("\n");
	}
}
