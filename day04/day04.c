#include/* 2 + 2 =*/ <stdio.h>
#include/* 2 * 2 =*/<stdlib.h>

//  AOC 2020 !! DAY NUMBER  //
int main(int r,char**v){char b
[99],d[30][10],*l=b,*k;int h,p
,i,a=0,c=0,f[]={27,16,28,15,11
,6,25},g[]={00,20,13,29,18,17,
20};for(;l;){for(h=0;h<30;++h)
*d[h]=0;for(;(l=      gets(b))
&&l&&*l;)for(k         =b;*k;k
=*k?k+1:k){h=          *k^*(k+
1);k+=4;for(           p=0;+*k
&&*k^32;)d[     h]     [p++]=*
(k++);d[h]     [p]     =0;}for
(i=0,h=0;     l&&i     <7;++i)
h+=*d[f[     i]]>0     ;if(h==
7){++a;     i=1919     ;p=atoi
(d[27]     )-i;h-=     0<p&&p<
84;i      +=90;p=+     atoi(d[
16])     -i;h-=0<p     &&p<12;
i+=                      10;//
p=                        atoi
(d[                       28])
-i;h-=0<p&&p<13-1;     for(k=d
[15];*k;++k);k-=2;     i=*k==+
99;*k=0;p=atoi(d[+     15])-58
;h-=i?91<p&&p<136:     0<p&&p<
19;p=d[11][0]==+35     &&d[11]
[7]==0;;for(k=d[11     ]+1;*k;
++k)p&=(47<*k&&*k<     58)|(96
<*k&&*k<'g');h-=p;     p=d[6][
0]+d[6][2]-100-95;     for(i=0
;i<7&&g[i]^p;++i);h-=i<7&&d[6]
[3]==0;p=0;for(k=d[25];*k;++k)
p+=47<*k&&*k<58;h-=p==9;c+=!h;
}}--r;printf("%d\n",r|r?c:a);}
