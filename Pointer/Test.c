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
int my_strlen(char* s)
{
	char* p = s;
	while (*p != '\0')
		p++;
	return p - s;

}
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
void result(int (*p)(int, int))
{
	int x = 0;
	int y = 0;
	printf("���������:");
	scanf("%d %d", &x, &y);
	printf("num = %d\n", (*p)(x, y));
}
int main()
{
	int input = 1;

	int ret = 0;
	do
	{
		printf("*************************\n");
		printf(" 1:add           2:sub \n");
		printf(" 3:mul           4:div \n");
		printf(" 0:exit                \n");
		printf("*************************\n");
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			result(add);
			break;
		case 2:
			result(sub);
			break;
		case 3:
			result(mul);
			break;
		case 4:
			result(div);
			break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}



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










