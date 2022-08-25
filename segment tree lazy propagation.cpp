#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
ll tree[4  * 200005];
ll a[4 * 200005];
ll lazy[4 * 200005];
void  built_tree(ll b, ll e, ll node){
  if (b == e) {
    tree[node] = a[b];
    return;
  }
  ll mid = (b + e) / 2;
  built_tree(b, mid, node * 2);
  built_tree(mid + 1, e, node * 2 + 1);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(ll node, ll b, ll e, ll l, ll r, ll val){
    if(lazy[node] != 0){ 
        tree[node] += (e - b + 1) * lazy[node];  
        if(b!= e){
            lazy[node*2] += lazy[node];                
            lazy[node*2+1] += lazy[node];              
        }
        lazy[node] = 0;                                
    }
    if(b > r || e < l)  return;
    if(b >= l and e <= r){
        tree[node] += (e - b + 1) * val;
        if(b!= e){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    ll mid = (b + e) / 2;
    update(node*2, b, mid, l, r, val);      
    update(node*2 + 1, mid + 1, e, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];      
}
ll query(ll node, ll  b,ll e, ll l, ll r){
  if (b>e||l > e || r < b) return 0;
   if (lazy[node] != 0) {
    tree[node] += (e - b + 1) * lazy[node];
    if (b != e) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
  lazy[node] = 0;
}
  if (l <= b && e <= r) return tree[node];
  ll mid = (b + e) / 2;
  ll ans1 = query(node*2, b, mid, l, r);
  ll ans2 = query(node*2+1, mid + 1, e, l, r);
  return ans1 + ans2;
}
int main(){
  int t=1, l = 1;
  //scanf("%d", &t);
  while (t--){
      ll x, n, i, j, q;
    scanf("%lld %lld", &n, &q);
    for (i = 1; i <= n; i++)  scanf("%lld", &a[i]);
    built_tree(1, n, 1);
    for (i = 1; i <= q; i++){
      ll pos, value, l, r;
      scanf("%lld", &x);
      if (x == 1){
        scanf("%lld %lld %lld", &l,&r,&value);
        update(1, 1,n,l,r,value);
      }
      else{
        scanf("%lld", &l);
        ll ans = query(1, 1, n, l, l);
        printf("%lld\n", ans);
      }
    }
  }
}

