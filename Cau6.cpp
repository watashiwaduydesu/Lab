#include <iostream>
using namespace std;

void main()
{
	typedef enum menu {NHAP_HH=1, TIM_HH, IN_DS_HH, XOA_HH, CAP_NHAT_HH, LUU_DL, TAI_DL, THOAT};
	menu choice;

	printf("1. Nhap hang hoa\n");
	printf("2. Tim hang hoa\n");
	printf("3. In ra danh sach hang hoa\n");
	printf("4. Xoa hang hoa\n");
	printf("5. Cap nhat hang hoa\n");
	printf("6. Luu du lieu\n");
	printf("7. Tai du lieu\n");
	printf("8. Thoat\n");
	printf("Hay chon chuc nang:");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case NHAP_HH: cout << "Nhap hang hoa\n"; break;
	case TIM_HH: cout << "Tim hang hoa\n"; break;
	case IN_DS_HH: cout << "In ra danh sach hang hoa\n"; break;
	case XOA_HH: cout << "Xoa hang hoa\n"; break;
	case CAP_NHAT_HH: cout << "Cap nhat hang hoa\n"; break;
	case LUU_DL: cout << "Luu du lieu\n"; break;
	case TAI_DL: cout << "Tai du lieu\n"; break;
	case THOAT: cout << "Thoat\n"; break;
	default: cout << "Loi nhap\n"; break;
	}

	system("pause");
}
