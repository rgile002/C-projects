
/*Rolf Kinder GIlet */
/*COP 4610 Lab2, Fall 2017*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// mutex and c
pthread_mutex_t lockclassroom;
pthread_cond_t cv_students;
pthread_mutex_t lockquestion;

// method prototyp 
void* answerqestion(void);
void Student(int id,pthread_t studentId[]);
void* EnterOffice(int id);
void QuestionStart(int id);
void QuestionDone(int id);
void LeaveOffice(int id);
void AnswerStart(int id);
void AnswerDone(int id);
void* Professor(int id);

// global elements and flags
int student_count = 0;
int totalS = 0;
int Nforks;
int classcapasity;
int question[2];

//main
int main(int argc, char *argv[]) {
// argument handler 
if (argc > 2) {
   if((Nforks = atoi(argv[1]))){
    classcapasity = atoi(argv[2]);
   }
   else
   {
   printf("Try again with 2 Integers separate them by a space\n");
   return -1;
   }
}else{
   printf("Try again with 2 Integers separate them by a space\n");
   return -1;
}

    //create threads
    pthread_t studentId[Nforks];
    pthread_t prof;

    // init mutex and cv
    pthread_mutex_init(&lockclassroom,NULL);
    pthread_mutex_init(&lockquestion,NULL);
    pthread_cond_init(&cv_students,NULL);

    //create student
    for (int i=0; i<Nforks;i++) {
        Student(i,studentId);
    }

    //create professor thread
    //will loop and answer question if any
    pthread_create(&prof, NULL, &Professor, NULL);

    // join student threads
    for (int i=0; i<Nforks;i++){
        pthread_join(studentId[i], NULL);
    }

    // join professor thread
    pthread_join(prof,NULL);

    // destroy mutex and cv
    pthread_mutex_destroy(&lockquestion);
    pthread_mutex_destroy(&lockclassroom);
    pthread_cond_destroy(&cv_students);
    return 1;
}

// loop and answed question if any
// terminate when there is no more students
void* Professor(int id){
    while(1) {
        // check if there is any question
        if (question[0] == 1){
            //answer question
            AnswerStart(question[1]);
            AnswerDone(question[1]);
            //let student know he is done with question
            question[0] =2;
        }
        // check if all the students was served
        if (totalS == Nforks){
            pthread_exit(NULL);
        }
    }
}

// create student threads
void Student(int id, pthread_t studentId[]){
    pthread_create(&studentId[id], NULL, &EnterOffice, (int *)id);
}

// professer's office handler
void* EnterOffice( int id){
    // generate number of question for each student
    int Squestion = (id % 4) + 1;
    // put process to sleep
    if (random() > RAND_MAX / 2){
        usleep(10);
    }
    // student trying to enter class room
    pthread_mutex_lock(&lockclassroom);
    // check is class room is full
    if (student_count>= classcapasity){
        // have a lock and unlock inside the wait
        pthread_cond_wait(&cv_students, &lockclassroom);
    }
    // student enter class room, add 1 to class counter
    student_count++;
    pthread_mutex_unlock(&lockclassroom);

    printf("Student %d shows up in the office \n",id);
    // student question loop
    for (int i=0; i< Squestion; i++){
        // process to sleep
        if (random() > RAND_MAX / 2){
            usleep(10);
        }
        // student try to ask question if professor not busy
        pthread_mutex_lock(&lockquestion);
        // ask question
        QuestionStart(id);
        // notify the professor
        question[1]=id;
        question[0]=1;
        // wait for professors' answer
        while(1){
            // check if professor is done
            if(question[0]==2){
                // student satisfied
                QuestionDone(id);
                // notify other students they can ask questions
                question[0]=0;
                // break waiting loop
                break;
            }
        }
        pthread_mutex_unlock(&lockquestion);
    }
    // student done with all questions and exiting office
    LeaveOffice(id);
    // increment total student served counter
    totalS++;
    pthread_exit(NULL);
}

void QuestionStart(int id){
    printf("Student %d asks a question\n",id);
}
void QuestionDone(int id){
    printf("Student %d is satisfied\n",id);
}

// leaving office notify outside students to enter office
void LeaveOffice(int id){
    printf("Student %d leaves the office.\n",id);
    pthread_mutex_lock(&lockclassroom);
    student_count--;
    pthread_cond_signal(&cv_students);
    pthread_mutex_unlock(&lockclassroom);
}

void AnswerStart(int id){
    printf("Professor starts to answer question for student %d\n",id);
}
void AnswerDone(int id){
    printf("Professor is done with answer for student %d \n",id);
}
// end 
