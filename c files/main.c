#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"get_input.h"
#include"sign_up.h"
#include"log_in.h"
#include"struct_buyer.h"
#include"struct_seller.h"
#include"buyer_initialize.h"
#include"seller_initialize.h"
#include"struct_selling_goods.h"
#include"struct_buying_goods.h"
#include"get_number.h"
#include"add_goods.h"
#include"show_goods.h"
#include"buy.h"
#include"view.h"
int main() {
	char c;
	int size = 1;
	//allocating memories which will be used during the program,and temporary memories to make sure the main memories won't leak.
	char** data = (char**)malloc(size * (sizeof(char*)));
	char** temp1 = (char**)malloc(size * sizeof(char*));
	char** temp2 = (char**)malloc(size * sizeof(char*));
	char** temp3 = (char**)malloc(size * sizeof(char*));
	char** username_s = (char**)malloc(size * sizeof(char*));
	char** password_s = (char**)malloc(size * sizeof(char*));
	char** roll_s = (char**)malloc(size * sizeof(char*));
	username_s = temp1;
	password_s = temp2;
	roll_s = temp3;
	if (temp1==NULL|| temp2 == NULL|| temp3 == NULL) {
		printf("memory allocation error.\n");
		return 0;
	}
	else {
		//allocating memories which will be used during the program,and temporary memories to make sure the main memories won't leak.
		int* temp_login = (int*)malloc(size * sizeof(int));
		int* condition_login = (int*)malloc(size * sizeof(int));
		condition_login = temp_login;
		int total = 0, num = 0;
		int* tedad_temp1 = (int*)malloc(size * (sizeof(int)));
		int* tedad_goods_sell = (int*)malloc(size * (sizeof(int)));
		int* tedad_temp2 = (int*)malloc(size * (sizeof(int)));
		int* tedad_goods_buy = (int*)malloc(size * (sizeof(int)));
		tedad_goods_sell = tedad_temp1;
		tedad_goods_buy = tedad_temp2;
		int num_b = -1, num_s = -1;
		int check = 1,log;
		int deposit_check = 0;
		int condition_check[2];
		condition_check[1] = 1;
		struct buyer* tempb = (struct buyer*)malloc(size * sizeof(struct buyer));
		struct buyer* BUYER = (struct buyer*)malloc(size * sizeof(struct buyer));
		BUYER = tempb;
		struct seller* temps = (struct seller*)malloc(size * sizeof(struct seller));
		struct seller* SELLER = (struct seller*)malloc(size * sizeof(struct seller));
		SELLER = temps;
		while (condition_check[1] != 10) {
			log = 0;
			char* INPUT = get_input(check, data);
			if (INPUT != NULL) {
				if (strcmp(INPUT, "signup") == 0) {
					for (int j = 0; j < total; j++) {
						if (condition_login[j] == 1) {
							printf("one user is already logged in.\n");
							log = 1;
							break;
						}
					}
					if (log ==1) {
						free(INPUT);
						continue;
					}
					//for checking that realloc will not leak
					username_s = (char**)realloc(username_s, sizeof(char*) * (total + 2));
					password_s = (char**)realloc(password_s, sizeof(char*) * (total + 2));
					roll_s = (char**)realloc(roll_s, sizeof(char*) * (total + 2));
					condition_check[1] = sign_up(total, condition_check, data, username_s, password_s, roll_s);
					if (condition_check[1] == 1) {
						printf("signup failed.try again.\n");
					}
					if (condition_check[1] == 2) {
						//add a pointer to struct buyer and allocate memory if the role is buyer
						if (strcmp(roll_s[total], "buyer") == 0) {
							num_b++;
							if (tempb != NULL) {
								BUYER = (struct buyer*)realloc(BUYER, sizeof(struct buyer) * (num_b + 1));
								BUYER = buyer_initialize(num_b, total, data, BUYER, roll_s, username_s);
								BUYER[num_b].goods_buy = (struct buying_goods*)malloc(size * sizeof(struct buying_goods));
								if (BUYER[num_b].goods_buy == NULL) {
									printf("memory allocation error.\n");
									return 0;
								}
							}
							if (tedad_temp2 != NULL) {
								tedad_goods_buy = (int*)realloc(tedad_goods_buy, (num_b + 1) * (sizeof(int)));
								tedad_goods_buy[num_b] = 0;
							}
						}
						if (strcmp(roll_s[total], "seller") == 0) {
							//add a pointer to struct seller and allocate memory if the role is seller
							num_s++;
							if (temps != NULL) {
								SELLER = (struct seller*)realloc(SELLER, sizeof(struct seller) * (num_s + 1));
								SELLER = seller_initialize(num_s, total, data, SELLER, roll_s, username_s);
								SELLER[num_s].goods_sell = (struct selling_goods*)malloc(size * sizeof(struct selling_goods));
								if (SELLER[num_s].goods_sell == NULL) {
									printf("memory allocation error.\n");
									return 0;
								}
							}
							if (tedad_temp1 != NULL) {
								tedad_goods_sell = (int*)realloc(tedad_goods_sell, (num_s + 1) * (sizeof(int)));
								tedad_goods_sell[num_s] = 0;
							}
						}
						total++;
					}
					free(INPUT);
					continue;
				}
				else if (strcmp(INPUT, "login") == 0) {
					if (temp_login != NULL)
						condition_login = (int*)realloc(condition_login, sizeof(int) * (total + 1));
					if (condition_login != NULL)
						condition_login = log_in(total, data, condition_login, username_s, password_s, roll_s);
					for (int j = 0; j < total; j++) {
						if (condition_login[j] == 1) {
							num = j;
							break;
						}
					}
					free(INPUT);
					continue;
				}
				else if (strcmp(INPUT, "deposit") == 0) {
					if (condition_login[num] == 1 && strcmp(roll_s[num], "buyer") == 0) {
						for (int k = 0; k <= num_b; k++) {
							if (strcmp(username_s[num], BUYER[k].name_b) == 0) {
								check = 2;
								deposit_check = get_number(data, check);
								BUYER[k].balance_b += deposit_check;
								printf("deposit succeeded!\n");
							}
						}
					}
					else {
						printf("deposit not possible.\n");
					}
					free(INPUT);
					continue;
				}
				else if (strcmp(INPUT, "add_goods") == 0) {
					if (condition_login[num] == 1 && strcmp(roll_s[num], "seller") == 0) {
						for (int k = 0; k <= num_s; k++) {
							if (strcmp(username_s[num], SELLER[k].name_s) == 0) {
								tedad_goods_sell[k]++;
								SELLER[k].goods_sell = add_goods(k, tedad_goods_sell, num_s, SELLER, data);
								break;
							}
						}
					}
					else {
						printf("adding goods not possible.\n");
					}
					free(INPUT);
					continue;
				}
				else if (strcmp(INPUT, "buy") == 0) {
					if (condition_login[num] == 1 && strcmp(roll_s[num], "buyer") == 0) {
						for (int k = 0; k <= num_b; k++) {
							if (strcmp(username_s[num], BUYER[k].name_b) == 0) {
								tedad_goods_buy[k]++;
								BUYER[k].goods_buy = buy(k, tedad_goods_buy, tedad_goods_sell, num_b, num_s, BUYER, SELLER, data);
								break;
							}
						}
					}
					else {
						printf("buying not possible.\n");
					}
					free(INPUT);
					continue;
				}
				else if (strcmp(INPUT, "show_goods") == 0) {
					if (condition_login[num] == 1) {
						show_goods(tedad_goods_sell, SELLER, num_s);
					}
					else {
						printf("user not logged in.\n");
					}
					free(INPUT);
					continue;
				}
				else if (strcmp(INPUT, "view") == 0) {
					if (condition_login[num] == 1) {
						view(num,tedad_goods_sell, tedad_goods_buy, SELLER, BUYER, num_s, num_b,username_s,roll_s);
					}
					else {
						printf("user not logged in.\n");
					}
					free(INPUT);
					continue;
				}
				else if (strcmp(INPUT, "logout") == 0) {
					for (int j = 0; j < total; j++)
						condition_login[j] = 0;
					printf("logout succeeded!\n");
					free(INPUT);
					continue;
				}
				else if (strcmp(INPUT, "exit") == 0) {
					condition_check[1] = 10;
					free(INPUT);
					continue;
				}
				else {
				//if other words are entered (with or without space), print error.
					if (INPUT != "\0") {
						while ((c = getchar()) != '\n') 
							c = '\0';
					}
				if(INPUT!="\0")
				free(INPUT);
				printf("invalid input.try again.\n");
				continue;
				}
			}

		}
		return 0;
	}
}
