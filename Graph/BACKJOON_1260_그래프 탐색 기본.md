# 백준 알고리즘 1260 문제

+ DFS.md 와 BFS.md 의 예제코드를 합친 문서임.

## 1. 코드
<pre>
  <code>
    /******************************************************************************

    Welcome to GDB Online.
    GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
    C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
    Code, Compile, Run and Debug online from anywhere in world.

    *******************************************************************************/

    #include <stdio.h>
    #define MAX_N 1001

    int Q[MAX_N];
    int front = -1, rear = -1;

    int Graph[MAX_N][MAX_N];
    int Visited[MAX_N * MAX_N];

    void DFS (int startV, int V) {
      // 방문 체크
      Visited[startV] = 1;

      // 출력
      printf("%d ", startV);

      // 정점 체크 시작
      for (int v = 1; v <= V; v++) {
          // 방문하지 않았고 연결된 정점이라면 진입
          if (Visited[v] == 0 && Graph[startV][v] == 1) {
              DFS(v, V);
          }
      }
    }


    void BFS (int V, int startV) {
      // 1. 큐에 정점 넣기
      Q[++rear] = startV;

      // 2. 방문 표시
      Visited[startV] = 1;

      printf("%d ", startV);

      // 3. BFS 시작
      while (front < rear) {
          // 4. 큐에서 정점 빼기
          int v = Q[++front];

          // 5. 인접 정점 찾기
          for (int i = 1; i <= V; i++) {
              // 6. 방문하지 않았고, 인접하였으면 큐에 등록
              if (Visited[i] == 0 && Graph[v][i] == 1) {
                  // 7. 방문 표시
                  Visited[i] = 1;

                  // 8. 큐에 정점 넣기
                  Q[++rear] = i;

                  // 9. 출력
                  printf("%d ", i);
              }
          }
      }
    }

    int main()
    {
      int N = 0;
      int M = 0;
      int V = 0;

      scanf("%d %d %d", &N, &M, &V);

      for (int i = 1; i <= M; i++) {
          int first = 0;
          int second = 0;
          scanf("%d %d", &first, &second);

          Graph[first][second] = 1;
          Graph[second][first] = 1;
      }

      DFS(V, N);

      printf("\n");

      for (int i = 0; i < MAX_N; i++) {
          Visited[i] = 0;
      }

      BFS(N, V);

      return 0;
    }

  </code>
</pre>

## 2. 코드 분석

+ 탐색 인덱스가 1부터 시작한다는 것에 주의해야함. 안그러면 배열 인덱스 초과 에러가 발생함.
+ 대부분 문제에서 인덱스가 1부터 시작함. 원래 개발자 언어로 첫 인덱스는 0인게 국내를 포함해서 전세계적인 트랜드인데 꼰머들이 이런 쓸따리없는 제도 읍읍 ...
+ DFS의 경우 경로 찾기나 최단 경로 찾기 문제에서 쉽게 볼 수 없는데, 재귀 기반이기 때문에 목적지에 도착하지 못하면 무한루프가 발생함. 대부분 경로 문제는 BFS임.

## 3. 출처

+ 백준 알고리즘 (https://www.acmicpc.net)
+ 내 거친 생각과 불안한 눈빛과 그걸 지켜보는 너어어어~ 그건 아마도~
