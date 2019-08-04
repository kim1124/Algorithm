#include <stdio.h>
#include <stdlib.h>

// 트리 저장용
char Tree[26][3];

// 노드 구성
typedef struct Node {
	char value;
	struct Node * left;
	struct Node * right;
} Node;

// Root Node
Node* root;

// 트리 생성
Node* createNode (Node* Parent, char value, int dir) {
	// 노드 변수 선언
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	// 노드 변수 초기화
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->value = value;
	
	// 부모 노드가 있으면
	if (Parent != NULL) {
		if (dir == 1) {
			Parent->left = newNode;
		} else if (dir == 2) {
			Parent->right = newNode;
		}
		
		return NULL;
	}
	
	return newNode;
}

// 트리 순회
void searchPrevTree(Node* Parent) {
	printf("%d", Parent->value);
	searchPrevTree(Parent->left);
	searchPrevTree(Parent->right);
}

// 트리 소멸

// 부모 노드 찾기
Node* searchParentNode (Node* Parent, char value) {
	// 부모 노드와 값 비교
	if (Parent->value == value) {
		return Parent;
	}
	
	// left 비교
	if (Parent->left != NULL) {
		return searchParentNode(Parent->left, value);
	}
	
	// right 비교
	if (Parent->right != NULL) {
		return searchParentNode(Parent->right, value);
	}
}

// 메모리 소멸
Node* freeTree (Node* Parent) {
	freeTree(Parent->left);
	freeTree(Parent->right);
	
	free(Parent);
}

int main(void) {
	// 노드 갯수
	int nodeCount = 0;
	
	// 입력값 받기
	scanf("%d", &nodeCount);
	
	// 맵 입력
	for (int y = 0; y < nodeCount; y++) {
		for (int x = 0; x < 3; x++) {
			scanf("%c", &Tree[y][x]);
			printf("입력 받은 문자 : %d %d : %c\n", x, y, Tree[y][x]);
		}
	}
	
	// 루트 노드 생성
	root = (Node*)malloc(sizeof(Node));

	// // 트리 생성 시작
	// for (int i = 0; i < nodeCount; i++) {
	// 	// 부모 노드 변수
	// 	Node* Parent = NULL;
		
	// 	// i가 0이라면 루트노드 생성
	// 	if (i == 0) {
	// 		// 루트노드 생성
	// 		Parent = createNode(NULL, Tree[i][0], 0);
			
	// 		// 부모 노드로 등록
	// 		root = Parent;
			
	// 		// 다음 반복 진행
	// 		continue;
	// 	} else {
	// 		// 부모 노드 찾기
	// 		Parent = searchParentNode(root, Tree[i][0]);
	// 	}
		
	// 	// 왼쪽노드 생성
	// 	if (Tree[i][1] != '.') {
	// 		createNode(Parent, Tree[i][1], 1);
	// 	}
		
	// 	// 오른쪽 노드 생성
	// 	if (Tree[i][2] != '.') {
	// 		createNode(Parent, Tree[i][2], 2);
	// 	}
	// }
	
	// // 전위 순회
	// searchPrevTree(root);
	
	// 메모리 소멸
	// freeTree(root);

	return 0;
}
