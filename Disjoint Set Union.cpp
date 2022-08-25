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
#define mp make_pair
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int parent[100005],rank1[100005];
int find(int x)
{
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void merge(int x, int y){
    int PX=find(x),PY=find(y);
    if(rank1[PX]>rank1[PY]){
        parent[PY]=PX;
         rank1[PX]++;
    }
    else{
        parent[PX]=PY;
        if(rank1[PX]==rank1[PY])
            rank1[PY]++;
    }
}
int main()
{
    int n,i,m,x,y,u,v;
    cin>>n>>m;
    for(i=0;i<=n;i++) parent[i]=i;
     for(i=0;i<m;i++)
     {
       cin>>u>>v;
       if(find(u)!=find(v))
       {
            merge(u,v);
       }
     }
     set<int>s;
     for(i=1;i<=n;i++) 
        {
           x=find(i);
        }
     for(i=1;i<=n;i++) s.insert(parent[i]);
       // for(i=1;i<=n;i++) cout<<parent[i]<<" ";
          //  cout<<endl;
        cout<<s.size()-1<<endl;
     vector<int>v1(all(s));
     for(i=1;i<v1.size();i++)
     {
        cout<<v1[i-1]<<" "<<v1[i]<<endl;
     }
}
