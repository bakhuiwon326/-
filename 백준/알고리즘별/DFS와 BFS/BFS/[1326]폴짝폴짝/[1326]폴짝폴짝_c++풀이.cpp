#include<iostream>
#include<queue>

// dp �ƴ�.. �ֳ�? bfs�� ���, ������ ��� ��θ� Ž���� ��ǥ�� ������ ��ΰ� �ִ� ������� �����Ѵ�.
// ������, dp�� ���� �ܹ��⿡ ���ȴ�. �ش� ������ ��� ��������� ������ �� �ֱ� ������ ������ �������� ����
// ��������� �����ϴ� ��θ� ã�ƾ��ϱ� ������ bfs�� ����Ѵ�.
// "�����ŭ ������ �ִ�"�� ������� �ǹ��Ѵ�. ���ǰ�, ���ǰ�

using namespace std;

int n, a, b;
int bridge[10001];
int dist[10001];
bool visited[10001];

void bfs() {

	queue<int> q;

	q.push(a);
	visited[a] = true;

	while (!q.empty()) {
		
		int now = q.front();
		q.pop();

		if (now == b) {
			return;
		}

		// ->
		for (int next = now + bridge[now]; next <= n; next += bridge[now]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				dist[next] = dist[now] + 1;
			}
		}

		// <-
		for (int next = now - bridge[now]; next >= 1; next -= bridge[now]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				dist[next] = dist[now] + 1;
			}
		}
	}

}

int main() {
	
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &bridge[i]);
	}

	scanf("%d %d", &a, &b);

	bfs();
	if (dist[b] == 0) dist[b] = -1;

	
	printf("%d", dist[b]);
	
}