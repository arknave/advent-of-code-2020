#include   <stdio.h>
#include  <stdlib.h>
#include  <string.h>

// AOC DAY NUMBER //
char*s=" %s%s%s";int
main(int g,char**v){
char c[99],a[9],b[9]
,*k;/**/int y=0,z=0;
while(       scanf(s
,a,b           ,c)>0
){     int u,    h,x
=strcspn(a,"-"    );
;a[x]=0;u=atoi    (a
);h=atoi(a+     x+1)
;int f=0;     for (k
=c;*k;     ++k){f+=*
k==      *b;}y+=u<=f
&&f              <=h
;z              +=(c
[--u]/*DAY2*/==*b)^(
c[--h]==*b);}printf(
"%d\n", --g?+z:+y);}
