/*************************************************************************
        > File Name: main.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Mon 09 Dec 2013 09:11:15 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"map.h"

int 
main(void)
{
    AdjMultipleList *G;
    G = (AdjMultipleList *)malloc(sizeof(AdjMultipleList));

    Build(G);
    Show(G);
    Dfsearch(G);
//  read_input_file(G);
//  A->B_DFS(G);
//  A->B_BFS(G);
//  A->B->C

    return 0;
}
