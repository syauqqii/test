#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void clrscr();
void menu();
void mulai_bermain();
int random_angka(int min, int max);

int main(){
	int input_menu;
	
	do{
		do{
			clrscr();
			
			menu();
			
			printf(" [?] Pilih Menu : ");
			scanf("%d", &input_menu);
			
		} while(input_menu < 0 || input_menu > 1);
		
		switch(input_menu){
			case 0:
				exit(0);
				break;
			case 1:
				mulai_bermain();
				break;
			default:
				break;
		}
		
	} while(input_menu != 0);

	return 0;
}

void clrscr(){
	system("cls||clear");
}

void menu(){
	printf("\n [#] Menu Program\n  |");
	printf("\n  |  [1] Mulai Bermain");
	printf("\n  |  [0] Exit Program\n  |\n");
}

void mulai_bermain(){
	int dari, ke; // dari 1 ke 99 (min 1, max 99)
	int jumlah_menebak;
	int i;
	int angka;
	int tebak;
	int temp;
	int salah = 0;
	
	do{
		clrscr();
		
		printf("\n [#] Input Data - Input Rentang Angka Acak (min 1, max 99)\n");
		
		printf("\n [?] Input MIN : [ 1..98] ");
		scanf("%d", &dari);
		
		if(dari < 10){
			printf(" [?] Input MAX : [ %d..99] ", dari+1);
			scanf("%d", &ke);
		} else{
			if((dari + 1) >= 99){
				printf(" [?] Input MAX : [%d..99] ", dari);
				scanf("%d", &ke);
			} else{
				printf(" [?] Input MAX : [%d..99] ", dari+1);
				scanf("%d", &ke);
			}
		}
		
	} while(dari < 1 || dari > 98 || ke <= dari || ke > 99);
	
	if((ke - dari) < 2){
		jumlah_menebak = 1;
	} else if((ke - dari) < 5 && (ke - dari) > 2){
		jumlah_menebak = 2;
	} else if((ke - dari) < 10 && (ke - dari) > 5){
		jumlah_menebak = 4;
	} else if((ke - dari) < 15 && (ke - dari) > 10){
		jumlah_menebak = 8;
	} else{
		do{
			clrscr();
			
			printf("\n [#] Input Data - Input Jumlah Berapa Kali Menebak (min 1, max 15)\n");
			
			printf("\n [?] Input Berapa Kali Anda Menebak : (1..15) ");
			scanf("%d", &jumlah_menebak);
		} while(jumlah_menebak < 1 || jumlah_menebak > 15 || jumlah_menebak > (ke - dari));
	}
	
	angka = random_angka(dari, ke);
	
	temp = jumlah_menebak;
	
	for(i = 1; i <= jumlah_menebak; i++){
		do{
			clrscr();
			
			// Cheat : printf("\n [#] Mulai Permainan, %d\n", angka);
			printf("\n [#] Mulai Permainan\n");
		
			printf("\n [>] Sisa Menebak Angka : %d\n", temp);
			
			printf("\n [>] Tebak Angka : (%d..%d) ", dari, ke);
			scanf("%d", &tebak);
			
			if(tebak > angka){
			    printf("\n [>] Tebakan anda terlalu besar\n");
			} else if(tebak < angka){
			    printf("\n [>] Tebakan anda terlalu kecil\n");
			}
			
			sleep(2);
			
		} while(tebak < dari || tebak > ke);
		
		if(tebak == angka){
			clrscr();
			printf("\n [#] Permainan Telah Selesai\n");
			printf("\n [>] Selamat Tebakan Anda Benar!\n");
			sleep(2);
			main();
		} else{
			temp = temp - 1;
			salah = salah + 1;
		}
	}
	
	clrscr();
	printf("\n [#] Permainan Telah Selesai\n");
	printf("\n [>] Yah Tebakan Anda Tidak Ada Yang Benar!\n");
	sleep(2);
	main();
	
	main();
}

int random_angka(int min, int max){
	return min + rand() % (max + 1 - min);
}
