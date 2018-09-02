int prime[maxn];
bool vis[maxn];
void Euler_peime(int n) //最大为n
{
    for(int i=2;i<=n;++i)
    {
        if(!vis[i]) {
            a[i] = i==2?1:(i-1)/2;
            prime[cnt++]=i;
            vis[i]=true;
        }
        for(int j=0;j<cnt;++j)
        {
            if(i*prime[j]>n)//判断是否越界
                break;
            vis[i*prime[j]]=true;//筛数
            if(i%prime[j]==0)//时间复杂度为O(n)的关键！
                break;
        }
    }
}