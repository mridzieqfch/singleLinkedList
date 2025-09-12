#include <iostream>
using namespace std;

// deklarasi single linked list
struct Mahasiswa {
    string nama, nim, jurusan;
    Mahasiswa *next;
};

// pointer global
Mahasiswa *head, *tail, *cur, *newNode, *del, *before;

// create single linked list
void createSingleLinkedList(string nama, string nim, string jurusan){
    head = new Mahasiswa();
    head->nama = nama;
    head->nim = nim;
    head->jurusan = jurusan;
    head->next = NULL;
    tail = head;
}

// count node
int countSingleLinkedList(){
    cur = head;
    int jumlah = 0;
    while(cur != NULL){
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

// tambah awal
void addFirst(string nama, string nim, string jurusan){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->jurusan = jurusan;
    newNode->next = head;
    head = newNode;
}

// tambah akhir
void addLast(string nama, string nim, string jurusan){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->jurusan = jurusan;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

// remove first
void removeFirst(){
    del = head;
    head = head->next;
    delete del;
}

// remove last
void removeLast(){
    del = tail;
    cur = head;
    while(cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

// ubah data pertama
void changeFirst(string nama, string nim, string jurusan){
    head->nama = nama;
    head->nim = nim;
    head->jurusan = jurusan;
}

// ubah data terakhir
void changeLast(string nama, string nim, string jurusan){
    tail->nama = nama;
    tail->nim = nim;
    tail->jurusan = jurusan;
}

// print data
void printSingleLinkedList(){
    cout << "Jumlah data: " << countSingleLinkedList() << endl;
    cout << "=====================" << endl;
    cur = head;
    int i = 1;
    while(cur != NULL){
        cout << "Data ke-" << i << endl;
        cout << "Nama    : " << cur->nama << endl;
        cout << "NIM     : " << cur->nim << endl;
        cout << "Jurusan : " << cur->jurusan << endl;
        cout << "---------------------" << endl;
        cur = cur->next;
        i++;
    }
    cout << "=====================\n" << endl;
}

int main(){
    createSingleLinkedList("Andi", "23111001", "Teknik Informatika");
    printSingleLinkedList();

    addFirst("Budi", "23111002", "Sistem Informasi");
    printSingleLinkedList();

    addLast("Citra", "23111003", "Teknik Komputer");
    printSingleLinkedList();

    removeFirst();
    printSingleLinkedList();

    removeLast();
    printSingleLinkedList();

    changeFirst("Eka", "23111005", "Teknik Informatika");
    printSingleLinkedList();

    addLast("Fajar", "23111006", "Sistem Informasi");
    printSingleLinkedList();

    return 0;
}