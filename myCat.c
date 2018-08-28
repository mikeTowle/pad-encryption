/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mike
 *
 * Created on February 17, 2018, 11:24 AM
 * 
 * The first part of the lab is to write a program to read the complete contents of a file to a string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myCat.h"

/*
int main2(int argc, char** argv) {
    char* inputFileName;
    char* outputFileName;
    char* fileContents;


    if (argc < 2) {
        fprintf(stderr, "usage: %s inputFileName outputFileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    inputFileName = argv[1];
    outputFileName = argv[2];


    FILE* file = open_file(inputFileName, "r"); //'r' means read
    fileContents = read_file(10, file);

    FILE* newFile = open_file(outputFileName, "w"); //'w' means write
    //write_file(newFile, fileContents);

    free(fileContents);

    return (EXIT_SUCCESS);
}
*/
/*
 * Reads the complete contents of a file to a string 
 */
char* read_file(int length, FILE* file) {


    long fileSize;
    char* buffer;
    int count = 0;
    int c;

    if (length == 0) {
        if (file) {
            fseek(file, 0, SEEK_END);
            fileSize = ftell(file);
            fseek(file, 0, SEEK_SET);
            buffer = (char*) malloc((fileSize + 1) * sizeof (char));
            if (buffer) {
                fread(buffer, sizeof (char), fileSize, file);
            }
            fclose(file);
        }

        buffer[fileSize] = '\0';

    }


    if (length > 0) {
        if (file) {
            fseek(file, 0, SEEK_END);
            fileSize = ftell(file);
            fseek(file, 0, SEEK_SET);
            buffer = (char*) malloc((length + 1) * sizeof (char));
            while ((c = fgetc(file)) != length || count <= length) {
                buffer[count++] = (char) c;
            }
        }
        buffer[count] = '\0';
    }


    return buffer;
}

/*
 * Writes the complete contents of a string to a file
 */
void write_file(int length, char* contents, FILE* newFile) {

    if (length == 0) {
        int lenContents;

        lenContents = strlen(contents);
        for (int i = 0; i < lenContents; i++) {
            fputc(contents[i], newFile);
        }

    } else {
        for (int i = 0; i < length; i++) {
            fputc(contents[i], newFile);
        }
    }


    //close the file
    fclose(newFile);
}

FILE* open_file(char* sFileName, char* sMode) {
    FILE *file = fopen(sFileName, sMode);
    
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }
    
    return file;
}