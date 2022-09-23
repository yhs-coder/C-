#define _CRT_SECURE_NO_WARNINGS

#include"alloc.h"
#undef malloc  //在alloc.c文件中可调用malloc,其它文件不可直接调用malloc
void* alloc(size_t size)
{
	void* new_num;
	new_num = malloc(size);
	//检查是否分配成功
	if (new_num == NULL)
	{
		printf("Out of memory!\n");
		exit(1);
	}
	return new_num;
}
