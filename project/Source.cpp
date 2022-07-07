#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#define sp " , "
using namespace std;
time_t t1, t2;
 struct Data 
 {
	int Ref, id;
	string fName, city, depart, grade;
};


void add() 
{
	Data x;
	int re = 0;
	ifstream in("Ass.txt");
	
	string line,r;
	while (getline(in,line))
	{
		r = line.substr(0, line.find(' '));
		if (r!= "Ref") {
			re = stoi(r);
		}
	}
	in.close();	
	re++;
	x.Ref = re;
	cout << "Enter ID: "; cin >> x.id;
	cout << "First Name: "; cin >> x.fName;
	cout << "city: "; cin >> x.city;
	cout << "Depart: "; cin >> x.depart;
	cout << "Grade: "; cin >> x.grade;

	ofstream ou("Ass.txt", std::ios::app);
	ou.write("\n",1);
	string strRef = to_string(x.Ref);
	string strID = to_string(x.id);
	string rec = strRef + " " +strID + " " + x.fName + " " + x.city + " " + x.depart + " " + x.grade;
	ou << rec ;
	ou.close();

}
void Display() {

	ifstream in("Ass.txt");
	string line;
	while (getline(in, line))
	{
		cout << line << endl;
	}
	in.close();
	

}
void Search() {

	int id, f = 0, cnt = 0;
	Data  x, y;
	cout << "Enter ID Please: "; cin >> id;
	ifstream in("Ass.txt");
	while (in.read((char*)&y, sizeof y) && in)
	{
		if (id == y.id)    f = 1, x = y;
		//       cout<<"Ref: "<<y.Ref<<sp<<"ID: "<<y.id<<sp<<"First_Name: "<<y.fName<<sp<<"City: "<<y.city<<sp<<"Depart: "<<y.depart<<sp<<"Grade: "<<y.grade<<endl;
	}
	in.close();
	if (!f) {
		cout << "Not Found " << endl;
		return;
	}
	cout << "Ref: " << x.Ref << sp << "ID: " << x.id << sp << "First_Name: " << x.fName << sp << "City: " << x.city << sp << "Depart: " << x.depart << sp << "Grade: " << x.grade << endl;

}


int main()
{
	add();
	t1 = time(0);
	tm *ltm = new tm;
	localtime_s(ltm,&t1);
	cout << "Time: " << 1+ltm->tm_hour << ":";
	cout << 1+ltm->tm_min << ":";
	cout << 1+ltm->tm_sec/1000 << endl;
	double x = 1 + ltm->tm_sec;
	Display();
	t1 = time(0);
	localtime_s(ltm, &t1);
	cout << "Time: " << 1+ltm->tm_hour << ":";
	cout << 1+ltm->tm_min << ":";
	cout << 1+ltm->tm_sec/1000 << endl;
	double y = 1 + ltm->tm_sec;
	double comparision_time;
	comparision_time = y - x;
	cout << "comparision_time : " << comparision_time<<endl;
	system("pause");
	return 0;
}
