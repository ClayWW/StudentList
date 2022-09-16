#include "slist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 128
typeStudent *root;
typeStudent *tail;

typeStudent* createStudent(){
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
    if(*root == NULL){
		*root = newStudent;
		*tail = newStudent;
	}else{
        typeStudent* end = *tail;
        end->next = newStudent;
        newStudent->prev = *tail;
        *tail = newStudent;
        /*
		typeStudent* current = *root;
        while(current->next != NULL){
     		current = current->next;
    	}
   		newStudent->next = NULL;
		newStudent->prev = current;
		current->next = (typeStudent*)malloc(sizeof(typeStudent));
		current->next = newStudent;
		*tail = newStudent;
        */
	}
}

void deleteStudent(typeStudent** root, typeStudent** tail, char* delete){ //results in a segmentation fault, this is the issue
    //(EDIT) no segmentation fault now which is good, but it also doesn't work which is bad
    typeStudent* current = *root;
    //printf("0");
    while(current != NULL){
        //printf("1");
        if(strcmp(current->last, delete)==0){ //not getting into here
            //printf("2");
            if(*root == current){
                //printf("3");
                if(current->next == NULL){
                    //printf("4");
                    *root = NULL;
                    //printf("5");
                } else{
                    //printf("6");
                    current->next->prev = NULL;
                    //printf("7");
                    *root = current->next;
                    //printf("8");
                }
            //printf("9");
            } else if(current->next == NULL){
                //printf("10");
                //current->prev->next = NULL;
                //printf("11");
                *tail = current->prev;
                //printf("12");
            } else{
                //printf("13");
                current->next->prev = current->prev;
                //printf("14");
                current->prev->next = current->next;
                //printf("15");
            }
        }
        printf("AA");
        current = current->next;
    }
    /*
    typeStudent* current = *root;
    if(strcmp(current->last, last) == 0 && root == tail){ //in the case of the root being the only node and having the last name
        free(current);
    }
    if(strcmp(current->last, last) == 0){
        while(strcmp(current->next->last, last) == 0 && current != NULL && current->next != NULL){
            current = current->next;
            typeStudent* old = current->prev;
            free(old);
        }
        *root = current;
    }
    
    typeStudent* current = *root;
    if(*root == *tail && strcmp(current->last, last)==0){
        typeStudent* current = *root;
        free(current);
    }
    if(strcmp(current->last, last) == 0){ //if root has last name, reestablish root first as the first student without the last name
	    while(strcmp(current->next->last, last) == 0 && current->next != NULL){
		    current = current->next; //can be NULL, need to delete node, not pointer
            typeStudent* old = current->prev;
		    free(old);
	    }
	    *root = current;
    }
    while(current->next != NULL){ //scroll through the entire list
        if(strcmp(current->last,last) == 0){ //in the case that the last name matches 
            typeStudent *old = current; 
            current = current->next;
            if(current == NULL){ //if the student is at the end of the list
        	    typeStudent *behind = old->prev;
       		    behind->next = NULL;
                *tail = behind;
        	    free(old);
	        }else{ //if the student is in the middle of the list
        	    typeStudent *behind = old->prev;
        	    typeStudent *front = old->next;
        	    front->prev = behind;
        	    behind->next = front;
        	    free(old);
	        }
        }else{ //if students last name does not match, keep going
            current = current->next;
        }
    }
    */
}

void printForwards(typeStudent** root){ //works
    typeStudent* current = *root;
    while(current != NULL){
        printf("%s %s\n", current->first, current->last);
        current = current->next;
    }
}

void printBackwards(typeStudent** tail){ //works
    typeStudent* current = *tail;
    while(current != NULL){
        printf("%s %s\n", current->first, current->last);
        current = current->prev;
    }
}

void quit(typeStudent** root){ //quits but may need to check if it properly deconstructs everything
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
    /*
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
    char grad[BUFFER];
    fgets(grad, 128, stdin);
    */
    //createStudent();
    
    typeStudent* root;
    typeStudent* tail;
    root = malloc(sizeof(typeStudent));
    tail = malloc(sizeof(typeStudent));
    int choice = 0;
    /*

    int realId = atoi(id);
    long int realRealId = (long int)realId;
    int realGrad = atoi(grad);
    */
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
            /*
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
            */
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
		
    return 0;
}

