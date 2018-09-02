#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5+5;
ll a[maxn];
ll r[maxn];
ll ans;
void Msort(int s,int t)
{
    if (s==t) return; //递归边界
    int mid=(s+t)/2; //计算中点
    Msort(s,mid); //递归排序左边界
    Msort(mid+1,t); //递归排序右边界
    int i=s,j=mid+1,k=s;
    while (i<=mid&&j<=t) //合并
    {
        if (a[i]<=a[j])
        {
            r[k]=a[i];
            k++; i++;
        }
        else
        {
            r[k]=a[j];
            k++; j++;
            ans+=(mid-i+1); //计数
        }
    }
    while (i<=mid) //处理剩余序列
    {
        r[k]=a[i];
        k++; i++;
    }
    while (j<=t)
    {
        r[k]=a[j];
        k++; j++;
    }
    for (int i=s;i<=t;i++) //复制
        a[i]=r[i];
}
int main(){
    ll n;
    while(~scanf("%lld", &n)){
        memset(a, 0, sizeof(a));
        ans = 0;
        for(ll i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        Msort(0, n - 1);
        printf("%lld\n", ans);
    }
}

