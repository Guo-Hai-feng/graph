#define _CRT_SECURE_NO_WARNINGS
#include"graph.h"
void DFS(AMGraph G, int v)//图为邻接矩阵类型
{
    //构建辅助数组
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

    //访问第v个节点的意思
    printf("%c", G.vexs[v]);

    visited[v] = 1;
    for (int w = 0; w < G.vexnum; w++)//依次检查邻接矩阵v所在的行
    {
        if (G.arcs[v][w] != 0 && (!visited[w]))
        {
            DFS(G, w);
            //w是v的临界点，如果w未被访问，则递归调用DFS
        }
    }
    //遍历结束，释放空间
    free(visited);
}





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

// 创建新节点
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

// 创建图
struct Graph* create_graph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL)
    {
        printf("malloc err");
        return NULL;
    }
    graph->vertices = vertices;

    // 创建邻接表
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

// 添加边到图中
void add_edge(struct Graph* graph, int src, int dest) {
    // 添加到源节点的链表
    struct Node* new_node = create_node(dest);

    //头插法
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;

    // 添加到目标节点的链表（无向图需要两次添加）
    new_node = create_node(src);
    new_node->next = graph->adj_list[dest];
    graph->adj_list[dest] = new_node;
}

// 深度优先遍历的辅助函数
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

// 深度优先遍历
void dfs(struct Graph* graph, int start_vertex)
{
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = 0;
    }

    dfs_util(graph, start_vertex, visited);

    free(visited);
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

    printf("DFS starting from vertex 2: ");
    dfs(graph, 2);

    return 0;
}

