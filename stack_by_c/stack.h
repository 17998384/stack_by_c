
//	Created by 葛振东 on 2020/02/02.
//  Copyright  2020 葛振东. All rights reserved.

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

struct Stack
{
	char** values;
	int current;
	int size;
};

/*
	new
*/
struct Stack* new_stack();

/*
	push
*/
void push(struct Stack* stack, char* value);

/*
	pop
*/
char* pop(struct Stack* stack);

/*
	del
*/
void del_stack(struct Stack* stack);

/*
	预处理
*/
void stack_prepare(struct Stack* stack);

/*
	预处理
*/
void check_values(struct Stack* stack);

/*
	扩容
*/
void dilatation(struct Stack* stack);