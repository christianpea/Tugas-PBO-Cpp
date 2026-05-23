#include "Resep.h"
#include <iostream>

Resep::Resep()
    : id(0), idKunjungan(0), idDokter(0), namaDokter(""),
      idPasien(0), namaPasien(""), tanggal(""),
      catatan(""), sudahDiambil(false) {}

Resep::Resep(int id, int idKunjungan, int idDokter, const string& namaDokter,
             int idPasien, const string& namaPasien, const string& tanggal)
    : id(id), idKunjungan(idKunjungan), idDokter(idDokter),
      namaDokter(namaDokter), idPasien(idPasien),
      namaPasien(namaPasien), tanggal(tanggal),
      catatan(""), sudahDiambil(false) {}

Resep::~Resep() {}

int    Resep::getId() const            { return id; }
int    Resep::getIdKunjungan() const   { return idKunjungan; }
int    Resep::getIdDokter() const      { return idDokter; }
int    Resep::getIdPasien() const      { return idPasien; }
string Resep::getNamaPasien() const    { return namaPasien; }
string Resep::getTanggal() const       { return tanggal; }
string Resep::getCatatan() const       { return catatan; }
bool   Resep::getSudahDiambil() const  { return sudahDiambil; }
const vector<ItemResep>& Resep::getDaftarObat() const { return daftarObat; }

void Resep::setCatatan(const string& catatan)   { this->catatan = catatan; }
void Resep::setSudahDiambil(bool status)        { this->sudahDiambil = status; }

void Resep::tambahObat(int idObat, const string& namaObat, int jumlah, const string& aturan) {
    ItemResep item;
    item.idObat     = idObat;
    item.namaObat   = namaObat;
    item.jumlah     = jumlah;
    item.aturanPakai = aturan;
    daftarObat.push_back(item);
}

void Resep::tampilkanInfo() const {
    cout << "==============================" << endl;
    cout << "  [RESEP] ID: " << id << endl;
    cout << "  Tanggal  : " << tanggal << endl;
    cout << "  Dokter   : dr. " << namaDokter << endl;
    cout << "  Pasien   : " << namaPasien << endl;
    cout << "  Status   : " << (sudahDiambil ? "Sudah Diambil" : "Belum Diambil") << endl;
    if (!catatan.empty())
        cout << "  Catatan  : " << catatan << endl;
    cout << "  -- Daftar Obat --" << endl;
    if (daftarObat.empty()) {
        cout << "  (Belum ada obat)" << endl;
    } else {
        for (size_t i = 0; i < daftarObat.size(); i++) {
            cout << "  " << (i+1) << ". " << daftarObat[i].namaObat
                 << " - " << daftarObat[i].jumlah << " " 
                 << " | Aturan: " << daftarObat[i].aturanPakai << endl;
        }
    }
    cout << "==============================" << endl;
}
