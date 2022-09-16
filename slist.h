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

typeStudent* createStudent(char* first, char* last, long id, char* year, int grad);
<<<<<<< HEAD
void addStudent(typeStudent** root, typeStudent** tail, typeStudent* newStudent);
//void cut(typeStudent* tobedeleted);
void deleteStudent(typeStudent** root, typeStudent** tail, char* last);
void printForwards(typeStudent** root);
void printBackwards(typeStudent** tail);
void quit(typeStudent** root);
=======
void addStudent(typeStudent* root, typeStudent* newStudent);
void cut(typeStudent* tobedeleted);
void deleteStudent(char* last);
void printForwards();
void printBackwards();
void quit();
>>>>>>> 6d92f88f689864188073186b3d03f7137c070f7c

#endif
