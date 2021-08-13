//heap insert/delete
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 20

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	while (i != 1 && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; //자리에 item 넣기
}

element delete_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--]; //제일 말단 노드
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if(child < h->heap_size && (h->heap[child].key < h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key) break; //말단 노드가 child보다 크면 그 위에 있어야 함
		//level down
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item; //어차피 반환하는 건 루트 노드 
}
int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;
	heap = create(); // 히프 생성
	init(heap); // 초기화
	// 삽입
	insert(heap, e1);
	insert(heap, e2);
	insert(heap, e3);
	// 삭제
	e4 = delete_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_heap(heap);
	printf("< %d > \n", e6.key);
	free(heap);
	return 0;
}
