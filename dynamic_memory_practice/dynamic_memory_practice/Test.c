#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
	使用malloc、free
*/
void test1()
{
	int num = 0;
	scanf("%d", &num);
	int* ptr = NULL;
	ptr = (int*)malloc(num * sizeof(int));
	if (NULL != ptr)//判断动态分配内存返回的指针是否为空
	{
		int i = 0;
		for (i = 0; i < num; i++)
		{
			ptr[i] = 0;
			printf("%d ", *ptr);
		}
	}
	free(ptr);//释放ptr指向的动态内存
	ptr = NULL;

}

/*
	calloc的使用
*/
void test2()
{
	//calloc返回地址之前把申请的空间的每个字节初始化为全0。
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		printf("Out of memery!");
		exit(-1);
	}
	free(p);
	p = NULL;
}

/*
	realloc的使用
	调整内存空间时存在两种情况：
	1. 原有的内存空间后，有足够的内存空间追加
	2. 原有的内存空间后无足够的内存空间，需要另外找找一个合适大小的连续空间来使用。此时，会把旧内存的数据拷贝到新内存上
*/

void test3()
{
	int *ptr = (int*)malloc(10 * sizeof(int));
	if (ptr == NULL)
	{
		printf("Out of memory!");
		exit(-1);
	}
	//扩容
	//ptr = realloc(ptr, 1000);

	int* p = NULL;
	p = realloc(ptr, 1000);
	if (p != NULL)
	{
		ptr = p;
	}
	free(ptr);
	ptr = NULL;
}


/*
	常见的动态内存错误
*/

//1.对NULL指针的解引用操作

/*
void test4()
{
	int *p = (int*)malloc(INT_MAX);
	*p = 100;
	free(p);
}

//2.对动态开辟空间的越界访问

void test5()
{
	int i = 0;
	int* p = (int*)malloc(10 * sizeof(int));
	if (NULL == p)
	{
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= 10; i++)
	{
		*(p + i) = i;//当i是10的时候越界访问
	}
	free(p);
}

//3. 对非动态开辟内存使用free释放
void test6()
{
	int a = 10;
	int* p = &a;
	free(p);//error
}

//4. 使用free释放一块动态开辟内存的一部分
void test7()
{
	int* p = (int*)malloc(100);
	p++;//指针指向下一个地址
	free(p);//此时指针不再指向动态内存的起始位置
}

//5. 对同一块动态内存多次释放
void test8()
{
	int* p = (int*)malloc(100);
	free(p);
	free(p);//重复释放
}

//6.动态开辟内存忘记释放（内存泄漏）!!!!!!!!!!
void test8()
{
	int* p = (int*)malloc(100);
	if (NULL != p)
	{
		*p = 20;
	}

}
*/


/*
	相关题目的练习
*/

//题目1：
void GetMemory(char* p)
{
	p = (char*)malloc(100 * sizeof(char));
}
void Test1()
{
	char* str = NULL;
	GetMemory(str);
	strcpy(str, "helllo world");
	printf(str);
	//问题：Test 函数会有什么样的结果？
	//结果：会造成程序崩溃，内存泄漏的问题
	//分析：1、形参的改变不会影响实参，形参仅仅是实参的拷贝，需要传址才可改变！2、需要使用free释放动态分配的内存，否则导致资源持续消耗！！
}

//题目2：
char* GetMemory2()
{
	char p[] = "hello world";
	return p;
}

void Test2()
{
	char* str = NULL;
	str = GetMemory2();
	printf(str);
	//问题：Test 函数会有什么样的结果？
	//结果：烫烫烫 
	//分析：p是在栈区开辟的内存空间，当函数运行结束时，栈区会被销毁，此时返回的p指向的内存空间已经被销毁释放，导致非法访问内存！
}

//题目3：
void GetMemory3(char** p, int num)
{
	*p = (char*)malloc(num);
}
void Test3(void)
{
	char* str = NULL;
	GetMemory3(&str, 100);
	strcpy(str, "hello");
	printf(str);
	//问题：运行Test 函数会有什么样的结果？
	//结果：hello  
	//分析：动态分配的内存时开辟在堆上的，函数运行结束也不会销毁掉动态分配的内存
	//出现的问题：内存泄漏
}

//题目4：
void Test4(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
	//问题：运行Test 函数会有什么样的结果？
	//结果：world  
	//分析：最后的if判断，是用来检查释放的动态内存是否为NULL!
}


/*
	柔性数组！！！！
	C99 中，结构中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员。

	知识补充：
	柔性数组的特点：
		1.结构中的柔性数组成员前面必须至少一个其他成员。
		2.sizeof 返回的这种结构大小不包括柔性数组的内存。
		3.包含柔性数组成员的结构用malloc ()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应
		柔性数组的预期大小。
*/

typedef struct st_type
{
	int i;
	int a[0]; //柔性数组成员
	//int a[]
}type_a;

//柔性数组的使用
void flexible_array() 
{
	int i = 0;
	type_a* p = (type_a*)malloc(sizeof(type_a) + 100 * sizeof(int));
	//业务处理
	p->i = 100;
	for (i = 0; i < 100; i++)
	{
		p->a[i] = i;
	}
	free(p);
	p = NULL;
}

//这种写法可代替柔性数组
typedef struct st_type
{
	int i;
	int* p_a;
}type_a;
void replace_flexible_array()
{
	int i = 0;
	type_a* p = malloc(sizeof(type_a));
	p->i = 100;
	p->p_a = (int*)malloc(p->i * sizeof(int));
	//业务处理
	for (i = 0; i < 100; i++)
	{
		p->p_a[i] = i;
	}
	free(p->p_a);
	p->p_a = NULL;
	free(p);
	p = NULL;

}


//柔性数组比较第二种代替写法：第一个好处是：方便内存释放。第二个好处是连续的内存有益于提高访问速度，也有益于减少内存碎片
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();

	//Test1();
	//Test2();
	//Test3();
	Test4();





	return 0;
}