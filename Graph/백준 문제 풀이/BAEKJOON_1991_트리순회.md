# 백준 알고리즘 1991 문제

+ 이진 트리를 전, 중, 후위로 풀어보는 문제.

## 1. 문제

+ <https://www.acmicpc.net/problem/1991>

## 2. 코드

<pre>
  <code>
    #include <stdio.h>
    #include <stdlib.h>
    #define MAX 1000

    // 트리 저장용
    char Tree[MAX][3];

    // 노드 구성
    typedef struct Node {
      char value;
      struct Node * left;
      struct Node * right;
    } Node;

    // Root Node
    Node* root = NULL;

    // 큐
    Node* nodeList[MAX];

    // 트리 생성
    Node* createNode (char value) {
      // 노드 변수 선언
      Node* newNode = (Node*)malloc(sizeof(Node));
      
      // 노드 변수 초기화
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->value = value;
      
      return newNode;
    }

    // 노드 연결
    Node* linkTreeNode (Node* Parent, int nodeCount) {
      // 재귀 끝나는 조건
      if (Parent == NULL || nodeCount == 0) {
        return NULL;
      }
      
      // 링크 검사
      for (int i = 0; i < nodeCount; i++) {
        // 이미 등록된 적이 있다면 패스
        if (nodeList[i] == NULL) {
          continue;
        }
        
        // 같은 요소가 있는지 리스트에서 확인
        if (Parent->value == nodeList[i]->value) {
          // 같은 요소가 있으면 노드 링크
          *Parent = *nodeList[i];
          
          // NULL 초기화
          nodeList[i] = NULL;
        }
      }
      
      // 왼쪽 노드 탐색
      linkTreeNode(Parent->left, nodeCount);
      linkTreeNode(Parent->right, nodeCount);
    }

    // 트리 순회
    void searchPrevTree(Node* Parent) {
      if (Parent == NULL) {
        return;
      }
      
      printf("%c", Parent->value);
      searchPrevTree(Parent->left);
      searchPrevTree(Parent->right);
    }

    void searchMiddleTree(Node* Parent) {
      if (Parent == NULL) {
        return;
      }
      
      searchMiddleTree(Parent->left);
      printf("%c", Parent->value);
      searchMiddleTree(Parent->right);
    }

    void searchAfterTree(Node* Parent) {
      if (Parent == NULL) {
        return;
      }

      searchAfterTree(Parent->left);
      searchAfterTree(Parent->right);
      printf("%c", Parent->value);
    }

    // 부모 노드 찾기
    Node* searchParentNode (Node* Parent, char value) {
      // 부모 노드와 값 비교
      if (Parent->value == value) {
        return Parent;
      }
      
      // left 비교
      if (Parent->left != NULL) {
        searchParentNode(Parent->left, value);
      }
      
      // right 비교
      if (Parent->right != NULL) {
        searchParentNode(Parent->right, value);
      }
    }

    // 메모리 소멸
    Node* freeTree (Node* Parent) {
      if (Parent == NULL) {
        return;
      }
      
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
          scanf("%s", &Tree[y][x]);
        }
      }
      
      // 루트 노드 생성
      root = (Node*)malloc(sizeof(Node));
      
      // 루트 노드 할당
      root = createNode(Tree[0][0]);
      
      // 루트 노드 왼쪽 생성
      if (Tree[0][1] != '.') {
        root->left = createNode(Tree[0][1]);
      }
      
      // 루트 노드 오른쪽 생성
      if (Tree[0][2] != '.') {
        root->right = createNode(Tree[0][2]);
      }
      
      // 하위 노드 생성 시작
      for (int y = 1; y < nodeCount; y++) {
        Node * Parent = NULL;
        for (int x = 0; x < 3; x++) {
          // 부모 노드 생성
          if (x == 0) {
            Parent = createNode(Tree[y][x]);
            continue;
          }
          
          // 왼쪽 노드 생성
          if (x == 1 && Tree[y][x] != '.') {
            Parent->left = createNode(Tree[y][x]);
          }
          
          // 오른쪽 노드 생성
          if (x == 2 && Tree[y][x] != '.') {
            Parent->right = createNode(Tree[y][x]);
          }
        }
        
        // 큐에 저장
        nodeList[y - 1] = Parent;
      }
      
      // 전위 순회하며 큐에서 아이템 달기
      linkTreeNode(root, sizeof(nodeList) / sizeof(Node));
      
      // 전위 순회
      searchPrevTree(root);
      
      printf("\n");
      
      // 중위 순회
      searchMiddleTree(root);
      
      printf("\n");
      
      // 후위 순회
      searchAfterTree(root);
      printf("\n");
      
      // 메모리 소멸
      freeTree(root);

      return 0;
    }
  </code>
</pre>

## 3. 풀이

+ 이 문제에서 가장 어려운 부분은 하위 노드들이 순서대로 들어오는 것을 보장하지 않는다는 것이다.
+ 루트 노드의 left와 right는 수동으로 직접 연결한다. 순서가 보장되는 유일한 노드들이기 때문이다.
+ 나머지 하위 노드는 동적 생성하여 배열에 넣는다.
+ 전위 순회로 루트 노드 탐색을 시작한다. 전위 순회 몸체 내부에는 스왑 대상 노드의 값과 배열에 저장한 노드의 값을 체크하여 같을 경우, 연결하는 코드를 추가한다.
+ 대입이 완료된 노드 리스트는 NULL로 초기화한다. 동적 계획법으로 필요없는 연산을 줄이기 위해서다.
+ 배열의 크기는 문제에 제시된 맥스 값인 26보다 커야한다. 최악의 경우에는 26 * 26 - 1의 경우의 수가 나오기 때문에 넉넉하게 1000으로 설정한다.

## 4. 출처
+ 백준 알고리즘 (https://www.acmicpc.net)
