#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


/*
	一、指针基础
*/

//
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	return 0;
//}

/*
	1.指针类型的意义：
		（1）指针的解引用： 能访问多少个字节
		（2）指针+-整数：指针向前后移动的距离（大小）
		是根据类型的大小访问和移动
*/

//1.1 指针的解引用
//int main()
//{
//	int n = 0x11223344;
//	char* pc = (char*)&n;
//	int* pi = &n;
//	//通过调试观察不同类型在内存中的变化
//	*pc = 0;
//	*pi = 0;
//	return 0;
//}

//1.2 指针+-整数
//int main()
//{
//	int n = 10;
//	char* pc = (char*)&n;
//	int* pi = &n;
//
//	printf("%p\n", &n);
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);
//	printf("%p\n", pi);
//	printf("%p\n", pi + 1);
//	return 0;
//}


/*
	2.野指针：
	（1） 指针未初始化
	（2） 指针越界访问
	（3） 指针指向的空间释放
*/

//2.1 指针未初始化
//int main()
//{
//	int* p;
//	*p = 20;
//	return 0;
//}

//2.2 指针越界访问

//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i <= 11; i++)
//	{
//		//当指针指向的范围超出数组arr的范围时，p就是野指针
//		*(p++) = i;
//	}
//	return 0;
//}

//2.3 指针指向的空间释放
//int main()
//{
//	int* ps = (int*)malloc(4 * sizeof(int));
//	if (ps == NULL)
//	{
//		exit(-1);
//	}
//	free(ps);
//	*ps = 20;//error,指针指向的内存空间释放了，非法访问
//	return 0;
//}


/*
	3. 避免野指针的写法:
	（1） 指针初始化
	（2）小心指针越界
	（3）指针指向空间释放即使置NULL
	（4）指针使用之前检查有效性
*/
//int main()
//{
//	int* p = NULL;
//	int a = 10;
//	p = &a;
//	if (p != NULL)
//	{
//		*p = 20;
//	}
//	return 0;
//}


/*
	4. 指针运算：
	（1）指针+- 整数
	（2）指针-指针
	（3）指针的关系运算

	标准规定：
		允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，但是不允许
		与指向第一个元素之前的那个内存位置的指针进行比较。

*/
//4.1 指针+- 整数

//#define N_VALUES 5
//void test()
//{
//	float values[N_VALUES];
//	float* vp;
//	for (vp = &values[0]; vp < &values[N_VALUES];)
//	{
//		*vp++ = 1;
//	}
//}
//4.2 指针-指针 可以用来求长度
//int my_strlen(char* s)
//{
//	char* p = s;
//	while (*p != '\0')
//		p++;
//	return p - s;
//
//}
//int main()
//{
//	//test();
//	//printf("%d\n",my_strlen("hello Linux"));
//	return 0;
//}

/*
	5.指针和数组

//*/
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int* p = arr;
//	int* pp = &arr;
//	printf("%p\n", arr);
//
//	printf("%p\n", p);
//	printf("%p\n", p+1);
//
//	printf("%p\n", pp);
//	printf("%p\n", pp+1);
//	return 0;
//}


/*
	二、指针进阶！！！
*/


/*
	1.字符指针
*/

//1.1 一般使用
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	*pc = 's';
//	return 0;
//}

//1.2 存放常量字符串
//int main()
//{
//	char* pstr = "hello C++";
//	//"hello C++"为常量字符串
//	//pstr存放的是常量字符串的首元素的地址
//	printf("%s\n", pstr);
//	return 0;
//}

//1.3 练习题
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	char* str3 = "hello bit.";
//	char* str4 = "hello bit.";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//
//	//str3和str4指向的是一个同一个常量字符串。
//	// C/C++会把常量字符串存储到单独的一个内存区域,str3、str4指向同一块内存空间
//	//输出：
//	//str1 and str2 are not same
//	//str3 and str4 are same
//	return 0;
//}


/*
	2. 数组指针

	&数组名VS数组名的区别：
	数组名表示数组首元素的地址
	&数组名表示整个数组的地址
	虽然两个地址相同，但 &数组名+1 移动的是整个数组的大小
*/

//2.1
//int main()
//{
//	int arr[10] = { 0 };
//	printf("arr = %p\n", arr);
//	printf("&arr= %p\n", &arr);
//	printf("arr+1 = %p\n", arr + 1);
//	printf("&arr+1= %p\n", &arr + 1);
//	return 0;
//}

//2.2 数组指针的使用: 主要应用于二维数组
//==> print_arr2()

void print_arr1(int arr[3][5], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void print_arr2(int(*arr)[5], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{

			////二维数组首元素的地址，是第一行的地址
			//将二维数组降维看作一维数组，
			//  一行为一个数组，再把数组在看成一个元素
			// 首元素地址相当于是二维数组的第一行的地址，
			//*(arr+i)，arr 是首元素地址，是第一行的地址
			// arr+i相当于是 第 1+i 行 首元素的地址
			//解引用后是首元素，首元素是二维数组的第一行，即是一个数组，
			//所以 *（arr+i)最后就是数组名，相当于一维数组里首元素的地址

			// *(*(arr+i) +j)则表示第一行首元素的地址+j，在解引用，得到第一行的数据

			//arr[i][j] == *(*(arr+i)+j)
			//arr[i][j] == *(arr+i)[j]
			//arr[i][j] == *(arr[i]+j)
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	//print_arr1(arr, 3, 5);
//	print_arr2(arr, 3, 5);
//
//	return 0;
//}


/*
	3. 数组传参、指针传参

	一级指针参数：可以接收一维数组的地址，一级指针
	二级指针参数：可以接收一级指针的地址、二级指针
*/


//3.1一维数组传参

//void test(int arr[]){}//可以接受数组
//void test(int arr[10]){}//也可以
//void test(int *arr){} //可以
////void test2(int *arr[20]){}//可以
//void test2(int **arr){} //可以
//
//
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	//test(arr);
//	test2(arr2);
//	return 0;
//}


// 3.2 二维数组传参
// 
//数组参数
//void test(int arr[3][5]) {}//ok
//void test(int arr[][5]){}//ok
//void test(int arr[][]) {}//error 
////总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。


//===== 指针参数 =======
//void test3(int *arr){}//error
//arr是第一行的地址，第一行是数组，即arr传递的是数组的地址
//指向的是数组的地址，不可用的整型指针接收，需要用数组指针
//void test(int* arr[5]);//error
//void test(int(*arr)[5]){} ok
//void test(int **arr){} //error 二级指针存放的是一级指针的地址
//int main()
//{
//	int arr[3][5];
//	//test(arr);
//	test(arr);
//	return 0;
//}

// 3.3 一级指针传参 

//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(p, sz);
//	return 0;
//}

//3.4 二级指针传参
//void test(int** ptr)
//{
//	printf("num = %d\n", **ptr);
//}
//
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//	//test(pp);
//	//test(&p);
//	int a = 110;
//	int b = 20;
//	int c = 30;
//	int* str[3] = { &a,&b,&c };
//	
//	return 0;
//}




/*
	4. 函数指针
*/
//
//void test()
//{
//	printf("haha\n");
//}
//int main()
//{
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	return 0;
//}

//有趣的代码
//代码1
//	( * (      void (*)()     ) 0  )  ();//调用0地址处的函数
//代码2

void (*signal(int, void(*)(int)))(int);//signal是一个函数，参数有int和 void(*)(int)[函数指针]
//	返回类型是 函数指针void(*) (int)

//函数指针类型，以上代码简化后为
//typedef void(*pfun_t)(int)
//===>     pfun_t signal(int,pfun_t)

/*
	5. 函数指针数组
	int (*p[10])()

	主要用途：转移表
*/

//简单例子：计算器
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}


//================第一种：如果以普通的方法实现？==============
//int main()
//{
//	int x, y;
//	int input = 1;
//	int ret = 0;
//	do
//	{
//		printf("*************************\n");
//		printf(" 1:add           2:sub \n");
//		printf(" 3:mul           4:div \n");
//		printf("*************************\n");
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 2:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 3:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 4:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}

//============= 第二种：以函数指针数组实现！！！！==========

//int main()
//{
//	int x, y;
//	int input = 1;
//	int ret = 0;
//	int(*p[5])(int x, int y) = { 0,add,sub,mul,div };//转移表
//	while (input)
//	{
//		printf("*************************\n");
//		printf(" 1:add           2:sub \n");
//		printf(" 3:mul           4:div \n");
//		printf("*************************\n");
//		printf("请选择：");
//		scanf("%d", &input);
//		if ((input <= 4 && input >= 1))
//		{
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = p[input](x, y);
//		}
//		else 
//			printf("输入有误\n");
//		printf("ret = %d\n", ret);
//	}
//	return 0;
//}

//================第三种:回调函数===========
//void result(int (*p)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("输入操作数:");
//	scanf("%d %d", &x, &y);
//	printf("num = %d\n", (*p)(x, y));
//}
//int main()
//{
//	int input = 1;
//
//	int ret = 0;
//	do
//	{
//		printf("*************************\n");
//		printf(" 1:add           2:sub \n");
//		printf(" 3:mul           4:div \n");
//		printf(" 0:exit                \n");
//		printf("*************************\n");
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			result(add);
//			break;
//		case 2:
//			result(sub);
//			break;
//		case 3:
//			result(mul);
//			break;
//		case 4:
//			result(div);
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}



/*
	指向函数指针数组的指针
*/
//
//void test(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	//函数指针
//	void (*pfun)(const char*) = test;
//	//函数指针数组
//	void(*pfunArr[5])(const char* str);
//	pfunArr[0] = test;
//	//指向函数指针数组的指针
//	void (*(*ppfunArr)[10])(const char*) = &pfunArr;
//	return 0;
//}



/*
	============= 回调函数的进一步学习 =========
*/

//使用回调函数，模拟实现qsort(冒泡方法）！！！！！！！
//qsort  对数组的元素进行排序
//void qsort(void* base, size_t num, size_t size,int (*compar)(const void*, const void*));
//参数 void*base 指向要排序的数组的第一个对象的指针，该对象已转换为 void*
//size_t num 所指向的数组中的元素数。
//size_t size 数组中每个元素的大小（以字节为单位）
/* 
int (*compar)(const void*, const void*) 指向比较两个元素的函数的指针。
<0	所指向的元素在所指向的元素之前p1p2  p1<p2
 0	指向的元素等效于指向的元素p1p2		p1=p2
> 0	指向的元素位于指向的元素之后p1p2	p1>p2
*/

//比较两个整数
int cmp_int(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}

//比较两个浮点数
int cmp_float(const void* p1, const void* p2)
{
	return (int)(*(float*)p1 - *(float*)p2);
}
struct Stu
{
	char* name;
	int age;
};

//比较结构体的年龄age
int cmp_stu_by_age(const void* p1, const void* p2)
{
	return (((struct Stu*)p1)->age - ((struct Stu*)p2)->age);
}

//比较结构体的名字name(字符串）
int cmp_stu_by_name(const void* p1, const void* p2)
{
	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
}



void _swap(void* p1, void* p2, size_t size)
{
	char tmp;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}
//可以进行任意数据类型的排序
void bubble_sort(void *base,size_t num,size_t size, int (*cmp)(const void*, const void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			//进行两个数的比较，从而判断是否交换
			//把base强制转换成char*类型，这样任何的类型，都可以根据类型的大小，一个个字节去改变
			if ( cmp((char*)base+j*size,(char*)base+(j+1)*size)>0 )
			{
				//base=arr;
				_swap((char*)base + j * size, (char*)base + (j + 1) * size,size);
			}
		}	
	}
}


void test_int()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) /sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(int), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	
}
void test_stu()
{
	struct Stu s[3] = { {"bobo",22},{"yy",20},{"aa",18} };
	int sz = sizeof(s) / sizeof(s[0]);
	int i = 0;
	//bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}


//int main()
//{
//	//test_int();
//	test_stu();
//	return 0;
//}


/*
	指针和数组笔试题解析
*/
//一维数组
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));		// 16
//	printf("%d\n", sizeof(a + 0));	// 4/8 32位机器则4个字节，64位机器则8个字节
//	printf("%d\n", sizeof(*a));		// 4
//	printf("%d\n", sizeof(a + 1));	// 4/8
//	printf("%d\n", sizeof(a[1]));	// 4
//	printf("%d\n", sizeof(&a));		// 4/8
//	printf("%d\n", sizeof(*&a));	// 16
//	printf("%d\n", sizeof(&a + 1));	// 4/8
//	printf("%d\n", sizeof(&a[0]));	// 4/8
//	printf("%d\n", sizeof(&a[0] + 1));	//	4/8
//}


//字符数组
// 
//	除了以下两种情况外，其它情况数组名表示首元素的地址
//	  1.sizeof(数组名)-数组名表示整个数组
//	  2. &数组名 - 数组名表示整个数组

//int main()
//{
	//char arr[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", sizeof(arr));		// 6
	//printf("%d\n", sizeof(arr + 0));	// 4/8
	//printf("%d\n", sizeof(*arr));		// 1 
	//printf("%d\n", sizeof(arr[1]));		// 1
	//printf("%d\n", sizeof(&arr));		// 4/8
	//printf("%d\n", sizeof(&arr + 1));	// 4/8
	//printf("%d\n", sizeof(&arr[0] + 1));	// 4/8
	
	//strlen（）直到遇到'\0'才停止
	//printf("%d\n", strlen(arr));	// 随机值	
	//printf("%d\n", strlen(arr + 0));// 随机值
	////printf("%d\n", strlen(*arr));	// error 错误,将a=97作为地址传入，程序出错
	////printf("%d\n", strlen(arr[1]));	//随机值
	//printf("%d\n", strlen(&arr));	// 随机值
	//printf("%d\n", strlen(&arr + 1));	//随机值
	//printf("%d\n", strlen(&arr[0] + 1));	//随机值

	//char arr[] = "abcdef";//"abcdef"为常量字符串，以'\0'结尾
	//printf("%d\n", sizeof(arr));	// 7 包括最后一个结束字符
	//printf("%d\n", sizeof(arr + 0));	// 4/8
	//printf("%d\n", sizeof(*arr));		// 1
	//printf("%d\n", sizeof(arr[1]));		// 1
	//printf("%d\n", sizeof(&arr));		// 4/8
	//printf("%d\n", sizeof(&arr + 1));	// 4/8
	//printf("%d\n", sizeof(&arr[0] + 1));	// 4/8

	//printf("%d\n", strlen(arr));	// 6
	//printf("%d\n", strlen(arr + 0));	// 6
	////printf("%d\n", strlen(*arr));		// error,a='97',非法访问，程序报错
	////printf("%d\n", strlen(arr[1]));		//  error
	//
	//printf("%d\n", strlen(&arr));		// 6 
	//printf("%d\n", strlen(&arr + 1));	// 随机值
	//printf("%d\n", strlen(&arr[0] + 1)); //5

	//char* p = "abcdef";
	//printf("%d\n", sizeof(p));	// 4/8
	//printf("%d\n", sizeof(p + 1));	// 4/8
	//printf("%d\n", sizeof(*p));		// 1
	//printf("%d\n", sizeof(p[0]));	// 1
	//printf("%d\n", sizeof(&p));		// 4/8
	//printf("%d\n", sizeof(&p + 1));	// 4/8
	//printf("%d\n", sizeof(&p[0] + 1));	// 4/8

	//printf("%d\n", strlen(p));	//  6
	//printf("%d\n", strlen(p + 1));	// 5
	////printf("%d\n", strlen(*p));		// error
	////printf("%d\n", strlen(p[0]));		// error
	//printf("%d\n", strlen(&p));			// 随机值
	//printf("%d\n", strlen(&p + 1));		// 随机值
	//printf("%d\n", strlen(&p[0] + 1));	// 5

	//二维数组
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));	// 48
//	printf("%d\n", sizeof(a[0][0]));	// 4
//	printf("%d\n", sizeof(a[0]));		// 16
//	printf("%d\n", sizeof(a[0] + 1));	// 4/8
//	printf("%d\n", sizeof(*(a[0] + 1)));	// 4
//	printf("%d\n", sizeof(a + 1));	// 4/8
//	printf("%d\n", sizeof(*(a + 1)));	//	16 
//	printf("%d\n", sizeof(&a[0] + 1));	// 4/8
//	printf("%d\n", sizeof(*(&a[0] + 1)));	// 16
//	printf("%d\n", sizeof(*a));	//16
//	printf("%d\n", sizeof(a[3]));	// 16
//
//	return 0;
//}

/*
	指针相关笔试题
*/

//题目1
//程序的结果是什么？
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//		2  5
//	return 0;
//}

//题目2
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//int main()
//{
//
//	printf("%p\n", p + 0x1); //地址跳过一个结构体大小
//	printf("%p\n", (unsigned long)p + 0x1);	// 强转为unsigned long类型，数值加1
//	printf("%p\n", (unsigned int*)p + 0x1);	//跳过一个整形指针大小
//	return 0;
//}

////题目3
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 4);//把a即首元素的地址强制转换成整型，最后地址只加了一而已，无法访问到该元素
//	printf("%x,%x", ptr1[-1], *ptr2);//4 异常 //地址访问异常，无法读出该值
//	return 0;
//}

//
////题目4
//#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };//(0,1)逗号表达式，取最右边的值1，3，5
//	int* p=NULL;
//	p = a[0];
//	printf("%d\n", p[0]); // 1
//	return 0;
//}

//题目5
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//FFFFFFFFFFFFFFFC,-4
// //关键是理解数组指针是怎么存放二维数组的
//	return 0;
//}

//题目6
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1)); //10 5
//	return 0;
//}

//题目7
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa); //at
//	pa++;
//	printf("%s\n", *pa);//alibaba
//
//	return 0;
//}

//题目8
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = &cp;
	printf("%s\n", **++cpp);//POINT
	printf("%s\n", *-- * ++cpp + 3);	// ER!! 
	//先计算 ++cpp, ==> *++cpp==> --*++cpp==>> *--*++cpp  +3
	printf("%s\n", *cpp[-2] + 3);		//	ST
	printf("%s\n", cpp[-1][-1] + 1);	//EW!!!
	return 0;
}

