# Brute-Force 최단 경로

가중치가 부여된 그래프에서 최단 경로를 구할때 사용한다. 사실 브루트-포스 방식은 그래프에만 사용하는 단어가 아닌데, 의미가 **"존나 다 까보는것"** 이기 때문이다.
<br>
이 알고리즘은 사실상 마지막 방법으로 성능 제한에 걸릴 확률이 높아 정말 최후의 보루로 사용해야만 한다.

## 1. 브루트-포스 기본

![가중치가 있는 무향 그래프](http://www.algocoding.net/_images/shrt_graph.png)

위의 그래프를 브루트 포스로 탐색해보자. 일단 점화식은 아래와 같다.

> 브루트 포스 점화식
>>
<pre>
  <code>
    // 최단 경로 저장하는 D
    // 진행 경로를 저장하는 P

    D[] = INFI
    P[] = 0

    Brute-Force (G, s):
      for v in V:
        D[v] = INFI
        P[v] = NULL

      D[s] = 0
  </code>
</pre>

최단 경로를 저장하는 D를 가장 큰 가중치로 모두 초기화 하고, 진행 경로도 없음으로 모두 초기화한다. 이후에 시작 간선을 0으로 초기화하고, 모든 정점을 **존나 다 탐색**한다. 탐색할 때 최단 경로를 변경해야 하는데, 조건에 성립하면 간선 완화 과정을 수행하여 더이상 변경이 없을때까지 수행한다.

위 그래프의 브루트-포스 알고리즘으로 탐색하는 코드는 아래와 같다.

<pre>
  <code>
    /******************************************************************************

    Welcome to GDB Online.
    GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
    C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
    Code, Compile, Run and Debug online from anywhere in world.

    *******************************************************************************/
    #include <stdio.h>

    int D[100];
    int P[100];
    int G[100][100];

    int main()
    {
      int edge[] = {1, 2, 2, 1, 3, 2, 2, 4, 3, 2, 5, 5, 3, 6, 1, 4, 7, 4, 5, 7, 1, 5, 6, 2, 6, 8, 6, 7, 8, 2};

      for (int i = 0; i < sizeof(edge) / 4; i+=3) {
          int src = edge[i];
          int dest = edge[i + 1];
          int weight = edge[i + 2];

          G[src][dest] = weight;
          G[dest][src] = weight;
      }

      for (int i = 1; i <= 8; i++) {
          D[i] = 9999;
      }

      D[1] = 0;
      int flag = 1;

      while (flag) {
          flag = 0;

          for (int i = 1; i <= 8; i++) {
              for (int j = 1; j <= 8; j++) {
                  if (G[i][j] > 0 && D[j] > D[i] + G[i][j]) {
                      D[j] = D[i] + G[i][j];
                      P[j] = i;
                      flag = 1;
                  }
              }
          }
      }

      for (int i = 1; i <= 8; i++) {
          printf("시작점부터 정점 %d 까지의 최단 거리 : %d\n", i, D[i]);
      }

      return 0;
    }

  </code>
</pre>

## 2. BFS로 브루트-포스 사용하기

브루트-포스는 효율성에서 매우 떨어지기 때문에 BFS 구조를 변경해서 사용한다. 아래의 그래프를 보자.

![가중치가 있는 무향 그래프](http://www.algocoding.net/_images/shrt_graph.png)

이 그래프를 BFS를 변경한 브루트-포스로 탐색해보자.
