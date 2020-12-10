#include/*surprise!*/<stdio.h>
#include/* we hex */<stdlib.h>

// ADVENT OF CODE 2020  DAY //
long*p,*q,y,t,e,n,a[110],b[110
];int main(          int c,//X
char**v){               for(n=
2,p=a+1;    scanf("%ld"   ,p)>
0;++p,++n);for(e=0;e<n;   ++e)
for(q=a;q+1<p;++q)if(     *q>*
(q+1))*q^=*               (q+1
)^=*q^=*             (q   +1);
*p=*(p-    1)+3;for(q=a   ;q<p
;e=*(q   +1)-*q,e==1?++   y:+e
==3?t    ++:0,++q);y*=t   ;for
(*b=1,    e=1;e<n;++e)   for(q
=a;q<a+e                  ;++q
)b[e]+=3/(a         [e]-   *q)
?b[q-a]:0;/*#TEN#*/10-t-e-n--;
printf("%ld\n",--c?b[n]:*&y);}
