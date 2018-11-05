#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4;

vector<int>G[MAXN];
int vis[MAXN];
void DFS_Recursion(int v)
{
        cout<<v<<" ";
        vis[v]=1;
        for(int i = 0;i < G[v].size();++i)
        {
                int w=G[v][i];
                if(!vis[w])
                        DFS_Recursion(w);
        }
}

void DFS_NonRecursion(int v)
{
        memset(vis,0,sizeof(vis));
        stack<int> s;
        s.push(v);
        while(s.size())
        {
                int u = s.top();s.pop();
                if(!vis[u])
                {
                        cout<<u<<" ";
                        vis[u]=1;
                        for(int i=G[u].size()-1;i>=0;--i)
                                if(!vis[G[u][i]])
                                        s.push(G[u][i]);
                
}  }
}

void BFS_NonRecursion(int v)
{
        memset(vis,0,sizeof(vis));
        vis[v]=1;
        cout<<v<<" ";
        queue<int> que;
        que.push(v);
        while(que.size())
        {
                int w=que.front();que.pop();
                for(int i=0;i<G[w].size();i++)
                {
                        int u = G[w][i];
                        if(!vis[u])
                        {
                                cout<<u<<" ";
                                vis[u]=1;
                                que.push(u);
                        }
                }
        }
}

int main()
{
        int n,m;
        printf("         ********************************************************\n"
               "         *                                                      *\n"
               "         *             此程序解决无向图的遍历问题               *\n"
               "         *             由邻接矩阵存储                           *\n"
               "         *             DFS BFS遍历                              *\n"
               "         *                                                      *\n"
               "         ********************************************************\n"
               );
        cout<<"请输入图点的个数和边的个数："<<endl;
        cin>>n>>m;
        for(int i=0;i<n;++i) 
            G[i].clear();
        printf("请输入%d条边:\n",m);
        for(int i=0;i<m;i++)
        {
                int x,y;
                cin>>x>>y;
                G[x].push_back(y);
                G[y].push_back(x);
        }
        memset(vis,0,sizeof(vis));
        cout<<"DFS_Recursion："<<endl;
        DFS_Recursion(1);
        printf("\n");
        cout<<"DFS_NonRecursion："<<endl;
        DFS_NonRecursion(1);
        printf("\n");
        cout<<"BFS_NonRecursion："<<endl;
        BFS_NonRecursion(1);
        return 0;
}


/*
        1
      /   \
     2     3
    / \   / \
   4   5 6   7

7 6
1 2
1 3
2 4
2 5
3 6
3 7
DFS_ans: 1 2 4 5 3 6 7
BFS_ans: 1 2 3 4 5 6 7
*/