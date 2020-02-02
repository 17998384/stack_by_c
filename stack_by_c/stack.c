
//	Created by ���� on 2020/02/02.
//  Copyright  2020 ����. All rights reserved.
//  �߱�ջ/���й���(Stack/queue capability)
//	���(push),ʹ��ջ����(pop)ʹ�ö���(poll)

#include "stack.h"

struct Stack* new_stack()
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	check_malloc_memory(stack);
	stack_prepare(stack);
	return stack;
}

void push(struct Stack* stack, char* value)
{
	if (stack->first == NULL)
	{
		struct Node* node = new_node(NULL, NULL, value);
		stack->first = node;
		stack->last = node;
	}
	else
	{
		struct Node* node = new_node(stack->last, NULL, value);
		stack->last->next = node;
		stack->last = node;
	}
	stack->size++;
}

char* pop(struct Stack* stack)
{
	struct Node* node = NULL;
	if (stack->size == 0)
	{
		return NULL;
	}
	if (stack->size == 1)
	{
		node = stack->last;
		stack->first = NULL;
		stack->last = NULL;
		stack->size--;
		return node;
	}
	node = stack->last;
	stack->last = node->prev;
	stack->last->next = NULL;
	stack->size--;
	return node;
}

char* poll(struct Stack* stack)
{
	struct Node* node = NULL;
	if (stack->size == 0)
	{
		return NULL;
	}
	if (stack->size == 1)
	{
		node = stack->last;
		stack->first = NULL;
		stack->last = NULL;
		stack->size--;
		return node;
	}
	node = stack->first;
	stack->first = node->next;
	stack->first->prev = NULL;
	stack->size--;
	return node;
}

void del_stack(struct Stack* stack)
{
	if (stack->size == 0)
	{
		free(stack);
		return;
	}
	struct Node* node = stack->first;
	struct Node* prev = NULL;
	while ((node = (prev = node)->next) != NULL)
	{
		free_node(prev);
	}
	free_node(prev);
	free(stack);
}

void stack_prepare(struct Stack* stack)
{
	stack->size = 0;
	stack->first = NULL;
	stack->last = NULL;
}

struct Node* new_node(struct Node* prev, struct Node* next, char* value)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	check_malloc_memory(node);
	node->prev = prev;
	node->next = next;
	node->value = value;
	return node;
}

void free_node(struct Node* node)
{
	free(node->value);
	free(node);
}