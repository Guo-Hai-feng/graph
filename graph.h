#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
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



//弧的节点结构
typedef struct ArcNode
{
	int adjvex;//该边所指向的顶点位置
	ArcType info;//信息域，存放权值
	struct ArcNode* nextarc;//指向下一条顶点信息
}ArcNode;


//顶点的节点结构
typedef struct VNode
{
	VerTexType data;//定点信息
	ArcNode* firstarc;//指向第一条依附于该顶点的指针

}VNode,AdjList[MVNum];

//定义邻接表
typedef struct
{
	AdjList vertices;//vertices--vertice的复数，表示邻接表数组
	int vexnum,arcnum;//图的当前顶点和弧数
}ALGraph;

int CreateUDG2(ALGraph* G);
int LocateVex2(ALGraph* G, VerTexType V1);
int LocateVex(AMGraph* G, VerTexType V1);
int CreateUDN(AMGraph* G);
void DFS(AMGraph G, int v);//图为邻接矩阵类型


