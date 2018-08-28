/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cat.h
 * Author: mike
 *
 * Created on February 17, 2018, 4:01 PM
 */

#ifndef MY_CAT_H
#define MY_CAT_H

char* read_file(int length, FILE*);
void write_file(int length, char* contents, FILE* newFile);
FILE* open_file(char*, char*);


#endif /* MY_CAT_H */

