#include <stdio.h>
#include <stdlib.h>

typedef int Type;

typedef struct Stack {
	Type* _array;
	size_t _size;
	size_t _capacity;
}Stack;

void StackInit(Stack* sk,size_t n) {
	sk->_array = (Type*)malloc(sizeof(Type)*n);
	sk->_capacity = n;
	sk->_size = 0;
}
//尾插
void StackPush(Stack* sk, Type data) {
	if (sk->_size == sk->_capacity) { //考虑扩容
		sk->_capacity *= 2;
		sk->_array = (Type*)realloc(sk->_array, sk->_capacity * sizeof(Type));
	}
	sk->_array[sk->_size++] = data;
}
//尾删
void StackPop(Stack* sk) {
	if (sk->_size)
		sk->_size--;
}
//获取栈顶元素
Type StackTop(Stack* sk) {
	return sk->_array[sk->_size-1];
}
//获取栈顶元素个数
size_t StackSize(Stack* sk) {
	return sk->_size;
}
//判断栈是否为空
int StackEmpty(Stack* sk) {
	if (sk->_size == 0) {
		return 0;
	}
	return 1;
}
//栈的销毁
void StackDestory(Stack* sk) {
	free(sk->_array);
	sk->_array = NULL;
	sk->_size = sk->_capacity = 0;
}
void test() {
	Stack sk;
	StackInit(&sk, 10);
	StackPush(&sk, 1);
	StackPush(&sk, 2);
	StackPush(&sk, 3);
	StackPush(&sk, 4);
	StackPush(&sk, 5);
	while (StackEmpty(&sk) != 0)//取栈顶元素实现栈的遍历
	{
		printf("%d ", StackTop(&sk));
		StackPop(&sk);
	}
	printf("\n");
}
int main() {
	test();	
	system("pause");
	return 0;
}