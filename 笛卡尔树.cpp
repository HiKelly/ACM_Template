int stk[maxn],r[maxn],l[maxn],vis[maxn];
// r:右子节点 l:左子节点 vis:求根用
void build(){
    int top = 0;
    for(int i = 0; i<n+1;i++) stk[i] = 0;
    for(int i = 0; i<n+1;i++) l[i] = r[i] = vis[i] = 0;
    for(int i = 1;i<n+1;i++){
        int k = top;
        while(k&&a[stk[k-1]]<a[i]) --k;
        if(k) r[stk[k-1]] = i;
        if(k<top) l[i] = stk[k];
        stk[k++] = i;
        top = k;
    }
}