#ifndef DOKTER_H
#define DOKTER_H

#include "Person.h"
#include <string>
using namespace std;

// Dokter mewarisi Person (Inheritance)
class Dokter : public Person {
private:
    string spesialisasi;
    string nomorSIP;       // Surat Izin Praktik
    int jumlahPasienDitangani;

public:
    Dokter();
    Dokter(int id, const string& nama, const string& noTelepon,
           const string& alamat, const string& spesialisasi,
           const string& nomorSIP);
    ~Dokter();

    // Getter
    string getSpesialisasi() const;
    string getNomorSIP() const;
    int getJumlahPasienDitangani() const;

    // Setter
    void setSpesialisasi(const string& spesialisasi);
    void tambahPasienDitangani();

    // Override virtual function dari Person (Polymorphism)
    void tampilkanInfo() const override;
    string getRole() const override;
};

#endif
