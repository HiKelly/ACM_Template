#define mod(x) (((x)%MOD+MOD)%MOD)
struct  mat{
    ll m[2][2]; //改矩阵大小
} unit;
mat operator *(mat a,mat b){
    mat ret;
    ll x;
    forn(i,n)
    	forn(j,n){
        	x =0 ;
        	forn(k,n) x+=mod((ll)a.m[i][k]*b.m[k][j]);
        	ret.m[i][j] = mod(x);
    }
    return ret;
}
/*
mat operator *(mat a,mat b) //稀疏矩阵乘法优化
{
    mat ret;
    initial(ret);
    ll x;
    forn(i,wid)
        forn(j,wid)
        {
            if(!a.m[i][j]) continue;
            forn(k,wid) ret.m[i][k]+=a.m[i][j]*b.m[j][k];

        }
    return ret;
}
*/
void init_unit(){
    forn(i,2){
        unit.m[i][i]=1;
    }
    return ;
}
mat pow_mat(mat a,ll n){//a^n
    mat ret = unit;
    while(n){
        if(n&1) ret = ret*a;
        a = a * a;
        n>>=1;
    }
    return ret;
}
mat tag,res,t;
int n;
int main(){
      res = pow_mat(t,n); // t^n
      res = res * tag; // B = A^n * x 
      cout<<res[0][0] // 答案位置
}