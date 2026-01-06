/*
lawrence mwangi
CT101/G/26436/25
FILE_HANDLING
*/

#include <stdio.h>
//file one prompting for the integers

int main(){

printf("enter 10 integers; ");

FILE *file =fopen("input.txt","w");


//checking if file is succesfully opened
if(file==NULL){
    printf("error");
    return 1;
}

int num[10];

for(int i=0;i<10;i++){
    printf("enter integers ");
    scanf("%d",&num);
    fprintf(file,"%d\n",num);
}

//closing file after entering digit

fclose(file);

printf("the 10 integers have been entered successfully");

//input and output file by reading the output.txt
//opening the input file to read
FILE *inputfile = fopen("input.txt","r");

//creating out put file
FILE *outputfile = fopen("output.txt","w");

 // Check if we can open input file
    if (inputfile == NULL) {
        printf("Error\n");
        return 1;
    }
    
    // Check if we can create output file
    if (outputfile == NULL) {
        printf("Error: Could not create output.txt file! \n");
        fclose(inputfile);  // Close the input file before exiting
        return 1;
    }
    
    int sum = 0, count = 0; 
    int currentNum; 
    
    while (fscanf(inputfile, "%d", &currentNum) != EOF) {
        sum += currentNum;  
        count++;    
    }
    
    // Calculate average (convert sum to float for decimal division)
    float average = (count > 0) ? (float)sum / count : 0;
    
    // Write results to output file
    fprintf(outputfile, "Sum: %d\n", sum);
    fprintf(outputfile, "Average: %.2f\n", average);
    
    // Close both files
    fclose(inputfile);
    fclose(outputfile);
    
    printf("Math complete! Sum and average calculated\n");
    printf("Results written to output.txt\n\n");
    
    

    
    // Display input.txt contents first
    printf("\n What's in input.txt?\n");
    FILE *showInput = fopen("input.txt", "r");
    
    // Check if we can open input file
    if (showInput == NULL) {
        printf("Error\n");
    } else {
        int num, position = 0;
        // Read and display each number with its position
        while (fscanf(showInput, "%d", &num) != EOF) {
            printf("Number %d: %d\n", ++position, num);
        }
        fclose(showInput);  // Close the file when done
    }
    
    // Display output.txt contents
    printf("\nWhat's in output.txt?\n");
    FILE *showOutput = fopen("output.txt", "r");
    
    // Check if we can open ou
    if (showOutput == NULL) {
        printf("Error\n");
    } else {
        char line[100];
        
        
        while (fgets(line, sizeof(line), showOutput) != NULL) {
            printf("%s", line);  
        }
        fclose(showOutput);  

    


    
    return 0; 
}























































    return 0;

}

