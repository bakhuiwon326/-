#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

vector<int> liquid;
int selected[2];
bool visited[100001];
int n;

void init() {
	liquid.clear();
}

void input() {
	scanf("%d", &n);
	int input;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		liquid.push_back(input);
	}
}

pair<int, int> combination(int depth, int next) {
	if (depth == 2) {
		int addRes = selected[0] + selected[1];

	}
	for (int i = next; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			selected[depth] = liquid[i];
			combination(depth + 1, i + 1);
			visited[i] = false;
		}
	}
}

int main() {

	init();
	input();

	int res = 2147483647;
	pair<int, int> resPair = {0,0};

	sort(liquid.begin(), liquid.end());

	int left = 0;
	int right = n - 1;

	while (left < right) {
		// left�� right ��ġ�� ����� ���غ���.
		int sum = liquid[left] + liquid[right];
		if (abs(sum) < abs(res)) {
			res = sum;
			resPair.first = liquid[left];
			resPair.second = liquid[right];
		}
		if (sum == 0) break;
		else if (sum > 0) right--; // sum�� �����,,, right ���� �� ���� ����� ���ؾ� 0�� ����� �� �� �ִ�.
		else left++; // sum�� ������,,, left ���� �� ���� ������ ���ؾ� 0�� ����� �� �� �ִ�.
	}
	
	printf("%d %d", resPair.first, resPair.second);

	return 0;
}