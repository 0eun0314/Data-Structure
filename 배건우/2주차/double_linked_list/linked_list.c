#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void init(float_double_linked_list *list) // list �ʱ�ȭ
{
  list->head = list->tail = NULL;
  list->list_size = 0;
}

float_node *peek(float_double_linked_list *list, const int index) // index��ġ���ִ� node����
{
  float_node *peeked_node = list->head; // head�� peeked_node�� ����
  for (int i = 0; i < index && peeked_node != NULL; ++i, peeked_node = peeked_node->next)
    return peeked_node;
}

float_node *find(float_double_linked_list *list, const float value) // value�����Ͱ� �����ϴ� ��� ����
{
  for (float_node *nowNode = list->head; nowNode != NULL; nowNode = nowNode->next)
  {
    if (nowNode->data == value)
      return nowNode;
  }
  return NULL;
}

void push_back(float_double_linked_list *list, const float value) // tail�ڿ� ����
{
  float_node *newNode = create_node(value);
  if (list->head == NULL) // head�� ����ִ°��
  {
    list->head = list->tail = newNode;
    list->tail->prev = newNode;
    list->tail->next = newNode;
  }
  else
  {
    newNode->prev = list->tail;
    newNode->next = list->tail->next;
    list->tail->next = newNode;
    list->head->prev = newNode;
    list->tail = newNode;
  }
  list->list_size++;
}

void push_front(float_double_linked_list *list, const float value) // head�տ� ����
{
  float_node *newNode = create_node(value);
  if (list->head == NULL) // head�� ����ִ°��
  {
    list->head = list->tail = newNode;
    list->head->prev = newNode;
    list->head->next = newNode;
  }
  else
  {
    newNode->prev = list->head->prev;
    newNode->next = list->head;
    list->head->prev = newNode;
    list->tail->next = newNode;
    list->head = newNode;
  }
  list->list_size++;
}

int insert(float_double_linked_list *list, const int index, const float value)
{
  float_node *new_node = create_node(value);
  float_node *current_node;

  if (index <= list->list_size) //���� ���� �ε����� ���� ����
  {
    if (index == 1) // head�� �տ� �����ϰ������
    {
      push_front(list, value);
      return 1;
    }
    else if (index == list->list_size) // tail�ڿ� �����ϰ������
    {
      push_back(list, value);
      return 1;
    }
    else //�߰��� �����ϰ������
    {
      int n = index - 1;         //���� int n�� �������ִ� ������ index�� const int �̱⶧��
      current_node = list->head; //�ӽ��� ���� node�� head�� ����
      while (--n)
      { // ���� �ְ� ���� �ڸ� �ٷ� ������ current_node�� �����ȴ�.
        current_node = current_node->next;
      }
      new_node->prev = current_node;
      new_node->next = current_node->next;
      current_node->next = new_node;
      new_node->next->prev = new_node;
      ++list->list_size;
      return 1;
    }
  }
  return 0;
}

void delete_back(float_double_linked_list *list)
{
  float_node *current_node;
  float_node *tmp;
  tmp = list->tail;

  if (tmp == NULL) // list->tail�� ����������
  {
    puts("list�� �������\n");
  }
  else
  {
    current_node = list->tail->prev;
    current_node->next = list->head;
    list->head->prev = current_node;
    list->tail = current_node;
    free(tmp); //�Ҵ� ����
    list->list_size--;
  }
}

void delete_front(float_double_linked_list *list)
{
  float_node *current_node;
  float_node *tmp;
  tmp = list->head; // tmp�� list->head�� �ʱ�ȭ

  if (tmp == NULL) // list->head�� ����ִ°��
  {
    puts("list�� �������\n");
  }
  else
  {
    current_node = list->head->next;
    current_node->prev = list->head->prev;
    list->tail->next = current_node;
    list->head = current_node;
    free(tmp); //�Ҵ� ����
    list->list_size--;
  }
}

int delete (float_double_linked_list *list, const int index) // node ���� �޼ҵ�
{
  float_node *current_node;
  float_node *tmp;

  if (index <= list->list_size) //���� ���� index�� ���� ���ǹ�
  {
    if (list->head == NULL) // head�� ����ִ°��
    {
      puts("list�� �������\n");
      return 0;
    }
    else if (index == 1) // head�� �����ϰ�������
    {
      delete_front(list);
      return 1;
    }
    else if (index == list->list_size) // tail�� �����ϰ�������
    {
      delete_back(list);
      return 1;
    }
    else //�߰��� index�� �����ϰ�������
    {
      int n = index;
      current_node = list->head;
      while (--n)
      { // ���� ����� ���� �ڸ��� current_node�� �����ȴ�.
        current_node = current_node->next;
      }
      tmp = current_node;
      current_node->prev->next = current_node->next;
      current_node->next->prev = current_node->prev;
      free(tmp);
      list->list_size--;
      return 1;
    }
  }
  return 0;
}

float_node *create_node(float data) //��� �Ѱ��� �����ϴ� �޼ҵ�
{
  float_node *node = (float_node *)malloc(sizeof(float_node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void print_list(float_double_linked_list *list) // node�� data�� ����ϴ� �޼ҵ�
{
  float_node *current_node;
  current_node = list->head;
  if (current_node == NULL)
  {
    puts("list�� �������\n");
  }
  else
  {
    int index = 1;
    while (index <= list->list_size) //��������  index�� ����
    {
      printf("L[%d] = %f\n", index, current_node->data);
      current_node = current_node->next; //����� �������� �ʱ�ȭ
      index++;                           // index����
    }
  }
  printf("\n");
}
