/*有一个巨大问题，该程序存在内存够大但是无法扩大的情况
 *
 *
 *
 *
 *
 *
 *
 */




#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int BLOCK_SIZE = 20;
Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*a.size);//malloc默认返回void*（无类型指针），需要强制转换成int*，因为void*不能实现*p、p+1、p[0]等应用
    return a;
}

void array_free(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

//封装
int array_size(const Array *a)
{
    return a->size;
}

int* array_at(Array *a, int index)
{
    if (index >= a->size){
        array_inflate(a, (index/BLOCK_SIZE + 1)*BLOCK_SIZE - a->size);
    }
    return &(a->array[index]);
}

void array_inflate(Array *a, int more_size)
{
    int *p = (int*)malloc(sizeof(int)*(a->size + more_size));
    memcpy(p, a, sizeof(int)*a->size);
    free(a->array);
    a->array = p;
    a->size += more_size;
}

int main(int argc, char const *argv[])
{
    Array a = array_create(100);
    printf("%d\n", array_size(&a));
    *array_at(&a, 0) = 10;
    printf("%d\n", *array_at(&a, 0));
    int number = 0;
    int cnt = 0;
    while (number != -1){
        scanf("%d", &number);
        if(number != -1)
            *array_at(&a, cnt++) = number;
    }

    array_free(&a);

    return 0;
}
