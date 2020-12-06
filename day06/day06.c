#include <stdio.h>
#include <stdlib.h>

// AOC DAY NUMBER //
int main(int c,char*
*v){int       t,p,q;
char           b[66]
,h[    66],*k   ,*l=
b,*   e=h+26;for(p=q
=0   ;l;   ){for(k=h
;k            <e;++k
)*    k=0;for   (t=0
;(   l=gets(b   ))&&
*l   ;++t)for(  k=l;
*k;   ++k)++h   [-97
+*k];          for(k
=h;k<e;     ++k){p+=
*k>0;q+=*k==t;}}--c;
printf("%d",c?q:p);}
