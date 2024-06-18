#include <iostream>
using namespace std;

struct Buku
{
	string nama;
	int tahun;
};

struct Node
{
	Buku data;
	Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void isEmpty()
{
	if (head == NULL)
	{
		cout << "List kosong" << endl;
	}
	else
	{
		cout << "List tidak kosong" << endl;
	}
}

void tambahDepan(Buku data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void tambahBelakang(Buku data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

void tambahTengah(Buku data, int posisi)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	Node* temp = head;
	for (int i = 1; i < posisi - 1; i++)
	{
		temp = temp->next;
	}

	newNode->next = temp->next;
	temp->next = newNode;
}

void hapusDepan()
{
	Node* temp = head;
	head = head->next;
	delete temp;
}

void hapusBelakang()
{
	Node* temp = head;
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	delete tail;
	tail = temp;
	tail->next = NULL;
}

void hapusTengah(int posisi)
{
	Node* temp = head;
	for (int i = 1; i < posisi - 1; i++)
	{
		temp = temp->next;
	}

	Node* hapus = temp->next;
	temp->next = hapus->next;
	delete hapus;
}

void tampil()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << "Nama Buku: " << temp->data.nama << endl;
		cout << "Tahun Terbit: " << temp->data.tahun << endl;
		cout << endl;
		temp = temp->next;
	}
}

int main()
{
	do
	{
		cout << "List Buku" << endl;
		cout << "====================" << endl;
		cout << "1. Tambah Depan" << endl;
		cout << "2. Tambah Belakang" << endl;
		cout << "3. Tambah Tengah" << endl;
		cout << "4. Hapus Depan" << endl;
		cout << "5. Hapus Belakang" << endl;
		cout << "6. Hapus Tengah" << endl;
		cout << "7. Tampil" << endl;
		cout << "Masukkan pilihan: ";
		int pilihan;
		cin >> pilihan;
		if (pilihan == 1)
		{
			Buku data;
			cout << "Masukkan nama buku: ";
			cin >> data.nama;
			cout << "Masukkan tahun terbit: ";
			cin >> data.tahun;
			tambahDepan(data);
		}
		else if (pilihan == 2)
		{
			Buku data;
			cout << "Masukkan nama buku: ";
			cin >> data.nama;
			cout << "Masukkan tahun terbit: ";
			cin >> data.tahun;
			tambahBelakang(data);
		}
		else if (pilihan == 3)
		{
			Buku data;
			cout << "Masukkan nama buku: ";
			cin >> data.nama;
			cout << "Masukkan tahun terbit: ";
			cin >> data.tahun;
			int posisi;
			cout << "Masukkan posisi: ";
			cin >> posisi;
			tambahTengah(data, posisi);
		}
		else if (pilihan == 4)
		{
			hapusDepan();
		}
		else if (pilihan == 5)
		{
			hapusBelakang();
		}
		else if (pilihan == 6)
		{
			int posisi;
			cout << "Masukkan posisi: ";
			cin >> posisi;
			hapusTengah(posisi);
		}
		else if (pilihan == 7)
		{
			tampil();
		}
	} while (true);
	
}