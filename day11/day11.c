#include/* eleven? */<stdio.h>

// ADVENT OF CODE 2020  DAY //
char*p,*q,n,m,a[121][121],b[11
*11][121],(*l)[121],(*r)[121];
int f,t,y,o,i,j,v,w,g,h,k=043; 
int     main(int c,char**d){//
;for(   n=+1;gets(b[n++]+1););
for(p   =b[1]+(m=1);*p;++p,++m
);for   (i=0;i<n;++i)b[i][0]=b
[i][m   ]=76;for(--n,j=0;j<=m;
++j)b   [0][j]=b[n][j]=76;for(
--c,f   =1;f        ;t=!t){l=t
?a:b;                   r=t?b:
a;for     (f=y=0,i=1     ;i<n;
!!++i   )for(j=1;j<m;p    =&l[
i][j]   ,q=&r[i][j],y+=   k==(
*q=*p   ==k?o>=4+!!c?76   :k:*
p==76   ?!o?k:76:*p),f    |=*q
^+*p,    ++j)for(o=0,    v=-1;
v<=1*                  +1;++v)
for(w   =-1          ;w<2;o+=(
v|w++)&&l[g][h]==k)if(g=i+v,h=
j+w,(v|w)&&c)for(;l[g][h]==46;
g+=v,h+=w);}printf("%d\n",y);}
