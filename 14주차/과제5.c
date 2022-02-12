#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	char* str;
	struct node* yes, * no;
}node;

node* getNode() {
	node* p = (node*)calloc(1, sizeof(node));
	return p;
}

int isInternal(node* v) {//내부노드인지 확인하는 함수
	if (v->yes == NULL && v->no == NULL) return 0;//노드 v에게 자식이 없으면 0을 반환
	return 1;
}

node* makeExternalNode() {//외부노드를 생성하는 함수
	node* v = getNode();
	char str[100] = { 0, };
	printf("Enter decision:");
	gets(str);//결정을 입력받음
	v->str = (char*)calloc(strlen(str) + 1, sizeof(char));
	strcpy(v->str, str);
	return v;
}

node* makeInternalNode() {//내부노드를 생성하는 함수
	node* v = getNode();
	char str[100] = { 0, }, answer = 0;//질문 문장을 입력받을 str과 Y나 N으로 예, 아니오를 표현할 answer
	printf("Enter question:");
	gets(str);//질문을 입력받음
	v->str = (char*)calloc(strlen(str) + 1, sizeof(char));
	strcpy(v->str, str);
	printf("Question if yes to %s?(Y/N)\n>>>", str);//질문에 '예'로 답할 경우에  다음 질문이 있는지 확인 
	scanf("%c", &answer);
	getchar();
	if (answer == 'Y') {//있다면
		v->yes = makeInternalNode();//내부노드생성함수를 호출
	}
	else if (answer == 'N') {//없다면
		v->yes = makeExternalNode();//외부노드생성함수를 호출
	}
	printf("Question if no to %s?(Y/N)\n> >>", str);//질문에 '아니오'로 답할 경우에  다음 질문이 있는지 확인 
	scanf("%c", &answer);
	getchar();
	if (answer == 'Y') {//있다면
		v->no = makeInternalNode();//내부노드생성함수를 호출
	}
	else if (answer == 'N') {//없다면
		v->no = makeExternalNode();//외부노드생성함수를 호출
	}
	return v;
}

node* buildDecisionTree() {
	printf("<<<결정트리를 구축합니다>>>\n");
	return makeInternalNode();
}

void processNode(node* v) {
	puts(v->str);
	char answer = 0;//Y나 N으로 예 아니오를 표현할 answer
	if (isInternal(v)) {//내부노드이면
		scanf("%c", &answer);//대답을 입력받고
		getchar();
		if (answer == 'Y') {//Y면 yes로
			processNode(v->yes);
		}
		else if (answer == 'N') {//N이면  no로 진행
			processNode(v->no);
		}
	}
}

void runDecisionTree(node*v) {
	printf("<<<질문에 Y또는 N으로 답해주세요>>>\n");
	processNode(v);
}

void free_tree(node* v) {
	if (v != NULL) {
		free_tree(v->no);
		free_tree(v->yes);
		free(v->str);
		free(v);
	}
	return;
}

int main() {
	node* root = NULL;
	root = buildDecisionTree();//결정트리생성함수를 호출
	for (int i = 0; i < 3; i++) {
		runDecisionTree(root);//결정트리를 구동하는 함수를 세 번 호출
	}
	free_tree(root);//사용이 끝난 메모리를 해제
}