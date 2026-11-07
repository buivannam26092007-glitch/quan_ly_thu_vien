#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

// Lớp trừu tượng: có hàm thuần ảo nên KHÔNG thể tạo đối tượng Book trực tiếp.
class Book {
protected:
    std::string maSach;
    std::string tenSach;
    std::string tacGia;
    std::string theLoai;
    int namXuatBan;
    double gia;
    int soLuong;      // số bản còn trong kho
    int soLanMuon;    // tổng số lần được mượn (phục vụ thống kê)

public:
    Book();
    Book(const std::string& ma, const std::string& ten, const std::string& tg,
         const std::string& tl, int nam, double gia, int sl);

    // BẮT BUỘC virtual: xóa Book* phải gọi đúng destructor lớp con.
    virtual ~Book();

    // ---- Hàm thuần ảo (làm Book trở thành abstract) ----
    virtual void hienThi(std::ostream& os) const = 0;
    virtual double tinhPhiMuon(int soNgay) const = 0;

    // ---- Hàm ảo thường ----
    virtual std::string getLoai() const = 0;              // "EBOOK" hoặc "AUDIO"
    virtual void ghiFile(std::ostream& os) const;         // ghi các trường chung, lớp con ghi tiếp
    virtual void docFile(std::istream& is);               // đọc các trường chung, lớp con đọc tiếp
    virtual void nhap(std::istream& is);                  // nhập từ bàn phím

    // ---- Getter ----
    const std::string& getMaSach() const;
    const std::string& getTenSach() const;
    const std::string& getTacGia() const;
    const std::string& getTheLoai() const;
    int getNamXuatBan() const;
    double getGia() const;
    int getSoLuong() const;
    int getSoLanMuon() const;

    // ---- Setter ----
    void setTenSach(const std::string& ten);
    void setTacGia(const std::string& tg);
    void setTheLoai(const std::string& tl);
    void setNamXuatBan(int nam);
    void setGia(double g);
    void setSoLuong(int sl);

    // ---- Nghiệp vụ nhỏ ----
    bool conSach() const;
    bool giamSoLuong();   // false nếu hết sách; tăng soLanMuon khi thành công
    void tangSoLuong();

    // ---- Nạp chồng toán tử ----
    bool operator==(const Book& other) const;   // so sánh theo mã sách
    bool operator<(const Book& other) const;    // so sánh theo tên sách
    friend std::ostream& operator<<(std::ostream& os, const Book& b);  // gọi hienThi (đa hình)
    friend std::istream& operator>>(std::istream& is, Book& b);        // gọi nhap (đa hình)
};

#endif
