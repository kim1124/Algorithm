# 벨만-포드

## 1. 벨만-포드 정의

-   단일 시작점에서 다른 정점들까지 최단 경로를 구하는 알고리즘이다.
-   가중치가 부여된 유향 그래프에 사용하는 알고리즘. (무향그래프가 아니라 캅니다 ...)
-   음의 가중치를 허용하지만, 가중치 합이 음인 싸이클에 허용하지 않는다.
-   정점의 수가 n개면 최단 경로를 구성하는 간선의 수는 최대 n-1 개 까지 가능하다.
-   시간 복잡도는 O(VE)

## 2. 점화식

-   모든 간선에 대해서 완화 과정을 수행한다. (그래서 다익스트라 대비 느리다. 하지만 ...)
-   간선 하나로 구성되는 경로부터 시작해서 간선을 하나씩 추가해서 간선 n-1개로 구성되는 경로를 모두 확인한다.

<pre>
  <code>
    // G: 그래프
    // V: 정점 집합
    // E: 간선 집합
    // S: 선택된 정점 집합
    // D: 시작점에서 각 정점까지의 최단 경로 비용
    // P: 최단 경로 저장

    BELLMAN_FORD (G, startV):
      // 최단 경로 풀이는 대부분 처음에 비용 및 경로를 최대치로 초기화한다.
      for v in V:
        D[v] = INFI
        P[v] = 0

      D[startV] = 0

      // 정점 갯수 - 1 만큼 반복
      for v in |V| - 1:
        // 간선 집합 돌기 (e == G[u][v])
        for e in E:
          // 간선 완화
          if D[v] > D[u] + G[u][v]:
            D[v] = D[u] + G[u][v]
            P[v] = u

      // 음의 싸이클 존재 확인
      for e in E:
        if D[v] > D[u] + G[u][v]:
          return false

      return true
  </code>
</pre>

## 3. 벨만-포드 예제

-   백준 알고리즘의 벨만-포드 문제를 풀이한 것.

<pre>
  <code>
  #include <stdio.h>
  #define MAX_N 501
  #define INFI_N 999999

  int Map[MAX_N][MAX_N];
  int Dist[MAX_N];

  // 맵 초기화
  void initMap () {
    for (int i = 0; i < MAX_N; i++) {
      for (int j = 0; j < MAX_N; j++) {
        Map[i][j] = INFI_N;
      }
    }
  }

  // 벨만-포드 함수
  void bellmanFord (int V) {
    // 정점 갯수별 초기화
    for (int v = 1; v <= V; v++) {
      Dist[v] = INFI_N;
    }

    // 정점 1부터 1까지 거리 초기화
    Dist[1] = 0;

    // 간선 완화 시작 (정점 갯수 - 1번)
    for (int i = 0; i < V - 1; i++) {
      // 간선 체크 시작
      for (int u = 1; u <= V; u++) {
        for (int v = 1; v <= V; v++) {
          if (v != u && Map[u][v] != INFI_N && Dist[v] > Map[u][v] + Dist[u]) {
            Dist[v] = Map[u][v] + Dist[u];
          }
        }
      }
    }

    // 싸이클 확인
    for (int u = 1; u <= V; u++) {
      for (int v = 1; v <= V; v++) {
        if (v != u && Map[u][v] != INFI_N && Dist[v] > Map[u][v] + Dist[u]) {
          printf("-1\n");
          return;
        }
      }
    }

    for (int i = 2; i <= V; i++) {
      if (Dist[i] >= INFI_N) {
        printf("-1\n");
      } else {
        printf("%d\n", Dist[i]);
      }
    }
  }

  int main(void) {
    int N = 0;
    int M = 0;
    int CheckStart = 0;

    initMap();

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
      int src = 0;
      int dst = 0;
      int time = 0;

      scanf("%d %d %d", &src, &dst, &time);

      if (src == 1) {
        CheckStart = 1;
      }

      if (Map[src][dst] > time) {
        Map[src][dst] = time;
      }
    }

    if (CheckStart == 1) {
      bellmanFord(N);
    } else {
      for (int i = 0; i < N - 1; i++) {
        printf("-1\n");
      }
    }

    return 0;
  }
  </code>
</pre>

## 4. 문제 링크

<https://www.acmicpc.net/problem/11657>

## 5. 출처

-   백준 알고리즘 (<https://www.acmicpc.net>)
-   김혜자 선생님도 울고갈 갓고코딩넷 많이 참고하시기 바랍니다. (<http://www.algocoding.net>)
