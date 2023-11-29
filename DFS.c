#define _CRT_SECURE_NO_WARNINGS
#include"graph.h"
void DFS(AMGraph G, int v)//ͼΪ�ڽӾ�������
{
    //������������
    int size = G.vexnum + 1;
    int* visited = (int*)malloc(size * sizeof(int));
    if (visited == NULL)
    {
        printf("malloc err");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    //���ʵ�v���ڵ����˼
    printf("%c", G.vexs[v]);

    visited[v] = 1;
    for (int w = 0; w < G.vexnum; w++)//���μ���ڽӾ���v���ڵ���
    {
        if (G.arcs[v][w] != 0 && (!visited[w]))
        {
            DFS(G, w);
            //w��v���ٽ�㣬���wδ�����ʣ���ݹ����DFS
        }
    }
    //�����������ͷſռ�
    free(visited);
}





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

// �����½ڵ�
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// ����ͼ
struct Graph* create_graph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL)
    {
        printf("malloc err");
        return NULL;
    }
    graph->vertices = vertices;

    // �����ڽӱ�
    graph->adj_list = (struct Node**)malloc(vertices * sizeof(struct Node*));
    if (graph->adj_list == NULL)
    {
        printf("malloc err");
        return NULL;
    }
    for (int i = 0; i < vertices; ++i) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

// ��ӱߵ�ͼ��
void add_edge(struct Graph* graph, int src, int dest) {
    // ��ӵ�Դ�ڵ������
    struct Node* new_node = create_node(dest);

    //ͷ�巨
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;

    // ��ӵ�Ŀ��ڵ����������ͼ��Ҫ������ӣ�
    new_node = create_node(src);
    new_node->next = graph->adj_list[dest];
    graph->adj_list[dest] = new_node;
}

// ������ȱ����ĸ�������
void dfs_util(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* current = graph->adj_list[vertex];
    if (current == NULL)
    {
        printf("malloc err");
        return;
    }
    while (current != NULL) {
        int neighbor = current->data;
        if (!visited[neighbor]) {
            dfs_util(graph, neighbor, visited);
        }
        current = current->next;
    }
}

// ������ȱ���
void dfs(struct Graph* graph, int start_vertex)
{
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = 0;
    }

    dfs_util(graph, start_vertex, visited);

    free(visited);
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

    printf("DFS starting from vertex 2: ");
    dfs(graph, 2);

    return 0;
}

