void getNext()
{
    int j,k;

    j = 0;
    k = -1;
    nxt[0] = -1;
    while(j<tlen)
    {
        if(k==-1||t[j] == t[k]) nxt[++j] = ++k;
        else k = nxt[k];
    }
}

int KMP_Index()
{
    int i = 0, j = 0;
    getNext();
    while(i<slen&&j<tlen)
    {
        if(j==-1||s[i] == t[j])
        {
            i++;
            j++;
        }
        else j = nxt[j];

    }
    if(j == tlen) return i - tlen;
    else return -1;
}

int KMP_count()
{
    int ans = 0;
    int i,j = 0;
    if(slen == 1&&tlen == 1)
    {
        if(s[0]==t[0]) return 1;
        else return 0;

    }
    getNext();
    for(int i = 0;i<slen;i++)
    {
        while(j>0&&s[i]!=t[j]) j = nxt[j];
        if(s[i] == t[j]) j++;
        if(j==tlen) ans++,j=nxt[j];

    }
    return ans;


}
