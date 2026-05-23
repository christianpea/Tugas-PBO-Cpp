#ifndef KUNJUNGAN_H
#define KUNJUNGAN_H

#include <string>
using namespace std;

// Class Kunjungan - mencatat rekam medis setiap kunjungan pasien
class Kunjungan {
private:
    int id;
    int idPasien;
    string namaPasien;
    int idDokter;
    string namaDokter;
    string tanggal;
    string keluhan;
    string hasilPemeriksaan;
    string diagnosis;
    string tindakan;
    bool sudahDiperiksa;
    bool adaResep;
    int idResep;           // 0 jika belum ada resep

public:
    Kunjungan();
    Kunjungan(int id, int idPasien, const string& namaPasien,
              const string& tanggal);
    ~Kunjungan();

    // Getter
    int getId() const;
    int getIdPasien() const;
    string getNamaPasien() const;
    int getIdDokter() const;
    string getNamaDokter() const;
    string getTanggal() const;
    string getKeluhan() const;
    string getHasilPemeriksaan() const;
    string getDiagnosis() const;
    string getTindakan() const;
    bool getSudahDiperiksa() const;
    bool getAdaResep() const;
    int getIdResep() const;

    // Setter
    void setKeluhan(const string& keluhan);
    void setDokter(int idDokter, const string& namaDokter);
    void setHasilPemeriksaan(const string& hasil);
    void setDiagnosis(const string& diagnosis);
    void setTindakan(const string& tindakan);
    void setSudahDiperiksa(bool status);
    void setResep(int idResep);

    void tampilkanInfo() const;
    void tampilkanRingkasan() const;
};

#endif
