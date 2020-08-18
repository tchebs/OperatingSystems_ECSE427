//
// Created by Julianna Tchebotareva on 2019-01-23.
//

//Implement model 2 String Matrix

#include "shellmemory.h"
#include "shell.h"
#include "interpreter.h"

#include<stdlib.h>
#include<string.h>

// Model 2: String matrix
//
char *model2[1000][2] = {NULL}; // var and value separated per row


// Model 2 public functions
//
void m2Set(char *string, char *val) {
    int i = 0;
    for (i = 0; i < 1000; i++) {
        if (model2[i][0] == NULL) {
            model2[i][0] = strdup(string);
            model2[i][1] = strdup(val);
            break;
        }
        else if (strcmp(model2[i][0], string) == 0) {
            model2[i][1] = strdup(val);
            break;
        }
    }
}
char *m2Get(char *var) {
    int i=0;

    for(i=0;i<1000;i++) {
        if (model2[i][0] == NULL)
            break;
        if (strcmp(model2[i][0], var) == 0) {
            return (model2[i][1]);
        }
    }
    return NULL;
}
