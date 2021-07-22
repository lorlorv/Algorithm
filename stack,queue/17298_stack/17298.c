//17298 - ¿ÀÅ«¼ö [stack]
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 1000001

int list[MAX_STACK_SIZE];
int newList[MAX_STACK_SIZE];

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
	if (is_empty(s)) {
		printf("nothing\n");
		exit(1);
	}

	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		printf("nothing");
		exit(1);
	}
	else
		return s->data[s->top];
}
void check(int list[], int n){
	StackType s;
	int index = 0;
	int rst = 0;

	while (index < n) {
		for (int i = index + 1; i < n; i++) {
			if (list[i] > index) {
				push(&s, list[i]);
			}
			printf("%d", s.data[s.top]);
		}
		if (is_empty(&s))
			newList[index] = -1;
		else {
			while (!is_empty(&s)) {
				rst = pop(&s);
			}
			newList[index] = rst;
		}
		index++;
	}
}

int main(void) {
	int n;

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &list[i]);
	}
	check(list, n);

	for (int i = 0; i < n; i++) {
		printf("%d\t", newList[i]);
	}

}