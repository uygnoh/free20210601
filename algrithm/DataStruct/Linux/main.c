#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node {
        struct list_head head;
        int value;
};
int main(void)
{
        int i;
        
        //创建头节点，并初始化它
        struct node l = {0};
        struct list_head *list = (struct list_head *)&l;
        struct list_head *slider = NULL;
        INIT_LIST_HEAD(list);
        
        //插入操作
        printf("Insert begin ...\n");
        for (i = 0; i < 5; i++) {
                struct node *n = (struct node *)malloc(sizeof(struct node));
                n->value = i;
                list_add_tail((struct list_head *)n, list);
        }
        list_for_each(slider, list) {
                printf("%d\n", ((struct node *)slider)->value);
        }
        printf("Insert end ...\n");
        
        //删除节点操作
        printf("Delete begin ...\n");
        list_for_each(slider, list) {
                if (((struct node *)slider)->value == 3) {
                        list_del(slider);
                        free(slider);
                        break;
                }
        }
        list_for_each(slider, list) {
                printf("%d\n", ((struct node *)slider)->value);
        }
        printf("Delete end ...\n");
        return 0;
}

