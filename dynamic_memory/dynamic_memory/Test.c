#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
#include"alloc.h"
#include<string.h>


void function()
{
	int* new_memory;
	new_memory = MALLOC(25, int);
	int i = 0;
	for (i = 0; i < 25; i++)
	{
		new_memory[i] = 0;
	}
	for (i = 0; i < 25; i++)
	{
		printf("%d ", new_memory[i]);
	}
	free(new_memory);//防止内存泄漏
	new_memory = NULL;

}
/*
	用途：
	为那些在运行时才知的数组分配内存空间,简单实现升序排序
*/

//由qsort()函数调用，用于比较整型值
int compare_integers(void const *a,void const *b)
{
	//使用register int申请的变量是存储在CPU中央寄存器中的（寄存器是中央处理器内的组成部分。寄存器是有限存贮容量的高速存贮部件），而使用int申请的变量是存储在内存中。
	register int const* pa = a;
	register int const* pb = b;
	return  *pa > *pb ? 1 : *pa < *pb ? -1 : 0;

}
void sort()
{
	int* array;
	int n_values;
	int i;
	//观察有几个值
	printf("input values number:");
	if (scanf("%d", &n_values) != 1 || n_values == 0)
	{
		printf("Illfgal number of values.\n");
		exit(EXIT_FAILURE);
	}
	printf("\ninput value:");

	//分配内存，存储值
	//运用内存分配器进行检查
	array = MALLOC(n_values, int);
	//读取值
	for (i = 0; i < n_values; i++)
	{
		if (scanf("%d", array + i) != 1)
		{
			printf("Error reading value :%d\n",i);
			free(array);
			array = NULL;
			exit(EXIT_FAILURE);
		}
	}

	//对值进行排序
	//void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*));
	qsort(array, n_values, sizeof(int),compare_integers);

	//输出
	for (i = 0; i < n_values; i++)
	{
		printf("%d ", array[i]);
	}
	//释放内存
	free(array);
	array = NULL;

}

/*
	用动态内存分配制作一个字符串的一份拷贝
*/
char* StrCopy(char const* string)
{
	char* new_string;
	new_string = MALLOC(strlen(string + 1), char);
	strcpy(new_string, string);
	return new_string;
}

int main()
{
	//function();//对动态分配内存，进行检查的动态内存分配器
	//sort();
	//char* new = StrCopy("hello C/C++");
	//printf("%s\n",new);

	return 0;
}
