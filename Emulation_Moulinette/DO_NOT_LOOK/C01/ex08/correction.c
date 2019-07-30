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
    int start_over = 1;
    int is_correct = 1;

    while(start_over == 1){
        int i = 1;
        is_correct = 1;
        while(i < size){
            if(tab[i-1] > tab[i]){
                is_correct = 0;
                int tmp = tab[i-1];
                tab[i-1] = tab[i];
                tab[i] = tmp;
            }
            i++;
        }
        if(is_correct == 1){
            start_over = 0;
        }
    }
}