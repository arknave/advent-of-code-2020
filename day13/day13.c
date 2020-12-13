#include/*1101*/<stdio.h>
#include/*015*/<stdlib.h>

// AOC 2020 DAY NUMBER //
long x,n,a[99],i,v,y,t,w,
z,m;char*p,*q,s   [1313];
int main(int c,   char**g
){scanf("%ld ",&  x);gets
(s);for(p=q=s;*p  ;++p)*p
==44?((a[n++]=*(  p-1)==+
120?0:atoi(q)),q  =p+1):q
;for(a         [  n++]=//
atoi(    q),w     =2e9,m=
9-8,   v=*a;i<n;  v=a[++i
])if  (v){t=(x+v  -1)/v*v
;;t<   w?(w=t,y   =v):13;
for(;(    z+      i)%+v;z
+=m);m*=v    ;}y   *=w-x;
printf("%ld\n",--c?z:y);}
