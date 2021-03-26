#include "std_lib_facilities.h"

using namespace std;

struct Person
{
	private:
	string first_name,last_name;
	int age;

	public:
	Person(){};
	Person(string fn1, string ln2, int a)
	{
		first_name=fn1;
		last_name=ln2;
		age=a;
	}

	//g
	string get_first_name() const {return first_name;}
	string get_last_name() const {return last_name;}
	int get_age() const {return age;}

	//s
	void set_first_name(string n){first_name=n;}
	void set_last_name(string n){last_name=n;}
	void set_age(int a){age=a;}
};

	ostream& operator<< (ostream& os, Person& p)
	{
		os<<"Name: "<<p.get_first_name()<<" "<<p.get_last_name()<<" age: "<<p.get_age();
		return os;
	}

	istream& operator>> (istream& is, Person& p)
	{
		string first,last;
		int a;
		is>>first>>last;

		for(auto letter : first)
		{
			if(!isalpha(letter) && !isdigit(letter))
			{
				error("Not allowed character in first name");
			}
		}
		p.set_first_name(first);

		for(auto letter : last)
		{
			if(!isalpha(letter))
			{
				error("Not allowed character in last name");
			}
		}
		p.set_last_name(last);

		is>>a;

		if(0<=a && a<=150)
			{
				p.set_age(a);
			}
		else
		{
			error("Invalid age!");
		}
		return is;
	}

int main()
try{
/*	Person p1;
	p1.name="Goofy";
	p1.age=63;
	cout<<p1.name<<" "<<p1.age<<endl;
	cout<<p1<<endl;
*/

	Person p2;

	cout<<"Give name and age:"<<endl;
	cin>>p2;
	cout<<p2<<endl;

/*	Person AllMight ("Yagi",55);
	cout<<AllMight<<endl;
*/
	cout<<"Give names to the vector:"<<endl;

	vector<Person> people;
	Person temp;
	int numOfPeople=0;
	while(cin>>temp)
	{
		people.push_back(temp);
		cout<<people[numOfPeople]<<endl;
	}


	return 0;
}

catch (exception& e) {
	cerr << "Exception: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch(...){
	cerr << "error";
	keep_window_open();
	return 2;
}

