#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct stack
{
    int top=1;
    paket data[10];
};

struct stack kirim;

bool isFull()
{
    if (kirim.top==11)
        return true;
    else
        return false;
}

bool isEmpty()
{
    if (kirim.top==1)
        return true;
    else
        return false;
}

void bersihlayar()
{
    for(int a=0;a<90;a++)
    {
        for(int b=7;b<=25;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void push()
{
    if (isFull()==false)
    {
        gotoxy(40,10);cout<<"Inputkan Jenis Barang    :";
        cin>>kirim.data[kirim.top].jenis_brg;
        gotoxy(40,11);cout<<"Inputkan Berat           :";
        cin>>kirim.data[kirim.top].berat;
        gotoxy(40,12);cout<<"Inputkan Kota Tujuan     :";
        cin>>kirim.data[kirim.top].kota;
        kirim.top++;
    }
    else
    {
        gotoxy(40,10);cout<<"MAAF STACK PENUH";
        getch();
        bersihlayar();
    }
}

void tampildata()
{
    gotoxy(1,10);cout<<"Daftar Kiriman Paket"<<endl;
    for(int a=1; a<kirim.top; a++)
    {
        gotoxy(1,22-a);
        cout<<a<<". ";
        cout<<kirim.data[a].jenis_brg<<" ";
        cout<<kirim.data[a].berat<<"Kg ";
        cout<<kirim.data[a].kota<<endl;
    }
}

void pop()
{
    if (isEmpty()==false)
    {
        gotoxy(40,10);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
        gotoxy(40,11);cout<<kirim.data[kirim.top-1].jenis_brg<<" ";
        cout<<kirim.data[kirim.top-1].berat<<"Kg ";
        cout<<kirim.data[kirim.top-1].kota;
        getch();
        kirim.top--;
        bersihlayar();
    }
    else
    {
        gotoxy(40,10);cout<<"Stack telah kosong"<<endl;
        getch();
        bersihlayar();
    }
}

void clear()
{
    char pilih;

    gotoxy(40,10);cout<<"Apakah anda yakin ingin membersihkan stack?(y/t) ";
    cin>>pilih;

    if (pilih=='y' || pilih=='Y')
    {
        kirim.top=1;
    }
    else
    {
        bersihlayar();
    }
}

int main()
{
    int pilih;
    do
    {
        bersihlayar();
        tampildata();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. Push";
        gotoxy(1,3);cout<<"2. Pop"<<endl;
        gotoxy(1,4);cout<<"3. Clear Stack"<<endl;
        gotoxy(1,5);cout<<"9. Keluar"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1)
        { /*Menambah data baru diletakan di DATAKE*/
            push();
        }
        if(pilih==2)
        { /*Menghapus Data Terakhir (DATAKE-1*/
            pop();
        }
        if(pilih==3)
        {
            clear();
        }
    }
    while(pilih!=9);
    return 0;
}
