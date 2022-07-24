#include<iostream>
#include <string>
using namespace std;

struct node {
	int id;
	string name;
	double score;
	node* next;
};

struct linked_list {
	node* head;
	node* tail;
	int count;
};

bool isEmpty(linked_list list) { // 1
	if (list.head == NULL)
		return true;
	return false;
}

void addNode(linked_list& list) {			// 2
	node* temp = new node();
	cout << "id cua hoc sinh: " << endl;
	cin >> temp->id;
	cout << "nhap ten hoc sinh: " << endl;
	cin >> temp->name;
	cout << "nhap diem cua hoc sinh: " << endl;
	cin >> temp->score;
	if (list.head == NULL) {
		list.head = temp;
		list.tail = temp;
	}
	else {
		list.tail->next = temp;
		list.tail = temp;
	}
}
//begin search
void searchID(linked_list& list, int id) {
	node* temp = list.head;
	while (temp != NULL) {
		if (temp->id == id) {
			cout << temp->id << " " << temp->name << " " << temp->score << endl;
			break;
		}
		temp = temp->next;
	}
}

void searchScore(linked_list& list, double score) {
	node* temp = list.head;
	while (temp != NULL) {
		if (temp->score == score) {
			cout << temp->id << " " << temp->name << " " << temp->score << endl;
		}
		temp = temp->next;
	}
}
//end search

//begin deleteNode					4
void deleteNode(linked_list& list, int id) {
	node* temp = list.head->next;
	bool found = false;
	node* pre = list.head;
	while (temp != NULL && !found) {
		if (temp->id == id)
			found = true;
		else {
			pre = temp;
			temp = temp->next;
		}
	}
	if (found) {
		if (temp == list.head) {
			list.head = temp->next;
		}
		else
			pre->next = temp->next;
		delete temp;
		list.count--;
	}
	else
		cout << "khong tim duoc";
}
//end deleteNode

//begin showList
void showList(linked_list& list) {			//5
	node* temp = list.head;
	if (temp == NULL)
		cout << "danh sach rong";
	else {
		while (temp != NULL) {
			cout << temp->id << " " << temp->name << " " << temp->score << endl;
			temp = temp->next;
		}
	}
}
//end showList

//begin deleteList
void deleteList(linked_list& list) {
	node* temp;
	while (list.head->next != NULL) {
		temp = list.head->next;
		list.head->next = temp->next;
		delete temp;
	}
	list.count = 0;
}
//end deleteList
int main()
{
	linked_list list;
	list.head = NULL;
	list.count = 0;
	list.tail = NULL;
	int choice = 0;

	do
	{
		system("cls");
		cout << "cac tac vu cua danh sach: " << endl;
		cout << "1. kiem tra danh sach rong" << endl;
		cout << "2. them vao danh sach" << endl;
		cout << "3. tim kiem" << endl;
		cout << "4. xoa " << endl;
		cout << "5. hien thi danh sach" << endl;
		cout << "6. huy danh sach" << endl;
		cout << "your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1: // ktra danh sach rong
		{
			if (isEmpty)
				cout << "Danh sach rong" << endl;
			else
				cout << "Danh sach khong rong" << endl;
			system("pause");
			break;
		}

		case 2: // them vao danh sach
		{
			addNode(list);
			break;
		}

		case 3: // search
		{
			int option, id;
			double score;
			cout << "Nhap 1 de tim kiem theo id va 2 de tim kiem theo diem so: ";
			cin >> option;
			if (option == 1) {
				cout << "Nhap id can tim: ";
				cin >> id;
				searchID(list, id);
				cout << endl;
			}
			else {
				cout << "Nhap diem so can tim: ";
				cin >> score;
				searchScore(list, score);
				cout << endl;
			}
			system("pause");
			break;
		}

		case 4: //delete
		{
			int id;
			cout << "Nhap id can xoa: ";
			cin >> id;
			deleteNode(list, id);
			break;
		}

		case 5: // showList
		{
			showList(list);
			cout << endl;
			system("pause");
			break;
		}

		case 6: // delete List
		{
			deleteList(list);
			break;
		}
		}

	} while (choice != 0);
	return 0;
}