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
void addStudent(typeStudent* newStudent);
void cut(typeStudent* tobedeleted);
void deleteStudent(char* last);
void printForwards();
void printBackwards();
void quit();

#endif //what does this do
