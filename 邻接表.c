#include"graph.h"

int LocateVex2(ALGraph *G, VerTexType V1)
{
	for (int i = 0; i < G->vexnum; i++)
	{
		if (G->vertices[i].data == V1)
		{
			return i;
		}
	}
	return -1;
}
int CreateUDG(ALGraph* G)
{
	int num1, num2;
	scanf("%d,%d", &num1, &num2);//输入总顶点数，总边数
	G->vexnum = num1;
	G->arcnum = num2;
	for (int i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &(G->vertices[i].data));//输入顶点信息，这里设置的顶点是字符
		G->vertices[i].firstarc = NULL;//初始化头节点的指针域
	}
	for (int k = 0; k < G->arcnum; k++)//输入各边，构建邻接表
	{
		int v1, v2;
		scanf("%c,%c", &v1, &v2);//输入一条边依附的两个顶点
		int i = LocateVex2(G, v1);
		int j= LocateVex2(G, v2);
		ArcNode* p1 = (ArcNode*)malloc(sizeof(ArcNode));//生成一个新的边节点*p1
		p1->adjvex = j;//邻接序号为j
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1;//将新节点*p1插入到顶点vi的边表头部
		
		ArcNode* p2 = (ArcNode*)malloc(sizeof(ArcNode));//生成一个新的边节点*p1
		p2->adjvex = i;//邻接序号为i
		p2->nextarc = G->vertices[j].firstarc;
		G->vertices[j].firstarc = p2;//将新节点*p2插入到顶点vj的边表头部

		//只实现上述重复代码的一个可以实现有向图
	}


}