
//	Created by ���� on 2020/02/01.
//  Copyright  2020 ����. All rights reserved.

#include "utils.h"
/*
	����ڴ��Ƿ�����ɹ�
*/
void check_malloc_memory(void* point)
{
	if (point == NULL)
	{
		printf("�ڴ�����ʧ��!\n");
		exit(-2);
	}
}