#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
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
	int* ptr = (int*)malloc(10 * sizeof(int));
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
	int a[]; //���������Ա
	//int a[0]
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
typedef struct st_type2
{
	int i;
	int* p_a;
}type_b;
void replace_flexible_array()
{
	int i = 0;
	type_b* p = malloc(sizeof(type_b));
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



/*
*	===============================
	ϰ����ϰ��
*	===============================

*/

/*
* 
	��ϰ1��
	�ӱ�׼�����ȡһ����EOF��β��������������һ��������Щֵ�Ķ�̬��������飬
	����ĵ�һ��Ԫ��������������ֵ������������Ԫ��Ϊ���������ֵ

*/
#define DETAL 10  //detal��ʾ����
int* ReadInts()
{
	int value;	//��ȡ������
	int count = 0;	//����
	int* array;	//���һ������������
	int size;	//��ʾ����Ĵ�С

	/*
		�����������飬��С��������DETAL��ֵ
	*/
	size = DETAL;
	array = (int*)malloc((size + 1) * sizeof(int));
	//assert(array != NULL);
	if (array == NULL)
	{
		return NULL;
	}

	/*
		�ӱ�׼����������ֵ
	*/

	while (scanf("%d", &value) == 1)
	{
		count += 1;

		//�����Ƿ���Ҫ����,���洢���������ֵ
		if (count > size)
		{
			size += DETAL;
			array = (int*)realloc(array, (size + 1) * sizeof(int));
			//assert(array != NULL);
			if (array == NULL)
			{
				return NULL;
			}
		}
		array[count] = value;
		
	}

	/*
		�������̬������ڴ棺
		ʹ��realloc�ı�����ĳ��ȣ�ʹ��պÿ��Դ洢����������ֵ���ü�1��
		�ٷ�������
	*/
	if (size > count)
	{
		array = (int*)realloc(array, (count + 1) * sizeof(int));
	}
	array[0] = count;
	return array;

}


/*
	��ϰ2��
	�ӱ�׼�����ж�ȡһ���ַ����� ���ַ������Ƶ���̬������ڴ��У����ظ��ַ����Ŀ�����
	���Ҳ��Ըö����ַ����ĳ������κ����ƣ�

*/

char* ReadString()
{

	static char* buffer = NULL;	//���뻺����
	static int buffer_size = 0;	//�������Ĵ�С
	char* bp;		//���ؿ������ַ���
	int len;		//�����ַ����ĳ���
	char ch;		//������ַ�
	len = 0;
	bp = buffer;
	buffer_size = DETAL;
	buffer = (char*)malloc((buffer_size ) * sizeof(char));
	assert(buffer!=NULL);

	/*
		һ�λ�ȡһ���ַ���ֱ����ȡ���з�'\n'��EOF�ѵ��
	*/
	do {
		ch = getchar();
		if (ch == '\n' || ch == EOF)
		{
			ch = '\0';
		}
		if (len > buffer_size)
		{
			buffer_size += DETAL ;
			buffer = (char*)realloc(buffer, (buffer_size) * sizeof(char));//buffer_size+1��Ϊ�˴洢���һ��\0�ַ�
			assert(buffer != NULL);
			buffer += len;
		}
		//*buffer++ = ch;//vs�³���
		buffer[len] = ch;
		len++;

	} while (ch!='\0');
	
	bp = (char*)malloc(len * sizeof(char));
	assert(bp != NULL);
	strcpy(bp, buffer);
	return bp;

}

//�������������VS��������
char* ReadString2()
{

	static char* buffer = NULL;	//���뻺����
	static int buffer_size = 0;	//�������Ĵ�С
	char* bp;		//���ؿ������ַ���
	int len;		//�����ַ����ĳ���
	int ch;		//������ַ�
	len = 0;
	bp = buffer;

	/*
		һ�λ�ȡһ���ַ���ֱ����ȡ���з�'\n'��EOF�ѵ��
	*/
	do {
		ch = getchar();
		if (ch == '\n' || ch == EOF)
		{
			ch = '\0';
		}
		//���������������ˣ�������
		if (len >= buffer_size)
		{
			buffer_size += DETAL;
			buffer = (char*)realloc(buffer, buffer_size);
			assert(buffer != NULL);
			buffer += len;//ÿ�����ݣ����ƶ�����һ����հ״�������ÿ�ζ�ȡ�ַ���ʱ����ͷ��ʼ����̬��������Ŀ�����
		}
		*buffer = ch;
		buffer++;
		len++;

	} while (ch != '\0');

	//���ظ��Ƶ��ַ���
	bp = (char*)malloc(len);
	assert(bp != NULL);
	strcpy(bp, buffer);
	return bp;

}




int main()
{

	/*int* ps = ReadInts();
	int i = 0;
	for (i = 0; i <= ps[0]; i++)
	{
		printf("%d ", ps[i]);
	}*/
	printf("%s\n",ReadString());
	//free(ReadString());
	
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
	//Test4();
	//flexible_array();




	return 0;
}