/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*
	Other functions 0.0.1
	Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.online/doc/cv
*/
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libcore.h"
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
int strcasecmp(const char *s1, const char *s2);
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* convert string to bool */
int str2bool(const char *p)
{
	if (strcasecmp(p, "true") == 0) return 1;
	if (strcasecmp(p, "t")    == 0) return 1;
	if (strcasecmp(p, "on")   == 0) return 1;
	if (strcasecmp(p, "1")    == 0) return 1;

	return 0;
}
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* get env var and convert to bool */
int env2bool(const char *name, int value_default)
{
	char *p = getenv(name);
	if (p == NULL)
	{
		return value_default;
	}

	return str2bool(p);
}
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* return (concat str1 and str2) or NULL */
char *concat_str(const char *str1, const char *str2)
{
	size_t str1_size = strlen(str1);
	size_t str2_size = strlen(str2);

	char *str3 = (char *)malloc(str1_size + str2_size + 1);
	if (str3 == NULL)
	{
		return NULL;
	}

	memcpy(str3, str1, str1_size);
	memcpy(str3 + str1_size, str2, str2_size);
	str3[str1_size + str2_size] = 0;

	return str3;
}
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* is unsigned int? */
int is_uint(const char *str)
{
	const char *p = str;
	if (p == NULL) return 1;

	for (;;p++)
	{
		if (*p == 0) break;

		if
		(
			(*p < '0') ||
			(*p > '9')
		)
		{
			return 0;
		}
	}

	if ((p - str) == 0) return 0;

	return 1;
}
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* is signed int? */
int is_sint(const char *str)
{
	const char *p = str;
	if (p == NULL) return 1;

	for (;;p++)
	{
		if (*p == 0) break;

		if
		(
			(*p < '0') ||
			(*p > '9')
		)
		{
			if (p == str)
			{
				if
				(
					(*p == '-') ||
					(*p == '+')
				)
				{
					continue;
				}
			}
			return 0;
		}
	}

	if ((p - str) == 0) return 0;

	return 1;
}
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
