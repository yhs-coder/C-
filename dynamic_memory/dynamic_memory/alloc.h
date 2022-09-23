#define _CRT_SECURE_NO_WARNINGS

/*
	定义一个不易出错的内存分配器
*/


#include<stdlib.h>
#include<stdio.h>

//错误检查分配器的接口
#define malloc       //不能直接调用malloc
#define MALLOC(num,type)  (type*)alloc((num)*sizeof(type))
extern void* alloc(size_t size);

