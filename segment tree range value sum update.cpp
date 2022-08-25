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
#define     REP(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int  a[300005];
int tree[4 * 300005];
void built_tree(int b, int e, int node)
{
  if (b == e)
  {
    tree[node] = a[b];
    return;
  }
  int mid, left, rigth;
  mid = (b + e) / 2;
  left = node * 2;
  rigth = left + 1;
  built_tree(b, mid, left);
  built_tree(mid + 1, e, rigth);
  tree[node] = tree[left] + tree[rigth];
}
void update(int b, int e, int pos, int value, int node)
{
  if (pos < b || pos > e) return;
  // if (b==e)
  // {
  //   tree[node] ^= value;
  //   return;
  // }
   if (pos <= b && pos >= e)
  {
    tree[node] += value;
    return;
  }
  int mid, left, rigth;
  mid = (b + e) / 2;
  left = node * 2;
  rigth = left + 1;
  update(b, mid, pos, value, left);
  update(mid + 1, e, pos, value, rigth);
  tree[node] = tree[left] + tree[rigth];
}
int search(int node, int b, int e, int l, int r)
{
  if (l > e || r < b) return 0;
  if (l <= b && e <= r) return tree[node];
  int mid, left, rigth, ans1, ans2;

  mid = (b + e) / 2;
  left = node * 2;
  rigth = left + 1;
  ans1 = search(left, b, mid, l, r);
  ans2 = search(rigth, mid + 1, e, l, r);
  return ans1 + ans2;

}

int main()
{
  int n, i, x, y, z, q;
  cin >> n >> q;
  for (i = 1; i <= n; i++) cin >> a[i];
  built_tree(1, n, 1);

  while (q--)
  {
    int p;
    cin >> p;
    if (p == 1)
    {
      int value, pos;
      cin >> pos >> value;

      update(1, n, pos, value, 1);
    } else
    {
      int l, r, ans;
      cin >> l >> r;
      ans = search(1, 1, n, l, r);
      cout << ans << endl;
    }
  }

}
