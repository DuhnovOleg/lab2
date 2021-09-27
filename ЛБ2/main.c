#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define n 10


/*int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	//clock_t start, end; // объ€вл€ем переменные дл€ определени€ времени выполнени€

	int i = 0, j = 0, r;
	int a[n][n], b[n][n], c[n][n], elem_c;

	clock_t start = clock();
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < n)
	{
		while (j < n)
		{
			a[i][j] = rand() % 100 + 1; // заполн€ем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < n)
	{
		while (j < n)
		{
			b[i][j] = rand() % 100 + 1; // заполн€ем массив случайными числами
			j++;
		}
		i++;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			elem_c = 0;
			for (r = 0; r < n; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	clock_t end = clock();
	float res = end - start;
	printf("¬рем€ в мс: %.15f", res/1000);

	return(0);
}*/

void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;

	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int main()
{
	setlocale(LC_ALL, "Ru");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start = clock();
	int count;
	printf("¬ведите размерность массива: ");
	scanf("%d", &count);
	int* items = (int*)malloc(count * sizeof(items));
	for (int i = 0; i < count; i++)
	{
		items[i] = rand() % 100;
	}

	shell(items, count);

	clock_t end = clock();
	float res = end - start;
	printf("¬рем€ в мс: %.15f", res / 1000);


	clock_t st = clock();

	qs(items, 0, count - 1);

	clock_t en = clock();
	float result = en - st;
	printf("\n¬рем€ в мс: %.15f", result / 1000);
}
