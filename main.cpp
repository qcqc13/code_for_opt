#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class man
{
public:
	string first, second, thrid;
	man(string f, string s, string t)
	{
	first = f;
    second = s;
    thrid = t;
    }
	~man()
	{cout << "";}

	virtual void showme()
	{
    cout << endl;
    cout << "This is virtual function in main class. The data---> " << first << " " << second << " " << thrid << endl;
    cout << endl;
 	}
};

class student:public man
{
public:

    string name, institute, faculty;

    student(string first, string second,string thrid):man(first,second,thrid)
	{
	name = first;
	institute = second;
	faculty = thrid;
	}
    ~student()
    {
    cout << endl;
    }
	void showme()
	{
	    cout << endl;
		cout << "The Name of a student is " << "\"" << name << "\"" << endl;
		cout << "His/her institute is a " << "\"" << institute << "\"" << endl;
		cout << "Faculty " << "\"" << faculty << "\"" << endl;
	}
};

class engineer:public man
{
public:
    string firm, post, pay;

    engineer(string first, string second,string thrid):man(first,second,thrid)
	{
	firm = first;
	post = second;
	pay = thrid;
	}
    ~engineer()
    {cout << endl;}

	void showme()
	{
	    cout << endl;
		cout << "The name of a firm is " << "\"" << firm << "\"" << endl;
		cout << "His/her post in, is a " << "\"" << post << "\"" << endl;
		cout << "Pay " << "\"" << pay << " rubles\"" << endl;
	}
};
//¬Œ«ÃŒ∆ÕŒ œŒ‘» —»“‹?
struct student_file
{
    string name;
    string inst;
    string fuck;
};
//¬Œ«ÃŒ∆ÕŒ œŒ‘» —»“‹?
struct engineer_file
{
    string firm;
    string post;
    string pay;
};


int main()
{
setlocale(LC_ALL,"rus");
string key;
while(key!="students"||key!="student"||key!="engineers"||key!="engineer")
{
    cout << "Choose from two: students or engineers (type \"stop\" for shutdown program). ---> "; getline(cin, key);
    if(key=="stop")
    {return 0;}

if(key=="students"||key=="student")
{
	ifstream count("students.txt");
	int k = 0;
	if (count)
    {
        while (!count.eof())
        {string buff;
        count >> buff;
        k++;}
	}
	else
        {cout << "File not found!" << endl;return 0;}

        if (k % 3 == 0)
            {k = k / 3;}
        else
            {k = (k - (k % 3)) / 3;}

    	ifstream fileb("students.txt");
    	student_file * spravoch = new student_file[k];

    	for (int i = 0; i < k; i++)
        {
		fileb >> spravoch[i].name;
		fileb >> spravoch[i].inst;
		fileb >> spravoch[i].fuck;
		}
        fileb.close();

        cout << endl;
        cout << "The students" << endl;
        for (int i = 0; i < k; i++)
        {cout << i+1 << " " << spravoch[i].name << endl;}


        string n,i,f;
        int number = 0;
        while(number < 1)
        {cout << "choose number of the student ---> "; cin >> number;}
        number = number - 1;
        n = spravoch[number].name;
        i = spravoch[number].inst;
        f = spravoch[number].fuck;


       student k1(n,i,f);
       k1.showme();
       return 0;

}

else if(key=="engineers"||key=="engineer")
{
ifstream count("students.txt");
int k = 0;
    if (count)
    {
        while (!count.eof())
        {
        string buff;
        count >> buff;
        k++;
        }
    }
    else
        {cout << "File not found!" << endl;return 0;}

    if (k % 3 == 0)
        {k = k / 3;}

    else
        {k = (k - (k % 3)) / 3;}

    ifstream fileb("engineers.txt");
    engineer_file * spisok = new engineer_file[k];	//‰ËÌ‡ÏË˜ÂÒÍÓÂ ÒÓÁ‰‡ÌËÂ Ï‡ÒÒË‚‡ ÒÚÛÍÚÛ

    for (int i = 0; i < k; i++)
    {
    fileb >> spisok[i].firm;
    fileb >> spisok[i].post;
    fileb >> spisok[i].pay;
    }
    fileb.close();

    cout << endl;
    cout << "The engineers" << endl;
    for (int i = 0; i < k; i++)
    {cout << i+1 << " " << spisok[i].firm << endl;}

    string n,i,f;
    int number = 0;

    while(number < 1)
    {cout << "choose number of the engineer ---> "; cin >> number;}

    number = number - 1;
    n = spisok[number].firm;
    i = spisok[number].post;
    f = spisok[number].pay;

    engineer k2(n,i,f);
    k2.showme();
    return 0;
    }}
}
