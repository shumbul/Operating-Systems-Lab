//banker's algorithm
#include <stdio.h> 
#include <string.h>  
int P,R,total = 0,safe[10],sz = 0;

int is_available(int process_id, int allocated[][R], int max[][R], int need[][R], int available[]) 
{ 
    int j;
    int flag = 1; 
    for (j = 0; j < R; j++) 
	{ 
        if (need[process_id][j] > available[j]) 
            flag = 0; 
    } 
    return flag; 
} 
 
void safe_sequence(int marked[], int available[], int allocated[][R], int max[][R], int need[][R]) 
{ 
  int i,j;
    for (i = 0; i < P; i++) { 
  
        if(marked[i]==0 && is_available(i, allocated, max, need, available)!=0)
		{ 
            marked[i] = 1; 
            for (j = 0; j < R; j++) 
               available[j] += allocated[i][j]; 
			//available increases after getting the allocated resources freed
            safe[sz] = i; //assume that process i is safe
            sz++;         //process ++
          
            safe_sequence(marked, available, allocated, max, need);  //so that all the possible sequences would be saved
            //rewind so as to get all the possible sequences
            sz--;         
            safe[sz] = 0;
            for (j = 0; j < R; j++) 
                available[j] -= allocated[i][j]; 
            marked[i] = 0; 
        } 
    }

    if (sz == P) //all the processes were able to fulfil their needs
	{ 
        total++; 
        for (i = 0; i < P; i++) 
		{ 
            printf("P%d  ", safe[i] + 1); 
        } 
  
        printf("\n");
    } 
} 
  
int main() 
{ 

	printf("Enter number of processes and number of resource types\n"); 
	scanf("%d%d", &P,&R);
	
	int i,j;
	int available[R];
	int allocated[P][R];
	int max[P][R];
	
	printf("Enter available matrix\n");
	for (i=0;i<R;i++)
	{
		scanf("%d", &available[i]);
	}
	
	printf("Enter allocated matrix\n");
	for (i=0;i<P;i++)
	{
		for (j=0;j<R;j++)
		{
			scanf("%d", &allocated[i][j]);
		}
		    printf("\n");
	}
			
	printf("Enter max matrix\n");
	for (i=0;i<P;i++)
	{
		for (j=0;j<R;j++)
		{
			scanf("%d", &max[i][j]);
		}
		    printf("\n");
	}
   
    int marked[P]; 
	for(i= 0 ; i < P; i++)
	marked[i] = 0;
  
    int need[P][R]; 
    for ( i = 0; i < P; i++) 
        for (j = 0; j < R; j++) 
            need[i][j] = max[i][j] - allocated[i][j]; 
  
    printf("Safe sequences are:\n"); 
    safe_sequence(marked, available, allocated, max, need); 
    
    if (total == 0) //a global variable
        printf("System is unsafe");
    else 
        printf("\nThere are total %d safe-sequences\n", total); 

    return 0;
}
