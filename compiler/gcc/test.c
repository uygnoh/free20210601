#include <stdio.h>
void sp(int *ptr)
{
	*ptr = 1;
	printf("hello\n");
}
int main(void)
{

	int tmp = 0;
	sp((int *)&tmp);
	printf("%p\n", (int *)&tmp);
	printf("%p\n", &tmp);
	return 0;
}
