#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#include <ctype.h>
/*
	�ַ��������ַ�������
*/

/*
	strlen():���ַ����ĳ���
*/


void test_strlen()
{
	
	const char* str1 = "abcdef";
	const char* str2 = "bbb";
	if (strlen(str1) - strlen(str2) > 0)
	{
		printf("str1>str2\n");
	}
	else
	{
		printf("str1<str2\n");

	}
	//printf("%d\n", my_strlen("hello C/C++!"));
}


void test_strcpy()
{
	char dest[] = "*************";
	char* src = NULL;
	strcpy(dest, "hello C/C++");
	printf("%s\n", dest);
}

/*
	strcat : ��һ���ַ���׷�ӵ���һ���ַ���֮��
	This function starts comparing the first character of each string. If they are equal to each other, itcontinues with the following pairs until the characters differ or until a terminating null-character is
	  reached.
*/
void test_strcat()
{
	char str[80];
	strcpy(str, "these ");
	strcat(str, "strings ");
	strcat(str, "are ");
	strcat(str, "concatenated. ");
	//strcat(str, str);//׷�ӵ��ַ�����������Ŀ���ַ����ص�
	puts(str);

}

/*
	strcmp:�Ƚ������ַ�����С
	ptr1 >ptr2  ����ֵ >0
	ptr1 =ptr2  ����ֵ =0
	ptr1 <ptr2  ����ֵ <0

*/

//void test_fflush()
//{
//	char mybuffer[80];
//	FILE* pFile;
//	pFile = fopen("example.txt", "r+");
//	if (pFile == NULL) perror("Error opening file");
//	else {
//		fputs("test", pFile);
//		fflush(pFile);    // flushing or repositioning required
//		fgets(mybuffer, 80, pFile);
//		puts(mybuffer);
//		fclose(pFile);
//}

void test_ctrcmp()
{
	char key[] = "apple";
	char buffer[80];
	do
	{
		printf("Guess my favorite fruit?");
		//fflush(stdout);
		//��������������£���Ϊȡ�����ض��Ŀ�ʵ�֡���ĳЩʵ���У�ˢ�´򿪵����Խ��ж�ȡ�ᵼ����������뻺����
		scanf("%79s", buffer);
	} while (strcmp(key, buffer) != 0);
	puts("Correct answer!");
}


/*
	strncpy()
	char * strncpy ( char * destination, const char * source, size_t num );
	���ַ����и����ַ�
	��Դ��ǰ num ���ַ����Ƶ�Ŀ�ꡣ
	����ڸ��������ַ�֮ǰ�ҵ�Դ C �ַ������ɿ��ַ���ʾ����ĩβ����Ŀ�꽫����(��'\0')��䣬ֱ���ܹ�д�������ַ�Ϊֹ��

*/
void test_strncpy()
{
	char str1[] = "To be or not to be";
	char str2[40];
	char str3[40];

	//���Ƶ���С�������������ȫ��
	strncpy(str2, str1, sizeof(str2));//

	//���ָ���
	strncpy(str3, str2, 5);
	str3[5] = '\0'; //��ӿ��ַ���ĩβ
	puts(str1);
	puts(str2);
	puts(str3);
}


/*
* 	strncat
	char * strncat ( char * destination, const char * source, size_t num );
	��Դ��ǰ num ���ַ�׷�ӵ�Ŀ�꣬���һ����ֹ���ַ���

*/
void test_strncat()
{
	char str1[20];
	char str2[20];
	strcpy(str1, "To be ");
	strcpy(str2, "or not to be");
	strncat(str1, str2, 6);
	puts(str1);
}

/*
*	=== strncmp ===
	int strncmp(const char*str1,const char * str2, size_t num );

*/
void test_strncmp()
{
	char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n < 3; n++)
	{
		if (strncmp(str[n], "R2xx", 2) == 0)
		{
			printf("founf %s\n", str[n]);
		}
	}
}

/*
	=== strstr ====
	��λ���ַ���:����ָ�� str1 �е�һ�γ��ֵ� str2 ��ָ�룬��� str2 ���� str1 ��һ���֣��򷵻ؿ�ָ�롣
	const char * strstr ( const char * str1, const char * str2 );
*/

void test_strstr()
{
	char str[] = "This is a simple string";
	char* pch;
	pch = strstr(str, "simple");
	strncpy(pch, "sample", 6);
	puts(str);
}

/*
	=== strtok ===
	���ݷָ�����ǣ��з��ַ���
	char * strtok ( char * str, const char * delimiters );
*/

void test_strtok()
{
	char str[] = "- This, a sample string.";
	char* pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str, " ,.-");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}

}
void test_strtok_copy()
{
	char* p = "zhazhabo@qq.com";
	const char* sep = ".@";
	char arr[30];
	char* str = NULL;
	strcpy(arr, p);//�����ݿ���һ�ݣ�����arr���������
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	{
		printf("%s\n", str);
	}
}

/*
	=== strerror ===
	���ش����룬����Ӧ�Ĵ�����Ϣ��
	char * strerror��int errnum)

*/

void test_strerror()
{
	FILE* pFile;
	pFile = fopen("unexit.txt", "r");
	if (pFile == NULL)
	{
		printf("Error opening file unexist.txt: %s\n", strerror(errno));
		//errno:Last error number
	}

}

/*
	�ַ����ຯ��
	ͷ�ļ��� <ctype.h>
*/
void classify()
{
	int i = 0;
	char str[] = "Test String.\n";
	char c;
	while (str[i])
	{
		c = str[i];
		/* isupper()  �ж��Ƿ�Ϊ��д��ĸ*/
		if (isupper(c))
		{
			/*	int tolower(int c);
				����д��ĸת��ΪСд��ĸ*/
			c = tolower(c);
		}
		putchar(c);
		i++;
	}
}

/*
	 === memcpy ===
	 ���ã������ڴ��
	 void * memcpy ( void * destination, const void * source, size_t num );
*/
struct {
	char name[40];
	int age;

}person, person_copy;
void test_memcpy()
{
	char myname[] = "Pierre de Fermat";
	/* using memcpy to copy string: */
	memcpy(person.name, myname, strlen(myname + 1));
	person.age = 22;

	/* using memcpy to copy structure: */
	memcpy(&person_copy, &person, sizeof(person));
	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
}


/*
	=== memmove ===
	���ã��ƶ��ڴ��
	void * memmove ( void * destination, const void * source, size_t num );
	��memcpy�Ĳ�����memmove���������Դ�ڴ���Ŀ���ڴ���ǿ����ص��ġ�
*/

void test_memmove()
{
	char str[] = "memmove can be very useful......";
	memmove(str + 20, str + 15, 11);
	puts(str);
}

/*
	=== memcmp ===
	���ã��Ƚ������ڴ��
	int memcmp ( const void * ptr1, const void * ptr2, size_t num );
	����num:Ҫ�Ƚϵ��ֽ�����
*/

void test_memcmp()
{
	char buffer1[] = "DWgaOtP12df0";
	char buffer2[] = "DWGAOTP12DF0";
	int n;
	n = memcmp(buffer1, buffer2, sizeof(buffer1));
	if (n > 0)
	{
		printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
	}
	else if (n < 0)
	{
		printf("'%s' is less than '%s'.\n", buffer1, buffer2);
	}
	else
	{
		printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
	}

}

/*
	*************** ģ��ʵ�ֿ⺯�� ****************
	
/*
	ģ��ʵ��strlen
*/

//��ʽһ��ָ�� - ָ�� 
size_t my_strlen_one(const char* str)
{
	const  char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}

//��ʽ��: ��������ʽ
size_t my_strlen_two(const char* str)
{
	int count = 0;
	assert(str != NULL); //��ָ֤�����Ч��
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

//��ʽ���� �ݹ���ñ�����������ʱ����������
int my_strlen_three(const char * str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen_three(str + 1);
}



/*
	ģ��ʵ��strcpy
*/
//��Ҫ���ǵ����⣺
//1.����˳��
//2.�����Ĺ��ܣ�ֹͣ����
//3.assert 
//4.const����ָ��
//5.��������ֵ
char* my_strcpy(char* dest, const char* src)
{
	/*while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;*/

	/*
		�Ż���Ĵ���
	*/
	assert(dest != NULL); //����
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}

}

/*
	ģ��ʵ��strcat
*/

char* my_strcat(char* dest, const char* src)
{
	/*char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest)
	{
		dest++;
	}
	while ((*dest++ = *src++))
	{
		;
	}
	return ret;*/
	char* tmp=dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*tmp != '\0')
	{
		tmp++;
	}
	while (*src != '\0')
	{
		*tmp++ = *src++;
	}
	*tmp = '\0';
	return dest;
}
void test_my_strcat()
{
	char str[80];
	strcpy(str, "these ");
	my_strcat(str, "strings ");
	my_strcat(str, "are ");
	my_strcat(str, "concatenated. ");
	puts(str);
}


/*
	ģ��ʵ��ststr
*/

/*
	����const�ڲ�ͬλ��ʱ�����ã�
	1. const int* p , const���ε���int,ָ��pָ������ݲ����޸ģ���*p�������޸�
	2. int* const p , const���ε���ָ��p��p��ָ�򲻿��޸ģ���ָ�뱾��p�����޸�
	2.const int* const p,  �����޸�*p��p
*/
char *my_strstr(const char *str1,const char *str2)
{
	assert(str1);
	assert(str2);
	//��Ϊ�����޸�strָ������ݣ����Ա���ǿת����ֵ��cpȥ����
	char* cp = (char*)str1;
	char* substr = (char*)str2;
	char* s1 = NULL;//���ڱȽϵı���
	if (*str2 == '\0')
	{
		return NULL;
	}

	//������str1��cp��ֱ������β
	while (*cp)
	{
		s1 = cp;//����ַ�����Ԫ�ص���ʼ��ַ
		substr = str2;//ÿ��ѭ��������ָ��ָ���λ�ã�����ָ��str2����ʼλ��

		//ֹͣ�������� s1Ϊ'\0',�����Ѿ�ƥ�������*substr=��\0'
		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		if (*substr == '\0')
		{
			return cp;
		}
		cp++;
	}
}

void test_my_strstr()
{
	char str[] = "This is a simple string";
	char* pch;
	pch = my_strstr(str, "simple");
	strncpy(pch, "sample", 6);
	puts(str);
}

/*
	ģ��ʵ��strcmp
*/

int my_strcmp(const char* src, const char* dst)
{
	int ret = 0;
	assert(src != NULL);
	assert(dst != NULL);
	while (!(ret=*(unsigned char *)src - *(unsigned char*)dst)&&*dst)
	{
		//ret=*(unsigned char *)src - *(unsigned char*)dst���������0��������ȣ������Ƚ�
		src++;
		dst++;
	}
	if (ret < 0) ret = -1;
	else if (ret > 0) ret = 1;
	return (ret);
}

/*
	ģ��ʵ��memcpy
*/
void* my_memcpy(void* dst, const void* src, size_t count)
{
	void* ret = dst;
	assert(dst!=NULL);
	assert(src!= NULL);
	while (count--)
	{
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return ret;

}
void test_my_memcpy()
{
	char myname[] = "Pierre de Fermat";
	/* using memcpy to copy string: */
	my_memcpy(person.name, myname, strlen(myname + 1));
	person.age = 22;
	/* using memcpy to copy structure: */
	my_memcpy(&person_copy, &person, sizeof(person));
	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
}
/*
	ģ��ʵ��memmove
*/
void* memcpy(void* dst, const void* src, size_t count)
{
	void* ret = dst;
	assert(dst!= NULL);
	assert(src != NULL);
	if (dst <= src || (char*)dst >= ((char*)src + count))//dstҪô��srcǰ�棬Ҫô��src+count���ֽ�֮��
	{
		//���ص�������
		//�ӽϵ͵�ַ���Ƶ��ϸߵ�ַ
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//�ص�������
		//�ӽϸߵ�ַ���Ƶ��ϵ͵�ַ
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;
		while (count--) {
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}

int main()
{

	//test_strlen();
	//test_strcpy();
	//test_strcat();
	//test_ctrcmp();
	//test_strncpy();
	//test_strncat();
	//test_strncmp();
	//test_strstr();
	//test_strtok();
	//test_strtok_copy();
	//test_strerror();
	//classify();
	//test_memcpy();
	//test_memmove();
	//test_memcmp();
	//test_my_strcat();
	//test_my_strstr();
	//printf("%d\n", my_strcmp("hello","hellz"));
	//test_my_memcpy();
	return 0;
}


