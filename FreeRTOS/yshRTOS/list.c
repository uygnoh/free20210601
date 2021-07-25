#include "list.h"

void list_item_initialize(list_item_t *const item)
{
	//初始化该节点所在的链表为空，表示节点还没有插入任何链表
	item->container = NULL;
}

void list_initialize(list_t *const list)
{
	//将链表索引指针指向最后一个节点
	list->index = (list_item_t *)&(list->list_end);
	
	//将链表最后一个节点的辅助排序值设置为最大，确保该节点就是链表的最后节点
	list->list_end.item_value = MAX_VALUE;
	
	//将最后一个节点的next和prev指针均指向节点自身，表示链表为空
	list->list_end.next = (list_item_t *)&(list->list_end);
	list->list_end.prev = (list_item_t *)&(list->list_end);
	
	//初始化链表节点计数器为0， 表示链表为空
	list->item_counter = (uint32_t)0U;
}

/* 将节点插入链表的尾部 */
void list_insert_end(list_t *const list, list_item_t *const new_list_item)
{
	list_item_t *const index = list->index;
	
	new_list_item->next = index;
	new_list_item->prev = index->prev;
	index->prev->next   = new_list_item;
	index->prev         = new_list_item;
	
	//记住该节点所在的链表
	new_list_item->container = (void *)list;
	//链表节点计数器++
	(list->item_counter)++;
}

/* 将节点按照升序排列插入到链表中 */
void list_insert(lit_t *const list, list_item *const new_list_item)
{
	list_item_t *iterator;
	
	//获取插入节点的排序辅助值
	const uint32_t insert_value = new_list_item->item_value;
	
	//寻找节点要插入的位置
	if (insert_value == MAX_DELAY) 
		iterator = list->list_end.prev;
	else 
		for (iterator = (list_item_t *)&(list->list_end);
			iterator->next->iterm_value <= insert_value;
				iterator = iterator->next);
	//根据升序排序，将节点插入
	new_list_item->next = iterator->next;
	new_list_item->next->prev = new_list_item;
	new_list_item->prev = iterator;
	iterator->next = new_list_item;
	
	//记住该节点所在链表
	new_list_item->container = (void *)list;
	//链表节点计数器++
	(list->item_counter)++;
}

uint32_t list_remove(list_item *const item_remove)
{
	//获取节点所在链表
	list_t *const list = (list_t *)item_remove->container;
	//将指定的节点从链表中删除
	item_remove->next->prev = item_remove->prev;
	item_remove->prev->next = item_remove->next;
	
	//调整链表的节点索引指针
	if (list->index == item_remove)
		list->index = item_remove->prev;
	
	//初始化该节点所在的链表为空，表示节点还没有插入任何链表
	item_remove->container = NULL;
	
	//链表节点计数器--
	(list->item_counter)--;
	//返回链表中剩余节点的个数
	return list->item_counter;
}
