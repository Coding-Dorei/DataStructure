#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

typedef struct node {//연결리스트를 위한 구조체 node
	int elem;
	struct node* next;//헤더가 없는 단일 연결리스트로 큐를 구현
}node;

node* getNode() {//getNode 함수
	node* p = (node*)calloc(1, sizeof(node));
	return p;
}

int isEmpty(node* popQ_front, node* pushQ_front) {//스택이 비어있는지 확인하는 함수
	int E = 0;
	if (popQ_front == NULL && pushQ_front == NULL) E = 1;//pushQ와 popQ가 둘다 비어있으면 스택도 비어있음
	else E = 0;
	return E;//결과를 반환
}

void enqueue(node ** Q_front,node** Q_rear, int elem, int* N) {//큐에 원소를 삽입하는 함수
	if (*Q_rear == NULL) {//내부적으로는 큐의 rear에 원소를 삽입하지만 외부적으론 스택에 push
		*Q_front = getNode();//큐가 비어있을 경우
		(*Q_front)->elem = elem;
		(*Q_rear) = (*Q_front);
	}
	else {
		node* p = getNode();
		p->elem = elem;
		(*Q_rear)->next = p;
		(*Q_rear) = p;
	}
	(*N)++;//스택의 원소 갯수 +1
}

int dequeue(node** Q_front, node** Q_rear, int*N) {//큐의 front로 부터 원소를 삭제하고 이를 반환하는 함수
	node* tmp = *Q_front;
	int elem = tmp->elem;
	if (*Q_front == *Q_rear) {//큐에 원소가 하나 밖에 없으면
		free(tmp);
		*Q_front = *Q_rear = NULL;//front와 rear 둘 다 NULL
	}
	else {
		*Q_front = (*Q_front)->next;
		free(tmp);
	}
	(*N)--;//원소 수 1감소
	return elem;//삭제한 노드의 원소를 반환
}

int pop(node** pushQ_front, node** pushQ_rear, node **popQ_front, node** popQ_rear, int*N) {//스택의 top의 원소를 삭제하고 반환하는 함수
	while (*pushQ_front != *pushQ_rear) {//push(enqueue)한 큐에 원소가 하나만 남을때까지
		enqueue(popQ_front,popQ_rear,dequeue(pushQ_front, pushQ_rear, N),N);//pushQ의 원소를 dequeue해서 popQ에 enqueue
	}
	int elem =  dequeue(pushQ_front, pushQ_rear, N);//pushQ의 마지막 원소를 elem에 저장하고 dequeue에서 메모리 해제
	if (isEmpty(*pushQ_front, *popQ_front)) return elem;
	while (*popQ_front != *popQ_rear) {//popQ의 원소를 다시 pushQ로 돌려놓음
		enqueue(pushQ_front, pushQ_rear, dequeue(popQ_front, popQ_rear, N), N);//popQ에서 dequeue하고 (N--) pushQ에 enqueue해서 (N++) 스택의 원소 갯수는 변하지 않음
	}
	enqueue(pushQ_front, pushQ_rear, dequeue(popQ_front, popQ_rear, N), N);
	return elem;//원소를 반환
}

int top(node** pushQ_front, node** pushQ_rear, node** popQ_front, node** popQ_rear, int* N) {//스택의 top에 위치한 원소를 삭제하지 않고 반환하는 함수
	while (*pushQ_front != *pushQ_rear) {
		enqueue(popQ_front, popQ_rear, dequeue(pushQ_front, pushQ_rear, N), N);//pushQ에 원소가 하나만 남을때 까지 dequeue해서 popQ에 enqueue
	}
	int elem = (*pushQ_front)->elem;
	enqueue(popQ_front, popQ_rear, dequeue(pushQ_front, pushQ_rear, N), N);//원상복귀
	while (*popQ_front != *popQ_rear) {
		enqueue(pushQ_front, pushQ_rear, dequeue(popQ_front, popQ_rear, N), N);
	}
	enqueue(pushQ_front, pushQ_rear, dequeue(popQ_front, popQ_rear, N), N);
	return elem;//top에 위치한 원소를 반환
}

void pushMillion(node**pushQ_front,node**pushQ_rear,int *N) {//push를 백만번 진행하는 함수
	for (int i = 0; i < 1000000; i++) {
		srand(time(NULL));
		enqueue(pushQ_front, pushQ_rear, rand()%90 + 10, N);//10~99범위의 난수를 생성하여 pushQ에 enqueue(push)
	}
}

void clear(node* Q) {//메모리를 해제하는 함수
	node* p = Q, * tmp = NULL;
	while (p != NULL) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

int main() {
	LARGE_INTEGER start = { 0, }, end = { 0, }, diff = { 0, }, ticks = { 0, };//실행시간 측정을 위한 변수
	QueryPerformanceFrequency(&ticks);
	node* popQ_front = NULL, * popQ_rear = NULL, * pushQ_front = NULL, * pushQ_rear = NULL;//pushQ와 popQ의 front와 rear를 저장할 포인터변수
	int N = 0, elem = 0, E = 0;//스택의 원소 갯수를 저장할 N, 반환된 원소와 입력받은 정수를 저장할 elem, isEmpty의 반환값을 저장할 E
	char mode = 0, tmp = 0;//실행할 작업을 저장할 mode와 임시변수 tmp
	while (1) {
		scanf("%c", &mode);
		diff.QuadPart = 0;
		if (mode == 'q') break;//q가 입력되면 프로그램 종료
		else if (mode == 'p') {//p가 입력되면
			while (1) {
				scanf("%d%c", &elem, &tmp);//정수를 입력받고
				QueryPerformanceCounter(&start);
				enqueue(&pushQ_front, &pushQ_rear, elem, &N);//입력받은 정수를 스택에 push
				QueryPerformanceCounter(&end);
				diff.QuadPart += end.QuadPart - start.QuadPart;//실행시간 측정
				//push(stack, elem, &N);
				if (tmp == '\n') break;//개행을 하면 입력을 종료하고 다음 작업을 입력받음
			}
		}
		else if (mode == 'o') {//o가 입력되면 pop
			getchar();
			E = isEmpty(popQ_front, pushQ_front);//스택이 비어있는지 확인
			QueryPerformanceCounter(&start);
			if (E) {
				printf("Empty Stack Exception!! ");//스택이 비어있으면 EmptyStackException발령
			}
			else {
				elem = pop(&pushQ_front, &pushQ_rear, &popQ_front, &popQ_rear, &N);//스택에서 pop한 원소를 elem에 저장
				printf("%d ", elem);//출력
			}
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
		}
		else if (mode == 'P') {
			getchar();
			QueryPerformanceCounter(&start);
			pushMillion(&pushQ_front, &pushQ_rear, &N);//push를 1000000번 진행
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
		}
		else if (mode == 'S') {
			getchar();
			QueryPerformanceCounter(&start);
			E = isEmpty(popQ_front, pushQ_front);//스택이 비어있는지 확인
			QueryPerformanceCounter(&end);
			if (E) {
				printf("Empty ");
			}//결과를 출력
			else printf("Nonempty ");
			diff.QuadPart = end.QuadPart - start.QuadPart;
		}
		else if (mode == 't') {
			getchar();
			E = isEmpty(popQ_front, pushQ_front);
			QueryPerformanceCounter(&start);
			if (E) {
				printf("Empty Stack Exception!! ");//스택이 비어있으면 EmptyStackException발령
			}
			else {
				elem = top(&pushQ_front, &pushQ_rear, &popQ_front, &popQ_rear, &N);//스택의 top에 위치한 원소를
				printf("%d ", elem);//출력
			}
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
		}
		E = 0;
		printf("(%d), cputime = %.10lf\n", N, ((double)diff.QuadPart / (double)ticks.QuadPart) * 1000);//스택에 저장된 원소의 숫자와 측정한 실행시간을 출력
	}
	clear(popQ_front);//사용이 끝난 메모리의 할당을 해제
	clear(pushQ_front);
}