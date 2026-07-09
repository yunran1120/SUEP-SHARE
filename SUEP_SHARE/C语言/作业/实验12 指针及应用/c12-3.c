/* c12-3.c  */
#include <stdio.h>
#include <stdlib.h>

/* 定义单链表结点类型 */
struct Node {
    int data;               /* 数据域 */
    struct Node *next;      /* 指针域，指向下一个结点 */
};

/* 函数声明 */
struct Node* create_node(int data);                 /* 创建新结点 */
void insert_head(struct Node **head, int data);     /* 头插法 */
void insert_tail(struct Node **head, int data);     /* 尾插法 */
struct Node* find(struct Node *head, int data);     /* 查找结点 */
int delete_node(struct Node **head, int data);      /* 删除结点 */
void print_list(struct Node *head);                 /* 打印链表 */
void free_list(struct Node **head);                 /* 释放链表 */

int main() {
    struct Node *head = NULL;   /* 链表头指针，初始为空 */
    int choice, val;
    struct Node *p;

    while (1) {
        printf("\n======== 单链表操作菜单 ========\n");
        printf("1. 头插法插入结点\n");
        printf("2. 尾插法插入结点\n");
        printf("3. 查找结点\n");
        printf("4. 删除结点\n");
        printf("5. 打印链表\n");
        printf("6. 退出\n");
        printf("请输入你的选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("请输入要插入的数据: ");
            scanf("%d", &val);
            insert_head(&head, val);
            break;
        case 2:
            printf("请输入要插入的数据: ");
            scanf("%d", &val);
            insert_tail(&head, val);
            break;
        case 3:
            printf("请输入要查找的数据: ");
            scanf("%d", &val);
            p = find(head, val);
            if (p != NULL)
                printf("找到了结点，地址为 %p，数据为 %d\n", (void*)p, p->data);
            else
                printf("未找到值为 %d 的结点。\n", val);
            break;
        case 4:
            printf("请输入要删除的数据: ");
            scanf("%d", &val);
            if (delete_node(&head, val))
                printf("删除成功！\n");
            else
                printf("未找到值为 %d 的结点，删除失败。\n", val);
            break;
        case 5:
            printf("当前链表: ");
            print_list(head);
            break;
        case 6:
            free_list(&head);
            printf("链表已释放，程序退出。\n");
            return 0;
        default:
            printf("无效选择，请重新输入。\n");
        }
    }
}

/* 创建新结点，返回指向该结点的指针 */
struct Node* create_node(int data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* 头插法：新结点成为链表第一个结点 */
void insert_head(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    new_node->next = *head;   /* 新结点指向原第一个结点 */
    *head = new_node;         /* 头指针指向新结点 */
}

/* 尾插法：新结点添加到链表末尾 */
void insert_tail(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;     /* 空链表，新结点即为头结点 */
        return;
    }
    /* 遍历到最后一个结点 */
    struct Node *p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new_node;
}

/* 查找第一个数据域等于 data 的结点，返回结点指针，未找到返回 NULL */
struct Node* find(struct Node *head, int data) {
    struct Node *p = head;
    while (p != NULL) {
        if (p->data == data)
            return p;
        p = p->next;
    }
    return NULL;
}

/* 删除第一个数据域等于 data 的结点，成功返回1，失败返回0 */
int delete_node(struct Node **head, int data) {
    struct Node *p = *head, *prev = NULL;
    while (p != NULL && p->data != data) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) return 0;   /* 未找到 */

    if (prev == NULL) {        /* 要删除的是头结点 */
        *head = p->next;
    } else {
        prev->next = p->next;
    }
    free(p);
    return 1;
}

/* 打印链表所有结点数据 */
void print_list(struct Node *head) {
    struct Node *p = head;
    if (p == NULL) {
        printf("(空链表)\n");
        return;
    }
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

/* 释放链表所有结点占用的内存 */
void free_list(struct Node **head) {
    struct Node *p = *head, *temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    *head = NULL;
}