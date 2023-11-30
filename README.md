#include <stdio.h>

void encrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] + key - 'A') % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] + key - 'a') % 26 + 'a';
        }
    }
}
int main()
{
    char message[100];
    int key;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key: ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);      
    return 0;
}
