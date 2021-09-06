#include<bits/stdc++.h>
using namespace std;
// int right(int i)
// {
//     return 2*i+1;
// }
// int left(int i)
// {
//     return 2*i;
// }

void max_heap(int a[],int heap,int i)
{
    int l,r,larg,t;
    r=2*i;
    l=2*i+1;
    if(l<=heap&&a[l]>a[i])
    {
    larg=l;
    }else
    {
        larg=i;
    }
    if(r<=heap && a[r]>a[larg])
    {
      larg=r;
    }
    if(larg!=i)
    {
         t=a[i];
        a[i]=a[larg];
        a[larg]=t;
        max_heap(a,heap,larg);
    }
    
}
  void heap_sort(int a[],int heap)
  {
    int i,t;
    for(i=heap;i>1;i--)
    {
        t=a[1];
        a[1]=a[i];
        a[i]=t;
        heap--;
        max_heap(a,heap,1);
    }

  }
void bmh(int a[],int heap)
{
    int i;
    for(i=heap/2;i>=1;i--)
    {
       max_heap(a,heap,i);
        
    }

}
int main()
{
    int heap,i;
    cin>>heap;
    int a[heap+2];
    for(i=1;i<=heap;i++)
    {
        cin>>a[i];
    }
    bmh(a,heap);
     heap_sort(a,heap);
  for(i=1;i<=heap;i++)
  {
   cout<<a[i]<<" ";
  }
  cout<<endl;
}
