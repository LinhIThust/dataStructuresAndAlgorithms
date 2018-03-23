#include <stdio.h>
#define MAXN 10000000
int n,k,p,q,i,s[MAXN],a[MAXN];
int main() {
    freopen("sum.inp","r",stdin);
    freopen("sum.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);
    s[0]=0;
    for(i=1; i<=n; i++)
        s[i]=s[i-1]+a[i];
    while (k--) {
        scanf("%d%d",&p,&q);
        printf("%d\n",s[q]-s[p-1]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
