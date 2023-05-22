#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minfunc(int key[],int set[], int V){
    int min=INT_MAX, min_id;
    int i;
    for(i=0;i<V;i++){
        if(set[i]==0 && key[i] < min){
            min=key[i];
            min_id=i;
        }
    }
    return min_id;
}

void display(int parent[], int **G,int V){
    int i;
    printf("Edge \t Weight\n");
    for(i=0;i<V;i++){
        printf("%d-%d \t %d\n",parent[i],i,G[i][parent[i]]);
    }
}

void process(int **G, int V){
    int i,j;
    
    int *parent =(int *)malloc(V *sizeof(int));
    int *key =(int *)malloc(V *sizeof(int));
    int *set =(int *)malloc(V *sizeof(int));
    
    for(i=0;i<V;i++){
        key[i]=INT_MAX;
        set[i]=0;
    }
    
    key[0]=0;
    parent[0]=-1;
    
    for(i=0;i<V-1;i++){
        int u = minfunc(key,set,V);
        set[u] = 1;
    
    
        for(j = 0;j<V;j++){
            if(G[u][j] && set[j]==0 && G[u][j]<key[j]){
                parent[j]=u;
                key[j]=G[u][j];
            }
        }
    }
    
    display(parent,G,V);
    
    free(parent);
    free(key);
    free(set);

}

int main()
{
    int Ver;
    int i,j;
    printf("Enter no.of vertices");
    scanf("%d",&Ver);
    
    int G=(int )malloc(Ver * sizeof(int *));
    for(i=0;i<Ver;i++){
        G[i]=(int *)malloc(Ver * sizeof(int));
    }
    printf("Enter the graph matrix(%d x %d);\n",Ver,Ver);
    for(i=0;i<Ver;i++){
        for(j=0;j<Ver;j++)
            scanf("%d",&G[i][j]);
    }
    
    process(G,Ver);
    
    for(i=0;i<Ver;i++){
        free(G[i]);
    }
    free(G);
    
    return 0;
}
