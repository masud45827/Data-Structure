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
int arr[200005];
int temp[200005];
ll merging(int l, int mid, int r)
{
    int n1,n2,i;
    n1 = l;
    n2 = mid + 1;
    ll inv=0;
    for(i = n1; n1<=mid && n2<=r; i++)
    {
        if(arr[n1] <= arr[n2]){
            temp[i] = arr[n1++];
        }
        else{
            temp[i] = arr[n2++];
            inv+=(mid-n1+1);
        }
    }

    while(n1 <= mid)
        temp[i++] = arr[n1++];

    while(n2 <= r)
        temp[i++] = arr[n2++];

    for(i = l; i<=r; i++)
        arr[i] = temp[i];
    return inv;

}

ll sorting(int l, int r)
{
    int mid;
      ll inv=0;
    if(l >= r)
        return 0;
    mid = (l+r)/2;
    inv+=sorting(l, mid);
    inv+=sorting(mid+1, r);
    inv+=merging(l, mid, r);
    //error(l,r,inv);
     return inv;
}

int main()
{
    int i, n;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);
    ll ans=sorting(0, n-1);
    cout<<ans<<endl;
    return 0;
}
