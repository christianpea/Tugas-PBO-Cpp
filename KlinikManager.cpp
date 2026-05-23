#include "KlinikManager.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

// ============================================================
//  Helper: bersihkan buffer input
// ============================================================
static void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ============================================================
//  Constructor & Destructor
// ============================================================
KlinikManager::KlinikManager()
    : nextIdPasien(1), nextIdDokter(1), nextIdObat(1),
      nextIdKunjungan(1), nextIdResep(1), nextAntrean(1),
      tanggalHariIni("2025-06-01") {
    laporan = Laporan(tanggalHariIni);
    inisialisasiDataContoh();
}

KlinikManager::~KlinikManager() {}

void KlinikManager::setTanggalHariIni(const string& tanggal) {
    tanggalHariIni = tanggal;
    laporan = Laporan(tanggal);
}

string KlinikManager::getTanggalHariIni() const { return tanggalHariIni; }

// ============================================================
//  Data Contoh (agar program langsung dapat dicoba)
// ============================================================
void KlinikManager::inisialisasiDataContoh() {
    // Dokter
    daftarDokter.push_back(Dokter(nextIdDokter++, "Budi Santoso", "081234567890",
                                   "Jl. Mawar No. 1", "Umum", "SIP-001"));
    daftarDokter.push_back(Dokter(nextIdDokter++, "Sari Dewi", "081987654321",
                                   "Jl. Melati No. 5", "Anak", "SIP-002"));

    // Pasien
    daftarPasien.push_back(Pasien(nextIdPasien++, "Tian", "082111222333",
                                   "Jl. Kenanga 10", "1990-03-15", "L", "A", "-"));
    daftarPasien.push_back(Pasien(nextIdPasien++, "Rina Wulandari", "082444555666",
                                   "Jl. Cempaka 7", "1995-07-20", "P", "B", "Penisilin"));

    // Obat
    daftarObat.push_back(Obat(nextIdObat++, "Paracetamol 500mg", "Analgesik",
                               "tablet", 100, 10, 500));
    daftarObat.push_back(Obat(nextIdObat++, "Amoksisilin 500mg", "Antibiotik",
                               "kapsul", 8, 10, 2000));   // stok menipis
    daftarObat.push_back(Obat(nextIdObat++, "Antasida", "Antasida",
                               "tablet", 60, 10, 300));
    daftarObat.push_back(Obat(nextIdObat++, "Vitamin C 500mg", "Vitamin",
                               "tablet", 200, 20, 1000));
    daftarObat.push_back(Obat(nextIdObat++, "OBH Combi", "Antitusif",
                               "botol", 5, 5, 15000));    // stok menipis
}

// ============================================================
//  Helper Cari
// ============================================================
Pasien* KlinikManager::cariPasienById(int id) {
    for (auto& p : daftarPasien)
        if (p.getId() == id) return &p;
    return nullptr;
}

Dokter* KlinikManager::cariDokterById(int id) {
    for (auto& d : daftarDokter)
        if (d.getId() == id) return &d;
    return nullptr;
}

Obat* KlinikManager::cariObatById(int id) {
    for (auto& o : daftarObat)
        if (o.getId() == id) return &o;
    return nullptr;
}

Kunjungan* KlinikManager::cariKunjunganById(int id) {
    for (auto& k : daftarKunjungan)
        if (k.getId() == id) return &k;
    return nullptr;
}

Resep* KlinikManager::cariResepById(int id) {
    for (auto& r : daftarResep)
        if (r.getId() == id) return &r;
    return nullptr;
}

// ============================================================
//  MODUL ADMINISTRASI
// ============================================================
void KlinikManager::daftarPasienBaru() {
    cout << "\n=== DAFTAR PASIEN BARU ===" << endl;
    string nama, telepon, alamat, tglLahir, jk, golDarah, alergi;

    cout << "Nama lengkap    : "; clearInput(); getline(cin, nama);
    cout << "No. Telepon     : "; getline(cin, telepon);
    cout << "Alamat          : "; getline(cin, alamat);
    cout << "Tanggal Lahir   : "; getline(cin, tglLahir);

    do {
        cout << "Jenis Kelamin (L/P): "; getline(cin, jk);
        transform(jk.begin(), jk.end(), jk.begin(), ::toupper);
        if (jk != "L" && jk != "P")
            cout << "  Input tidak valid. Masukkan L atau P." << endl;
    } while (jk != "L" && jk != "P");

    cout << "Golongan Darah  : "; getline(cin, golDarah);
    cout << "Riwayat Alergi  : "; getline(cin, alergi);

    try {
        Pasien p(nextIdPasien++, nama, telepon, alamat, tglLahir, jk, golDarah, alergi);
        daftarPasien.push_back(p);
        cout << "\n[OK] Pasien berhasil didaftarkan. ID: " << (nextIdPasien - 1) << endl;
    } catch (const exception& e) {
        nextIdPasien--;
        cout << "[ERROR] " << e.what() << endl;
    }
}

void KlinikManager::cariPasien() {
    cout << "\n=== CARI PASIEN ===" << endl;
    cout << "Cari berdasarkan: 1) ID  2) Nama  : ";
    int pilih; cin >> pilih;

    if (pilih == 1) {
        cout << "Masukkan ID Pasien: ";
        int id; cin >> id;
        Pasien* p = cariPasienById(id);
        if (p) p->tampilkanInfo();
        else   cout << "[!] Pasien dengan ID " << id << " tidak ditemukan." << endl;
    } else {
        cout << "Masukkan nama (sebagian): ";
        string kata; clearInput(); getline(cin, kata);
        transform(kata.begin(), kata.end(), kata.begin(), ::tolower);
        bool ada = false;
        for (auto& p : daftarPasien) {
            string nm = p.getNama();
            transform(nm.begin(), nm.end(), nm.begin(), ::tolower);
            if (nm.find(kata) != string::npos) {
                p.tampilkanInfo();
                ada = true;
            }
        }
        if (!ada) cout << "[!] Tidak ada pasien dengan nama yang mengandung '" << kata << "'." << endl;
    }
}

void KlinikManager::tampilkanSemuaPasien() {
    cout << "\n=== DAFTAR SEMUA PASIEN ===" << endl;
    if (daftarPasien.empty()) {
        cout << "  Belum ada data pasien." << endl;
        return;
    }
    cout << left << setw(5) << "ID"
         << setw(25) << "Nama"
         << setw(15) << "Jenis Kel."
         << setw(15) << "No. Telp" << endl;
    cout << string(60, '-') << endl;
    for (const auto& p : daftarPasien) {
        cout << left << setw(5) << p.getId()
             << setw(25) << p.getNama()
             << setw(15) << (p.getJenisKelamin() == "L" ? "Laki-laki" : "Perempuan")
             << setw(15) << p.getNoTelepon() << endl;
    }
}

void KlinikManager::tampilkanAntrean() {
    cout << "\n=== ANTREAN HARI INI (" << tanggalHariIni << ") ===" << endl;
    bool ada = false;
    for (const auto& k : daftarKunjungan) {
        if (k.getTanggal() == tanggalHariIni && !k.getSudahDiperiksa()) {
            cout << "  No. Antrean: ";
            Pasien* p = cariPasienById(k.getIdPasien());
            if (p) cout << p->getNomorAntrean();
            cout << " | Pasien: " << k.getNamaPasien()
                 << " | Keluhan: " << k.getKeluhan()
                 << " | Kunjungan ID: " << k.getId() << endl;
            ada = true;
        }
    }
    if (!ada) cout << "  Antrean kosong." << endl;
}

void KlinikManager::tambahKeAntrean() {
    cout << "\n=== TAMBAH PASIEN KE ANTREAN ===" << endl;
    cout << "Masukkan ID Pasien: ";
    int id; cin >> id;
    Pasien* p = cariPasienById(id);
    if (!p) {
        cout << "[!] Pasien tidak ditemukan." << endl;
        return;
    }

    string keluhan;
    cout << "Keluhan pasien  : "; clearInput(); getline(cin, keluhan);

    try {
        Kunjungan k(nextIdKunjungan++, p->getId(), p->getNama(), tanggalHariIni);
        k.setKeluhan(keluhan);
        p->setNomorAntrean(nextAntrean++);
        daftarKunjungan.push_back(k);
        cout << "[OK] Pasien masuk antrean. No. Antrean: " << p->getNomorAntrean()
             << " | Kunjungan ID: " << (nextIdKunjungan - 1) << endl;
    } catch (const exception& e) {
        nextIdKunjungan--;
        cout << "[ERROR] " << e.what() << endl;
    }
}

// ============================================================
//  MODUL DOKTER
// ============================================================
void KlinikManager::tampilkanSemuaDokter() {
    cout << "\n=== DAFTAR DOKTER ===" << endl;
    for (const auto& d : daftarDokter)
        d.tampilkanInfo();
}

void KlinikManager::lihatDataPasienUntukDokter() {
    cout << "\n=== LIHAT DATA PASIEN (DOKTER) ===" << endl;
    cout << "Masukkan ID Pasien: ";
    int id; cin >> id;
    Pasien* p = cariPasienById(id);
    if (!p) { cout << "[!] Pasien tidak ditemukan." << endl; return; }
    p->tampilkanInfo();

    // Tampilkan riwayat kunjungan pasien
    cout << "\n  -- Riwayat Kunjungan --" << endl;
    bool ada = false;
    for (const auto& k : daftarKunjungan) {
        if (k.getIdPasien() == id) {
            k.tampilkanRingkasan();
            ada = true;
        }
    }
    if (!ada) cout << "  Belum ada riwayat kunjungan." << endl;
}

void KlinikManager::periksaPasien() {
    cout << "\n=== PERIKSA PASIEN ===" << endl;
    tampilkanAntrean();

    cout << "\nMasukkan ID Kunjungan: ";
    int idK; cin >> idK;
    Kunjungan* k = cariKunjunganById(idK);
    if (!k) { cout << "[!] Kunjungan tidak ditemukan." << endl; return; }
    if (k->getSudahDiperiksa()) { cout << "[!] Pasien sudah diperiksa." << endl; return; }

    // Pilih dokter
    tampilkanSemuaDokter();
    cout << "Masukkan ID Dokter: ";
    int idD; cin >> idD;
    Dokter* d = cariDokterById(idD);
    if (!d) { cout << "[!] Dokter tidak ditemukan." << endl; return; }

    string hasil, diagnosis, tindakan;
    clearInput();
    cout << "Hasil pemeriksaan: "; getline(cin, hasil);
    cout << "Diagnosis        : "; getline(cin, diagnosis);
    cout << "Tindakan         : "; getline(cin, tindakan);

    k->setDokter(d->getId(), d->getNama());
    k->setHasilPemeriksaan(hasil);
    k->setDiagnosis(diagnosis);
    k->setTindakan(tindakan);
    k->setSudahDiperiksa(true);
    d->tambahPasienDitangani();

    cout << "\n[OK] Data pemeriksaan tersimpan." << endl;

    // Tanya apakah perlu resep
    cout << "Buat resep? (1=Ya / 0=Tidak): ";
    int buatResep; cin >> buatResep;
    if (buatResep == 1) {
        Resep r(nextIdResep++, k->getId(), d->getId(), d->getNama(),
                k->getIdPasien(), k->getNamaPasien(), tanggalHariIni);

        string catatanResep;
        clearInput();
        cout << "Catatan resep: "; getline(cin, catatanResep);
        r.setCatatan(catatanResep);

        // Tambah obat ke resep
        bool tambahLagi = true;
        while (tambahLagi) {
            tampilkanDaftarObat();
            cout << "ID Obat (0 = selesai): ";
            int idObat; cin >> idObat;
            if (idObat == 0) break;

            Obat* o = cariObatById(idObat);
            if (!o) { cout << "[!] Obat tidak ditemukan." << endl; continue; }

            int jumlah;
            cout << "Jumlah: "; cin >> jumlah;
            string aturan;
            clearInput();
            cout << "Aturan pakai: "; getline(cin, aturan);

            r.tambahObat(o->getId(), o->getNamaObat(), jumlah, aturan);
            cout << "[OK] Obat ditambahkan ke resep." << endl;

            cout << "Tambah obat lagi? (1=Ya / 0=Tidak): ";
            int lagi; cin >> lagi;
            tambahLagi = (lagi == 1);
        }

        daftarResep.push_back(r);
        k->setResep(nextIdResep - 1);
        cout << "[OK] Resep dibuat. ID Resep: " << (nextIdResep - 1) << endl;
    }
}

// ============================================================
//  MODUL FARMASI
// ============================================================
void KlinikManager::tampilkanDaftarObat() {
    cout << "\n=== DAFTAR OBAT ===" << endl;
    if (daftarObat.empty()) { cout << "  Belum ada data obat." << endl; return; }
    cout << left << setw(5) << "ID"
         << setw(25) << "Nama Obat"
         << setw(15) << "Kategori"
         << setw(8)  << "Stok"
         << setw(10) << "Satuan"
         << "Harga" << endl;
    cout << string(70, '-') << endl;
    for (const auto& o : daftarObat) {
        cout << left << setw(5) << o.getId()
             << setw(25) << o.getNamaObat()
             << setw(15) << o.getKategori()
             << setw(8)  << o.getStok()
             << setw(10) << o.getSatuan()
             << "Rp " << fixed << setprecision(0) << o.getHarga()
             << (o.isStokMenurun() ? "  [!!]" : "") << endl;
    }
}

void KlinikManager::tambahObatBaru() {
    cout << "\n=== TAMBAH OBAT BARU ===" << endl;
    string nama, kategori, satuan;
    int stok, stokMin;
    double harga;

    clearInput();
    cout << "Nama Obat      : "; getline(cin, nama);
    cout << "Kategori       : "; getline(cin, kategori);
    cout << "Satuan         : "; getline(cin, satuan);
    cout << "Stok Awal      : "; cin >> stok;
    cout << "Stok Minimum   : "; cin >> stokMin;
    cout << "Harga (Rp)     : "; cin >> harga;

    try {
        Obat o(nextIdObat++, nama, kategori, satuan, stok, stokMin, harga);
        daftarObat.push_back(o);
        cout << "[OK] Obat berhasil ditambahkan. ID: " << (nextIdObat - 1) << endl;
    } catch (const exception& e) {
        nextIdObat--;
        cout << "[ERROR] " << e.what() << endl;
    }
}

void KlinikManager::tambahStokObat() {
    cout << "\n=== TAMBAH STOK OBAT ===" << endl;
    tampilkanDaftarObat();
    cout << "Masukkan ID Obat: ";
    int id; cin >> id;
    Obat* o = cariObatById(id);
    if (!o) { cout << "[!] Obat tidak ditemukan." << endl; return; }

    cout << "Stok saat ini: " << o->getStok() << endl;
    cout << "Jumlah tambah: ";
    int jumlah; cin >> jumlah;
    try {
        o->tambahStok(jumlah);
        cout << "[OK] Stok berhasil ditambah. Stok sekarang: " << o->getStok() << endl;
    } catch (const exception& e) {
        cout << "[ERROR] " << e.what() << endl;
    }
}

void KlinikManager::lihatResepBelumDiambil() {
    cout << "\n=== RESEP BELUM DIAMBIL ===" << endl;
    bool ada = false;
    for (const auto& r : daftarResep) {
        if (!r.getSudahDiambil()) {
            r.tampilkanInfo();
            ada = true;
        }
    }
    if (!ada) cout << "  Semua resep sudah diambil." << endl;
}

void KlinikManager::prosesResep() {
    cout << "\n=== PROSES PENGAMBILAN OBAT ===" << endl;
    lihatResepBelumDiambil();

    cout << "Masukkan ID Resep: ";
    int id; cin >> id;
    Resep* r = cariResepById(id);
    if (!r) { cout << "[!] Resep tidak ditemukan." << endl; return; }
    if (r->getSudahDiambil()) { cout << "[!] Resep sudah diambil sebelumnya." << endl; return; }

    r->tampilkanInfo();

    // Cek dan kurangi stok
    bool cukup = true;
    for (const auto& item : r->getDaftarObat()) {
        Obat* o = cariObatById(item.idObat);
        if (!o || o->getStok() < item.jumlah) {
            cout << "[!!] Stok " << item.namaObat << " tidak mencukupi!" << endl;
            cukup = false;
        }
    }

    if (!cukup) {
        cout << "[!] Proses dibatalkan karena stok tidak mencukupi." << endl;
        return;
    }

    // Kurangi stok semua obat
    for (const auto& item : r->getDaftarObat()) {
        Obat* o = cariObatById(item.idObat);
        if (o) {
            o->kurangiStok(item.jumlah);
            if (o->isStokMenurun())
                cout << "[!!] PERINGATAN: Stok " << o->getNamaObat() << " menipis!" << endl;
        }
    }

    r->setSudahDiambil(true);
    cout << "[OK] Obat berhasil diberikan kepada pasien." << endl;
}

// ============================================================
//  MODUL LAPORAN
// ============================================================
void KlinikManager::tampilkanLaporanHarian() {
    laporan.tampilkanLaporanHarian(daftarKunjungan, daftarResep, daftarObat, tanggalHariIni);
}

void KlinikManager::tampilkanStokMenurun() {
    cout << "\n=== STOK OBAT MENIPIS ===" << endl;
    laporan.tampilkanObatMenurun(daftarObat);
}
