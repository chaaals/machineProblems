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
	struct Student *prev, *next;
	
}Record;

Record *HEAD, *TAIL, *newStudent;
int numOfRecords = 1;

void gotoxy(short x, short y);

void init(){
	printf("\n\t\tICC 104.1 DATA STRUCTURES AND ALGORITHMS\n");
	printf("\t\tMachine Problem 5\n");
	printf("\t\tStudent Record (Doubly Linked List)\n\n");
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
	
	traverseRec = HEAD;
	
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
	Record *prev, *next;
	
	newStudent = (Record*)malloc(sizeof(Record));
  	
  	HEAD = newStudent;
  	TAIL = newStudent;
  	HEAD->next = NULL;
  	HEAD->prev = NULL;
	
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
		
		prev = newStudent;
		next = newStudent->next;
		
		next->prev = prev;
		
		newStudent = newStudent->next;
		TAIL = newStudent;
		system("cls");
	}
	
	TAIL->next = NULL;
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

int addAfterRecord(){
	
	Record *prev, *next, *curRecord = HEAD;
	newStudent = (Record*)malloc(sizeof(Record));
	char afterRecord[12];
	int Flag = 0;
	
	printf("[STATUS] Insert a record after a record\n\n");
	
	if(displayRecord()){
		return;
	};
	
	printf("\n\tStudent %d\n\n", numOfRecords+1);
		
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
	
	newStudent->prev = NULL;
	newStudent->next = NULL;
	
	printf("\n\tInsert the record after student number => ");
	scanf("%s", &afterRecord);
	
	while(Flag == 0 && curRecord != NULL)
		{
			if (strcmp(curRecord->studentNumber, afterRecord) == 0)
				Flag = 1;
			else
				curRecord = curRecord->next;
		}

		if (Flag == 0)
			printf("\n\tInsertion failed because %s does not exist in the list.\n", afterRecord);

		else
		{
			
			if (curRecord == TAIL)
			{
				newStudent->prev = TAIL;
				TAIL->next = newStudent;
				TAIL = newStudent;
				printf("\n\tInsertion complete. Student %s added after Student %s.\n", curRecord->studentNumber , afterRecord);
			}

			else
			{
				newStudent->next = curRecord->next;
				newStudent->prev = curRecord;
				
				curRecord->next = newStudent;
				
				next = curRecord->next;
				prev = next->prev;
				
				prev = newStudent;
				
				printf("\n\tInsertion complete. Student %s added after Student %s.\n", newStudent->studentNumber, afterRecord);
			}
			curRecord = NULL;
			newStudent = NULL;
		}
	
	numOfRecords++;
	
	printf("\n\tStudent %d recorded\n", numOfRecords);
	printf("\tPress any key to continue...");
	getch();
}

int delBeforeRecord(){
	
	char studNo[12];
	Record *prevRec, *curRec, *next, *prev;
	
	prevRec = HEAD;
	curRec = HEAD;
	
	printf("[STATUS] Delete a record before a record\n\n");
	
	if(displayRecord()){
		return;
	};
	
	printf("\n\n\tENTER a Student Number : ");
	scanf("%s", &studNo);
	
	printf("\n\tDeleting the record before Student Record %s\n", studNo);
	printf("\tPress any key to continue...");
	getch();
	
	if (curRec->next == NULL)
	{
		printf("\n\tDeletion failed because list only has one record.\n");
		printf("\tPress any key to continue...");
		return;
	}
	else
	{

        while (strcmp(curRec->studentNumber,studNo) != 0)
		{
			curRec = curRec->next;

			if (curRec == NULL)
			{
				printf("\n\tDeletion failed because %s does not exist in the list.\n", studNo);
				printf("\tPress any key to continue...");
				getch();
				system("cls");
				return;
			}
		}

        if (curRec == HEAD->next)
		{
            HEAD = curRec;
			prevRec->next = NULL;
			curRec->prev = NULL;
            free(prevRec);
			prevRec = NULL;
			curRec = NULL;
			printf("\n\tRecord before Student %s has been deleted.\n\n", studNo);
        }

        else if (curRec == HEAD)
		{
            printf("\n\tDeletion failed because there are no record before Student %s to delete.\n", studNo);
            printf("\tPress any key to continue...");
			getch();
			return;
        }

        else
		{
            prevRec = curRec->prev;
            
            prev = prevRec->prev;
            prev->next = curRec;
            
			curRec->prev = prevRec->prev;
			
			prevRec->prev = NULL;
			prevRec->next = NULL;
			
            free(prevRec);
			prevRec = NULL;
			curRec = NULL;
			printf("\n\tRecord before Student %s has been deleted.\n\n", studNo);
        }
	}
    
    printf("\tRecord has been deleted.\n");
	printf("\tPress any key to continue...");
	getch();
}

int main(){
	
	int res;
	int isChoosing = 1;
	
	init();
	
	while(isChoosing == 1){
		printf("\n\n\t\tMENU OPTIONS\n\n");
		printf("\t\t1.) Creation of Nodes in Doubly/Double Linked List.\n\n");
		printf("\t\t2.) Traversal of Nodes in Doubly/Double Linked List.\n\n");
		printf("\t\t3.) Addition of  Node in Doubly/Double Linked List (after a node).\n\n");
		printf("\t\t4.) Deletion of Node in Doubly/Double Linked List (before a node).\n\n");
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
				addAfterRecord();
				system("cls");				
				break;
			case 4:
				system("cls");
				delBeforeRecord();
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
