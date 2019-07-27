#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include"ex.h"

int run_test(int n){
    int debug = 0;

    /* Gathering student answers */
    char buffer1[999] = "";
    char buffer2[999] = "";

    get_answer_student(buffer1, n);

    /* Gathering corresponding correct answers */
    
    get_answer_reference(buffer2, n);

    if(debug == 1){
        printf("*********************\n\n");
        printf("Etudiant:\n\n");
        printf("%s\n\n", buffer1);
        printf("Correction:\n\n");
        printf("%s\n\n", buffer2);
    }

    int result = strcmp(buffer1, buffer2);

    // if(strcmp(buffer1, buffer2) == 0){
    //     printf("Test Passed!\n\n");
    // }else{
    //     printf("Test Failed!\n\n");
    // }

    return result;
}

void get_answer_student(char *buf, int n){
    int  stdout_bk; //is fd for stdout backup
    stdout_bk = dup(fileno(stdout));
    int pipefd[2];
    pipe2(pipefd, 0); // O_NONBLOCK);
    // What used to be stdout will now go to the pipe.
    dup2(pipefd[1], fileno(stdout));

    /* ************************************************************ */

    // Student function
    ft_is_negative(n);

    /* ************************************************************ */

    close(pipefd[1]);
    read(pipefd[0], buf, 998); 
    dup2(stdout_bk, fileno(stdout));//restore
}

void get_answer_reference(char *buf, int n){
    int  stdout_bk; //is fd for stdout backup
    stdout_bk = dup(fileno(stdout));
    int pipefd[2];
    pipe2(pipefd, 0); // O_NONBLOCK);
    // What used to be stdout will now go to the pipe.
    dup2(pipefd[1], fileno(stdout));

    /* ************************************************************ */
    
    // Reference function
    correction(n);

    /* ************************************************************ */

    close(pipefd[1]);
    read(pipefd[0], buf, 998); 
    dup2(stdout_bk, fileno(stdout));//restore
}

int main(void) {
    int is_ok = 0;

    if(is_ok == 0){
        is_ok = run_test(-10);
    }
    if(is_ok == 0){
        is_ok = run_test(0);
    }
    if(is_ok == 0){
        is_ok = run_test(-1);
    }
    if(is_ok == 0){
        is_ok = run_test(1);
    }
    if(is_ok == 0){
        is_ok = run_test(10);
    }
    if(is_ok == 0){
        is_ok = run_test(-6);
    }
    if(is_ok == 0){
        is_ok = run_test(-1000);
    }
    if(is_ok == 0){
        is_ok = run_test(1000);
    }

    if(is_ok == 0){
        printf("Cet exercice marche parfaitement, bravo !\n\n");
    }else{
        printf("Cet exercice ne marche pas encore completement...\n\n");
    }
}  