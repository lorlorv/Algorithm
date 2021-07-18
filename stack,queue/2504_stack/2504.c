#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
int sum = 0;
typedef char element;
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

int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in); //문자열의 길이
	int tmp = 1;

	init(&s);

	for (i = 0; i < n; i++) {
		ch = in[i]; //ch == 다음문자
		switch (ch) {
		case '(': case '[':
			push(&s, ch);
			if (ch == '(')
				tmp *= 2;
			else
				tmp *= 3;
			break;

		case ')': case ']':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				//잘못된 문자열
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']')) {
					return 0;
				}

				if (ch == ')') {
					if (in[i - 1] == '(') {
						sum += tmp;
						tmp /= 2;
					}
					else
						tmp /= 2;
				}
				else if (ch == ']') {
					if (in[i - 1] == '[') {
						sum += tmp;
						tmp /= 3;
					}
					else
						tmp /= 3;
				}
				break;
			}//else
		}//switch
	}//for


	if (!is_empty(&s)) return 0; //스택에 남아있으면 오류
	return 1;
}

int main(void) {
	char* p = (char*)malloc(sizeof(char) * 30);
	scanf("%s", p);

	if (check_matching(p) == 1)
		printf("%d", sum);
	else
		printf("0");

	free(p);
	return 0;
}

