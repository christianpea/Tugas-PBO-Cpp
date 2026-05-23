#include "Kunjungan.h"
#include <iostream>
#include <stdexcept>

Kunjungan::Kunjungan()
    : id(0), idPasien(0), namaPasien(""), idDokter(0), namaDokter(""),
      tanggal(""), keluhan(""), hasilPemeriksaan(""), diagnosis(""),
      tindakan(""), sudahDiperiksa(false), adaResep(false), idResep(0) {}

Kunjungan::Kunjungan(int id, int idPasien, const string& namaPasien,
                     const string& tanggal)
    : id(id), idPasien(idPasien), namaPasien(namaPasien),
      idDokter(0), namaDokter(""), tanggal(tanggal),
      keluhan(""), hasilPemeriksaan(""), diagnosis(""),
      tindakan(""), sudahDiperiksa(false), adaResep(false), idResep(0) {}

Kunjungan::~Kunjungan() {}

int    Kunjungan::getId() const                { return id; }
int    Kunjungan::getIdPasien() const          { return idPasien; }
string Kunjungan::getNamaPasien() const        { return namaPasien; }
int    Kunjungan::getIdDokter() const          { return idDokter; }
string Kunjungan::getNamaDokter() const        { return namaDokter; }
string Kunjungan::getTanggal() const           { return tanggal; }
string Kunjungan::getKeluhan() const           { return keluhan; }
string Kunjungan::getHasilPemeriksaan() const  { return hasilPemeriksaan; }
string Kunjungan::getDiagnosis() const         { return diagnosis; }
string Kunjungan::getTindakan() const          { return tindakan; }
bool   Kunjungan::getSudahDiperiksa() const    { return sudahDiperiksa; }
bool   Kunjungan::getAdaResep() const          { return adaResep; }
int    Kunjungan::getIdResep() const           { return idResep; }

void Kunjungan::setKeluhan(const string& keluhan) {
    if (keluhan.empty()) throw invalid_argument("Keluhan tidak boleh kosong.");
    this->keluhan = keluhan;
}

void Kunjungan::setDokter(int idDokter, const string& namaDokter) {
    this->idDokter   = idDokter;
    this->namaDokter = namaDokter;
}

void Kunjungan::setHasilPemeriksaan(const string& hasil) {
    this->hasilPemeriksaan = hasil;
}

void Kunjungan::setDiagnosis(const string& diagnosis) {
    this->diagnosis = diagnosis;
}

void Kunjungan::setTindakan(const string& tindakan) {
    this->tindakan = tindakan;
}

void Kunjungan::setSudahDiperiksa(bool status) {
    this->sudahDiperiksa = status;
}

void Kunjungan::setResep(int idResep) {
    this->idResep  = idResep;
    this->adaResep = (idResep > 0);
}

void Kunjungan::tampilkanInfo() const {
    cout << "========================================" << endl;
    cout << "  [KUNJUNGAN] ID: " << id << endl;
    cout << "  Tanggal         : " << tanggal << endl;
    cout << "  Pasien          : " << namaPasien << " (ID: " << idPasien << ")" << endl;
    cout << "  Dokter          : " << (namaDokter.empty() ? "-" : "dr. " + namaDokter)
         << (idDokter > 0 ? " (ID: " + to_string(idDokter) + ")" : "") << endl;
    cout << "  Keluhan         : " << (keluhan.empty() ? "-" : keluhan) << endl;
    cout << "  Hasil Periksa   : " << (hasilPemeriksaan.empty() ? "-" : hasilPemeriksaan) << endl;
    cout << "  Diagnosis       : " << (diagnosis.empty() ? "-" : diagnosis) << endl;
    cout << "  Tindakan        : " << (tindakan.empty() ? "-" : tindakan) << endl;
    cout << "  Status          : " << (sudahDiperiksa ? "Sudah Diperiksa" : "Menunggu") << endl;
    cout << "  Resep           : " << (adaResep ? "Ada (ID: " + to_string(idResep) + ")" : "Tidak Ada") << endl;
    cout << "========================================" << endl;
}

void Kunjungan::tampilkanRingkasan() const {
    cout << "  [" << id << "] " << namaPasien
         << " | " << tanggal
         << " | " << (sudahDiperiksa ? "Selesai" : "Antrean")
         << " | Dokter: " << (namaDokter.empty() ? "-" : "dr. " + namaDokter)
         << endl;
}
