#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct_buyer.h"
#include"struct_buying_goods.h"
struct buyer* buyer_initialize(int num_b, int total, char** input,struct buyer* BUYER, char** roll_s, char** username_s) {
	int size = 1;
	//allocate dynamic memory, and make sure it will not leak.
	*input = NULL;
	*input = (char*)malloc(size * sizeof(char));
	BUYER[num_b].name_b = (char*)malloc(size * sizeof(char));
	BUYER[num_b].name_b = *input;
	if ((*input) != NULL)
	BUYER[num_b].name_b = (char*)realloc(BUYER[num_b].name_b, sizeof(char) * (strlen(username_s[total]) + 1));
	if (BUYER[num_b].name_b != NULL)
		strcpy(BUYER[num_b].name_b, username_s[total]);
	BUYER[num_b].balance_b = 0;
	return BUYER;
}