#include   <stdio.h>

// AOC DAY NUMBER //
int a=0,t=1,x;char b
[32],            h[1
<<10   ],*k;int main
(int  c,char**v){for
(--           c;gets
(b) ;)for(x=0    ,k=
b;*k;x=2*x|!(*k   &4
),h[x]=5,a=a>x?   +a
:x,k  ++);for(;   !h
[t-    1]|h[t]|   !h
[t+1   ];)++t;   //V
printf         ("%d"
/*CD*/"\n",c?t:+a);}
