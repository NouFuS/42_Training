#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include"ex.h"

int run_test(char* str){
    int debug = 0;

    /* Gathering student answers */
    char buffer1[99999] = "";
    char buffer2[99999] = "";

    get_answer_student(buffer1, str);

    /* Gathering corresponding correct answers */
    
    get_answer_reference(buffer2, str);

    if(debug == 1){
        printf("\n\n*********************\n\n");
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

void get_answer_student(char *buf, char* str){
    int  stdout_bk; //is fd for stdout backup
    stdout_bk = dup(fileno(stdout));
    int pipefd[2];
    pipe2(pipefd, 0); // O_NONBLOCK);
    // What used to be stdout will now go to the pipe.
    dup2(pipefd[1], fileno(stdout));

    /* ************************************************************ */

    // Student function
    ft_putstr(str);

    /* ************************************************************ */

    close(pipefd[1]);
    read(pipefd[0], buf, 99998); 
    dup2(stdout_bk, fileno(stdout));//restore
}

void get_answer_reference(char *buf, char* str){
    int  stdout_bk; //is fd for stdout backup
    stdout_bk = dup(fileno(stdout));
    int pipefd[2];
    pipe2(pipefd, 0); // O_NONBLOCK);
    // What used to be stdout will now go to the pipe.
    dup2(pipefd[1], fileno(stdout));
    
    correction(str);

    close(pipefd[1]);
    read(pipefd[0], buf, 99998); 
    dup2(stdout_bk, fileno(stdout));//restore
}

int main(void) {
    int is_ok = 0;

    printf("\n");

    // for(int i = -100; i<100 ;i++){
    //     for(int j = -10; j<10 ;j++){
    //         if(is_ok == 0){
    //             is_ok = run_test(i, j);
    //         }
    //     }
    // }

    char test[12] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
    is_ok = run_test(test);
    
    if(is_ok == 0){
        printf("Cet exercice marche parfaitement, bravo !\n\n");
    }else{
        printf("Cet exercice ne marche pas encore completement...\n\n");
    }
}  