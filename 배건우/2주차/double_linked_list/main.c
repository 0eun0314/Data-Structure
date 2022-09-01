#include "linked_list.h"
#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float_double_linked_list *L = (float_double_linked_list *)malloc(sizeof(float_double_linked_list));
  init(L); // L �ʱ�ȭ

  push_front(L, 1.0); // head �տ� �߰�
  push_front(L, 2.0);
  push_front(L, 3.0);
  push_front(L, 4.0);
  print_list(L);     //���
  push_back(L, 1.0); // tail �ڿ� �߰�
  push_back(L, 2.0);
  push_back(L, 3.0);
  push_back(L, 4.0);
  print_list(L);   //���
  delete_back(L);  // tail����
  delete_front(L); // head����
  print_list(L);   //���

  insert(L, 1, 8.0); // index���������� value����
  print_list(L);     //���

  free(L); //�Ҵ� ����

  return 0;
}
