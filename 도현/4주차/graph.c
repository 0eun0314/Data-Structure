//
//  graph.c
//  graph
//
//  Created by 정도현 on 2022/08/01.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

// 간선 초기화
void init(weighted_undirected_graph* graph, int n){
    graph->nodeCount = n; // 정점 수 설정
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            graph->arr[i][j] = 1001;    // 가중치 범위가 -1000 ~ 1000 이므로 1001로 초기화
        }
    }
    
    for(int i = 0; i<n; i++){
        graph->visited[i] = false;
    }
}

// 간선 삽입
void insert_edge(weighted_undirected_graph* graph, int u, int v, int w){
    if(u<graph->nodeCount && v < graph->nodeCount) {
        graph->arr[u][v] = w;
        graph->arr[v][u] = w;
    }
}

// 간선 제거
void remove_edge(weighted_undirected_graph* graph, int u, int v){
    if(u<graph->nodeCount && v < graph->nodeCount && graph->arr[u][v] != 1001) {
        graph->arr[u][v] = 1001;
        graph->arr[v][u] = 1001;    // 초기 값 1001로 복귀
    }
}

int get_degree(weighted_undirected_graph* graph, int u){
    int cnt = 0;
    int nodeCnt = graph->nodeCount;
    
    if(u < nodeCnt) {
    // 반복문으로 인접 노드 탐색
        for(int i = 0; i < nodeCnt; i++) {
            // 루프가 없음
            if (i==u)
                continue;
            
            if(graph->arr[u][i] != 1001)
                cnt++;;
        }
    }
    return cnt;
}

// DFS
void DFS(weighted_undirected_graph* graph, int u){
    int nodeCnt = graph->nodeCount;
    int *stack = (int *)malloc(sizeof(int) * graph->nodeCount);
    
    for(int i = 0; i<nodeCnt; i++){
        graph->visited[i] = false;
    }
    
    int top = -1;
    stack[++top] = u;   // 현재 정점 삽입
    
   
    while(top != -1) {
        int cur = stack[top--]; // 스택 pop
        if(!graph->visited[cur]) { // 방문하지 않았다면 방문 처리
            graph->visited[cur] = true;
            printf("%d ", cur);
            for(int nextNode = 0; nextNode < nodeCnt; nextNode++){
                // 방문하지 않았고 간선이 존재하면 스택에 삽입
                if(!graph->visited[nextNode] && graph->arr[cur][nextNode] != 1001)
                    stack[++top] = nextNode;
            }
        }
    }
    printf("\n");
}

// BFS 탐색
void BFS(weighted_undirected_graph* graph, int u){
    int nodeCnt = graph->nodeCount;
    int *q = (int *)malloc(sizeof(int) * graph->nodeCount);
    
    for(int i = 0; i<nodeCnt; i++){
        graph->visited[i] = false;
    }
    
    int front = -1;
    int rear = -1;
    
    q[++rear] = u;
    graph->visited[u] = true;
    while(front != rear) {
        int cur = q[++front];
        printf("%d ", cur);
        for(int nextNode = 0; nextNode < nodeCnt; nextNode++) {
            if(!graph->visited[nextNode] && graph->arr[cur][nextNode] != 1001){
                // 방문되지 않았고 간선이 존재하는 경우 큐에 삽입
                graph->visited[nextNode] = true;
                q[++rear] = nextNode;
            }
        }
    }
    printf("\n");
}
