#include <stdlib.h>#include "oj.h"
/****************************************************************************** *                          全局变量/静态变量定义区******************************************************************************/
#define OK 1#define ERROR -1
typedef struct std_stack{ char* data; std_stack *next;//}std_stack;

/****************************************************************************** *                          内部结构定义区******************************************************************************///内部结构需要自行定义

/****************************************************************************** *                          函数实现区******************************************************************************//**********************************************************************功能:创建堆栈。
输入:N/A
输出:N/A     返回:创建的堆栈***********************************************************************/Stack* stack_create(){ Stack* pStack  = (Stack*)malloc(sizeof(Stack));        if (pStack == NULL)    {        return NULL;    } pStack->next = NULL; pStack->data = NULL;
    return pStack;}
/**********************************************************************功能:释放整个堆栈，包括里面的数据。注意有相同数据（同一块内存）多次入栈  时，栈中元素的释放
输入:self：待删除的堆栈  free_object：堆栈中的数据元素内存释放接口
输出:N/A     返回:N/A***********************************************************************/void stack_distory(Stack* self, void (*free_object)(void* object)){ if(self == NULL || free_object == NULL)  return; Stack* cur = self;
 while(self) {  cur = self;  self = self->next;  free_object(cur->data);  free(cur); }
 return;}
/**********************************************************************功能:清空整个堆栈，与stack_destory不同，不释放数据元素的内存空间。
输入:self：待清空的堆栈
输出:N/A     返回:N/A***********************************************************************/void stack_clear(Stack* self){ if(self == NULL || self->base == NULL)  return;
 self->top = self->base; self->size = 0;  return;}
/**********************************************************************功能:把项压入堆栈顶部。
输入:self：堆栈  data：压入堆栈的数据
输出:N/A     返回:N/A***********************************************************************/void stack_push(Stack* self, void* data){ if(self == NULL || self->base == NULL || data == NULL)  return;  if(self->size > STACK_MAX_SIZE)  return;
 char* pdata = reinterpret_cast <char*>(data);  *(self->top) = *pdata; self->top++; self->size++;
 return;}
/**********************************************************************功能:移除堆栈顶部的对象，并返回该对象。
输入:self：堆栈
输出:N/A     返回:堆栈顶部的对象***********************************************************************/void* stack_pop(Stack* self){ if(self == NULL || self->base == NULL)  return NULL;
 if(self->size == 0)  return NULL;
 return self->top--;}
/**********************************************************************功能:查看堆栈顶部的对象，但不从堆栈中移除它。。
输入:self：堆栈
输出:N/A     返回:堆栈顶部的对象***********************************************************************/void* stack_peek(Stack* self){ if(self == NULL || self->base == NULL)  return NULL;
 if(self->size == 0)  return NULL;
 return (--self->top);}
/**********************************************************************功能:测试堆栈是否为空。
输入:self：堆栈
输出:N/A     返回:当且仅当堆栈中不含任何项时返回 true；否则返回 false。***********************************************************************/boolean stack_empty(Stack* self){ if(self == NULL || self->base == NULL)  return false;
 if(self->size == 0)  return true;}
/**********************************************************************功能:返回对象在堆栈中的位置，以 1 为基数。  如果对象是堆栈中的一个项，此方法返回距堆栈顶部最近的出现位置  到堆栈顶部的距离；堆栈中最顶部项的距离为 1。
输入:self：堆栈  data：查找的对象  match：查找的对象的匹配函数。   match的形参data：栈中的data，此时的待匹配对象在match函数中，        向本函数屏蔽待查找对象的细节。 如果match为 NULL，才需要自行匹配栈中元素和search第二个形参data的指针。 如果match和data都为空，视为异常。
输出:N/A     返回:对象到堆栈顶部的位置，以 1 为基数；返回值 -1 表示不在堆栈中或存在异常。***********************************************************************/int stack_search(Stack* self, void* data, boolean (*match)(void* data)){ if(self->base == NULL || self == NULL)  return -1;
 if(data == NULL && match == NULL)  return -1;

 return -1;}
