/*c������ �޸� �����Ҵ��� malloc, calloc, realloc���� ������.

malloc �Լ��� ���� : void* malloc(size_t size)
-- > �Լ� ȣ�� �� �Ҵ��ϰ��� �ϴ� �޸��� ũ�⸦ ����Ʈ ������ �����ϸ�
�� ũ�⸸ŭ �޸𸮸� �Ҵ��ϰ� �ǰ�, �Ҵ��� �޸��� ù ��° ����Ʈ �ּҸ� ����.
���� �� NULL ����.

calloc �Լ��� ���� : void* calloc(size_t elt_count, size_t elt_size)
-- > elt_size ũ���� ������ elt_count�� ��ŭ ������ �� �ִ� �޸� ������ �Ҵ��ϰ�,
�� ������ ���� ���� 0���� �ٲ۴�.������ malloc�� ����.

realloc �Լ��� ���� : void* realloc(void* memblock, size_t size);
-- > �̹� �Ҵ��� ������ ������ memblock�� �ְ�, ������ ũ�⸦ size�� �Էµ� ������ �ٲ۴�.

free �Լ��� ���� : void free(void* ptr)
-- > �޸� ���� �ʼ�

������ �� ������ ��α� :
https://dsnight.tistory.com/51*/

#define _CRTDBG_MAP_ALLOC // CRT �� �Լ��� �⺻ ������ �ش� ����� ������ ����
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h> // malloc �� free �Լ��� �ش� ����� ������ _malloc_dbg �� _free_dbg�� ���εǾ� �޸� �Ҵ� �� �Ҵ� ������ ���� �����ϰ� ��


int main() {
	int arr_1[5];	// �迭 ����
	int* arr_2;		// ������ ���� ����
	int i;

	for (i = 0; i < 5; i++) {
		arr_1[i] = i + 1;	// �迭�� �� ����
	}

	arr_2 = (int*)malloc(sizeof(int) * 5);	// �޸� �Ҵ�, �迭�� ũ�⸸ŭ �Ҵ��ϱ� ���� 5�� ����

	for (i = 0; i < 5; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	free(arr_2);	// free�Լ��� �̿��Ͽ� �޸� ����

	_CrtDumpMemoryLeaks(); // ���� ����� �� �޸� ���� ������ ǥ��

	return 0;
}

#define _CRTDBG_MAP_ALLOC // CRT �� �Լ��� �⺻ ������ �ش� ����� ������ ����
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h> // malloc �� free �Լ��� �ش� ����� ������ _malloc_dbg �� _free_dbg�� ���εǾ� �޸� �Ҵ� �� �Ҵ� ������ ���� �����ϰ� ��

int main() {
	int arr_1[5];	// �迭 ����
	int* arr_2;		// ������ ���� ����
	int i;

	for (i = 0; i < 5; i++) {
		arr_1[i] = i + 1;	// �迭�� �� ����
	}

	//arr_2 = (int*) malloc(sizeof(int)*5);	// �޸� �Ҵ�, �迭�� ũ�⸸ŭ �Ҵ��ϱ� ���� 5�� ����
	arr_2 = (int*)calloc(5, sizeof(int));	// sizoe(int)ũ���� ������ 5�� ������ �� �ִ� �����Ҵ�

	for (i = 0; i < 5; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	free(arr_2);	// free�Լ��� �̿��Ͽ� �޸� ����

	_CrtDumpMemoryLeaks(); // ���� ����� �� �޸� ���� ������ ǥ��

	return 0;
}

#define _CRTDBG_MAP_ALLOC // CRT �� �Լ��� �⺻ ������ �ش� ����� ������ ����
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h> // malloc �� free �Լ��� �ش� ����� ������ _malloc_dbg �� _free_dbg�� ���εǾ� �޸� �Ҵ� �� �Ҵ� ������ ���� �����ϰ� ��

int main() {
	int arr_1[10];	// �迭 ����
	int* arr_2;		// ������ ���� ����
	int i;

	for (i = 0; i < 10; i++) {
		arr_1[i] = i + 1;	// �迭�� �� ����
	}

	arr_2 = (int*)malloc(sizeof(int) * 5);	// �޸� �Ҵ�, �迭�� ũ�⸸ŭ �Ҵ��ϱ� ���� 5�� ����

	for (i = 0; i < 5; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	printf("\n");

	// sizeof(int) = 4����Ʈ
	realloc(arr_2, sizeof(int) * 10);	// arr_2�� �޸𸮸� 40����Ʈ�� �� �Ҵ�
	// arr_2�� �޸� ũ�� : 20����Ʈ -> 40����Ʈ

	for (i = 0; i < 10; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	free(arr_2);	// free�Լ��� �̿��Ͽ� �޸� ����

	_CrtDumpMemoryLeaks(); // ���� ����� �� �޸� ���� ������ ǥ��

	return 0;
}