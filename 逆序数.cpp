#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5+5;
ll a[maxn];
ll r[maxn];
ll ans;
void Msort(int s,int t)
{
    if (s==t) return; //�ݹ�߽�
    int mid=(s+t)/2; //�����е�
    Msort(s,mid); //�ݹ�������߽�
    Msort(mid+1,t); //�ݹ������ұ߽�
    int i=s,j=mid+1,k=s;
    while (i<=mid&&j<=t) //�ϲ�
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
            ans+=(mid-i+1); //����
        }
    }
    while (i<=mid) //����ʣ������
    {
        r[k]=a[i];
        k++; i++;
    }
    while (j<=t)
    {
        r[k]=a[j];
        k++; j++;
    }
    for (int i=s;i<=t;i++) //����
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

