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

void sneake_init(int* arr, int size) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int tabl = 0;
	int* end = arr + size * size - 1;
	for (int* ptr = arr; ptr <= end; ptr++) {
		destCoord.X = (ptr - arr) / size + ((tabl / size) * 5);
		destCoord.Y = (ptr - arr) % size;
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << *ptr;
		cout.flush();
		Sleep(300);
		tabl++;
	}
	destCoord.X = 0;
	destCoord.Y = size;
	SetConsoleCursorPosition(hStdout, destCoord);
}

void standart_init(int* arr, int size) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int tabl = 0;
	int* end = arr + size * size - 1;
	for (int* ptr = arr; ptr <= end; ptr++) {
		destCoord.X = (ptr - arr) % size + ((tabl % size) * 5);
		destCoord.Y = (ptr - arr) / size;
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << *ptr;
		cout.flush();
		Sleep(300);
		tabl++;
	}
	destCoord.X = 0;
	destCoord.Y = size;
	SetConsoleCursorPosition(hStdout, destCoord);
}

void diagonal_transpon(int* arr, int size){
	int mid = (size * size / 2) - 1;
	int mid_row = size / 2;
	for (int i=0; i <= mid; i++) {
		if(i < mid_row){
			swap(*(arr + i), *(arr + (size / 2 * size) + i + size / 2));
			}
		if(i >= mid_row){
			swap(*(arr + i), *(arr + (size / 2 * size) + i - size / 2));
			}
		if ((i + 1) % size == 0){
			mid_row += size;
		}
	}
}

void vertical_transpon(int* arr, int size){
	int cur_col = 1;
	int start_pos = 0;
	while (cur_col <= int(size / 2))
	{
		for(int i=start_pos; i < size * size; i+=size){
			swap(*(arr + i), *(arr + (int(size / 2)) + i));
		}
		cur_col++;
		start_pos++;
	}	
}

void curcle_transpon(int* arr, int size){
	int mid_col = (size / 2), cur_row = 1;
	int start_pos = 0;
	while (cur_row <= int(size / 2))
	{
		for(int i=start_pos; i < (mid_col); i++){
			swap(*(arr + i), *(arr + (int(size / 2)) + i));
			swap(*(arr + i), *(arr + (size / 2 * size) + i + size / 2));
			swap(*(arr + i), *(arr + (size * size / 2) + i));
		}
		cur_row++;
		mid_col += size;
		start_pos += size;
	}	
}

void horizontal_transpon(int* arr, int size){
	int mid = (size * size / 2) - 1;
	for (int i=0; i <= mid; i++) {
		swap(*(arr + i), *(arr + (size * size / 2) + i));
	}
}

void operation_with_matrix(int* arr, int size, int num, char action) {
	int* end = arr + size * size - 1;
	for (int* ptr = arr; ptr <= end; ptr++) {
		switch(action){
			case '+':
			*ptr += num;
			break;
			case '*':
			*ptr *= num;
			break;
			case '-':
			*ptr += num;
			break;
			case '/':
			*ptr /= num;
			break;
			default:
			break;
		}
	}
}


void spiral_init(int* arr, int size) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int* ptr = arr;
	int cur_x = -1, cur_y = 0;
	int tabl = -1;
	int left = 0, right = size - 1;
    int top = 0, bottom = size - 1;
	while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
			tabl++;
			cur_x++;
            destCoord.X = cur_x + ((tabl % size) * 5);
		    destCoord.Y = cur_y;
		    SetConsoleCursorPosition(hStdout, destCoord);
		    cout << *ptr;
		    cout.flush();
		    Sleep(300);
		    ptr++;
        }
		top++;

        for (int i = top; i <= bottom; i++) {
			destCoord.X = right + ((tabl % size) * 5);
		   	destCoord.Y = cur_y % size + 1;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *ptr;
			cout.flush();
			Sleep(300);
			cur_y++;
		   	ptr++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
				tabl--;
				cur_x--;
                destCoord.X = cur_x + ((tabl % size) * 5);
		   		destCoord.Y = bottom;
				SetConsoleCursorPosition(hStdout, destCoord);
				cout << *ptr;
				cout.flush();
				Sleep(300);
		   		ptr++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
				cur_y--;
                destCoord.X = left + (tabl * 5);
		   		destCoord.Y = cur_y;
				SetConsoleCursorPosition(hStdout, destCoord);
				cout << *ptr;
				cout.flush();
				Sleep(300);
		   		ptr++;
            }
            left++;
        }
	}
	destCoord.X = 0;
	destCoord.Y = size;
	SetConsoleCursorPosition(hStdout, destCoord);
}
int partition(int* arr, int low, int high) {
    int pivot = *(arr + high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (*(arr + j) <= pivot) {
            i++; 
            swap(*(arr + i), *(arr + j));
        }
    }
    swap(*(arr + i + 1), *(arr + high)); 
    return i + 1; 
}

void determinant_of_matrix(int* arr, int size){
	int determn = 0; 
	for(int i = 0; i < size; i++){
		if (i == 0){
			determn += *(arr + i) * *(arr + i + size + 1) * *(arr + i + (size * 2)+ 2);
			determn -= *(arr + i) * *(arr + i + size + 2) * *(arr + i + (size * 2)+ 1);
		}
		if (i == 1){
			determn += *(arr + i) * *(arr + i + size + 1) * *(arr + i + (size * 2) - 1);
			determn -= *(arr + i) * *(arr + i + size - 1) * *(arr + i + (size * 2) + 1);
		}
		if (i == 2){
			determn += *(arr + i) * *(arr + i + size - 2) * *(arr + i + (size * 2) - 1);
			determn -= *(arr + i) * *(arr + i + size - 1) * *(arr + i + (size * 2) - 2);
		}
	}
	cout << "Determinant = " << determn << endl;
}

void quicksort(int* arr, int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
	srand(time(0));
	int size;
	cout << "Enter the size of matrix(even number): ";
	cin >> size;
	int arr[size][size]{}; 
	init_matrix(*arr, size);
	char action = 's';
	while (action != 'e') {
		cout << "Menu\n----------------\n1) Fill matrix" << endl;
		cout << "2) Build new matrix from old\n3) Sort matrix" << endl;
		cout << "4)Operation with matrix\n5)IDZ" << endl;
		cout << "Choose action(e - quit): ";
		cin >> action;
		switch (action) {
			case '1':
			{
				char fill_act;
				cout << "1)Sneake fill\n2)Spiral fill\n3)Standart fill\nChoose action:";
				cin >> fill_act;
				switch (fill_act) {
				case '1':
					{
					system("cls");
					sneake_init(*arr, size);
					break;
					}
				case '2':
					{
					system("cls");
					spiral_init(*arr, size);
					break;
					}
				
				case '3':
					{
					system("cls");
					standart_init(*arr, size);
					break;
					}
				default:
				break;
				}
				break;
			}
			case '2':
			{
				char transp_act;
				cout << "1)Circle\n2)Diagonal\n3)Vertical\n4)Horizontal\nChoose action: ";
				cin>> transp_act;
				switch (transp_act)
				{
				case '1':
					curcle_transpon(*arr, size);
					break;
				case '2':
					diagonal_transpon(*arr, size);
					break;
				case '3':
					vertical_transpon(*arr, size);
					break;
				case '4':
					horizontal_transpon(*arr, size);
					break;
				default:
					break;
				}
				cout << "Done" << endl;
				break;
			}
			case '3':
			{
				quicksort(*arr, 0, size * size - 1);
				cout << "Array sorted" << endl;
				break;
			}
			case '4':
			{
				cout << "Enter number: ";
				int n;
				cin >> n;
				cout << "1)Multiply\n2)Add\n3)Subtract\n4)Divide\nChoose action: ";
				char operation;
				cin >> operation;
				switch (operation)
				{
				case '1':
					operation_with_matrix(*arr, size, n, '*');
					break;
				case '2':
					operation_with_matrix(*arr, size, n, '+');
					break;
				case '3':
					operation_with_matrix(*arr, size, n, '-');
					break;
				case '4':
					operation_with_matrix(*arr, size, n, '/');
					break;
				default:
					break;
				}
				cout << "Done" << endl;
				break;
			}
			case '5':{
				int idz_arr[3][3]{};
				init_matrix(*arr, 3);
				system("cls");
				standart_init(*arr, 3);
				determinant_of_matrix(*arr, 3);

			}
			default:
				break;	
		}
	}
}
