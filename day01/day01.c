#include   <stdio.h>
#include  <stdlib.h>

// AOC DAY NUMBER //
const int M=2020,D=9
;char b[D],h[M];main
(int c,char **v){int
x,i,j,a=0;  /**/FILE
*f=fopen    ("01.in"
,"r");      ;;while(
fgets(b,D   ,f)){;x=
atoi(b);;   if(x<M){
h[x]=1;}}   for(i=0;
i<M;++i){   for(j=i;
j<M;++j){   if (h[i]
&&h[j] &&   i+j<=M){
if(c==1){   if(i+j==
M)a=i*j;}   else if(
h[M-             i-j
])a=             i*j
*(M-i-j);}}}fclose(f
);printf("%d\n",a);}
