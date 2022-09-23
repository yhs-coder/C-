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
	free(new_memory);//��ֹ�ڴ�й©
	new_memory = NULL;

}
/*
	��;��
	Ϊ��Щ������ʱ��֪����������ڴ�ռ�,��ʵ����������
*/

//��qsort()�������ã����ڱȽ�����ֵ
int compare_integers(void const *a,void const *b)
{
	//ʹ��register int����ı����Ǵ洢��CPU����Ĵ����еģ��Ĵ��������봦�����ڵ���ɲ��֡��Ĵ��������޴��������ĸ��ٴ�������������ʹ��int����ı����Ǵ洢���ڴ��С�
	register int const* pa = a;
	register int const* pb = b;
	return  *pa > *pb ? 1 : *pa < *pb ? -1 : 0;

}
void sort()
{
	int* array;
	int n_values;
	int i;
	//�۲��м���ֵ
	printf("input values number:");
	if (scanf("%d", &n_values) != 1 || n_values == 0)
	{
		printf("Illfgal number of values.\n");
		exit(EXIT_FAILURE);
	}
	printf("\ninput value:");

	//�����ڴ棬�洢ֵ
	//�����ڴ���������м��
	array = MALLOC(n_values, int);
	//��ȡֵ
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

	//��ֵ��������
	//void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*));
	qsort(array, n_values, sizeof(int),compare_integers);

	//���
	for (i = 0; i < n_values; i++)
	{
		printf("%d ", array[i]);
	}
	//�ͷ��ڴ�
	free(array);
	array = NULL;

}

/*
	�ö�̬�ڴ��������һ���ַ�����һ�ݿ���
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
	//function();//�Զ�̬�����ڴ棬���м��Ķ�̬�ڴ������
	//sort();
	//char* new = StrCopy("hello C/C++");
	//printf("%s\n",new);

	return 0;
}
