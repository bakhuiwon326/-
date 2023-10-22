#include <iostream>

using namespace std;

int dp[1001]; // ���� n���� �� ���� �� ���� �� Ƚ��
int n;
int main() {
	// ��������, "�Ϻ��ϰ� ������ �ߴ�"�� "���� ������ ���� Ƚ���� �ּ�"���� �ǹ�
	string res = "";

	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	}

	// n���� ���� ���� �� ���� ���ư��� ������ turn Ƚ���� ¦���� â���̰� �̱�. Ȧ���� ����̰� �̱�
	res = dp[n] % 2 == 0 ? "CY" : "SK";

	printf("%s", res.c_str());

	return 0;
}