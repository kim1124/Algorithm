# 다익스트라

## 1. 정의

+ 가중치가 주어지면 사실상 이 알고리즘에 관련된 문제가 튀어나올 확률이 매우 높은 알고리즘.
+ 가중치가 주어진 최단거리 / 최단경로 문제에 관련된 알고리즘 중 가장 빠르다.
+ 단일 시작점에서 다른 정점까지 최단 경로를 구하는 알고리즘이다.
+ 시작점에서 도착점까지 최단 경로를 구하려면 나머지 정점들에 대한 최단 경로도 구해야한다.
+ 음의 가중치를 사용할 수 없다. 음의 가중치가 나오면 <strong>벨만-포드</strong> 알고리즘을 기억하자.

## 2. 점화식

<pre>
    <code>
        // D: 최단 경로 저장
        // M: 인접 행렬
        // Visited: 방문한 정점

        Dijkstra (startV, destV, countV):
            // 최단 경로 최대치로 초기화
            for v in |V|:
                D[v] = INFI

            // 시작점 최소 초기화
            D[startV] = 0

            // 간선 갯수만큼 시작
            for v in |V|:
                // 최소 경로 초기화
                int min = INFI

                // 가장 가까운 정점 찾기
                for vv in |V|:
                    // 방문하지 않았고, 최소값보다 작은 경로
                    if Visited[vv] == 0 && min > D[vv]:
                        min = D[vv]
                        startV = vv

                // 방문 표시
                Visited[startV] = 1;
                
                // 간선 완화 시작
                for vv in |V|:
                    // 이동 가능한 정점이고, 간선 완화 시 출발지에서 목적지로 가는 비용보다 작으면 최단비용 갱신
                    if M[startV][vv] != INFI && D[v] > D[startV] + M[startV][vv]:
                        D[v] = D[startV] + M[startV][vv]
    </code>
</pre>

## 3. 출처

+ 백준 알고리즘 (https://www.acmicpc.net)
