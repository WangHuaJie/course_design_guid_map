/*************************************************************************
        > File Name: Show.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Tue 10 Dec 2013 08:03:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include"map.h"


void
vexallarc(AdjMultipleList *G,int i)
{
    ArcNode *ar;
    VertexNode *vex;
    int no;
    int key1 = 0,
        key2 = 0;

    vex = &G->vertex[i];
    ar = vex->head;
    no = vex->No;
    while(ar != NULL)
    {
//        printf("o;o\n");
        if(ar->pvex == no)
        {
            printf("%s<---->%s:  %d km\n",G->vertex[no].name,G->vertex[ar->bvex].name,ar->distence);
            ar = ar->pvex_next;
            
        }   
        else if(ar->bvex == no)
        {
            printf("%s<---->%s:  %d km\n",G->vertex[no].name,G->vertex[ar->pvex].name,ar->distence);
            ar = ar->bvex_next;
        }
    }

    return;
}

void
Show(AdjMultipleList *G)
{
    int i;

    for(i = 0;i < G->vexnum;i++)
    {
        vexallarc(G,i);
    }
        
    return;
}
