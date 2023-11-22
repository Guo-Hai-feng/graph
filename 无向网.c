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
	//���ڽӾ����ʾ��������������

	scanf("%d,%d", &(G->vexnum),&(G->arcnum));//�����ܶ��������ܱ���

	//���������
	for (int i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &(G->vexs[i]));//�������붥����Ϣ
	}

	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 9; j < G->vexnum; j++)
		{
			G->arcs[i][j] = MaxInt;//�ߵ�Ȩֵ������Ϊ���ֵ
		}
	}

	for (int k = 0; k < G->vexnum; k++)//�����ڽӾ���
	{
		VerTexType v1, v2;
		int w;
		scanf("%c,%c,%d", &v1, &v2, &w);//�����Ӧ�����Ȩֵ
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		G->arcs[i][j] = w;
		G->arcs[j][i] = G->arcs[i][j];//�Գ�ȨֵΪw
	}
	return OK;
}