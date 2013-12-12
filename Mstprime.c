/*************************************************************************
        > File Name: Mstprime.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Thu 12 Dec 2013 05:41:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"map.h"

//*********************************************************************

void
getplace( char *ch)
{
    printf("Please input the core-place that you want to search:\n");
    scanf("%s",ch);
    return;
}

//*********************************************************************

int
cmp1(AdjMultipleList *G,char *ch)
{
    int i,j;
    for(i = 0;i < G->vexnum;i++){
        if((j = strcmp(ch,G->vertex[i].name)) == 0)
            return j;
    }
    if(i == G->vexnum)
        return -1;
}

void
printwrong1(char *ch)
{
    printf("Sorry,There is no such %s place in the map !\n",ch);
    return;
}

void
init_vexarray(AdjMultipleList *G,int j,int *vexarray)
{
    memset(vexarray,-1,sizeof(int)*MAXVEX);
    vexarray[0] = j;
    return;
}

int
cmp2(int *vexarray,int no)
{
    int i;
    for(i = 0;(i < MAXVEX) && (vexarray[i] != -1);i++){
        if(vexarray[i] == no)
            return 1;
    }
    return -1;
}

void
ovexarray(AdjMultipleList *G,int *vexarray,ArcNode *arc[])
{
    int i,j
    ArcNode *ar;

    for(i = 0;(i < MAXVEX) && (vexarray[i] != -1) ;i++){
        for(j = 0;j < G->vexnum;j++){
            if(arc[j] == NULL)
                break;
        }
        ar = G->vertex[vexarray[i]].head;
        while(ar != NULL){
            if(ar->pvex == vexarray[i]){
                if(cmp2(vexarray,ar->bvex))
                    ar = ar->pvex_next;
                else{
                    if(ar->distence < arc[j-1]->distence){
                        arc[j-1] = ar;
                        vexarray[i+1] = ar->bvex;
                    }
                    ar = ar->pvex_next;
                }
            }
            else if(ar->bvex == vexarray[i]){
                if(cmp2(vexarray,ar->pvex))
                    ar = ar->bvex_next;
                else{
                    if(ar->distence < arc[j-1]->distence){
                        arc[j-1] = ar;
                        vexarray[i+1] = ar->pvex;
                    }
                    ar = ar->bvex_next;
                }
            }
        }
    }
    return;
}

void
mst(AdjMultipleList *G,char *ch,ArcNode *arc[])
{
    int i,j,
        vexarray[MAXVEX];
    if(( j = cmp1(G,ch)) == -1){
        printwrong1(ch);
        return;
    }
    init_vexarray(G,j,vexarray);
    ovexarray(G,vexarray,arc);
    return;
}

//***********************************************************************

void
show_mst(AdjMultipleList *G,ArcNode *arc[])
{
    int i;
    printf("MST of this map is showing following:\n");
    for(i = 0;i < arc[i] != NULL;i++)
    {
        printf("%s<------->%s  %d\n",G->vertex[arc[i]->pvex].name,
                G->vertex[arc[i]->bvex].name,arc[i]->distence);
    }

    return;
}
//***********************************************************************
void Mstprime(AdjMultipleList *G)
{
    char ch[20];
    ArcNode *arc[G->vexnum];
    memset(arc,NULL,sizeof(ArcNode*)*(G->vexnum));

    getplace(ch);
    mst(G,ch,arc);
    show_mst(arc);
    return;
}
