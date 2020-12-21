#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,r[191][6],i,d,a,t[99][99][191],e;
char*p,b[99],v[99][99][191];

char s(int u, int l, int h) {
    int*q=r[u],*x=&t[l][h][u];
    if(l==h)
        return !q[0]&&b[l]==q[1]||!q[2]&&b[l]==q[3];

    char*o=&v[l][h][u];
    *x^e?*o=0:0;
    for(int d=0;*x^e&&d<5;d+=2)
        for(int j=l;!*o&&q[d]>0&&q[d+1]>0&&j<h;++j)
            *o|=s(q[d],l,j)&&s(q[d+1],j+1,h);

    *x=e;
    return *o;
}

int main(int c,char**g){
    for(;(p=gets(b))&&*b;n=n>i?n:i+1){
        i = atoi(p);
        for(;*p^32;++p);
        if (*++p==34)
            r[i][1]=*++p;
        else{
            for(d=0;*p;++d){
                r[i][d]=atoi(p);
                for(;*p&&*p^32;++p);
                *p&&*++p==124?p+=2,d=1:0;
            }
        }
    }
    for(i=0;i<n;++i)
        for(d=0;d<3;d+=2)
            r[i][d]&&!r[i][d+1]?
                r[i][d+1]=r[r[i][d]][1],r[i][d]=r[r[i][d]][0]:0;
    for(i=0;i<4;++i)r[8][i]=r[42][i];
    --c?
        r[r[8][5]=8][4]=r[11][2]=42,
        r[r[n][0]=11][3]=n,
        r[n++][1]=31:0;
    for(;++e,gets(b)&&*b;a+=s(0,0,i-1))
        for(i=0;b[i];++i);
    printf("%d\n",a);
}
