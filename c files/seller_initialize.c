#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct_seller.h"
#include"struct_selling_goods.h"
struct seller* seller_initialize(int num_s,int total,  char** input,struct seller* SELLER, char** roll_s, char** username_s) {
	//allocate dynamic memory, and make sure it will not leak.
	*input = NULL;
	*input = (char*)malloc(sizeof(char));
	SELLER[num_s].name_s = (char*)malloc(sizeof(char));
	SELLER[num_s].name_s = *input;
	if ((*input) != NULL)
		SELLER[num_s].name_s = (char*)realloc(SELLER[num_s].name_s, sizeof(char) * (strlen(username_s[total]) + 1));
	if (SELLER[num_s].name_s != NULL)
		strcpy(SELLER[num_s].name_s, username_s[total]);
	SELLER[num_s].balance_s = 0;
	return SELLER;
}