# 백준 알고리즘 2667 문제

+ DFS / BFS 모두 풀 수 있는 문제로, 출력값을 정렬해야한다.

## 1. 코드

<pre>
    <code>
        #include <stdio.h>
        #include <stdlib.h>
        #define MAX 25

        // 맵크기 선언
        int MAP[MAX][MAX];

        // 큐초기화
        typedef struct Queue {
            int x;
            int y;
        } Queue;

        // 버블정렬 함수
        void bubbleSort (int * array, int size) {
            int temp = 0;
            
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size - 1; j++) {
                    if (array[j] > array[j + 1]) {
                        temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
        }

        // BFS 탐색 시작 - 아파트 단지 크기를 리턴한다.
        int BFS (int startX, int startY, int limitSize) {
            // 단지 크기 측정용 변수
            int aptSize = 1;
            
            // 큐 선언 - BFS 함수가 여러번 호출되므로 큐가 알아서 초기화 하도록 한다.
            Queue Q [MAX * MAX];
            int front = -1, rear = -1;
            
            // rear 증가
            rear++;
            Q[rear].x = startX;
            Q[rear].y = startY;
            
            // 시작지점 이동 표시
            MAP[startY][startX] = 0;
            
            // 탐색 시작
            while (front < rear) {
                // 큐에서 꺼내기
                front++;
                
                int x = Q[front].x;
                int y = Q[front].y;
                
                // 왼
                if (x - 1 >= 0 && MAP[y][x - 1]) {
                    // 큐에 추가
                    rear++;
                    Q[rear].x = x - 1;
                    Q[rear].y = y;
                    
                    // MAP에 방문 표시
                    MAP[y][x - 1] = 0;
                    
                    // 단지 사이즈 증가
                    aptSize++;
                }
                
                // 오
                if (x + 1 < limitSize && MAP[y][x + 1]) {
                    // 큐에 추가
                    rear++;
                    Q[rear].x = x + 1;
                    Q[rear].y = y;
                    
                    // MAP에 방문 표시
                    MAP[y][x + 1] = 0;
                    
                    // 단지 사이즈 증가
                    aptSize++;
                }
                
                // 위
                if (y - 1 >= 0 && MAP[y - 1][x]) {
                    // 큐에 추가
                    rear++;
                    Q[rear].x = x;
                    Q[rear].y = y - 1;
                    
                    // MAP에 방문 표시
                    MAP[y - 1][x] = 0;
                    
                    // 단지 사이즈 증가
                    aptSize++;
                }
                
                // 아
                if (y + 1 < limitSize && MAP[y + 1][x]) {
                    // 큐에 추가
                    rear++;
                    Q[rear].x = x;
                    Q[rear].y = y + 1;
                    
                    // MAP에 방문 표시
                    MAP[y + 1][x] = 0;
                    
                    // 단지 사이즈 증가
                    aptSize++;
                }
            }
            
            return aptSize;
        }

        int main(void) {
            // 맵사이즈 입력
            int mapSize = 5;
            int aptCount = 0;
            
            // 맵사이즈 선택
            scanf("%d", &mapSize);
            
            // 맵에서 나올 수 있는 최대 단지수로 배열 생성
            int * aptSize = (int*)malloc(sizeof(int) * (mapSize * mapSize));
            
            // 메모리 초기화
            memset(aptSize, 0, sizeof(int) * (mapSize * mapSize));
            
            // 단지 입력
            for (int y = 0; y < mapSize; y++) {
                for (int x = 0; x < mapSize; x++) {
                    scanf("%1d", &MAP[y][x]);
                }
            }
            
            // 맵을 체크하여 BFS가 가능하면 크기 측정 시작
            for (int y = 0; y < mapSize; y++) {
                for (int x = 0; x < mapSize; x++) {
                    // 아파트 단지의 시작
                    if (MAP[y][x] == 1) {
                        // 아파트 갯수 증가
                        aptCount++;
                        
                        // 단지 사이즈 측정 시작
                        aptSize[aptCount - 1] = BFS(x, y, mapSize);
                    }
                }
            }
            
            // APT 내림차순으로 정렬
            bubbleSort(aptSize, aptCount);
            
            // 최종 출력
            printf("%d\n", aptCount);
            
            for (int i = 0; i < mapSize * mapSize; i++) {
                if (aptSize[i] == 0) {
                    break;
                }
                
                printf("%d\n", aptSize[i]);
            }
            
            // 배열 초기화
            free(aptSize);
            
            return 0;
        }
    </code>
</pre>

## 2. 코드 분석

+ 방문 기록을 MAP에다 직접 표기하였다. 따로 2차원 배열을 두어도 상관은 없으나, 메모리 낭비이다.
+ 이전에 방문한 기록이 그대로 MAP에 남아 있는 것이 좋다. 어차피 한번 방문한 단지는 들어가지 못하기 때문이다.
+ 버블 정렬을 사용하였다. 갯수가 많아봐야 25 * 25개이므로 제한시간 내에 충분히 답을 구할 수 있다. 다른 목적으로는 버블 정렬 상기용으로 써봤다.

## 3. 출처
+ 백준 알고리즘 (https://www.acmicpc.net)