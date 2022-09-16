#include "slist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 128
typeStudent **root;
typeStudent **tail;

typeStudent* createStudent(char* first, char*last, long id, char* year, int grad){
    typeStudent* student = malloc(sizeof(typeStudent));
    student->first = first;
    student->last = last;
    student->id = id;
    student->year = year;
    student->grad = grad;
    return student;
}

void addStudent(typeStudent **root, typeStudent **tail, typeStudent* newStudent){
        if(*root == NULL){
		*root = newStudent;
		*tail = newStudent;
	}else{
		typeStudent* current = *root;
        	while(current->next != NULL){
            		current = current->next;
       		}
       		newStudent->next = NULL;
		newStudent->prev = current;
		current->next = (typeStudent*)malloc(sizeof(typeStudent));
		current->next = newStudent;
		*tail = newStudent;
		//current->next->next = NULL;
	}
}
/*
void cut(typeStudent* tobedeleted){
    if(tobedeleted->next == NULL){
        typeStudent *behind = tobedeleted->prev;
        behind->next = NULL;
        free(tobedeleted);
    }else{
        typeStudent *behind = tobedeleted->prev;
        typeStudent *front = tobedeleted->next;
        front->prev = behind;
        behind->next = front;
        free(tobedeleted);
    }
}
*/

void deleteStudent(typeStudent** root, typeStudent** tail, char* last){
    typeStudent* current = *root;
    if(current->last == last){
	while(current->next->last == last && current->next != NULL){
		current = current->next;
		free(current->prev);
	}
	*root = current;
    }
    while(current->next != NULL){
        if(current->last == last){
            typeStudent *old = current;
            current = current->next;
            if(old->next == NULL){
        	typeStudent *behind = old->prev;
       		behind->next = NULL;
        	free(old);
	    }else{
        	typeStudent *behind = old->prev;
        	typeStudent *front = old->next;
        	front->prev = behind;
        	behind->next = front;
        	free(old);
	    }
        }
    }
}

void printForwards(typeStudent** root){
	//printf("Gets here");
    typeStudent* current = *root;
   // printf(root->first); core dumps
    while(current != NULL){
        printf("%s %s\n", current->first, current->last);
        current = current->next;
	//printf(current->first);
    }
   //printf("gets here");
}

void printBackwards(typeStudent** tail){
    typeStudent* current = *tail;
    /*
    while(current->next != NULL){
        current = current->next;
    }
    */
    while(current != NULL){
        printf("%s %s\n", current->first, current->last);
        current = current->prev;
    }
}

void quit(typeStudent** root){
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
    printf("First name:\n");
    char first[BUFFER];
    fgets(first, 128, stdin);
    printf("Last name:\n");
    char last[BUFFER];
    fgets(last, 128, stdin);
    printf("Student ID:\n");
    char id[BUFFER];
    fgets(id, 128, stdin);
    printf("Freshmen, Sophomore, Junior, or Senior?\n");
    char year[BUFFER];
    fgets(year, 128, stdin);
    printf("Graduation Year:\n");
    //printf("-1");
    char grad[BUFFER];
    //printf("0");
    //ends here for some reason
    fgets(grad, 128, stdin);
    //printf("1");
    //printf("2");
    typeStudent* root;
    typeStudent* tail;
    root = malloc(sizeof(typeStudent));
    tail = malloc(sizeof(typeStudent));
    //printf("3");
    int choice = 0;
    //printf("4");
    int realId = atoi(id);
    long int realRealId = (long int)realId;
    int realGrad = atoi(grad);
    root = createStudent(first, last, realRealId, year, realGrad);
    //printf("5");
    *tail = *root;
    //printf("6");
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
            fgets(first, 64, stdin);
            printf("Last name:\n");
            fgets(last, 64, stdin);
            printf("Student ID:\n");
            fgets(id, 64, stdin);
            printf("Freshmen, Sophomore, Junior, or Senior?\n");
            fgets(year, 64, stdin);
            printf("Graduation Year:\n");
            fgets(grad, 64, stdin);
	    realId = atoi(id);
	    realRealId = (long int)realId;
	    realGrad = atoi(grad);

            addStudent(&root, &tail, createStudent(first, last, realRealId, year, realGrad));

        }else if(choice == 2){
            printf("What is the last name of this unfortunate Student?\n");
            fgets(last, 15, stdin);
            deleteStudent(&root, &tail, last);

        }else if(choice == 3){
            printForwards(&root);

        }else if(choice == 4){
            printBackwards(&root);

        }else if(choice == 5){
            choice = 5;

    	}
	}
    exit(0);
    free(root);
		
    return 0;
}

