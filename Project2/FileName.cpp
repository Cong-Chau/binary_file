#include<iostream>
#include<fstream>

using namespace std;

struct Date {
	int ngay, thang, nam;
};

struct Node {
	Date data;
	Node* next;
};

Node* makeNode(Date x) {
	Node* tmp = new Node;
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

void addLast(Node*& day, Date x) {
	Node* tmp = makeNode(x);
	if (day = NULL)
		day = tmp;
	else {
		Node* last = day;
		while (last->next != NULL)
			last = last->next;
		last->next = tmp;
	}
}

void Input(Node*& day, int n) {
	for (int i = 0; i < n; i++) {
		Date x;
		cout << "Ngay thu " << i + 1 << ": \n";
		cout << " Ngay  : "; cin >> x.ngay;
		cout << " Thang : "; cin >> x.thang;
		cout << " Nam   : "; cin >> x.nam;
		cout << endl;
	}
}


int main() {
	Node* day;
	int n;
	cout << "So luong: "; cin >> n;
	Input(day, n);

	for (int i = 0; i < n; i++) {
		ofstream write("data.bin", ios::binary | ios::out);
		write.write((char*)day, n * sizeof(Node));
		write.close();
		day = day->next;
	}
	
	system("pause");
	return 0;
}