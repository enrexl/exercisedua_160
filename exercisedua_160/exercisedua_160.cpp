#include <iostream>
#include<vector>

#include "buku.h"
using namespace std;

class pengarang {
public:
    string nama;
    vector<buku*> daftar_buku;
    vector<penerbit*> daftar_penerbit;

    pengarang(string pNama) :nama(pNama) {
        
    }

    void tambahBuku(buku*);
    void cetakBuku();
    void cetakPenerbit();
};

class penerbit {
public:
    string nama;
    vector<pengarang*> daftar_pengarang;

    penerbit(string pNama) :nama(pNama) {

    }
    void tambahPengarang(pengarang*);
    void cetakPengarang();
    
};

void buku::tambahPengarang(pengarang* pPengarang) {
    daftar_pengarang.push_back(pPengarang);
}
void buku::cetakPengarang() {
    cout << "Daftar Buku yang ditulis oleh \"" << this->nama << "\":\n";
    for (auto& a : daftar_pengarang) {
        cout << a->nama << "\n";
    }
    cout << endl;
}
void pengarang::tambahBuku(buku* pBuku) {
    daftar_buku.push_back(pBuku);
    pBuku->tambahPengarang(this);
}
void pengarang::cetakBuku() {
    cout << "Daftar Buku yang dikarang \"" << this->nama << "\":\n";
    for (auto& a : daftar_buku) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

void penerbit::tambahPengarang(pengarang* pPengarang) {
    daftar_pengarang.push_back(pPengarang);
   
}

void penerbit::cetakPengarang() {
    cout << "Daftar Pengarang pada penerbit \"" << this->nama << "\":\n";
    for (auto& a : daftar_pengarang) {
        cout << a->nama << "\n";
    }
    cout << endl;
}


void pengarang::cetakPenerbit() {
    cout << "Daftar Penerbit yang diikuti \"" << this->nama << "\":\n";
    for (auto& a : daftar_penerbit) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main()
{
    pengarang* varPengarang1 = new pengarang("Giga");
    pengarang* varPengarang2 = new pengarang("Joko");
    pengarang* varPengarang3 = new pengarang("Lia");
    pengarang* varPengarang4 = new pengarang("Asroni");
    penerbit* varPenerbit1 = new penerbit("Gama Press");
    penerbit* varPenerbit2 = new penerbit("Intan Pariwara");
    buku* varBuku1 = new buku("Matematika ");
    buku* varBuku2 = new buku("Matematika 1");
    buku* varBuku3 = new buku("Fisika");
    buku* varBuku4 = new buku("Algoritma");
    buku* varBuku5 = new buku("Basisdata");
    buku* varBuku6 = new buku("Dasar Pemrograman");

    varPengarang2->tambahBuku(varBuku3);
    varPengarang2->tambahBuku(varBuku4);
    varPengarang3->tambahBuku(varBuku5);
    varPengarang4->tambahBuku(varBuku6);
    varPengarang1->tambahBuku(varBuku1);
    varPengarang1->tambahBuku(varBuku2);

    varPenerbit1->tambahPengarang(varPengarang2);
    varPenerbit1->tambahPengarang(varPengarang3);
    varPenerbit1->tambahPengarang(varPengarang1);
    varPenerbit2->tambahPengarang(varPengarang4);
    varPenerbit2->tambahPengarang(varPengarang1);

    varPenerbit1->cetakPengarang();
    varPenerbit2->cetakPengarang();
    varPengarang1->cetakPenerbit(); //giga
    varPengarang1->cetakBuku();
    varPengarang2->cetakBuku();
    varPengarang3->cetakBuku();
    varPengarang4->cetakBuku();

};
