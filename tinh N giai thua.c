#include<stdio.h>
#define MAX 1000
int i;
double a[MAX];
int n;


int main(){
FILE* f = fopen("inputGiaiThua.txt","r");
fscanf(f,"%d",&n);
FILE* fn = fopen("outputGiaiThua.txt","w");

a[0]=1;
for(i=1;i<=n;i++)
    a[i]=a[i-1]*i;

fprintf(fn,"%5d",a[n]);
fclose(f);
fclose(fn);

}
