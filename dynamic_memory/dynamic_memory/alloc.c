#define _CRT_SECURE_NO_WARNINGS

#include"alloc.h"
#undef malloc  //��alloc.c�ļ��пɵ���malloc,�����ļ�����ֱ�ӵ���malloc
void* alloc(size_t size)
{
	void* new_num;
	new_num = malloc(size);
	//����Ƿ����ɹ�
	if (new_num == NULL)
	{
		printf("Out of memory!\n");
		exit(1);
	}
	return new_num;
}
