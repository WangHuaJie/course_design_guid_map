/*************************************************************************
        > File Name: Dfsearch.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Wed 11 Dec 2013 08:05:30 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"map.h"

int start = -1;
int end = -1;
int *startp = &start;
int *endp = &end;

//*********************************************************************
void
get2places( char *ch1, char *ch2)
{
    printf("Please input the START and END places you want to search:\n");
    scanf("%s",ch1);
    fflush(NULL);
    scanf("%s",ch2);
    return;
}

//********************************************************************
void
printwrong(const char *ch)
{
    printf("Sorry,no such %s place in the map,please input again!\n"
            ,ch);
    return;
}

int
changeintono(AdjMultipleList *G,const char *ch1,const char *ch2)
{
    int i,j,k;
    for(i = 0;i <= G->vexnum;i++){
        if(i == G->vexnum){
            printwrong(ch1);
            return -1;
        }
        if(!strcmp(ch1,G->vertex[i].name)){
            *startp = i;
            break;
        }

    }
    for(j = 0;j <= G->vexnum;j++){
        if(j == G->vexnum){
            printwrong(ch2);
            return -1;
        }
        if((k = strcmp(ch2,G->vertex[j].name)) == 0){
            *endp = j;
            break;
        }
    }
    return 1;
}

//*********************************************************************

void
copy(int *road,int *copyroad)
{
    int i;
    for(i = 0;road[i] >-1;i++){
        copyroad[i] = road[i];
    }
    return;
}

void
output(AdjMultipleList *G,int *road)
{
    int i;

    printf("%s",G->vertex[road[0]].name);
    for(i = 1;road[i] > -1;i++){
        printf("---->%s",G->vertex[road[i]].name);
    }
    printf("\n");
    return;
}

int
overoad(int *road,int now)
{
    int i;
    for(i = 0;road[i] > -1;i++){
        if(road[i] == now)
            return -1;
    }
        
    return 1;
}

void
addroad(int *road,int now)
{
    int i;
    for(i = 0;road[i] > -1;i++)
        ;
    road[i] = now;
    return;
}

void
overarc(AdjMultipleList *G,int *vexarray,int now)
{
    ArcNode *ar = G->vertex[now].head;
    int i = 0;
    while(ar != NULL){
        if(ar->pvex == now){
            vexarray[i++] = ar->bvex;
            ar = ar->pvex_next;
        }
        else if(ar->bvex == now){
            vexarray[i++] = ar->pvex;
            ar = ar->bvex_next;
        }
    }
    return;
}

void
recur(AdjMultipleList *G,int *road,int now,int end)
{
    int i,k;
    int j = G->vexnum;
    int vexarray[MAXVEX] = {0},
        copyroad[MAXVEX] = {0};
    memset(vexarray,-1,sizeof(int)*MAXVEX);
    memset(copyroad,-1,sizeof(int)*MAXVEX);
    copy(road,copyroad);
    if(now == end){
        addroad(copyroad,now);
        output(G,copyroad);
        return;
    }
    if((k = overoad(copyroad,now)) == -1){
        return;
    }
    addroad(copyroad ,now);
    overarc(G,vexarray,now);
    for(i = 0;vexarray[i] > -1;i++){
        recur(G,copyroad,vexarray[i],end);
    }
    return;
}

void
search(AdjMultipleList *G)
{
    int road[MAXVEX] = {0};
    memset(road,-1,sizeof(int)*MAXVEX);
    printf("The road is:\n");
    recur(G,road,*startp,*endp);
    return;
}
//*********************************************************************
void
Dfsearch(AdjMultipleList *G)
{
    char ch1[20],
         ch2[20];
    while(1){
        get2places(ch1,ch2);
       if(changeintono(G,ch1,ch2))
           break;
    }
    search(G);
    return;
}
