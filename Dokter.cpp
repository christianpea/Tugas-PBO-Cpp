#include "Dokter.h"
#include <iostream>
#include <stdexcept>

Dokter::Dokter()
    : Person(), spesialisasi("Umum"), nomorSIP(""), jumlahPasienDitangani(0) {}

Dokter::Dokter(int id, const string& nama, const string& noTelepon,
               const string& alamat, const string& spesialisasi,
               const string& nomorSIP)
    : Person(id, nama, noTelepon, alamat),
      spesialisasi(spesialisasi), nomorSIP(nomorSIP),
      jumlahPasienDitangani(0) {
    if (nomorSIP.empty()) throw invalid_argument("Nomor SIP tidak boleh kosong.");
}

Dokter::~Dokter() {}

string Dokter::getSpesialisasi() const          { return spesialisasi; }
string Dokter::getNomorSIP() const              { return nomorSIP; }
int    Dokter::getJumlahPasienDitangani() const { return jumlahPasienDitangani; }

void Dokter::setSpesialisasi(const string& spesialisasi) {
    if (spesialisasi.empty()) throw invalid_argument("Spesialisasi tidak boleh kosong.");
    this->spesialisasi = spesialisasi;
}

void Dokter::tambahPasienDitangani() { jumlahPasienDitangani++; }

void Dokter::tampilkanInfo() const {
    cout << "==============================" << endl;
    cout << "  [DOKTER]" << endl;
    cout << "  ID              : " << id << endl;
    cout << "  Nama            : " << "dr. " << nama << endl;
    cout << "  Spesialisasi    : " << spesialisasi << endl;
    cout << "  No. SIP         : " << nomorSIP << endl;
    cout << "  No. Telepon     : " << noTelepon << endl;
    cout << "  Pasien Ditangani: " << jumlahPasienDitangani << endl;
    cout << "==============================" << endl;
}

string Dokter::getRole() const { return "Dokter"; }
