#include <iostream>
#include <iomanip>
using namespace std;

void print_matrix(int** matrix, unsigned N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
}

void change_direction(int& x, int& y, int& di, int& steps, int directions[4][2])
{
	di = (di + 1) % 4; // смена направления
	x = directions[di][0];
	y = directions[di][1];
	steps = 0;
}

void spiral(int N)
{
	int** matrix = new int* [N]; // динамический массив
	for (int i = 0; i < N; ++i)
	{
		matrix[i] = new int[N];
		for (int j = 0; j < N; ++j)
		{
			matrix[i][j] = 0; // тут матрица заполняется нулями
		}
	}

	int directions[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; // массив направлений
	int di = 0; // индекс направления
	int x = 1, y = 0; // направление движения по массиву
	int value = 1; // значение элемента массива
	int i = 0, j = 0; // индексы элемента массива

	int steps = 0;
	// тут массив заполняется числами от 1 до N^2 по спирали
	while (value <= N * N)
	{
		matrix[i][j] = value++;
		if (steps == N - 1) // если на границе в углу матрицы
			change_direction(x, y, di, steps, directions);
		else if (matrix[i + y][j + x] != 0) // если следующий элемент уже заполнен
			change_direction(x, y, di, steps, directions);
		i += y;
		j += x; // увеличение индексов на вектор направления (x, y)
		++steps; // шаг вперёд
	}
	print_matrix(matrix, N);
}


int main()
{
	setlocale(LC_ALL, "rus");

	unsigned N;
	cout << "Введите размер матрицы: ";
	cin >> N;

	if (N > 0)
		spiral(N);
	else
		cout << "Неверный размер матрицы!";

	return 0;
}