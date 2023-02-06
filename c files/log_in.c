#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"get_input.h"
int* log_in(int total, char** data,int* condition_login, char** username_s, char** password_s, char** roll_s) {
		int size = 1;
		char* username_l = NULL;
		char* password_l = NULL;
		char* roll_l = NULL;
		int check = 1;
		int count = 0;
		int check_log = 0;
		//get inputs for username, password and role
		//make sure no user is already logged in
		username_l = get_input(check, data);
		if (username_l != "\0") {
			password_l = get_input(check, data);
			if (password_l != "\0") {
				check = 2;
				roll_l = get_input(check, data);
				for (int j = 0; j < total; j++) {
					if (condition_login[j] == 1) {
						printf("another user is alredy logged in.\n");
						if (roll_l != "\0")
							free(roll_l);
						free(password_l);
						free(username_l);
						check_log = 1;
						break;
					}
				}
				if(check_log==1)
					return condition_login;
				//check if the user has already signed up.
				for (int j = 0; j < total; j++) {
					if ((strcmp(username_l, username_s[j]) == 0) && (strcmp(password_l, password_s[j]) == 0) && (strcmp(roll_l, roll_s[j]) == 0)) {
						printf("login succeeded!\n");
						condition_login[j] = 1;
						count++;
					}
				}
				if (count == 0) {
					if (roll_l != "\0")
						free(roll_l);
					free(password_l);
					free(username_l);
					printf("login failed.try again.\n");
				}
			}
			else {
				free(username_l);
				printf("login failed.try again.\n");
			}
		}
		else {
			printf("login failed.try again.\n");
		}
	return condition_login;
}