# 백준 알고리즘 13913 문제

+ BFS.md 기본 문제 중 하나로 인접 행렬을 사용하지 않는 특징이 있음.

## 1. 코드

#include <stdio.h>
#define MAX 100000

// 큐 필요
int Q[MAX * 2];
int front = -1, rear = -1;

// 경로 저장용
int P[MAX + 1];
int D[MAX + 1];
int printP[MAX + 1];

// 방문 표시
int Visited[MAX + 1];

void printPath (int v, int c, int max) {
	// 최대치까지 오면 종료
	if (c < 0) {
		// 최종 출력
		for (int i = 0; i < max; i++) {
			printf("%d ", printP[i]);
		}
		
		return;
	}
	
	printP[c - 1] = P[v];
	
	// 재귀 시작
	printPath(P[v], c - 1, max);
}

void BFS (int startV, int distV) {
	// 리어 증가
	rear++;
	
	// 큐에 등록
	Q[rear] = startV;
	
	// 시작 지점 추가
	Visited[startV] = 1;
	
	// 시작 지점 거리, 경로 등록
	P[rear] = startV;
	D[startV] = 0;
	
	// BFS 탐색 시작
	while (front < rear) {
		// Front 증가
		front++;
		
		// 큐에서 꺼내기
		int nextV = Q[front];
		
		// 현재 위치가 목적지면 종료
		if (nextV == distV) {
			// 최단 거리
			printf("%d\n", D[nextV]);
			
			// 최단 경로 끝에 목적지 추가
			printP[D[nextV]] = distV;
			
			// 최단 경로
			printPath(distV, D[nextV], D[nextV] + 1);
			
			break;
		}
		
		// nextV - 1 진행 시 > nextV가 0보다 크거나 같고, 방문하지 않았다면 큐에 등록
		if (nextV - 1 >= 0 && !Visited[nextV - 1]) {
			// rear 증가
			rear++;
			
			// 큐에 등록
			Q[rear] = nextV - 1;
			
			// 방문 등록
			Visited[nextV - 1] = 1;
			
			// 거리 및 가중치 등록
			P[nextV - 1] = nextV;
			D[nextV - 1] = D[nextV] + 1;
		}
		
		// X + 1 진행 시 > 방문 체크만 확인
		if (nextV + 1 <= MAX && !Visited[nextV + 1]) {
			// rear 증가
			rear++;
			
			// 큐에 등록
			Q[rear] = nextV + 1;
			
			// 방문 등록
			Visited[nextV + 1] = 1;
			
			// 거리 및 가중치 등록
			P[nextV + 1] = nextV;
			D[nextV + 1] = D[nextV] + 1;
		}
		
		// X * 2 진행 시
		if (nextV * 2 <= MAX && !Visited[nextV * 2]) {
			// rear 증가
			rear++;
			
			// 큐에 등록
			Q[rear] = nextV * 2;
			
			// 방문 등록
			Visited[nextV * 2] = 1;
			
			// 거리 및 가중치 등록
			P[nextV * 2] = nextV;
			D[nextV * 2] = D[nextV] + 1;
		}
	}
}

int main(void) {
	int start = 0, end = 0;
	
	scanf("%d %d", &start, &end);
	
	BFS(start, end);
	
	return 0;
}

## 2. 코드 분석

+ 인접 행렬을 사용하지 않는 문제지만, 2차원 배열의 맵에서 움직이는 것과 같다.
+ 방문하지만 않았다면 모두 이동 가능하므로, 구지 2차원 배열로 표시해가며 이동할 필요가 없다.
+ 여기서 특이한 점은 최단 경로를 저장하고 출력하는 부분이며, 재귀 함수를 사용하여 경로를 저장하고 마지막에 출력한다.
+ 이동할 정점을 큐에 넣을때 이전 경로를 배열 P에 넣기 때문에 역순으로 출력해야만 한다.

## 3. 출처

+ 백준 알고리즘 (https://www.acmicpc.net)