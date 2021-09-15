#include <stdio.h>
#include <stdlib.h>
// gcc main.c -std=c99 -o app
#define length(array) (sizeof(array) / sizeof((array)[0]))
#define OTHER_SIZE 2
#define SIZE 4

struct array {
    int * data;
    size_t length;
};
//int x = 100;

//int main (void) 
//{    
//   for (int i = 0; i < x; i++)
//   {
//       if (i%3 == 0 && i%5 == 0) 
 //      {           
 //          printf("%s", "fizzbuzz");
 //      }
  //     else if (i%3 == 0)
 //      {
  //         printf("%s", "fizz");
  //     }
  //     else if (i%5 == 0)
  //     {
  //         /printf("%s", "buzz");
  //     }   
  //     else
  //     {
  //         printf("%s", i);
  //     }           
  // }    
//}

void print_arry(struct array *s)
{
    for (size_t i = 0; i  < s->length; i++)
    {
        printf("%d", s->data[i]);
    }
}

int main(int argc, char **argv)
{
    int my_array[SIZE] = {1,2,3,4};

    //size_t s = sizeof(arry) / sizeof(int);

    struct array s = {my_array, length(my_array)};

    print_arry(&s);
}