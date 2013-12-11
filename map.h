/*************************************************************************
        > File Name: map.h
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Mon 09 Dec 2013 08:50:35 AM CST
 ************************************************************************/
#include<string.h>
#define MAXVEX 20
//#define weight int
typedef struct ArcNode
{
    int mark,
        pvex,
        bvex;
    int distence,
        time,
        money;
    
    struct ArcNode *pvex_next,
                   *bvex_next;
}ArcNode;

//#define Datatype char
typedef struct VertexNode
{
    char name[20];
    int No;
    ArcNode *head;
}VertexNode;

typedef struct 
{
    VertexNode vertex[MAXVEX];
    int vexnum,
        arcnum;
}AdjMultipleList;

//function in Build.c**********************************
void
init_map(AdjMultipleList *G);

void
read_vex_data(AdjMultipleList *G);

int
cmp(const char *ch,AdjMultipleList *G);

void
init_arc(ArcNode *arc,int r1,int r2,const char *ch1,const char *ch2);

void
oversert(AdjMultipleList *G,ArcNode *arc,int no);

void
arc_insert(AdjMultipleList *G,ArcNode *arc);
void
arc_build(AdjMultipleList *G,int r1,int r2,const char *ch1,const char *ch2);

void
read_arc_data(AdjMultipleList *G);

void
Build(AdjMultipleList *G);

//functon in Show.c***********************************

void
vexallarc(AdjMultipleList *G,int i);

void
Show(AdjMultipleList *G);
