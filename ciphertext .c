#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
void frequencyAnalysis(char ciphertext[], char frequencyTable[]) {
    int count[256] = {0}; 
    int len = strlen(ciphertext);

    for (int i = 0; i < len; i++) {
        if (isalpha(ciphertext[i]) || isdigit(ciphertext[i])) {
            count[ciphertext[i]]++;
        }
    }
    int maxCount = 0;
    char mostFrequentChar;

    for (int i = 0; i < 256; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mostFrequentChar = i;  
        }
    }  
    int offset = mostFrequentChar - 'E';
    for (int i = 0; i < 256; i++) {
        frequencyTable[i] = (char)((i - offset + 256) % 256);
    }
}
void decryptCiphertext(char ciphertext[], char frequencyTable[]) { 
    int len = strlen(ciphertext);

    for (int i = 0; i < len; i++) {
        if (isalpha(ciphertext[i]) || isdigit(ciphertext[i])) {
            printf("%c", frequencyTable[ciphertext[i]]);
        } else {
            printf("%c", ciphertext[i]);
        }
    }

    printf("\n");
}

int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    char frequencyTable[256];
    frequencyAnalysis(ciphertext, frequencyTable);
    decryptCiphertext(ciphertext, frequencyTable);

    return 0;
}
