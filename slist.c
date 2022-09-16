#include "slist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ticker;
typeStudent *root;

typeStudent* createStudent(char* first, char*last, long id, char* year, int grad){
    typeStudent* student = malloc(sizeof(typeStudent));
    student->first = first;
    student->last = last;
    student->id = id;
    student->year = year;
    student->grad = grad;
    return student;
}

void addStudent(typeStudent* newStudent){
    if(ticker == 0){
        root = (typeStudent*)malloc(sizeof(typeStudent));
        root = newStudent;
        root->next = NULL;
        root->prev = NULL;
        ticker++;
    }else{
        typeStudent* current = root; //need to first establish the root
        while(current->next != NULL){
            current = current->next;
        }
        current->next = (typeStudent*)malloc(sizeof(typeStudent));
        current->next = newStudent;
        current->next->next = NULL;
        current->next->prev = current;
        ticker++;
    }
}

void cut(typeStudent* tobedeleted){
    if(tobedeleted->next == NULL){
        typeStudent *behind = tobedeleted->prev;
        behind->next = NULL;
        free(tobedeleted);
        ticker--;
    }else{
        typeStudent *behind = tobedeleted->prev;
        typeStudent *front = tobedeleted->next;
        front->prev = behind;
        behind->next = front;
        free(tobedeleted);
        ticker--;
    }
}

void deleteStudent(char* last){
    typeStudent* current = root;
    while(current->next != NULL){
        if(current->last == last){
            typeStudent *old = current;
            current = current->next;
            if(old->next == NULL){
        	typeStudent *behind = old->prev;
       		behind->next = NULL;
        	free(old);
        	ticker--;
	    }else{
        	typeStudent *behind = old->prev;
        	typeStudent *front = old->next;
        	front->prev = behind;
        	behind->next = front;
        	free(old);
        	ticker--;
	    }
        }
    }
}

void printForwards(){
    typeStudent* current = root;
    while(current != NULL){
        printf("%s %s\n", current->first, current->last);
        current = current->next;
    }
}

void printBackwards(){
    typeStudent* current = root;
    while(current->next != NULL){
        current = current->next;
    }
    while(current != NULL){
        printf("%s %s\n", current->first, current->last);
        current = current->prev;
    }
}

void quit(){
    typeStudent *current = root;
    while(current != NULL){
        typeStudent *old = current;
        current = current->next;
        free(old);
        ticker--;
    }
    free(current);
    exit(0);
}

int main(){
    printf("Welcome to the Student List. To begin, we will create our first student\n");
    printf("First name:\n");
    char *first = malloc(sizeof(char*));
    fgets(first, 20, stdin);
    printf("Last name:\n");
    char *last = malloc(sizeof(char*));
    fgets(last, 20, stdin);
    printf("Student ID:\n");
    long *id = malloc(sizeof(long));
    scanf("%ld",id);
    printf("Freshmen, Sophomore, Junior, or Senior?\n");
    char *year = malloc(sizeof(char*));
    scanf("%s", year);
    printf("Graduation Year:\n");
    int *grad = malloc(sizeof(int));
    scanf("%d",grad);

    typeStudent* root;
    root = malloc(sizeof(typeStudent));
    int ticker = 0;
    int choice = 0;
	
    addStudent(createStudent(first, last, *id, year, *grad));

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
            printf("Let's Begin.\n");
            printf("First name:\n");
	    printf("Gets to fget");	    
            fgets(first, 20, stdin);
	    printf("Gets through fget");
            printf("Last name:\n");
            fgets(last, 20, stdin);
            printf("Student ID:\n");
            scanf("%ld",id);
            printf("Freshmen, Sophomore, Junior, or Senior?\n");
            scanf("%s", year);
            printf("Graduation Year:\n");
            scanf("%d",grad);

            addStudent(createStudent(first, last, *id, year, *grad));

        }else if(choice == 2){
            printf("What is the last name of this unfortunate Student?\n");
            fgets(last, 15, stdin);
            deleteStudent(last);

        }else if(choice == 3){
            printForwards();

        }else if(choice == 4){
            printBackwards();

        }else if(choice == 5){
            choice = 5;
        }
    }
    exit(0);

    return 0;
}

