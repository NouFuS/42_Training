#include<unistd.h>
#include<stdio.h>

void correction(int n){
    char result;
    if(n < 0){
        result = 'N';
        write(1, &(result), 1);  
    }else{
        result = 'P';
        write(1, &(result), 1);  
    }
}