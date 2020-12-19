#include   <stdio.h>
#include  <stdlib.h>
#include  <string.h>

// AOC DAY NUMBER //
int x[888],e,i,g,h,t
,n;char b[888][9],s[
888];int main(int c,
char**v      ){for(;
gets(          b[n])
;x[   n+!!0]=   atoi
(b    [n]+8/2),  ++n
);   for(i=-1;!  t&&
i<    n;e>=n?t   =g:
!~i    ?h=g:8   ,++i
){for(        memset
(s,0,          888),
e=g=    0;e<    +n&&
!s    [e];++e)   {s[
e]   =1;b[e][0   ]==
97   ?g+=x[e]:   i==
e^b   [e][0]==  'j'?
e+=             x[e]
-1:8;}       }printf
("%d\n",~~--c?t:h);}
