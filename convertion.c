#include <stdlib.h>
#include "minitalk.h"

int   *char_to_binary(unsigned char c)
{
	int  *arr;
	int  i;

	arr = malloc(8 * sizeof(int));
	if (!arr)
		return NULL;
	i = 7;
	while (i >= 0)
	{
		arr[i] = c % 2;
		c = c / 2;
		i--;
	}
	return arr;
}

