#include<stdio.h>
#define MAX 1000
int i;
int a[MAX];
int n;


int main(){
FILE* f = fopen("inputFibo.txt","r");
fscanf(f,"%d",&n);
FILE* fn = fopen("outputFibo.txt","w");

a[0]=1;a[1]=1;
for(i=2;i<=n;i++)
    a[i]=a[i-1]+a[i-2];
fprintf(fn,"%d",a[n]);
fclose(f);
fclose(fn);

}

