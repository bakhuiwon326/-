#include <iostream>
#include <vector>

using namespace std;

int n;
long long dp[1000001];


int main() {
	scanf("%d", &n);
	// �ٷ� ������ ������ �� ������ ���� 1�� ���� ��.
	// �ٷ� ���������� ������ �� ������ ���� 0�� ���ΰ�.
	// �� �ΰ��� ��� ���Ѱ�!
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i<= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	printf("%lld", dp[n]);

	return 0;
}