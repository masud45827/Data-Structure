//range  minimum value query
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
ll g[200005][20];
int a[200004];
int query1(int l, int r)
{
  int  p=log2(r-l+1);
  return min(g[l][p],g[r-(1<<p)+1][p]);
}
void fun(int n)
{
  int i,j;
  for(j=1;j<=20;j++)
  {
    for(i=1;(i+(1<<j)-1)<=n;i++)
    {
       g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
    }
  }
}
int main()
{
   int t = 1, fac = 1;
    // scanf("%d", &t);
   while (t--)
   {
     int n,i,j,x,y;
     cin>>n;
     for(i=1;i<=n;i++) 
      {
        cin>>a[i]; g[i][0]=a[i];
      }
      fun(n);
      int q,l,r;
      cin>>q;
      while(q--)
      {
        cin>>l>>r;
        l++; r++;
        int ans=query1(l,r);
        cout<<ans<<endl;
      }

   }

}


//range  gcd query
// #include<bits/stdc++.h>
// using namespace std;
// typedef     long long    ll;
// typedef     unsigned long long    ull;
// typedef     vector<int> vi;
// typedef     vector<long long> vl;
// typedef     pair<int, int>pi;
// typedef     pair<long long, long long>pl;
// #define F   first
// #define S   second
// #define pb  push_back
// #define     all(x)      x.begin() , x.end()
// #define mod 1000000007
// #define       FOR(i,a,b) for(i=a;i<=b;i++)
// #define     mem(a)      memset(a , 0 ,sizeof a)
// #define     memn(a)     memset(a , -1 ,sizeof a)
// ll g[200005][20];
// int a[200004];
// int query1(int l, int r)
// {
//   int  p=log2(r-l+1);
//   return __gcd(g[l][p],g[r-(1<<p)+1][p]);
// }
// void fun(int n)
// {
//   int i,j;
//   for(j=1;j<=20;j++)
//   {
//     for(i=1;(i+(1<<j)-1)<=n;i++)
//     {
//        g[i][j]=__gcd(g[i][j-1],g[i+(1<<(j-1))][j-1]);
//     }
//   }
// }
// int main()
// {
//    int t = 1, fac = 1;
//      scanf("%d", &t);
//    while (t--)
//    {
//      int n,i,j,x,y;
//      cin>>n;
//      for(i=1;i<=n;i++) 
//       {
//         cin>>a[i]; g[i][0]=a[i];
//       } 
//       fun(n);
//       int q,l,r;
//       cin>>q;
//       while(q--)
//       {
//         cin>>l>>r;
//         int ans=query1(l,r);
//         cout<<ans<<endl;
//       }

//    }

// }


//range  sum query
// #include<bits/stdc++.h>
// using namespace std;
// typedef     long long    ll;
// typedef     unsigned long long    ull;
// typedef     vector<int> vi;
// typedef     vector<long long> vl;
// typedef     pair<int, int>pi;
// typedef     pair<long long, long long>pl;
// #define F   first
// #define S   second
// #define pb  push_back
// #define     all(x)      x.begin() , x.end()
// #define mod 1000000007
// #define       FOR(i,a,b) for(i=a;i<=b;i++)
// #define     mem(a)      memset(a , 0 ,sizeof a)
// #define     memn(a)     memset(a , -1 ,sizeof a)
// int a[100004];
// int g[100003][22];
// int query(int l,int r)
// {
//  int  s=0,i;
//   for(i=20;i>=0;i--)
//   {
//      if((1<<i)<=(r-l+1))
//      {
//       s+=g[l][i];
//        l+=(1<<i);
//      }
//   }
//   return s;
// }
// void  fun(int n)
// {
//   int i,j,x,y;
//     for(j=1;j<=20;j++)
//     {
//        for(i=1;(i+(1<<j)-1)<=n;i++)
//        {
//            g[i][j]=g[i][j-1]+g[i+(1<<(j-1))][j-1];
//        }
//     }
// }

// int main()
// {
//   int t = 1;
//   //cin >> t;
//   while (t--)
//   {
//     int n,i,j,x,y;
//     cin>>n;
//     for(i=1;i<=n;i++) 
//       {
//         cin>>a[i];
//         g[i][0]=a[i];
//       }
//      fun(n);
//      int q;
//      cin>>q;
//      while(q--)
//      {
//       int l,r;
//       cin>>l>>r;
//       cout<<query(l,r)<<endl;
//      }
//   }
// }
