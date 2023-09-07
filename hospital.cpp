#include <iostream>
#include <string>
#include <fstream>
#include<cstdio>

using namespace std;

fstream bimarManager("bimars.txt", ios::app | ios::in);
fstream doctorManager("doctor.txt", ios::app | ios::in);
int bimar2;
int number;
int bimarName;
string phoneNumber;
void Addbimar();
int rate;
float averate;

void Addbimar() {

	string bimarName;
	string lastName;
	int bimarcode;


	int doctorcode;
	string phonenumber;
	int rate[100];
	int a = 1;
	int i = 0;
	int sum;
	while (a != 0) {
		cout << "Enter bimar name:" << endl;
		cin >> bimarName;
		cout << "Enter last name:" << endl;
		cin >> lastName;
		cout << "Enter bimarcode:" << endl;
		cin >> bimarcode;
		cout << "Enter doctorcode:" << endl;
		cin >> doctorcode;
		cout << "Enter phonenumber:" << endl;
		cin >> phonenumber;
		cout << "Enter rate:" << endl;
		cin >> rate[i];
		i++;
		sum = rate[i]++;
		bimarManager << bimarName << " " << lastName << " " << bimarcode << " " << doctorcode << " " << phonenumber << " " << rate[i] << "" << endl;
		cout << "For continue Enter 1 & For finish Enter 0:" << endl;
		cin >> a;
	}
	averate = (sum / i);
}


void Editbimar()
{
	ifstream bimarManager("bimars.txt", ios::in);
	ofstream bimarManager2("bimars1.txt", ios::app);
	if (!bimarManager)
	{
		cout << "The file could not be opened!" << endl;
		abort();
	}
	string bimarName;
	string lastName;
	int doctorcode;
	long  bimarcode,bimarcode2;
	string phonenumber;
	bool found = false;
	cout << "Enter bimarcode to edit bimar's informtions. ";
	cin >> bimarcode;
	cout << endl;
	while (bimarManager >> bimarName)
	{
		bimarManager >> lastName;
		bimarManager >> bimarcode;
		bimarManager >> doctorcode;
		bimarManager >> phonenumber;
		
		if (bimarcode2 == bimarcode)
		{
			cout << "Enter bimar's name:" << endl;
			cin >> bimarName;
			cout << "Enter last name:" << endl;
			cin >> lastName;
			cout << "Enter bimarcode:" << endl;
			cin >> bimarcode;
			cout << "Enter doctorcode:" << endl;
			cin >> doctorcode;
			cout << "Enter the phonenumber bimar:" << endl;
			cin >> phonenumber;

			bimarManager2 << bimarName << " " << lastName << " " << bimarcode << " " << doctorcode << " " << phonenumber << " " << endl;
			found = true;
		}
		else
			bimarManager2 << bimarName << " " << lastName << " " << bimarcode << " " << doctorcode << " " << phonenumber << " " << endl;

	}
	bimarManager2.close();
	bimarManager.close();
	if (remove("bimars.txt") != 0)
		cout << "Error in deleting original file!" << endl;

	if (rename("bimars1.txt", "bimars.txt") != 0)
		cout << "Error in renaming output file!" << endl;
	if (!found)
		cout << "This bimar not found." << endl;
}
void removebimar() {
	string bimarName;
	string lastName;
	int doctorcode;
	long  bimarcode, bimarcode2;
	string phonenumber;
	
	ifstream bimarManager("bimars.txt");
	ofstream bimarManager2("bimars2.txt");
	if (!bimarManager)
	{
		cout << "The file could not be opened!" << endl;
		abort();
	}
	

	cout << "Enter bimarcode to delete. ";
	cin >> bimarcode2;
	cout << endl;
	while (bimarManager >> bimarName)
	{
		bimarManager >> lastName;
		bimarManager >> bimarcode;
		bimarManager >> doctorcode;
		bimarManager >> phonenumber;
        
        if(bimarcode!=bimarcode2)
        {
	
		
			bimarManager2 << bimarName << " " << lastName << " " << bimarcode << " " << doctorcode << " " << phonenumber << " " << endl;
}
	}
	bimarManager2.close();
	bimarManager.close();
	if (remove("bimars.txt") != 0)
		cout << "Error in deleting the original file!" << endl;

	if (rename("bimars2.txt", "bimars.txt") != 0)
		cout << "Error in renaming output file!" << endl;

}

void Searchbimar() {
	string bimarName, SearchName;
	string lastName;
	int bimarcode;
	long long int phonenumber;
	int doctorcode;
	bool found = false;
	cout << "Enter the bimar's name to search:" << endl;
	cin >> SearchName;
	cout << endl;
	while (!bimarManager.eof()) {
		bimarManager >> bimarName;
		bimarManager >> lastName;
		bimarManager >> bimarcode;
		bimarManager >> doctorcode;
		bimarManager >> phonenumber;
		bimarManager >> rate;
		if (SearchName == bimarName) {
			cout << bimarName << " ; " << lastName << " ; " << bimarcode << " ; " << doctorcode << " ; " << phonenumber << " ; " << rate << ";" << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Your selected bimar is not available!" << endl;
	}
}
void showbimar() {
	string bimarName;
	string lastName;
	int bimarcode;
	long phoneNumber;
	
	int doctorcode;
		ifstream bimarManager("bimars.txt");

	while (bimarManager >> bimarName) {
		bimarManager >> lastName;
		bimarManager >> doctorcode;
		bimarManager >> bimarcode;
		bimarManager >> phoneNumber;
		
		cout << bimarName << ";" << lastName << ";" << bimarcode << ";" << doctorcode << ";" << phoneNumber << ";" << endl;
	}
}


void Adddoctor() {
	string name;
	string family;
	long doctorcode;
	string phonenumber;
	string zaminetakhasos;

	int a = 1;
	while (a != 0) {
		cout << "Enter name:" << endl;
		cin >> name;
		cout << "Enter last name:" << endl;
		cin >> family;
		cout << "Enter doctorcode:" << endl;
		cin >> doctorcode;
		cout << "Enter phone number:" << endl;
		cin >> phonenumber;
		cout << "Enterzaminetakhasos:";
			cin >> zaminetakhasos;

		doctorManager << name << "  " << family << "  " << doctorcode << "  " << phonenumber << "  " << zaminetakhasos << endl;
		cout << "For continue Enter 1 & For finish Enter 0:" << endl;
		cin >> a;
	}
}

void removedoctor() {
	string name;
	string family;
	long doctorcode,doctorcode2;
	string phonenumber;
	string zaminetakhasos;
	
	ifstream doctorManager("doctors.txt");
	ofstream doctorManager2("doctors2.txt");
	if (!doctorManager)
	{
		cout << "The file could not be opened!" << endl;
		abort();
	}
	
	
	cout << "Enter doctorcode to delete. ";
	cin >> doctorcode2;
	cout << endl;
	while (doctorManager >> name)
	{
		
		doctorManager >> family;
		doctorManager >> doctorcode;
		doctorManager >> phonenumber;
		doctorManager >> zaminetakhasos;
		
		if(doctorcode!=doctorcode2)
	{	
		
			doctorManager2 << name << " ; " << family << " ; " << doctorcode << " ; " << phonenumber << " ; " << zaminetakhasos << ";" << endl;
	}
}	
	doctorManager2.close();
	doctorManager.close();
	if (remove("doctors.txt") != 0)
		cout << "Error in deleting the original file!" << endl;

	if (rename("doctors2.txt", "doctors.txt") != 0)
		cout << "Error in renaming output file!" << endl;

}
void showdoctor() {
string name;
	string family;
	long doctorcode;
	string phonenumber;
	string zaminetakhasos;
	ifstream doctorManager("doctors.txt");

	while (doctorManager >> name)
	{
		doctorManager >> family;
		doctorManager >> doctorcode;
		doctorManager >> phonenumber;
		doctorManager >> zaminetakhasos;
		
		cout << name << " ; " << family << " ; " << doctorcode << " ; " << phonenumber << " ; " << zaminetakhasos << ";" << endl;
	}
}

void Searchdoctor() {
	string name;
	string family;
	long doctorcode, Searchdoctorcode;
	string phonenumber;
	string zaminetakhasos;
	bool found = false;
	cout << "Enter doctorcode:" << endl;
	cin >> Searchdoctorcode;
	cout << endl;
	while (!doctorManager.eof()) {
		doctorManager >> name;
		doctorManager >> family;
		doctorManager >> doctorcode;
		doctorManager >> phonenumber;
		doctorManager >> zaminetakhasos;
		doctorManager >> averate;
		if (Searchdoctorcode == doctorcode) {
			cout << name << " ; " << family << " ; " << doctorcode << " ; " << phonenumber << " ; " << zaminetakhasos << ";" << averate << ";" << endl;
			found = true;
			break;
		}

	}
	if (!found) {
		cout << "This doctor is not a member." << endl;
	}

}
int main()
{
	string user;
	string user1;
	int pass;
	int pass1;
	ifstream fp("pass.txt");

	fp >> user;
	fp >> pass;

	cout << "please enter username:";
	cin >> user1;
	cout << "please enter pass:";
	cin >> pass1;
	if (user1 == user&&pass1 == pass){
		int i;
		cout << "\n \n \n \t \t \t \t \t      *** welcome ***  \n \n \n \t \t \t \t  Please enter the number of your choice \n \n \n \t \t \t \t \t      -manage bimars- \n \n \n \t \t \t \t 1.show all bimars \n \n \t \t \t \t 2.search bimar \n \n \t \t \t \t 3.add new bimar \n \n \t \t \t \t 4.edit bimars \n \n \t \t \t \t 5.remove bimar \n \n \t \t \t \t \t      -manage doctor- \n \n \t \t \t \t 6.add doctor \n \n \t \t \t \t 7.search doctor \n \n \t \t \t \t 8.removedoctor \n \n \t \t \t \t 9.showdoctor  ";
		cin >> i;

		switch (i)
		{
		case 1: showbimar(); break;
		case 2: Searchbimar(); break;
		case 3: Addbimar(); break;
		case 4: bimarManager.close();
			Editbimar(); break;
		case 5: bimarManager.close();
			removebimar(); break;
		case 6: Adddoctor(); break;
		case 7:Searchdoctor(); break;
		case 8:removedoctor();break;
		case 9:showdoctor();break;

	 default:
			cout << "\n \n Your choice is wrong! \n \n ";

		}
		return 0;
	}
	else
	{
		cout << "wrong";
	}
}



