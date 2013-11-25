/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
	Double linked list 0.0.1
	Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* item of double linked list */
typedef struct list_item_t
{
	void *pdata;
	struct list_item_t *prev;
	struct list_item_t *next;

} list_item_t;
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* double linked list */
typedef struct
{
	list_item_t *head;
	list_item_t *tail;
	size_t size;

} list_t;
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* alloc and init new list */
extern list_t *list_open();

/* deinit and free list */
extern void list_close(list_t *plist);

/* clear list */
extern void list_clear(list_t *plist);

/* check list size */
extern int list_empty(const list_t *plist);

/* return list size */
extern size_t list_size(const list_t *plist);

/* add pointer in head of list */
extern int list_push_front(list_t *plist, const void *pdata);

/* add pointer in tail of list */
extern int list_push_back(list_t *plist, const void *pdata);

/* return begin iterator */
extern list_item_t *list_begin(const list_t *plist);

/* return end iterator */
extern list_item_t *list_end(const list_t *plist);

/* increment and return iterator */
extern list_item_t *list_inc(list_item_t *item);

/* decrement and return iterator */
extern list_item_t *list_dec(list_item_t *item);

/* get iterator list item and return item value */
extern void        *list_val(const list_item_t *item);

/* return pointer from head of list */
extern void        *list_front(const list_t *plist);

/* return pointer from tail of list */
extern void        *list_back(const list_t *plist);

/* get pointer from head of list, del head item, return pointer */
extern void        *list_pop_front(list_t *plist);

/* get pointer from tail of list, del tail item, return pointer */
extern void        *list_pop_back(list_t *plist);

/* atomic merge other list to current list before iterator */
extern int          list_merge(list_t *plist, list_item_t *item, const list_t *plist_other);

/* insert pointer before iterator */
extern list_item_t *list_insert(list_t *plist, list_item_t *item, const void *pdata);

/* erase pointer in iterator and return next iterator */
extern list_item_t *list_erase(list_t *plist, list_item_t *item);
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#endif
