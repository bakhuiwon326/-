#include<iostream>

#define INTEGER_MAX_VALUE 987654321

using namespace std;

int n, k;
int small[21], big[21], dp[21][2];
bool isBigBigJump[21];

int main() {
	
	scanf("%d", &n);

	for (int i = 1; i <= n-1; i++) {
		scanf("%d %d", &small[i], &big[i]);
	}

	scanf("%d", &k);

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = INTEGER_MAX_VALUE;
		}
	}

	// dp[������][0] : �������� ������ �� �ſ� ū ���� ������� ����.
	// dp[������][1] : �������� ������ �� ��𼱰� �ſ� ū ������ �����.

	// �ʱ�ȭ
	dp[1][0] = 0;
	dp[2][0] = small[1];
	dp[3][0] = min(dp[1][0] + big[1], dp[2][0] + small[2]);

	// ���� �� ���� ������ now�� ��
	for (int now = 4; now <= n; now++) {
		dp[now][0] = min(dp[now - 1][0] + small[now - 1], dp[now - 2][0] + big[now - 2]);
		dp[now][1] = min(dp[now - 3][0] + k, min(dp[now - 1][1] + small[now - 1], dp[now - 2][1] + big[now - 2]));
	}

	printf("%d", min(dp[n][0], dp[n][1]));

}