#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAXPARTS 1000

/*
	变体记录
	例子：存货系统
*/

struct PARTINFO	//零件
{
	int cost; //价格
	int supplier;//供应
};

struct SUBASSYINFO	//装配件
{
	int n_parts; 
	struct
	{
		char partno[10];
		short quan;
	}part[MAXPARTS];
};

struct INVENTORY	//存货
{
	char partno[10];
	int quan;
	enum {PART,SUBASSY} type;
	union
	{
		struct PARTINFO  part;
		struct SUBASSYINFO	subassy;
	}info;
};


/*
	结构体的声明
*/

struct Stu
{
	char namr[20];
	int age;
	char sex[5];
	char id[20];
};

/*
	特殊的声明
*/
//匿名结构体类型
//匿名结构体创建的变量，会被编译器识别为不同的类型
struct
{
	int a;
	char b;
	float c;
}x;
struct
{
	int a;
	char b;
	float c;
}a[20],*p;
//p = &x;//error
//匿名结构体创建的变量，就算内部成员相同，也会被编译器识别为不同的类型


/*
	结构体的自引用
*/

//代码1
//struct Node
//{
//	int data;
//	struct Node next;
//};
//此为错误示范，结构体内部自引用结构体，如果创建的是结构体的变量，那么该变量又会指向下一个成员，成员又会指向下一个成员，，像递归一样无条件不断运行，不能得知结构体的大小

//正确的自引用方式
struct Node
{
	int data;
	struct Node* next;
};


/*
	结构体变量的定义和初始化
*/

struct Point
{
	int x;
	int y;
}y;//声明类型的同时定义变量p1
struct Point p2={1,2};//定义结构体变量p2的同时赋值

struct Nodes
{
	int data;
	struct Point p;
	struct Node* next;
}n1={10,{1,2},NULL};//结构体嵌套初始化


/*
	！！！！！！！！！！
	结构体内存对齐
*/
//计算以下结构体的大小
struct S1
{
	char c1;
	int i;
	char c2;
};

struct S2
{
	char c1;
	char c2;
	int i;
};

struct S3
{
	double d;
	char c;
	int i;
};

//结构体嵌套问题
struct S4
{
	char c1;
	struct S3 s3;
	double d;
};


//设计结构体的时候,让占用空间小的成员尽量集中在一起。如S2
#pragma pack(1)//设置对齐数为4
struct S21
{
	char c1;
	int i;
	char c2;
};
#pragma pack()//取消设置的默认对齐数，还原为默认


/*
	结构体传参!
	传地址是最优选
*/
struct S
{
	int data[1000];
	int num;
};
struct S s = { {1,2,3,4}, 1000 };

//结构体传参
void print1(struct S s)
{
	printf("%d\n", s.num);
}

//结构体地址传参✔
void print2(struct S* ps)
{
	printf("%d\n", ps->num);
}


/*
	位段
*/

struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};

void test1()
{
	struct A a = { 0 };
	a._a = 10;
	a._b = 12;
	a._c = 3;
	a._d = 4;

}

struct SS
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};

void test2()
{
	struct SS s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
}


/*
	枚举
*/
enum Color//颜色
{
	RED = 1,
	GREEN = 2,
	BLUE = 4
};


/*
	Union 联合
*/
//联合类型的声明
union Un
{
	char c;
	int i;
}un;

// 利用联合判断当前计算机的大小端存储
int check_sys()
{
	un.i = 1;
	return un.c;
}

union Un1
{
	char c[5];
	int i;
};

union Un2
{
	short c[7];
	int i;
};


int main()
{
//	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));



	//printf("%d\n", sizeof(un));
	////查看联合里成员的地址
	//printf("%u\n", &(un.i));
	//printf("%u\n", &(un.c));
	//un.i = 0x11223344;
	//printf("%x\n", un.c); //0x44

	int res = check_sys();
	if (res)
	{
		printf("小端模式！\n");
	}
	else
	{
		printf("大端模式！\n");

	}



	//enum Color clr = GREEN;
	//int i = RED;
	//printf("%d\n", i);
	//printf("%d\n", sizeof(struct Node));
	//printf("%d\n", sizeof(struct S1));
	//printf("%d\n", sizeof(struct S2));
	//printf("%d\n", sizeof(struct S3));
	//printf("%d\n", sizeof(struct S21));
	//print1(s);
	//print2(&s);
	//printf("%d\n", sizeof(struct A));
	//test2();
	//test1();




	return 0;
}