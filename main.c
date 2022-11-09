#include "main.h"

int main(int argc, char*__argv)
{
    system("cls");
    int c;
    do
    {
        c=getUserChoice();
        switch (c)
        {
        case 1:
            nhap_thong_tin("FU.txt");
            printf("Da nhap xong\n");
            system("pause");
            break;
        case 2:
            in_sach("FU.txt");
            system("pause");
            break;
        case 3:
            sap_xep_va_in("FU.txt","FU2022.txt");
            system("pause");
            break;
        case 4:
            tim_theo_ten_sach("FU.txt");
            system("pause");
            break;
        case 5:
            tim_theo_ten_tac_gia("FU.txt");
            system("pause");
            break;
        default:
            printf("Ban da thoat chuong trinh, Xin cam on!\n");
            system("pause");
            break;
        }
    } while ((c>0)&&(c<6));
    
    return 0;
}