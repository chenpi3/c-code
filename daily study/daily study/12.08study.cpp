//����Ҫ���д���򣬼������� 1 + 1 / 2 + 1 / 3 + ... ��ǰN��֮�͡�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int  N;
	float i;
	float sum = 0;
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			sum += 1 / i;
		printf("sum=%f", sum);
		return 0;





}