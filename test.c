/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
	test for list.h 0.0.1
	Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "other.h"
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
static int global__flag_debug = 0;
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* view list items */
void view(const char *name, list_t *plist)
{
	list_item_t *i;


	if (global__flag_debug == 1)
	{
		printf("-[%s]----------------\n", name);
	}

	for (i = list_begin(plist); i != NULL; i = list_inc(i))
	{
		if (global__flag_debug == 1)
		{
			printf("\"%s\"\n", (char *)list_val(i));
		}
	}

	if (global__flag_debug == 1)
	{
		printf("------------------} %s\n", name);
	}
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* reverse view list items */
void view_reverse(const char *name, list_t *plist)
{
	list_item_t *i;


	if (global__flag_debug == 1)
	{
		printf("-[%s]----------------\n", name);
	}

	for (i = list_end(plist); i != NULL; i = list_dec(i))
	{
		if (global__flag_debug == 1)
		{
			printf("\"%s\"\n", (char *)list_val(i));
		}
	}

	if (global__flag_debug == 1)
	{
		printf("------------------} %s\n", name);
	}
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* view list items and clear list */
void view_and_clear(const char *name, list_t *plist)
{
	if (global__flag_debug == 1)
	{
		printf("-[%s]----------------\n", name);
	}

	while (list_empty(plist) == 0)
	{
		char *p = (char *)list_pop_front(plist);
		if (global__flag_debug == 1)
		{
			printf("\"%s\"\n", p);
		}
	}

	if (global__flag_debug == 1)
	{
		printf("------------------} %s\n", name);
	}
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* test002 */
int test002(list_t *plist1, list_t *plist2)
{
	list_item_t *i;
	char *p;


	if (list_push_back(plist1, "1") == -1)
	{
		printf("error[test002::step001]: list_push_back()\n");
		return -1;
	}

	if (list_push_back(plist1, "2") == -1)
	{
		printf("error[test002::step002]: list_push_back()\n");
		return -1;
	}

	if (list_push_back(plist2, "3") == -1)
	{
		printf("error[test002::step003]: list_push_back()\n");
		return -1;
	}

	if (list_push_back(plist2, "4") == -1)
	{
		printf("error[test002::step004]: list_push_back()\n");
		return -1;
	}

	if (list_push_back(plist1, "5") == -1)
	{
		printf("error[test002::step005]: list_push_back()\n");
		return -1;
	}

	if (list_push_back(plist1, "6") == -1)
	{
		printf("error[test002::step006]: list_push_back()\n");
		return -1;
	}

	if (list_size(plist1) != 4)
	{
		printf("error[test002::step007]: list_size()\n");
		return -1;
	}

	if (list_size(plist2) != 2)
	{
		printf("error[test002::step008]: list_size()\n");
		return -1;
	}

	view("test002::step009", plist1);

	view_reverse("test002::step010", plist1);

	i = list_begin(plist1);
	if (i == NULL)
	{
		printf("error[test002::step011]: list_begin()\n");
		return -1;
	}

	i = list_inc(i);
	if (i == NULL)
	{
		printf("error[test002::step012]: list_inc()\n");
		return -1;
	}

	i = list_inc(i);
	if (i == NULL)
	{
		printf("error[test002::step013]: list_inc()\n");
		return -1;
	}

	p = (char *)list_val(i);
	if (strcmp(p, "5") != 0)
	{
		printf("error[test002::step014]: list_val()\n");
		return -1;
	}

	if (global__flag_debug == 1)
	{
		printf("test002::step015 val:\"%s\"\n", p);
	}

	if (list_merge(plist1, i, plist2) == -1)
	{
		printf("error[test002::step016]: list_merge()\n");
		return -1;
	}

	view("test002::step017", plist1);

	view_reverse("test002::step018", plist1);

	view("test002::step019", plist2);

	i = list_begin(plist1);
	if (i == NULL)
	{
		printf("error[test002::step020]: list_begin()\n");
		return -1;
	}

	if (global__flag_debug == 1)
	{
		printf("test002::step021 begin(): \"%s\"\n", (char *)list_val(i));
	}

	i = list_end(plist1);
	if (i == NULL)
	{
		printf("error[test002::step022]: list_begin()\n");
		return -1;
	}

	if (global__flag_debug == 1)
	{
		printf("test002::step023 end(): \"%s\"\n", (char *)list_val(i));
	}

	p = (char *)list_pop_front(plist1);
	if (strcmp(p, "1") != 0)
	{
		printf("error[test002::step024]: list_pop_front()\n");
		return -1;
	}

	if (global__flag_debug == 1)
	{
		printf("test002::step025 list_pop_front:\"%s\"\n", p);
	}

	view_reverse("test002::step026", plist1);

	if (list_size(plist1) != 5)
	{
		printf("error[test002::step027]: list_size()\n");
		return -1;
	}

	if (list_size(plist2) != 2)
	{
		printf("error[test002::step028]: list_size()\n");
		return -1;
	}

	i = list_begin(plist1);
	if (i == NULL)
	{
		printf("error[test002::step029]: list_begin()\n");
		return -1;
	}

	if (strcmp("2", (char *)list_val(i)) != 0)
	{
		printf("error[test002::step030]: list_val()\n");
		return -1;
	}

	i = list_inc(i);
	if (i == NULL)
	{
		printf("error[test002::step031]: list_inc()\n");
		return -1;
	}

	if (strcmp("3", (char *)list_val(i)) != 0)
	{
		printf("error[test002::step032]: list_val()\n");
		return -1;
	}

	i = list_inc(i);
	if (i == NULL)
	{
		printf("error[test002::step033]: list_inc()\n");
		return -1;
	}

	if (strcmp("4", (char *)list_val(i)) != 0)
	{
		printf("error[test002::step034]: list_val()\n");
		return -1;
	}

	i = list_inc(i);
	if (i == NULL)
	{
		printf("error[test002::step035]: list_inc()\n");
		return -1;
	}

	if (strcmp("5", (char *)list_val(i)) != 0)
	{
		printf("error[test002::step036]: list_val()\n");
		return -1;
	}

	i = list_inc(i);
	if (i == NULL)
	{
		printf("error[test002::step037]: list_inc()\n");
		return -1;
	}

	if (strcmp("6", (char *)list_val(i)) != 0)
	{
		printf("error[test002::step038]: list_val()\n");
		return -1;
	}

	if (global__flag_debug == 1)
	{
		printf("test002::step039 list1.size(): %u\n", (unsigned int)list_size(plist1));
		printf("test002::step040 list2.size(): %u\n", (unsigned int)list_size(plist2));
	}

	view_and_clear("test002::step041", plist1);

	if (list_size(plist1) != 0)
	{
		printf("error[test002::step042]: list_size()\n");
		return -1;
	}

	view_and_clear("test002::step043", plist2);

	if (list_size(plist2) != 0)
	{
		printf("error[test002::step044]: list_size()\n");
		return -1;
	}


	return 0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* test001 */
int test001(list_t *plist1)
{
	list_item_t *i;
	char *p;


	if (list_push_back(plist1, "a") == -1)
	{
		printf("error[test001::step001]: list_push_back()\n");
		return -1;
	}

	if (list_push_back(plist1, "b") == -1)
	{
		printf("error[test001::step002]: list_push_back()\n");
		return -1;
	}

	if (list_push_back(plist1, "c") == -1)
	{
		printf("error[test001::step003]: list_push_back()\n");
		return -1;
	}

	if (list_size(plist1) != 3)
	{
		printf("error[test001::step004]: list_size()\n");
		return -1;
	}

	p = (char *)list_front(plist1);
	if (p == NULL)
	{
		printf("error[test001::step005]: list_front()\n");
		return -1;
	}

	if (strcmp(p, "a") != 0)
	{
		printf("error[test001::step006]: list_front()\n");
		return -1;
	}

	p = (char *)list_back(plist1);
	if (p == NULL)
	{
		printf("error[test001::step007]: list_back()\n");
		return -1;
	}

	if (strcmp(p, "c") != 0)
	{
		printf("error[test001::step008]: list_back()\n");
		return -1;
	}

	p = (char *)list_pop_front(plist1);
	if (p == NULL)
	{
		printf("error[test001::step009]: list_pop_front()\n");
		return -1;
	}

	if (strcmp(p, "a") != 0)
	{
		printf("error[test001::step010]: list_pop_front()\n");
		return -1;
	}

	if (list_size(plist1) != 2)
	{
		printf("error[test001::step011]: list_size()\n");
		return -1;
	}

	p = (char *)list_pop_back(plist1);
	if (p == NULL)
	{
		printf("error[test001::step012]: list_pop_back()\n");
		return -1;
	}

	if (strcmp(p, "c") != 0)
	{
		printf("error[test001::step013]: list_pop_back()\n");
		return -1;
	}

	if (list_size(plist1) != 1)
	{
		printf("error[test001::step014]: list_size()\n");
		return -1;
	}

	if (list_empty(plist1) != 0)
	{
		printf("error[test001::step015]: list_empty()\n");
		return -1;
	}

	i = list_begin(plist1);
	if (i == NULL)
	{
		printf("error[test001::step016]: list_begin()\n");
		return -1;
	}

	if (strcmp("b", (char *)list_val(i)) != 0)
	{
		printf("error[test001::step017]: list_val()\n");
		return -1;
	}

	list_clear(plist1);

	if (list_size(plist1) != 0)
	{
		printf("error[test001::step018]: list_size()\n");
		return -1;
	}

	if (list_empty(plist1) != 1)
	{
		printf("error[test001::step019]: list_empty()\n");
		return -1;
	}

	if (list_push_front(plist1, "ccc") == -1)
	{
		printf("error[test001::step020]: list_push_front()\n");
		return -1;
	}

	if (list_push_front(plist1, "bbb") == -1)
	{
		printf("error[test001::step021]: list_push_front()\n");
		return -1;
	}

	if (list_push_front(plist1, "aaa") == -1)
	{
		printf("error[test001::step022]: list_push_front()\n");
		return -1;
	}

	if (list_push_back(plist1, "ddd") == -1)
	{
		printf("error[test001::step023]: list_push_back()\n");
		return -1;
	}

	if (list_push_back(plist1, "eee") == -1)
	{
		printf("error[test001::step024]: list_push_back()\n");
		return -1;
	}

	if (list_size(plist1) != 5)
	{
		printf("error[test001::step025]: list_size()\n");
		return -1;
	}

	if (global__flag_debug == 1)
	{
		printf("test001::step026 list1.size(): %u\n", (unsigned int)list_size(plist1));
	}

	view("test001::step027", plist1);

	view_reverse("test001::step028", plist1);

	i = list_begin(plist1);
	if (i == NULL)
	{
		printf("error[test001::step029]: list_begin()\n");
		return -1;
	}


	if (strcmp("aaa", (char *)list_val(i)) != 0)
	{
		printf("error[test001::step030]: list_val()\n");
		return -1;
	}

	if (global__flag_debug == 1)
	{
		printf("test001::step031: list_begin(): \"%s\"\n", (char *)list_val(i));
	}


	i = list_insert(plist1, i, "???");
	if (i == NULL)
	{
		printf("error[test001::step032]: list_insert()\n");
		return -1;
	}

	i = list_insert(plist1, i, "!!!");
	if (i == NULL)
	{
		printf("error[test001::step033]: list_insert()\n");
		return -1;
	}

	view("test001::step017", plist1);

	i = list_erase(plist1, i);
	if (i == NULL)
	{
		printf("error[test001::step034]: list_erase()\n");
		return -1;
	}

	view("test001::step019", plist1);

	i = list_erase(plist1, i);
	if (i == NULL)
	{
		printf("error[test001::step035]: list_erase()\n");
		return -1;
	}

	if (list_size(plist1) != 5)
	{
		printf("error[test001::step036]: list_size()\n");
		return -1;
	}

	view("test001::step037", plist1);

	view_reverse("test001::step038", plist1);

	i = list_begin(plist1);
	if (i == NULL)
	{
		printf("error[test001::step039]: list_begin()\n");
		return -1;
	}

	if (strcmp("aaa", (char *)list_val(i)) != 0)
	{
		printf("error[test001::step040]: list_val()\n");
		return -1;
	}

	i = list_inc(i);
	if (i == NULL)
	{
		printf("error[test001::step041]: list_inc()\n");
		return -1;
	}
	if (strcmp("bbb", (char *)list_val(i)) != 0)
	{
		printf("error[test001::step042]: list_val()\n");
		return -1;
	}

	i = list_inc(i);
	if (i == NULL)
	{
		printf("error[test001::step043]: list_inc()\n");
		return -1;
	}

	if (strcmp("ccc", (char *)list_val(i)) != 0)
	{
		printf("error[test001::step044]: list_val()\n");
		return -1;
	}

	i = list_inc(i);
	if (i == NULL)
	{
		printf("error[test001::step045]: list_inc()\n");
		return -1;
	}

	if (strcmp("ddd", (char *)list_val(i)) != 0)
	{
		printf("error[test001::step046]: list_val()\n");
		return -1;
	}

	i = list_inc(i);
	if (i == NULL)
	{
		printf("error[test001::step047]: list_inc()\n");
		return -1;
	}

	if (strcmp("eee", (char *)list_val(i)) != 0)
	{
		printf("error[test001::step048]: list_val()\n");
		return -1;
	}

	view_and_clear("test001::step049", plist1);

	if (list_size(plist1) != 0)
	{
		printf("error[test001::step050]: list_size()\n");
		return -1;
	}

	if (global__flag_debug == 1)
	{
		printf("test001::step051 list1.size(): %u\n", (unsigned int)list_size(plist1));
	}


	return 0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* run tests */
int do_it()
{
	int rc;
	list_t *plist1;
	list_t *plist2;

/* create list */
	plist1 = list_open();
	if (plist1 == NULL)
	{
		return -1;
	}

/* create list */
	plist2 = list_open();
	if (plist2 == NULL)
	{
		list_close(plist1);
		return -1;
	}

/* run test001() */
	rc = test001(plist1);
	if (rc == -1)
	{
		list_close(plist2);
		list_close(plist1);
		return -1;
	}

/* run test002() */
	rc = test002(plist1, plist2);
	if (rc == -1)
	{
		list_close(plist2);
		list_close(plist1);
		return -1;
	}


	list_close(plist2);
	list_close(plist1);


	return 0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* general function */
int main()
{
	global__flag_debug = env2bool("FLAG_DEBUG", 0);


	if (do_it() == -1)
	{
		return 1;
	}


	printf("ok, test passed\n");
	return 0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
