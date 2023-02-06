#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"get_input.h"
#include"struct_seller.h"
#include"struct_selling_goods.h"
#include"get_number.h"
struct selling_goods* add_goods(int k,int* tedad_goods_sell,int num_s, struct seller* SELLER,char**data) {
	//create memory allocations for pointers to structs.
	SELLER[k].goods_sell = (struct selling_goods*)realloc(SELLER[k].goods_sell, (tedad_goods_sell[k]) * sizeof(struct selling_goods));
	if (SELLER[k].goods_sell != NULL) {
		SELLER[k].goods_sell[tedad_goods_sell[k] - 1].name = (char*)malloc(sizeof(char));
		if (SELLER[k].goods_sell[tedad_goods_sell[k] - 1].name != NULL) {
			int size = 1;
			int tedad = tedad_goods_sell[k];
			int j;
			int check;
			check = 1;
			int condition = 0;
			int goods_price = 0, goods_count = 0;
			//get the input for name price and count of the goods.
			char* goods_name = get_input(1, data);
			if (goods_name != "\0") {
				goods_price = get_number(data, check);
				if (goods_price > 0) {
					check = 2;
					goods_count = get_number(data, check);
					if (goods_count > 0) {
						//check if the goods is not for another seller.
						for (int i = 0; i <= num_s; i++) {
							j = 0;
							while (j < tedad_goods_sell[i]) {
								if (strcmp(SELLER[i].goods_sell[j].name, goods_name) == 0 && strcmp(SELLER[k].name_s, SELLER[i].name_s) != 0) {
									printf("this goods belongs to another seller.\n");
									tedad_goods_sell[k]--;
									condition = 1;
									break;
								}
								else {
									j++;
								}
							}
							if (condition == 1) {
								break;
							}
						}
						//check if the goods already exist for the seller or is a new one.
						if (condition == 0) {
							for (int a = 0; a < tedad; a++) {
								if ((strcmp(goods_name, SELLER[k].goods_sell[a].name) == 0) && (goods_price == SELLER[k].goods_sell[a].price)) {
									tedad_goods_sell[k]--;
									SELLER[k].goods_sell[a].count += goods_count;
									printf("adding succeeded!\n");
									condition = 2;
								}
								//if the goods already exists,check if the price matches too.
								else if ((strcmp(goods_name, SELLER[k].goods_sell[a].name) == 0) && (goods_price != SELLER[k].goods_sell[a].price)) {
									printf("price doesn't match with goods.\n");
									tedad_goods_sell[k]--;
									condition = 2;
								}
								if (condition == 2)
									break;
							}
							//adding a goods which is new.
							if (condition != 2) {
								SELLER[k].goods_sell[tedad - 1].name = (char*)realloc(SELLER[k].goods_sell[tedad - 1].name, (strlen(goods_name) + 1) * sizeof(char));
								if (SELLER[k].goods_sell[tedad_goods_sell[k] - 1].name != NULL) {
									strcpy(SELLER[k].goods_sell[tedad - 1].name, goods_name);
									SELLER[k].goods_sell[tedad - 1].price = goods_price;
									SELLER[k].goods_sell[tedad - 1].count = goods_count;
									printf("adding succeeded!\n");
								}
							}
						}
					}
					else {
						printf("invalid count.\n");
						free(goods_name);
						tedad_goods_sell[k]--;
						condition = 2;
					}
				}
				else {
					printf("invalid price.\n");
					free(goods_name);
					tedad_goods_sell[k]--;
					char c;
					while ((c = getchar()) != '\n')
						condition = 2;
				}
			}
			else {
				printf("adding failed.\n");
				tedad_goods_sell[k]--;
				condition = 2;
			}
			if(condition!=2)
				free(goods_name);
		}
	}
	return SELLER[k].goods_sell;
}
