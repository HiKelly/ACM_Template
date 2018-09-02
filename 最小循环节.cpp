#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 2000010;
int Next[N];
char str[1000010];
void Getfail(int m){
    Next[0] = -1;
    int i = 0, j =-1;
    while(i < m){
        if(j == -1 || str[i] == str[j]){
            i++,j++;
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}

int main(){
    scanf("%s", str);
    int len = strlen(str);
    Getfail(len);
    int ans = len - Next[len];
    printf("%d\n", ans);
    return 0;
}
