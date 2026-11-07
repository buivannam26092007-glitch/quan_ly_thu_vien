#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>

class User {
private:
    std::string maUser;
    std::string hoTen;
    std::string sdt;
    std::vector<std::string> dsMaSachMuon;   // chỉ lưu MÃ sách, không lưu con trỏ

public:
    static const int MAX_MUON = 5;   // giới hạn số sách mượn cùng lúc

    User();
    User(const std::string& ma, const std::string& ten, const std::string& sdt);

    // ---- Getter / Setter ----
    const std::string& getMaUser() const;
    const std::string& getHoTen() const;
    const std::string& getSdt() const;
    const std::vector<std::string>& getDsMaSachMuon() const;
    void setHoTen(const std::string& ten);
    void setSdt(const std::string& sdt);

    // ---- Nghiệp vụ mượn/trả (phía User) ----
    int soSachDangMuon() const;
    bool daMuon(const std::string& maSach) const;
    bool coTheMuonThem() const;                  // chưa đạt MAX_MUON
    bool themSachMuon(const std::string& maSach);   // false nếu đã mượn hoặc đạt giới hạn
    bool xoaSachMuon(const std::string& maSach);    // false nếu không có trong danh sách

    // ---- File ----
    void ghiFile(std::ostream& os) const;
    void docFile(std::istream& is);   // đọc 1 dòng đã ghi bởi ghiFile

    // ---- Nạp chồng toán tử ----
    bool operator==(const User& other) const;   // so theo mã user
    friend std::ostream& operator<<(std::ostream& os, const User& u);
    friend std::istream& operator>>(std::istream& is, User& u);
};

#endif
