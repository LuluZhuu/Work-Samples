#include <stdio.h>
#include <string.h>
int main(void) 
{
	//TODO 1
	//declare the course list as multidimensional character array and name it courselist1
	//You can use the example I have given in the assignment but do not forget that we will test
	//your solution also for different names
	char courselist1 [5][80]={"Causal Inference",
								"Probability & Statistics",
								"Computer System Organization",
								"Data Structure",
								"Principles of Data Science"};
	//TODO 2
	//declare the same course list with array of pointers and name it courselist2
    char * courselist2 [5]={"Causal Inference",
								"Probability & Statistics",
								"Computer System Organization",
								"Data Structure",
								"Principles of Data Science"};
	puts("Size with multidomensional array: ");
	//TODO 3
	//print the size of courselist1
	printf("%zu\n",sizeof(courselist1));
	puts("Size with array of pointers: ");
  //TODO 4
	//print the total size of strings in courselist2
	int total = 0;
	//char* ptr = NULL;
	int i;
	for(i=0;i<5;i++){
		total+=(strlen(courselist2[i])+1);
	}
	printf("%d\n",total);

	  
	int col;
	int row;
	for (row = 0; row < 5; row++) 
	{
		col = 0;
		while(courselist2[row][col]!='\0'){
			printf("%c",courselist2[row][col]);
			col++;
		}
	printf("\n");
    //TODO 5
	  //print course names by using courselist2
	  //
	}
	return 0;	
}
