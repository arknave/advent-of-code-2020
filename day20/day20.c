#include <stdio.h>
#include <stdlib.h>

long s[150],l[15][15][2],n,k,i,j,S=10,d,y,F[]={1,8,6},M[][8]={{18},{0,5,6,11,12,17,18,19},{1,4,7,10,13,16}},x,m,z,t;
char(*p)[15],b[20],e[150][8][15][15],f[8][200][200],u[150];
long dfs(int r,int c){
    long*h,o=0,g=0;
    if(c==d)
        o=dfs(r+1,0);
    else if(r==d)
        o=1;
    else{
        for(;!o&&g<n;++g){
            if(!u[g]){
                u[g]=1;
                *l[r][c]=g;
                h=&l[r][c][1];
                for(*h=0;!o&&*h<8;++*h){
                    p=e[g][*h];
                    for(i=0;i<S;++i)
                        for(j=0;j<S;++j)
                            f[0][S*r+i][S*c+j]=p[i][j];

                    for(k=1,i=0;i<S;++i)
                        k&=!r||f[0][S*r-1][S*c+i]==f[0][S*r][S*c+i],
                        k&=!c||f[0][S*r+i][S*c-1]==f[0][S*r+i][S*c];

                    if(k&&dfs(r,c+1))
                        o=1;
                }
                --*h;
                u[g]=0;
            }
        }
    }
    return o;
}

int main(int c,char**r){
    for(;gets(b);n++){
        s[n]=atoi(b+5);
        for(p=e[n][0];gets(*p)&&**p;++p);
        for(k=1;k<8;++k)
            for(i=0;i<S;++i)
                for(j=0;j<S;++j)
                    e[n][k][i][j]=k&1?e[n][k-1][i][S-1-j]:e[n][k-1][j][i];
    }
    for(;d*d<n;++d);
    dfs(0,0);

    for(y=1,i=0;i<d;i+=d-1)for(j=0;j<d;j+=d-1)y*=s[*l[i][j]];
    --c?0:printf("%ld\n",y);
    y=d*(S-=2);
    for(i=0;i<d;++i)
        for(j=0;j<d;++j)
            for(z=1;z<=S;++z)
                for(m=1;m<=S;++m)
                    t+=(f[0][S*i+z-1][S*j+m-1]=e[*l[i][j]][l[i][j][1]][z][m])=='#';
    for(k=0;z=0,k<8;++k){
        for(i=0;i<y-2;++i)
            for(j=0;j<y-19;++j){
                for(x=0,m=0;x<3;++x)
                    for(n=0;n<F[x];++n)
                        m+=f[k][i+x][j+M[x][n]]=='#';
                z+=m==15;
            }
        z&&c?printf("%ld\n",t-15*z):0;
        if(k+1<8)
            for(i=0;i<y;++i)
                for(j=0;j<y;++j)
                    f[k+1][i][j]=k&1?f[k][j][i]:f[k][i][y-1-j];
    }
}
