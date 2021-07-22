//10828 - Ω∫≈√ stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10001

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		printf("overflow");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s))
		return -1;
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		return -1;
	}
	else
		return s->data[s->top];
}

int main(void) {
	StackType stack;
	int n, item = 0;
	char s[10];

	init(&stack);

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%s",s,sizeof(s));
		
		if (strcmp(s, "push") == 0) {
			scanf_s("%d", &item);
			push(&stack, item);
		}
		else if (strcmp(s, "pop") == 0) {
			printf("%d\n", pop(&stack));
		}
		else if (strcmp(s, "top") == 0)
			printf("%d\n", peek(&stack));
		else if (strcmp(s, "size") == 0)
			printf("%d\n", stack.top + 1);
		else if (strcmp(s, "empty") == 0) {
			if (is_empty(&stack))
				printf("1\n");
			else
				printf("0\n");
		}
	}

	return 0;
}