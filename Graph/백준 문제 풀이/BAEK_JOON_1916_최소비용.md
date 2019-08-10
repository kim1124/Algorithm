# 백준 알고리즘 1916 문제

+ 다익스트라 알고리즘의 기본 문제로 

## 1. 코드

<pre>
    <code>
        #include <stdio.h>
        #define MAX 1003
        #define MAX_M 100000
        #define INFI 999999999

        // 맵 저장
        int Map[MAX][MAX];

        // 정점 가중치 저장
        int V[MAX_M][3];

        // 비용 저장
        int D[MAX];
        int Visited[MAX] = {0};

        void Dijistra(int startV, int destV, int countV) {
            // 비용 초기화
            for (int i = 1; i <= countV; i++) {
                D[i] = INFI;
            }

            D[startV] = 0;

            // 간선 갯수만큼 시작
            for (int i = 1; i <= countV; i++) {
                // 비용이 가장 낮은 정점 찾기
                int Min = INFI;
                for (int j = 1; j <= countV; j++) {
                    // 방문하지 않은 정점 중 비용이 가장 낮은 정점 선택
                    if (Visited[j] == 0 && Min > D[j]) {
                        Min = D[j];
                        startV = j;
                    }
                }

                // 방문 표시
                Visited[startV] = 1;

                // 인접 정점 체크
                for (int k = 1; k <= countV; k++) {
                    // 방문하지 않았고, 이동 가능하며, 간선완화로 가장 가까운 정점
                    if (Map[startV][k] != INFI && D[k] > D[startV] + Map[startV][k]) {
                        // 최소비용 저장
                        D[k] = D[startV] + Map[startV][k];
                    }
                }
            }

            printf("%d\n", D[destV]);
        }

        int main() {
            // 정점, 간선 입력
            int N = 5;
            int M = 8;
            int S = 1;
            int F = 5;

            // Map 초기화
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++) {
                    Map[i][j] = INFI;
                }
            }

            scanf("%d", &N);
            scanf("%d", &M);

            for (int i = 0; i < M; i++) {
                int source;
                int dest;
                int weight;

                scanf("%d %d %d", &source, &dest, &weight);

                if (Map[source][dest] > weight || Map[source][dest] == 0)
                    Map[source][dest] = weight;
            }

            scanf("%d %d", &S, &F);

            // 최소비용 시작
            Dijistra(S, F, N);

            return 0;
        }
    </code>
</pre>

## 2. 코드 분석

+ 다익스트라 기본 문제. 최소값을 초기화 하는 부분과 간선 완화 부분을 집중적으로 보자.

## 3. 출처

+ 백준 알고리즘 (https://www.acmicpc.net)