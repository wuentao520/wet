#include<stdio.h>
#include<stdlib.h> 
typedef struct Node
{
    int password;                     //每个人持有的密码
    int num;                          //人员的编号
    struct Node* next;                //指向下一个节点
}Node, * Link;
//创建一个空的链表
void InitList(Link& L)
{
    L = (Node*)malloc(sizeof(Node));
    if (!L) exit(1);
    L->password = 0;
    L->num = 0;
    L->next = L;
}
//初始化链表，初始化人员编号和输入每个人的密码
void Creater(int n, Link& L)
{
    Link p, q;
    q = L;
    for (int i = 1; i <= n; i++)
    {
        p = (Node*)malloc(sizeof(Node));
        if (!p) exit(1);
        printf("请输入第 %d 个人的密码 : ", i);
        scanf_s("%d", &p->password);
        p->num = i;
        L->next = p;
        L = p;
    }
    L->next = q->next;
    free(q);
}
//主函数，执行约瑟夫环的运行
void main()
{
    printf("*********************约瑟夫环********************* \n");
    Link L, p, q;
    int n, m;
    int a = 1;
    int b = 1;
    //创建一个循环语句，用于在实现约瑟夫环运算结束后是否继续执行
    while (b == 1)
    {
        L = NULL;
        InitList(L);                      //构造出一个只有头结点的空链表
        printf("请输入总人数 N: \n");
        scanf_s("%d", &n);                   //输入总共的人数 n
        while (n <= 1)                       //判断输入数值是否有误
        {
            printf("输入的总人数有误，请重新输入大于1的总人数：\n");
            scanf_s("%d", &n);
        }
        printf("请输入初始的上限值 M (正整数):\n ");
        scanf_s("%d", &m);                   //输入初始的上限值 m
        while (m < 0)                        //判断输入数值是否有误
        {
            printf("输入上限值有误，请重新输入：\n");
            scanf_s("%d", &m);
        }
        Creater(n, L);
        printf("最终出列的顺序为 : \n"); //建立一个循环列表，赋予初始编号和输入每个人的密码，构成一个约瑟夫环
        p = L;
        for (int i = 1; i <= n; i++)            //关于约瑟夫环的主要实现
        {
            for (int j = 1; j < m; j++)         //找到密码对应的节点
            {
                p = p->next;
            }
            q = p->next;
            m = q->password;               //重新赋值给上限值
            printf("%d  ", q->num);
            p->next = q->next;             //让下一个节点成为头结点
            free(q);
        }
        printf("\n");
        printf("是否继续重新输入运算 (1.继续 0.退出):\n ");
        scanf_s("%d", &b);
        printf("\n\n\n");
    }
}