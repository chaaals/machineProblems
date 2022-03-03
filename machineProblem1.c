#include <stdio.h>
 
int electionData[6][5] = 
    {   
        {0,0,0,0,0}, //buffer values: used for header initialization
        {1,192,48,206,37},
        {2,147,90,312,21},
        {3,186,12,121,38},
        {4,114,21,408,39},
        {5,267,13,382,29}
    };

int main ()
{
    const char * headers[] = {"Precincts", "Candidate A", "Candidate B", "Candidate C", "Candidate D"};
    int n = 5;
    int isInitialized = 0;
    
    for(int i = 0; i <= n; ++i)
    {
        if(isInitialized == 0){
            for(int j = 0; j <= 4; j++){
                printf("%s    ",headers[j]);
            }

            isInitialized++;
        }

        else{
            for(int k = 0; k <= 4; k++){
                printf("    %d        ", electionData[i][k]);
            }
        }
    printf("\n");
    }
    return 0;
 }