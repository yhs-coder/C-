#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


/*
	һ��ָ�����
*/

//
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	return 0;
//}

/*
	1.ָ�����͵����壺
		��1��ָ��Ľ����ã� �ܷ��ʶ��ٸ��ֽ�
		��2��ָ��+-������ָ����ǰ���ƶ��ľ��루��С��
		�Ǹ������͵Ĵ�С���ʺ��ƶ�
*/

//1.1 ָ��Ľ�����
//int main()
//{
//	int n = 0x11223344;
//	char* pc = (char*)&n;
//	int* pi = &n;
//	//ͨ�����Թ۲첻ͬ�������ڴ��еı仯
//	*pc = 0;
//	*pi = 0;
//	return 0;
//}

//1.2 ָ��+-����
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
	2.Ұָ�룺
	��1�� ָ��δ��ʼ��
	��2�� ָ��Խ�����
	��3�� ָ��ָ��Ŀռ��ͷ�
*/

//2.1 ָ��δ��ʼ��
//int main()
//{
//	int* p;
//	*p = 20;
//	return 0;
//}

//2.2 ָ��Խ�����

//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i <= 11; i++)
//	{
//		//��ָ��ָ��ķ�Χ��������arr�ķ�Χʱ��p����Ұָ��
//		*(p++) = i;
//	}
//	return 0;
//}

//2.3 ָ��ָ��Ŀռ��ͷ�
//int main()
//{
//	int* ps = (int*)malloc(4 * sizeof(int));
//	if (ps == NULL)
//	{
//		exit(-1);
//	}
//	free(ps);
//	*ps = 20;//error,ָ��ָ����ڴ�ռ��ͷ��ˣ��Ƿ�����
//	return 0;
//}


/*
	3. ����Ұָ���д��:
	��1�� ָ���ʼ��
	��2��С��ָ��Խ��
	��3��ָ��ָ��ռ��ͷż�ʹ��NULL
	��4��ָ��ʹ��֮ǰ�����Ч��
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
	4. ָ�����㣺
	��1��ָ��+- ����
	��2��ָ��-ָ��
	��3��ָ��Ĺ�ϵ����

	��׼�涨��
		����ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����Ǹ��ڴ�λ�õ�ָ��Ƚϣ����ǲ�����
		��ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ�λ�õ�ָ����бȽϡ�

*/
//4.1 ָ��+- ����

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
//4.2 ָ��-ָ�� ���������󳤶�
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
	5.ָ�������

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
	����ָ����ף�����
*/


/*
	1.�ַ�ָ��
*/

//1.1 һ��ʹ��
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	*pc = 's';
//	return 0;
//}

//1.2 ��ų����ַ���
//int main()
//{
//	char* pstr = "hello C++";
//	//"hello C++"Ϊ�����ַ���
//	//pstr��ŵ��ǳ����ַ�������Ԫ�صĵ�ַ
//	printf("%s\n", pstr);
//	return 0;
//}

//1.3 ��ϰ��
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
//	//str3��str4ָ�����һ��ͬһ�������ַ�����
//	// C/C++��ѳ����ַ����洢��������һ���ڴ�����,str3��str4ָ��ͬһ���ڴ�ռ�
//	//�����
//	//str1 and str2 are not same
//	//str3 and str4 are same
//	return 0;
//}


/*
	2. ����ָ��

	&������VS������������
	��������ʾ������Ԫ�صĵ�ַ
	&��������ʾ��������ĵ�ַ
	��Ȼ������ַ��ͬ���� &������+1 �ƶ�������������Ĵ�С
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

//2.2 ����ָ���ʹ��: ��ҪӦ���ڶ�ά����
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

			////��ά������Ԫ�صĵ�ַ���ǵ�һ�еĵ�ַ
			//����ά���齵ά����һά���飬
			//  һ��Ϊһ�����飬�ٰ������ڿ���һ��Ԫ��
			// ��Ԫ�ص�ַ�൱���Ƕ�ά����ĵ�һ�еĵ�ַ��
			//*(arr+i)��arr ����Ԫ�ص�ַ���ǵ�һ�еĵ�ַ
			// arr+i�൱���� �� 1+i �� ��Ԫ�صĵ�ַ
			//�����ú�����Ԫ�أ���Ԫ���Ƕ�ά����ĵ�һ�У�����һ�����飬
			//���� *��arr+i)���������������൱��һά��������Ԫ�صĵ�ַ

			// *(*(arr+i) +j)���ʾ��һ����Ԫ�صĵ�ַ+j���ڽ����ã��õ���һ�е�����

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
	3. ���鴫�Ρ�ָ�봫��

	һ��ָ����������Խ���һά����ĵ�ַ��һ��ָ��
	����ָ����������Խ���һ��ָ��ĵ�ַ������ָ��
*/


//3.1һά���鴫��

//void test(int arr[]){}//���Խ�������
//void test(int arr[10]){}//Ҳ����
//void test(int *arr){} //����
////void test2(int *arr[20]){}//����
//void test2(int **arr){} //����
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


// 3.2 ��ά���鴫��
// 
//�������
//void test(int arr[3][5]) {}//ok
//void test(int arr[][5]){}//ok
//void test(int arr[][]) {}//error 
////�ܽ᣺��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]�����֡�
//��Ϊ��һ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ�ж���Ԫ�ء�


//===== ָ����� =======
//void test3(int *arr){}//error
//arr�ǵ�һ�еĵ�ַ����һ�������飬��arr���ݵ�������ĵ�ַ
//ָ���������ĵ�ַ�������õ�����ָ����գ���Ҫ������ָ��
//void test(int* arr[5]);//error
//void test(int(*arr)[5]){} ok
//void test(int **arr){} //error ����ָ���ŵ���һ��ָ��ĵ�ַ
//int main()
//{
//	int arr[3][5];
//	//test(arr);
//	test(arr);
//	return 0;
//}

// 3.3 һ��ָ�봫�� 

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

//3.4 ����ָ�봫��
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
	4. ����ָ��
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

//��Ȥ�Ĵ���
//����1
//	( * (      void (*)()     ) 0  )  ();//����0��ַ���ĺ���
//����2

void (*signal(int, void(*)(int)))(int);//signal��һ��������������int�� void(*)(int)[����ָ��]
//	���������� ����ָ��void(*) (int)

//����ָ�����ͣ����ϴ���򻯺�Ϊ
//typedef void(*pfun_t)(int)
//===>     pfun_t signal(int,pfun_t)

/*
	5. ����ָ������
	int (*p[10])()

	��Ҫ��;��ת�Ʊ�
*/

//�����ӣ�������
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


//================��һ�֣��������ͨ�ķ���ʵ�֣�==============
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
//		printf("��ѡ��");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("�����������");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 2:
//			printf("�����������");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 3:
//			printf("�����������");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 4:
//			printf("�����������");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 0:
//			printf("�˳�����\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}

//============= �ڶ��֣��Ժ���ָ������ʵ�֣�������==========

//int main()
//{
//	int x, y;
//	int input = 1;
//	int ret = 0;
//	int(*p[5])(int x, int y) = { 0,add,sub,mul,div };//ת�Ʊ�
//	while (input)
//	{
//		printf("*************************\n");
//		printf(" 1:add           2:sub \n");
//		printf(" 3:mul           4:div \n");
//		printf("*************************\n");
//		printf("��ѡ��");
//		scanf("%d", &input);
//		if ((input <= 4 && input >= 1))
//		{
//			printf("�����������");
//			scanf("%d %d", &x, &y);
//			ret = p[input](x, y);
//		}
//		else 
//			printf("��������\n");
//		printf("ret = %d\n", ret);
//	}
//	return 0;
//}

//================������:�ص�����===========
//void result(int (*p)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("���������:");
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
//		printf("��ѡ��");
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
//			printf("�˳�����\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}



/*
	ָ����ָ�������ָ��
*/
//
//void test(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	//����ָ��
//	void (*pfun)(const char*) = test;
//	//����ָ������
//	void(*pfunArr[5])(const char* str);
//	pfunArr[0] = test;
//	//ָ����ָ�������ָ��
//	void (*(*ppfunArr)[10])(const char*) = &pfunArr;
//	return 0;
//}



/*
	============= �ص������Ľ�һ��ѧϰ =========
*/

//ʹ�ûص�������ģ��ʵ��qsort(ð�ݷ�������������������
//qsort  �������Ԫ�ؽ�������
//void qsort(void* base, size_t num, size_t size,int (*compar)(const void*, const void*));
//���� void*base ָ��Ҫ���������ĵ�һ�������ָ�룬�ö�����ת��Ϊ void*
//size_t num ��ָ��������е�Ԫ������
//size_t size ������ÿ��Ԫ�صĴ�С�����ֽ�Ϊ��λ��
/* 
int (*compar)(const void*, const void*) ָ��Ƚ�����Ԫ�صĺ�����ָ�롣
<0	��ָ���Ԫ������ָ���Ԫ��֮ǰp1p2  p1<p2
 0	ָ���Ԫ�ص�Ч��ָ���Ԫ��p1p2		p1=p2
> 0	ָ���Ԫ��λ��ָ���Ԫ��֮��p1p2	p1>p2
*/

//�Ƚ���������
int cmp_int(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}

//�Ƚ�����������
int cmp_float(const void* p1, const void* p2)
{
	return (int)(*(float*)p1 - *(float*)p2);
}
struct Stu
{
	char* name;
	int age;
};

//�ȽϽṹ�������age
int cmp_stu_by_age(const void* p1, const void* p2)
{
	return (((struct Stu*)p1)->age - ((struct Stu*)p2)->age);
}

//�ȽϽṹ�������name(�ַ�����
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
//���Խ��������������͵�����
void bubble_sort(void *base,size_t num,size_t size, int (*cmp)(const void*, const void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			//�����������ıȽϣ��Ӷ��ж��Ƿ񽻻�
			//��baseǿ��ת����char*���ͣ������κε����ͣ������Ը������͵Ĵ�С��һ�����ֽ�ȥ�ı�
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
	ָ���������������
*/
//һά����
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));		// 16
//	printf("%d\n", sizeof(a + 0));	// 4/8 32λ������4���ֽڣ�64λ������8���ֽ�
//	printf("%d\n", sizeof(*a));		// 4
//	printf("%d\n", sizeof(a + 1));	// 4/8
//	printf("%d\n", sizeof(a[1]));	// 4
//	printf("%d\n", sizeof(&a));		// 4/8
//	printf("%d\n", sizeof(*&a));	// 16
//	printf("%d\n", sizeof(&a + 1));	// 4/8
//	printf("%d\n", sizeof(&a[0]));	// 4/8
//	printf("%d\n", sizeof(&a[0] + 1));	//	4/8
//}


//�ַ�����
// 
//	����������������⣬���������������ʾ��Ԫ�صĵ�ַ
//	  1.sizeof(������)-��������ʾ��������
//	  2. &������ - ��������ʾ��������

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
	
	//strlen����ֱ������'\0'��ֹͣ
	//printf("%d\n", strlen(arr));	// ���ֵ	
	//printf("%d\n", strlen(arr + 0));// ���ֵ
	////printf("%d\n", strlen(*arr));	// error ����,��a=97��Ϊ��ַ���룬�������
	////printf("%d\n", strlen(arr[1]));	//���ֵ
	//printf("%d\n", strlen(&arr));	// ���ֵ
	//printf("%d\n", strlen(&arr + 1));	//���ֵ
	//printf("%d\n", strlen(&arr[0] + 1));	//���ֵ

	//char arr[] = "abcdef";//"abcdef"Ϊ�����ַ�������'\0'��β
	//printf("%d\n", sizeof(arr));	// 7 �������һ�������ַ�
	//printf("%d\n", sizeof(arr + 0));	// 4/8
	//printf("%d\n", sizeof(*arr));		// 1
	//printf("%d\n", sizeof(arr[1]));		// 1
	//printf("%d\n", sizeof(&arr));		// 4/8
	//printf("%d\n", sizeof(&arr + 1));	// 4/8
	//printf("%d\n", sizeof(&arr[0] + 1));	// 4/8

	//printf("%d\n", strlen(arr));	// 6
	//printf("%d\n", strlen(arr + 0));	// 6
	////printf("%d\n", strlen(*arr));		// error,a='97',�Ƿ����ʣ����򱨴�
	////printf("%d\n", strlen(arr[1]));		//  error
	//
	//printf("%d\n", strlen(&arr));		// 6 
	//printf("%d\n", strlen(&arr + 1));	// ���ֵ
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
	//printf("%d\n", strlen(&p));			// ���ֵ
	//printf("%d\n", strlen(&p + 1));		// ���ֵ
	//printf("%d\n", strlen(&p[0] + 1));	// 5

	//��ά����
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
	ָ����ر�����
*/

//��Ŀ1
//����Ľ����ʲô��
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//		2  5
//	return 0;
//}

//��Ŀ2
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
//	printf("%p\n", p + 0x1); //��ַ����һ���ṹ���С
//	printf("%p\n", (unsigned long)p + 0x1);	// ǿתΪunsigned long���ͣ���ֵ��1
//	printf("%p\n", (unsigned int*)p + 0x1);	//����һ������ָ���С
//	return 0;
//}

////��Ŀ3
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 4);//��a����Ԫ�صĵ�ַǿ��ת�������ͣ�����ַֻ����һ���ѣ��޷����ʵ���Ԫ��
//	printf("%x,%x", ptr1[-1], *ptr2);//4 �쳣 //��ַ�����쳣���޷�������ֵ
//	return 0;
//}

//
////��Ŀ4
//#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };//(0,1)���ű��ʽ��ȡ���ұߵ�ֵ1��3��5
//	int* p=NULL;
//	p = a[0];
//	printf("%d\n", p[0]); // 1
//	return 0;
//}

//��Ŀ5
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//FFFFFFFFFFFFFFFC,-4
// //�ؼ����������ָ������ô��Ŷ�ά�����
//	return 0;
//}

//��Ŀ6
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1)); //10 5
//	return 0;
//}

//��Ŀ7
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

//��Ŀ8
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = &cp;
	printf("%s\n", **++cpp);//POINT
	printf("%s\n", *-- * ++cpp + 3);	// ER!! 
	//�ȼ��� ++cpp, ==> *++cpp==> --*++cpp==>> *--*++cpp  +3
	printf("%s\n", *cpp[-2] + 3);		//	ST
	printf("%s\n", cpp[-1][-1] + 1);	//EW!!!
	return 0;
}

