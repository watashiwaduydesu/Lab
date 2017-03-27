#include <iostream>
#include <math.h>
using namespace std;
#define EPSILON 1.0E-13

void main()
{
	double a=0, b=0, c=0;
	enum loaitamgiac { TAM_GIAC_DEU , TAM_GIAC_CAN, TAM_GIAC_VUONG_CAN, TAM_GIAC_VUONG,TAM_GIAC_THUONG,KHONG_LA_TAM_GIAC};
	loaitamgiac tamgiac;
	cout << "Nhap canh a:"; cin >> a;
	cout << "Nhap canh b:"; cin >> b;
	cout << "Nhap canh c:"; cin >> c;
	if (a + b > c && a + c > b && b + c > a)
	{
		//cap (a,b)
		if (abs(a - b) < EPSILON)
		{
			if (abs(a - c) < EPSILON)
			{
				tamgiac = TAM_GIAC_DEU;
			}
			else
			{
				if (abs((a*a + b*b) - c*c) < EPSILON)
				{
					tamgiac = TAM_GIAC_VUONG_CAN;
				}
				else
				{
					tamgiac = TAM_GIAC_CAN;
				}
			}
		}
		else
		{
			if ((abs((a*a + b*b) - c*c) < EPSILON))
			{
				tamgiac = TAM_GIAC_VUONG;
			}
			else
			{
				tamgiac = TAM_GIAC_THUONG;
			}
		}
		//cap (a,c)
		if (tamgiac == TAM_GIAC_THUONG)
		{
			if (abs(a - c) < EPSILON)
			{
				if (abs((a*a + c*c) - b*b) < EPSILON)
				{
					tamgiac = TAM_GIAC_VUONG_CAN;
				}
				else
				{
					tamgiac = TAM_GIAC_CAN;
				}
			}
			else
			{
				if (abs((a*a + c*c) - b*b) < EPSILON)
				{
					tamgiac = TAM_GIAC_VUONG;
				}
				else
				{
					tamgiac = TAM_GIAC_THUONG;
				}
			}
		}
		//cap (b,c)
		if (tamgiac == TAM_GIAC_THUONG)
		{
			if (abs(a - c) < EPSILON)
			{
				if (abs((a*a + c*c) - b*b) < EPSILON)
				{
					tamgiac = TAM_GIAC_VUONG_CAN;
				}
				else
				{
					tamgiac = TAM_GIAC_CAN;
				}
			}
			else
			{
				if (abs((a*a + c*c) - b*b) < EPSILON)
				{
					tamgiac = TAM_GIAC_VUONG;
				}
				else
				{
					tamgiac = TAM_GIAC_THUONG;
				}
			}
		}

	}
	else
	{
		tamgiac = KHONG_LA_TAM_GIAC;
	}
	
	switch (tamgiac)
	{
	case TAM_GIAC_CAN: cout << "Tam giac can.\n"; break;
	case TAM_GIAC_DEU: cout << "Tam giac deu.\n"; break;
	case TAM_GIAC_VUONG: cout << "Tam giac vuong.\n"; break;
	case TAM_GIAC_VUONG_CAN: cout << "Tam giac vuong can.\n"; break;
	case TAM_GIAC_THUONG: cout << "Tam giac thuong.\n"; break;
	case KHONG_LA_TAM_GIAC: cout << "Khong la tam giac.\n"; break;
	}
	system("pause");
}