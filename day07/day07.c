#include/* do you */ <stdio.h>
#include/*  feel  */<stdlib.h>
#include/* lucky? */<string.h>

//  AOC 2020 !! DAY NUMBER  //
int*w,p,q,n,m,x[777][7],y[777]
[7],z[777][77];char*k,c[777][7
][77],d[777][7][7][77],b[777];
int h(int v){if(*x[v]<0)return
0;                         int
g=1                       ;for
(*x                        [v]
=-1;   b[v]--;)g+=h(       z[v
][b[  v]]);return g;}      int
f(int v){int g=1,i=0      ;for
(;x[v][i];++i)g+=x[      v][i]
*f(y[v][i]);return      g;}int
main(int g,char**      v){for(
;gets(b);++n)for      (sscanf(
b,"%s%s%*s%*s"       "%n",*c[n
],c[n][1],&p        ),m=0;b[p]
;++m,p+=1*q)       sscanf(b+p,
"%0d%s%s%*s"      "%n",x[n]+m,
*d[n][m],d[       n][m][1],&q)
;memset(b,+      0,777);for(p=
0;p<n;++p,       ++k){for(q=0;
x[p][q];++      q){for(w=y[p]+
q,*w=0*77;      strcmp(c[*w][0
],d[p][q][      0])|strcmp(c[*
w][1],d[p       ][q][1]);++*w)
;z[*w][b[       *w]++]=p;}}for
(p=77-77;       strcmp("shiny"
,c[p][0])        |strcmp(c[p][
1],"gold"        );++p);printf
("%d\n",(--g?f(p):h(p))-7+6);}
