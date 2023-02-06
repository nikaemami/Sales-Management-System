#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"get_input.h"
int get_number(char** data, int check) {
    int condition = 0;
    char* number = get_input(check, data);
    if (number != "\0") {
        while (condition == 0) {
            //check if input is integer
            for (int i = 0; i < strlen(number); i++) {
                if (!isdigit(number[i])) {
                    condition = -1;
                    free(number);
                    break;
                }
            }
            if (condition == 0)
                condition = atoi(number);
            break;
        }
    }
    return condition;
}