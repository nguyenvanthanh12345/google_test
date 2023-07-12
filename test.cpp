#include "pch.h"
#include"string.h"
#include"stdio.h"
enum LoaiTamGiac {
    TamGiacKhongTonTai,
    TamGiacDeu,
    TamGiacCan,
    TamGiacVuong,
    TamGiacThuong
};

class ArraySorter {
private:
    int* arr;
    int size;

public:
    ArraySorter(int array[], int arraySize) : arr(array), size(arraySize) {}

    void BubbleSort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Hoán đổi giá trị của hai phần tử
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void PrintArray() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};


LoaiTamGiac XacDinhLoaiTamGiac(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return TamGiacKhongTonTai;
    }

    if (a == b && b == c) {
        return TamGiacDeu;
    }

    if (a == b || b == c || c == a) {
        return TamGiacCan;
    }

    double maxSide = std::max(a, std::max(b, c));
    double sumSquares = a * a + b * b + c * c;

    if (2 * maxSide * maxSide == sumSquares) {
        return TamGiacVuong;
    }

    return TamGiacThuong;
}
TEST(XacDinhLoaiTamGiac, tamGiacKhongTonTai_1) {
  EXPECT_EQ(XacDinhLoaiTamGiac(0,2,4), TamGiacKhongTonTai);
}

TEST(XacDinhLoaiTamGiac, tamGiacKhongTonTai_2) {
    EXPECT_EQ(XacDinhLoaiTamGiac(2, 0, 4), TamGiacKhongTonTai);
}

TEST(XacDinhLoaiTamGiac, tamGiacKhongTonTai_3) {
    EXPECT_EQ(XacDinhLoaiTamGiac(2, 3, 0), TamGiacKhongTonTai);
}

TEST(XacDinhLoaiTamGiac, tamGiacDeu) {
    EXPECT_EQ(XacDinhLoaiTamGiac(2, 2, 2), TamGiacDeu);
}

TEST(XacDinhLoaiTamGiac, tamGiacCan_1) {
    EXPECT_EQ(XacDinhLoaiTamGiac(2, 2, 5), TamGiacCan);
}

TEST(XacDinhLoaiTamGiac, tamGiacCan_2) {
    EXPECT_EQ(XacDinhLoaiTamGiac(2, 3, 3), TamGiacCan);
}

TEST(XacDinhLoaiTamGiac, tamGiacCan_3) {
    EXPECT_EQ(XacDinhLoaiTamGiac(2, 5, 2), TamGiacCan);
}

TEST(XacDinhLoaiTamGiac, tamGiacVuong1) {
    EXPECT_EQ(XacDinhLoaiTamGiac(3, 4, 5), TamGiacVuong);
}

TEST(XacDinhLoaiTamGiac, tamGiacThuong) {
    EXPECT_EQ(XacDinhLoaiTamGiac(2, 6, 4), TamGiacThuong);
}

TEST(ArraySorter, BubbleSort) {
    int a[5] = { 1,4,2,5,3};
    int b[5] = { 1,2,3,4,5 };
    ArraySorter arr_sort(a, 5);
    arr_sort.BubbleSort();
    EXPECT_EQ(memcmp(a,b,5), 0);
}