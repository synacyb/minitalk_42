#include "minitalk.h"

int   *char_to_binary(unsigned char c)
{
	int             *arr;
	unsigned int    value;
	int             i;

	arr = malloc(8 * sizeof(int));
	value = (unsigned int)c;
	i = 7;
	while (i >= 0)
	{
		arr[i] = value % 2;
		value = value / 2;
		i--;
	}
	return(arr);
}
