#ifndef OBAT_H
#define OBAT_H

#include <string>
using namespace std;

// Class Obat - mengelola data dan stok obat
class Obat {
private:
    int id;
    string namaObat;
    string kategori;       // misal: antibiotik, analgesik, antasida, dll.
    string satuan;         // tablet, kapsul, botol, dll.
    int stok;
    int stokMinimum;       // batas minimum sebelum peringatan
    double harga;

public:
    Obat();
    Obat(int id, const string& namaObat, const string& kategori,
         const string& satuan, int stok, int stokMinimum, double harga);
    ~Obat();

    // Getter
    int getId() const;
    string getNamaObat() const;
    string getKategori() const;
    string getSatuan() const;
    int getStok() const;
    int getStokMinimum() const;
    double getHarga() const;
    bool isStokMenurun() const;

    // Setter dengan validasi
    void setNamaObat(const string& nama);
    void setHarga(double harga);
    void setStokMinimum(int min);

    // Operasi stok
    void tambahStok(int jumlah);
    bool kurangiStok(int jumlah);   // return false jika stok tidak cukup

    void tampilkanInfo() const;
};

#endif
