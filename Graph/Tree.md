# 트리



## 1. 트리 생성
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
            
            return prevNode;
        }
    </code>
</pre>

## 2. 트리 탐색
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