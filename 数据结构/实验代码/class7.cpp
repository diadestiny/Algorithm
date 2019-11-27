#include<stdio.h>
  
#define MAX 600  
#define INF 1000000;  
 
int map[MAX][MAX];  
int len[MAX];  	
int visit[MAX];  
int n,m;  
 
int dijkstra(int from, int to){
	
    int i;  
    
    for(i = 1 ; i <= n ; i ++){	
        visit[i] = 0;	
        len[i] = map[from][i]; 
    }  
  
    int j;  
    for(i = 1 ; i < n ; ++i){	
        int min = INF; 
        int pos;  
  
        for(j = 1 ; j <= n ; ++j){	
            if(!visit[j] && min > len[j]){  
                pos = j;  
                min = len[j];  
            }  
        }  
        visit[pos] = 1;  
  
        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && (len[j] > (len[pos] +map[pos][j]))){ 
                len[j] = len[pos] + map[pos][j];	
            }  
        }  
    }  
  
    return len[to];
}
  
  
int main () {  
 
    int i,j;  
    
    scanf("%d%d",&n,&m);	
 
    for(i = 1 ; i <= n ; ++i){	
        for(j = 1 ; j <= n ; ++j){  
            map[i][j] = INF;  
        }  
    }  
	
	int a,b,c;	
    for(i = 1 ; i <= m ; ++i){  
        scanf("%d%d%d",&a,&b,&c);  
        map[a][b] = map[b][a] = c;  
    }  
    
    int temp = INF;
	for(i = 1 ; i <= n ; ++i){
		for(j = 1 ; j <= n ; ++j){
			if(map[i][j] == temp)
				map[i][j] = map[j][i];
		}
	}
    
    int ans = dijkstra(1,n);  
 
    printf("from 1 to %d min distance is %d",n,ans);  

    return 0;  
} 
 
/*	
6 9
1 2 7
1 3 9
1 6 14
2 3 10
2 4 15
3 6 2
5 6 9
4 5 6
3 4 15
*/