/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   otpencryption.c
 * Author: mike
 *
 * Created on February 17, 2018, 3:58 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "myCat.h"


void get_file_name(char *);
char* make_rand_key(int length, char* key);
void encrypt(char* clearText, char* randKey, FILE* cipherFile);
char* decrypt(FILE* cipherFile, char* randKey);

/*
 * 
 */
int main(int argc, char** argv) {

    int menuOption;
    char inFilename[100];
    FILE* inFile;
    char* inFileContents;
    FILE* outFile;
    char outFilename[100];
    char* message;
    char* randKey;
    FILE* cipherFile;

    randKey = make_rand_key(12, randKey);

    do {
        
        printf("Menu Options: Please Enter Corresponding Number\n----------"
                "--------------------\n");
        printf("1. Encrypt File\n2. Decrypt File\n3. Exit Program\n");
        scanf("%d", &menuOption);
        
        switch (menuOption) {

            case 1: 
                //use message.txt -> 'hello there'
                get_file_name(inFilename);
                inFile = open_file("message.txt", "r");
                inFileContents = read_file(0, inFile);
                cipherFile = open_file("newcipherText.txt", "w");
                encrypt(inFileContents, randKey, cipherFile);
                printf("Your File Has Been Encrypted to file: newcipherText.txt\n");
                break;

            case 2:

                get_file_name(outFilename);
                outFile = open_file(outFilename, "r");
                message = decrypt(outFile, randKey);
                printf("\nYour Message Was: %s ", message);
                free(message);
                break;

            case 3:

                return (EXIT_SUCCESS);

        }
        
    } while (1);

    
       
    return (EXIT_SUCCESS);
}



//returns stream to file

void get_file_name(char *fileName) {

    printf("Enter a File Name: ");
    scanf("%s", fileName);

}

/*
 * Generates and returns a random key of length chars
 */
char* make_rand_key(int length, char* key) {

    srand(time(NULL));
    key = (char*) (malloc(length + 1));
    for (int i = 0; i < length; ++i) {
        key[i] = (char) (rand() % 255 + 1);
    }
    key[length] = '\0';

    return key;

}

void encrypt(char* clearText, char* randKey, FILE* cipherFile) {

    int contentLength = strlen(clearText);
    char* cipherText = (char*) (malloc(contentLength + 1));

    int i;

    for (i = 0; i < contentLength; i++) {
        char temp = clearText[i] ^ randKey[i];
        cipherText[i] = temp;
    }

    cipherText[i] = '\0';


    //write cipherContexts to cipherFile
    write_file(0, cipherText, cipherFile);
    free(cipherText);
}

char* decrypt(FILE* cipherFile, char* randKey) {
    char* cipherContents = read_file(0, cipherFile);
    int contentLength = strlen(randKey);
    char* message = (char*) (malloc(contentLength + 1));
    int i;

    for (int i = 0; i < contentLength; i++) {
        char temp = cipherContents[i] ^ randKey[i];
        message[i] = temp;
    }

    message[i] = '\0';
    
    return message;
}




