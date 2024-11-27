#include <iostream>
#include <Windows.h>
using namespace std;


void init_matrix(int *arr, int size){
	int startr = 0, endr = size * size - 1;
	int* end = arr + size * size - 1;
	for (int* ptr = arr; ptr <= end; ptr++) {
		*ptr = rand() % (endr - startr + 1) + startr;
	}
}
int partition(int *arr, int size, int start, int end) {
	int pivot = *(arr + end);
	int i = (start - 1);
	for (int j = start; j < end; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[end]);
	return (i + 1);
}

void quick_sort(int arr[], int size, int start, int end) {
	if (start < end) {
		int mid = partition(arr, size, start, end);
		quick_sort(arr, size, start, mid - 1);
		quick_sort(arr, size, mid + 1, end);
	}
}
void sneake_init(int* arr, int size, int dis) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));
	int tabl = 0;
	int* end = arr + size * size - 1;
	for (int* ptr = arr; ptr <= end; ptr++) {
		destCoord.X = (ptr - arr) / size + ((tabl / size) * 5);
		destCoord.Y = (ptr - arr) % size + dis;
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << *ptr;
		cout.flush();
		Sleep(500);
		tabl++;
	}
}

void mupltiply_by_num(int* arr, int size, int num) {
	int* end = arr + size * size - 1;
	for (int* ptr = arr; ptr <= end; ptr++) {
		*ptr *= num;
	}
}

void spiral_init(int* arr, int size, int dis) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));
	int tabl = 0;
	int* end = arr + size * size - 1;
}

int main() {
	const int size = 4;
	int arr[size][size]{};
	init_matrix(*arr, size);
	int y_dis = 0;
	char action = 's';
	while (action != 'e') {
		cout << "\nMenu\n----------------\n1) Fill matrix\n";
		cout << "2) Build new matrix from old\n3) Sort matrix\n";
		cout << "4)Multiply every matrix elem on num\n";
		cout << "Choose action(e - quit): ";
		cin >> action;
		y_dis += 8;
		switch (action) {
			case '1':
			{
				char fill_act;
				cout << "1)Sneake fill\n2)Spiral fill\nChoose action:";
				cin >> fill_act;
				y_dis += 3;
				switch (fill_act) {
				case '1':
					{
					sneake_init(*arr, size, y_dis);
					y_dis += size;
					break;
					}
				case '2':
					{
					spiral_init(*arr, size, y_dis);
					y_dis += size;
					break;
					}
				}
				break;
			}
			case '2':
			{
				cout << ")))))))" << endl;
				y_dis++;
				break;
			}
			case '3':
			{
				cout << ")))))))" << endl;
				y_dis++;
				break;
			}
			case '4':
			{
				cout << "Enter number to multiply: ";
				int n;
				cin >> n;
				mupltiply_by_num(*arr, size, n);
				cout << "Done" << endl;
				y_dis += 2;
				break;
			}	
		}
	}
}