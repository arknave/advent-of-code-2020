#include/* count black tiles */<stdio.h>

// ADVENT OF CODE 2020 || DAY 24: HEX //
int x,y,p,t=100,f,v,w,N=399;char*l,b[99]
,s[400][400];int main(int c,char**g){for
(;gets(b)&&*b;(s[x][ y]^=1)?++p:--p)for(
x=y=t+t,l=b;*l;++l     ){y-=*l=='n';y+=*
l=='s';*l=='e'            ||*l=='n'&&*(l
+1)=='e'?++x                 :*l=='w'||*
l=='s'&&*                       (l+01)== 
'w'?--                             x:0;l
+=*l==                             'n'||
*l==23                             *05;}
for(f=                             --c;f
&&t--;                             ){for
(x=1;x                             <N;++
x)for(                             y=1;y
<N;s[x][y                       ]|=(p==2
||s[x][y]&&p                 ==1)<<1,++y
)for(p=0,v=-1;v           <=1;++v)for(w=
-1;w<=1;++w)p+=v!=     w&&s[x+v][y+w]%2;
for(p=x=+0;x<+N;++x) for(y=0;y<N;++y)p+=
s[x][y]>>=24/1/2/3/4;}printf("%d\n",p);}
