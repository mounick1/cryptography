#include <stdio.h>
#include <string.h>
#include <ctype.h>
void encrypt(char message[], char key[]) {
    int i;

    for (i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) 
		{
            int isUpperCase = isupper(message[i]);

           
            char letter = toupper(message[i]);

            if (isUpperCase) {
                message[i] = key[letter - 'A'];
            } else {
                message[i] = tolower(key[letter - 'A']);
            }
        }
    }
}

int main() 
{
    char message[100];
    char key[26];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key (26 unique uppercase letters): ");
    fgets(key, sizeof(key), stdin);
    strtok(message, "\n");
    strtok(key, "\n");
    if (strlen(key) != 26) {
        printf("Invalid key length. Please enter 26 unique uppercase letters.\n");
        return 1;
    }
for (int i = 0; i < 26; ++i) {
        if (!isalpha(key[i]) || islower(key[i])) {
            printf("Invalid key format. Please enter 26 unique uppercase letters.\n");
            return 1;
        }
        for (int j = i + 1; j < 26; ++j) {
            if (key[i] == key[j]) {
                printf("Invalid key. Each letter in the key must be unique.\n");
                return 1;
            }
        }
    }
    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}
