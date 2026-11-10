
#include "AudioBook.h"
#include <iostream>
#include <limits>
using namespace std;

// Ham khoi tao mac dinh
AudioBook::AudioBook() : Book() {
    thoiLuong = 0;
    nguoiDoc = "";
    dinhDangAudio = "";
}
AudioBook::AudioBook(const string& ma, const string& ten,
    const string& tg, const string& tl,
    int nam, double gia, int sl,
    int thoiLuong, const string& nguoiDoc,
    const string& dinhDang)
    : Book(ma, ten, tg, tl, nam, gia, sl) {

    this->thoiLuong = thoiLuong;
    this->nguoiDoc = nguoiDoc;
    this->dinhDangAudio = dinhDang;
}
AudioBook::~AudioBook() {
}

void AudioBook::hienThi(ostream& os) const {
    Book::hienThi(os);

    os << "Thoi luong: " << thoiLuong << " phut" << endl;
    os << "Nguoi doc: " << nguoiDoc << endl;
    os << "Dinh dang audio: " << dinhDangAudio << endl;
}

double AudioBook::tinhPhiMuon(int soNgay) const {
    return thoiLuong * soNgay * 1000.0;
}


string AudioBook::getLoai() const {
    return "AUDIO";
}


void AudioBook::ghiFile(ostream& os) const {
    Book::ghiFile(os);

    os << thoiLuong << endl;
    os << nguoiDoc << endl;
    os << dinhDangAudio << endl;
}


void AudioBook::docFile(istream& is) {
    Book::docFile(is);

    is >> thoiLuong;
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(is, nguoiDoc);
    getline(is, dinhDangAudio);
}


void AudioBook::nhap(istream& is) {
    Book::nhap(is);

    cout << "Nhap thoi luong (phut): ";
    is >> thoiLuong;
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap nguoi doc: ";
    getline(is, nguoiDoc);

    cout << "Nhap dinh dang audio: ";
    getline(is, dinhDangAudio);
}


int AudioBook::getThoiLuong() const {
    return thoiLuong;
}

const string& AudioBook::getNguoiDoc() const {
    return nguoiDoc;
}

const string& AudioBook::getDinhDangAudio() const {
    return dinhDangAudio;
}


void AudioBook::setThoiLuong(int tl) {
    thoiLuong = tl;
}

void AudioBook::setNguoiDoc(const string& nd) {
    nguoiDoc = nd;
}

void AudioBook::setDinhDangAudio(const string& dd) {
    dinhDangAudio = dd;
}
