#include "array.h"
#include <stdio.h>

void init(int_array* array, const int capacity) {


	//malloc()�� �����迭�Ҵ�
	array->arr = (int*)malloc(sizeof(int) * capacity);
	//assert��
	assert(array->arr != NULL);
	//capacity(�迭ũ��)�� �����ش�.
	array->capacity = capacity;
	//�ʱ�ȭ size�� 0
	array->size = 0;
}

int peek(int_array* array, const int index) {
	if (index >= 0 && index <= array->size - 1) {
		printf("%d", array->arr[index]);
		return array->arr[index];
	}
	else {
		printf("���� ������ �ƴϿ���!");
		exit(1); //���α׷� ����
	}
}

int insert(int_array* array, const int index, const int value) {
	//���� size�� capacity������ push�� ���� 
	if (array->size == array->capacity) {
		int* temp = NULL;
		temp = realloc(array->arr, sizeof(int) * (array->capacity + 5));
		if (temp != NULL) {
			array->arr = temp;
			array->capacity = array->capacity + 5;
		}
		else {
			return 0;
		}
	}
	//������ ��ġ(0~size)���� Ȯ��
	if (index >= 0 && index <= array->size) {
		for (int i = array->size; i > index; i--) {
			array->arr[i] = array->arr[i - 1];  //�� ĭ�� �ڷ� ����
		}
		array->arr[index] = value; 
		array->size++;
		return 1;

	}
	else {
		return 0;
	}
}

void push(int_array* array, const int value) {

	//���� size�� capacity������ realloc���� ũ�� +5
	if (array->size == array->capacity) {
		int* temp = NULL;
		temp = realloc(array->arr, sizeof(int) * (array->capacity + 5)); //ũ�����Ҵ�
		if ( temp != NULL) {
			array->arr = temp;
			array->capacity = array->capacity + 5;  //capacity����
		}
	}

	array->arr[array->size] = value; //������ �ڸ��� �� �־��ֱ�
	array->size++; //������ +1
}

int delete(int_array* array, const int index) {
	
	if (index >= 0 && index <= array->size - 1) {
		for (int i = index; i <  array->size-1; i++) {
			array->arr[i] = array->arr[i+1];  //�� ĭ�� ������ ����
		}
		array->size--; 
		return 1;

	}
	else {
		return 0;
	}
}