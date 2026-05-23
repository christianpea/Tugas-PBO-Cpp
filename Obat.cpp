#include "Obat.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

Obat::Obat()
    : id(0), namaObat(""), kategori(""), satuan("tablet"),
      stok(0), stokMinimum(5), harga(0.0) {}

Obat::Obat(int id, const string& namaObat, const string& kategori,
           const string& satuan, int stok, int stokMinimum, double harga)
    : id(id), kategori(kategori), satuan(satuan), stok(stok),
      stokMinimum(stokMinimum) {
    setNamaObat(namaObat);
    setHarga(harga);
    if (stok < 0) throw invalid_argument("Stok tidak boleh negatif.");
}

Obat::~Obat() {}

int    Obat::getId() const           { return id; }
string Obat::getNamaObat() const     { return namaObat; }
string Obat::getKategori() const     { return kategori; }
string Obat::getSatuan() const       { return satuan; }
int    Obat::getStok() const         { return stok; }
int    Obat::getStokMinimum() const  { return stokMinimum; }
double Obat::getHarga() const        { return harga; }
bool   Obat::isStokMenurun() const   { return stok <= stokMinimum; }

void Obat::setNamaObat(const string& nama) {
    if (nama.empty()) throw invalid_argument("Nama obat tidak boleh kosong.");
    this->namaObat = nama;
}

void Obat::setHarga(double harga) {
    if (harga < 0) throw invalid_argument("Harga tidak boleh negatif.");
    this->harga = harga;
}

void Obat::setStokMinimum(int min) {
    if (min < 0) throw invalid_argument("Stok minimum tidak boleh negatif.");
    this->stokMinimum = min;
}

void Obat::tambahStok(int jumlah) {
    if (jumlah <= 0) throw invalid_argument("Jumlah tambah stok harus positif.");
    stok += jumlah;
}

bool Obat::kurangiStok(int jumlah) {
    if (jumlah <= 0) throw invalid_argument("Jumlah kurang stok harus positif.");
    if (stok < jumlah) return false;
    stok -= jumlah;
    return true;
}

void Obat::tampilkanInfo() const {
    cout << left;
    cout << "  ID      : " << id << endl;
    cout << "  Nama    : " << namaObat << endl;
    cout << "  Kategori: " << kategori << endl;
    cout << "  Satuan  : " << satuan << endl;
    cout << "  Stok    : " << stok
         << (isStokMenurun() ? "  [!! STOK MENIPIS !!]" : "") << endl;
    cout << "  Harga   : Rp " << fixed << setprecision(0) << harga << endl;
}
