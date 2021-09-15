#include <stdio.h>
#include <stdlib.h>

int *get_pos(int *arry, size_t len, int target)
{
    int * pos = (int *)malloc(sizeof(int) * 2);
    for(size_t i = 0; i < len; i++){
        for(size_t j = 0; j < len; j++){
            if (arry[i] + arry[j] == target){
                pos[0] = i;
                pos[1] = j;
                return pos;
            }
        }
    }
    return NULL;
}

int main(void){
    int my_array[5] = {1,2,3,4,5};
    int *p = get_pos(my_array, 5, 3);
    if(p == NULL)
    {
        return 1;
    }

    for (int i = 0; i < 2; i++){
        printf("%d", p[i]);
    }

    return 0;
}