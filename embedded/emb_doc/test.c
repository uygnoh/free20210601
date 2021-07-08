#include <stdio.h>
void test1(void);
void test2(void);
int main(void)
{
	test2();
	test1();
	return 0;
}

void test1(void)
{
	int arr[] = {1, 2, 3};
	int *ptr = arr;
	printf("test1 = %d\n", *(ptr++));
}
void test2(void)
{
	int arr[] = {1, 2, 3};
	int *ptr = arr;
	printf("test1 = %d\n", *(++ptr));
}
