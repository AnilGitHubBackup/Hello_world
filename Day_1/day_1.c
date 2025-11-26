//Day_1.c
#include <stdio.h>
// Write a function that takes char **argv and an int argc and reverses the order of the pointers in-place.
  // int main( int argc, char **argv){
  
  //   int i = 0;
  //   int j = argc-1; 
  //   char *temp = NULL;
  //   while(i<j) {
  //     temp = argv[i];
  //     argv[i] = argv[j];
  //     argv[j] = temp;
  //     i++;
  //     j--;    
  //   }
    
  // return 0;
  // }

/******************************************************************************************************
8. Implement a function that allocates a 2D array of ints with dimensions rows × cols such that it is contiguous in memory; return pointer suitable for int * indexing.
*******************************************************************************************************/
// int ** create_2d_array(void) {
//   int **ptr = malloc(2*sizeof(int*));
//   for(int i =0; i< 2; i++){
//      ptr[i] = malloc(2*sizeof(int));
//   }
//   return ptr;
// }

/***************************************************************************************************
9. Implement a function void call_fn_array(void (**fns)(int), size_t count, int arg) that iterates the array of function pointers and calls each with arg.
****************************************************************************************************/
void fn1(int x) { printf("fn1 %d", x);}
void fn2(int x) { printf("fn2 %d", x);}
void fn3(int x) { printf("fn3 %d", x);}


void call_fn_array(void (**fns)(int), size_t count, int arg) {
  for(size_t i =0; i< count; i++){
    void (*fns_temp)(int) = fns[i];
    fns_temp(arg);
  }
}

int main() {
  void (*fn[3])(int) = {fn1,fn2,fn3};
  call_fn_array(fn, 3, 20);
}

/************************************************************************************************
10. Given char *buffer = malloc(32), write a function void ensure_capacity(char **buf, size_t *cap, size_t needed) that grows the buffer using realloc if needed > *cap.
************************************************************************************************/
void ensure_capacity(char **buf, size_t *cap, size_t needed) {
  if(needed> *cap) {
    char *temp = realloc(*buf,needed);
    if(temp == NULL) {
      printf("error realloc\n");
      return;
    }
    *buf = temp;
    *cap = needed;
  }
}

/*********************************************************************************************
11. Create a small dispatcher: define typedef int (*op_t)(int,int); and implement int compute(op_t *ops, size_t nops, const char *expr) where expr is like "0 + 2" meaning call ops[0] with two ints parsed from expr.
**********************************************************************************************/
typedef int (*op_t)(int, int);

int compute(op_t *ops, size_t nops, const char *expr) {
    int a, b;

    // Parse two integers from expr
    if (sscanf(expr, "%d %d", &a, &b) != 2) {
        printf("Invalid expression\n");
        return -1;
    }
    int result = 0;
    for (size_t i = 0; i < nops; i++) {
        op_t actual_fun = ops[i];   // correct
        result = actual_fun(a, b);  // store result
    }
    return result;  
}

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int main() {
    op_t ops[] = { add, sub, mul };
    int r = compute(ops, 3, "6 3");
    printf("last result = %d\n", r);
}






















