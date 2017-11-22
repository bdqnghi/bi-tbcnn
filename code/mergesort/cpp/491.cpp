#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "string.h"

void swap(int * array, int a, int b);
void sswap(int * array, int a, int b);
void MergeSort(int * array, int * tmpary, int len);
void printArray(int * array, int len);

void swap(int * array, int a, int b)
{
	int tmp = 0;
	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

/*
	smart swap 判断两个值，如果第一个大于第二个，就交换
	如果不大于，不交换
*/
void sswap(int * array, int a, int b)
{
	if (array[a] < array[b])
		swap(array, a, b);
}

void MergeSort(int * array, int * tmpary, int len)
{
	
}

/*
	输出数组
*/
void printArray(int * array, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

void main()
{
	// 设置随机数种子
	srand((int)time(0));
	// 第一次是固定的2
	(int)(20.0*rand()/(RAND_MAX+1.0));				
	int length = (int)(20.0*rand()/(RAND_MAX+1.0));
	int * ary = (int *)malloc(sizeof(int)*length);
	int * tmpary = (int *)malloc(sizeof(int)*length);
	memset(ary, 0 , sizeof(int)*length);
	memset(tmpary, 0 , sizeof(int)*length);

	printf("数组长度为 %d\n", length);

	// 初始化数组
	for (int i = 0; i < length; i++)
	{
		ary[i] = (int)(500.0*rand()/(RAND_MAX+1.0))+1;
		//printf("%d\n", (int)(20.0*rand()/(RAND_MAX+1.0)) );
	}

	printf("初始数组为：", length);
	printArray(ary, length);

	// 排序
	MergeSort(ary, tmpary, length);

	free(ary);
	system("pause");
}
