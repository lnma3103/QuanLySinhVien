#include <iostream>
using namespace std;

string center(const std::string &str, int width) {
  if (str.length() == width) {
    return str;
  }
  string result = str;
  int space = width - str.length();
  for (int i = 0; i < space; i++) {
    result += " ";
  }
  return result;
}

struct Timetable {
  string t1, t2, t3, t4, t5, chieu;
  Timetable(string Tiet1, string Tiet2 = "Khong hoc",
            string Tiet3 = "Khong hoc", string Tiet4 = "Khong hoc",
            string Tiet5 = "Khong hoc", string Chieu = "Khong hoc")
      : t1(Tiet1), t2(Tiet2), t3(Tiet3), t4(Tiet4), t5(Tiet5), chieu(Chieu) {}
  void print() {
    if (t2 == "Khong hoc" && t3 == "Khong hoc" && t4 == "Khong hoc" &&
        t5 == "Khong hoc" && chieu == "Khong hoc") {
      cout << "+------------+----------------------------------------------+"
           << endl;
      cout << "| Tiet hoc:  | Noi dung mon hoc:                            |"
           << endl;
      cout << "+------------+----------------------------------------------+"
           << endl;
      cout << "| Tiet 1:    | " << center(t1, 44) << " |" << endl;
      cout << "+------------+----------------------------------------------+"
           << endl;
    } else {
      cout << "+------------+----------------------------------------------+"
           << endl;
      cout << "| Tiet hoc:  | Noi dung mon hoc:                            |"
           << endl;
      cout << "+------------+----------------------------------------------+"
           << endl;
      cout << "| Tiet 1:    | " << center(t1, 44) << " |" << endl;
      cout << "| Tiet 2:    | " << center(t2, 44) << " |" << endl;
      cout << "| Tiet 3:    | " << center(t3, 44) << " |" << endl;
      cout << "| Tiet 4:    | " << center(t4, 44) << " |" << endl;
      cout << "| Tiet 5:    | " << center(t5, 44) << " |" << endl;
      if (chieu != "Khong hoc") {
        cout << "| Chieu:     | " << center(chieu, 44) << " |" << endl;
      }
      cout << "+------------+----------------------------------------------+"
           << endl;
    }
  }
};

int main() {
  int day;
  do {
    system("clear");
    cout << "Nhap thu ban muon xem 2-7 (8 de thoat chuong trinh): ";
    cin >> day;
    switch (day) {
    case 2: {
      cout << "Thoi khoa bieu thu hai: " << endl;
      Timetable *ThuHai =
          new Timetable("Chao Co", "Vat Ly", "Toan", "Ngu Van", "Ngu Van");
      ThuHai->print();
      delete ThuHai;
      system("pause");
      system("clear");
      break;
    }
    case 3: {
      cout << "Thoi khoa bieu thu ba: " << endl;
      Timetable *ThuBa =
          new Timetable("Sinh Hoc", "Tin Hoc", "Ngu Van", "Lich Su", "Lich Su",
                        "The Duc 2h - Tiet 1 -> 2");
      ThuBa->print();
      delete ThuBa;
      system("pause");
      system("clear");
      break;
    }
    case 4: {
      cout << "Thoi khoa bieu thu tu: " << endl;
      Timetable *ThuTu = new Timetable("Tieng Anh", "Tieng Anh", "Vat Ly",
                                       "Tin Hoc", "Hoa Hoc");
      ThuTu->print();
      delete ThuTu;
      system("pause");
      system("clear");
      break;
    }
    case 5: {
      cout << "Thoi khoa bieu thu nam: " << endl;
      Timetable *ThuNam =
          new Timetable("Toan", "Toan", "Vat Ly", "Sinh Hoc", "Hoa Hoc",
                        "Giao Duc Dia Phuong va Hoat Dong Trai Nghiem");
      ThuNam->print();
      delete ThuNam;
      system("pause");
      system("clear");
      break;
    }
    case 6: {
      cout << "Thoi khoa bieu thu sau: " << endl;
      Timetable *ThuSau = new Timetable("Toan", "Quoc Phong An Ninh",
                                        "Tieng Anh", "Hoa Hoc", "Sinh Hoc");
      ThuSau->print();
      delete ThuSau;
      system("pause");
      system("clear");
      break;
    }
    case 7: {
      cout << "Thoi khoa bieu thu bay: " << endl;
      Timetable *ThuBay =
          new Timetable("Giao Duc Dia Phuong va Hoat Dong Trai Nghiem");
      ThuBay->print();
      delete ThuBay;
      system("pause");
      system("clear");
      break;
    }
    default: {
      cout << "Khong hop le!" << endl;
      system("pause");
      system("clear");
      break;
    }
    }
  } while (day != 8);
  return 0;
}