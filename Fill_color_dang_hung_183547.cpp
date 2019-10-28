#include <iostream>
#include <vector>
#include <fstream>
//tu tuong: dung thuat toan tham lam de to mau cac dinh
using namespace std;
ofstream outfile;//ghi file 
ifstream infile;//doc file
struct node {
	int bac=0;//bac cua dinh
	vector<int>DK;
};
int Max=0; 
int n,m; //n la dinh m la canh
int next=0;
int maxi=0;//tim so mau da su dung de to
int Test(int u){
    if(Max>u)
		return Max;
    else
		return u;
}
void Sorting_Node(node Node[],int Sorting[]){
    while(Max>=0){
        for(int i=1;i<=n;i++){
            if(Node[i].bac==Max){
				Sorting[next]=i;//i la cac dinh
                next++;//bien next la thu tu dinh
            }
        }
        Max--;
    }
}
void Color(int u,node Node[],int Filled[],int FreeColor[]){//to mau dinh u
	for(int i=0;i<Node[u].bac;i++){//xet all edge v of[u,v] ma v da to mau
		if(Filled[Node[u].DK.at(i)]!=0){
			FreeColor[Filled[Node[u].DK.at(i)]]=1;//mau i da bi dinh v to
		}
	}
	for(int i=1;i<20;i++)
	{//tim mau nho nhat chua bi to thi to cho dinh u
		if(FreeColor[i]==0){
			Filled[u]=i;
			if(i>maxi)
				maxi=i;//tim so mau nhieu nhat da to
			break;
		}
	}
	for(int i=0;i<Node[u].bac;i++){
		if(Filled[Node[u].DK.at(i)]!=0){
			FreeColor[Filled[Node[u].DK.at(i)]]=0;//gan lai tat ca cac mau deu free co the to
		}
	}
}
void change_to_textcolor(int a,int i)//chuyen doi mau dang int sang char
{
	outfile <<"\n  "<< i<< " [fillcolor = ";
	switch(a){
		case 1: cout<<"Red, ";
				outfile<<"red, ";
				break;
		case 2: cout<<"Green, ";
				outfile<<"green, ";
				break;
		case 3: cout<<"Yellow, ";
				outfile<<"yellow, ";
				break;
		case 5: cout<<"Orange, ";
				outfile<<"orange, ";
				break;
		case 4: cout<<"Blue, ";
				outfile<<"blue, ";
				break;
		case 6: cout<<"White, ";
				outfile<<"white, ";
				break;
		case 7: cout<<"SkyBlue1, ";
				outfile<<"skyblue1, ";
				break;
		case 8: cout<<"Black, ";
				outfile<<"black, ";
				break;
		case 9: cout<<"Pink, ";
				outfile<<"pink, ";
				break;
		case 10: cout<<"LightGrey, ";
				outfile<<"lightgrey, ";
				break;
		case 11: cout<<"YellowGreen, ";
				outfile<<"yellowgreen,";
				break;
		case 12: cout<<"SandyBrown, ";
				outfile<<"sandybrown, ";
				break;
		case 13: cout<<"Snow, ";
				outfile<<"snow, ";
				break;
		case 14: cout<<"Brown, ";
				outfile<<"brown, ";
				break;
		case 15: cout<<"SkyBlue2, ";
				outfile<<"skyblue2, ";
				break;
		case 16: cout<<"SkyBlue3, ";
				outfile<<"skyblue3, ";
				break;
		case 17: cout<<"Chocolate, ";
				outfile<<"chocolate, ";
				break;
		case 18: cout<<"Purple, ";
				outfile<<"purple, ";
				break;
		case 19: cout<<"DarkGrey, ";
				outfile<<"darkgrey, ";
				break;
		case 20: cout<<"LightGreen, ";
				outfile<<"lightgreen, ";
				break;
	}
	outfile <<"style=filled;]";
}
void Print(int Filled[])
{
	outfile<< "\ngraph dothi\n{";
	for(int i=1;i<=n;i++){
		cout<<"\n\t"<< i<< " [fillcolor=";
		change_to_textcolor(Filled[i],i);
		cout<<" style = filled;]";
	}
	cout<<"\n}";
}
int main ()
{
	infile.open ("dothi.txt");
	outfile.open("tomaudothi.dot");
	infile >> m;
	infile >> n;
	cout<< "Cac gia tri tu file: "<<
	endl<< "So canh: "<<m<<
	endl<< "So dinh: "<<n<<
	endl<< "Cac canh la: ";
	int Filled[n+1]={0};//mang luu cac mau to cho dinh thu i
	node Node[n+1];//mang luu cac data cua dinh
	int out_to_file[2][m];
	//input
		{//doc cac gia tri tu file va xu li
			int d,dk;
			for (int i=0;i<m;i++){
				infile >> d;
				infile >> dk;
				cout<<endl<< d<<" -- "<<dk;
				out_to_file[0][i]=d;
				out_to_file[1][i]=dk;
				Node[d].DK.push_back(dk);
				Node[dk].DK.push_back(d);
				Node[d].bac++;
				Node[dk].bac++;
				Max=Test(Node[d].bac);
				Max=Test(Node[dk].bac);
			}
		}
	cout<<endl<<"Cac dinh deu co bac <= "<<Max;
	int FreeColor[20]={0};//mang luu cac mau tu 1->20 dung de to mau cac dinh
	int Sorting[n];//mang sap xep thu tu cac dinh de to
	cout<<endl;
	Sorting_Node(Node, Sorting);
	for(int i=0;i<n;i++){
		Color(Sorting[i],Node,Filled,FreeColor);
	}
	cout<< endl<< "graph dothi"<<endl<<"{";
	Print(Filled);
	outfile<< "\n\n";
	for(int i=0;i<m;i++){
		outfile<<"\n  "<<out_to_file[0][i]<<" -- "<<out_to_file[1][i]<<";";
	}
	outfile<< "\n}";
	cout<< "\nSo mau khac nhau da su dung de to la: "<<maxi;
	return 0;
}

