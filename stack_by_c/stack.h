
//	Created by ���� on 2020/02/02.
//  Copyright  2020 ����. All rights reserved.

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

struct Stack
{
	int size;
	struct Node* first;
	struct Node* last;
};

struct Node
{
	struct Node* prev;
	struct Node* next;
	char* value;
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
	poll
*/
char* poll(struct Stack* stack);

/*
	del_stack
*/
void del_stack(struct Stack* stack);

/*
	Ԥ����
*/
void stack_prepare(struct Stack* stack);

/*
	����node
*/
struct Node* new_node(struct Node* prev, struct Node* next, char* value);

/*
	�ͷ�node
*/
void free_node(struct Node* node);