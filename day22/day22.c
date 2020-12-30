#include <stdio.h>

typedef struct deck {
    int cards[111],len;
} deck_t;

int pop_deck(deck_t* d){
    int ans = d->cards[0];
    for(int i=0;i+1<d->len;++i){
        d->cards[i]=d->cards[i+1];
    }
    --d->len;
    return ans;
}
void push(deck_t* d,int v){
    d->cards[d->len++]=v;
}
void copy(deck_t*dst,deck_t*src,int k){
    dst->len=0;
    for(int*p=dst->cards,*q=src->cards;k--;++dst->len,++p,++q)
        *p=*q;
}

int game(deck_t* a, deck_t* b,int r){
    deck_t sub1,sub2;
    int x,y,z,i;
    for(i=0;a->len&&b->len;++i){
        if(i>1000)return 1;
        x=pop_deck(a);
        y=pop_deck(b);
        if(r&&x<=a->len&&y<=b->len){
            copy(&sub1,a,x);
            copy(&sub2,b,y);
            z=game(&sub1,&sub2,r);
        }else{
            z=x>y;
        }
        z?(push(a,x),push(a,y)):(push(b,y),push(b,x));
    }
    return a->len;
}

int*p;
char b[99];
deck_t h[2];
int main(int c,char**v){
    gets(b);
    for(p=h[0].cards;scanf(" %d",p++)>0;++h[0].len);
    gets(b);
    for(p=h[1].cards;scanf(" %d",p++)>0;++h[1].len);
    game(&h[0],&h[1],--c);
    deck_t* ans = h+(!!h[1].len);
    long score = 0;
    for(int i=0;i<ans->len;++i){
        score+=(ans->len-i)*ans->cards[i];
    }
    printf("%ld\n",score);
}
