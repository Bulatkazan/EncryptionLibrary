/* example.h*/
#include "arcfour.h"

#define F fflush(stdout);

int main(void );

// ef20 ac12

void printbin(const int8 *input, const int16 size) {
    int16 i;
    const int8 *p;
    // i = 32 aa
    // i = 31 bb

    assert(size > 0);
    
    for(i=size, p=input; i; i--, p++ ) {
        if(!(i % 2))
            printf(" ");
        printf("%.02x", *p);F;

    }
    printf("\n");
}
int main() {
    Arcfour *rc4;
    int16 skey, stext;
    char *key, *from;
    int8 *encrypted, *decrypted;
    
    key = "tomatoess"; /* 8 BITS -> 2048 BITS*/
    skey = strlen(key);
    from = "Shall I compare thee to a summer's day?";
    stext = strlen(from);

    printf("Initializing encryption...");F;
    rc4 = rc4init((int8 *)key, skey);
    printf("done\n");
    
    printf("'%s'\n -> ", from);
    encrypted = rc4encrypt(rc4, (int8 *)from, stext);
    // printbin((int8 *)key, skey);
    // printf("\n");
    // printbin(rc4->s, skey);
    printbin(encrypted, stext);
    
    rc4uninit(rc4);
    printf("Initializing decrypted...");F;
    rc4 = rc4init((int8 *)key, skey);
    printf("done\n");

    decrypted = rc4encrypt(rc4, encrypted, stext);
    printf("   -> '%s'\n", decrypted);
    rc4uninit(rc4);
    free(encrypted);
    free(decrypted);
    return 0;
}