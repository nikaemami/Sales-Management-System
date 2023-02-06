#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"get_input.h"
#include"struct_seller.h"
#include"struct_buyer.h"
#include"struct_buying_goods.h"
#include"struct_selling_goods.h"
#include"get_number.h"
struct buying_goods* buy(int k, int* tedad_goods_buy, int* tedad_goods_sell, int num_b, int num_s, struct buyer* BUYER, struct seller* SELLER, char** data) {
	//create memory allocations for pointers to structs.
	BUYER[k].goods_buy = (struct buying_goods*)realloc(BUYER[k].goods_buy, (tedad_goods_buy[k]) * sizeof(struct buying_goods));
	if (BUYER[k].goods_buy != NULL) {
		BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_goods = (char*)malloc(sizeof(char));
		BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_seller = (char*)malloc(sizeof(char));
		int tedad = tedad_goods_buy[k];
		int size = 1;
		int  goods_count = 0;
		int check = 1;
		int condition_a = 0,condition_b = 0, condition_c = 0;
		int repeat = 0;
		//read the name and the count of the goods, and the name of its seller.
		char* goods_name = get_input(check, data);
		if (goods_name != "\0") {
			goods_count = get_number(data, check);
			if (goods_count > 0) {
				check = 2;
				char* goods_seller = get_input(check, data);
				if (goods_seller != "\0") {
					for (int i = 0; i <= num_s; i++) {
						if (strcmp(goods_seller, SELLER[i].name_s) == 0) {
							condition_b = 1;
							for (int j = 0; j < tedad_goods_sell[i]; j++) {
								if (strcmp(goods_name, SELLER[i].goods_sell[j].name) == 0) {
									condition_c = 1;
									//check if the buyer has enough money and the seller has enough counts.
									if (BUYER[k].balance_b >= (goods_count * SELLER[i].goods_sell[j].price)) {
										if (SELLER[i].goods_sell[j].count >= goods_count) {
											if (BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_seller != NULL && BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_goods != NULL) {
												BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_seller = (char*)realloc(BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_seller, (strlen(goods_seller) ) * sizeof(char));
												BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_goods = (char*)realloc(BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_goods, (strlen(goods_name) ) * sizeof(char));
											}
											
											//assign the inputs to the values of structers.
											//if the goods already exists.
											for (int t = 0; t < tedad_goods_buy[k]-1; t++) {
												if (strcmp(BUYER[k].goods_buy[t].name_goods, goods_name) == 0) {
													repeat = 1;
													BUYER[k].goods_buy[t].count += goods_count;
													SELLER[i].goods_sell[j].count -= goods_count;
													BUYER[k].balance_b -= (goods_count * SELLER[i].goods_sell[j].price);
													SELLER[i].balance_s += (goods_count * SELLER[i].goods_sell[j].price);
													tedad_goods_buy[k]--;
													printf("buying succeeded!\n");
													condition_a = 1;
													break;
												}
											}
											//if the goods is new, initialize its count to 0 (otherwise it will print garbage)
											if (repeat == 0) {
												if (BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_seller != NULL && BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_goods != NULL) {
													strcpy(BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_seller, goods_seller);
													strcpy(BUYER[k].goods_buy[tedad_goods_buy[k] - 1].name_goods, goods_name);
												}
												BUYER[k].goods_buy[tedad_goods_buy[k] - 1].count = 0;
												BUYER[k].goods_buy[tedad_goods_buy[k] - 1].count += goods_count;
												BUYER[k].goods_buy[tedad_goods_buy[k] - 1].price = SELLER[i].goods_sell[j].price;
												SELLER[i].goods_sell[j].count -= goods_count;
												BUYER[k].balance_b -= (goods_count * SELLER[i].goods_sell[j].price);
												SELLER[i].balance_s += (goods_count * SELLER[i].goods_sell[j].price);
												printf("buying succeeded!\n");
												condition_a = 1;
												break;
											}
										}
										else {
											printf("not enough goods in stuck.\n");
											tedad_goods_buy[k]--;
											condition_a = 2;
											break;
										}
									}
									else {
										printf("not enough money.\n");
										tedad_goods_buy[k]--;
										condition_a = 2;
										break;
									}
								}
							}
							if (condition_c == 0) {
								tedad_goods_buy[k]--;
								printf("this seller doesn't sell the product.\n");
								break;
							}
							if (condition_a == 0) {
								printf("this product doesn't exist.\n");
								tedad_goods_buy[k]--;
								break;
							}
							if (condition_a == 2) {
								break;
							}
						}
					}
					if (condition_b == 0) {
						tedad_goods_buy[k]--;
						printf("this seller doesn't exist.\n");
					}
				}
				else {
					printf("buying failed.try again.\n");
					tedad_goods_buy[k]--;
					free(goods_name);
				}
			}
			else {
				printf("invalid price.\n");
				tedad_goods_buy[k]--;
				char c;
				while ((c = getchar()) != '\n')
				free(goods_name);
			}
		}
		else {
			printf("buying failed.try again.\n");
			tedad_goods_buy[k]--;
		}
	}
	return BUYER[k].goods_buy;
}