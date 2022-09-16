//Clay Wilfong

#ifndef STUDENT_FIRST
#define STUDENT_FIRST

typedef struct student {
    char* last;
    char* first;
    long id;
    char* year;
    int grad;
    struct student *next;
    struct student *prev;
} typeStudent;

typeStudent* createStudent();
void addStudent(typeStudent** root, typeStudent** tail, typeStudent* newStudent);
void deleteStudent(typeStudent** root, typeStudent** tail, char* delete);
void printForwards(typeStudent** root);
void printBackwards(typeStudent** tail);
void quit(typeStudent** root);

#endif
