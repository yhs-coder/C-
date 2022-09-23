#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
	ʹ��malloc��free
*/
void test1()
{
	int num = 0;
	scanf("%d", &num);
	int* ptr = NULL;
	ptr = (int*)malloc(num * sizeof(int));
	if (NULL != ptr)//�ж϶�̬�����ڴ淵�ص�ָ���Ƿ�Ϊ��
	{
		int i = 0;
		for (i = 0; i < num; i++)
		{
			ptr[i] = 0;
			printf("%d ", *ptr);
		}
	}
	free(ptr);//�ͷ�ptrָ��Ķ�̬�ڴ�
	ptr = NULL;

}

/*
	calloc��ʹ��
*/
void test2()
{
	//calloc���ص�ַ֮ǰ������Ŀռ��ÿ���ֽڳ�ʼ��Ϊȫ0��
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
	realloc��ʹ��
	�����ڴ�ռ�ʱ�������������
	1. ԭ�е��ڴ�ռ�����㹻���ڴ�ռ�׷��
	2. ԭ�е��ڴ�ռ�����㹻���ڴ�ռ䣬��Ҫ��������һ�����ʴ�С�������ռ���ʹ�á���ʱ����Ѿ��ڴ�����ݿ��������ڴ���
*/

void test3()
{
	int *ptr = (int*)malloc(10 * sizeof(int));
	if (ptr == NULL)
	{
		printf("Out of memory!");
		exit(-1);
	}
	//����
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
	�����Ķ�̬�ڴ����
*/

//1.��NULLָ��Ľ����ò���

/*
void test4()
{
	int *p = (int*)malloc(INT_MAX);
	*p = 100;
	free(p);
}

//2.�Զ�̬���ٿռ��Խ�����

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
		*(p + i) = i;//��i��10��ʱ��Խ�����
	}
	free(p);
}

//3. �ԷǶ�̬�����ڴ�ʹ��free�ͷ�
void test6()
{
	int a = 10;
	int* p = &a;
	free(p);//error
}

//4. ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
void test7()
{
	int* p = (int*)malloc(100);
	p++;//ָ��ָ����һ����ַ
	free(p);//��ʱָ�벻��ָ��̬�ڴ����ʼλ��
}

//5. ��ͬһ�鶯̬�ڴ����ͷ�
void test8()
{
	int* p = (int*)malloc(100);
	free(p);
	free(p);//�ظ��ͷ�
}

//6.��̬�����ڴ������ͷţ��ڴ�й©��!!!!!!!!!!
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
	�����Ŀ����ϰ
*/

//��Ŀ1��
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
	//���⣺Test ��������ʲô���Ľ����
	//���������ɳ���������ڴ�й©������
	//������1���βεĸı䲻��Ӱ��ʵ�Σ��βν�����ʵ�εĿ�������Ҫ��ַ�ſɸı䣡2����Ҫʹ��free�ͷŶ�̬������ڴ棬��������Դ�������ģ���
}

//��Ŀ2��
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
	//���⣺Test ��������ʲô���Ľ����
	//����������� 
	//������p����ջ�����ٵ��ڴ�ռ䣬���������н���ʱ��ջ���ᱻ���٣���ʱ���ص�pָ����ڴ�ռ��Ѿ��������ͷţ����·Ƿ������ڴ棡
}

//��Ŀ3��
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
	//���⣺����Test ��������ʲô���Ľ����
	//�����hello  
	//��������̬������ڴ�ʱ�����ڶ��ϵģ��������н���Ҳ�������ٵ���̬������ڴ�
	//���ֵ����⣺�ڴ�й©
}

//��Ŀ4��
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
	//���⣺����Test ��������ʲô���Ľ����
	//�����world  
	//����������if�жϣ�����������ͷŵĶ�̬�ڴ��Ƿ�ΪNULL!
}


/*
	�������飡������
	C99 �У��ṹ�е����һ��Ԫ��������δ֪��С�����飬��ͽ������������须��Ա��

	֪ʶ���䣺
	����������ص㣺
		1.�ṹ�е����������Աǰ���������һ��������Ա��
		2.sizeof ���ص����ֽṹ��С����������������ڴ档
		3.�������������Ա�Ľṹ��malloc ()���������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С������Ӧ
		���������Ԥ�ڴ�С��
*/

typedef struct st_type
{
	int i;
	int a[0]; //���������Ա
	//int a[]
}type_a;

//���������ʹ��
void flexible_array() 
{
	int i = 0;
	type_a* p = (type_a*)malloc(sizeof(type_a) + 100 * sizeof(int));
	//ҵ����
	p->i = 100;
	for (i = 0; i < 100; i++)
	{
		p->a[i] = i;
	}
	free(p);
	p = NULL;
}

//����д���ɴ�����������
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
	//ҵ����
	for (i = 0; i < 100; i++)
	{
		p->p_a[i] = i;
	}
	free(p->p_a);
	p->p_a = NULL;
	free(p);
	p = NULL;

}


//��������Ƚϵڶ��ִ���д������һ���ô��ǣ������ڴ��ͷš��ڶ����ô����������ڴ���������߷����ٶȣ�Ҳ�����ڼ����ڴ���Ƭ
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