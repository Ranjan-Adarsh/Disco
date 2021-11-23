#include <stdio.h>
#include <string.h>

#define mxN 1000 // upper_limit

int n, ct = 0;   // n is label_count
int g[mxN][mxN]; // graph
int vis[mxN];  // boolean visited array
int cmp[mxN];  // component of each node

void dfs (int u) {
   vis[u] = 1;
   cmp[u] = ct; 
   for (int v = 0; v < n; v++) {
      if (vis[v] == 0 && g[u][v] == 1) {
         // printf("%d %d\n", u, v);
         dfs(v);
      }
   }
}

int main () {
   scanf("%d", &n);
   for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
         scanf("%d", &g[r][c]);
      }
   }
   memset(vis, 0, sizeof(vis));
   for (int i = 0; i < n; i++) {
      if (!vis[i]) {
         ct++;
         dfs(i);
      }   
   }
   for (int i = 0; i < n; i++) {
      printf("%d ", cmp[i]);
   }
   printf("\n");
   // can print all the connected components from here as needed, ct is the total components
   return 0;
}

/*
5
0 1 0 1 1
0 0 1 0 1
0 1 0 1 1
1 0 1 0 1
1 1 1 1 1
*/