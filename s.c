#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	register double a_up = 0.0f, a_down = 0.0f; //a_분자부분    a_분모부분
	double MSE = 0.0f, x_mean = 0.0f, y_mean = 0.0f, a = 0.0f, b = 0.0f, x[100] = { 0.0f, }, y[100] = { 0.0f, }, pred[100] = { 0.0f, };
	//   평균제곱오차      x_평균        y_평균        a(x 계수)      b(y 절편)    입력될 x값     입력될 y값       예측값 
	scanf("%d", &n);



	//입력된 x, y 각각의 평균 계산
	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &x[i], &y[i]);

	for (int i = 0; i < n; i++)
		x_mean += x[i];
	x_mean /= n;

	for (int i = 0; i < n; i++)
		y_mean += y[i];
	y_mean /= n;



	//기울기(a) 및 y절편(b) 계산
	for (int i = 0; i < n; i++)
		a_up += (x[i] - x_mean) * (y[i] - y_mean);

	for (int i = 0; i < n; i++)
		a_down += pow((x[i] - x_mean), 2);

	a = a_up / a_down;
	b = y_mean - (x_mean * a);



	//예측값 및 MSE 계산
	for (int i = 0; i < n; i++)
	{
		pred[i] = (a * x[i]) + b;
		MSE += pow(y[i] - pred[i], 2);
	}
	MSE /= n;



	//최종 결과 출력
	printf("%lg %lg %lg\n", a, b, MSE);

	for (int i = 0; i < n; i++)
		printf("%lg %lg\n", y[i], pred[i]);



	return 0;
}