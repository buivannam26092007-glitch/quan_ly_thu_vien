#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<Book*> dsSach;   // Library GIỮ con trỏ và chịu trách nhiệm delete (xem destructor)
    std::vector<User> dsUser;

    int timViTriSach(const std::string& ma) const;   // -1 nếu không thấy
    int timViTriUser(const std::string& ma) const;   // -1 nếu không thấy
    void xoaToanBoSach();                            // delete mọi Book* rồi clear

public:
    Library();
    ~Library();                                  // delete các Book*
    Library(const Library&) = delete;            // chặn copy: tránh 2 Library cùng trỏ 1 vùng nhớ
    Library& operator=(const Library&) = delete;

    // ================= CRUD SÁCH =================
    bool themSach(Book* b);                                     // false nếu trùng mã. Library nhận quyền sở hữu b
    bool suaSach(const std::string& ma, Book* sachMoi);         // thay sách cũ bằng sachMoi, delete sách cũ
    bool xoaSach(const std::string& ma);
    Book* timTheoMa(const std::string& ma) const;               // nullptr nếu không thấy
    std::vector<Book*> timTheoTen(const std::string& tuKhoa) const;     // chứa chuỗi, không phân biệt hoa thường
    std::vector<Book*> timTheoTacGia(const std::string& tuKhoa) const;
    std::vector<Book*> timTheoTheLoai(const std::string& theLoai) const;

    // ================= CRUD USER =================
    bool themUser(const User& u);       // false nếu trùng mã
    bool xoaUser(const std::string& ma);   // false nếu không thấy hoặc còn sách chưa trả
    User* timUser(const std::string& ma);

    // ================= NGHIỆP VỤ THỰC TẾ =================
    bool muonSach(const std::string& maUser, const std::string& maSach, std::string& thongBao);
    bool traSach(const std::string& maUser, const std::string& maSach, std::string& thongBao);
    double tinhPhiMuon(const std::string& maSach, int soNgay) const;    // -1 nếu không có sách

    // ================= THỐNG KÊ =================
    int demTheoLoai(const std::string& loai) const;       // "EBOOK" hoặc "AUDIO"
    double tongGiaTriKho() const;
    Book* sachMuonNhieuNhat() const;                      // nullptr nếu kho rỗng
    void thongKe(std::ostream& os) const;                 // in tổng hợp các thống kê trên

    // ================= LỌC (trả về danh sách mới, không sửa kho) =================
    std::vector<Book*> locTheoTheLoai(const std::string& theLoai) const;
    std::vector<Book*> locTheoNam(int tuNam, int denNam) const;
    std::vector<Book*> locConSach() const;
    std::vector<Book*> locHetSach() const;

    // ================= SẮP XẾP (sắp xếp trực tiếp dsSach) =================
    void sapXepTheoTen();     // dùng operator<
    void sapXepTheoNam();
    void sapXepTheoGia();

    // ================= HIỂN THỊ =================
    void hienThiDanhSach(std::ostream& os) const;
    static void hienThiDanhSach(std::ostream& os, const std::vector<Book*>& ds);   // in kết quả tìm/lọc
    void hienThiDanhSachUser(std::ostream& os) const;

    // ================= FILE =================
    bool ghiFileSach(const std::string& duongDan) const;
    bool docFileSach(const std::string& duongDan);    // xóa dữ liệu cũ, đọc lại; dòng đầu mỗi sách là loại
    bool ghiFileUser(const std::string& duongDan) const;
    bool docFileUser(const std::string& duongDan);
};

#endif
