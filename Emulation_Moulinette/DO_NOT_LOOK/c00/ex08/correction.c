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

int is_last(int max_n, char array[]){
    int i = max_n-1;
    int target = '9';
    int is_ok = 1;
    while(i>=0 && is_ok == 1){
        if(array[i] != target){
            is_ok = 0;
        }
        target--;
        i--;
    }

    return is_ok;
}

void write_char_rec(int max_n, char previous[], int current_n){
    int size = current_n;
    char start = previous[size-1]+1;
    // printf("Current size= %d\n\n", size);

    if(size < max_n){
        while(start <= '9'){
            char new[size+1];
            int index = 0;
            while(index <size){
                // printf("Array[%d]= %c\n", index, new[index]);
                new[index] = previous[index];
                index++;
            }
            new[size]=start;
            write_char_rec(max_n, new, size+1);
            start++;
        }
    }else{
        int i = 0;
        while(i<size){
            write_char(previous[i]);
            i++;
        }
        if(is_last(max_n, previous) == 0){
                write_char(',');
                write_char(' ');
        }
    }
}

void correction(int n){
    // printf("Starting...\n\n");
    char start = '0';

    while(start <= '9'){
        char new[1];
        new[0] = start;
        write_char_rec(n, new, 1);
        start++;
    }
}