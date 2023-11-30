#include <stdio.h>
#include <string.h>
#include <ctype.h>  
void encrypt(char message[], char key[]) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    char encryptedMessage[messageLength];

    for (int i = 0, j = 0; i < messageLength; ++i) {
        char currentChar = message[i];

        if (isalpha(currentChar)) {
            int isUpperCase = isupper(currentChar);

            char letter = toupper(currentChar);

            char shiftedChar = (letter + key[j] - 2 * 'A') % 26 + 'A';

            encryptedMessage[i] = isUpperCase ? shiftedChar : tolower(shiftedChar);

            j = (j + 1) % keyLength;
        } else {
            encryptedMessage[i] = currentChar;
        }
    }

    encryptedMessage[messageLength] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);
}

int main() {
    char message[1000], key[100];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);

    strtok(message, "\n");
    strtok(key, "\n");

    encrypt(message, key);

    return 0;
}
