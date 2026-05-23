#include "Person.h"
#include <iostream>
#include <stdexcept>

Person::Person() : id(0), nama(""), noTelepon(""), alamat("") {}

Person::Person(int id, const string& nama, const string& noTelepon, const string& alamat)
    : id(id), noTelepon(noTelepon), alamat(alamat) {
    setNama(nama);
}

Person::~Person() {}

int Person::getId() const { return id; }
string Person::getNama() const { return nama; }
string Person::getNoTelepon() const { return noTelepon; }
string Person::getAlamat() const { return alamat; }

void Person::setNama(const string& nama) {
    if (nama.empty()) throw invalid_argument("Nama tidak boleh kosong.");
    this->nama = nama;
}

void Person::setNoTelepon(const string& noTelepon) {
    if (noTelepon.empty()) throw invalid_argument("Nomor telepon tidak boleh kosong.");
    this->noTelepon = noTelepon;
}

void Person::setAlamat(const string& alamat) {
    if (alamat.empty()) throw invalid_argument("Alamat tidak boleh kosong.");
    this->alamat = alamat;
}
