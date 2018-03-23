#include<stdio.h>

int n,count,x;
int a[100];
void printfList(){
	count++;
	printf("xau thu %2d:",count);
	for(int i =1;i<=n;i++){
			printf("%4d",a[i]);
	}
	printf("\n");
	}


//KHONG DIEU KIEN
bool check(){
return true;
}

//liet xau nhi phan khong co 2 xau 1 canh nhau
bool check1(int i,int v){
	if(a[i-1]==1 &&v ==1)
		return false;
	else
		return true;
}
//xau khong co 2so 0 canh nhau
bool check2(int i,int v){
	if(a[i-1]==0 && v==0) return false;
	return true;
}
//xau khong có x so 0 lien tiep
bool check3(int i,int v){
	if(i<x) return true;
	int c=0;
	for(int j =1; j<x ; j++){
			if (a[i-j]==0)  c++;
		}
	if(v==0) c++;
	if(c==x) return false;
	return true;
}


//liet ke xau nhi phan
void backTracking(int k){
	int i;
	for(i =0;i<=1;i++){
		if(check3(k,i)){
			a[k]=i;
			if(k==n) {
					//printfList();
					count++;
			}
				else{
					backTracking(k+1);
			}
		}
	}
}



int main(){
n=3;
x=2;
count=0;
backTracking(1);
printf("%d",count);
}