#include<iostream>
#include<list>
#include<fstream>


using namespace std;

void doc_File(ifstream&, int**&);
void ghi_File(ofstream&, int**);
int** mangTemp514_514(int**);
int** ketQua(int**);



int main()
{
	ifstream filein; 
	filein.open("2.txt",ios::in);
    int **mangTruocKhiMF=new int* [512];
  	for(int i=0;i<512;i++)
		mangTruocKhiMF[i]=new int[512];
	int **mangSauKhiMF=new int* [512];
	for(int i=0;i<512;i++)
		mangSauKhiMF[i]=new int[512];
	doc_File(filein, mangTruocKhiMF);
mangSauKhiMF=ketQua(mangTemp514_514(mangTruocKhiMF));

	ofstream fileout; 
	fileout.open("KETQUA_ANH_MEDIAN.txt",ios::out);
	ghi_File(fileout,mangSauKhiMF);


	fileout.close();
	filein.close();	
	for(int i=0;i<512;i++)
		delete[] mangTruocKhiMF[i];
	delete[] mangTruocKhiMF;
	system("pause");
	return 0;
}


void doc_File(ifstream &filein,int **&a)
{
	for(int i = 0; i < 512; i++)
		for(int j = 0;j < 512; j++)
			filein >> a[i][j];
}

void ghi_File(ofstream& fileout,int** a)
{
	for(int i = 0; i < 512; i++)
	{
		for(int j=0;j<512;j++)
		{
			fileout<<a[i][j];
			if((j+1)%512!=0)
				fileout<<" ";				
		}
		fileout<<"\n";
	}
}



int ** mangTemp514_514(int**a)
{ 
    int **temp = new int *[514];
    for (int i = 0; i < 514; i++)
        temp[i] = new int[514];

    for (int i = 0; i < 514; i++)
    {
        for (int j = 0; j < 514; j++)
        {
            if (i == 0 || i == 513|| j == 0 || j == 513)
                temp[i][j] = 0;
            else
                temp[i][j] = a[i - 1][j - 1];           
        }
	}
    return temp;
}
    
    
int** ketQua(int ** temp)
{
	int **kq=new int* [512];
  	for(int i=0;i<512;i++)
		kq[i]=new int[512];	
	list<int> cuaSoLoc;
    int k, q = 0;
    for (int i = 1; i < 513; i++)
    {
        for (int j = 1; j < 513; j++)
        {
            k = 0;
            for (int p = 0; p < 3; p++)
            {
                while (k < (3 * (p + 1)))
                {
                    cuaSoLoc.push_back(temp[i - 1 + p][j - 1 + q]);
                    k++;
                    q++;
                }
                q = 0;
            }      
            cuaSoLoc.sort();
            list<int>::iterator it= cuaSoLoc.begin();
			for(int i=0;i<5;i++)
				it++;
            kq[i - 1][j - 1] = *it;
            cuaSoLoc.clear();
		}
	}
	return kq;
}


            
            
    
