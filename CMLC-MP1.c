#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<math.h>

// global variables
int electionData[5][5] = {};
const char * headers[] = {"Precincts", "Candidate A", "Candidate B", "Candidate C", "Candidate D"};
int totalVotesPerCandidate[4] = {0,0,0,0};
float votePercentageOfCandidate[4] = {};
float sumOfVotes = 0.0;
int userInput, navigation = 1;
int i,j,k,l,x;

//functions
void gotoxy(short x, short y);    //gotoxy boilerplate

int main()
{
	while(navigation == 1){
		gotoxy(25,0);printf("DSA Machine Problem 1: Arrays");
		gotoxy(25,1);printf("Enter 0 to start the program: ");scanf("%d",&userInput);
		
		switch(userInput){
			case 0: // user input
				sumOfVotes = 0.0; // initialization for a new table
				dataManip();
				if (navigation == 1){
					for(i = 0; i <= 4; i++){
						totalVotesPerCandidate[i] = 0;
					}
					system("CLS");
					continue;
				}
				else{
					continue;
				}
				break;
				
			default:
				system("CLS");
				continue;
		}
	}

	return 0;
}

int dataManip(){
	
	const char * candidates[] = {"Candidate A", "Candidate B", "Candidate C", "Candidate D"}; 
	// prints candidates, precincts, total and percentage
	for(i = 0; i <= 4; i++){
		gotoxy(15*i,2);printf("%s", headers[i]);
	}
	
	for(i = 1; i <= 5; ++i){
		gotoxy(0,2+i);printf("%d",i);
	}
	
	// user-input
	for(j = 0, l = 1; j <= 3; ++j, l++){
		for(k = 0; k <= 4; k++){
			gotoxy(15*l,k+3);scanf("%d", &electionData[k][j]);
		}
	}
	
	// computes total number of votes per candidate
	for(j = 0; j <= 4; j++){
		for(k = 0; k <= 4; k++){
			totalVotesPerCandidate[j] += electionData[k][j];
		}
	}
	
	// gathers the sum of votes
	for(j = 0; j <= 3; j++){
		sumOfVotes += totalVotesPerCandidate[j];
	}
	
	// computes for the percentage
	for(k = 0; k <= 3; k++){
		float n = totalVotesPerCandidate[k];
		float percentage = (n/sumOfVotes)*100;
		
		votePercentageOfCandidate[k] = percentage;
	}
	
	// assessment and sorting
	
	float percentagePlaceholder[4] = {};
	for (k = 0; k <= 3; k++){
		percentagePlaceholder[k] = votePercentageOfCandidate[k];
	}
	
	float data = 0.0;
	for (i = 0; i < 4; ++i){
        for (j = i + 1; j < 4; ++j){
            if (percentagePlaceholder[i] < percentagePlaceholder[j]){
                    data =  percentagePlaceholder[i];
                    percentagePlaceholder[i] = percentagePlaceholder[j];
                    percentagePlaceholder[j] = data;
                }
            }
        }
    
    // prints a line separating the total number of votes per candidate and percentage
	for(l = 0; l <= 80; l++){
		gotoxy(l,8);printf("-");
	}
        
	gotoxy(0,9);printf("Total: ");
	gotoxy(0,10);printf("Percentage: ");
	
	// prints the total number of votes per candidate
	for(i = 0, x = 1; i <= 3; i++,x++){
		gotoxy(15*x,9);printf("%d", totalVotesPerCandidate[i]);
	}
        
	// prints the percentage
	for(i = 0, x = 1; i <= 3; i++,x++){
		gotoxy(15*x,10);printf("%.2f", votePercentageOfCandidate[i]);
	}
	
	// identifying the index of the candidate winner
	for(l = 0; l <= 3; l++){
		if(percentagePlaceholder[0] == votePercentageOfCandidate[l]){
				gotoxy(0,12);printf("Candidate winner: %s", candidates[l]);
		}
	}

	gotoxy(25,14);printf("1 to create a new table, 0 to exit: ");scanf("%d", &navigation);
	
	return navigation;
}

void gotoxy(short x, short y)   //gotoxy boilerplate                                              
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
