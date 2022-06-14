#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct{
	int numberOfVotes[4][5];
	char candidate[100];
}Tally;

Tally record[4];
Tally extract[4];
bool recordIsExisting = false;

void gotoxy(short x, short y);

void init(){
	printf("\n\t\tICC 104.1 DATA STRUCTURES AND ALGORITHMS\n");
	printf("\t\tMachine Problems 2 and 3\n\n");
	printf("\t\tConstraints:\n");
	printf("\t\t=> Limited to 4 Candidates and 5 Precincts");
	printf("\n\n\t\tSubmitted by Charles Ching\n");
	printf("\t\tPress any key to continue...");
	getch();
	system("cls");
}

void createRecord(){
	int i,j;
	for(i = 0; i < 4; i++){
		printf("\n\tHi, I am Tallie! I will help you record the number of votes per candidate.\n\n\tPlease fill up the following input fields: \n\n");
		printf("\t\tCANDIDATE %d\n\n", i+1);
		printf("\t\tENTER candidate name => ");
		scanf("%s", &record[i].candidate);
		
		for(j = 0; j < 5; j++){
			printf("\n\t\t\tENTER number of votes on precinct %d => ", j+1);
			scanf("%d", &record[i].numberOfVotes[i][j]);
		}
		printf("\n\t\t\tCandidate recorded. Press any key to continue.");
		getch();
		system("cls");
	}
	
	recordIsExisting = true;
}

void thankYouMessage(){
	printf("\n\t\tGreat! Thank you for filling out the input fields.\n\n");
	printf("\t\tPress any key to reshow options.");
	getch();
	system("cls");
}

void showOptions(){
	printf("\n\n\t\tMENU OPTIONS\n\n");
	printf("\t\t1.) Create a tally record.\n\n");
	printf("\t\t2.) Display and Calculate the winner of the current data.\n\n");
	printf("\t\t3.) Save the current data on a separate file.\n\n");
	printf("\t\t4.) Retrieve, Display, and Calculate existing data from a file.\n\n");
	printf("\t\t5.) Exit.\n\n");
	printf("\t\tENTER an option: ");	
}

int displayData(){
	int i, j, sum = 0;
	int sumOfAllVotes[4];
	float num, total = 0.0;
	float percentage[4];
	
	gotoxy(30,2);printf("TALLY OF VOTE PER PRECINCT\n\n");
	
	gotoxy(2,4);printf("Precincts");
	
	for(i = 0; i < 4; i++){
		gotoxy(18*(i+1),4);printf("CANDIDATE\n");
		gotoxy(18*(i+1),5);printf("%s\n", extract[i].candidate);
		
		for(j = 0; j < 5; j++){
			gotoxy(2,7 + j);printf("%d", j+1);
			gotoxy(18*(i+1),7 + j);printf("%d", extract[i].numberOfVotes[i][j]);
			sum += extract[i].numberOfVotes[i][j];
		}
		gotoxy(18*(i+1),13);printf("%d", sum);
		sumOfAllVotes[i] = sum;
		sum = 0;
	}
	
	gotoxy(2,13);printf("Total");
	
	/* Gets Total Votes */
	for(i = 0; i < 4; i++){
		total += sumOfAllVotes[i];
	}
	
	/* Getting Percentage For Each Candidate */
	for(j = 0; j < 4; j++){
		percentage[j] = (sumOfAllVotes[j]/total)*100.0;
	}
	
	gotoxy(2,14);printf("Percentage");
	
	for(i = 0; i < 4; i++){
		gotoxy(18*(i+1),14);printf("%.2f", percentage[i]);
	}
	
	/* Checks if any of them is 50 or more */
	for(i = 0; i < 4; i++){
		if(percentage[i] >= 50.0){
			gotoxy(2,16);printf("Winner : ");
			gotoxy(18,16);printf("%s", extract[i].candidate);
			return;
		}
	}
	
	/* IF NONE OF THE PERCENTAGE IS GREATER THAN OR EQUAL TO 50% */
	/* Copy and Sort */
	float sortedPercentage[4];
	
	for(j = 0; j < 4; j++){
		sortedPercentage[j] = percentage[j];
	}
	
	float data = 0.0;
	for (i = 0; i < 4; i++){
        for (j = i + 1; j < 4; j++){
            if (sortedPercentage[i] < sortedPercentage[j]){
                    data =  sortedPercentage[i];
                    sortedPercentage[i] = sortedPercentage[j];
                    sortedPercentage[j] = data;
                }
            }
        }    
	
	/* Finds two qualifiers based on the value on index 0 and 1 in sortedPercentage */
	int qualifiers[2];
	for(i = 0; i < 2; i++){
		for(j = 0; j < 4; j++){
			if(sortedPercentage[i] == percentage[j]){
				gotoxy(2,16+i);printf("Run-off qualifier [%s]", extract[j].candidate);
				qualifiers[i] = j;
			}
		}
	}
	
	/* Compares the two qualifiers */
	int qualifier_1 = qualifiers[0];
	int qualifier_2 = qualifiers[1];
	
	gotoxy(2,19);printf("Winner : ");
	
	if(percentage[qualifier_1] > percentage[qualifier_2]){
		gotoxy(18,19);printf("%s", extract[qualifier_1].candidate);
	} else{
		gotoxy(18,19);printf("%s", extract[qualifier_2].candidate);
	}
	
	return 1;
}

void saveData(){
	
	Tally tempRec;
	FILE *TALLYRECORD;
	char fileName[100];
	int i,j;
	
	printf("\n\n\t\tAlright! Tallie will now save the current data.\n\n");
	printf("\t\tPlease enter a file name with .txt extension : ");
	scanf("%s", fileName);
	
	TALLYRECORD = fopen(fileName, "w");
	
	for(i = 0; i < 4; i++){
		tempRec = record[i];
		fwrite(&tempRec,sizeof(tempRec),1,TALLYRECORD);
	}
	
	fclose(TALLYRECORD);
	
	printf("\n\n\t\tData has been saved!\n\n");
	printf("\t\tPress any key to continue.");
	getch();
	
}

int retrieveData(){
	
	FILE *readRecord;
	Tally extractedRecord;
	Tally tmp[4];
	char fName[100];
	int res = 0;
	int i = 0;
	
	printf("\n\n\t\tTallie will now help you retrieve an existing data.\n\n");
	printf("\t\tNOTE: any retrieval of data will overwrite the current data.\n\t\tMake sure it has been saved or it will be lost forever!\n\n");
	printf("\t\tHave you saved the current data? [1 for Y/ 0 for N] : ");
	scanf("%d", &res);
	
	if(res == 0){
		printf("\n\n\t\tMake sure to save it first!\n\n");
		printf("\t\t[REDIRECTING TO MENU OPTIONS] Press any key to continue...\n\n");
		getch();
		return;
	}
	
	printf("\t\tPlease ENTER the file name with .txt extension : ");
	scanf("%s", fName);
	
	if(!(readRecord = fopen(fName, "r"))){
		system("cls");
		printf("\n\n\t\tFile does not exist!\n\n");
		printf("\t\tPress any key to continue...");
		fclose(readRecord);
		getch();
		return;
	};
	
	while(!feof(readRecord)){
		fread(&extractedRecord, sizeof(extractedRecord),1,readRecord);
		tmp[i] = extractedRecord;
		i++;
	}

	memcpy(&extract, &tmp, sizeof(tmp));
	
	system("cls");
	printf("\n\n\t\tData has been retrieved!\n\n");
	printf("\t\tPress any key to display and calculate the data...");
	getch();
	system("cls");
	
	gotoxy(0,0);printf("[STATUS] Displaying Existing Record from %s", fName);
	displayData();
	
	fclose(readRecord);
	gotoxy(2,21);printf("Data has been displayed!");
	gotoxy(2,22);printf("Press any key to continue...");
	getch();
}

int main(){
	
	/* Variables */
	int i,j,k,l;
	int res = 0, isChoosing = 1;
	
	/* Starts the program with information about the course, machine problem, and submitted by */
	init();
	
	/* Shows what can be done with the current data */
	while(isChoosing == 1){
		showOptions();
		scanf("%d", &res);
	
		switch(res){
			case 1:
				system("cls");
				/* Creates a record using the record struct variable at the global scope */
				createRecord();
				/* After creating a record, a thank you prompt displays */
				thankYouMessage();
				break;
			case 2:
				
				if(!recordIsExisting){
					system("cls");
					printf("\n\t\tYou don't have a record to display!\n\t\tYou can either retrieve data from a file or create a tally record.\n\n");
					printf("\t\tPress any key to continue...");
					getch();
					system("cls");
					break;
				}
				
				system("cls");
				memcpy(&extract, &record, sizeof(record));
				displayData();
				gotoxy(2,21);printf("Result has been displayed.");
				gotoxy(2,23);printf("Press any key to continue...");
				getch();
				system("cls");
				
				break;
			case 3:
				system("cls");
				saveData();
				system("cls");
				break;
			case 4:
				system("cls");
				retrieveData();
				system("cls");
				break;
			case 5:
				isChoosing = 0;
				break;
			default:
				printf("Invalid option, please try again.");
				printf("Press any key to continue...");
				getch();
		}
	}


	return 0;
}

void gotoxy(short x, short y)                                              
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
