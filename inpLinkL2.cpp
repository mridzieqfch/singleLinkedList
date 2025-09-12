#include <iostream>
using namespace std;

// deklarasi single linked list
struct Mahasiswa {
  string nama, nim, jurusan;
  Mahasiswa *next;
};

// pointer global
Mahasiswa *head, *tail, *cur, *newNode, *del, *before;
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
  jumlah = 0; // reset jumlah agar tidak double count
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

// tambah tengah
void tambahTengah(string nama, string nim, string jurusan, int posisi){
  newNode = new Mahasiswa();
  newNode->nama = nama;
  newNode->nim = nim;
  newNode->jurusan = jurusan;

  cur = head;
  int no = 1;
  while(no < posisi - 1){
    cur =cur->next;
    no++;
  }
  newNode->next = cur->next;
  cur->next = newNode;
}

// hapus first
void hapusAwal(){
  del = head;
  head = head->next;
  delete del;
}

// hapus last
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

// hapus tengah
void hapusTengah(int posisi){
  cur = head;
  int no = 1;
  while(no <= posisi){
    if(no == posisi - 1){
      before = cur;
    }
    if(no == posisi){
      del = cur;
    }
    cur = cur->next;
    no++;
  }
  before->next = cur;
  delete del;
}

// ubah data pertama
void ubahAwal(string nama, string nim, string jurusan){
  head->nama = nama;
  head->nim = nim;
  head->jurusan = jurusan;
}

// ubah tengah
void ubahTengah(string nama, string nim, string jurusan, int posisi){
  cur = head;
  int no = 1;
  while (no < posisi){
    cur = cur->next;
    no++;
  }
  cur->nama = nama;
  cur->nim = nim;
  cur->jurusan = jurusan;
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
  int pilihan, posisi;

  system("clear");

  do {
    cout << "=============================" << endl;
    cout << "   Single Linked List Menu   " << endl;
    cout << "=============================" << endl;
    cout << "1. Buat Linked List" << endl;
    cout << "2. Tambah Data di Awal" << endl;
    cout << "3. Tambah Data di Akhir" << endl;
    cout << "4. Tambah Data di Tengah" << endl;
    cout << "5. Hapus Data di Awal" << endl;
    cout << "6. Hapus Data di Akhir" << endl;
    cout << "7. Hapus Data di Tengah" << endl;
    cout << "8. Ubah Data Awal" << endl;
    cout << "9. Ubah Data Tengah" << endl;
    cout << "10. Ubah Data Akhir" << endl;
    cout << "11. Print Data" << endl;
    cout << "12. Keluar" << endl;
    cout << "=============================" << endl;
    cout << "Masukkan pilihan (1-12): ";
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
        cout << "Masukkan Posisi : "; cin >> posisi; cin.ignore();
        if(posisi < 1 || posisi > hitungLinkL()){
          cout << "Posisi diluar Jangkauan!" << endl;
        } else if(posisi == 1){
          cout << "Bukan Posisi Tengah!" << endl;
        } else{
          inputData(nama, nim, jurusan);
          tambahTengah(nama, nim, jurusan, posisi);
          cout << "\nData berhasil ditambahkan di tengah!\n" << endl;
        }
        break;
      case 5:
        if (head == NULL) {
          cout << "Linked list kosong!\n" << endl;
        } else {
          hapusAwal();
          cout << "\nData di awal berhasil dihapus!\n" << endl;
        }
        break;
      case 6:
        if (head == NULL) {
          cout << "Linked list kosong!\n" << endl;
        } else {
          hapusAkhir();
          cout << "\nData di akhir berhasil dihapus!\n" << endl;
        }
        break;
      case 7:
        cout << "Masukkan Posisi : "; cin >> posisi; cin.ignore();
        if(posisi < 1 || posisi > hitungLinkL()){
          cout << "Posisi diluar Jangkauan!" << endl;
        } else if(posisi == 1 || posisi == hitungLinkL()){
          cout << "Bukan Posisi Tengah!" << endl;
        } else{
          hapusTengah(posisi);
          cout << "\nData di tengah berhasil dihapus!\n" << endl;
        }
        break;
      case 8:
        inputData(nama, nim, jurusan);
        ubahAwal(nama, nim, jurusan);
        cout << "\nData di awal berhasil diubah!\n" << endl;
        break;
      case 9:
        cout << "Masukkan Posisi : "; cin >> posisi; cin.ignore();
        if(posisi < 1 || posisi > hitungLinkL()){
          cout << "Posisi diluar Jangkauan!" << endl;
        } else if(posisi == 1 || posisi == hitungLinkL()){
          cout << "Bukan Posisi Tengah!" << endl;
        } else{
          inputData(nama, nim, jurusan);
          ubahTengah(nama, nim, jurusan, posisi);
          cout << "\nData di tengah berhasil diubah!\n" << endl;
        }
        break;
      case 10:
        inputData(nama, nim, jurusan);
        ubahAkhir(nama, nim, jurusan);
        cout << "\nData di akhir berhasil diubah!\n" << endl;
        break;
      case 11:
        printLinkL();
        break;
      case 12:
        cout << "Keluar dari program." << endl;
        return 0;
      default:
        cout << "Pilihan tidak valid. Silakan coba lagi.\n" << endl;
    }

    cout << "Kembali ke menu utama? (y/n): ";
    cin >> ulang; cin.ignore(); cout << endl;
    if (ulang != "y" && ulang != "Y") {
      cout << "=============================" << endl;
      cout << "        Terima Kasih" << endl;
      cout << "=============================" << endl;
      break;
    }
    system("clear");

  } while (true);

  return 0;
}