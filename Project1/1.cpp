#include<iostream>
#include<fstream>

using namespace std;

struct Date {
	int ngay, thang, nam;
};



int main() {
	fstream f;
	Date* date;
	int n;
	cout << "Nhap so luong: ";
	cin >> n;
	date = new Date[n];
	Date* date2 = new Date[n];
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin ngay thu " << i + 1 << ": " << endl;
		cout << "Nhap ngay: ";
		cin >> date[i].ngay;
		cout << "Nhap thang: ";
		cin >> date[i].thang;
		cout << "Nhap nam: ";
		cin >> date[i].nam;
	}
	f.open("date.bin", ios::binary | ios::out);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return 0;
	}
	f.write((char*)date, n * sizeof(Date));
	f.close();


	fstream f1;
	f1.open("date.bin", ios::binary | ios::in);
	if (f1.fail()) {
		cout << "LOi" << endl;
		return 0;
	}
	f1.read((char*)date2, n * sizeof(Date));
	f1.close();


	Date max = date[0];
	for (int i = 1; i < n; i++) {
		if (date[i].nam > max.nam)
			max = date[i];
		if (date[i].nam == max.nam) {
			if (date[i].thang > max.thang)
				max = date[i];
			if (date[i].thang == max.thang) {
				if (date[i].ngay > max.ngay)
					max = date[i];
			}
		}
	}
	cout << "Ngay lon nhat: " << max.ngay << "/" << max.thang << "/" << max.nam;
}