#include <iostream>
#include <limits>
#include <string>
#include "KlinikManager.h"
using namespace std;

// ============================================================
//  Helper: input integer dengan validasi
// ============================================================
int inputInt(const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cout << "  [!] Input tidak valid. Masukkan angka." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// ============================================================
//  Sub-menu Administrasi
// ============================================================
void menuAdministrasi(KlinikManager& km) {
    int pilih;
    do {
        cout << "\n========================================" << endl;
        cout << "   MENU ADMINISTRASI" << endl;
        cout << "========================================" << endl;
        cout << "  1. Daftarkan Pasien Baru" << endl;
        cout << "  2. Cari Data Pasien" << endl;
        cout << "  3. Lihat Semua Pasien" << endl;
        cout << "  4. Tambah Pasien ke Antrean" << endl;
        cout << "  5. Tampilkan Antrean Hari Ini" << endl;
        cout << "  0. Kembali" << endl;
        pilih = inputInt("Pilihan: ");

        switch (pilih) {
            case 1: km.daftarPasienBaru();      break;
            case 2: km.cariPasien();            break;
            case 3: km.tampilkanSemuaPasien();  break;
            case 4: km.tambahKeAntrean();       break;
            case 5: km.tampilkanAntrean();      break;
            case 0: break;
            default: cout << "[!] Pilihan tidak valid." << endl;
        }
    } while (pilih != 0);
}

// ============================================================
//  Sub-menu Dokter
// ============================================================
void menuDokter(KlinikManager& km) {
    int pilih;
    do {
        cout << "\n========================================" << endl;
        cout << "   MENU DOKTER" << endl;
        cout << "========================================" << endl;
        cout << "  1. Lihat Antrean Pasien" << endl;
        cout << "  2. Periksa Pasien & Buat Resep" << endl;
        cout << "  3. Lihat Data Pasien" << endl;
        cout << "  4. Lihat Daftar Dokter" << endl;
        cout << "  0. Kembali" << endl;
        pilih = inputInt("Pilihan: ");

        switch (pilih) {
            case 1: km.tampilkanAntrean();              break;
            case 2: km.periksaPasien();                 break;
            case 3: km.lihatDataPasienUntukDokter();    break;
            case 4: km.tampilkanSemuaDokter();          break;
            case 0: break;
            default: cout << "[!] Pilihan tidak valid." << endl;
        }
    } while (pilih != 0);
}

// ============================================================
//  Sub-menu Farmasi
// ============================================================
void menuFarmasi(KlinikManager& km) {
    int pilih;
    do {
        cout << "\n========================================" << endl;
        cout << "   MENU FARMASI" << endl;
        cout << "========================================" << endl;
        cout << "  1. Lihat Daftar Obat" << endl;
        cout << "  2. Tambah Obat Baru" << endl;
        cout << "  3. Tambah Stok Obat" << endl;
        cout << "  4. Lihat Resep Belum Diambil" << endl;
        cout << "  5. Proses Pengambilan Obat" << endl;
        cout << "  6. Cek Stok Menipis" << endl;
        cout << "  0. Kembali" << endl;
        pilih = inputInt("Pilihan: ");

        switch (pilih) {
            case 1: km.tampilkanDaftarObat();       break;
            case 2: km.tambahObatBaru();            break;
            case 3: km.tambahStokObat();            break;
            case 4: km.lihatResepBelumDiambil();    break;
            case 5: km.prosesResep();               break;
            case 6: km.tampilkanStokMenurun();      break;
            case 0: break;
            default: cout << "[!] Pilihan tidak valid." << endl;
        }
    } while (pilih != 0);
}

// ============================================================
//  Sub-menu Laporan
// ============================================================
void menuLaporan(KlinikManager& km) {
    int pilih;
    do {
        cout << "\n========================================" << endl;
        cout << "   MENU LAPORAN" << endl;
        cout << "========================================" << endl;
        cout << "  1. Laporan Harian" << endl;
        cout << "  2. Stok Obat Menipis" << endl;
        cout << "  0. Kembali" << endl;
        pilih = inputInt("Pilihan: ");

        switch (pilih) {
            case 1: km.tampilkanLaporanHarian();  break;
            case 2: km.tampilkanStokMenurun();    break;
            case 0: break;
            default: cout << "[!] Pilihan tidak valid." << endl;
        }
    } while (pilih != 0);
}

// ============================================================
//  Main Menu
// ============================================================
int main() {
    cout << "========================================" << endl;
    cout << "  SISTEM MANAJEMEN KLINIK SEHAT BERSAMA" << endl;
    cout << "  Berbasis Object Oriented Programming" << endl;
    cout << "========================================" << endl;

    KlinikManager km;

    // Set tanggal hari ini
    cout << "\nMasukkan tanggal hari ini (YYYY-MM-DD): ";
    string tgl;
    cin.ignore();
    getline(cin, tgl);
    if (!tgl.empty()) km.setTanggalHariIni(tgl);
    cout << "Tanggal aktif: " << km.getTanggalHariIni() << endl;

    int pilih;
    do {
        cout << "\n========================================" << endl;
        cout << "   MENU UTAMA" << endl;
        cout << "   Tanggal: " << km.getTanggalHariIni() << endl;
        cout << "========================================" << endl;
        cout << "  1. Administrasi (Pendaftaran & Antrean)" << endl;
        cout << "  2. Dokter (Pemeriksaan & Resep)" << endl;
        cout << "  3. Farmasi (Obat & Resep)" << endl;
        cout << "  4. Laporan" << endl;
        cout << "  0. Keluar" << endl;
        pilih = inputInt("Pilihan: ");

        switch (pilih) {
            case 1: menuAdministrasi(km); break;
            case 2: menuDokter(km);       break;
            case 3: menuFarmasi(km);      break;
            case 4: menuLaporan(km);      break;
            case 0:
                cout << "\nTerima kasih telah menggunakan Sistem Klinik Sehat Bersama." << endl;
                break;
            default:
                cout << "[!] Pilihan tidak valid." << endl;
        }
    } while (pilih != 0);

    return 0;
}
