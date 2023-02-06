#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sign_up.h"
char* get_input(int check, char** input) {
	//allocate memory and check that it won't leak
	*input = NULL;
	*input = (char*)malloc(sizeof(char));
	char* alter = (char*)malloc(sizeof(char));
	alter = *input;
	//get input until it is space or newline
	if ((*input) != NULL)
	{
		char character;
		int length = 0;
		while ((character = getchar()) && character != ' ' && character != '\n') {
			alter[length] = character;
			length++;
			alter = (char*)realloc(alter, sizeof(char) * (length+1));
			alter[length] = '\0';
		}
		//check if 4 words are entered
		if (character == '\n' && check == 1 && strcmp(alter,"show_goods\0")!=0 && strcmp(alter, "view\0") != 0 && strcmp(alter, "logout\0") != 0 && strcmp(alter, "exit\0") != 0){
			alter = "\0";
		}
		else
		alter[length] = '\0';
	}
	return alter;
}

