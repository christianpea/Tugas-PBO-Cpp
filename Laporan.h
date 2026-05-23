#ifndef LAPORAN_H
#define LAPORAN_H

#include "Kunjungan.h"
#include "Resep.h"
#include "Obat.h"
#include <vector>
#include <string>
using namespace std;

// Class Laporan - mengelola dan menampilkan laporan harian klinik
class Laporan {
private:
    string tanggal;

public:
    Laporan();
    explicit Laporan(const string& tanggal);
    ~Laporan();

    string getTanggal() const;

    // Metode laporan - menerima data dari manager classes
    void tampilkanLaporanHarian(
        const vector<Kunjungan>& kunjungan,
        const vector<Resep>& resepList,
        const vector<Obat>& obatList,
        const string& tanggalFilter
    ) const;

    void tampilkanObatMenurun(const vector<Obat>& obatList) const;
    void tampilkanDaftarPasienHariIni(const vector<Kunjungan>& kunjungan,
                                      const string& tanggal) const;
};

#endif
