#include "Laporan.h"
#include <iostream>
#include <iomanip>

Laporan::Laporan() : tanggal("") {}
Laporan::Laporan(const string& tanggal) : tanggal(tanggal) {}
Laporan::~Laporan() {}

string Laporan::getTanggal() const { return tanggal; }

void Laporan::tampilkanLaporanHarian(
    const vector<Kunjungan>& kunjungan,
    const vector<Resep>& resepList,
    const vector<Obat>& obatList,
    const string& tanggalFilter) const
{
    cout << "\n========================================" << endl;
    cout << "   LAPORAN HARIAN KLINIK SEHAT BERSAMA" << endl;
    cout << "   Tanggal: " << tanggalFilter << endl;
    cout << "========================================" << endl;

    // Hitung kunjungan hari ini
    int totalKunjungan = 0, sudahDiperiksa = 0;
    cout << "\n-- DAFTAR KUNJUNGAN --" << endl;
    for (const auto& k : kunjungan) {
        if (k.getTanggal() == tanggalFilter) {
            k.tampilkanRingkasan();
            totalKunjungan++;
            if (k.getSudahDiperiksa()) sudahDiperiksa++;
        }
    }
    if (totalKunjungan == 0) cout << "  (Tidak ada kunjungan)" << endl;

    cout << "\n  Total Kunjungan    : " << totalKunjungan << endl;
    cout << "  Sudah Diperiksa    : " << sudahDiperiksa << endl;
    cout << "  Masih Menunggu     : " << (totalKunjungan - sudahDiperiksa) << endl;

    // Resep yang dikeluarkan hari ini
    int totalResep = 0;
    cout << "\n-- RESEP DIKELUARKAN HARI INI --" << endl;
    for (const auto& r : resepList) {
        if (r.getTanggal() == tanggalFilter) {
            cout << "  Resep #" << r.getId()
                 << " | Pasien: " << r.getNamaPasien()
                 << " | Status: " << (r.getSudahDiambil() ? "Sudah Diambil" : "Belum Diambil")
                 << endl;
            totalResep++;
        }
    }
    if (totalResep == 0) cout << "  (Tidak ada resep)" << endl;
    cout << "  Total Resep: " << totalResep << endl;

    // Stok obat menipis
    cout << "\n-- PERINGATAN STOK OBAT --" << endl;
    tampilkanObatMenurun(obatList);

    cout << "\n========================================\n" << endl;
}

void Laporan::tampilkanObatMenurun(const vector<Obat>& obatList) const {
    bool ada = false;
    for (const auto& o : obatList) {
        if (o.isStokMenurun()) {
            cout << "  [!!] " << o.getNamaObat()
                 << " - Stok: " << o.getStok()
                 << " (Minimum: " << o.getStokMinimum() << ")" << endl;
            ada = true;
        }
    }
    if (!ada) cout << "  Semua stok obat mencukupi." << endl;
}

void Laporan::tampilkanDaftarPasienHariIni(
    const vector<Kunjungan>& kunjungan,
    const string& tanggal) const
{
    cout << "\n-- DAFTAR PASIEN HARI INI (" << tanggal << ") --" << endl;
    int no = 1;
    for (const auto& k : kunjungan) {
        if (k.getTanggal() == tanggal) {
            cout << "  " << no++ << ". " << k.getNamaPasien()
                 << " | Keluhan: " << k.getKeluhan()
                 << " | " << (k.getSudahDiperiksa() ? "Selesai" : "Menunggu")
                 << endl;
        }
    }
    if (no == 1) cout << "  Belum ada pasien hari ini." << endl;
}
