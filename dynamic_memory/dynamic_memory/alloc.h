#define _CRT_SECURE_NO_WARNINGS

/*
	����һ�����׳�����ڴ������
*/


#include<stdlib.h>
#include<stdio.h>

//������������Ľӿ�
#define malloc       //����ֱ�ӵ���malloc
#define MALLOC(num,type)  (type*)alloc((num)*sizeof(type))
extern void* alloc(size_t size);

