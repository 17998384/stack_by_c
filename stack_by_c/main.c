
//	Created by ¸ðÕñ¶« on 2020/02/02.
//  Copyright  2020 ¸ðÕñ¶« All rights reserved.

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
	strcpy(str1, "²âÊÔ0");
	strcpy(str2, "²âÊÔ1");
	strcpy(str3, "²âÊÔ2");
	push(stack, str1);
	push(stack, str2);
	push(stack, str3);
	struct Node* str4 = poll(stack);
	struct Node* str5 = poll(stack);
	struct Node* str6 = poll(stack);
	printf("%s\n", str4->value);
	printf("%s\n", str5->value);
	printf("%s\n", str6->value);
	free(str4);
	free(str5);
	free(str6);
	del_stack(stack);
}

int main(void)
{
	for (int i = 1; i <= 1000; i++)
	{
		printf("²âÊÔµÚ%d´Î\n", i);
		test1();
	}
	//test();
	return 0;
}
