#include   <stdio.h>
#include  <stdlib.h>

// AOC DAY NUMBER //
/**/const int M=2020
;char h[M];int main(
int c,char  **v){int
x,i,j,a=    0;while(
scanf       (" %d",&
x)>0)if(    x<M){h[x
]=1;}for    (i=0;i<M
; ++i) {    for(j=i;
j<M;++j)    {if(h[i]
&&h[j]&&    i+j<=M){
if(c==1)    {if (i+j
==M)a=i     *j;}else
if(h            [M-i
-j])a=i*j*(M-i-j);}}
}printf("%d\n",a);;}
