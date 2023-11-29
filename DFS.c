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