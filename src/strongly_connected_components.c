#include <stdio.h>
#include <string.h>

#define mxN 1000 // upper_limit

int n, ct = 0;   // n is label_count
int g[mxN][mxN]; // graph
int vis[mxN];  // boolean visited array
int cmp[mxN];  // component of each node

const char * labels[] = {"Tree", "Wave", "Cloud", "Bruh", "Yama"};

void dfs (int u) {
   vis[u] = 1;
   cmp[u] = ct; 
   for (int v = 0; v < n; v++) {
      if (vis[v] == 0 && g[u][v] == 1 && g[v][u] == 1) {
         printf("%d %d\n", u, v);
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
   /* for (int i = 0; i < n; i++) {
      printf("%d ", cmp[i]);
   }
   printf("\n"); */
   // answer of that question is always yes, if we count a single website to be a part of the piece.
   // O(n^2) without the use of a hashmap.
   for (int i = 1; i <= ct; i++) {
      printf("Component %d:\n", i);
      for (int j = 0; j < n; j++) {
         if (cmp[j] == i) {
            printf("%s ", labels[j]);
         }
      }
      printf("\n");
   }
   return 0;
}

/*
Sample: 
5
0 1 0 1 1
0 0 1 0 1
0 1 0 1 1
1 0 1 0 1
1 1 1 1 1
1 component: {1, 4, 3, 2, 5}

Test case 1:
5
0 0 0 1 0 
0 0 1 0 0 
0 1 0 0 0
1 0 0 0 1
0 0 0 1 0
2 components: {1, 4, 5}, {2, 3}
*/