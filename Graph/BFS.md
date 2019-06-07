# BFS (너비 우선 탐색)

## 1. BFS 정의

+ 그래프 자료구조의 탐색 방법 중 하나로써 가능한 더 넓게 탐색하는 방법이다.
+ 체계적으로 연결된 간선을 찾아가는 방법으로, 그래프 탐색 알고리즘의 기반이 된다.
+ 큐를 이용하여 대상 간선에 연결된 인접 정점을 찾는다.
+ 시작 정점에서 특정 정점까지의 최단 거리를 알 수 있다.
+ 대부분 경로 탐색 또는 최단 거리 문제가 나오면 BFS일 가능성이 높다.

## 2. BFS 점화식

+ 큐에 의한 BFS 알고리즘은 아래와 같다.

<pre>
  <code>
    // Q: 큐
    // V: 정점 리스트
    // Visited: 방문 정보 저장 리스트
    // D: 출발지부터 대상 정점까지의 거리
    // P: 출발지부터 대상 정점까지의 경로

    BFS (startV):
      Q.enqueue(startV)

      Visited[startV] = true

      while (!Q.empty) {
        int v = Q.dequeue()

        for targetV in V:
          if (Visited[targetV] == false) {
            D[targetV] = D[v] + 1
            P[targetV] = v
            Visited[targetV] = true
          }
      }
  </code>
</pre>

## 3. BFS 기본 예제

+ 이 예제는 백준 알고리즘 홈페이지의 DFS / BFS 문제 중 DFS만을 구현한 코드임.
+ 문제는 백준 알고리즘 사이트가서 확인해보자. 어차피 풀면 리스팅되서 알아서 다나옴.

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

      BFS(N, V);

      return 0;
    }

  </code>
</pre>

## 4. 문제 링크

<https://www.acmicpc.net/problem/1260>

## 5. 출처

+ 백준 알고리즘 (https://www.acmicpc.net)
+ 김혜자 선생님도 울고갈 갓고코딩넷 많이 참고하시기 바랍니다. (http://www.algocoding.net)
