/******************************************************************************
  Copyright (C), 2001-2012, Huawei Tech. Co., Ltd.
 ******************************************************************************  File Name     :  Version       :  Author        :  Created       : 2010/9/1  Last Modified :  Description   :  Function List :
  History       :  1.Date        : 2010/9/1    Author      :    Modification: Created file
******************************************************************************/#include <cppunit/config/SourcePrefix.h>#include "CExampleTest.h"#include <stdlib.h>#include <string.h>
extern int Calculate(const int iNumerator, const int iDenominator ,char *pucOut);
// 注册测试套到CppUnitCPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );
// 测试用例实现示例
// SetUp: 在每个用例前执行一次void CExampleTest::setUp(){
}
// tearDown: 在每个用例后执行一次void CExampleTest::tearDown(){
}/****************************************************************************** *                         被函数指针调用的一些函数******************************************************************************/void free_object_stack(void *object){    free(object);}
boolean match_stack(void* data){    char *temp;    temp=(char*)data;    if (0 == strcmp(temp, "123"))        return true;
    return false;}
/// 列表函数测试/****************************************************************************** *                                               stack_create******************************************************************************/void CExampleTest::TestCase01(){ Stack *stack = stack_create();    CPPUNIT_ASSERT(NULL != stack);
    stack_distory(stack, free_object_stack);}
/****************************************************************************** *                                               stack_destory******************************************************************************//// 常规
void CExampleTest::TestCase02(){    Stack *stack = stack_create();    CPPUNIT_ASSERT(NULL != stack);
    char *data = (char *)malloc(4);    memcpy(data, "123", 4);
    stack_push(stack, data);
    stack_distory(stack, free_object_stack);    CPPUNIT_ASSERT( 0 != strcmp("123", data));}/// 队列中有元素值相等void CExampleTest::TestCase03(){    Stack *stack = stack_create();    CPPUNIT_ASSERT(NULL != stack);
    char *data1 = (char *)malloc(4);    memcpy(data1, "123", 4);    char *data2 = (char *)malloc(4);    memcpy(data2, "456", 4);
    stack_push(stack, data1);    stack_push(stack, data2);    stack_push(stack, data1);    stack_push(stack, data2);
    stack_distory(stack, free_object_stack);    CPPUNIT_ASSERT(0 != strcmp("123", data1));    CPPUNIT_ASSERT(0 != strcmp("456", data2));}
/// 函数指针为NULLvoid CExampleTest::TestCase04(){    Stack *stack = stack_create();    CPPUNIT_ASSERT(NULL != stack);
    char *data1 = (char *)malloc(4);    memcpy(data1, "123", 4);    char *data2 = (char *)malloc(4);    memcpy(data2, "456", 4);
    stack_push(stack, data1);    stack_push(stack, data2);    stack_push(stack, data1);    stack_push(stack, data2);
    stack_distory(stack, NULL);    CPPUNIT_ASSERT(0 == strcmp("123", data1));    CPPUNIT_ASSERT(0 == strcmp("456", data2));}
/// 传进去的stack为NULLvoid CExampleTest::TestCase05(){    Stack *stack = NULL;    stack_distory(stack, free_object_stack);}
/****************************************************************************** *                                               stack_clear******************************************************************************//// 常规void CExampleTest::TestCase06(){    Stack *stack = stack_create();    CPPUNIT_ASSERT(NULL != stack);
    char *data = (char *)malloc(4);    memcpy(data, "123", 4);
    stack_push(stack, data);
    stack_clear(stack);    CPPUNIT_ASSERT(NULL != stack);
    CPPUNIT_ASSERT(0 == strcmp("123", data));
    stack_distory(stack, free_object_stack);}
/****************************************************************************** *                                               stack_is_empty******************************************************************************//// 常规void CExampleTest::TestCase09(){    Stack *stack = stack_create();    CPPUNIT_ASSERT(NULL != stack);    CPPUNIT_ASSERT(true == stack_empty(stack));
    char *data = (char *)malloc(4);    memcpy(data, "123", 4);
    stack_push(stack, data);    CPPUNIT_ASSERT(false == stack_empty(stack));
    stack_distory(stack, free_object_stack);}

/****************************************************************************** *                                               stack_push******************************************************************************//// 常规void CExampleTest::TestCase11(){    Stack *stack = stack_create(); CPPUNIT_ASSERT(NULL != stack);
 char *data1 = (char *)malloc(4); memcpy(data1, "123", 4); char *data2 = (char *)malloc(4); memcpy(data2, "456", 4); char *data3 = (char *)malloc(4); memcpy(data3, "789", 4); char *test_data1, *test_data2, *test_data3;
 stack_push(stack, data1); stack_push(stack, data2); stack_push(stack, data3);
 test_data3 = (char *)stack_pop(stack); test_data2 = (char *)stack_pop(stack); test_data1 = (char *)stack_pop(stack);
 CPPUNIT_ASSERT(0 == strcmp(data1,test_data1)); CPPUNIT_ASSERT(0 == strcmp(data2,test_data2)); CPPUNIT_ASSERT(0 == strcmp(data3,test_data3));
 stack_distory(stack,free_object_stack);}

/****************************************************************************** *                                               stack_pop******************************************************************************//// 常规void CExampleTest::TestCase14(){    Stack *stack = stack_create(); CPPUNIT_ASSERT(NULL != stack);
 char *data1 = (char *)malloc(4); memcpy(data1, "123", 4); char *data2 = (char *)malloc(4); memcpy(data2, "456", 4); char *data3 = (char *)malloc(4); memcpy(data3, "789", 4); char *test_data1, *test_data2, *test_data3;
 stack_push(stack, data1); stack_push(stack, data2); stack_push(stack, data3);
 test_data3 = (char *)stack_pop(stack); test_data2 = (char *)stack_pop(stack); test_data1 = (char *)stack_pop(stack);
 CPPUNIT_ASSERT(0 == strcmp(data1,test_data1)); CPPUNIT_ASSERT(0 == strcmp(data2,test_data2)); CPPUNIT_ASSERT(0 == strcmp(data3,test_data3));
 stack_distory(stack,free_object_stack);}

/****************************************************************************** *                                               stack_peek******************************************************************************///参数为空的情况void CExampleTest::TestCase17(){   Stack *stack=NULL;   void *get_adr=stack_peek(stack);   CPPUNIT_ASSERT(NULL == get_adr);   stack_distory(stack,free_object_stack);}
/****************************************************************************** *                                               stack_search******************************************************************************/
///常规void CExampleTest::TestCase20(){    Stack *stack=stack_create();    char *data0 = (char *)malloc(4);    char *data1 = (char *)malloc(4);    int data1_dis;    memcpy(data0, "123", 4);    memcpy(data1, "456", 4);    stack_push(stack,data0);    stack_push(stack,data1);    data1_dis=stack_search(stack,NULL,match_stack);    CPPUNIT_ASSERT(data1_dis == 2);
    stack_distory(stack,free_object_stack);}
