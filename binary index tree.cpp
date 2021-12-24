//http://lightoj.com/volume_showproblem.php?problem=1112
#include<bits/stdc++.h>
using namespace std;
long long  a[1000006];
void update(long long i, long long x, long long n){
  while (i <= n){
    a[i] += x;
    i += (i & (-i));
  }
}
void decr(long long i, long long x, long long n){
  while (i <= n){
    a[i] -= x;
    i += (i & (-i));
  }
}
long long query(long long x){
  long long sum = 0;
  while (x > 0){
    sum += a[x];
    x -= (x & (-x));
  }
  return sum;
}
int main(){
  int t, test = 1;
  scanf("%d",&t);
  while (t--){
   memset(a,0,sizeof(a));
    long long n, i, j, x, y, q, p;
  scanf("%lld %lld",&n,&q);
    for (i = 1; i <= n; i++){
      scanf("%lld",&x);
      update(i, x, n);
    }
    // cout << "Case " << test << ":" << endl;
    printf("Case %d:\n",test);
    while (q--){
     scanf("%lld",&x);
      if (x == 1) {
      scanf("%lld",&y);
        long long ans;
        y++;
        ans = query(y);
        if (y != 1) ans-=query(y - 1);
        printf("%lld\n",ans);
        decr(y, ans, n);
      } else if (x == 2){
        scanf("%lld %lld",&p,&y);
        p++;
        update(p, y, n);
 
      } else{
        long long  ans, l, r;
        //cin >> l >> r;
        scanf("%lld %lld",&l,&r);
        l++; r++;
        ans = query(r);
        if (l != 1) ans -= query(l - 1);
     
       printf("%lld\n",ans);
      }
    }
    test++;
  }
}
//http://lightoj.com/volume_showproblem.php?problem=1112
