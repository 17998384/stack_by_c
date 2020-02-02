
//	Created by 葛振东 on 2020/02/02.
//  Copyright  2020 葛振东 All rights reserved.

#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

void test1()
{
	struct Stack* stack = new_stack();
	for (int i = 0; i < 10000; i++)
	{
		char* str1 = (char*)malloc(sizeof(char) * 20);
		sprintf(str1, "%s%d", "ceshi", i);
		push(stack, str1);
	}
	del_stack(stack);
}

void test(void)
{
	struct Stack* stack = new_stack();
	char* str1 = (char*)malloc(sizeof(char) * 20);
	char* str2 = (char*)malloc(sizeof(char) * 20);
	char* str3 = (char*)malloc(sizeof(char) * 20);
	strcpy(str1, "测试1");
	strcpy(str2, "测试2");
	strcpy(str3, "测试3");
	push(stack, str1);
	push(stack, str2);
	push(stack, str3);
	char* str4 = pop(stack);
	char* str5 = pop(stack);
	char* str6 = pop(stack);
	printf("%s\n", str4);
	printf("%s\n", str5);
	printf("%s\n", str6);
	free(str4);
	free(str5);
	free(str6);
	del_stack(stack);
}

int main(void)
{
	for (int i = 1; i <= 100000; i++)
	{
		printf("测试第%d次\n", i);
		test1();
	}
	return 0;
}
