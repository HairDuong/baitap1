#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

void Menu(){
	cout << "\n\t\t\t -----------------------------------------"<<endl;
	cout << "\t\t\t|                MENU                     |"<<endl;
	cout << "\t\t\t -----------------------------------------"<<endl;
	cout<<"========================================================================================================================";
	cout<<"\n\n"<<"   1. Xem hang ton kho";
	cout<<"\n\n"<<"   2. Nhap hang vao kho";
	cout<<"\n\n"<<"   3. Xuat hang";
	cout<<"\n\n"<<"   4. Xem hoa don nhap";
	cout<<"\n\n"<<"   5. Xem hoa don xuat";
	cout<<"\n\n"<<"   6. Them hang ";
	cout<<"\n\n"<<"   7. Xoa vat tu khoi danh sach";
	cout<<"\n\n"<<"   8. Thoat\n\n";
	cout<<"========================================================================================================================";
}
	
class Vattu{
	public:
	int MSVT;
	char ngay[30];
	char ten[30];
	char donvi[10];
	int soluong;
	float gia;
	int dem=0;
	float Tong;
	
	void Nhap(){
		cout<<"Nhap ngay: ";
		cin.ignore();
        cin.getline(ngay,30);
		cout<<"Nhap ma so vat tu: ";
		cin>>MSVT;
		cout<<"Nhap ten: ";
		cin.ignore();
        cin.getline(ten,30);
		cout<<"Nhap don vi: ";
		cin.getline(donvi,10);
		cout<<"so luong: ";
		cin>>soluong;
		cout<<"Nhap gia: ";
		cin>>gia;
		}
	void Xuat(){
		Tong=gia*soluong;
		cout<<setw(8)<<ngay<<" |"<<setw(9)<<MSVT<<" |"<<setw(15)<<ten<<" |"<<setw(8)<<donvi<<" |"<<setw(12)<<soluong<<" |"<<setw(8)<<gia<<" |"<<setw(12)<<Tong<<" |"<<endl;
	}
};
void NhapSL(Vattu a[],int &dem,char f, int &demnhap)
{
do{
    	cout<<"Nhap thong tin vat lieu thu "<<dem+1<<":"<<endl;
		a[dem].Nhap();
		dem+=1;
		cout<<"Bam y de nhap tiep, bam n de huy:";
		cin>>f;
		}			
	while (f=='y');
if(dem>=1)
	{
	int s;
	do {
		s=0;
	for(int i=0;i<dem;i++)
	{
		
		int j;
		j=i+1;
		for(j;j<dem;j++)
		{
			if(a[i].MSVT==a[j].MSVT) 
			{
			s=s+1;
			int tg1= i+1;
			int tg2=j+1;
		    cout << " msvt thu " << tg1 << " trung voi msvt thu " << tg2 << "vui long nhap lai" << endl;
			cout << "nhap msvt thu " << tg1 << endl;
			cin >>a[i].MSVT;
			cout << "nhap msvt thu " << tg2 << endl;
			cin >>a[j].MSVT;}
			
		}

	}}
	while(s!=0);
	demnhap ++;
	}
    
}

void XuatSL(Vattu a[],int dem){	   
	    for (int i=0;i<dem;i++){
		cout << setw(3)<< i+1<<" |";
		a[i].Xuat();}
		}


void Tieude(){
		cout<<"-------------------------------------------------------------------------------------------\n";
		cout<<setw(3)<<"STT"<<" |"<<setw(8)<<"Ngay"<<" |"<<setw(9)<<"MSVT"<<" |"<<setw(15)<<"Ten Vat Tu"<<" |"<<setw(8)<<"Don vi"<<" |"<<setw(12)<<"So luong"<<" |"<<setw(8)<<"Gia"<<" |"<<setw(12)<<"Tong tien"<<" |"<<endl;
	}
	
void Press()
{
    system("pause");
    system("cls");
}

void Xuathang(int &k,int dem,Vattu a[],Vattu c[],int &e,int demnhap)
{
	if(demnhap!=0)
{
	int h=0;
	do{
	cout<<"Nhap MSVT hang can xuat: "<<endl;
	cin>>k;
	for(int i=0;i<dem;i++)
	{
		if(k==a[i].MSVT){
			cout<<"Nhap so luong muon xuat hang: ";
			 int s;
			do
		{
			s=0;
			cin>>e;
			if(a[i].soluong < e)
			{ 
				s++;
				cout << " so luong can xuat lon hon trong kho hien dang co vui long nhap lai" <<endl;
			}
		}
			while(s!=0);
			a[i].soluong=a[i].soluong-e;
			c[i].soluong=e;
			a[i].Tong=a[i].Tong - (e*a[i].gia);
			h++;
		cout<<"  Xuat hang thanh cong  "<<endl;
			}}
		if(h==0){
        cout <<"Ma so khong co trong danh sach!"<<endl;}}
		while (h==0);
}	
else cout << " chua co vat tu nao trong kho hang de xuat " << endl;
}
        
void Nhaphang(int &k,int dem,Vattu a[],Vattu c[],int &e,int demnhap)
{
    if(demnhap!=0)
{		
	int h=0;
	do
	{
	cout<<"Nhap MSVT hang can them: "<<endl;
	cin>>k;
	for(int i=0;i<dem;i++)
	  {
		if(k==a[i].MSVT)
		{
			cout<<"Nhap so luong muon nhap hang: ";
			cin>>e;
			a[i].soluong=a[i].soluong+e;
			a[i].Tong=a[i].Tong + (e*a[i].gia);
			h++;
		cout<<"  Nhap hang thanh cong  "<<endl;
		}
	  }
		if(h==0){
        cout <<"Ma so khong co trong danh sach!"<<endl;}
	}
		while(h==0);
}
else cout << " ban chua nhap bat ky vat pham nao nen khong the nhap them " << endl;		
}
        
void Hoadonnhap(Vattu a[],Vattu b[],int dem){
	for(int i=0;i<dem;i++)
	{b[i]=a[i];}}
	
void Hoadonxuat(Vattu a[],Vattu c[],int dem,int &i){
	c[i]=a[i];
	c[i].soluong=0;
	i++;
	}
	
void Xuathoadonnhap(Vattu b[],int dem){
	for(int i=0;i<dem;i++){
		cout << setw(3)<<i+1<<" |";
		b[i].Xuat();}}
		
void Xuathoadonxuat(Vattu c[],int dem){
	for(int i=0;i<dem;i++){
		cout << setw(3)<<i+1<<" |";
		c[i].Xuat();}}
		
int Xoavattu(Vattu a[], int dem,int MSVT) {
    int found = 0;
    for(int i = 0; i < dem; i++) {
        if (a[i].MSVT == MSVT) {
            found = 1;
            for (int j = i; j < dem; j++) {
                a[j] = a[j+1];
            }
            break;
        }
    }
    if (found == 0) {
        cout<<"MSVT khong ton tai.";
        return 0;
    } else {
        return 1;
    }
}
		
void Nhapmk(int& baomat){
	char liver[30]={'a','d','m','i','n'};
	char real[30]={'a','d','m','i','n'};
	int r=0;
	char tk[30],mk[30];
	do
	{
	cout<<"Nhap tai khoan: ";
	cin >> tk;
	cout<<"Nhap mat khau: ";
	cin >> mk;
	if(strcmp(liver,tk)==0 && strcmp(real,mk)==0 )
	   {r=1;}
	else
	  {
		r=0;
	    cout<<"Ban da nhap sai tai khoan mat khau vui long nhap lai."<<endl;
	    baomat ++;
	    if(baomat>2) {break;}
	  }
	}
	while(r==0);}
		
int main()
{
		int dem=0;
		Vattu c[1000];
		Vattu b[1000];
		Vattu a[1000];
		int k,e;
		int lenh;
		int chon=1;
		char f;
		int demnhap=0;
		int baomat=0;
		int i=0;
		Nhapmk(baomat);
		if (baomat<3)
		{
		do{
		Menu();
		cout<<"\n Nhap lenh: "<<endl;
		cin>>lenh;
		switch(lenh){
			case 1:
				Tieude();
				XuatSL(a,dem);
						cout<<"-------------------------------------------------------------------------------------------\n";
				Press();
				break;
			case 2:
				NhapSL(a,dem,f,demnhap);
				Hoadonnhap(a,b,dem);
				Hoadonxuat(a,c,dem,i);
				Press();
				break;
			case 3:
				Tieude();
				XuatSL(a,dem);
				Xuathang(k,dem,a,c,e,demnhap);
				Press();				
				break;
			case 4:
				Tieude();
				Xuathoadonnhap(b,dem);
						cout<<"-------------------------------------------------------------------------------------------\n";
				Press();
				break;
			case 5:
				Tieude();
				Xuathoadonxuat(c,dem);
						cout<<"-------------------------------------------------------------------------------------------\n";
				Press();
				break;
			case 6:
				Tieude();
				XuatSL(a,dem);
						cout<<"-------------------------------------------------------------------------------------------\n";
				Nhaphang(k,dem,a,c,e,demnhap);
				Hoadonnhap(a,b,dem);
				Press();
				break;
			case 7:
				Tieude();
				XuatSL(a,dem);
				cout<<"-------------------------------------------------------------------------------------------\n";
				if(dem>0){
				int MSVT;
				cout<<"Nhap MSVT vat can xoa:";
				cin>>MSVT;
				if(Xoavattu(a,dem,MSVT)==1){
					cout<<"Vat tu da xoa"<<endl;}}
				else{
                    cout << "Danh sach vat tu trong!"<<endl;
                }
				dem--;
				Press();
				break;
			case 8:
				chon=0;
				break;			
        	default:
            cout <<"Ban da nhap sai lua chon!"<<endl;
            Press();
            break;
		}

    } while (chon ==1 );
	}
}
