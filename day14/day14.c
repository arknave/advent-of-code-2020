#include/* let epsilon */ <stdio.h>
#include/* = fourteen  */<stdlib.h>

//ADVENT OF CODE 2020  DAY NUMBER//
char*p,*q,s[84],t[42],c;long*a,l,r,
i,v,b,y,n,e[14<<18][2],d[14<<18],h;  
void w(long f,long k,long u){if(!~k
){d[f]=r;             return;}long*
x,o=t[k]      ==         49||u&1;if
(t[k]^     88)x=&e[f]      [o],w(!*
x?*x=     ++h:*x,k-1,u/     2);else
for(o    =0;o<2;x=&e[f]      [o++],
w(!*                          x?*x=
++h:    *x,k-1,u/2));;}int main(int
ooo,    char**g){--ooo;for(;gets(//
s);)     {if(s[1]==97)for(p=s+7,q=t
;*p;)     *q++=*p++;else{l=  atol(s
+1*4);     for(p=s+5;*p^61;  ++p);r
=atol(p      +2);for(n=      i=v=0,
b=1;i<36;                  ++i,b*=2
){c=*(q-1-i)           ;v|=(c==49||
(c==88&&(r&b)))*b;y=(l&b)>0;a=&e[n]
[y];n=*a|ooo?/*E*/*a:(*a=++h);}!ooo
?d[n]=v:w(0,35,l);}}for(y=i=0;i<1<<
21;++i)y=y+d[i];printf("%ld\n",y);}
