
//	Created by ���� on 2020/02/02.
//  Copyright  2020 ����. All rights reserved.

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
	Ԥ����
*/
void stack_prepare(struct Stack* stack);

/*
	Ԥ����
*/
void check_values(struct Stack* stack);

/*
	����
*/
void dilatation(struct Stack* stack);