#include <iostream>
using namespace std;

// deklarasi single linked list
struct Mahasiswa {
    string nama, nim, jurusan;
    Mahasiswa *next;
};

// pointer global
Mahasiswa *head, *tail, *cur, *newNode, *del;
int jumlah = 0;

void inputData(string &nama, string &nim, string &jurusan) {
  cout << "Masukkan nama\t: "; getline(cin, nama);
  cout << "Masukkan NIM\t: "; getline(cin, nim);
  cout << "Masukkan jurusan: "; getline(cin, jurusan);
}

// buat single linked list
void buatLinkL(string nama, string nim, string jurusan){
  head = new Mahasiswa();
  head->nama = nama;
  head->nim = nim;
  head->jurusan = jurusan;
  head->next = NULL;
  tail = head;
}

// hitung node
int hitungLinkL(){
  cur = head;
  while(cur != NULL){
    jumlah++;
    cur = cur->next;
  }
  return jumlah;
}

// tambah awal
void tambahAwal(string nama, string nim, string jurusan){
  newNode = new Mahasiswa();
  newNode->nama = nama;
  newNode->nim = nim;
  newNode->jurusan = jurusan;
  newNode->next = head;
  head = newNode;
}

// tambah akhir
void tambahAkhir(string nama, string nim, string jurusan){
  newNode = new Mahasiswa();
  newNode->nama = nama;
  newNode->nim = nim;
  newNode->jurusan = jurusan;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

// remove first
void hapusAwal(){
  del = head;
  head = head->next;
  delete del;
}

// remove last
void hapusAkhir(){
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
void ubahAwal(string nama, string nim, string jurusan){
  head->nama = nama;
  head->nim = nim;
  head->jurusan = jurusan;
}

// ubah data terakhir
void ubahAkhir(string nama, string nim, string jurusan){
  tail->nama = nama;
  tail->nim = nim;
  tail->jurusan = jurusan;
}

// print data
void printLinkL(){
  cout << "Jumlah data: " << hitungLinkL() << endl;
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
  string nama, nim, jurusan, ulang;
  int pilihan;

  system("clear");

  do {
    cout << "=============================" << endl;
    cout << "   Single Linked List Menu   " << endl;
    cout << "=============================" << endl;
    cout << "1. Buat Linked List" << endl;
    cout << "2. Tambah Data di Awal" << endl;
    cout << "3. Tambah Data di Akhir" << endl;
    cout << "4. Hapus Data di Awal" << endl;
    cout << "5. Hapus Data di Akhir" << endl;
    cout << "6. Ubah Data Awal" << endl;
    cout << "7. Ubah Data Akhir" << endl;
    cout << "8. Print Data" << endl;
    cout << "9. Keluar" << endl;
    cout << "=============================" << endl;
    cout << "Masukkan pilihan (1-9): ";
    cin >> pilihan; cin.ignore(); cout << endl;

    switch(pilihan) {
      case 1:
        inputData(nama, nim, jurusan);
        buatLinkL(nama, nim, jurusan);
        cout << "\nLinked list berhasil dibuat!\n" << endl;
        break;
      case 2:
        inputData(nama, nim, jurusan);
        tambahAwal(nama, nim, jurusan);
        cout << "\nData berhasil ditambahkan di awal!\n" << endl;
        break;
      case 3:
        inputData(nama, nim, jurusan);
        tambahAkhir(nama, nim, jurusan);
        cout << "\nData berhasil ditambahkan di akhir!\n" << endl;
        break;
      case 4:
        if (head == NULL) {
          cout << "Linked list kosong, tidak ada data untuk dihapus!\n" << endl;
          break;
        } else if (head == tail) {
          hapusAwal();
          head = NULL;
          tail = NULL;
          cout << "\nData di awal berhasil dihapus! Linked list sekarang kosong.\n" << endl;
          break;
        } else if (head != NULL) {
          hapusAwal();
          cout << "\nData di awal berhasil dihapus!\n" << endl;
          break;
        }
      case 5:
        if (head == NULL) {
          cout << "Linked list kosong, tidak ada data untuk dihapus!\n" << endl;
          break;
        } else if (head == tail) {
          hapusAkhir();
          head = NULL;
          tail = NULL;
          cout << "\nData di akhir berhasil dihapus! Linked list sekarang kosong.\n" << endl;
          break;
        } else if (head != NULL) {
          hapusAkhir();
          cout << "\nData di akhir berhasil dihapus!\n" << endl;
          break;
        }
      case 6:
        inputData(nama, nim, jurusan);
        ubahAwal(nama, nim, jurusan);
        cout << "\nData di awal berhasil diubah!\n" << endl;
        break;
      case 7:
        inputData(nama, nim, jurusan);
        ubahAkhir(nama, nim, jurusan);
        cout << "\nData di akhir berhasil diubah!\n" << endl;
        break;
      case 8:
        printLinkL();
        break;
      case 9:
        cout << "Keluar dari program." << endl;
        break;
      default:
        cout << "Pilihan tidak valid. Silakan coba lagi.\n" << endl;
    }
    if (pilihan != 9) {
      cout << "Kembali ke menu utama? (y/n): ";
      cin >> ulang; cin.ignore(); cout << endl;
      if (ulang != "y" && ulang != "Y") {
        cout << "Keluar dari program." << endl;
        cout << "=============================" << endl;
        cout << "        Terima Kasih" << endl;
        cout << "=============================" << endl;
        break;
      }
      system("clear");
    }
  } while (pilihan != 9);

  return 0;
}