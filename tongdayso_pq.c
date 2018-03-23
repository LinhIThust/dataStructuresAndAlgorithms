#include<stdio.h>
#define MAX 1000000
#define for1(n) for(i =1;i<n;i++)

int i,n,k,p,q,kq;
int a[MAX],sum[MAX];
int main(){
FILE* f =fopen("sum.inp","r");
FILE*f1 = fopen("sum.out","w");
fscanf(f,"%d",&n);
fscanf(f,"%d",&k);
for(i=0;i<n;i++)
	fscanf(f,"%d",&a[i]);
sum[0] =0;
for(i=1;i<=n;i++)
	sum[i] = sum[i-1]+a[i-1];
for(i=0;i<k;i++){
		fscanf(f,"%d %d",&p,&q);
		fprintf(f1,"%d\n",sum[q]-sum[p-1]);
		}

fclose(f1);
fclose(f);
}
