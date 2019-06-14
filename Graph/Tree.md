# 트리

+ 그래프의 종류로 상하 관계를 표현할 때 자주 사용하는 자료구조.
+ 그래프 탐색 알고리즘 중에서 DFS를 사용하여 각노드를 탐색한다. (재귀랄)
+ 트리의 끝부분을 노드라고 하고, 노드를 이어주는 선을 간선 또는 엣지라고 한다.
+ 트리의 최상위 노드를 루트 노드라고 칭하며, 하위 노드는 자식 노드라고 불린다.
+ 전위, 중위, 후위 탐색 방법이 있으며, 실제 노드의 값을 참조하는 위치에 따라 구현되므로 간결하다.
+ 트리의 종류 중에서, 자식 노드의 갯수가 항상 2개인 트리를 이진트리라고 하며, 모든 부모 노드가 자식 노드를 풀로 가지고 있는 트리를 완전 이진 트리라고 한다.

## 1. 트리 생성

+ 재귀함수를 이용하여 노드가 NULL인 놈이 나올때까지 파고든다.
+ NULL인 노드가 나오면 노드를 동적생성하고, 생성된 노드를 리턴한다. (ㅄ같이 리턴 안했다가 삽질함.)
+ 상위 노드의 값을 기준으로 크면 오른쪽, 작으면 왼쪽으로 깊이 파고 들어간다.

<pre>
    <code>
        Node* insertNode (Node * prevNode, int newValue) {
            if (prevNode == NULL) {
                prevNode = malloc(sizeof(Node));
                prevNode->left = NULL;
                prevNode->right = NULL;
                prevNode->value = newValue;
                return prevNode;
            }
            
            if (prevNode->value > newValue) {
                prevNode->left = insertNode(prevNode->left, newValue);
            } else {
                prevNode->right = insertNode(prevNode->right, newValue);
            }
            
            return prevNode; // ㅅㅂ 꼭 리턴하자.
        }
    </code>
</pre>

## 2. 트리 탐색

+ 값을 참조하는 위치에 따라 전위, 중위, 후위 탐색으로 구분된다.

<pre>
    <code>
        void searchPrevNode (Node * root) {
            if (root == NULL) {
                return;
            }
            
            printf("전위 : %d\n", root->value);
            searchPrevNode(root->left);
            searchPrevNode(root->right);
        }

        void searchMidNode (Node * root) {
            if (root == NULL) {
                return;
            }
            
            searchMidNode(root->left);
            printf("중위 : %d\n", root->value);
            searchMidNode(root->right);
        }

        void searchAfterNode (Node * root) {
            if (root == NULL) {
                return;
            }
            
            searchAfterNode(root->left);
            searchAfterNode(root->right);
            printf("후위 : %d\n", root->value);
        }
    </code>
</pre>

## 3. 트리 삭제

+ 최하단 노드먼저 제거해야 하므로 후위 순회로 메모리를 해제한다.

<pre>
    <code>
        void destroyTree (Node * targetNode) {
            if (targetNode == NULL) {
                return;
            }
            
            destroyTree(targetNode->left);
            destroyTree(targetNode->right);
            free(targetNode);
        }
    </code>
</pre>

## 4. 트리 전체 코드
<pre>
    <code>
        #include <stdio.h>
        #include <stdlib.h>

        typedef struct TreeNode {
            int value;
            struct TreeNode * left;
            struct TreeNode * right;
        } Node;

        Node* insertNode (Node * prevNode, int newValue) {
            if (prevNode == NULL) {
                prevNode = malloc(sizeof(Node));
                prevNode->left = NULL;
                prevNode->right = NULL;
                prevNode->value = newValue;
                return prevNode;
            }
            
            if (prevNode->value > newValue) {
                prevNode->left = insertNode(prevNode->left, newValue);
            } else {
                prevNode->right = insertNode(prevNode->right, newValue);
            }
            
            return prevNode;
        }

        void destroyTree (Node * targetNode) {
            if (targetNode == NULL) {
                return;
            }
            
            destroyTree(targetNode->left);
            destroyTree(targetNode->right);
            printf("노드 파괴 : %d\n", targetNode->value);
            free(targetNode);
        }

        void searchPrevNode (Node * root) {
            if (root == NULL) {
                return;
            }
            
            printf("전위 : %d\n", root->value);
            searchPrevNode(root->left);
            searchPrevNode(root->right);
        }

        void searchMidNode (Node * root) {
            if (root == NULL) {
                return;
            }
            
            searchMidNode(root->left);
            printf("중위 : %d\n", root->value);
            searchMidNode(root->right);
        }

        void searchAfterNode (Node * root) {
            if (root == NULL) {
                return;
            }
            
            searchAfterNode(root->left);
            searchAfterNode(root->right);
            printf("후위 : %d\n", root->value);
        }

        int main(void) {
            Node * root = malloc(sizeof(Node));
            root->left = NULL;
            root->right = NULL;
            root->value = 5;
            
            insertNode(root, 3);
            insertNode(root, 2);
            insertNode(root, 10);
            insertNode(root, 4);
            insertNode(root, 7);
            insertNode(root, 8);
            insertNode(root, 9);
            insertNode(root, 6);
            
            searchPrevNode(root);
            searchMidNode(&root);
            searchAfterNode(&root);
            
            destroyTree(root);
            
            return 0;
        }
    </code>
</pre>