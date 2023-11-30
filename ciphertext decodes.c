#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char findEsubstitution(char ciphertext[]) {
    int count[256] = {0};
    int len = strlen(ciphertext);

    for (int i = 0; i < len; i++) {
        if (isalpha(ciphertext[i])) {
            count[ciphertext[i]]++;
        }
    }
    int maxCount = 0;
    char eSubstitution;

    for (int i = 0; i < 256; i++) {
        if (count[i] > maxCount) { 
            maxCount = count[i];
            eSubstitution = i;
        }
    }

    return eSubstitution;
}
void decryptCiphertext(char ciphertext[], char eSubstitution) {
    int len = strlen(ciphertext);

    for (int i = 0; i < len; i++) {
        if (isalpha(ciphertext[i])) {
            char decryptedChar = (ciphertext[i] - eSubstitution + 26) % 256;
            printf("%c", decryptedChar);
        } else {
            printf("%c", ciphertext[i]); 
        }
    }
    printf("\n");
}
int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    char eSubstitution = findEsubstitution(ciphertext);
    decryptCiphertext(ciphertext, eSubstitution);

    return 0;
}
