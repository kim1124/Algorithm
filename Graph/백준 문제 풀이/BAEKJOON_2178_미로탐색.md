# 백준 알고리즘 1260 문제

+ BFS로 미로를 탐색하는 문제로 가장 기본적인 문제임.
+ DFS로 미로를 탐색하지 않는 이유는 만약에 미로에 출구가 없는 감금 플레이의 (???) 경우에는 무한루프에 빠지기 때문.
+ 또한 DFS는 재귀를 기반으로 동작하기 때문에 맵의 크기가 커지면 커질수록 시간초과의 확률이 높다.

## 1. 문제
+ <https://www.acmicpc.net/problem/2178>

## 2. 코드

<pre>
  <code>
    /******************************************************************************

    Welcome to GDB Online.
    GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
    C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
    Code, Compile, Run and Debug online from anywhere in world.

    *******************************************************************************/
    #include <stdio.h>
    #define MAX 100

    int Map[MAX][MAX];
    int Visited[MAX][MAX];

    typedef struct {
      int x;
      int y;
      int v;
    } Queue;

    Queue Q[MAX * MAX];
    int front = -1, rear = -1;

    int BFS (int maxY, int maxX) {
    int min = maxY * maxX;

      rear++;
      Q[rear].x = 0;
      Q[rear].y = 0;
      Q[rear].v = 1;

      Visited[0][0] = 1;

      while (front < rear) {
          front++;
          int x = Q[front].x;
          int y = Q[front].y;
          int v = Q[front].v;

          // 끝나는 조건
          if (x == maxX - 1 && y == maxY - 1) {
              if (min > v) {
                min = v;
              }
          }

          // 왼
          if (x - 1 >= 0 && Visited[y][x - 1] == 0 && Map[y][x - 1] == 1) {
              rear++;
              Q[rear].x = x - 1;
              Q[rear].y = y;
              Q[rear].v = v + 1;

              Visited[y][x - 1] = 1;
          }

          // 오
          if (x + 1 < maxX && Visited[y][x + 1] == 0 && Map[y][x + 1] == 1) {
              rear++;
              Q[rear].x = x + 1;
              Q[rear].y = y;
              Q[rear].v = v + 1;

              Visited[y][x + 1] = 1;
          }

          // 위
          if (y - 1 >= 0 && Visited[y - 1][x] == 0 && Map[y - 1][x] == 1) {
              rear++;
              Q[rear].x = x;
              Q[rear].y = y - 1;
              Q[rear].v = v + 1;

              Visited[y - 1][x] = 1;
          }

          // 아
          if (y + 1 < maxY && Visited[y + 1][x] == 0 && Map[y + 1][x] == 1) {
              rear++;
              Q[rear].x = x;
              Q[rear].y = y + 1;
              Q[rear].v = v + 1;

              Visited[y + 1][x] = 1;
          }
      }

      return min;
    }

    int main()
    {
      int N = 0, M = 0;

      scanf("%d %d", &N, &M);

      for (int i = 0; i < N; i++) {
          for (int j = 0; j < M; j++) {
              scanf("%1d", &Map[i][j]);
          }
      }

      printf("%d\n", BFS(N, M));

      return 0;
    }

  </code>
</pre>

## 3. 풀이

+ 2차원 배열을 시작점부터 끝점까지 찾는 기본적인 미로 문제로써 큐의 형태를 자세히 봐야한다.
+ 기본 BFS 코드에서는 큐가 단순히 정점을 등록했다면, 미로 문제는 좌표를 기준으로 큐에 등록해야 하므로 **구조체**를 사용한다.
+ 큐의 구조체에 **v**값은 목적지까지의 거리이며, 문제에서는 이 값이 가장 최소가 되는 경우를 찾아야 한다.
+ 길찾기 문제의 경우 경로가 여러가지가 나오기 때문에 맵에서 나올 수 있는 최대 경우의 수 **(X * Y)** 를 최초 min 값으로 잡고, 미로 탐색 중 목적지에 도착할 때마다 **v**와 **min**을 비교해서 가장 경로수가 작은 값을 리턴한다.

## 4. 출처
+ 백준 알고리즘 (https://www.acmicpc.net)
+ 내가 푼거임. 두번째 품. 더이상 풀고싶지 않음. ㅠㅠ...
