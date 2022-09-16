#include "slist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 128
typeStudent *root;
typeStudent *tail;

typeStudent* createStudent(){
    /*
    PARAMETERS: none
    RETURNS: a student (typeStudent)

    Our buffer is defined above as 128. For the first name we first create the variable, prompt the user for their input,
    we then alter the string to remove the \n character at the end (which has been the bane of my existence this project), and then
    once fully prepped, we attribute the first name to the first field of the student. We repeat this process for last name, id, year, and graduation year.
    Id is a long int and grad year is an int so for those two specific cases we go through the steps of converting them from a char to their respective 
    data types. Our final result is a completed student (aside from their next and prev fields which remain NULL for the time being).
    */
    typeStudent* student = (typeStudent*)malloc(sizeof(typeStudent));
    int control;

    char first[BUFFER];
    printf("First Name:\n");
    fgets(first, BUFFER, stdin);
    control = (int)strlen(first);
    first[control-1] = '\0'; //Silber said to use this IT FINALLY WORKS NO MORE SEGMENTATION ERROR
    student->first = (char*)malloc(control);
    strcpy(student->first, first);

    char last[BUFFER];
    printf("Last Name:\n");
    fgets(last, BUFFER, stdin);
    control = (int)strlen(last);
    last[control-1] = '\0';
    student->last = (char*)malloc(control);
    strcpy(student->last, last);

    char fakeid[BUFFER];
    printf("ID:\n");
    fgets(fakeid, BUFFER, stdin);
    int realId = atoi(fakeid);
    long int realRealId = (long int)realId;
    student->id = realRealId;

    char year[BUFFER];
    printf("Freshman, Sophomore, Junior, or Senior?:\n");
    fgets(year, BUFFER, stdin);
    control = (int)strlen(year);
    year[control-1] = '\0';
    student->year = (char*)malloc(control);
    strcpy(student->year, year);

    char fakegrad[BUFFER];
    printf("What year do they graduate?\n");
    fgets(fakegrad, BUFFER, stdin);
    int realGrad = atoi(fakegrad);
    student->grad = realGrad;

    return student;
}

void addStudent(typeStudent **root, typeStudent **tail, typeStudent* newStudent){
    /*
    PARAMETERS: typeStudent **root: a double pointer that points to the pointer of the root
                typeStudent **tail: a double pointer that points to the pointer of the tail
                typeStudent* newStudent: The student that is being added to the doubly linked list
    RETURNS: none

    We first check the case of whether or not the root is null, meaning that our doubly linked list does not exist yet. Should this be the case,
    we establish the newStudent as both the root and tail since it is the only student. Otherwise, we begin at the tail of the list and push the new student
    onto the end of the list and reestablish the tail.
    */
    if(*root == NULL){
		*root = newStudent;
		*tail = newStudent;
	}else{
        typeStudent* end = *tail;
        end->next = newStudent;
        newStudent->prev = *tail;
        *tail = newStudent;
        free(end);
	}
}

void deleteStudent(typeStudent** root, typeStudent** tail, char* delete){
    /*
        PARAMETERS: typeStudent** root: a double pointer that points to the pointer of the root
                    typeStudent **tail: a double pointer that points to the pointer of the tail
                    char* delete: the last name that you are trying to totally remove from the doubly linked list
        RETURNS: None

        We first establish a current value as our root which will be our starting point. We enter a while loop that continues so long
        as the current student is not a NULL value. using strcmp(string compare), we check to see if the value between the students last name field
        matches the inputted last name that was entered by the user. If the root has the last name we are looking for and is the only node, we set the root to null.
        Otherwise, if the root's last name matches the last name we are looking for we disconnect the root node from the next, and then reestablish the root as the student,
        that was to the right of our deleted root. If we are looking to delete a student who is at the tail of the list, we disconnect the tail from the student before it and
        then reestablish the tail as the student to the left of the previous tail. If neither of these cases happen, it means that the student is in the middle of the
        list, we merely have to connect the student behind our current studnet to the student ahead of our current student and vice versa. Should none of these cases be true,
        meaning that the student does not have the last name we are looking for, we shift to the next one and repeat the process until we reach the end of our list.
    */
    typeStudent* current = *root;
    while(current != NULL){
        if(strcmp(current->last, delete)==0){ //not getting into here
            if(*root == current){
                if(current->next == NULL){
                    *root = NULL;
                } else{
                    current->next->prev = NULL;
                    *root = current->next;
                }
            } else if(current->next == NULL){
                current->prev->next = NULL;
                *tail = current->prev;
            } else{
                current->next->prev = current->prev;
                current->prev->next = current->next;
            }
        }
        current = current->next;
    }
    free(current);
}

void printForwards(typeStudent** root){ //works
    /*
        PARAMETERS: typeStudent** root: a double pointer that points to the pointer of the root
        RETURNS: None

        Starts at the beginning of the doubly linked list and loops through it so long as the student is not of NULL value. At every iteration,
        the function prints the student's first and last name. It then shifts to the right and repeats the process until the while loop ends (meaning we have reached
        the end of the list).
    */
    typeStudent* current = *root;
    while(current != NULL){
        printf("%s %s\n", current->first, current->last);
        current = current->next;
    }
    free(current);
}

void printBackwards(typeStudent** tail){ //works
    /*
        PARAMETERS: typeStudent** tail: a double pointer that points to the pointer of the tail
        RETURNS: None

        SStarts at the end of the doubly linked list and loops through it so long as the student is not of NULL value. At every iteration,
        the function prints the student's first and last name. It then shifts to the left and repeats the process until the while loop ends (meaning we have reached
        the front of the list).
    */
    typeStudent* current = *tail;
    while(current != NULL){
        printf("%s %s\n", current->first, current->last);
        current = current->prev;
    }
    free(current);
}

void quit(typeStudent** root){ //quits but may need to check if it properly deconstructs everything
    /*
        PARAMETERS: typeStudent** root: a double pointer that points to the pointer of the root
        RETURNS: None

        We start at the beginning of our doubly linked list, we then cycle through the entire list. While doing so, we continually free the previous
        student's memory until we are left with nothing but our current value left. We then free the final student and exit from the program.
    */
    typeStudent *current = *root;
    while(current != NULL){
        typeStudent *old = current;
        current = current->next;
        free(old);
    }
    free(current);
    exit(0);
}

int main(){
    printf("Welcome to the Student List. To begin, we will create our first student\n");
    
    typeStudent* root;
    typeStudent* tail;
    root = malloc(sizeof(typeStudent));
    tail = malloc(sizeof(typeStudent));
    int choice = 0;
    root = createStudent();
    tail = root;
    
    while(choice != 5){
        printf("Now, how would you like to proceed?\n");
        printf("Enter the number that corresponds to your choice.\n");
        printf("1: Add a Student to the List\n");
        printf("2: Delete a Student(s) from the List\n");
        printf("3: Print the List from Beginning to End\n");
        printf("4: Print the List from End to Beginning\n");
        printf("5: Exit the Program\n");
        scanf("%d", &choice);
	    getchar();
        if(choice == 1){
            addStudent(&root, &tail, createStudent());

        }else if(choice == 2){
            printf("What is the last name of this unfortunate Student?\n");
            char lastSearch[BUFFER];
            fgets(lastSearch, BUFFER, stdin);
            int fixTheFgets = (int)strlen(lastSearch);
            lastSearch[fixTheFgets-1] = '\0';
            deleteStudent(&root, &tail, lastSearch);

        }else if(choice == 3){
            printForwards(&root);

        }else if(choice == 4){
            printBackwards(&tail);

        }else if(choice == 5){
            choice = 5;

    	}
	}
    exit(0);
    free(root);
    free(tail);
		
    return 0;
}

