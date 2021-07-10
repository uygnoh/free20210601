#include <stdio.h>
#include <unistd.h>

void (*step)(void) = NULL;

void run(void)
{
	int cnt = 0;
	while (1)
	{
		if (cnt > 10)
			break;
		if (step != NULL)
			step();
		cnt++;
		sleep(1);
	}
}
