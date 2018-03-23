#include <bits/stdc++.h>
#define MAXN (int)(1e5)
#define MAXA (int)(1e9)

using namespace std;

int n,q,u,v;

int main() {
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   freopen("chenhlech.inp","w",stdout);
   srand(time(NULL));
   n=rand()%MAXN +1;
   q=rand()%MAXN +1;
   cout << n << " " << q << endl;
   for (int i=1; i<=n; i++)
       cout << rand()%MAXA << " ";
   cout << endl;
   while (q--) {
    u=rand()%n +1;
    v=u+rand()%(n-u+1);
    cout << u << " " << v << endl;
   }
   fclose(stdout);
}
