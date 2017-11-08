#include <stdio.h>
#include <stdlib.h>

#include "test.h"

int main(void){

char* a ;

a = (char*) malloc(sizeof(void*));

printf("Claimed --> %ld bytes\n", syscall(__NR_get_slob_amt_claimed));

printf("Free --> %ld bytes\n", syscall(__NR_get_slob_amt_free));

free(a);
return 1;

}
