#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct __float_node
{
  float data;
  struct __float_node *prev;
  struct __float_node *next;
} float_node;

typedef struct __float_double_linked_list
{
  float_node *head;
  float_node *tail;
  int list_size;
} float_double_linked_list;

//���� ���� ����Ʈ ���� �Լ�
void init(float_double_linked_list *list);
float_node *peek(float_double_linked_list *list, const int index);
float_node *find(float_double_linked_list *list, const float target);
void push_back(float_double_linked_list *list, const float value);
void push_front(float_double_linked_list *list, const float value);
int insert(float_double_linked_list *list, const int index, const float value);
void delete_back(float_double_linked_list *list);  // push_back �޼ҵ�Ͱ��� delete_back�� �ۼ���
void delete_front(float_double_linked_list *list); // push_front �޼ҵ�Ͱ��� delete_front�� �ۼ���
int delete (float_double_linked_list *list, const int index);
float_node *create_node(float data);
