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

void correction(int n){

    int current_nb = n;
    if(current_nb < 0){
        write_char('-');
        current_nb = -current_nb;
    }

    int tmp;
    int decimal_nb = 1;

    while(current_nb > 10){
        tmp = current_nb/10;
        while(tmp >= 10){
            tmp = tmp/10;
            decimal_nb++;
        }
        write_number_1digits(tmp);
        int i = 0;
        int pow = 1;
        while(i < decimal_nb){
            pow = 10*pow;
            i++;
        }
        int sub = tmp*pow;
        current_nb = current_nb - sub;
        decimal_nb = 1;
    }
    write_number_1digits(current_nb);
}