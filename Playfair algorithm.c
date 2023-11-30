#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void generateMatrix(char key[], char matrix[SIZE][SIZE]) {
    int i, j, k;
    char letters[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";  

    int keyLength = strlen(key);
    char uniqueKey[keyLength];
    int index = 0;

    for (i = 0; i < keyLength; ++i) {
        if (strchr(uniqueKey, key[i]) == NULL) 
		{
            uniqueKey[index++] = key[i];
        }
    }           
    k = 0; 
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (k < index) {
                matrix[i][j] = toupper(uniqueKey[k++]);
            } else {
                while (strchr(uniqueKey, letters[index]) != NULL) {
                    ++index;
                }
                matrix[i][j] = letters[index++];
            }
        } 
    }
}
void findPosition(char matrix[SIZE][SIZE], char ch, int pos[2]) {
    int i, j;

    if (ch == 'J') {
        ch = 'I';  
    }

    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (matrix[i][j] == ch) {
                pos[0] = i;
                pos[1] = j;
                return;
            }
        }
    }
}
void encryptPair(char matrix[SIZE][SIZE], char pair[2], char encryptedPair[2]) {
    int pos1[2], pos2[2];
    findPosition(matrix, pair[0], pos1);
    findPosition(matrix, pair[1], pos2);

    if (pos1[0] == pos2[0]) {
        encryptedPair[0] = matrix[pos1[0]][(pos1[1] + 1) % SIZE];
        encryptedPair[1] = matrix[pos2[0]][(pos2[1] + 1) % SIZE];
    }
    else if (pos1[1] == pos2[1]) {
        encryptedPair[0] = matrix[(pos1[0] + 1) % SIZE][pos1[1]];
        encryptedPair[1] = matrix[(pos2[0] + 1) % SIZE][pos2[1]];
    }
    else {
        encryptedPair[0] = matrix[pos1[0]][pos2[1]];
        encryptedPair[1] = matrix[pos2[0]][pos1[1]];
    }
}

void playfairEncrypt(char message[], char key[]) {
    char matrix[SIZE][SIZE];
    char encryptedMessage[1000];
    int i, j, k;

    generateMatrix(key, matrix);

    for (i = 0, k = 0; message[i] != '\0'; ++i) {
        char pair[2] = {message[i], '\0'};
        char encryptedPair[2];

        if (message[i] == 'J') {
            pair[0] = 'I'; 
        }

        if (message[i] == message[i + 1]) {
            pair[1] = 'X';
            ++i;
        } else {
            pair[1] = message[i + 1];
            i += 2;
        }

        encryptPair(matrix, pair, encryptedPair);

        encryptedMessage[k++] = encryptedPair[0];
        encryptedMessage[k++] = encryptedPair[1];
    }

    encryptedMessage[k] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);
}

int main() {
    char message[1000], key[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter a keyword: ");
    fgets(key, sizeof(key), stdin);

    strtok(message, "\n");
    strtok(key, "\n");

    playfairEncrypt(message, key);

    return 0;
}
