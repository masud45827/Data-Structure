#include<bits/stdc++.h>
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
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
const int N   = (int) 500 + 5;
const int M   = (int) 9;
ll a[N][N];
ll table[N][M][N][M];
void fun(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)table[i][0][j][0] = a[i][j];
        for (int k = 1; (1 << k) <= m; k++) {
            for (int j = 1; j + (1 << (k - 1)) - 1 <= m; j++) {
                table[i][0][j][k] = min(table[i][0][j][k - 1], table[i][0][j + (1 << k)][k - 1]);
            }
        }
    }
    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            for (int l = 0; (1 << l) <= m; l++) {
                for (int j = 1; j + (1 << l) - 1 <= m; j++) {
                    table[i][k][j][l] = min(table[i][k - 1][j][l], table[i + (1 << (k - 1))][k - 1][j][l]);
                }
            }
        }
    }
}
int query(int x1, int y1, int x2, int y2) {
    int k = log2(x2 - x1 + 1), l = log2(y2 - y1 + 1);
     int  x = min(table[x1][k][y1][l], table[x1][k][y2 + 1 - (1 << l)][l]);
      int y = min(table[x2 + 1 - (1 << k)][k][y1][l], table[x2 + 1 - (1 << k)][k][y2 + 1 - (1 << l)][l]);
    return min(x, y);
}

int main()
{
    int t = 1, fac = 1;
    //scanf("%d",&t);
    while (t--) {
        int n, m, i, x1;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cin >> a[i][j];
        }
        fun(n, m);
        int q,y1,x2,y2;
        cin>>q;
        while(q--){
            cin>>x1>>y1>>x2>>y2;
            int ans=query(x1,y1,x2,y2);
            cout<<ans<<endl;

        }
    }
}
