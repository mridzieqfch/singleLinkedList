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

// tambah tengah
void addMiddle(string nama, string nim, string jurusan, int posisi){
    if(posisi < 1 || posisi > countSingleLinkedList()){
        cout << "Posisi di luar jangkauan!" << endl;
    }else if(posisi == 1){
        cout << "Posisi bukan posisi tengah!" << endl;
    }else{
        newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->jurusan = jurusan;

        cur = head;
        int nomor = 1;
        while(nomor < posisi - 1){
            cur = cur->next;
            nomor++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
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

// remove middle
void removeMiddle(int posisi){
    if(posisi < 1 || posisi > countSingleLinkedList()){
        cout << "Posisi di luar jangkauan!" << endl;
    }else if(posisi == 1){
        cout << "Posisi bukan posisi tengah!" << endl;
    }else{
        int nomor = 1;
        cur = head;
        while(nomor <= posisi){
            if(nomor == posisi - 1) before = cur;
            if(nomor == posisi) del = cur;
            cur = cur->next;
            nomor++;
        }
        before->next = cur;
        delete del;
    }
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

// ubah data tengah
void changeMiddle(string nama, string nim, string jurusan, int posisi){
    if(posisi < 1 || posisi > countSingleLinkedList()){
        cout << "Posisi di luar jangkauan!" << endl;
    }else if(posisi == 1 || posisi == countSingleLinkedList()){
        cout << "Posisi bukan posisi tengah!" << endl;
    }else{
        cur = head;
        int nomor = 1;
        while(nomor < posisi){
            cur = cur->next;
            nomor++;
        }
        cur->nama = nama;
        cur->nim = nim;
        cur->jurusan = jurusan;
    }
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

    addMiddle("Dewi", "23111004", "Data Science", 2);
    printSingleLinkedList();

    removeFirst();
    printSingleLinkedList();

    removeLast();
    printSingleLinkedList();

    changeFirst("Eka", "23111005", "Teknik Informatika");
    printSingleLinkedList();

    addLast("Fajar", "23111006", "Sistem Informasi");
    printSingleLinkedList();

    changeMiddle("Gita", "23111007", "Teknik Komputer", 2);
    printSingleLinkedList();

    removeMiddle(2);
    printSingleLinkedList();

    return 0;
}