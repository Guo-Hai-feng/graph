#define _CRT_SECURE_NO__WARNINGS
#include<stdio.h>
#define MVNum 100						//最大顶点数
#define MaxInt 32767					//表示极大值
#define OK 1
typedef char VerTexType;				//设置顶点的数据类型
typedef int ArcType;					//假设边的权值为整型
typedef struct
{
	VerTexType vexs[MVNum];             //顶点表
	ArcType arcs[MVNum][MVNum];			//邻接矩阵
	int vexnum, arcnum;					//图的当前点数和边数
}AMGraph;

//边节点的定义
typedef struct ArcNode
{
	int adjvex;//该边所指向的顶点位置
	ArcType info;//信息域，存放权值
	struct ArcNode* nextarc;//指向下一条顶点信息
}ArcNode;

typedef struct VNode
{
	VerTexType data;//定点信息
	ArcNode* firstarc;//指向第一条依附于该顶点的指针

}VNode,AdjList[MVNum];

typedef struct
{
	AdjList vertices;//vertices--vertice的复数，表示邻接表数组
	int vexnum,arcnum;//图的当前顶点和弧数
}ALGraph;
int CreateUDG(ALGraph* G);
int LocateVex(AMGraph* G, VerTexType V1);
int CreateUDN(AMGraph* G);
