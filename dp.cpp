#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int w[maxn], v[maxn];
int f[maxn];

/*01����*/
int solve1(){
    memset(f, 0, sizeof(f));    //1.��Ҫ�����ѱ���װ������f[0]Ϊ0��������ʼ��Ϊ-��
                                //2.��δҪ��װ������ȫ��ʼ��Ϊ0
        for(int i = 0; i < n; i++)
            for(int j = V; j >= w[i]; j--)
                f[j] = max(f[j], f[j-w[i]] + v[i]);
    return dp[V];
}
