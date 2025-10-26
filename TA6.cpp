#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
    int kodeProduk;
    string namaProduk;
    Node* next;
};

void initTable(Node* table[]) {
    for (int i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }
}

int hashFunction(int kodeProduk) {
    return (kodeProduk % SIZE + SIZE) % SIZE;
}

void insert(Node* table[], int kodeProduk, string namaProduk) {
    int index = hashFunction(kodeProduk);
    Node* cur = table[index];

    while (cur != NULL) {
        if (cur->kodeProduk == kodeProduk) {
            cur->namaProduk = namaProduk;
            return;
        }
        cur = cur->next;
    }

    Node* baru = new Node;
    baru->kodeProduk = kodeProduk;
    baru->namaProduk = namaProduk;
    baru->next = table[index];
    table[index] = baru;
}

void display(Node* table[]) {
    cout << "\nDaftar Produk:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        Node* tmp = table[i];
        while (tmp != NULL) {
            cout << "[Kode: " << tmp->kodeProduk << ", Produk: " << tmp->namaProduk << "] -> ";
            tmp = tmp->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    Node* table[SIZE];
    initTable(table);

    int jumlah;
    cout << "Masukkan jumlah data produk: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        int kode;
        string nama;
        cout << "Masukkan kode produk ke-" << i + 1 << ": ";
        cin >> kode;
        cout << "Masukkan nama produk: ";
        cin >> nama;
        insert(table, kode, nama);
    }

    display(table);
    return 0;
}