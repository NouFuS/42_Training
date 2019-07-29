#include<unistd.h>
#include<stdio.h>

void ft_putchar_correction(char c){
    write(1, &c, 1);
}