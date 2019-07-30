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

void correction(int* tab, int size){
    int tab_tmp[size];

    int i = 0;
    while(i < size){
        tab_tmp[size-1-i] = tab[i];
        i++;
    }

    i = 0;
    while(i < size){
        tab[i] = tab_tmp[i];
        i++;
    }
}