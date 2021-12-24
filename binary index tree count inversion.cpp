#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
//typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
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
int  bit[200004];
int query(int i) {
    int ans = 0;
    while (i > 0) {
        ans += bit[i];
        i -= (i & (-i));
    }
    return ans;
}
void update(int i, int x, int n) {
    while (i <= n) {
        bit[i] += x;
        i+=(i&(-i));
    }
}
int main() {
    int test = 1, fac = 1;
    //scanf("%d", &test);
    while (test--) {
        int n, i, j, x, y, ans = 0;
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> x;
            ans+=(query(n) - query(x));
            update(x, 1, n);
        }
        cout << ans << endl;
    }
    return 0;
}

