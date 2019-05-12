# DFS (깊이 우선 탐색)


## 1. DFS 정의

+ 그래프 자료구조의 탐색 방법 중 하나로써 가능한 더 깊이 탐색하는 방법이다.
+ 가장 최근에 발견된 정점 v에 연결된 간선 (정점) 중에서 아직 탐색하지 않은 간선을 선택해서 따라간다.
+ 정점 v에 연결된 모든 간선들이 탐색되었다면, 정점 v를 발견하게 해준 정점으로 돌아가서 아직 탐색하지 않은 간선을 따라간다.
+ 탐색하는 동안 방문한 정점들을 기록하고, 되돌아가기 위해 스택을 사용한다. 코드상으로는 재귀를 사용하는 것이 일반적이다. (재귀로 스택을 구현)

## 2. DFS 점화식

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

## 3. DFS 기본 예제

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

## 4. 문제 링크

<https://www.acmicpc.net/problem/1260>

## 5. 출처

+ 백준 알고리즘 (https://www.acmicpc.net)
+ 김혜자 선생님도 울고갈 갓고코딩넷 많이 참고하시기 바랍니다. (http://www.algocoding.net)
