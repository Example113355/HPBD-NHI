#include<iostream>
#include <stdlib.h>
#include <time.h>  
using namespace std;

int findMin(int* arr, int size) {
	int min = *arr;
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}
int main(){
	int difi, key, guess, count = 0;
	int idx = 0;
	bool end = true;
	cout << "Tim so ma he thong da chon trong khoang tuy vao muc do nguoi choi chon." << endl << "chon do kho:" << endl;
	cout << "1. trong khoang 10.\n" << "2. trong khoang 20.\n" << "3. trong khoang 50\n"<<"Do kho ban chon la: ";
	cin >> difi;
	int top_1[20], top_2[20], top_3[20];
	if (difi > 3 || difi <= 0) {
		cout << "Do kho khong hop le. Vui long nhap lai.";
	}
	srand(time(NULL));
	// khoi tao key
	while (end) {
		if (difi == 1) {
			key = rand() % 10 + 1;
		}
		else if (difi == 2) {
			key = rand() % 20 + 1;
		}
		else {
			key = rand() % 50 + 1;
		}
		while (true) {
			cout << "Nhap so ban doan: ";
			cin >> guess;
			if (guess == key) {
				cout << "Chuc mung ban da doan dung.\n";
				count++;
				cout << "So lan nhap ban da thuc hien: " << count << endl;
				break;
			}
			else if (guess > key) {
				cout << "So ban doan lon hon so cua he thong.\n";
				count++;
				cout << "So lan nhap ban da thuc hien: " << count << endl;
				continue;
			}
			else {
				cout << "So ban chon be hon so cua he thong.\n";
				count++;
				cout << "So lan nhap ban da thuc hien: " << count << endl;
				continue;
			}
		}
		if (difi == 1) {
			top_1[idx] = count;
			idx++;
			cout << "Ki luc cua ban o do kho nay la: " << findMin(top_1, idx)<<endl;
		}
		else if (difi == 2) {
			top_2[idx] = count;
			idx++;
			cout << "Ki luc cua ban o do kho nay la: " << findMin(top_2, idx)<<endl;
		}
		else {
			top_3[idx] = count;
			idx++;
			cout << "Ki luc cua ban o do kho nay la: " << findMin(top_3, idx)<<endl;
		}
		count = 0;
		cout << "Ban co muon choi tiep khong? (Nhap 1 neu co va 0 neu ban muon dung.) ";
		cin >> end;
	}
	system("pause");
}