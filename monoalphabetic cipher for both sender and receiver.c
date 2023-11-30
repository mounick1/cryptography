#include <stdio.h>
#include <string.h>
#include <ctype.h>
void generateCipherSequence(char keyword[], char cipherSequence[]) {
    int keywordLength = strlen(keyword);
    char keyAlphabet[26];
    int index = 0;
    for (int i = 0; i < keywordLength; ++i) {
        char currentChar = toupper(keyword[i]);
        if (isalpha(currentChar) && strchr(keyAlphabet, currentChar) == NULL) {
            keyAlphabet[index++] = currentchar;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ++ch)  {
        if (strchr(keyAlphabet, ch) == NULL) {
            keyAlphabet[index++] = ch;
        }
    }
    strcpy(cipherSequence, keyAlphabet);
}
void encryptMonoalphabetic(char plaintext[], char cipherSequence[], char ciphertext[]) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; ++i) {
        if (isalpha(plaintext[i])) {
            char currentChar = toupper(plaintext[i]);
            int index = currentChar - 'A';
            if (isupper(plaintext[i])) {
                ciphertext[i] = cipherSequence[index];
            } else {
                ciphertext[i] = tolower(cipherSequence[index]);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[length] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[1000];
    printf("Enter a plaintext message: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    strtok(plaintext, "\n");
    char cipherSequence[26];
    generateCipherSequence(keyword, cipherSequence);
    char ciphertext[1000];
    encryptMonoalphabetic(plaintext, cipherSequence, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}
