#include<unistd.h>
#include<stdio.h>

void ft_print_alphabet_correction(void){
    char start = 'a';
    char stop = 'z';
    char current = start;

    while(current <= stop){
        write(1, &(current), 1);
        current++;
    }
}