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