#include <stdio.h>
#include <stdlib.h>

long*p,s[32][4],a[333][32],h[512],u[512],t[32],n,i,j,m,x,v,y,z;
char*l,b[999];
int main(int c,char**g){
    for(p=*s;(l=gets(b))&&*l;p=s[++n]){
        for(;*l^':';++l);
        *p++ = atoi(l+2);
        for(;*l^'-';++l);
        *p++ = atoi(l+1);
        for(;*l^'r';++l);
        *p++ = atoi(l+2);
        for(;*l^'-';++l);
        *p++ = atoi(l+1);
    }

    gets(b);
    for(l=gets(b);*l;*l?++l:0){
        t[i++]=atoi(l);
        for(;*l&&*l^',';++l);
    }

    for(p=u;p<u+n*n;++p)
        *p=1;
    gets(b);
    gets(b);
    for(;(l=gets(b))&&*l;){
        for(z=1,p=a[m++],l=b,i=0;*l;*l?++l:0,++i,v=0){
            *p++=x=atoi(l);
            for(;*l&&*l^',';++l);
            for(j=0;j<n;++j)
                v|=(h[n*i+j]=(s[j][0]<=x&&x<=s[j][1])||(s[j][2]<=x&&x<=s[j][3]));
            v?0:(y+=x);
            z&=v;
        }
        for(i=0;z&&i<n*n;++i)
            u[i]&=h[i];
    }

    for(z=1,m=0;m<n;++m)
        for(i=0;i<n;++i){
            for(v=j=0;j<n;++j)
                v+=u[n*i+j]?(x=j,1):0;
            if(v==1){
                z*=x<6?t[i]:1;
                for(j=0;j<n;++j)
                    u[n*j+x]=0;
                break;
            }
        }

    printf("%ld\n",--c?z:y);
}
