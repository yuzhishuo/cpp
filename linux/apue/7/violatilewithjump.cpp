/*************************************************************************
    > File Name: violatilewithjump.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月19日 星期一 13时58分11秒
 ************************************************************************/

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static void f1(int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;

int main(void)
{

	int count;
	register int val;
	volatile int sum;

	count = 2;
	val = 3;
	sum = 4;

	if (setjmp(jmpbuffer) != 0)
	{
		printf("after longjmp: count = %d, val = %d, sum = %d \n",
			   count, val, sum);
		exit(0);
	}
	count = 97;
	val = 98;
	sum = 99;

	f1(count, val, sum);
	return 0;
}

static void f1(int i, int j, int k)
{

	printf("in f1(): count = %d, val = %d, sum = %d\n", i, j, k);
	f2();
}

static void f2(void)
{

	longjmp(jmpbuffer, 1);
}