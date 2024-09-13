#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<string> vt_Str;

vt_Str Split(const string &str, char delimiter) {
  vt_Str result;
  string token;
  stringstream ss(str);
  while (getline(ss, token, delimiter)) {
    result.push_back(token);
  }
  return result;
}

string space_left(string str, int width) {
  string result = str;
  while (result.length() < width) {
    result += " ";
  }
  return result;
}

string fixed_diem(float diem) {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << diem;
  return stream.str();
}

struct SinhVien {
  string ten;
  int tuoi;
  float diem;
  SinhVien(string ten, int tuoi, float diem)
      : ten(ten), tuoi(tuoi), diem(diem) {}
};

void docFile(string path, vector<SinhVien> &sv_list) {
  ifstream file(path);
  if (!file.is_open()) {
    cout << "Khong the mo file " << path << endl;
    return;
  }
  string line;
  while (getline(file, line)) {
    vt_Str tokens = Split(line, ';');
    if (tokens.size() == 3) {
      sv_list.push_back(SinhVien(tokens[0], stoi(tokens[1]), stof(tokens[2])));
    }
  }
  file.close();
}

void inDanhSachSinhVien(vector<SinhVien> &sv_list) {
  const int WIDTH = 7;
  const int WIDTH_TEN = 23;
  const int WIDTH_TUOI_DIEM = 11;
  cout << "\t+--------+-----------------------+----------+----------+\n";
  cout << "\t| STT    | Ten Sinh Vien         | Tuoi     | Diem     |\n";
  cout << "\t+--------+-----------------------+----------+----------+\n";
  for (int i = 0; i < sv_list.size(); i++) {
    cout << "\t| " << space_left(to_string(i + 1), 7) << "| "
         << space_left(sv_list[i].ten, 22) << "| "
         << space_left(to_string(sv_list[i].tuoi), 9) << "| "
         << space_left(fixed_diem(sv_list[i].diem), 9) << "|\n";
  }
  cout << "\t+--------+-----------------------+----------+----------+\n";
}

void themSinhVien(vector<SinhVien> &sv_list) {
  string ten;
  int tuoi;
  float diem;
  cout << "\t(?) Nhap ten: ";
  cin.ignore();
  getline(cin, ten);
  cout << "\t(?) Nhap tuoi: ";
  cin >> tuoi;
  cout << "\t(?) Nhap diem: ";
  cin >> diem;
  sv_list.push_back(SinhVien(ten, tuoi, diem));
  cout << "\t(!) Da them sinh vien co ten " << ten << ", tuoi " << tuoi
       << ", diem " << diem << " vao danh sach\n";
}

void suaThongTinSinhVien(vector<SinhVien> &sv_list) {
  inDanhSachSinhVien(sv_list);
  int stt;
  cout << "\t(?) Nhap stt sinh vien can sua: ";
  cin >> stt;
  cout << "\t\t(+) 1 - Sua ten\n";
  cout << "\t\t(+) 2 - Sua tuoi\n";
  cout << "\t\t(+) 3 - Sua diem\n";
  cout << "\t\t(+) 4 - Cap nhat thong tin moi cho sinh vien\n";
  cout << "\t\t(?) Lua chon: ";
  int luaChon;
  cin >> luaChon;
  switch (luaChon) {
  case 1: {
    string ten;
    cout << "\t\t(?) Nhap ten moi: ";
    cin.ignore();
    getline(cin, ten);
    cout << "\t\t(!) Da sua ten sinh vien " << sv_list[stt - 1].ten << " -> "
         << ten << endl;
    sv_list[stt - 1].ten = ten;
    break;
  }
  case 2: {
    int tuoi;
    cout << "\t\t(?) Nhap tuoi moi: ";
    cin >> tuoi;
    cout << "\t\t(!) Da sua tuoi sinh vien " << sv_list[stt - 1].ten << " -> "
         << tuoi << endl;
    sv_list[stt - 1].tuoi = tuoi;
    break;
  }
  case 3: {
    float diem;
    cout << "\t\t(?) Nhap diem moi: ";
    cin >> diem;
    cout << "\t\t(!) Da sua diem sinh vien " << sv_list[stt - 1].ten << " -> "
         << diem << endl;
    sv_list[stt - 1].diem = diem;
    break;
  }
  case 4: {
    string ten;
    int tuoi;
    float diem;
    cout << "\t\t(?) Nhap ten moi: ";
    cin.ignore();
    getline(cin, ten);
    cout << "\t\t(?) Nhap tuoi moi: ";
    cin >> tuoi;
    cout << "\t\t(?) Nhap diem moi: ";
    cin >> diem;
    cout << "\t\t(!) Da sua thong tin sinh vien " << sv_list[stt - 1].ten
         << " -> " << ten << ", " << tuoi << ", " << diem << endl;
    sv_list[stt - 1].ten = ten;
    sv_list[stt - 1].tuoi = tuoi;
    sv_list[stt - 1].diem = diem;
    break;
  }
  default: {
    cout << "\t[?] Lua chon khong hop le\n";
    break;
  }
  }
}

void xoaSinhVien(vector<SinhVien> &sv_list) {
  inDanhSachSinhVien(sv_list);
  int stt;
  cout << "\t(?) Nhap stt sinh vien can xoa: ";
  cin >> stt;
  cout << "\t(!) Da xoa sinh vien " << sv_list[stt - 1].ten
       << " khoi danh sach!" << endl;
  sv_list.erase(sv_list.begin() + stt - 1);
}

void thongKeSinhVien(vector<SinhVien> &sv_list) {
  int sv_gioi = 0, sv_kha = 0, sv_trungBinh = 0, sv_yeu = 0;
  float max_diem = 0, tong_diem = 0;
  for (int i = 0; i < sv_list.size(); i++) {
    if (sv_list[i].diem >= 8) {
      sv_gioi++;
    } else if (sv_list[i].diem >= 6.5) {
      sv_kha++;
    } else if (sv_list[i].diem >= 5) {
      sv_trungBinh++;
    } else {
      sv_yeu++;
    }
    if (sv_list[i].diem > max_diem) {
      max_diem = sv_list[i].diem;
    }
    tong_diem += sv_list[i].diem;
  }
  cout << "\t(+) Diem trung binh ca lop: "
       << fixed_diem(tong_diem / sv_list.size()) << endl;
  cout << "\t(+) Ti le sinh vien gioi: "
       << fixed_diem(sv_gioi * 100.0 / sv_list.size()) << "%\n";
  cout << "\t(+) Ti le sinh vien kha: "
       << fixed_diem(sv_kha * 100.0 / sv_list.size()) << "%\n";
  cout << "\t(+) Ti le sinh vien trung binh: "
       << fixed_diem(sv_trungBinh * 100.0 / sv_list.size()) << "%\n";
  cout << "\t(+) Ti le sinh vien yeu: "
       << fixed_diem(sv_yeu * 100.0 / sv_list.size()) << "%\n";
  cout << "\t(+) Sinh vien co diem cao nhat " << max_diem << " la: " << endl;
  for (int i = 0; i < sv_list.size(); i++) {
    if (sv_list[i].diem == max_diem) {
      cout << "\t\t- " << sv_list[i].ten << endl;
    }
  }
}

string to_lower_name(string name) {
  for (int i = 0; i < name.length(); i++) {
    name[i] = tolower(name[i]);
  }
  return name;
}

void timKiemSinhVien(vector<SinhVien> &sv_list) {
  string ten;
  vt_Str ten_list;
  vt_Str ten_list_lower;
  for (int i = 0; i < sv_list.size(); i++) {
    ten_list.push_back(sv_list[i].ten);
  }
  for (int i = 0; i < ten_list.size(); i++) {
    ten_list_lower.push_back(to_lower_name(ten_list[i]));
  }
  cout << "\t(?) Nhap ten sinh vien can tim: ";
  cin.ignore();
  getline(cin, ten);
  cout << "\t+--------+-----------------------+----------+----------+\n";
  cout << "\t| STT    | Ten Sinh Vien         | Tuoi     | Diem     |\n";
  cout << "\t+--------+-----------------------+----------+----------+\n";
  for (int i = 0; i < sv_list.size(); i++) {
    if (ten_list[i].find(ten) != string::npos) {
      cout << "\t| " << space_left(to_string(i + 1), 7) << "| "
           << space_left(sv_list[i].ten, 22) << "| "
           << space_left(to_string(sv_list[i].tuoi), 9) << "| "
           << space_left(fixed_diem(sv_list[i].diem), 9) << "|\n";
    } else if (ten_list_lower[i].find(ten) != string::npos) {
      cout << "\t| " << space_left(to_string(i + 1), 7) << "| "
           << space_left(sv_list[i].ten, 22) << "| "
           << space_left(to_string(sv_list[i].tuoi), 9) << "| "
           << space_left(fixed_diem(sv_list[i].diem), 9) << "|\n";
    }
  }
  cout << "\t+--------+-----------------------+----------+----------+\n";
}

void luuDanhSachSinhVien(vector<SinhVien> &sv_list) {
  ofstream file("..\\Data.txt");
  for (int i = 0; i < sv_list.size(); i++) {
    file << sv_list[i].ten << ";" << sv_list[i].tuoi << ";" << sv_list[i].diem
         << endl;
  }
  file.close();
}

int main() {
  vector<SinhVien> sv_list;
  docFile("..\\Data.txt", sv_list);
  int luaChon;
  do {
    // Hiển thị danh sách các chức năng
    cout << "Danh sach thao tac:\n";
    cout << "1 - In ra danh sach sinh vien\n";
    cout << "2 - Them sinh vien\n";
    cout << "3 - Sua thong tin sinh vien\n";
    cout << "4 - Xoa sinh vien\n";
    cout << "5 - Thong ke sinh vien\n";
    cout << "6 - Tim kiem sinh vien\n";
    cout << "7 - Luu danh sach sinh vien vao file\n";
    cout << "8 - Thoat\n";
    cout << "Nhap lenh: ";
    cin >> luaChon;
    switch (luaChon) {
    case 1: {
      cout << "[1] In ra danh sach sinh vien\n";
      inDanhSachSinhVien(sv_list);
      system("pause");
      system("cls");
      break;
    }
    case 2: {
      cout << "[2] Them sinh vien\n";
      themSinhVien(sv_list);
      system("pause");
      system("cls");
      break;
    }
    case 3: {
      cout << "[3] Sua thong tin sinh vien\n";
      suaThongTinSinhVien(sv_list);
      system("pause");
      system("cls");
      break;
    }
    case 4: {
      cout << "[4] Xoa sinh vien\n";
      xoaSinhVien(sv_list);
      system("pause");
      system("cls");
      break;
    }
    case 5: {
      cout << "[5] Thong ke sinh vien\n";
      thongKeSinhVien(sv_list);
      system("pause");
      system("cls");
      break;
    }
    case 6: {
      cout << "[6] Tim kiem sinh vien\n";
      timKiemSinhVien(sv_list);
      system("pause");
      system("cls");
      break;
    }
    case 7: {
      cout << "[7] Luu danh sach sinh vien vao file\n";
      inDanhSachSinhVien(sv_list);
      luuDanhSachSinhVien(sv_list);
      system("pause");
      system("cls");
      break;
    }
    case 8: {
      cout << "[8] Thoat\n";
      break;
    }
    default: {
      cout << "[?] Lua chon khong hop le\n";
      break;
    }
    }
  } while (luaChon != 8);
  return 0;
}
