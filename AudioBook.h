#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "Book.h"

class AudioBook : public Book {
private:
    int thoiLuong;           // phút
    std::string nguoiDoc;
    std::string dinhDangAudio;  // MP3, M4A, ...

public:
    AudioBook();
    AudioBook(const std::string& ma, const std::string& ten, const std::string& tg,
              const std::string& tl, int nam, double gia, int sl,
              int thoiLuong, const std::string& nguoiDoc, const std::string& dinhDang);
    ~AudioBook() override;

    void hienThi(std::ostream& os) const override;
    double tinhPhiMuon(int soNgay) const override;   // tính theo thời lượng
    std::string getLoai() const override;
    void ghiFile(std::ostream& os) const override;
    void docFile(std::istream& is) override;
    void nhap(std::istream& is) override;

    int getThoiLuong() const;
    const std::string& getNguoiDoc() const;
    const std::string& getDinhDangAudio() const;
    void setThoiLuong(int tl);
    void setNguoiDoc(const std::string& nd);
    void setDinhDangAudio(const std::string& dd);
};

#endif
