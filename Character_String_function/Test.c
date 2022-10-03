#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#include <ctype.h>
/*
	字符函数和字符串函数
*/

/*
	strlen():求字符串的长度
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
	strcat : 将一个字符串追加到另一个字符串之后，
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
	//strcat(str, str);//追加的字符串，不能与目标字符串重叠
	puts(str);

}

/*
	strcmp:比较两个字符串大小
	ptr1 >ptr2  返回值 >0
	ptr1 =ptr2  返回值 =0
	ptr1 <ptr2  返回值 <0

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
		//在所有其他情况下，行为取决于特定的库实现。在某些实现中，刷新打开的流以进行读取会导致清除其输入缓冲区
		scanf("%79s", buffer);
	} while (strcmp(key, buffer) != 0);
	puts("Correct answer!");
}


/*
	strncpy()
	char * strncpy ( char * destination, const char * source, size_t num );
	从字符串中复制字符
	将源的前 num 个字符复制到目标。
	如果在复制数字字符之前找到源 C 字符串（由空字符表示）的末尾，则目标将用零(即'\0')填充，直到总共写入数字字符为止。

*/
void test_strncpy()
{
	char str1[] = "To be or not to be";
	char str2[40];
	char str3[40];

	//复制到大小缓冲区（溢出安全）
	strncpy(str2, str1, sizeof(str2));//

	//部分复制
	strncpy(str3, str2, 5);
	str3[5] = '\0'; //添加空字符到末尾
	puts(str1);
	puts(str2);
	puts(str3);
}


/*
* 	strncat
	char * strncat ( char * destination, const char * source, size_t num );
	将源的前 num 个字符追加到目标，外加一个终止空字符。

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
	定位子字符串:返回指向 str1 中第一次出现的 str2 的指针，如果 str2 不是 str1 的一部分，则返回空指针。
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
	根据分隔符标记，切分字符串
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
	strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	{
		printf("%s\n", str);
	}
}

/*
	=== strerror ===
	返回错误码，所对应的错误信息。
	char * strerror（int errnum)

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
	字符分类函数
	头文件： <ctype.h>
*/
void classify()
{
	int i = 0;
	char str[] = "Test String.\n";
	char c;
	while (str[i])
	{
		c = str[i];
		/* isupper()  判断是否为大写字母*/
		if (isupper(c))
		{
			/*	int tolower(int c);
				将大写字母转换为小写字母*/
			c = tolower(c);
		}
		putchar(c);
		i++;
	}
}

/*
	 === memcpy ===
	 作用：复制内存块
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
	作用：移动内存块
	void * memmove ( void * destination, const void * source, size_t num );
	和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的。
*/

void test_memmove()
{
	char str[] = "memmove can be very useful......";
	memmove(str + 20, str + 15, 11);
	puts(str);
}

/*
	=== memcmp ===
	作用：比较两个内存块
	int memcmp ( const void * ptr1, const void * ptr2, size_t num );
	参数num:要比较的字节数。
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
	*************** 模拟实现库函数 ****************
	
/*
	模拟实现strlen
*/

//方式一：指针 - 指针 
size_t my_strlen_one(const char* str)
{
	const  char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}

//方式二: 计数器方式
size_t my_strlen_two(const char* str)
{
	int count = 0;
	assert(str != NULL); //保证指针的有效性
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

//方式三： 递归调用本身，不创建临时变量计数器
int my_strlen_three(const char * str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen_three(str + 1);
}



/*
	模拟实现strcpy
*/
//需要考虑的问题：
//1.参数顺序
//2.函数的功能，停止条件
//3.assert 
//4.const修饰指针
//5.函数返回值
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
		优化后的代码
	*/
	assert(dest != NULL); //断言
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}

}

/*
	模拟实现strcat
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
	模拟实现ststr
*/

/*
	关于const在不同位置时的作用：
	1. const int* p , const修饰的是int,指针p指向的内容不可修改，即*p不可以修改
	2. int* const p , const修饰的事指针p，p的指向不可修改，即指针本身p不可修改
	2.const int* const p,  不可修改*p和p
*/
char *my_strstr(const char *str1,const char *str2)
{
	assert(str1);
	assert(str2);
	//因为不可修改str指向的内容，所以必须强转并赋值给cp去操作
	char* cp = (char*)str1;
	char* substr = (char*)str2;
	char* s1 = NULL;//用于比较的变量
	if (*str2 == '\0')
	{
		return NULL;
	}

	//遍历（str1）cp，直至到结尾
	while (*cp)
	{
		s1 = cp;//存放字符串首元素的起始地址
		substr = str2;//每次循环，重置指针指向的位置，让其指向str2的起始位置

		//停止的条件： s1为'\0',或者已经匹配结束，*substr=’\0'
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
	模拟实现strcmp
*/

int my_strcmp(const char* src, const char* dst)
{
	int ret = 0;
	assert(src != NULL);
	assert(dst != NULL);
	while (!(ret=*(unsigned char *)src - *(unsigned char*)dst)&&*dst)
	{
		//ret=*(unsigned char *)src - *(unsigned char*)dst，结果等于0，两者相等，继续比较
		src++;
		dst++;
	}
	if (ret < 0) ret = -1;
	else if (ret > 0) ret = 1;
	return (ret);
}

/*
	模拟实现memcpy
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
	模拟实现memmove
*/
void* memcpy(void* dst, const void* src, size_t count)
{
	void* ret = dst;
	assert(dst!= NULL);
	assert(src != NULL);
	if (dst <= src || (char*)dst >= ((char*)src + count))//dst要么在src前面，要么在src+count个字节之后
	{
		//非重叠缓冲区
		//从较低地址复制到较高地址
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//重叠缓冲区
		//从较高地址复制到较低地址
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


