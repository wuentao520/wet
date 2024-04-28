#include<stdio.h>
#include<stdlib.h> 
typedef struct Node
{
    int password;                     //ÿ���˳��е�����
    int num;                          //��Ա�ı��
    struct Node* next;                //ָ����һ���ڵ�
}Node, * Link;
//����һ���յ�����
void InitList(Link& L)
{
    L = (Node*)malloc(sizeof(Node));
    if (!L) exit(1);
    L->password = 0;
    L->num = 0;
    L->next = L;
}
//��ʼ��������ʼ����Ա��ź�����ÿ���˵�����
void Creater(int n, Link& L)
{
    Link p, q;
    q = L;
    for (int i = 1; i <= n; i++)
    {
        p = (Node*)malloc(sizeof(Node));
        if (!p) exit(1);
        printf("������� %d ���˵����� : ", i);
        scanf_s("%d", &p->password);
        p->num = i;
        L->next = p;
        L = p;
    }
    L->next = q->next;
    free(q);
}
//��������ִ��Լɪ�򻷵�����
void main()
{
    printf("*********************Լɪ��********************* \n");
    Link L, p, q;
    int n, m;
    int a = 1;
    int b = 1;
    //����һ��ѭ����䣬������ʵ��Լɪ������������Ƿ����ִ��
    while (b == 1)
    {
        L = NULL;
        InitList(L);                      //�����һ��ֻ��ͷ���Ŀ�����
        printf("������������ N: \n");
        scanf_s("%d", &n);                   //�����ܹ������� n
        while (n <= 1)                       //�ж�������ֵ�Ƿ�����
        {
            printf("����������������������������1����������\n");
            scanf_s("%d", &n);
        }
        printf("�������ʼ������ֵ M (������):\n ");
        scanf_s("%d", &m);                   //�����ʼ������ֵ m
        while (m < 0)                        //�ж�������ֵ�Ƿ�����
        {
            printf("��������ֵ�������������룺\n");
            scanf_s("%d", &m);
        }
        Creater(n, L);
        printf("���ճ��е�˳��Ϊ : \n"); //����һ��ѭ���б������ʼ��ź�����ÿ���˵����룬����һ��Լɪ��
        p = L;
        for (int i = 1; i <= n; i++)            //����Լɪ�򻷵���Ҫʵ��
        {
            for (int j = 1; j < m; j++)         //�ҵ������Ӧ�Ľڵ�
            {
                p = p->next;
            }
            q = p->next;
            m = q->password;               //���¸�ֵ������ֵ
            printf("%d  ", q->num);
            p->next = q->next;             //����һ���ڵ��Ϊͷ���
            free(q);
        }
        printf("\n");
        printf("�Ƿ���������������� (1.���� 0.�˳�):\n ");
        scanf_s("%d", &b);
        printf("\n\n\n");
    }
}