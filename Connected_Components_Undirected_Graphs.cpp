#include<bits/stdc++.h>
using namespace std;

int const MAXN = 1e5+5;

int n;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;



void dfs(int v){
	used[v] = true;
	comp.push_back(v);
	for(int i=0; i<g[v].size(); ++i){
		int to = g[v][i];
		if(!used[to])
			dfs(to);
	}
}

void find_comps(){
	for(int i=0; i<n; i++)
		used[i] = false;

	for(int i=0; i<n; i++){
		if(!used[i]){
			comp.clear();
			dfs(i);
			cout<<"Components: ";
			for(int j=0; j<comp.size(); j++){
				cout<<' '<<comp[j];
			}
			cout<<endl;
		}
	}
}

int main(){
	int x, y, e;
	cin>>n>>e;
	for(int i=0; i<e; i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	find_comps();
}
