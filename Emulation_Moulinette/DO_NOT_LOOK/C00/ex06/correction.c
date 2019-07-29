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

void correction(){
    int n_1 = 0;
    int n_2 = 0;

    int is_first = 1;

    char display;

    while(n_1 <= 99){
        while(n_2 <= 99){
            if(n_1 < n_2){
                if(is_first != 1){
                    display = ',';
                    write(1, &display, 1);
                    display = ' ';
                    write(1, &display, 1);
                }else{
                    is_first = 0;
                }
                write_number_2digits(n_1);
                // write_number_2digits(n_1);
                display = ' ';
                 write(1, &display, 1);
                write_number_2digits(n_2);
            }
            n_2++;
        }
        n_1++;
        n_2 = 0;
    }
}