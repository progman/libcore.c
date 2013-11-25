/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
	Double linked list 0.0.1
	Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdlib.h>
#include "list.h"
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* alloc and init new list */
list_t *list_open()
{
	list_t *plist = (list_t *)malloc(sizeof(list_t));
	if (plist != NULL)
	{
		plist->head = NULL;
		plist->tail = NULL;
		plist->size = 0;
	}

	return plist;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* deinit and free list */
void list_close(list_t *plist)
{
	list_clear(plist);

	free(plist);
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* clear list */
void list_clear(list_t *plist)
{
	list_item_t *tmp = plist->head;
	if (tmp == NULL) return;


	for (;;)
	{
		list_item_t *next = tmp->next;
		free(tmp);
		tmp = next;
		if (tmp == NULL) break;
	}


	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* check list size */
int list_empty(const list_t *plist)
{
	if (plist->head == NULL)
	{
		return 1;
	}

	return 0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* return list size */
size_t list_size(const list_t *plist)
{
	return plist->size;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* add pointer in head of list */
int list_push_front(list_t *plist, const void *pdata)
{
	list_item_t *tmp = (list_item_t *)malloc(sizeof(list_item_t));
	if (tmp == NULL) return -1;

	tmp->pdata = (void *)pdata;
	tmp->prev  = NULL;
	tmp->next  = plist->head;


	plist->size++;


	if (plist->head == NULL)
	{
		plist->head = tmp;
		plist->tail = tmp;
		return 0;
	}


	plist->head->prev = tmp;
	plist->head = tmp;


	return 0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* add pointer in tail of list */
int list_push_back(list_t *plist, const void *pdata)
{
	list_item_t *tmp = (list_item_t *)malloc(sizeof(list_item_t));
	if (tmp == NULL) return -1;

	tmp->pdata = (void *)pdata;
	tmp->prev  = plist->tail;
	tmp->next  = NULL;


	plist->size++;


	if (plist->head == NULL)
	{
		plist->head = tmp;
		plist->tail = tmp;
		return 0;
	}


	plist->tail->next = tmp;
	plist->tail = tmp;


	return 0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* return begin iterator */
list_item_t *list_begin(const list_t *plist)
{
	return plist->head;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* return end iterator */
list_item_t *list_end(const list_t *plist)
{
	return plist->tail;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* increment and return iterator */
list_item_t *list_inc(list_item_t *item)
{
	return item->next;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* decrement and return iterator */
list_item_t *list_dec(list_item_t *item)
{
	return item->prev;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* get iterator list item and return item value */
void *list_val(const list_item_t *item)
{
	return item->pdata;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* return pointer from head of list */
void *list_front(const list_t *plist)
{
	list_item_t *pitem = list_begin(plist);
	if (pitem == NULL) return NULL;

	return pitem->pdata;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* return pointer from tail of list */
void *list_back(const list_t *plist)
{
	list_item_t *pitem = list_end(plist);
	if (pitem == NULL) return NULL;

	return pitem->pdata;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* get pointer from head of list, del head item, return pointer */
void *list_pop_front(list_t *plist)
{
	void *pdata = list_front(plist);

	if (plist->head != NULL)
	{
		list_item_t *tmp = plist->head;

		plist->head = tmp->next;
		free(tmp);

		if (plist->head == NULL)
		{
			plist->tail = NULL;
		}
		else
		{
			plist->head->prev = NULL;
		}

		plist->size--;
	}

	return pdata;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* get pointer from tail of list, del tail item, return pointer */
void *list_pop_back(list_t *plist)
{
	void *pdata = list_back(plist);

	if (plist->tail != NULL)
	{
		list_item_t *tmp = plist->tail;

		plist->tail = tmp->prev;
		free(tmp);

		if (plist->tail == NULL)
		{
			plist->head = NULL;
		}
		else
		{
			plist->head->next = NULL;
		}

		plist->size--;
	}

	return pdata;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* atomic merge other list to current list before iterator */
int list_merge(list_t *plist, list_item_t *item, const list_t *plist_other)
{
	list_item_t *head = NULL;
	list_item_t *tail = NULL;
	list_item_t *item_other;
	int flag_ok = 1;


	if (plist_other == NULL) return 0;


	item_other = plist_other->head;
	if (item_other == NULL) return 0;


	for (;;)
	{
		list_item_t *tmp = (list_item_t *)malloc(sizeof(list_item_t));
		if (tmp == NULL)
		{
			flag_ok = 0;
			break;
		}

		tmp->pdata = item_other->pdata;

		if (tail == NULL)
		{
			tmp->prev = NULL;
			tmp->next = NULL;

			head = tmp;
			tail = tmp;
		}
		else
		{
			tmp->prev = tail;
			tmp->next = NULL;

			tail->next = tmp;

			tail = tmp;
		}

		if (item_other->next == NULL) break;

		item_other = item_other->next;
	}


	if (flag_ok == 0)
	{
		while (head != NULL)
		{
			list_item_t *tmp = head->next;
			free(head);

			head = tmp;
		}
		return -1;
	}


	if (item == NULL)
	{
		plist->head = head;
		plist->tail = tail;
	}
	else
	{
		head->prev  = item->prev;
		tail->next  = item;


		if (item->prev == NULL)
		{
			plist->head = head;
		}
		else
		{
			item->prev->next = head;
		}
		item->prev = tail;


		if (item->next == NULL)
		{
			plist->tail = tail;
		}
		else
		{
			item->prev = tail;
		}
	}


	plist->size += plist_other->size;


	return 0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* insert pointer before iterator */
list_item_t *list_insert(list_t *plist, list_item_t *item, const void *pdata)
{
	list_item_t *tmp = (list_item_t *)malloc(sizeof(list_item_t));
	if (tmp == NULL) return NULL;

	tmp->pdata = (void *)pdata;

	if (item == NULL)
	{
		tmp->prev  = NULL;
		tmp->next  = NULL;

		plist->head = tmp;
		plist->tail = tmp;
	}
	else
	{
		tmp->prev  = item->prev;
		tmp->next  = item;
		if (item->prev == NULL)
		{
			plist->head = tmp;
		}
		else
		{
			item->prev->next = tmp;
		}
		item->prev = tmp;
	}

	plist->size++;

	return tmp;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* erase pointer in iterator and return next iterator */
list_item_t *list_erase(list_t *plist, list_item_t *item)
{
	list_item_t *next;


	if (item == NULL) return NULL;

	plist->size--;

	if (item->next == NULL)
	{
		plist->tail = item->prev;
	}
	else
	{
		item->next->prev = item->prev;
	}

	if (item->prev == NULL)
	{
		plist->head = item->next;
	}
	else
	{
		item->prev->next = item->next;
	}


	next = item->next;
	free(item);

	return next;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
