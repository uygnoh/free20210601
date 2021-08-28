#ifndef offsetof
#define offsetof(TYPE, MEMBER)                  \
(size_t)(&((TYPE*)0)->MEMBER)
#endif

#ifndef container_of
#define container_of(ptr, type, member)         \
((type *)((char *)ptr - offsetof(type, member)))
#endif

#define LIST_POISON1    (NULL)
#define LIST_POISON2    (NULL)

#define prefetch(x) ((void)x)

#define LIST_HEAD_INIT(name)                    \
{ &(name), &(name) }

#define LIST_HEAD(name)                         \
struct list_head name = LIST_HEAD_INIT(name)



/*******************************************************************************
                           include/linux/list.h
*******************************************************************************/
/* linux/types.h */
struct list_head {
        struct list_head *next;
        struct list_head *prev;
};


//链表节点初始化
static inline void INIT_LIST_HEAD(struct list_head *list)
{
        list->next = list;
        list->prev = list;
}

//链表增加节点公共函数
//new是要增加的节点，prev和next是相邻的节点
static inline void __list_add(struct list_head *new,
                               struct list_head *prev,
                               struct list_head *next)
{
        next->prev = new;
        new->next = next;
        new->prev = prev;
        prev->next = new;
}

//将新节点插入链表的头部
static inline void list_add(struct list_head *new, struct list_head *head)
{
        __list_add(new, head, head->next);
}

//将新节点插入链表的尾部
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
        __list_add(new, head->prev, head);
}

//删除节点
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
        next->prev = prev;
        prev->next = next;
}
static inline void list_del(struct list_head *entry)
{
        __list_del(entry->prev, entry->next);
        entry->next = LIST_POISON1;
        entry->prev = LIST_POISON2;
}

//正向遍历节点
#define list_for_each(pos, head)                        \
        for (pos = (head)->next;                        \
                prefetch(pos->next), pos != (head);     \
                         pos = pos->next)

//反向遍历节点
#define list_for_each_prev(pos, head)                   \
        for (pos = (head)->prev;                        \
                prefetch(pos->prev), pos != (head);     \
                        pos = pos->prev)
                        
                        
                        
