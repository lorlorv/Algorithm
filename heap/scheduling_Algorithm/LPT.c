//LPT
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 20

typedef struct {
	int id;
	int available;
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
//����� ����ð��� �ּ� ������ �ִ´�.
void insert(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	while (i != 1 && (item.available < h->heap[i / 2].available)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; //�ڸ��� item �ֱ�
}
//�ּ� �������� ��踦 ������.
element delete_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--]; //���� ���� ���
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if (child < h->heap_size && (h->heap[child].available > h->heap[child + 1].available))
			child++;
		if (temp.available < h->heap[child].available) break; //���� ��尡 child���� ������ �� ���� �־�� ��
		//level down
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item; //������ ��ȯ�ϴ� �� ��Ʈ ��� 
}
#define JOBS 7
#define MACHINES 3
int main(void)
{
	int jobs[JOBS] = { 8, 7, 6, 5, 3, 2, 1 }; // �۾��� ���ĵǾ� �ִٰ� ����
	element m = { 0, 0 };
	HeapType* h;
	h = create();
	init(h);

	//���⼭ available���� ��谡 ����ϰ� �Ǵ� �ð�
	for (int i = 0; i < MACHINES; i++) {
		m.id = i + 1;
		m.available = 0;
		insert(h, m);
	}

	// �ּ� �������� ��踦 ������ �۾��� �Ҵ��ϰ� ��밡�� �ð��� ������Ų �Ŀ�
	// �ٽ� �ּ� ������ �߰��Ѵ�.
		for (int i = 0; i < JOBS; i++) {
			m = delete_heap(h);
			printf("JOB %d�� �ð�=%d���� �ð�=%d���� ��� %d���� �Ҵ��Ѵ�. \n",i, m.available, m.available + jobs[i] - 1, m.id);
			m.available += jobs[i];
			insert_max_heap(h, m);
		}
	return 0;
}