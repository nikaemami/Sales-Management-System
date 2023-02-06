#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct_buyer.h"
#include"struct_seller.h"
#include"buyer_initialize.h"
#include"seller_initialize.h"
#include"struct_selling_goods.h"
#include"struct_buying_goods.h"
void view(int num, int* tedad_goods_sell, int* tedad_goods_buy, struct seller* SELLER, struct buyer* BUYER, int num_s, int num_b, char** username_s, char** roll_s) {
	//view the account of all buyers and sellers.
	if (strcmp(roll_s[num], "seller") == 0) {
		for (int i = 0; i <= num_s; i++) {
			if (strcmp(SELLER[i].name_s, username_s[num]) == 0) {
				printf("name:%s ", SELLER[i].name_s);
				printf("role:seller ");
				printf("balance:%d\n", SELLER[i].balance_s);
				printf("goods:\n");
				for (int j = 0; j < tedad_goods_sell[i]; j++) {
					printf("name:%s ", SELLER[i].goods_sell[j].name);
					printf("price:%d ", SELLER[i].goods_sell[j].price);
					printf("count:%d\n", SELLER[i].goods_sell[j].count);
				}
				break;
			}
		}
	}
	if (strcmp(roll_s[num], "buyer") == 0) {
		for (int i = 0; i <= num_b; i++) {
			if (strcmp(BUYER[i].name_b, username_s[num]) == 0) {
				printf("name:%s ", BUYER[i].name_b);
				printf("role:buyer ");
				printf("balance:%d\n", BUYER[i].balance_b);
				printf("goods:\n");
				for (int j = 0; j < tedad_goods_buy[i]; j++) {
					printf("name:%s ", BUYER[i].goods_buy[j].name_goods);
					printf("price:%d ", BUYER[i].goods_buy[j].price);
					printf("count:%d ", BUYER[i].goods_buy[j].count);
					printf("seller:%s\n", BUYER[i].goods_buy[j].name_seller);
				}
				break;
			}
		}
	}
}