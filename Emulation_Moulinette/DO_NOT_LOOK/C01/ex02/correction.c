#include<unistd.h>
#include<stdio.h>

void write_number_2digits(int n){
    int offset = 48;
    char display;

    display = n/10 + offset;
    write(1, &display, 1);

    display = n%10 + offset;
    write(1, &display, 1);
}

void write_number_1digits(int n){
    int offset = 48;
    char display;
    display = n + offset;
    write(1, &display, 1);
}

void write_char(char c){
    char display = c;
    write(1, &display, 1);
}

void correction(int *a, int *b){
    int c;
    c = *b;
    *b = *a;
    *a = c;
}