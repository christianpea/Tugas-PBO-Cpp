#include "Pasien.h"
#include <iostream>
#include <stdexcept>

Pasien::Pasien()
    : Person(), tanggalLahir(""), jenisKelamin("L"), golonganDarah(""),
      riwayatAlergi(""), sudahDaftar(false), nomorAntrean(0) {}

Pasien::Pasien(int id, const string& nama, const string& noTelepon,
               const string& alamat, const string& tanggalLahir,
               const string& jenisKelamin, const string& golonganDarah,
               const string& riwayatAlergi)
    : Person(id, nama, noTelepon, alamat),
      tanggalLahir(tanggalLahir), golonganDarah(golonganDarah),
      riwayatAlergi(riwayatAlergi), sudahDaftar(true), nomorAntrean(0) {
    if (jenisKelamin != "L" && jenisKelamin != "P")
        throw invalid_argument("Jenis kelamin harus 'L' atau 'P'.");
    this->jenisKelamin = jenisKelamin;
}

Pasien::~Pasien() {}

string Pasien::getTanggalLahir() const  { return tanggalLahir; }
string Pasien::getJenisKelamin() const  { return jenisKelamin; }
string Pasien::getGolonganDarah() const { return golonganDarah; }
string Pasien::getRiwayatAlergi() const { return riwayatAlergi; }
bool   Pasien::getSudahDaftar() const   { return sudahDaftar; }
int    Pasien::getNomorAntrean() const  { return nomorAntrean; }

void Pasien::setGolonganDarah(const string& golDarah) { this->golonganDarah = golDarah; }
void Pasien::setRiwayatAlergi(const string& alergi)   { this->riwayatAlergi = alergi; }
void Pasien::setSudahDaftar(bool status)               { this->sudahDaftar = status; }
void Pasien::setNomorAntrean(int nomor) {
    if (nomor < 0) throw invalid_argument("Nomor antrean tidak boleh negatif.");
    this->nomorAntrean = nomor;
}

void Pasien::tampilkanInfo() const {
    cout << "==============================" << endl;
    cout << "  [PASIEN]" << endl;
    cout << "  ID          : " << id << endl;
    cout << "  Nama        : " << nama << endl;
    cout << "  Tgl Lahir   : " << tanggalLahir << endl;
    cout << "  Jenis Kel.  : " << (jenisKelamin == "L" ? "Laki-laki" : "Perempuan") << endl;
    cout << "  Gol. Darah  : " << (golonganDarah.empty() ? "-" : golonganDarah) << endl;
    cout << "  Alergi      : " << (riwayatAlergi.empty() ? "-" : riwayatAlergi) << endl;
    cout << "  No. Telepon : " << noTelepon << endl;
    cout << "  Alamat      : " << alamat << endl;
    if (nomorAntrean > 0)
        cout << "  No. Antrean : " << nomorAntrean << endl;
    cout << "==============================" << endl;
}

string Pasien::getRole() const { return "Pasien"; }
