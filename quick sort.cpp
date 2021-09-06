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
int n;
int part(int a[],int l,int h)
{
  int p,i,j,x;
   p=a[h]; i=l;
   for(j=l;j<h;j++){
    if(a[j]<p){
       swap(a[i],a[j]);
           i++;
    }
   }
   swap(a[i],a[h]);
   return i;
}
void fun(int a[],int l,int h)
{

  if(l>=h) return;
  int p=part(a,l,h);
   fun(a,l,p-1);
   fun(a,p+1,h);
}
int main()
{
  int t = 1;
  //cin >> t;
  while (t--)
  {
      int i,x,y;
      cin>>n;
      int a[n+3];
      for(i=0;i<n;i++) cin>>a[i];
       fun(a,0,n-1);
     for(i=0;i<n;i++) cout<<a[i]<<" ";
      cout<<endl;
  }
}



