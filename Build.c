/*************************************************************************
        > File Name: build.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Mon 09 Dec 2013 09:10:38 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"map.h"

//**********************************************************************
void
init_map(AdjMultipleList *G)
{
    int i;
    for(i = 0;i < MAXVEX;i++)
    {
        G->vertex[i].head = NULL;
        G->vertex[i].No = 0;
        G->vertex[i].mark = 0;
        memset(G->vertex[i].name,0,MAXVEX);
    }
    G->vexnum = 0;
    G->arcnum = 0;

    return;
}
//******************************************************************
void 
read_vex_data(AdjMultipleList *G)
{
    char ch;
    int i = 0;
    printf("Please input places' name:\n");
    while(1)
    {
        G->vertex[i++].No = G->vexnum;
        printf("Place %d's name:",G->vexnum);
        fflush(NULL);
        scanf("%s",G->vertex[G->vexnum].name);
        getchar();
        G->vexnum++;

        if(G->vexnum > 20)
        {
            printf("Vertex is full!\n");
            break;
        }

        printf("Continue?(y/n):");
        scanf("%c",&ch);
        getchar();
        if(ch == 'n')
            break;
    }
}

int
cmp(const char *ch,AdjMultipleList *G)
{
    int i,
        j;
    for(i = 0;i < G->vexnum;i++)
        if((j = strcmp(ch,G->vertex[i].name)) == 0)
            return ++i;
    printf("No such place %s in the map! Try again!",ch);
    return -1;
}
//*********************************************************************
void
init_arc(ArcNode *arc,int r1,int r2,const char *ch1,const char *ch2)
{
    arc->mark = 0;
    arc->pvex = r1;
    arc->bvex = r2;
    arc->distence = 0;
    arc->time = 0;
    arc->money = 0;
    arc->pvex_next = NULL;
    arc->bvex_next = NULL;

    printf("The distence between %s <----> %s is:",ch1,ch2);
    scanf("%d",&arc->distence);
    printf("The time between %s <----> %s is:",ch1,ch2);
    scanf("%d",&arc->time);
    printf("The cost between %s <----> %s is:",ch1,ch2);
    scanf("%d",&arc->money);

    return;
}


void
oversert(AdjMultipleList *G,ArcNode *arc,int no)
{
    ArcNode *ar1,
            *ar2;
    ar1 = G->vertex[no].head;
    
    while(ar1 != NULL){
        if(ar1->pvex == no){
            ar2 = ar1;
            ar1 = ar1->pvex_next;
        }
        else{
            ar2 = ar1;
            ar1 = ar1->bvex_next;
        }
    }
    if(ar2->pvex == no)
        ar2->pvex_next = arc;
    else if(ar2->bvex == no)
        ar2->bvex_next = arc;
    
    return;
}

void
arc_insert(AdjMultipleList *G,ArcNode *arc)
{
    int pvex = arc->pvex,
        bvex = arc->bvex;

    if(G->vertex[pvex].head == NULL)
        G->vertex[pvex].head = arc;
    else
        oversert(G,arc,pvex);

    if(G->vertex[bvex].head == NULL)
        G->vertex[bvex].head = arc;
    else
        oversert(G,arc,bvex);

    return;
}

<<<<<<< HEAD
=======

>>>>>>> b4d11f85fd9534fe4a61fe916fdf972fb2e0992c
void
arc_build(AdjMultipleList *G,int r1,int r2,const char *ch1,const char *ch2)
{

    ArcNode *arc;
    arc = (ArcNode*)malloc(sizeof(ArcNode));
    r1--;
    r2--;
    init_arc(arc,r1,r2,ch1,ch2);
    arc_insert(G,arc);
    return;
}

void
read_arc_data(AdjMultipleList *G)
{
    char ch1[20],
         ch2[20];
    char ch;

    int r1,
        r2;

    printf("Please input arcs' data\n");
    while(1)
    {
        fflush(NULL);
        printf("Place 1:");
        scanf("%s",ch1);
        printf("Place 2:");
        scanf("%s",ch2);
        if((r1 = cmp(ch1,G)) && (r2 = cmp(ch2,G)))
            arc_build(G,r1,r2,ch1,ch2);            
        printf("Continue?(y/n):");
        fflush(stdin);
        scanf(" %c",&ch);
        getchar();
        if(ch == 'n')
            break;
    }             
    return;
}
//********************************************************************
void
Build(AdjMultipleList *G)
{
    init_map(G);
    read_vex_data(G);
    read_arc_data(G);
            
    return;
}
