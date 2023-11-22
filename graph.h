#define _CRT_SECURE_NO__WARNINGS
#include<stdio.h>
#define MVNum 100						//��󶥵���
#define MaxInt 32767					//��ʾ����ֵ
#define OK 1
typedef char VerTexType;				//���ö������������
typedef int ArcType;					//����ߵ�ȨֵΪ����
typedef struct
{
	VerTexType vexs[MVNum];             //�����
	ArcType arcs[MVNum][MVNum];			//�ڽӾ���
	int vexnum, arcnum;					//ͼ�ĵ�ǰ�����ͱ���
}AMGraph;

//�߽ڵ�Ķ���
typedef struct ArcNode
{
	int adjvex;//�ñ���ָ��Ķ���λ��
	ArcType info;//��Ϣ�򣬴��Ȩֵ
	struct ArcNode* nextarc;//ָ����һ��������Ϣ
}ArcNode;

typedef struct VNode
{
	VerTexType data;//������Ϣ
	ArcNode* firstarc;//ָ���һ�������ڸö����ָ��

}VNode,AdjList[MVNum];

typedef struct
{
	AdjList vertices;//vertices--vertice�ĸ�������ʾ�ڽӱ�����
	int vexnum,arcnum;//ͼ�ĵ�ǰ����ͻ���
}ALGraph;
int CreateUDG(ALGraph* G);
int LocateVex(AMGraph* G, VerTexType V1);
int CreateUDN(AMGraph* G);
