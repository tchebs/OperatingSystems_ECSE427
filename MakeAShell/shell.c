/**
 * Julianna Tchebotareva 260761726
 * ECSE 427 - Assignment 1
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interpreter.h"
#include "shellmemory.h"
#include "shell.h"


//shell file includes  the main() and parse () functions


int parse(char ui[]) {

    int a,b;
    int w =0;
    char tmp[200];
    char *words[1000]; //char* = string

    for(a=0; ui[a]==' ' && a<1000; a++); //skip white spaces

    while(ui[a] != '\0' && a<1000) {
        for (b=0; ui[a]!='\0' && ui[a]!=' ' && a<1000 && ui[a]!='\n' && ui[a]!='\r'; a++, b++ )
            tmp[b] =ui[a]; //extract a word

        tmp[b] = '\0'; // all words end in \0

        words[w] =strdup(tmp); //
        a++; //move to next letter in input
        w++; //move to next word
    }

    return interpreter(words);
}


int main() {

    printf("Welcome to the Julianna Tchebotareva shell!\n"
           "Version 1.0 Created January 2019\n");
    char prompt[100] = {'$', '\0'}; // \0 is equivalent to end of word
    char userInput[1000]; //allows 1000 chars
    int errorCode =0;

    while(1) {
        printf("%s", prompt);
        fgets(userInput, 999, stdin); //stores user input in a variable userInput


        errorCode = parse(userInput);
        if(errorCode == -1)
            break;
    }
    return 0;

}


// result of parse is sent to interpreter