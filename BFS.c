#include <stdio.h>
#include <stdlib.h>

// �ṹ���ʾͼ�еĽڵ�
struct Node {
    int data;
    struct Node* next;
};

// �ṹ���ʾͼ
struct Graph {
    int vertices;
    struct Node** adj_list;
};

// �ṹ���ʾ���нڵ�
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// �ṹ���ʾ����
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// �����½ڵ�
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// ����ͼ
struct Graph* create_graph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // �����ڽӱ�
    graph->adj_list = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; ++i) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

// ��ӱߵ�ͼ��
void add_edge(struct Graph* graph, int src, int dest) {
    // ��ӵ�Դ�ڵ������
    struct Node* new_node = create_node(dest);
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;

    // ��ӵ�Ŀ��ڵ����������ͼ��Ҫ������ӣ�
    new_node = create_node(src);
    new_node->next = graph->adj_list[dest];
    graph->adj_list[dest] = new_node;
}

// ��ʼ������
struct Queue* create_queue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// ���
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

// ����
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1; // ����Ϊ��
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

// �ж϶����Ƿ�Ϊ��
int is_empty(struct Queue* queue) {
    return queue->front == NULL;
}

// ������ȱ���
void bfs(struct Graph* graph, int start_vertex) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = 0;
    }

    //����һ������
    struct Queue* queue = create_queue();

    //���ʵ�һ���ڵ�
    visited[start_vertex] = 1;
    printf("%d ", start_vertex);
    //���
    enqueue(queue, start_vertex);

    while (!is_empty(queue)) {

        int current_vertex = dequeue(queue);
        //���ʳ��ӽڵ���ڽӵ�
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

// ������
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



