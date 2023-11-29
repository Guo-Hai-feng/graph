#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
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



//���Ľڵ�ṹ
typedef struct ArcNode
{
	int adjvex;//�ñ���ָ��Ķ���λ��
	ArcType info;//��Ϣ�򣬴��Ȩֵ
	struct ArcNode* nextarc;//ָ����һ��������Ϣ
}ArcNode;


//����Ľڵ�ṹ
typedef struct VNode
{
	VerTexType data;//������Ϣ
	ArcNode* firstarc;//ָ���һ�������ڸö����ָ��

}VNode,AdjList[MVNum];

//�����ڽӱ�
typedef struct
{
	AdjList vertices;//vertices--vertice�ĸ�������ʾ�ڽӱ�����
	int vexnum,arcnum;//ͼ�ĵ�ǰ����ͻ���
}ALGraph;

int CreateUDG2(ALGraph* G);
int LocateVex2(ALGraph* G, VerTexType V1);
int LocateVex(AMGraph* G, VerTexType V1);
int CreateUDN(AMGraph* G);
void DFS(AMGraph G, int v);//ͼΪ�ڽӾ�������


