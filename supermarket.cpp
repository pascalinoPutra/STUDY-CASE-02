#include<iostream>
#include<windows.h>
#include<fstream>
#include"kasir.h"
#include"rekrusif.h"
using namespace std;
void gotoxy(int x ,int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);	
}
struct kasir
{
	char answer,opsi;
}ksr;
int main()
{
	awal:
	ofstream database;
	database.open("minimarket.txt",ios::app);
	database<<"============== OUTPUT HASIL PEMBELIAN ============="<<endl;
	
	string barang;
	int jumlahBarang,hargaBarang,potonganHarga,total;
	int totalHarga,bayar,kembalian;
	
	gotoxy(0,0);cout<<"| SELAMAT DATANG DI MINI MARKET   |";
	gotoxy(0,1);cout<<"| jl.ambarketawang 2              |";
	gotoxy(0,2);cout<<"| yogyakarta                      |";
	gotoxy(0,3);rekrusifSamaDengan(65);
	gotoxy(0,5);rekrusifStrip(26);
	gotoxy(0,6);cout<<"| NO |  Nama Barang  |  Jumlah  |  Harga  | Potongan Harga | Total Harga |"<<endl;
	gotoxy(0,7);rekrusifSamaDengan(26);
	
	for(int i=1;i<=12;i++)
	{	
		gotoxy(0,7+i);
		cout<<"|    |               |          |         |                |             |";
	}
	
	cout<<endl;
	gotoxy(0,20);rekrusifSamaDengan(26);
	gotoxy(0,21);cout<<"|TOTAL                                                     |             |";
	gotoxy(0,22);cout<<"|TOTAL POTONGAN                                            |             |";
	gotoxy(0,23);cout<<"|BAYAR                                                     |             |";
	gotoxy(0,24);cout<<"|KEMBALIAN                                                 |             |";
	gotoxy(0,25);rekrusifSamaDengan(26); 
	for(int i=1;i<12;i++)
	{   
		gotoxy(40,4);cout<<"Masukan barang belanja [Y/T] : ";
		cin>>ksr.answer;
		if(ksr.answer=='y'||ksr.answer=='Y')
		{
			gotoxy(2,7+i);cout<<i;
			gotoxy(7,7+i);cin>>barang;;
			gotoxy(26,7+i);cin>>jumlahBarang;
			gotoxy(35,7+i);cin>>hargaBarang;
			gotoxy(51,7+i);cin>>potonganHarga;
			total=kali(jumlahBarang,hargaBarang);
			gotoxy(62,7+i);cout<<total;
			totalHarga=total+totalHarga;
			gotoxy(60,21);cout<<totalHarga;
			
			database<<barang;
			database<<"    x"<<jumlahBarang<<"    ";
			database<<hargaBarang<<"    ";
			database<<total<<endl;		
		}
		else if(ksr.answer=='T'||ksr.answer=='t')
		{	
			gotoxy(60,22);cout<<potonganHarga;
			gotoxy(60,23);cin>>bayar;
			kembalian=kurang(bayar,totalHarga);
			gotoxy(60,24);cout<<kembalian;
			database<<"TOTAL HARGA                       = "<<totalHarga<<endl;
			database<<"KEMABALIAN                        = "<<kembalian<<endl;		
			database<<"===================================================";
			database.close();
			
			
			cout<<"\n\nPelanggan berikut [Y/T] : ";cin>>ksr.opsi;
			if(ksr.opsi=='Y'||ksr.opsi=='y')
			{
				system("cls");  
				goto awal;
			}
			else
			{
				system("cls");
				goto awal;
			}
		
			return 0;   
		}
	}
	return 0;
}