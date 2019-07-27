#include<unistd.h>
#include<stdio.h>

void ft_print_reverse_alphabet_correction(void){
    char start = 'z';
    char stop = 'a';
    char current = start;

    while(current >= stop){
        write(1, &(current), 1);
        current--;
    }
}