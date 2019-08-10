# 백준 알고리즘 2606 문제

+ 폴로이드-워셜 문제로 나와 있었으나 DFS로 가능할 것 같아 DFS로 푼 문제.
+ 초등학교 알고리즘 문제라 그런지 DFS로 쉽게 해결되었다.

## 1. 코드

<pre>
    <code>
        #include <stdio.h>
        #define MAX 101

        int Map[MAX][MAX];
        int Virus = 0;
        int Visited[MAX * MAX];

        void DFS(int startV, int endV, int pareC) {
            // 방문 표시
            Visited[startV] = 1;
            
            // MAP 탐색 시작
            for (int v = 1; v <= endV; v++) {
                // 방문하지 않았고, 이동 가능한 정점일 경우
                if (Visited[v] == 0 && Map[startV][v] == 1) {
                    Virus++;
                    DFS(v, endV, pareC + 1);
                }
            }
        }

        int main(void) {
            int N = 0;
            int E = 0;
            
            scanf("%d", &N);
            scanf("%d", &E);
            
            for (int i = 0; i < E; i++) {
                int first = 0;
                int second = 0;
                
                scanf("%d %d", &first, &second);
                
                Map[first][second] = 1;
                Map[second][first] = 1;
            }
            
            DFS(1, N, 0);
            
            printf("%d\n", Virus);
            
            return 0;
        }
    </code>
</pre>

## 2. 코드 분석

+ DFS로 쉽게 풀 수 있는 문제. 단순하게 정점만 따라가면 되는 문제다.
+ 좌표별 이동이 아니므로 반복문 하나와 재귀의 DFS 만으로 쉽게 풀 수 있다.
+ 감염된 컴퓨터를 체크하면 더이상 체크하지 않으므로 정답을 출력하는 변수를 전역으로 빼고 체킹 될때마다 증가시키면 된다.
+ 폴로이드-워샬 문제라고 해서 한건데, 시작점이 정해져 있는 문제라 딱히 폴로이드-워샬을 쓸 필요가 없었다.

## 3. 출처

+ 백준 알고리즘 (https://www.acmicpc.net)