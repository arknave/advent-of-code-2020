#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int*x,*w,i,j,n,m,y,z,f[2][999],a[999][999],d[999];
char*p,*q,*r,*s,b[999],g[999][10],l[99][10];
int main(int c, char**v) {
    for(;gets(b)&&*b;){
        for(p=q=b,x=d;*p!='(';++p)
            if(*p==' '){
                for(i=0,z=-1;!~z&&i<n;z=r==p?i:z,++i)
                    for(r=q,s=g[i];r<p&&*r==*s;++r,++s);
                if(!~z)
                    for(r=q,s=g[z=n++];r<p;)
                        *s++=*r++;

                ++f[0][*x++=z];
                q=p+1;
                ++y;
            }
        for(q=p+=10;*p;++p)
            if(*p==','||*p==')'){
                for(i=0,z=-1;!~z&&i<m;z=r==p?i:z,++i)
                    for(r=q,s=l[i];r<p&&*r==*s;++r,++s);
                if(!~z)
                    for(r=q,s=l[z=m++];r<p;)
                        *s++=*r++;
                ++f[1][z];
                for(w=d;w<x;++w)
                    ++a[*w][z];
                q=p+2;
            }
    }
    for(*d=i=0;i<n;y-=d[i]*f[0][i],d[++i]=0)
        for(j=0;j<m;++j)
            d[i]|=a[i][j]=a[i][j]==f[1][j];
    !--c?printf("%d\n",y):0;

    for(j=0;j<m;++j)
        for(i=0;i<n;++i){
            for(z=0,x=a[i];x<a[i]+m;++x)
                z+=*x;
            if(z==1){
                for(z=0;!a[i][z];++z);

                d[z]=i;
                for(y=0;y<n;++y)
                    a[y][z]=0;
                break;
            }
        }
    for(j=0;c&&j<m;*l[y]='{',printf("%s%c",g[d[y]],",\n"[++j==m]))
        for(i=y=0;i<m;i^y&&*p-*q<0?y=i:0,++i)
            for(p=l[i],q=l[y];i^y&&*p==*q;++p,++q);
}
