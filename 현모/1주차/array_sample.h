#pragma once

typedef struct __int_array
{
    int* arr;
    int size;
    int capacity;
} int_array;

void init(int_array* array, const int capacity); //배열 초기화
int peek(int_array* array, const int index);
int insert(int_array* array, const int index, const int value);
void push(int_array* array, const int value);
int delete (int_array* array, const int index);