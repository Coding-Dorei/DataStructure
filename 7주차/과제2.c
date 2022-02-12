#include<stdio.h>
#include<stdlib.h>

typedef struct node {//노드 구조체 정의
	struct node* next_g, * next_e;
	char e, g;
}node;

typedef struct arr {//Group, element의 배열에 쓰일 구조체
	struct node* header;
}arr;

node* getNode() {//노드 생성 함수
	node* p = (node*)calloc(1, sizeof(node));
	return p;
}

void initShare(arr* elements, arr* group, int NE, int NG) {//다중연결리스트 초기화함수
	node* p = NULL;
	for (int i = 0; i < NG; i++) {
		p = getNode();//헤더가 될 노드를 생성하고
		group[i].header = p;//연결
		p->next_e = p;//원형연결리스트이기 때문에 자기자신에게 연결
	}
	for (int i = 0; i < NE; i++) {
		p = getNode();//헤더가 될 노드를 생성하고
		elements[i].header = p;//연결
		p->next_g = p;//원형연결리스트이기 때문에 자기자신에게 연결
	}
}

void visitElement(node* p) {
	printf("%c ", p->e);//원소를 방문하는 함수
}

void visitGroup(node* p) {
	printf("%c ", p->g);//그룹을 방문하는 함수
}

int addShare(arr* elem, arr* group, char e, char g) {//노드삽입함수
	node* p = getNode(), * HG = group[g - 'A'].header, * HE = elem[e - '1'].header;//새로운 노드를 할당
	if (p == NULL) return 0;//할당에 실패하면 0을 반환
	p->e = e;//새로운 노드에 값을 입력
	p->g = g;
	p->next_e = HG->next_e;//원형 연결리스트의
	HG->next_e = p;//맨앞부분에
	p->next_g = HE->next_g;//삽입
	HE->next_g = p;
	return 1;//성공하면 1을 반환
}

int removeShare(arr* elem, arr* group, char e, char g) {//노드 삭제함수
	node* HG = group[g - 'A'].header, * HE = elem[e - '1'].header, * p = NULL, * tmp = NULL;
	p = HG;//수직방향(원소)으로 횡단하는 연결을 끊는다
	while (p->next_e->e != e) {//삭제할 원소까지 이동
		p = p->next_e;
		if (p == HG) return 0;//노드가 없으면 0을 반환
	}
	tmp = p->next_e;
	p->next_e = p->next_e->next_e;//삭제하고자하는 노드위 뒤와 앞 노드를 서로 연결
	p = HE;//수평방향(그룹)으로 횡단하는 연결을 끊는다
	while (p->next_g->g != g) {//삭제할 그룹까지 이동
		p = p->next_g;
		if (p = HE) return 0;//노드가 없으면 0을 반환
	}
	p->next_g = p->next_g->next_g;//삭제하고자하는 노드위 뒤와 앞 노드를 서로 연결
	free(tmp);//동적할당해제
	return 1;//삭제에 성공하면 1을 반환
}

void traverseShareElement(arr* group, char g) {
	node* p = group[g - 'A'].header;
	if (p->next_e == p) {//노드가 없으면
		printf("0");//0을 출력하고 종료
		return;
	}
	p = p->next_e;
	while (p->e != 0) {//헤더로 돌아오기전까지
		visitElement(p);//출력
		p = p->next_e;//이동
	}
}

void traverseShareGroup(arr* elem, char e) {
	node* p = elem[e - '1'].header;
	if (p->next_g == p) {//노드가 없으면
		printf("0");//0을 출력하고 종료
		return;
	}
	p = p->next_g;
	while (p->g != 0) {//헤더로 돌아올때까지
		visitGroup(p);//이동하면서 출력함
		p = p->next_g;
	}
}

void clear_e(arr* elem) {//원소 부분의 동적할당을 해제하는 함수
	node* p = elem->header->next_g, * tmp = NULL;
	while (p != elem->header) {
		tmp = p;
		p = p->next_g;
		free(tmp);
	}
	return;
}

void clear_g(arr* group) {//그룹부분의 동적할당을 해제하는 함수
	node* p = group->header->next_e, * tmp = NULL;
	while (p != group->header) {
		tmp = p;
		p = p->next_e;
		free(tmp);
	}
	return;
}

int main() {
	arr groups[5] = { 0, }, elems[4] = { 0, };//조건:NE = 4, NG = 5
	initShare(elems, groups, 4, 5);//주어진 조건에 따라 초기화
	char mode = 0, e = 0, g = 0;//여러 변수 선언
	int flag = 0;//add와 remove의 성공을 확인할 변수
	while (mode != 'q') {//mode가 q면 종료
		scanf("%c", &mode);//mode를 입력받음
		//printf("mode:%c\n", mode);
		switch (mode) {
		case 'q'://q이면 종료
			return 1;
			break;
		case 'a'://a면 addShare를 수행
			getchar();
			scanf("%c %c", &e, &g);
			//printf("e:%c g:%c\n", e, g);
			getchar();
			flag = addShare(elems, groups, e, g);
			if (flag) printf("OK\n");//성공시 OK를 출력
			break;
		case 'r'://r이면 removeShare를 수행
			getchar();
			scanf("%c %c", &e, &g);
			//printf("e:%c g:%c\n", e, g);
			getchar();
			flag = removeShare(elems, groups, e, g);
			if (flag) printf("OK\n");//성공시 OK를 출력
			break;
		case 'g'://g이면 traverseShareGroup을 수행
			getchar();
			scanf("%c", &e);
			//printf("e:%c\n", e);
			getchar();
			traverseShareGroup(elems, e);
			printf("\n");//끝까지 출력하고 개행
			break;
		case 'e'://e이면 traverseShareElement를 수행
			getchar();
			scanf("%c", &g);
			//printf("g:%c\n", g);
			getchar();
			traverseShareElement(groups, g);
			printf("\n");//끝까지 출력하고 개행
			break;
		}
	}
	for (int i = 0; i < 5; i++) {//동적할당 해제
		clear_g(&groups[i]);
	}
}
/*
a 1 C
a 4 A
a 4 E
a 4 D
e A
g 4
a 2 A
e A
r 4 A
g 4
e A
g 1
r 1 C
e C
g 1
g 3
q
*/