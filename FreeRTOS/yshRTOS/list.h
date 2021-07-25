#ifndef __LIST_H__
#define __LIST_H__

struct list_item {
	uint32_t item_value;		//辅助值，用于帮助节点做顺序排列
	struct list_item *next;		//指向链表下一个节点
	struct list_item *prev;		//指向链表前一个节点
	void *owner;			//指向拥有该节点的内核对象，通常是TCB
	void *container;		//指向该节点所在的链表，通常指向链表的根节点
};
typedef list_item List_item_t;		//节点数据类型重定义

struct mini_list_item {
	uint32_t item_value;		//辅助值，用于帮助节点做顺序排列
	struct list_item *next;		//指向链表下一个节点
	struct list_item *prev;		//指向链表前一个节点
};
typedef struct mini_list_item mini_list_item_t;

struct list {
	uint32_t item_counter;		//链表节点计数器
	list_item_t *index;		//链表节点索引指针
	mini_list_item_t list_end;	//链表最后一个节点
};
typedef struct list list_t;

#endif
