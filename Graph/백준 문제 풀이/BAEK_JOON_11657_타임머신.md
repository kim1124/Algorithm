# 백준 알고리즘 11657 문제

+ 벨만-포드 알고리즘을 사용하는 문제로, 가중치에 음수값이 들어갈 경우 해당 알고리즘을 사용한다.

## 1. 코드

<pre>
    <code>
        #include <stdio.h>
        #define MAX 501
        #define INFI_MAX 9999999

        int D[MAX * MAX];
        int Map[MAX][MAX];

        void bellmanFord(int V, int startV) {
            int vCount = V;
            
            // 거리 초기화
            for (int i = 1; i <= V; i++) {
                D[i] = INFI_MAX;
            }
            
            // 시작 거리 초기화
            D[startV] = 0;
            
            // 벨만 포드 시작
            while (vCount - 1 > 0) {
                for (int u = 1; u <= V; u++) {
                    for (int v = 1; v <= V; v++) {
                        if (u != v && Map[u][v] != INFI_MAX && D[v] > Map[u][v] + D[u]) {
                            D[v] = Map[u][v] + D[u];
                        }
                    }
                }
                
                vCount--;
            }
            
            // 사이클 확인
            for (int u = 1; u <= V; u++) {
                for (int v = 1; v <= V; v++) {
                    if (u != v && Map[u][v] != INFI_MAX && D[v] > Map[u][v] + D[u]) {
                        printf("-1\n");
                        return;
                    }
                }
            }
            
            // 최단 경로 출력
            for (int i = 2; i <= V; i++) {
                if (D[i] >= INFI_MAX) {
                    printf("%d\n", -1);
                    continue;
                }
                
                printf("%d\n", D[i]);
            }
        }

        int main(void) {
            int N = 0, M = 0, algoFlag = 0;
            
            scanf("%d %d", &N, &M);
            
            for (int s = 1; s <= N; s++) {
                for (int d = 1; d <= N; d++) {
                    Map[s][d] = INFI_MAX;
                }
            }
            
            for (int i = 0; i < M; i++) {
                int s = 0;
                int d = 0;
                int w = 0;
                
                scanf("%d %d %d", &s, &d, &w);
                
                if (s == 1) {
                    algoFlag = 1;
                }
                
                if (Map[s][d] > w) {
                    Map[s][d] = w;
                }
            }
            
            if (algoFlag) {
                bellmanFord(N, 1);
            } else {
                for (int i = 0; i < N - 1; i++) {
                    printf("-1\n");
                }
            }
            
            return 0;
        }
    </code>
</pre>

## 2. 코드 분석

+ 벨만-포드 알고리즘의 기본 문제로, 유향 그래프와 음수 가중치가 나오는 경우 이 알고리즘 외에 풀 수 있는 방법이 없다.
+ 중요 반복문 2개로 구성이 되는데, 전형적인 중첩 반복문인 폴로이드-워셜과 달리 다익스트라 알고리즘의 간선완화 방법과 매우 흡사하게 생겼다.
+ 모든 정점의 거리를 최대치로 설정하고 시작 정점을 0으로 하는 것으로 시작하는 점은 다익스트라와 흡사하다. (다익스트라가 더 개같지만 ...)
+ 특이한 점은 리사이클 판별이 가능하다는 것인데, 알고리즘이 끝난 후 다시 간선완화 체크를 하여 D[v]가 D[u] + D[u][v]보다 크면 싸이클이 있다고 판단한다.

## 3. 출처

+ 백준 알고리즘 (https://www.acmicpc.net)