// Add library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Add library windows.h, conio.h if windows, add unistd.h if not windows
// And define OS_Windows if windows
#ifdef _WIN32
	#include <windows.h>
	#include <conio.h>
	#define OS_Windows
#else
	#include <unistd.h>
#endif

// Declare global vairable display for display table data (list ticket)
int display = 0;

// Initialization struct data
struct data{
	char nama[500];
	long long int nim;
	char jurusan[500];
	char binusian[500];
	struct data *next;
};

// Add pointer variable head to structur data
struct data *head = NULL;

// Create struct function to add data
struct data *new(char nama[], long long int nim, char jurusan[], char binusian[]){
	struct data *add = (struct data*)malloc(sizeof(struct data));

	strcpy(add->nama, nama);
	
	add->nim = nim;

	strcpy(add->jurusan, jurusan);
	strcpy(add->binusian, binusian);

	add->next = NULL;

	return add;
}

// config function
void config();

// Menu Program
int menuProgram();

// Add Data
void pushHead(char nama[], long long int nim, char jurusan[], char binusian[]);
void pushTail(char nama[], long long int nim, char jurusan[], char binusian[]);
void pushMid(int number, char nama[], long long int nim, char jurusan[], char binusian[]);

// Delete Data
void popHead();
void popTail();
void popMid(int number);

void input(int option);

// Print Data
void print();

/* --------------------------
	Main Program Area
-------------------------- */
int main(){
	// Declare option to input menu
	int option;

	config();

	do{

		do{

			system("cls||clear");

			if(display == 1){
				// call print function
				print();

				// call menu function and get return value option
				option = menuProgram();
				fflush(stdin);
			} else{
				// call menu function and get return value option
				option = menuProgram();
				fflush(stdin);
			}

		} while(option < 1 || option > 8);

		switch(option){
			case 1:
				input(option);
				break;
			case 2:
				if(head == NULL){
					break;
				} else{
					input(option);
				}
				break;
			case 3:
				if(head == NULL){
					break;
				} else{
					input(option);
				}
				break;
			case 4:
				if(head == NULL){
					break;
				} else{
					popHead();
				}
				break;
			case 5:
				if(head == NULL){
					break;
				} else{
					popTail();
				}
				break;
			case 6:
				if(head == NULL){
					break;
				} else{
					input(option);
				}
				break;
			case 7:
				if(display == 0){
					display = 1;
				} else{
					display = 0;
				}
				break;
			case 8:
				// call function exit()
				exit(0);
		}

	} while (option != 8);

	return 0;
}

/* --------------------------
	Config Program Area
-------------------------- */
void config(){
	#ifdef OS_Windows
		system("MODE CON: COLS=99 LINES=45");
		system("title List Data Mahasiswa");
	#endif
}

/* --------------------------
	Menu Program Area
-------------------------- */
int menuProgram(){
	// Declare option to input menu
	int option;

	// prefix
	printf("\n  ");

	// Menu program - with title program name
	printf("[#] List Data Mahasiswa");

	// prefix
	printf("\n   |\n   |   ");

	// Menu 1 - Add data from beggin list, Menu 4 - delete data from beggin list
	printf("[1] Add data beg     [4] Delete data beg");

	// prefix
	printf("\n   |   ");

	// Menu 2 - add data from end list, Menu 5 - delete data from end list
	printf("[2] Add data end     [5] Delete data end");
	
	// prefix
	printf("\n   |   ");
	
	// Menu 3 - add mid (custom number to add), Menu 6 - delete mid (custom number to delete)
	printf("[3] Add data mid     [6] Delete data mid");

	// prefix
	printf("\n   |");

	// prefix
	printf("\n   |   ");

	// Menu 7 - Print Table
	printf("[7] Print data       [8] Exit Program");

	// prefix
	printf("\n   |\n  ");

	// Input option
	printf("[#] Input Menu : ");
	scanf("%d", &option);

	// Return value option
	return option;
}

/* --------------------------
	insert beggin Area
-------------------------- */
void pushHead(char nama[], long long int nim, char jurusan[], char binusian[]){
	struct data *temp;
	struct data *baru = new(nama, nim, jurusan, binusian);

	if(head == NULL){
		head = baru;
		baru->next = head;
	} else{
		temp = head;

		while(temp->next != head){
			temp = temp->next;
		}

		baru->next = head;
		temp->next = baru;
		head = baru;
	}
}

/* --------------------------
	insert end list Area
-------------------------- */
void pushTail(char nama[], long long int nim, char jurusan[], char binusian[]){
	struct data *temp;
	struct data *baru = new(nama, nim, jurusan, binusian);

	if(head == NULL){
		head = baru;
		baru->next = head;
	} else{
		temp = head;

		while(temp->next != head){
			temp = temp->next;
		}

		temp->next = baru;
		baru->next = head;
	}
}

/* --------------------------
	insert custom Area
-------------------------- */
void pushMid(int number, char nama[], long long int nim, char jurusan[], char binusian[]){
	struct data *temp, *curr;
	struct data *baru = new(nama, nim, jurusan, binusian);
	int inc = 0;

	temp = head;

	if(head == NULL){
		head = baru;
		baru->next = head;
	} else{
		while(temp->next != head){
			inc++;
			temp = temp->next;
		}

		if(number == 1){
			pushHead(nama, nim, jurusan, binusian);
			return;
		} else if(number == (inc + 2)){
			pushTail(nama, nim, jurusan, binusian);
			return;
		} else{
			temp = head;
			curr = head;

			for(inc = 1; inc < number - 1; inc++){
				curr = curr->next;
			}

			for(inc = 1; inc < number; inc++){
				temp = temp->next;
			}

			curr->next = baru;
			baru->next = temp;
		}
	}
}

/* --------------------------
		Input Area
-------------------------- */
void popHead(){
	struct data *temp;

	if(head->next == head){
		head = NULL;
		free(head);
	} else{
		temp = head;
		
		while(temp->next != head){
			temp = temp->next;
		}

		temp->next = head->next;
		free(head);
		head = temp->next;
	}
}

/* --------------------------
		Input Area
-------------------------- */
void popTail(){
	struct data *temp, *curr;

	if(head->next == head){
		head = NULL;
		free(head);
	} else{
		temp = head;
		
		while(temp->next != head){
			curr = temp;
			temp = temp->next;
		}

		curr->next = temp->next;
		free(temp);
	}
}

/* --------------------------
		Input Area
-------------------------- */
void popMid(int number){
	int inc, num = 0;

	struct data *temp, *curr, *proc, *tmp;

	temp = curr = tmp = head;

	while(tmp->next != head){
		num++;
		tmp = tmp->next;
	}

	if(number == 1){
		popHead();
		return;
	} else if(number == num+1){
		popTail();
		return;
	} else{
		for(inc = 1; inc < number - 1; inc++){
			curr = curr->next;
		}

		for(inc = 1; inc < number; inc++){
			temp = temp->next;
		}

		curr->next = NULL;
		proc = temp->next;
		free(temp);
		curr->next = proc;
	}
}

/* --------------------------
		Input Area
-------------------------- */
void input(int option){
	int number, tmp = 0;

	struct data *curr = head;

	char nama[500];
	long long int nim;
	char jurusan[500];
	char binusian[500];

	if(option == 3){
		while(curr->next != head){
			tmp++;
			curr = curr->next;
		}

		printf("\n  [>] Number      : (1..%d) ", tmp+2);
		scanf("%d", &number);

		if(number < 1 || number > (tmp + 2)){
			return;
		}
	} else if(option == 6){
		while(curr->next != head){
			tmp++;
			curr = curr->next;
		}

		printf("\n  [>] Number      : (1..%d) ", tmp+1);
		scanf("%d", &number);

		if(number < 1 || number > (tmp + 1)){
			return;
		}

		popMid(number);

		return;
	}

	printf("\n  [>] Nama     : ");
	scanf(" %[^\n]s ", nama);

	
	printf("  [>] NIM      : ");
	scanf("%lld", &nim);

	
	printf("  [>] Jurusan  : ");
	scanf(" %[^\n]s ", jurusan);
	
	printf("  [>] Binusian : ");
	scanf("%s", binusian);

	if(option == 1){
		pushHead(nama, nim, jurusan, binusian);
	} else if(option == 2){
		pushTail(nama, nim, jurusan, binusian);
	} else if(option == 3){
		pushMid(number, nama, nim, jurusan, binusian);
	}
}

/* --------------------------
	Print Function Area
-------------------------- */
void print(){
	struct data *temp = head;
	int i = 0;

	printf("\n");

	printf("   +-------+--------------------+--------------------+--------------------+---------------------+\n");
	printf("   |  NO   |        NAMA        |        NIM         |      JURUSAN       |       BINUSIAN      |\n");
	printf("   +-------+--------------------+--------------------+--------------------+---------------------+\n");

	if(temp == NULL){
		printf("   |       |                    |                    |                    |                     |\n");
	} else{

		while(temp->next != head){
			i++;
			printf("   | %5d | %-18s |     %-10lld     | %-18s | %-19s |\n", i, temp->nama, temp->nim, temp->jurusan, temp->binusian);
			temp = temp->next;
		}

		printf("   | %5d | %-18s |     %-10lld     | %-18s | %-19s |\n", i+1, temp->nama, temp->nim, temp->jurusan, temp->binusian);

	}
	printf("   +-------+--------------------+--------------------+--------------------+---------------------+\n");
}
