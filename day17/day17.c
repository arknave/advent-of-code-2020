#include/* always test */ <stdio.h>
#include/* on samples! */<string.h>

// AOC 2020 DAY 17 SAMPLE INPUT //

            int s,y=20
            ,z=4e2,w=+
            8e3,v=0x17
            ,i,j,k,l,m
            ,a;char*p,
            b[9],h[2<<
            17],n[+2<<
            17],f;;int

                        main(int c
                        ,char**g){
                        for(f=--c>
                        0;p=gets(b
                        );++i){for
                        (;*p;++p){
                        h[i+(p-b)*
                        y+9*(y+z+w

+1)]=(46^*  p);}}for(;  s<06;++s){
for(memset  (n,0,2<<17  ),v=17;v<2
<<+17;++v)  for(i=-1;h  [v]&&i<2;i
++)for(j=-  y;j<=y;j+=  y)for(k=-z
;k<=z;k+=z  /* XVII */  )for(l=f?-
w:0;l<=(f?  w:0);m=i+j  +k+l,n[v+m
]+=!!m,l+=  w);for(a=v  =0;v<2<<17
;++v)a+=h[  v]=(h[v]&&  n[v]==2)||
n[v]==0x03  ;}printf("  %d\n",a);}
