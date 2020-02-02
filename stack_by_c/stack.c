
//	Created by 葛振东 on 2020/02/02.
//  Copyright  2020 葛振东. All rights reserved.

#include "stack.h"
#define INITIAL_SIZE 16				//初始大小
#define GROWTH_FACTOR  1			//增长因子
#define MULTIPLE 2					//扩大倍数

struct Stack* new_stack()
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	check_malloc_memory(stack);
	stack_prepare(stack);
	return stack;
}

void push(struct Stack* stack, char* value)
{
	check_values(stack);
	stack->values[stack->current++] = value;
}

char* pop(struct Stack* stack)
{
	return stack->values[--stack->current];
}

void del_stack(struct Stack* stack)
{
	for (int i = 0, size = stack->current; i < size; i++)
	{
		free(stack->values[i]);
	}
	free(stack->values);
	free(stack);
}

void stack_prepare(struct Stack* stack)
{
	stack->current = 0;
	stack->size = 0;
	stack->values = NULL;
}

void check_values(struct Stack* stack)
{
	if (stack->values == NULL)
	{
		stack->values = (char**)malloc(sizeof(char*) * INITIAL_SIZE);
		stack->size = INITIAL_SIZE;
		return;
	}
	//达到倍数需要扩容
	if (stack->current == stack->size * GROWTH_FACTOR)
	{
		dilatation(stack);
	}
}

void dilatation(struct Stack* stack)
{
	int new_size = stack->size * MULTIPLE;
	char** old_value = stack->values;
	char** new_value = (char**)malloc(sizeof(char*) * new_size);
	check_malloc_memory(new_value);
	for (int i = 0, size = stack->size; i < size; i++)
	{
		new_value[i] = old_value[i];
	}
	stack->size = new_size;
	stack->values = new_value;
	free(old_value);
}