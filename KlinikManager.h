#ifndef KLINIKMANAGER_H
#define KLINIKMANAGER_H

#include "Pasien.h"
#include "Dokter.h"
#include "Obat.h"
#include "Kunjungan.h"
#include "Resep.h"
#include "Laporan.h"
#include <vector>
#include <string>
using namespace std;

// KlinikManager - class utama yang mengkoordinasikan seluruh operasi klinik
// Menerapkan Single Responsibility + modular design
class KlinikManager {
private:
    vector<Pasien>    daftarPasien;
    vector<Dokter>    daftarDokter;
    vector<Obat>      daftarObat;
    vector<Kunjungan> daftarKunjungan;
    vector<Resep>     daftarResep;
    Laporan           laporan;

    int nextIdPasien;
    int nextIdDokter;
    int nextIdObat;
    int nextIdKunjungan;
    int nextIdResep;
    int nextAntrean;

    string tanggalHariIni;

    // Helper private methods
    Pasien*    cariPasienById(int id);
    Dokter*    cariDokterById(int id);
    Obat*      cariObatById(int id);
    Kunjungan* cariKunjunganById(int id);
    Resep*     cariResepById(int id);

    void inisialisasiDataContoh();

public:
    KlinikManager();
    ~KlinikManager();

    void setTanggalHariIni(const string& tanggal);
    string getTanggalHariIni() const;

    // === MODUL ADMINISTRASI ===
    void daftarPasienBaru();
    void cariPasien();
    void tampilkanSemuaPasien();
    void tampilkanAntrean();
    void tambahKeAntrean();

    // === MODUL DOKTER ===
    void tampilkanSemuaDokter();
    void periksaPasien();
    void lihatDataPasienUntukDokter();

    // === MODUL FARMASI ===
    void tampilkanDaftarObat();
    void tambahStokObat();
    void tambahObatBaru();
    void prosesResep();
    void lihatResepBelumDiambil();

    // === MODUL LAPORAN ===
    void tampilkanLaporanHarian();
    void tampilkanStokMenurun();
};

#endif
