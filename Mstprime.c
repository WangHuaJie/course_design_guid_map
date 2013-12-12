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
    printf("1\n");
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
            return i;
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

int
cmp2(int *vexarray,int no)
{
    int i;
    printf("5\n");
    for(i = 0;(i < MAXVEX) && (vexarray[i] != -1);i++){
        if(vexarray[i] == no)
            return 1;
    }
    return -1;
}

void
ovexarray(AdjMultipleList *G,int *vexarray,ArcNode *arc[])
{
    int i,j,l,
        k = 1;
    ArcNode *ar;

while(1){
    for(i = 0;i < k;i++){

        for(j = 0;j < G->vexnum;j++){
            if(arc[j] == NULL)
                break;
        }

        ar = G->vertex[vexarray[i]].head;
        while(ar != NULL){
            if(arc[j] == NULL){
                arc[j] = ar;
                if(ar->pvex == vexarray[i])
                    vexarray[k] = ar->bvex;
                else if(ar->bvex == vexarray[i])
                    vexarray[k] = ar->pvex;
            }
            if(ar->pvex == vexarray[i]){
                if((l = cmp2(vexarray,ar->bvex)) == 1){
                    ar = ar->pvex_next;
                }
                else if(ar->distence < arc[j]->distence){
                    arc[j] = ar;
                    vexarray[k] = ar->bvex;
                    ar = ar->pvex_next;
                }
                else
                    ar = ar->pvex_next;
            }
            else if(ar->bvex == vexarray[i]){
                if((l = cmp2(vexarray,ar->pvex)) == 1){
                    ar = ar->bvex_next;
                }
                else if(ar->distence < arc[j]->distence){
                    arc[j] = ar;
                    vexarray[k] = ar->pvex;
                    ar = ar->bvex_next;
                }
                else
                    ar = ar->bvex_next;
            }
        }
    }
    k++;
    if(k > G->vexnum)
        break;
}
    return;
}

void
mst(AdjMultipleList *G,char *ch,ArcNode *arc[])
{
    int i,j,
        vexarray[MAXVEX];
    memset(vexarray,-1,sizeof(int)*MAXVEX);

    if(( j = cmp1(G,ch)) == -1){
        printwrong1(ch);
        return;
    }
    vexarray[0] = j;
    ovexarray(G,vexarray,arc);
    return;
}

//***********************************************************************

void
show_mst(AdjMultipleList *G,ArcNode *arc[])
{
    int i;
    printf("8\n");
    printf("MST of this map is showing following:\n");
    for(i = 0;arc[i] != NULL;i++)
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
    ArcNode *arc[MAXVEX] = {NULL};
    printf("9\n");
    getplace(ch);
    mst(G,ch,arc);
    show_mst(G,arc);
    return;
}
