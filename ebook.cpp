#include "Ebook.h"

Ebook::Ebook() : Book(), dungLuong(0.0), dinhDang(""), linkTai(""){}
Ebook::Ebook(const string& ma, const string& ten, const string& tg,
             const string& tl, int nam, double gia,
             int sl, double dungLuong, const string& dinhDang, const string& link): Book(ma, ten, tg, tl, nam, gia, sl){
                this->dungLuong=dungLuong;
                this->dinhDang = dinhDang;
                this->linkTai = link;
}
Ebook::~Ebook(){}
//hien thi thong tin
void Ebook::hienThi(ostream& os) const{
    os<<"   Thong tin ve Ebook  \n"
      <<"Ma sach: "<< maSach<<"\n"
      <<"Ten sach: "<< tenSach <<"\n"
      <<"Tac gia: "<< tacGia<<"\n"
      <<"The loai: "<< theLoai<<"\n"
      <<"Nam xuat ban: "<< namXuatBan<<"\n"
      <<"Gia: "<<gia<<"\n"
      <<"So luong con lai: "<< soLuong<<"\n"
      <<"So lan muon: "<< soLanMuon<<"\n"
      << "Dung luong: " << dungLuong << " MB\n"
      << "Dinh dang: " << dinhDang << "\n"
      << "Link tai: " << linkTai << "\n";
}

double Ebook::tinhPhiMuon(int soNgay) const {
    return soNgay * 1000.0;
}
string EBook::getLoai() const{
    return "EBOOK";
}

void Ebook::ghiFile(ostream& os) const{
    os<<"EBOOK\n";
    Book::ghiFile(os);
    os << dungLuong << "\n";
       << dinhDang << "\n";
       << linkTai <<"\n";
}

void Ebook::docFile(istream& is){
    Book::docFile(is);
    is >> dungLuong;
    is.ignore();
    getline(is, dinhDang);
    getline(is, linkTai);
}

void EBook::nhap(istream& is){
    Book::nhap(is);
    cout<<"Nhap dung luong (MB): ";
    is>>dungLuong;
    is.ignore();
    cout << "Nhap dinh dang (PDF, EPUB,...): ";
    getline(is, dinhDang);
    cout << "Nhap link tai: ";
    getline(is, linkTai);
}
double EBook::getDungLuong() const{
    return dungLuong;
}
const std::string& EBook::getDinhDang() const {
    return dinhDang;
}

const std::string& EBook::getLinkTai() const {
    return linkTai;
}

void EBook::setDungLuong(double dl) {
    dungLuong = dl;
}

void EBook::setDinhDang(const std::string& dd) {
    dinhDang = dd;
}

void EBook::setLinkTai(const std::string& link) {
    linkTai = link;
}
