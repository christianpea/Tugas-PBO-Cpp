#ifndef RESEP_H
#define RESEP_H

#include <string>
#include <vector>
using namespace std;

// Struct untuk item dalam resep
struct ItemResep {
    int idObat;
    string namaObat;
    int jumlah;
    string aturanPakai;   // misal: "3x sehari setelah makan"
};

// Class Resep - mengelola daftar obat yang diresepkan dokter
class Resep {
private:
    int id;
    int idKunjungan;
    int idDokter;
    string namaDokter;
    int idPasien;
    string namaPasien;
    string tanggal;
    string catatan;
    bool sudahDiambil;
    vector<ItemResep> daftarObat;

public:
    Resep();
    Resep(int id, int idKunjungan, int idDokter, const string& namaDokter,
          int idPasien, const string& namaPasien, const string& tanggal);
    ~Resep();

    // Getter
    int getId() const;
    int getIdKunjungan() const;
    int getIdDokter() const;
    int getIdPasien() const;
    string getNamaPasien() const;
    string getTanggal() const;
    string getCatatan() const;
    bool getSudahDiambil() const;
    const vector<ItemResep>& getDaftarObat() const;

    // Setter / Operasi
    void setCatatan(const string& catatan);
    void setSudahDiambil(bool status);
    void tambahObat(int idObat, const string& namaObat, int jumlah, const string& aturan);

    void tampilkanInfo() const;
};

#endif
