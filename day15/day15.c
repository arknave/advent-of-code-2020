#include <stdio.h>

int a[45151515],n,x,v,m;
int main(int c, char**g){
    for(m=--c?3e7:2020;scanf("%d%*c",&x)>0;a[x]=++n);
    for(a[x]=0;n<m;v=a[x]?n-a[x]:0,a[x]=n++,x=v);
    printf("%d\n",v);
}
