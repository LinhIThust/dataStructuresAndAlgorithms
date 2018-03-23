#include<stdio.h>
#define MAX 10000
int i,j,n,a[MAX][MAX];
int main(){
FILE* f =fopen("TRIANPAS.INP","r");
FILE*f1 = fopen("TRIANPAS.OUT","w");
fscanf(f,"%d",&n);
a[0][0]=1;
a[1][0]=1;
a[1][1]=1;
for(i=2;i<=n;i++){
	a[i][0]=1;
	for(j=1;j<=i+1;j++){
		a[i][j] = a[i-1][j-1]+a[i-1][j];
	}
}
for(i=0;i<=n;i++)
	 fprintf(f1,"%5d",a[n][i]);
fclose(f);
fclose(f1);



}