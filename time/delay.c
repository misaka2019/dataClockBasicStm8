
/*****1ms的纯软件延时函数*****/
void delay_ms(unsigned int num)
{
	unsigned int i, j;
	for(i=0; i<num; i++)
	{
		for(j=0; j<400; j++);
	}
}

