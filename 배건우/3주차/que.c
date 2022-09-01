#include "que.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  Queue Q;
  init_queue(&Q); //ť �ʱ�ȭ

  int n, k, tmp;

  printf("n�� k�� �Է��ϼ���\n");
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; i++)
  {
    push(&Q, i + 1); // 1~n������ ���� que�� push
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k - 1; j++)
    {
      tmp = pop(&Q); // que�� �պκп��� k��° ������ ���� pop�� ���� tmp�� �����ϰ�
      push(&Q, tmp); // tmp�� que�� �޺κп� ����
    }
    if (size(&Q) == 1) //ť�ȿ� ���� 1�������ִٸ� break
      break;

    tmp = pop(&Q); //���⼭ tmp�� ������k��°�� ���� ����Ű���ִ�.
    printf("%d ", tmp);
  }
  printf("%d", pop(&Q)); //�����ִ� ������que�� �ܿ����� ������־���Ѵ�.(���� �ݺ������� break�� ����̱⶧��)

  return 0;
}