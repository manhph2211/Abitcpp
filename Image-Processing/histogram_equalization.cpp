#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
#define MAX 262144

using namespace std;

void doc_File(ifstream&, int*&);
void ghi_File(ofstream& , int*);
vector<int> danhSachDoXam(int*);
vector<int> soLuongPhanTuCoDoXam_x(int*,vector <int> l);
vector<double> tinhXacSuat(vector<int>);
vector<double> tinhXacSuatTichLuy(vector<double>);
vector<int> sauLamTron(vector<double>);
int* ketQua(int*,vector<int>,vector<int>);



int main()
{
	ifstream filein; 
	filein.open("3.txt",ios::in);
    int *mangTruocKhiHE=new int [MAX];
    int *mangSauKhiHE=new int [MAX];
	doc_File(filein, mangTruocKhiHE);


	mangSauKhiHE=ketQua(mangTruocKhiHE,danhSachDoXam(mangTruocKhiHE),sauLamTron(tinhXacSuatTichLuy(tinhXacSuat(soLuongPhanTuCoDoXam_x(mangTruocKhiHE,danhSachDoXam(mangTruocKhiHE))))));
	
		
	ofstream fileout; 
	fileout.open("KETQUA_ANH_3.txt",ios::out);
	ghi_File(fileout,mangSauKhiHE);
	fileout.close();
	filein.close();
	delete[] mangTruocKhiHE;
	delete[] mangSauKhiHE;
	system("pause");
	return 0;
}


void doc_File(ifstream &filein,int *&a)
{
	for(int i = 0; i < MAX; i++)
		filein >> a[i];
}

void ghi_File(ofstream& fileout,int* a)
{
	for(int i = 0; i < MAX; i++)
	{
		fileout <<a[i];
		if((i+1)%512==0 && i!=0)
		{
			fileout << "\n";
			continue;
		}			
		fileout<<" ";
	}
}


vector<int> danhSachDoXam(int *a)
{
	vector <int> l;
	for(int i=0;i<256;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			if(i==a[j])
				{
					l.push_back(i);
					break;
				}
		}
	}
	return l;
}

vector<int> soLuongPhanTuCoDoXam_x(int* a,vector <int> l)
{
	vector<int> ds;
	for(int i=0;i<l.size();i++)
	{
	int dem=0;
		for(int j=0;j<MAX;j++)
		{		
			if(a[j]==l[i])
				dem++;
		}
	ds.push_back(dem);
	}
	return ds;
}

vector<double> tinhXacSuat(vector<int>ds)
{
	vector<double> dsSX;
	for(int i=0;i<ds.size();i++)
	{
		dsSX.push_back(100000* ds[i]/MAX);
	}
	return dsSX;
}


vector<double> tinhXacSuatTichLuy(vector<double>dsXS)
{
	vector<double> dsXSTL;
	dsXSTL.push_back(dsXS[0]);
	double x=dsXS[0];
	for(int i=1;i<dsXS.size();i++)
	{
		x=dsXS[i]+x;
		dsXSTL.push_back(x);
	}
	return dsXSTL;
}



vector<int> sauLamTron(vector<double> dsXSTL)
{
	vector<int> b;
		for(int j=0;j<dsXSTL.size();j++)
			b.push_back(round((dsXSTL[j]*256/100000)));
	return b;
}



int* ketQua(int* a,vector<int> c,vector<int>b)
{
	int *kq=new int[MAX];
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<b.size();j++)
		{
			if(a[i]==c[j])
				kq[i]=b[j];
		}
	}
	return kq;
}
