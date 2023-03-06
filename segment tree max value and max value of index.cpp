#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <assert.h>
#include <new>
#include <sstream>
#include <time.h>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
#define setpr(x) cout<<setprecision(x)<<fixed
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
template <typename T> inline void Int(T &a) {
	bool minus = false; a = 0; char ch = getchar();
	while (true) { if (ch == '-' or (ch >= '0' && ch <= '9')) break; ch = getchar(); }
	if (ch == '-') minus = true; else a = ch - '0';
	while (true) { ch = getchar(); if (ch < '0' || ch > '9') break; a = a * 10 + (ch - '0'); }
	if (minus)a *= -1 ;
}
#ifdef LOCAL
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ' ' ;
	err(++it, args...);
}
#else
#define error(args...)
#endif

const int N          = (int)2e5 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;
const int mod        = (int)1e9 + 7 ;
const double EPS     = (double)1e-9 ;
const double PI      = (double)acos(-1.0) ;


inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}
ll a[N + 3];
ll tree[3 * N + 3];
ll index[3 * N + 3];
void build(ll b, ll e, ll node) {
	if (b == e) {
		index[node] = b;
		tree[node] = a[b];
		return ;
	}
	ll mid = (b + e) / 2;
	ll left = 2 * node, right = 2 * node + 1;
	build(b, mid, left);
	build(mid + 1, e, right);
	if (tree[left] > tree[right]) {
		tree[node] = tree[left];
		index[node] = index[left];
	} else {
		tree[node] = tree[right];
		index[node] = index[right];
	}
}
void update(ll b, ll e, ll pos, ll value, ll node) {
	if (pos < b || pos > e) return;
	if (pos <= b && pos >= e) {
		tree[node] = value;
		index[node] = pos;
		return;
	}
	ll mid, left, right;
	mid = (b + e) / 2;
	left = node * 2;
	right = node * 2 + 1;
	update(b, mid, pos, value, left);
	update(mid + 1, e, pos, value, right);
	if (tree[left] > tree[right]) {
		tree[node] = tree[left];
		index[node] = index[left];
	} else {
		tree[node] = tree[right];
		index[node] = index[right];
	}
}
pl query(ll node, ll b, ll e, ll l, ll r) {
	if (l > e || r < b) return { -1, -1};
	if (b >= l && e <= r) {
		return {index[node], tree[node]};
	}
	ll mid = (b + e) / 2;
	pl p1 = query(node * 2, b, mid, l, r);
	pl p2 = query(node * 2 + 1, mid + 1, e, l, r);
	if (p1.F == -1 && p2.F == -1) return { -1, -1};
	if (p1.F == -1) return p2;
	if (p2.F == -1) return p1;
	if (p1.S > p2.S) return p1;
	else return p2;
}
int main() {
	int test = 1, fac = 1;
	//cin >> test;
	while (test--) {
		ll n, i, j, x, y;
		cin >> n;
		for (i = 1; i <= n; i++)  cin >> a[i];
		build(1, n, 1);
		ll q;
		cin >> q;
		while (q--) {
			ll t;
			cin >> t;
			if (t == 1) {
				ll l, r;
				cin >> l >> r;
				pl p = query(1, 1, n, l, r);
				cout << p.F << " " << p.S << endl;
			}else{
				 ll pos,val;
				 cin>>pos>>val;
				  update(1, n, pos, val, 1);
			}
		}
	}
	return 0;
}


