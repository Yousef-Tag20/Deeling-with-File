#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <ctime>
#include <list>
#include <algorithm> 
#define sp " , "
using namespace std;
time_t t1, t2;
 struct Data 
 {
	int Ref, id;
	string fName, city, depart, grade;
	size_t offset;
 };


void add() 
{
Data x;
	int re = 0;
	ifstream in("Ass.txt");
	string line,r;
	while (getline(in,line))
	{
		r = line.substr(0, line.find('  '));
		if (r!= "Ref") 
		{
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
	string rec = strRef + "  " +strID + "  " + x.fName + "  " + x.city + "  " + x.depart + "  " + x.grade+"  ";
	ou << rec ;
	ou.close();

}

void Display()
{
	ifstream in("Ass.txt");
	string line;
	while (getline(in, line))
	{
		cout << line << endl;
	}
	in.close();
	
}
void Search() 
{
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
//size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
//{
//	size_t pos = txt.find(ch);
//	size_t initialPos = 0;
//	strs.clear();
//
//	// Decompose statement
//	while (pos != std::string::npos) {
//		strs.push_back(txt.substr(initialPos, pos - initialPos));
//		initialPos = pos + 1;
//
//		pos = txt.find(ch, initialPos);
//	}

	// Add the last one
//	strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));
//
//	return strs.size();
//}
vector<string> split(string s, string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}



int main()
{
	cout << "at first enter your data :"<<endl;
	add();
	t1 = time(0);
	tm *ltm = new tm;
	localtime_s(ltm,&t1);
	cout << "Time: " << 1+ltm->tm_hour << ":";
	cout << 1+ltm->tm_min << ":";
	cout << 1+ltm->tm_sec/1000 << endl;
	double x = 1 + ltm->tm_sec;
	ifstream in("Ass.txt");
	string line;
	string delimiter = "  ";
	vector<string> v = split(line, delimiter);

	map<string, string> primary_key;
	map<string, string> name;
	map<string, string> city;
	map<string, string> depart;
	map<string, string> grade;
	vector<int> pointers;
	vector<string>names;
	vector<string>cities;
	vector<string>departs;
	vector<string>grades;
	vector<string>id;
	vector<string>Ref;
	while (getline(in, line))
	{
		vector<string> v = split(line, delimiter);
		primary_key.insert(make_pair(v[1], v[0]));
		name.insert(make_pair(v[2], v[1]));
		city.insert(make_pair(v[3], v[1]));
		depart.insert(make_pair(v[4], v[1]));
		grade.insert(make_pair(v[5], v[1]));		
		names.push_back(v[2]);
		cities.push_back(v[3]);
		departs.push_back(v[4]);
		grades.push_back(v[5]);
		names.push_back(v[2]);
		id.push_back(v[1]);
		Ref.push_back(v[0]);
		pointers.push_back(-1);
	}
	/*for(int i = 0; i < name.size();i++)
	{
		pointers.at(i) = -1;
	}*/
		char secondary;
	cout << "please choose the secondary key press n for name , c for city , d for depart , g for grade" << endl;
	cout << "your choice :" << endl;
	cin >> secondary;
	Display();
	cout << "***********************************************************************" << endl;
	cout << "key " << "=> " << "Reference" << endl;
	for (std::map<string, string>::iterator it = primary_key.begin(); it != primary_key.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	cout << "************************************************************************" << endl;
	switch (secondary)
	{
	case'n':
		for (int i = 0; i < Ref.size(); i++)
			for (int j = i + 1; j < Ref.size()-1; j++)
			{
				if (names.at(i) == names.at(j))
				{
					pointers.at(i) =stoi(Ref.at(j));
				}
				break;
			}
		cout << "secodary key " << "=> " << "P.k"<<endl;
		for (std::map<string, string>::iterator it = name.begin(); it != name.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';
		}
		cout << "********************************************************************" << endl;
		cout << "Inverted list Table " << endl;
		cout << "********************************************************************" << endl;
		cout << "Id" << "         " << "Ref" << "     " << "pointers" << endl;
		for (int i = 0; i < Ref.size(); ++i)
		{
			cout << id[i] << "     " << Ref[i] << "     " << pointers[i] << endl;
		}
		break;
	case'c':
		for (int i = 0; i < Ref.size(); i++)
			for (int j = i + 1; j < Ref.size()-1; j++)
			{
				if (cities.at(i) == cities.at(j))
				{
					pointers.at(i) =stoi(Ref.at(j));
				}
				break;
			}
		cout << "secodary key " << "=> " << "P.k"<<endl;
		for (std::map<string, string>::iterator it = city.begin(); it != city.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';
		}
		cout << "*************************************************************************" << endl;
		cout << "Inverted list Table " << endl;
		cout << "********************************************************************" << endl;
		cout << "Id" << "          " << "Ref" << "     " << "pointers" << endl;
		for (int i = 0; i < Ref.size(); ++i)
		{
			cout << id[i] << "     " << Ref[i] << "     " << pointers[i] << endl;
		}
		break;
	case'd':
		for (int i = 0; i < Ref.size(); i++)
			for (int j = i + 1; j < Ref.size()-1; j++)
			{
				if (departs.at(i) == departs.at(j))
				{
					pointers.at(i) = stoi(Ref.at(j));
				}
				break;
			}
		cout << "secodary key " << "=> " << "P.k"<<endl;
		for (std::map<string, string>::iterator it = depart.begin(); it != depart.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';
		}
		cout << "**********************************************************************" << endl;
		cout << "Inverted list Table " << endl;
		cout << "********************************************************************" << endl;
		cout << "Id" << "       " << "Ref" << "     " << "pointers" << endl;
		for (int i = 0; i < Ref.size(); ++i)
		{
			cout << id[i] << "     " << Ref[i] << "     " << pointers[i] << endl;
		}
		break;
	case'g':
		for (int i = 0; i < Ref.size(); i++)
			for (int j = i + 1; j < Ref.size()-1; j++)
			{
				if (grades.at(i) == grades.at(j))
				{
					pointers.at(i) =stoi(Ref.at(j));
				}
				break;
			}
		cout << "secodary key " << "=> " << "P.k"<<endl;
		for (std::map<string, string>::iterator it = grade.begin(); it != grade.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';
		}
		cout << "******************************************************************" << endl;
		cout << "Inverted list Table " << endl;
		cout << "********************************************************************" << endl;
		cout << "Id" << "        " << "Ref" << "     " << "pointers" << endl;
		for (int i = 0; i < Ref.size(); ++i)
		{
			cout << id[i] << "     " << Ref[i] << "     " << pointers[i] << endl;
		}
		break;
	default:
		cout << "try again" << endl;
		cout << "********************************************************************" << endl;
	}
	

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
