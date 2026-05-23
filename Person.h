#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

// Abstract base class - menerapkan Abstraction dan sebagai dasar Inheritance
class Person {
protected:
    int id;
    string nama;
    string noTelepon;
    string alamat;

public:
    Person();
    Person(int id, const string& nama, const string& noTelepon, const string& alamat);
    virtual ~Person();

    // Getter
    int getId() const;
    string getNama() const;
    string getNoTelepon() const;
    string getAlamat() const;

    // Setter dengan validasi
    void setNama(const string& nama);
    void setNoTelepon(const string& noTelepon);
    void setAlamat(const string& alamat);

    // Pure virtual function - wajib diimplementasikan oleh turunan (Abstraction + Polymorphism)
    virtual void tampilkanInfo() const = 0;
    virtual string getRole() const = 0;
};

#endif
