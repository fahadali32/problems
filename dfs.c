#include<stdio.h>
int a[20][20], s[20], visited[20], n, i, j, f = 0, top = -1;
void dfs(int v) {
for(i = 1; i <= n; i++)
if(a[v][i] && !visited[i])
s[++top] = i;
if(top!=-1) {
visited[s[top]] = 1;
dfs(s[top--]);
}
}
void main() {
int v;
printf("\n Enter the number of vertices:");
scanf("%d", &n);
for(i=1; i <= n; i++) {
s[i] = 0;
visited[i] = 0;
}
printf("\n Enter graph data in matrix form:\n");
for(i=1; i<=n; i++) {
for(j=1;j<=n;j++) {
scanf("%d", &a[i][j]);
}
}
printf("\n Enter the starting vertex:");
scanf("%d", &v);
dfs(v);
printf("\n The node which are reachable are:\n");
for(i=1; i <= n; i++) {
if(visited[i])
printf("%d\t", i);
else {
printf("\n Dfs is not possible. Not all nodes are reachable");
break;
}
}
}
