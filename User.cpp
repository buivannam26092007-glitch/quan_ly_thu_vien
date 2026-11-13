#include "User.h"
#include <string>

using namespace std;

User::User() {
    maUser = "";
    hoTen = "";
    sdt = "";
}
User::User(const string& ma, const string& ten, const string& sdt) {
    this->maUser = ma;
    this->hoTen = ten;
    this->sdt = sdt;
}
const string& User::getMaUser() const {
    return maUser;
}
const string& User::getHoTen() const {
    return hoTen;
}
const string& User::getSdt() const {
    return sdt;
}
const vector<string>& User::getDsMaSachMuon() const {
    return dsMaSachMuon;
}
void User::setHoTen(const string& ten) {
    hoTen = ten;
}
void User::setSdt(const string& sdt) {
    this->sdt = sdt;
}
// Mượn trả
int User::soSachDangMuon() const {
    return dsMaSachMuon.size();
}
//Kiểm tra mã sách đã có trong danh sách mượn hay chưa
bool User::daMuon(const string& maSach) const {
    for (int i = 0; i < dsMaSachMuon.size(); i++) {
        if (dsMaSachMuon[i] == maSach) {
            return true; // Đã mượn
        }
    }
    return false; // Chưa mượn
}
bool User::coTheMuonThem() const {
    return dsMaSachMuon.size() < MAX_MUON; //MAX_MUON = 5
}
bool User::themSachMuon(const string& maSach) {
    // nếu đã mượn đủ 5 cuốn hoặc cuốn này đã mượn rồi thì không cho mượn nữa
    if (!coTheMuonThem() || daMuon(maSach)) {
        return false;
    }
    dsMaSachMuon.push_back(maSach);
    return true;
}
bool User::xoaSachMuon(const string& maSach) {
    for(int i = 0; i < dsMaSachMuon.size(); i++) {
        if(dsMaSachMuon[i] == maSach) {
            dsMaSachMuon.erase(dsMaSachMuon.begin() + i); // xoá phần tử tại vị trí i trong vector
            return true;
        }
    }
    return false; // không tìm thấy mã sách để xoá 
}

// Đọc và ghi file
// Định dạng dòng: maUser|hoTen|sdt|soLuongSach|maSach1|maSach2|
void User::ghiFile(ostream& os) const {
    os << maUser << "|" << hoTen << "|" << sdt << "|" << dsMaSachMuon.size() << "|";
    for (int i = 0; i < dsMaSachMuon.size(); i++) {
        os << dsMaSachMuon[i] << "|";
    }
    os << endl;
}
void User::docFile(istream& is) {
    if (!getline(is, maUser, '|')) { // đọc từng thông tin ngăn cách bởi dấu '|'
        return; // dừng khi hết file
    }
    getline(is, hoTen, '|');
    getline(is, sdt, '|');
    // đọc số lượng sách đang mượn
    string strSoLuong; 
    getline(is, strSoLuong, '|');
    int soLuong = stoi(strSoLuong); // đổi chuỗi sang số nguyên
    // đọc danh sách từng mã sách
    dsMaSachMuon.clear();
    for(int i = 0; i < soLuong; i++) {
        string maSach;
        getline (is, maSach, '|');
        dsMaSachMuon.push_back(maSach);
    }
    string boQuaXuongDong;
    getline(is, boQuaXuongDong);
}
// nạp chồng toán tử
bool User::operator==(const User& other) const {
    return this-> maUser == other.maUser;
}
ostream& operator<<(ostream& os, const User& u) {
    os << "Ma User: " << u.maUser
       << " | Ho ten: " << u.hoTen
       << " | SDT: " << u.sdt
       << " | Sach dang muon (" << u.soSachDangMuon() << "/" << User::MAX_MUON << "): ";
    if (u.dsMaSachMuon.empty()) {
        os << "Khong co";
    } else {
        for(int i = 0; i < u.dsMaSachMuon.size(); i++) {
            os << u.dsMaSachMuon[i] << " ";
        }
    }
    return os;
}
istream& operator >> (istream& is, User& u) {
    cout << "Nhap ma user: ";
    getline(is >> ws, u.maUser);
    cout << "Nhap ho va ten: ";
    getline(is >> ws, u.hoTen);
    cout << "Nhap so dien thoai: ";
    getline(is >> ws, u.sdt);
    u.dsMaSachMuon.clear(); //User mới tạo chưa mượn sách nào
    return is;
}