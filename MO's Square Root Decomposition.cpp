//Distinct value of range
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
int n,q,seg,res=0;
int ans[1000005],a[1000005],cnt[1000005];
struct query{
   int l,r,index;
}Q[1000005];
bool cmp(query i,query j){
   if((i.l/seg)!=(j.l/seg))return (i.l/seg)<(j.l/seg);
   else return i.r<j.r; 
}
 void remove(int index){
    cnt[a[index]]--;
     if(cnt[a[index]]==0)  res--;
 }
 void add(int index){
    cnt[a[index]]++;
     if(cnt[a[index]]==1)  res++;
 }
int main()
{
  int t = 1, fac = 1;
  scanf("%d", &t);
  while (t--)
  {
    int i,j,l,r;
      res=0;
      mem(cnt);
     scanf("%d%d",&n,&q);
     seg=sqrt(n);
     for(i=0;i<n;i++) scanf("%d",&a[i]);
     for(i=0;i<q;i++){
         scanf("%d %d",&l,&r);
         Q[i].l=l-1; Q[i].r=r-1;  Q[i].index=i;
     }
     sort(Q,Q+q,cmp);
      int curl=0,curr=-1;
     for(i=0;i<q;i++){
       l=Q[i].l; r=Q[i].r;
       while(curl<l) remove(curl++);
       while(curl>l) {
        add(--curl);
      }
      while(curr<r) add(++curr);
       while(curr>r){
         remove(curr--);
       }
       ans[Q[i].index]=res;
   }
   printf("Case %d:\n",fac++);
    for(i=0;i<q;i++) printf("%d\n",ans[i]);
 
  }
return 0;
}

//sum of range
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
// ll segment[10000],a[200005],seg;
// void update(ll pos,ll val){
//   segment[pos/seg]-=a[pos];
//   a[pos]=val;
//   segment[pos/seg]+=a[pos];
// }
// ll query(ll l, ll r){
//   ll s=0;
//    while(l<r&&l%seg!=0) s+=a[l++];
//        while(l+seg<=r){
//           s+=segment[l/seg];
//           l+=seg;
//        }
//        while(l<=r) s+=a[l++];
//        return s;
// }
// int main()
// {
//   int t = 1, fac = 1;
//   //scanf("%d", &t);
//   while (t--)
//   {
//     ll n,i,j,x,y,cur_seg=-1,q;
//     cin>>n>>q;
//       for(i=0;i<n;i++) cin>>a[i];
//     seg=sqrt(n);
//     for(i=0;i<n;i++){
//       if(i%seg==0) cur_seg++;
//        segment[cur_seg]+=a[i];
//     }
//     ll l,r,s=0;
//     while(q--){
//         cin>>x>>l>>r;
//         l--;r--;
//          if(x==2) cout<<query(l,r)<<endl;
//          else update(l,r+1);
//     }
//   }
// }
//sum of range
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
// int segment[10000];
// int main()
// {
//   int t = 1, fac = 1;
//   //scanf("%d", &t);
//   while (t--)
//   {
//     int n,i,j,x,y,cur_seg=-1,seg;
//     cin>>n;
//      int a[n+2];
//       for(i=0;i<n;i++) cin>>a[i];
//     seg=sqrt(n);
//     for(i=0;i<n;i++){
//       if(i%seg==0) cur_seg++;
//        segment[cur_seg]+=a[i];
//     }
//     int q,l,r,s=0;
//     cin>>q;
//     while(q--){
//       int s=0;
//       cin>>l>>r;
//        while(l<r&&l%seg!=0) s+=a[l++];
//        while(l+seg<=r){
//           s+=segment[l/seg];
//           l+=seg;
//        }
//        while(l<=r) s+=a[l++];
//        cout<<s<<endl;
//     }
//   }
// }
