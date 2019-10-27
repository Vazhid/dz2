//
//  main.c
//  flita_dz2
//
//  Created by Vazhid on 13/10/2019.
//  Copyright © 2019 Vazhid. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



_Bool comm(int n, int arr[n][n]){ // true для связаного / false для не связаного
    for(int i=0; i<n; i++){
        _Bool result = 0;
        for(int j=0; j<n; j++){
            if( arr[i][j] != 0 )
                result = 1;
                
        }
        if(result == 0)
            return 0;
    }
    

    return 1;
}




int main() {

    
    int n;
    printf("Введите количество вершин в графе (число от 1 до 10):\n");
    scanf("%d",&n);
    printf("\n");
    
    if(n<0){
        printf("Введите заново количество вершин, так как оно не может быть отрицательным!\n");
        scanf("%d",&n);
        printf("\n");
    }
    
    int mas[n][n];
    printf("Матрица смежности для данного графа:\n");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i<j) {
              mas[i][j]=-1+rand()%3;
            } else if(i==j) {
                mas[i][j]=0;
            } else {
                mas[i][j]=mas[j][i];
            }
            if (mas[i][j]==-1){
                printf("%d  ",mas[i][j]);
            } else {
                printf("%d   ",mas[i][j]);
            }
        }
        printf("\n");
    }
    
    printf("\n");
    if (comm(n,mas)) printf("Граф связаный!\n");
    else printf("Граф не связаный!\n");
    printf("\n");
    
    
    if (n<=10) {
        char *graph;
        graph = calloc(2048, sizeof(char));
        
        strcat(graph,"echo 'digraph G {");
        
        for(int i=0;i<n;i++) {
                char str0[2] = "0";
                str0[0] = i + '0';
                strcat(graph, str0);
                strcat(graph,";");
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (i<j) {
                    
                    if (mas[i][j]==1) {
                        char str1[2] = "0";
                        str1[0] = i + '0';
                        graph = strcat(graph, str1);
                        graph = strcat(graph, "->");
                        str1[0] ='\0';
                        
                        char str2[2] = "0";

                        str2[0] = j + '0';
                        graph = strcat(graph, str2);
                        graph = strcat(graph, ";");
                        str2[0] ='\0';
                    }
                    if (mas[i][j]==-1) {
                        char str3[2] = "0";
                        
                        str3[0] = j + '0';
                        graph = strcat(graph, str3);
                        graph = strcat(graph, "->");
                        str3[0] ='\0';

                        char str4[2] = "0";
                        str4[0] = i + '0';
                        graph = strcat(graph, str4);
                        graph = strcat(graph, ";");
                        str4[0] ='\0';

                    }
                }
            }
        }
        
    
        graph = strcat(graph,"}' | dot -Tpng >./graph.png");
//        printf("");
//        printf("%s\n",graph);
        system(graph);
    }
    
    return 0;
}

