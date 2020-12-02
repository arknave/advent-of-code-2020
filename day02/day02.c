#include   <stdio.h>
#include  <stdlib.h>
#include  <string.h>

// AOC DAY NUMBER //
char*s=" %s%s%s";int
main(int argc,char**
argv){char c[99],a[9
],b[9          ];int
y=0             ,z=0
;    while(    scanf
(s,a,b,c)>    0){int
u, h,x=+    strcspn(
a,"-");    a[x]='\0'
;u =+     atoi(a);h=
atoi(    a+x+1); int
f=0;    for(char*k=c
;*k    ;++k){f+=*k==
*b     ;}y+=u<=+f&&f
<=               h;z
+=(             c[--
u]==*b)^(c[--h]==*b)
;}{}/*DAY 2*/printf(
"%d\n",argc-1?z:y);}
