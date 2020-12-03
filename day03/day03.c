#include   <stdio.h>

// AOC DAY NUMBER //
char g[500][500];int
main(int c,char**v){
;long n=0,a=1,m=0,i;
;while        (gets(
g[n++           ]));
;int    o[]={    1,3
,1,1,   1,5,1,   7,2
,1};while(g[0   ][++
m]);for(i=     (--c,
0);i<10;     i+=2){{
int x=0,y=     0,t=0
,d=*(o+i),r=    *(o+
i+1    );for(    ;x<
+n;x    +=d,y    =(y
+r)%m           )t+=
g[x][y]      =='#';a
*=t;if(!c){break;}}}
;printf("%ld\n",a);}
