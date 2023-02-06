#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"get_input.h"
int sign_up(int total, int condition_check[2],char**data, char** username_s, char** password_s, char** roll_s) {
	condition_check[1] = 1;
	int check = 1;
	int repeat = 0;
	//get inputs for username, password and role
	username_s[total] = get_input(check,data);
	if (username_s[total] != "\0") {
		password_s[total] = get_input(check, data);
		if (password_s[total] != "\0") {
			check = 2;
			roll_s[total] = get_input(check, data);
			if (strcmp(roll_s[total], "seller") == 0 || strcmp(roll_s[total], "buyer") == 0) {
				for (int j = 0; j < total; j++) {
					if (strcmp(username_s[total], username_s[j]) == 0 && strcmp(roll_s[total], roll_s[j]) == 0 && total != j) {
						printf("username already used in this roll\n");
						free(roll_s[total]);
						free(password_s[total]);
						free(username_s[total]);
						repeat = 1;
						break;
					}
				}
				if (repeat == 0) {
					printf("signup succeeded!\n");
					condition_check[1] = 2;
				}
			}
			else {
				free(password_s[total]);
				free(username_s[total]);
			}
		}
		else {
			free(username_s[total]);
		}
	}
	return condition_check[1];
}