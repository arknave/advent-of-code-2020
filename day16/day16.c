#include/*  Your train ticket (the puzzle input) has all  */ <stdio.h>
#include/*  its fields encoded in hexadecimal or binary!  */<stdlib.h>

//           ADVENT OF CODE 2020 DAY 16 || TICKET TRANSLATION       //
long*p,s[32][4],a[333][32],h[512],u[512],t[32],n,i,j,m,x,v,y,z;char*l,
b[999];int main(int c,char**g){for(p=*s;(l=gets(b))&&*l;p=s[++n]){for(
;*l^':'                 ;++l);*p++=+                         atoi(l+2)
;for(/*   DATE:: 0x89   */;*l^'-';/*   PLATFORM:: 00111011   */++l);*p
++=atoi                 (l+1);for(;*                         l^'r';++l
);*p++=atoi(l+2);for(;*l^'-';++l);*p++=atoi(l+1);}gets(b);for(l=gets(b
),--c;*l;*l?++l:0){t[i++]=atoi(l);for(;*l&&*l^',';++l);}for(p=u;p<u+n*
n;++p)*                 p=1;gets(b);                         gets(b);;
for(4/*   TIME:: 0x8b   */;gets(b)/*   LOCATION:: 00110101   */&&*b;){
for(z=1                 ,p=a[m++],l=                         b,i=0;*l;
*l?++l:0,++i,v=0){*p++=x=atoi(l);for(;*l&&*l^',';++l);for(j=0;j<n;++j)
v|=(h[n*i+j]=(s[j][0]<=x&&x<=s[j][1])||(s[j][2]<=x&&x<=s[j][3]));v?0:(
y+=x);z                 &=v;}for(i=0                         ;z&&i<n*n
;++i)/*  TRACK:: 0x65   */u[i]&=h[/*    STATION:: 00111101   */i];}for
(z=1,m=                 0;m<n;++m,8)                         for(i=0;i
<n;++i){for(v=j=0;j<n;++j)v+=u[n*i+j]?(x=j,1):0;if(v==1){z*=x<6?t[i]:1
;for(j=0;j<n;++j)u[n*j+x]=0x10^020^0x0;break;}}printf("%ld\n",c?z:y);}
