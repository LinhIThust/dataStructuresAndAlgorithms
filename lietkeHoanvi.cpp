//hoan vi
#include<stdio.h>
int n,count;
int a[100];

void printfList(){
	count++;
	printf("hoan vi thu %3d:",count);
	for(int i=1;i<=n;i++){
		printf("%3d",a[i]);
	}
	printf("\n");
}

bool check(int i,int v){
	int j;
	for(j=1;j<=i-1;j++)
		if(a[j]==v) return false;
	return true;
}

void backTracking(int k){

	for(int i=1;i<=n;i++){
		if(check(k,i)){
			a[k] =i;
			if(k==n) {
					printfList();
			}else{
				backTracking(k+1);
			}
		}
	}
}

int main(){
n=4;
count=0;
backTracking(1);


}
