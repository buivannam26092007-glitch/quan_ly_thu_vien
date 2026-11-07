#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

class EBook : public Book {
private:
    double dungLuong;      // MB
    std::string dinhDang;  // PDF, EPUB, ...
    std::string linkTai;

public:
    EBook();
    EBook(const std::string& ma, const std::string& ten, const std::string& tg,
          const std::string& tl, int nam, double gia, int sl,
          double dungLuong, const std::string& dinhDang, const std::string& link);
    ~EBook() override;

    void hienThi(std::ostream& os) const override;
    double tinhPhiMuon(int soNgay) const override;
    std::string getLoai() const override;
    void ghiFile(std::ostream& os) const override;
    void docFile(std::istream& is) override;
    void nhap(std::istream& is) override;

    double getDungLuong() const;
    const std::string& getDinhDang() const;
    const std::string& getLinkTai() const;
    void setDungLuong(double dl);
    void setDinhDang(const std::string& dd);
    void setLinkTai(const std::string& link);
};

#endif
