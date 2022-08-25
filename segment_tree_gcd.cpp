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
 int tree[4 * 100005];
 int a[4 * 100005];
int const infinity=(int) INT_MAX;  
void  built_tree(int b, int e, int node)
{
  if (b == e)
  {
    tree[node] = a[b];
    return;
  }
  int left, right, mid;
  mid = (b + e) / 2;
  left = node * 2;
  right = node * 2 + 1;
  built_tree(b, mid, left);
  built_tree(mid + 1, e, right);
  tree[node] = __gcd(tree[left] , tree[right]);
}
void update(int b, int e, int pos, int value, int node)
{
  if (pos < b || pos > e) return;
  if (pos <= b && pos >= e)
  {
    tree[node] = value;
    return;
  }
  int mid, left, right;
  mid = (b + e) / 2;
  left = node * 2;
  right = node * 2 + 1;
  update(b, mid, pos, value, left);
  update(mid + 1, e, pos, value, right);
  tree[node] = __gcd(tree[left] ,tree[right]);
}
 int query(int node, int b, int e, int l, int r)
{
  if (l > e || r < b) return 0;
  if (l <= b && e<= r) return tree[node];
  int mid, left, right;
  mid = (b + e) / 2;
  left = node * 2;
  right = node * 2 + 1;
  int ans1 = query(left, b, mid, l, r);
  int ans2 = query(right, mid + 1, e, l, r);
  return __gcd(ans1 , ans2);

}

int main()
{
  int t=1, l = 1;
  //scanf("%d", &t);
  while (t--)
  {
    int x, n, i, j, q;
    scanf("%d %d", &n, &q);
    for (i = 1; i <= n; i++)  scanf("%d", &a[i]);
    built_tree(1, n, 1);
    for (i = 1; i <= q; i++)
    {
      int pos,value,l,r,d;
      scanf("%d", &x);
      if (x == 1)
      {
        scanf("%d %d", &pos, &value);
        update(1, n, pos, value, 1);
      }
      else 
      {

        scanf("%d %d", &l, &r);
         int ans = query(1, 1, n, l, r);
          cout<<ans<<endl;

      }
    }

  }
}

  
