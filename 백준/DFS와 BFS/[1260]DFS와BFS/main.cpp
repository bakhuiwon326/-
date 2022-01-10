#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define MAXN 1001

using namespace std;

int n, m , v;
vector<int> map[MAXN]; // ������� ���� 
bool visited[MAXN]; // �湮���� 
queue<int> q; // ť

// ��͸� �̿��� DFS 
void DFS(int v){
	visited[v] = true; // v��带 �湮 
	cout << v << " "; // �湮�� ��带 ��� 
	// v���� � ��尡 ����Ǿ��ִ��� Ȯ���Ѵ�. 
	for(int i = 0 ; i < map[v].size(); i++){
		int node = map[v][i]; // v���� ����� i��° ��带 node�� �����Ѵ� 
		if(!visited[node]){ // node�� ���� �湮���� ���� �����, DFS�� �����Ѵ�. 
			DFS(node);
		}
	}
}

// Queue �ڷᱸ���� Ȱ���� BFS 
void BFS(int v){
	q.push(v); // �켱, ó������ �湮�� v��带 queue�� push�Ѵ�.
	visited[v] = true; // ù��° ��带 �湮�ߴٰ� ǥ���Ѵ� 
	// �湮�� ���� ������ ��带  queue�� push�ϰ�, ������ ��带 �˱� ���� ������ �Ǵ� ���� queue���� pop �Ѵ�
	// ��� ��带 pop�Ͽ� queue�� ������� ���� 
	while(!q.empty()){ 
		int root = q.front(); // ������ �Ǵ� ��� ������ ���� 
		q.pop(); // queue���� pop
		cout << root << " ";
		for(int i = 0; i < map[root].size(); i++){
			int node = map[root][i]; // ������ ��� ������ node�� ���� 
			if(!visited[node]){  
				visited[node] = true; // �湮�ߴٰ� ǥ���ϱ� 
				q.push(node); // ������ ��带 queue�� push �Ѵ�. 
			}
		}
	}
}

// �������� ������ ���� compare �Լ� 
int compare(int a, int b){
	return a < b;
}

int main(){
	
	std::ios::sync_with_stdio(false);
	
	cin >> n >> m >> v;
	
	// ���� ��� ������ �����Ѵ� 
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	
	// �� ��������Ʈ�� �������� �����Ѵ� 
	for(int i = 0; i < n; i++){
		sort(map[i].begin(), map[i].end(), compare);
	}
	
	// DFS ���� 
	DFS(v);
	
	// visited�迭�� ���������̱� ������, BFS������ ���� ��� ���Ҹ� false�� �ʱ�ȭ ��Ų�� 
	fill_n(visited, sizeof(visited) / sizeof(bool), false);
	
	cout << endl;
	
	// BFS ����
	BFS(v); 
	
	return 0;
	
}
