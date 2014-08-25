#include "../../include/include.h"

void *xmalloc(size_t size)
{
	void *ret;

	ret = malloc(size);
	if (ret != 0)
	{
		return (ret);
	}
	else
	{
		printf("Malloc said fuck off !");
		exit(0);
	}
}
