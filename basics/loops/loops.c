#include <stdio.h>

int main(){
    printf("for loops starting from 0 with i++:\n");
    for (int i = 0; i < 5; i++){
        printf("%d\n", i);
    }
    printf("\n");

    printf("while loop:\n");
    int iter = 0;
    while (iter < 5){
        printf("%d\n", iter);
        iter++;
    }
}
