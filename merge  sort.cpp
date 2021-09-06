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
int arr[1003];
int temp[1001], counter = 0;

void merging(int startPoint, int midPoint, int endPoint)
{
    int firstArrCnt,secArrCnt,i;
    firstArrCnt = startPoint;
    secArrCnt = midPoint + 1;

    for(i = firstArrCnt; firstArrCnt<=midPoint && secArrCnt<=endPoint; i++)
    {
        if(arr[firstArrCnt] < arr[secArrCnt])
            temp[i] = arr[firstArrCnt++];
        else
            temp[i] = arr[secArrCnt++];
    }

    while(firstArrCnt <= midPoint)
        temp[i++] = arr[firstArrCnt++];

    while(secArrCnt <= endPoint)
        temp[i++] = arr[secArrCnt++];

    for(i = startPoint; i<=endPoint; i++)
        arr[i] = temp[i];

}

void sorting(int startPoint, int endPoint)
{
    int midPoint;

    if(startPoint >= endPoint)
        return;
    midPoint = (startPoint+endPoint)/2;

    sorting(startPoint, midPoint);
    sorting(midPoint+1, endPoint);
    merging(startPoint, midPoint, endPoint);
}

int main()
{
    int i, n;

    printf("Enter number of elements:\n");
    scanf("%d", &n);
    printf("Enter %d elements:\n",n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sorting(0, n-1);
    printf("\nAfter sorting the Array:\n");
    for(i = 0; i<n; i++)   printf("%d ", arr[i]);
        printf("\n");


    return 0;
}
