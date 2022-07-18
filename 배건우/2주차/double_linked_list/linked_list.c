#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void init(float_double_linked_list *list) // list �ʱ�ȭ
{
  float_node *head_node = (float_node *)malloc(sizeof(float_node));
  float_node *tail_node = (float_node *)malloc(sizeof(float_node));
  list->head = head_node;
  list->tail = tail_node;
}

float_node *peek(float_double_linked_list *list, const int index) // index��ġ���ִ� node����
{
  float_node *peeked_node = list->head; // head�� peeked_node�� ����
  for (int i = 0; i < index && peeked_node != NULL; ++i)
    peeked_node = peeked_node->next;
  return peeked_node;
}

float_node *find(float_double_linked_list *list, const float value) // value�����Ͱ� �����ϴ� ��� ����
{
  for (float_node *nowNode = list->head; nowNode != NULL; nowNode = nowNode->next)
  {
    if (nowNode->data = value)
      return nowNode;
  }
  return NULL;
}

int insert(float_double_linked_list *list, const int index, const float value)
{
  float_node *target_node, *previous_node;
  float_node *insert_node = create_node(value);

  int i;
  previous_node = NULL;
  for (target_node = list->head, i = 0; i < index && target_node != NULL; ++i, target_node = target_node->next)
  {
    previous_node = target_node;
  }

  if (target_node == NULL)
  {
    return 0;
  }

  else
  {
    if (index == 0) // head�� �������
    {
      insert_node->next = list->head; // insert_node�� ������ head�� ����
      list->head->prev = insert_node; // head�� ����尡 insert_node
      list->head = insert_node;       // head�� insert_node�� ����
    }
    else //�߰��� �����ϴ°��
    {
      previous_node->next = insert_node; // previous_node�� ������ insert_node�� ����
      insert_node->next = target_node;   // insert_node�� ������ target_node�� ����
      insert_node->prev = previous_node; // insert_node�� ����尡 previose_node�� ����
      target_node->prev = insert_node;   // target_node�� ����尡 insert_node�� ����
    }
    return 1;
  }
}

void push_back(float_double_linked_list *list, const float value)
{
  float_node *newNode = create_node(value);
  float_node *pre_node = list->tail->prev;
  pre_node->next = newNode;
  newNode->prev = pre_node;
  newNode->next = list->tail;
}

void push_front(float_double_linked_list *list, const float value)
{
  float_node *newNode = create_node(value);
  newNode->next = list->head;
  list->head->prev = newNode;
  list->head = newNode;
}

int delete (float_double_linked_list *list, const int index)
{
  float_node *delete_node, *previous_node;
  int i;
  previous_node = NULL;
  for (delete_node = list->head, i = 0; i < index && delete_node != NULL; ++i, delete_node = delete_node->next)
  {
    previous_node = delete_node;
  }
  if (delete_node == NULL)
  {
    return 0;
  }
  else
  {
    if (index == 0) //������� ��尡 head�ϰ��
    {
      list->head = list->head->next;
      list->head->prev = NULL;
    }
    else if (delete_node == list->tail) //������� ��尡 tail�ϰ��
    {
      list->tail = previous_node;
      list->tail->next = NULL;
    }
    else //���̿��ִ� ��带 ���ﶧ
    {
      previous_node->next = delete_node->next;
      delete_node->next->prev = previous_node;
    }
    free_node(delete_node);
    return 1;
  }
}

float_node *create_node(float data) //��� �Ѱ��� �����ϴ� �޼ҵ�
{
  float_node *node = (float_node *)malloc(sizeof(float_node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void free_node(float_node *Node)
{
  free(Node);
}

void print_list(float_double_linked_list *list)
{
  for (float_node *node = list->head; node != NULL; node = node->next)
  {
    printf("%f ", node->data);
  }
}
