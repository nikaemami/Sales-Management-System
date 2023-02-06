#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct_seller.h"
#include"seller_initialize.h"
#include"struct_selling_goods.h"
//print the goods of all sellers.
void show_goods(int* tedad_goods_sell, struct seller* SELLER, int num_s) {
	for (int i = 0; i <= num_s; i++) {
		printf("seller: %s\n", SELLER[i].name_s);
		for (int j = 0; j < tedad_goods_sell[i]; j++) {
			printf("goods:%s ", SELLER[i].goods_sell[j].name);
			printf("price:%d ", SELLER[i].goods_sell[j].price);
			printf("count:%d\n", SELLER[i].goods_sell[j].count);
		}
	}
}