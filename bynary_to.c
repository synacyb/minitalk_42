#include <unistd.h>
#include <stdio.h>

void    convert_binary(int *arr)
{
    int r = 0;
    int i = 0;
    int res;
    while (i < 8)
        r = r * 2 + arr[i++];
    char c;
    c = (char)r;
    write(1, &c, 1);
}
// int main()
// {
//     int arr[8] = {0, 1, 0, 0, 0, 1, 1, 0};
//     convert_binary(arr);
// }