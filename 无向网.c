#include"graph.h"
int LocateVex(AMGraph *G, VerTexType V1)
{
	for (int i = 0; i < G->vexnum; i++)
	{
		if (G->vexs[i] == V1)
		{
			return i;
		}
	}
	return -1;
}
int CreateUDN(AMGraph* G)
{
	//用邻接矩阵表示法，创建无向网

	scanf("%d,%d", &(G->vexnum),&(G->arcnum));//输入总顶点数和总边数

	//建立顶点表
	for (int i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &(G->vexs[i]));//依次输入顶点信息
	}

	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 9; j < G->vexnum; j++)
		{
			G->arcs[i][j] = MaxInt;//边的权值均设置为最大值
		}
	}

	for (int k = 0; k < G->vexnum; k++)//构造邻接矩阵
	{
		VerTexType v1, v2;
		int w;
		scanf("%c,%c,%d", &v1, &v2, &w);//输入对应顶点的权值
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		G->arcs[i][j] = w;
		G->arcs[j][i] = G->arcs[i][j];//对称权值为w
	}
	return OK;
}