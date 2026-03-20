#include <stdio.h>

void greeting(char *name);

int main(){
    greeting("Filip\n");
    return 0;
}

void greeting(char *name){
    printf("Hello, %s", name);
}
