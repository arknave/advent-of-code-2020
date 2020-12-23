#include/*  Pick a cup, any cup.  Choose wisely! */<stdio.h>

//        ADVENT OF CODE 2020 DAY 23 || CRAB CUPS         //
long n[+1<<20],N=1e6,M,i=9,h,g,x,y,z=49;char s[23];int main(
int c,char**v){for(;i<N;++i)n[i]=i+1;gets(s);for(i=0;i<8;++i
)n[s[i]-     z]=s[i+1]-z;--c?M=1e7,n[s[8]-z]=9,     g=N-1:(N
=9,M=+         1e2,g=s[8]-z      );n[g]=h=*s-         z;for(
;M--;           ){x=n[h];          y=n[x];z=           n[y];
g=h;;           for(h;+g            ==h||g==           +x||g
==y||g==z;)g--?0:(g=N-1              );n[h]=n[z];n[z]=n[g];n
[g]=x;h=n[h];}c?x=n[0],/*  DAY 23  */y=n[x],printf("%ld",++x
*++y):0;for(h=n[0];!c&&h;h=n[h])printf("%ld",h+1);puts("");}
