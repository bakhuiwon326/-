#include<iostream>
#include<memory.h>

using namespace std;

int tobni[5][8];
int k, num, dir, score;
int dc[2] = { 1, -1 };
bool visited[5];
int rotateInfo[5];

void init() {
	score = 0;
	memset(tobni, 0, sizeof(tobni));
	memset(rotateInfo, 0, sizeof(rotateInfo));
	memset(visited, false, sizeof(visited));
}

void copy(int* origin, int* tmp) {
	for (int i = 0; i < 8; i++) {
		tmp[i] = origin[i];
	}
}

bool isRange(int idx) {
	return 1 <= idx && idx <= 4;
}

void dfs(int num, int dir) {
	for (int i = 0; i < 2; i++) {
		int next = num + dc[i];
		if (isRange(next) && !visited[next]) {
			visited[num] = true;
			if (dc[i] == 1) {
				if (tobni[num][2] == tobni[next][6]) {
					rotateInfo[next] = 0;
				}
				else {
					rotateInfo[next] = rotateInfo[num] * -1;
				}
			}
			else {
				if (tobni[num][6] == tobni[next][2]) {
					rotateInfo[next] = 0;
				}
				else {
					rotateInfo[next] = rotateInfo[num] * -1;
				}
			}
			dfs(next, rotateInfo[next]);
		}
	}
}

void rotate(int idx) {
	int tmp[8];
	copy(tobni[idx], tmp);
	for (int i = 0; i < 8; i++) {
		tobni[idx][(i - 1 + 8) % 8] = tmp[i];
	}
}

void rotate_clock(int idx) {
	int tmp[8];
	copy(tobni[idx], tmp);
	for (int i = 0; i < 8; i++) {
		tobni[idx][(i + 1) % 8] = tmp[i];
	}
}

int main() {

	init();

	// ��� ���� �Է�
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &tobni[i][j]);
		}
	}

	// k�Է�
	scanf("%d", &k);

	// ȸ�� ����
	for (int i = 0; i < k; i++) {
		// num: ���� ��Ϲ��� / dir: ȸ�� ����
		scanf("%d %d", &num, &dir);
		// dfs�� �� ��Ϲ��� ȸ������ ���ϱ�
		memset(visited, false, sizeof(visited));
		rotateInfo[num] = dir;
		visited[num] = true;
		dfs(num, dir);
		// ȸ��
		for (int j = 1; j <= 4; j++) {
			int state = rotateInfo[j];
			if (state == 0) { // ����
				continue;
			}
			else if (state == -1) { // �ݽð�
				rotate(j);
			}
			else if (state == 1) { // �ð�
				rotate_clock(j);
			}
		}
	}

	// ȸ���� ��� ������ ���� �ű�
	score = tobni[1][0] == 0 ? score : score + 1;
	score = tobni[2][0] == 0 ? score : score + 2;
	score = tobni[3][0] == 0 ? score : score + 4;
	score = tobni[4][0] == 0 ? score : score + 8;

	printf("%d", score);

	return 0;

}
