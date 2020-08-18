//
// Created by Julianna Tchebotareva on 2019-01-23.
//
#include <stdio.h>
#include <string.h>
#include "interpreter.h"
#include "shellmemory.h"
#include "shell.h"

// this class should have the interpreter function
// interpreter accepts a command, and has a corresponding function



int help () {
   printf("COMMAND ------------------ DESCRIPTION\n");
    printf("help ......................displays all commands\n");
    printf("quit ......................terminates the shell\n");
    printf("set  ......................assigns a value to shell memory\n");
    printf("print .....................prints the string assigned to VAR\n");
    printf("run .......................executes a file\n");


    return 0;
}

int quit() {
    printf("Bye!\n");
    return -1;
}

// helper function to use when you want words to point to null
int m3fix(char* words){
    if (words == NULL){
        return 1;
    }
    else
        return 0;
}


int set(char* words[]) {

    if (words[1]==NULL|| words[2]==NULL) {
        printf("Please enter a variable and value after 'set'\n ");
        return 0;
    }
    else {
        m2Set(words[1], words[2]);
    }// set var x
    return 0;

}

int print(char* words[]) {
    if (words[1]==NULL){
        printf("Please enter a variable after 'print' \n");
        return 0;
    }

    if (m2Get(words[1]) == NULL ) {
        printf("Variable does not exist\n");
    }
    else {

        printf("%s\n", m2Get(words[1]));
    }


    return 0;

}

int run(char* words[]) {
    int error =0;

    FILE *textfile;
    textfile = fopen(words[1],"r"); // need to read the file

    if (textfile == NULL){
        printf("Script not found\n");
        return 0;
    }
    char lineinfile[1000] ; //store line from file as a string
        fgets(lineinfile,999,textfile);
        while(!feof(textfile)){ //feof looks for the end of file
            error = parse(lineinfile);
            if (error != 0) {
                fclose(textfile);
                return 0;
            }
            fgets(lineinfile,999, textfile);
        }
    fclose(textfile);


    return 0;

}

//interpreter if statements will be defined here

int interpreter(char *words[]) {



    // the user is asking to execute a single command
    if (strcmp(words[0],"help")==0)
        return help();

    else if (strcmp(words[0],"quit")==0)
        return quit();

    else if (strcmp(words[0],"set")==0)
        return set(words);

    else if (strcmp(words[0],"print")==0)
        return print(words);

    else if (strcmp(words[0],"run")==0)
        return run(words);

    else {
        printf("Unknown command\n");
        return 0;
    }



}


