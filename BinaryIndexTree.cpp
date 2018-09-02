#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e4+5;
int a[maxn];
int val[maxn];
int n;
int lowbit(int x){
    return x & (-x);
}
int Query(int x){
    int sum = 0;
    while(x > 0){
        sum += val[x];
        x -= lowbit(x);
    }
    return sum;
}
void Update(int x, int k){
    while(x <= n){
        val[x] += k;
        x += lowbit(x);
    }
}
int main(){
    int T;
    cin >> T;
    int cas = 1;
    while(T--){
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(val, 0, sizeof(val));
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            Update(i, a[i]);
        }
        cout << "Case " << cas++ << ":" << endl;
        string s;
        while(cin >> s && s != "End"){
            int x, y;
            cin >> x >> y;
            if(s == "Query")
                cout << Query(y) - Query(x - 1) << endl;
            else if(s == "Add")
                Update(x, y);
            else
                Update(x, -y);
        }
    }
}

