#include<unistd.h>
#include<stdio.h>

void correction(){
    char n_1 = '0';
    char n_2 = '0';
    char n_3 = '0';

    int is_first = 1;

    while(n_1 <='9'){
        while(n_2 <='9'){
            while(n_3 <='9'){
                if(n_1 < n_2 && n_2 < n_3){
                    if(is_first != 1){
                        char display = ',';
                        write(1, &display, 1);
                        display = ' ';
                        write(1, &display, 1);
                    }else{
                        is_first = 0;
                    }

                    write(1, &n_1, 1);
                    write(1, &n_2, 1);
                    write(1, &n_3, 1);
                    
                }
                n_3++;
            }
            n_2++;
            n_3 = '0';
        }
        n_1++;
        n_2 = '0';
        n_3 = '0';
    }
}