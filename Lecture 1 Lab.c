
#include <stdio.h>
//C:\Users\Cameron\Documents\"Uni stuff"\"Year 2"\"Advanced Programing"\"Lecture 1 Lab.exe"
char studentDetails(char firstName[50], char lastName[50]){
    printf("First name: \n");
    scanf("%s", firstName);
    printf("Last name: \n");
    scanf("%s", lastName);
}

void moduleDetails(int i, int moduleNumber, char moduleName[][50], int moduleMark[]){
    for (i; i < moduleNumber; i++){
        printf("Type module name AND mark: \n");
        scanf("%s %d", moduleName[i], &moduleMark[i]);
        while (1){
            if(moduleMark[i] >= 0 && moduleMark[i] <= 100){
                break;  
            }else{
                printf("mark needs to be between 0 and 100, type mark again: \n");
                scanf("%d",&moduleMark[i]);
            }
        }
    }
}

float moduleAverage(int moduleNumber, int moduleMark[]){
    int average = 0;
    for (int i = 0; i < moduleNumber; i++){
        average += moduleMark[i];
    }
    return average / (float)moduleNumber;
}

int overallGrade(float gradeAve,  int overall){
    
    if (gradeAve >= 69.5) {
        (overall = 1);
    } else if ((gradeAve < 69.5) && (gradeAve >= 59.5)){
        (overall = 2);
    } else if ((gradeAve < 59.5) && (gradeAve >= 49.5)){
        (overall = 3);
    } else if ((gradeAve < 49.5) && (gradeAve >= 39.5)){
        (overall = 4);
    } else {
        (overall = 5);
    }
    return overall;
}

void displayResults (int i, char firstName[50], char lastName[50], char moduleName[5][50], int moduleMark[], int moduleNumber, float gradeAve, int achievedGrade){
    printf("Student: %s %s\n",firstName, lastName);
    printf("---------------Grades---------------\n");
    for (i; i < moduleNumber; i++){
        printf("%s %d\n", moduleName[i], moduleMark[i]);
    }

    printf("------------------------------------\n");
    printf("Grade Average:%.2f\n", gradeAve);

    if (achievedGrade == 1){
        printf("Student achieved A 1st \n");
        printf("Student recieved an award");
    } else if (achievedGrade == 2){
        printf("Student achieved A 2.1");
    } else if (achievedGrade == 3){
        printf("Student achieved A 2.2");
    } else if (achievedGrade == 4){
        printf("Student achieved A 3rd");
    } else { 
        printf("Student Failed");
    }
}

int main() {
    
    int i = 0;
    char firstName[50];
    char lastName[50];
    
    int moduleNumber = 5;
    char moduleName[5][50];
    int moduleMark[5];
    int overall;

    
    studentDetails(firstName, lastName);
    //printf("Student: %s %s\n",firstName, lastName);
    
    moduleDetails(i ,moduleNumber, moduleName, moduleMark);
    /*for (i; i < moduleNumber; i++){
        printf("Grades: %s %d\n", moduleName[i], moduleMark[i]);
    }*/
    float gradeAve = moduleAverage(moduleNumber, moduleMark);
    //printf("Grade Average:%.2f\n", gradeAve);

    int achievedGrade = overallGrade(gradeAve, overall);
    //printf("Student achieved a: %d\n", achievedGrade);

    displayResults(i, firstName, lastName, moduleName, moduleMark, moduleNumber, gradeAve, achievedGrade);


    return 0;
}