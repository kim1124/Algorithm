DFS (깊이 우선 탐색)
================

1. DFS 정의
==========
+ 그래프 자료구조의 탐색 방법 중 하나로써 가능한 더 깊이 탐색하는 방법이다.
+ 가장 최근에 발견된 정점 v에 연결된 간선 (정점) 중에서 아직 탐색하지 않은 간선을 선택해서 따라간다.
+ 정점 v에 연결된 모든 간선들이 탐색되었다면, 정점 v를 발견하게 해준 정점으로 돌아가서 아직 탐색하지 않은 간선을 따라간다.
+ 탐색하는 동안 방문한 정점들을 기록하고, 되돌아가기 위해 스택을 사용한다. 코드상으로는 재귀를 사용하는 것이 일반적이다. (재귀로 스택을 구현)

2. DFS 점화식
===========
+ 재귀 호출에 의한 DFS 알고리즘은 아래와 같다.

<pre>
    <code>
        // V: 정점 리스트
        // Visited: 방문 정보 저장 리스트

        DFS (startV):
            Visited[startV] = true

            for v in V:
                if Visited[v] == false:
                    DFS(v)
    </code>
</pre>

3. DFS 기본 예제
==============

3.1 문제
-------
+ 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

3.2 입력
-------
+ 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

3.3 출력
-------
+ 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

3.4 DFS 코드
-----------
<pre>
  <code>
  /******************************************************************************

  Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
  C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
  Code, Compile, Run and Debug online from anywhere in world.

  *******************************************************************************/
  #include <stdio.h>
  #include <stdlib.h>

  #define MAX_N 1001
  #define MAX_M 10001

  int Visited[MAX_N];
  int Graph[MAX_N][MAX_N];

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

  int main()
  {
    // 정점, 앳지, 시작 정점
    int V = 0;
    int E = 0;
    int startV = 0;

    // 위에 3가지 종류 입력
    scanf("%d %d %d", &V, &E, &startV);

    // 간선 리스트 입력 - 그래프 초기화
    for (int i = 1; i <= E; i++) {
        int firstE = 0;
        int secondE = 0;
        
        scanf("%d %d", &firstE, &secondE);

        Graph[firstE][secondE] = 1;
        Graph[secondE][firstE] = 1;
    }

    // 깊이 우선 탐색 시작
    DFS(startV, V);

    return 0;
  }

  </code>
</pre>
