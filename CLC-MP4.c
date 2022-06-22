#include <stdio.h>
#include <mem.h>
#include <malloc.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
	
	char studentNumber[12];
	char studentName[24];
	char course[10];
	char year[10];
	float gwa;
	struct Student *next;
	
}Record;

Record *student, *newStudent;
int numOfRecords = 1;

void gotoxy(short x, short y);

void init(){
	printf("\n\t\tICC 104.1 DATA STRUCTURES AND ALGORITHMS\n");
	printf("\t\tMachine Problem 4\n");
	printf("\t\tStudent Record (Singly Linked List)\n\n");
	printf("\t\tSubmitted by Charles Ching\n");
	printf("\t\tPress any key to continue...");
	getch();
	system("cls");
}

void displayHeader(){
	
	gotoxy(10,3);printf("STUDENT NO.");
	gotoxy(28,3);printf("STUDENT NAME");
	gotoxy(50,3);printf("COURSE");
	gotoxy(64,3);printf("YEAR");
	gotoxy(76,3);printf("GWA");
}

int displayRecord(){
	
	int i = 0;
	Record *traverseRec;
	
	traverseRec = student;
	
	gotoxy(40,1);printf("STUDENT RECORDS");
	displayHeader();
	
	if(traverseRec == NULL){
		gotoxy(28,5);printf("NO EXISTING RECORD, CREATE A RECORD FIRST!");
		gotoxy(28,7);printf("Press any key to continue...");
		getch();
		system("cls");
		return true;
	}
	
	while(traverseRec != NULL){
		gotoxy(10,5+i);printf("%s\n", traverseRec->studentNumber);
		gotoxy(28,5+i);printf("%s\n", traverseRec->studentName);
		gotoxy(50,5+i);printf("%s\n", traverseRec->course);
		gotoxy(64,5+i);printf("%s\n", traverseRec->year);
		gotoxy(76,5+i);printf("%.2f\n", traverseRec->gwa);
		
		traverseRec = traverseRec->next;
		i++;
	}
	
	return false;
}

void createRecord(){
	
	int i, recordLength;
	
	student = NULL;
	newStudent = (Record*)malloc(sizeof(Record));
  	student = newStudent;
	
	printf("[STATUS] Creating Student Record\n\n");
	printf("How many students do you wish to record? => ");
	scanf("%d", &recordLength);
	
	numOfRecords = recordLength;
	
	system("cls");
	for(i = 0; i < recordLength; i++){
		printf("[STATUS] Creating Student Record\n\n");
		printf("Student %d\n\n", i+1);
		
		printf("\tENTER a 12 Digit Student Number => ");
		scanf("%s", &newStudent->studentNumber);
		
		printf("\tENTER Student Surname => ");
		scanf("%s", &newStudent->studentName);
		
		printf("\tENTER Course => ");
		scanf("%s", &newStudent->course);
		
		printf("\tENTER Year => ");
		scanf("%s", &newStudent->year);
		
		printf("\tENTER Student GWA => ");
		scanf("%f", &newStudent->gwa);
		
		printf("\nStudent %d recorded\n", i+1);
		printf("Press any key to continue...");
		getch();
		
		if(i == (recordLength - 1)){
			system("cls");	
			break;
		}
		
		newStudent->next = (Record*)malloc(sizeof(Record));
		newStudent = newStudent->next;
		system("cls");
	}
	
	newStudent->next=NULL;
   	newStudent=NULL;
	
	printf("[STATUS] Creating Student Record\n\n");
	printf("You recorded %d students\n", recordLength);
	printf("Press any key to continue...");
	getch();
}

int traverseRecord(){
	
	printf("[STATUS] Displaying Student Record\n\n");
	
	if(displayRecord()){
		return;
	};
	
	printf("\n\n\tRecord has been displayed. Press any key to continue.");
	getch();
}

void addTailRecord(){
	
	Record *lastRec;
	newStudent = (Record*)malloc(sizeof(Record));
	
	printf("[STATUS] Adding a Student Record\n\n");
		
	if(student == NULL){
		displayHeader();
		gotoxy(28,5);printf("NO EXISTING RECORD, CREATE A RECORD FIRST!");
		gotoxy(28,7);printf("Press any key to continue...");
		getch();
		system("cls");
		return;
	};
	
	printf("Student %d\n\n", numOfRecords+1);
		
	printf("\tENTER a 12 Digit Student Number => ");
	scanf("%s", &newStudent->studentNumber);
		
	printf("\tENTER Student Surname => ");
	scanf("%s", &newStudent->studentName);
		
	printf("\tENTER Course => ");
	scanf("%s", &newStudent->course);
		
	printf("\tENTER Year => ");
	scanf("%s", &newStudent->year);
		
	printf("\tENTER Student GWA => ");
	scanf("%f", &newStudent->gwa);
	
	newStudent->next = NULL;
	
	lastRec = student;
	
	while(lastRec->next != NULL)
	{
		lastRec = lastRec->next;
	}
	
	lastRec->next = newStudent;
	newStudent = NULL;
	lastRec = NULL;
	
	numOfRecords++;
	
	printf("\nStudent %d recorded\n", numOfRecords);
	printf("Press any key to continue...");
	getch();
}

int delRecord(){
	
	char studNo[12];
	Record *prevRec, *curRec;
	
	prevRec = NULL;
	curRec = student;
	
	printf("[STATUS] Deleting a Record\n\n");
	
	if(displayRecord()){
		return;
	};
	
	printf("\n\n\tENTER the Student Number you wish to delete : ");
	scanf("%s", &studNo);
	
	if (strcmp(curRec->studentNumber,studNo) == 0){
		student = curRec->next;
		free(curRec);
		curRec = NULL;
		
	    printf("\n\n\tRecord has been deleted.\n");
		printf("\tPress any key to continue...");
		getch();
		return;
	}
	
    while (curRec != NULL)
    {
        if (strcmp(curRec->studentNumber,studNo) == 0)
        {
            if (prevRec != NULL) 
                prevRec->next = curRec->next;

            free(curRec);
            break;
        } 

        prevRec = curRec;
        curRec = curRec->next;
    }
    
    printf("\n\n\tRecord has been deleted.\n");
	printf("\tPress any key to continue...");
	getch();
}

int main(){
	
	int res;
	int isChoosing = 1;
	
	init();
	
	while(isChoosing == 1){
		printf("\n\n\t\tMENU OPTIONS\n\n");
		printf("\t\t1.) Creation of Nodes in Singly/Single Linked List.\n\n");
		printf("\t\t2.) Traversal of Nodes in Singly/Single Linked List.\n\n");
		printf("\t\t3.) Addition of  Node in Singly/Single Linked List (at the end).\n\n");
		printf("\t\t4.) Deletion of Nodes in Singly/Single Linked List.\n\n");
		printf("\t\t5.) Exit\n\n");
		printf("\t\tENTER an option: ");
		scanf("%d", &res);
		
		switch(res){
			case 1:
				system("cls");
				createRecord();
				system("cls");
				break;
			case 2:
				system("cls");
				traverseRecord();
				system("cls");
				break;
			case 3:
				system("cls");
				addTailRecord();
				system("cls");				
				break;
			case 4:
				system("cls");
				delRecord();
				system("cls");
				break;
			case 5:
				isChoosing = 0;
				break;
			default:
				system("cls");
				printf("Invalid input, please try again.");
				printf("Press any key to continue...");
				getch();
				system("cls");
				break;
		}
	}

	return 0;
}

void gotoxy(short x, short y){
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
