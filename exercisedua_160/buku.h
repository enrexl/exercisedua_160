#ifndef BUKU_H
#define BUKU_H
#include <string>
#include <vector>
using namespace std;

class pengarang;
class buku {
public:
    string nama;
    vector<pengarang*> daftar_pengarang;
    buku(string pNama) :nama(pNama) {

    }
    void tambahPengarang(pengarang*);
    void cetakPengarang();
};
#endif // !BUKU_H
