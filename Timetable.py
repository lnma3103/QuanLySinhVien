import os


class Timetable:
    def __init__(
        self,
        Tiet1,
        Tiet2="Khong hoc",
        Tiet3="Khong hoc",
        Tiet4="Khong hoc",
        Tiet5="Khong hoc",
        Chieu="Khong hoc",
    ):
        self.Tiet1 = Tiet1
        self.Tiet2 = Tiet2
        self.Tiet3 = Tiet3
        self.Tiet4 = Tiet4
        self.Tiet5 = Tiet5
        self.Chieu = Chieu

    def center(self, string, width):
        if len(string) == width:
            return string
        result = string
        space = width - len(string)
        for i in range(space):
            result += " "
        return result

    def print(self):
        if (
            self.Tiet2 == "Khong hoc"
            and self.Tiet3 == "Khong hoc"
            and self.Tiet4 == "Khong hoc"
            and self.Tiet5 == "Khong hoc"
            and self.Chieu == "Khong hoc"
        ):
            print("+------------+----------------------------------------------+")
            print("| Tiet hoc:  | Noi dung mon hoc:                            |")
            print("+------------+----------------------------------------------+")
            print("| Tiet 1:    | " + self.center(self.Tiet1, 44) + " |")
            print("+------------+----------------------------------------------+")
        else:
            print("+------------+----------------------------------------------+")
            print("| Tiet hoc:  | Noi dung mon hoc:                            |")
            print("+------------+----------------------------------------------+")
            print("| Tiet 1:    | " + self.center(self.Tiet1, 44) + " |")
            print("| Tiet 2:    | " + self.center(self.Tiet2, 44) + " |")
            print("| Tiet 3:    | " + self.center(self.Tiet3, 44) + " |")
            print("| Tiet 4:    | " + self.center(self.Tiet4, 44) + " |")
            print("| Tiet 5:    | " + self.center(self.Tiet5, 44) + " |")
            if self.Chieu != "Khong hoc":
                print("| Chieu:     | " + self.center(self.Chieu, 44) + " |")
            print("+------------+----------------------------------------------+")


def main():
    day = int(input("Nhap thu ban muon xem 2-7 (8 de thoat chuong trinh): "))
    while day != 8:
        if day == 2:
            print("Thoi khoa bieu thu hai: ")
            ThuHai = Timetable("Chao Co", "Vat Ly", "Toan", "Ngu Van", "Ngu Van")
            ThuHai.print()
        elif day == 3:
            print("Thoi khoa bieu thu ba: ")
            ThuBa = Timetable(
                "Sinh Hoc",
                "Tin Hoc",
                "Ngu Van",
                "Lich Su",
                "Lich Su",
                "The Duc 2h - Tiet 1 -> 2",
            )
            ThuBa.print()
        elif day == 4:
            print("Thoi khoa bieu thu tu: ")
            ThuTu = Timetable("Tieng Anh", "Tieng Anh", "Vat Ly", "Tin Hoc", "Hoa Hoc")
            ThuTu.print()
        elif day == 5:
            print("Thoi khoa bieu thu nam: ")
            ThuNam = Timetable(
                "Toan",
                "Toan",
                "Vat Ly",
                "Sinh Hoc",
                "Hoa Hoc",
                "Giao Duc Dia Phuong va Hoat Dong Trai Nghiem",
            )
            ThuNam.print()
        elif day == 6:
            print("Thoi khoa bieu thu sau: ")
            ThuSau = Timetable(
                "Toan", "Quoc Phong An Ninh", "Tieng Anh", "Hoa Hoc", "Sinh Hoc"
            )
            ThuSau.print()
        elif day == 7:
            print("Thoi khoa bieu thu bay: ")
            ThuBay = Timetable(
                "Toan",
                "Toan",
                "Vat Ly",
                "Sinh Hoc",
                "Hoa Hoc",
                "Giao Duc Dia Phuong va Hoat Dong Trai Nghiem",
            )
            ThuBay.print()
        else:
            print("Ngay khong hop le. Vui long nhap lai.")
        os.system("pause")
        os.system("clear")
        day = int(input("Nhap thu ban muon xem 2-7 (8 de thoat chuong trinh): "))


if __name__ == "__main__":
    main()
