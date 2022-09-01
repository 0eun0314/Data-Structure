typedef struct __example_node
{
  //���� ���� ����Ʈ�� ���
  int data;
  struct __example_node *next;
} example_node;

typedef struct __example_list
{
  example_node *head, *tail;
} example_list; // head �� tail �� �����ϴ� ���� ���Ḯ��Ʈ

//���� ���� ����Ʈ ���� �Լ� ����
void init_example(example_list *list);
example_node *peek_example(example_list *list, const int at);
example_node *find_example(example_list *list, const int target);
int insert_example(example_list *list, const int at, const int value);
void push_back_example(example_list *list, const int value);
void push_front_example(example_list *list, const int value);
int delete_example(example_list *list, const int at);
example_node *create_example_node(int data);
