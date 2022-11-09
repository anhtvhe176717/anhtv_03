#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int getUserChoice();
//Yêu cầu người dùng chọn chức năng từ Menu

void nhap_thong_tin(char *filename);
//Nhập thông tin n cuốn sách lưu vào file

void in_sach(char *filename);
//In ra màn hình thông tin vừa nhập hoặc thông tin có sẵn  trong file

void sap_xep_va_in(char *filename1, char *filename2);
//Sắp xếp theo năm giảm dần rồi theo giá giảm dần

void tim_theo_ten_sach(char *filename);
//Tìm kiếm theo tên sách

void tim_theo_ten_tac_gia(char *filename);
//Tìm kiếm theo tên tác giả

int getUserChoice()
{
    int choice;
    printf("====================================\n");
    printf("1. Nhap thong tin cua n cuon sach FU\n");
    printf("2. In ra man hinh thong tin vua nhap\n");
    printf("3. Sap xep thong tin giam dan theo nam xuat ban va hien thi\n");
    printf("4. Tim kiem theo ten sach\n");
    printf("5. Tim kiem theo ten tac gia\n");
    printf("6. Thoat\n");
    printf("====================================\n");
    printf("Lua chon chuc nang: \n");
    fflush(stdin);
    scanf("%d",&choice);
    return choice;
}

void nhap_thong_tin(char *filename)
{
    system("cls");
    FILE *f=fopen(filename,"w+");
    int n,price,year;
    printf("So cuon sach can nhap thong tin: \n");
    scanf("%d",&n);
    fprintf(f,"%d\n",n);
    char s[100];
    for(int i=1;i<=n;i++)
    {
        printf("Nhap ten sach %d: ",i);fflush(stdin);
        scanf("%[^\n]",&s);fprintf(f,"%s\n",s);
        printf("Nhap ten tac gia %d: ",i);fflush(stdin);
        scanf("%[^\n]",&s);fprintf(f,"%s\n",s);
        printf("Nhap ten nha xuat ban %d: ",i);fflush(stdin);
        scanf("%[^\n]",&s);fprintf(f,"%s\n",s);
        printf("Nhap nam san xuat %d: ",i);fflush(stdin);
        scanf("%d",&year);fprintf(f,"%d\n",year);
        printf("Nhap gia sach %d: ",i);fflush(stdin);
        scanf("%d",&price);fprintf(f,"%d\n\n",price);
        printf("\n");
    }

    fclose(f);
}

void in_sach(char *filename)
{
    FILE *f=fopen(filename,"r");
    int so_sach;
    fscanf(f,"%d", &so_sach);fgetc(f);
    struct sach
    {
        char ten_sach[31];
        char ten_tac_gia[31];
        char nha_xuat_ban[31];
        int nam;
        int gia;
    };
    struct sach sach[10];
    for(int i=1;i<=so_sach;i++)
    {
        fscanf(f,"%[^\n]",&sach[i].ten_sach);fgetc(f);
        fscanf(f,"%[^\n]",&sach[i].ten_tac_gia);fgetc(f);
        fscanf(f,"%[^\n]",&sach[i].nha_xuat_ban);fgetc(f);
        fscanf(f,"%d",&sach[i].nam);fgetc(f);
        fscanf(f,"%d",&sach[i].gia);fgetc(f);
        fgetc(f);
    }
    printf("Co %d cuon sach\n",so_sach);
    for (int i=1;i<=so_sach;i++)
    {
        printf("Sach %d: |Ten: %30s|Tac gia: %30s|Nam: %10d|Gia: %10d|\n",i,sach[i].ten_sach,sach[i].ten_tac_gia,sach[i].nam,sach[i].gia);
    }
    fclose(f);
}

void sap_xep_va_in(char *filename1, char *filename2)
{
    FILE *f1=fopen(filename1,"r");
    FILE *f2=fopen(filename2,"w+");
    int so_sach;
    fscanf(f1,"%d",&so_sach);fgetc(f1);
    struct sach
    {
        char ten_sach[31];
        char ten_tac_gia[31];
        char nha_xuat_ban[31];
        int nam;
        int gia;
    };
    struct sach sach[10];
    for(int i=1;i<=so_sach;i++)
    {
        fscanf(f1,"%[^\n]",&sach[i].ten_sach);fgetc(f1);
        fscanf(f1,"%[^\n]",&sach[i].ten_tac_gia);fgetc(f1);
        fscanf(f1,"%[^\n]",&sach[i].nha_xuat_ban);fgetc(f1);
        fscanf(f1,"%d",&sach[i].nam);fgetc(f1);
        fscanf(f1,"%d",&sach[i].gia);fgetc(f1);
        fgetc(f1);
    }
    int vi_tri[20]={0};
    for(int i=1;i<=so_sach;i++) vi_tri[i]=i;
    for(int i=1;i<=so_sach;i++)
    {
        for(int j=i+1;j<=so_sach;j++)
        {
            if(sach[i].nam<sach[j].nam)
            {
                int t=vi_tri[i];  vi_tri[i]=vi_tri[j]; vi_tri[j]=t;
            }
        }
    }
    
    for(int i=1;i<so_sach;i++)
    {
        for(int j=i+1;j<=so_sach;j++)
        {
            if(sach[vi_tri[i]].nam==sach[vi_tri[j]].nam)
            if(sach[vi_tri[i]].gia<sach[vi_tri[j]].gia)
            {
                int t=vi_tri[i];  vi_tri[i]=vi_tri[j]; vi_tri[j]=t;
            }
        }
    }
    
    fprintf(f2,"%d\n",so_sach);
    for(int i=1;i<=so_sach;i++)
    {
        fprintf(f2,"%s\n",sach[vi_tri[i]].ten_sach);
        fprintf(f2,"%s\n",sach[vi_tri[i]].ten_tac_gia);
        fprintf(f2,"%s\n",sach[vi_tri[i]].nha_xuat_ban);
        fprintf(f2,"%d\n",sach[vi_tri[i]].nam);
        fprintf(f2,"%d\n\n",sach[vi_tri[i]].gia);
    }
    for (int i=1;i<=so_sach;i++)
    {
        printf("|Ten: %30s|Tac gia: %30s|Nam: %10d|Gia: %10d|\n",sach[vi_tri[i]].ten_sach,sach[vi_tri[i]].ten_tac_gia,sach[vi_tri[i]].nam,sach[vi_tri[i]].gia);
    }
        fclose(f1);fclose(f2);
}

void tim_theo_ten_sach(char *filename)
{
    FILE *f=fopen(filename,"r");
    int so_sach,check=0;
    char ten[31];
    fscanf(f,"%d", &so_sach);fgetc(f);
    struct sach
    {
        char ten_sach[31];
        char ten_tac_gia[31];
        char nha_xuat_ban[31];
        int nam;
        int gia;
    };
    struct sach sach[10];
    for(int i=1;i<=so_sach;i++)
    {
        fscanf(f,"%[^\n]",&sach[i].ten_sach);fgetc(f);
        fscanf(f,"%[^\n]",&sach[i].ten_tac_gia);fgetc(f);
        fscanf(f,"%[^\n]",&sach[i].nha_xuat_ban);fgetc(f);
        fscanf(f,"%d",&sach[i].nam);fgetc(f);
        fscanf(f,"%d",&sach[i].gia);fgetc(f);
        fgetc(f);
    }
    printf("Nhap ten sach ban muon tim: \n");fflush(stdin);
    scanf("%[^\n]",&ten);
    for(int i=1;i<=so_sach;i++)
    {
        int c=strcmp((sach[i].ten_sach),ten);
        if(c==0)
        {
            printf("|Ten: %30s|Tac gia: %30s|Nam: %10d|Gia: %10d|\n",sach[i].ten_sach,sach[i].ten_tac_gia,sach[i].nam,sach[i].gia);
            check =1;
        }
    }
    if(check==0) printf("Khong tim thay cuon sach nao\n");
    fclose(f);
}

void tim_theo_ten_tac_gia(char *filename)
{
    FILE *f=fopen(filename,"r");
    int so_sach,check=0;
    char ten[31];
    fscanf(f,"%d", &so_sach);fgetc(f);
    struct sach
    {
        char ten_sach[31];
        char ten_tac_gia[31];
        char nha_xuat_ban[31];
        int nam;
        int gia;
    };
    struct sach sach[10];
    for(int i=1;i<=so_sach;i++)
    {
        fscanf(f,"%[^\n]",&sach[i].ten_sach);fgetc(f);
        fscanf(f,"%[^\n]",&sach[i].ten_tac_gia);fgetc(f);
        fscanf(f,"%[^\n]",&sach[i].nha_xuat_ban);fgetc(f);
        fscanf(f,"%d",&sach[i].nam);fgetc(f);
        fscanf(f,"%d",&sach[i].gia);fgetc(f);
        fgetc(f);
    }
    printf("Nhap ten tac gia ban muon tim: \n");fflush(stdin);
    scanf("%[^\n]",&ten);
    for(int i=1;i<=so_sach;i++)
    {
        int c=strcmp((sach[i].ten_tac_gia),ten);
        if(c==0)
        {
            printf("|Ten: %30s|Tac gia: %30s|Nam: %10d|Gia: %10d|\n",sach[i].ten_sach,sach[i].ten_tac_gia,sach[i].nam,sach[i].gia);
            check =1;
        }
    }
    if(check==0) printf("Khong tim thay tac gia nao\n");
    fclose(f);
}

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
