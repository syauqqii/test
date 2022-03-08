#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define size 7

int i;
int addr=0;
char store[] = "STAR FROZEN FOOD SHOP CASHIER";

// Deklarasi Struct data
struct data{
	char code[30];
	char name[30];
	int stock;
	long price;
};

struct data product[7] = {
	{"FF001", "Squid BBQ", 15, 40000},
	{"FF004", "Chicken Cordon Bleu", 17, 50000},
	{"FF008", "Salmon Garlic Butter", 24, 60000},
	{"FF010", "Korean Beef Slice-BBQ", 30, 65000},
	{"FF012", "Classic Tteobokki", 15, 75000},
	{"FF015", "Chicken Gyoza", 35, 85000},
	{"FF019", "Crispy Duck Confit", 20, 95000}
};

void clear_screen();
void print();
void add_stock();
void sell_product();
void menu();
void check(char code[]);

// Main Program
int main(){
	menu();
	
	return 0;
}

void clear_screen(){
	system("cls||clear");
}

// Tampilkan tabel produk
void print(){
	printf("%s\n", store);
	printf("=============================\n\n");
	
	printf("No. | Code  | Frozen Food Name          | Available | Price\n");
	printf("-------------------------------------------------------------------\n");
	
	for(i=0; i<size; i++){
		printf("0%d. | %s | %-25s | %9d | Rp. %ld,-\n", i+1, product[i].code, product[i].name, product[i].stock, product[i].price);
	}
	
	printf("-------------------------------------------------------------------\n\n");
}

// Menu program
void menu(){
	int select;
	
	clear_screen();
	print();
	
	printf("Menu : \n");
	printf("1. Sell\n");
	printf("2. Add Stock\n");
	printf("3. Exit\n");
	
	printf("Input choice : ");
	scanf("%d", &select);
	
	switch(select){
		case 1:
			sell_product();
		case 2:
			add_stock();
		case 3:
			exit(0);
		default:
			exit(1);
	}
}

// Jual produk
void sell_product(){
	char code[10];
	int quantitiy;
	
	printf("\nInput Froze Food Code [5 Chars]: ");
	scanf("%s", code);
	
	check(code);
	
	printf("Input Quantitiy [0..%d]: ", product[addr].stock);
	scanf("%d", &quantitiy);

	if(quantitiy < 0 || quantitiy > product[addr].stock){
		printf("\n\n...The quantity of frozen food is not enough...");
		
		sleep(3);
		menu();
	} else if(quantitiy == 0){
		printf("\n--- Thank You ---");
		
		sleep(3);
		menu();
	}
	
	printf("\nTotal Price: Rp %ld,- x %d = Rp %ld,-", product[addr].price, quantitiy, (quantitiy * product[addr].price));
	
	product[addr].stock = product[addr].stock - quantitiy;
	
	printf("\n\n--- Thank You ---");
	
	sleep(3);
	menu();
}

void add_stock(){
	char code[10];
	int stock;
	
	printf("\nInput Frozen Food Code [5 Chars]: ");
	scanf("%s", code);
	
	check(code);
	
	printf("Input Quantitiy [1..100]: ");
	scanf("%d", &stock);

	if(stock < 0 || stock > 100){
		exit(1);
	} else if(stock == 0){
		menu();
	}
	
	product[addr].stock = product[addr].stock + stock;
	
	printf("\n\n--- Adding Stock Success ---");
	
	sleep(3);
	menu();
}

void check(char code[]){
	int found=0;
	
	if(strlen(code) != 5){
		printf("\n\n---The frozen food code doesn't exist---");
		
		sleep(3);
		menu();
	}
	
	for(i=0; i<size; i++){
		if(strcmp(product[i].code, code) == 0){
			found = 1;
			addr = i;
		}
	}
	
	if(found == 0){
		printf("\n\n---The frozen food code doesn't exist---");
		
		sleep(3);
		menu();
	}
}
