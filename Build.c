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
    printf("3\n");
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
    printf("4\n");
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
arc_insert(AdjMultipleList *G,ArcNode *arc)
{
    int i = 0;
    int key1 = 0,
        key2 = 0;
    ArcNode *ar;

    for(i = 0;i < G->vexnum;i++){
        if(G->vertex[i].head != NULL){
            if(G->vertex[i].head->pvex == arc->pvex)
            {
                ar = G->vertex[i].head;
                while(ar->pvex_next != NULL)
                {
                    printf("ooioo\n");
                    ar = ar->pvex_next;
                }
                ar->pvex_next = arc;
                key1 = 1;
            }
            else if((G->vertex[i].head->bvex == arc->pvex) && (arc != G->vertex[i].head))
            {
                ar = G->vertex[i].head;
                while(ar->bvex_next != NULL)
                {   
                    printf("ooo\n");
                    ar = ar->bvex_next;
                }
                if(arc != ar)
                {
                    ar->bvex_next = arc;
                    key1 = 1;
                }
            }
        }
    }
    if(key1 == 0)
        G->vertex[arc->pvex].head = arc;

    for(i = 0;i < G->vexnum;i++){
        if(G->vertex[i].head != NULL){
            if(G->vertex[i].head->pvex == arc->bvex)
            {
                ar = G->vertex[i].head;
                while(ar->pvex_next != NULL)
                    ar = ar->pvex_next;
                ar->pvex_next = arc;
                key2 = 1;
            }
            else if((G->vertex[i].head->bvex == arc->bvex) && (arc != G->vertex[i].head))
            {
                ar = G->vertex[i].head;
                while(ar->bvex_next != NULL)
                    ar = ar->bvex_next;
                if(arc != ar)
                {
                    ar->bvex_next = arc;
                    key2 = 1;
                }
            }
        }
    }
    if(key2 == 0)
        G->vertex[arc->bvex].head = arc;

    return;
}

void
arc_build(AdjMultipleList *G,int r1,int r2,const char *ch1,const char *ch2)
{

    ArcNode *arc;
    arc = (ArcNode*)malloc(sizeof(ArcNode));
    printf("6\n");
    r1--;
    r2--;
    init_arc(arc,r1,r2,ch1,ch2);
    printf("6.1\n");
    arc_insert(G,arc);
    printf("6.2\n");
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
    printf("8\n");
//    G = (AdjMultipleList *)malloc(sizeof(AdjMultipleList));
    init_map(G);
    read_vex_data(G);
    read_arc_data(G);
            
    return;
}
