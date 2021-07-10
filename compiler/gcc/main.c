extern void (*step)(void);

void mystep_cb(void)
{
	printf("记秒到时\n");
}

int main(void)
{
	step = mystep_cb;
	run();
}
