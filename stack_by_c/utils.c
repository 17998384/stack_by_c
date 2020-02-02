
//	Created by 葛振东 on 2020/02/01.
//  Copyright  2020 葛振东. All rights reserved.

#include "utils.h"
/*
	检查内存是否申请成功
*/
void check_malloc_memory(void* point)
{
	if (point == NULL)
	{
		printf("内存申请失败!\n");
		exit(-2);
	}
}