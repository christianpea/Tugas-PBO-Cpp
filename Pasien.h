#ifndef PASIEN_H
#define PASIEN_H

#include "Person.h"
#include <string>
#include <vector>
using namespace std;

// Pasien mewarisi Person (Inheritance)
class Pasien : public Person {
private:
    string tanggalLahir;
    string jenisKelamin;   // "L" atau "P"
    string golonganDarah;
    string riwayatAlergi;
    bool sudahDaftar;
    int nomorAntrean;

public:
    Pasien();
    Pasien(int id, const string& nama, const string& noTelepon,
           const string& alamat, const string& tanggalLahir,
           const string& jenisKelamin, const string& golonganDarah = "",
           const string& riwayatAlergi = "");
    ~Pasien();

    // Getter
    string getTanggalLahir() const;
    string getJenisKelamin() const;
    string getGolonganDarah() const;
    string getRiwayatAlergi() const;
    bool getSudahDaftar() const;
    int getNomorAntrean() const;

    // Setter
    void setGolonganDarah(const string& golDarah);
    void setRiwayatAlergi(const string& alergi);
    void setSudahDaftar(bool status);
    void setNomorAntrean(int nomor);

    // Override virtual function dari Person (Polymorphism)
    void tampilkanInfo() const override;
    string getRole() const override;
};

#endif
