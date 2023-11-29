#include <stdio.h>
#include <stdlib.h>

// 结构体表示图中的节点
struct Node {
    int data;
    struct Node* next;
};

// 结构体表示图
struct Graph {
    int vertices;
    struct Node** adj_list;
};

// 结构体表示队列节点
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// 结构体表示队列
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// 创建新节点
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// 创建图
struct Graph* create_graph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // 创建邻接表
    graph->adj_list = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; ++i) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

// 添加边到图中
void add_edge(struct Graph* graph, int src, int dest) {
    // 添加到源节点的链表
    struct Node* new_node = create_node(dest);
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;

    // 添加到目标节点的链表（无向图需要两次添加）
    new_node = create_node(src);
    new_node->next = graph->adj_list[dest];
    graph->adj_list[dest] = new_node;
}

// 初始化队列
struct Queue* create_queue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// 入队
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* new_node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
}

// 出队
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1; // 队列为空
    }

    struct QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// 判断队列是否为空
int is_empty(struct Queue* queue) {
    return queue->front == NULL;
}

// 广度优先遍历
void bfs(struct Graph* graph, int start_vertex) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = 0;
    }

    //创造一个队列
    struct Queue* queue = create_queue();

    //访问第一个节点
    visited[start_vertex] = 1;
    printf("%d ", start_vertex);
    //入队
    enqueue(queue, start_vertex);

    while (!is_empty(queue)) {

        int current_vertex = dequeue(queue);
        //访问出队节点的邻接点
        struct Node* current = graph->adj_list[current_vertex];
        while (current != NULL) {
            int neighbor = current->data;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                printf("%d ", neighbor);
                enqueue(queue, neighbor);
            }
            current = current->next;
        }
    }

    free(visited);
    free(queue);
}

// 主函数
int main() {
    struct Graph* graph = create_graph(4);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 3);

    printf("BFS starting from vertex 2: ");
    bfs(graph, 2);

    return 0;
}



