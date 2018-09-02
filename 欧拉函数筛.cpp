ll Euler(ll n){
    ll res = n;
    for(ll i = 2;i * i <= n;i++){
        if(n%i==0) res = res/i*(i-1);
        while(n%i==0) n/=i;
    }
    if(n>1) res = res/n*(n-1);
    return res;a
}
void getphi(int n){

    phi[1] = 1;
    cnt = 0;
    for(int i = 2;i<=n;i++){
        if(!vis[i]){phi[i] = i - 1;prime[cnt++] = i;}
        for(int j = 0;j<cnt;j++){
            int x = prime[j];
            if(i*x>n) break;
            vis[i*x] = true;
            if(!(i%x)) {phi[i*x] = phi[i] * x;break;}
            else phi[i*x] = phi[i] * phi[x];
        }
    }
}