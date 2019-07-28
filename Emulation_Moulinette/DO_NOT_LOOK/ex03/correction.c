#include<unistd.h>
#include<stdio.h>

void ft_print_numbers_correction(void){
    char start = '0';
    char stop = '9';
    char current = start;

    while(current <= stop){
        write(1, &(current), 1);
        current++;
    }
}