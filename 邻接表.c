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
	scanf("%d,%d", &num1, &num2);//�����ܶ��������ܱ���
	G->vexnum = num1;
	G->arcnum = num2;
	for (int i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &(G->vertices[i].data));//���붥����Ϣ���������õĶ������ַ�
		G->vertices[i].firstarc = NULL;//��ʼ��ͷ�ڵ��ָ����
	}
	for (int k = 0; k < G->arcnum; k++)//������ߣ������ڽӱ�
	{
		int v1, v2;
		scanf("%c,%c", &v1, &v2);//����һ������������������
		int i = LocateVex2(G, v1);
		int j= LocateVex2(G, v2);
		ArcNode* p1 = (ArcNode*)malloc(sizeof(ArcNode));//����һ���µı߽ڵ�*p1
		p1->adjvex = j;//�ڽ����Ϊj
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1;//���½ڵ�*p1���뵽����vi�ı߱�ͷ��
		
		ArcNode* p2 = (ArcNode*)malloc(sizeof(ArcNode));//����һ���µı߽ڵ�*p1
		p2->adjvex = i;//�ڽ����Ϊi
		p2->nextarc = G->vertices[j].firstarc;
		G->vertices[j].firstarc = p2;//���½ڵ�*p2���뵽����vj�ı߱�ͷ��

		//ֻʵ�������ظ������һ������ʵ������ͼ
	}


}