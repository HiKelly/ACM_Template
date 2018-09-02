#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int w[maxn], v[maxn];
int f[maxn];

/*01背包*/
int solve1(){
    memset(f, 0, sizeof(f));    //1.若要求必须把背包装满，则f[0]为0，其他初始化为-∞
                                //2.若未要求装满，则全初始化为0
        for(int i = 0; i < n; i++)
            for(int j = V; j >= w[i]; j--)
                f[j] = max(f[j], f[j-w[i]] + v[i]);
    return dp[V];
}
