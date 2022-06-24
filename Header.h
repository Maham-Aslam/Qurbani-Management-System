#pragma once
#include<iostream>
#include<fstream>
#include <string>

using namespace std;

int isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return -1;

	return stoi(s);
}

class Schedule {
	string time;
	int day;
public:
	Schedule() {
		time = "";
		day = 0;
	}
	Schedule(int sday, string stime) {
		day = sday;
		time = stime;
	}
	Schedule(Schedule const& obj) {
		day = obj.day;
		time = obj.time;
	}
	void setDay(int d) {
		day = d;
	}
	void setTime(string t) {
		time = t;
	}
	int getDay() {
		return day;
	}
	string getTime() {
		return time;
	}
};

class Person {
	char* first_name;
public:
	Person();
	Person(char[]);
	Person(const Person&);
	char* getPersonName();
	void setPersonName(char* n) {
		int len = 0;
		for (int i = 0; n[i] != '\0'; i++) {
			len++;
		}
		first_name = new char[len + 1];
		for (int i = 0; i <= len; i++) {
			first_name[i] = n[i];
		}
	}
	virtual void show() = 0;
	virtual void print() {
		cout << "Name = " << first_name << endl;
	}
	virtual ~Person() {
		delete[]first_name;
	}
};
class Employee :public Person {
	char* id;
	int pass;
public:
	Employee() :Person(0) {
		id = 0;
		pass = 0;
	}
	Employee(char idee[], char f[], int passw) :Person(f) {
		pass = passw;
		int len = 0;
		for (int i = 0; idee[i] != '\0'; i++) {
			len++;
		}
		id = new char[len + 1];
		for (int i = 0; i <= len; i++) {
			id[i] = idee[i];
		}
	}
	Employee(const Employee& obj) {
		id = obj.id;
		pass = obj.pass;
	}
	char* getEmployeeID() {
		return id;
	}
	void setPass(int n) {
		pass = n;
	}
	int getPass() {
		return pass;
	}
	void show() {
		cout << "Employee_ID = " << id << endl;
	}
	void print() {
		Person::print();
		cout << "Employee_ID = " << id << endl;
	}
	virtual ~Employee() {
		delete[]id;
	}
};

class Manager :public Employee {

public:
	Manager() :Employee(0, 0, 0) {}
	Manager(char idee[], char f[], int pas) :Employee(idee, f, pas) {}
	~Manager() {}
};
class Salesman :public Employee {
	static int Salesman_count;
public:
	Salesman(char idee[], char f[]) :Employee(idee, f, 0) {
		Salesman_count++;
	}
	void show() {
		cout << "Salesman_ID = " << getEmployeeID() << endl;
	}
	void print() {
		Person::print();
		cout << "Salesman_ID = " << getEmployeeID() << endl;
	}
	~Salesman() {}
};

class Customer : public Person {
private:
	int customerId;
	int contact;
	char* address;
public:
	Customer() : Person(0) {
		contact = 0;
		address = nullptr;
	}
	Customer(char obj_name[], int con, char loc[]) :Person(obj_name) {
		contact = con;
		int len = 0;
		for (int i = 0; loc[i] != '\0'; i++) {
			len++;
		}
		address = new char[len + 1];
		for (int i = 0; i <= len; i++) {
			address[i] = loc[i];
		}
	}
	Customer(Customer const& obj) {
		customerId = obj.customerId;
		contact = obj.contact;
		address = obj.address;
	}
	void setPhone(int n) {
		contact = n;
	}
	void setLoc(char loc[]) {
		int len = 0;
		for (int i = 0; loc[i] != '\0'; i++) {
			len++;
		}
		address = new char[len + 1];
		for (int i = 0; i <= len; i++) {
			address[i] = loc[i];
		}
	}
	void setID(int n) {
		customerId = n;
	}
	int getID() {
		return customerId;
	}
	int getCon() {
		return contact;
	}
	char* getLoc() {
		return address;
	}
	void show() {

	}
	void print() {
		cout << "		" << " Phone Number: " << contact << endl;
		cout << "		" << " Address: " << address << endl;
	}
};

struct sharedOwner {
	Customer* cust;
	int sharehold;
	sharedOwner() {
		cust = nullptr;
		sharehold = 0;
	}
	sharedOwner(Customer* c, int sh) {
		cust = c;
		sharehold = sh;
	}
};

class Animal {
private:
	string name;
	int weight;
	int price;
	bool slaughter;
	bool deliever;
	static int token_number;
	Schedule* schedule;
public:
	Animal() {
		name = '\0';
		weight = 0;
		price = 0;
		slaughter = false;
		deliever = false;
		token_number += 1;
		schedule = nullptr;
	}
	Animal(string obj_name, int obj_weight, int obj_price) {
		name = obj_name;
		weight = obj_weight;
		price = obj_price;
		slaughter = false;
		deliever = false;
		token_number += 1;
		schedule = nullptr;
	}
	void changeSlaughter(int n) {
		cout << endl << endl << "					....Updatig Status of Shortlisted Animal...." << endl;
		cout << "		S/N";
		cout << "			" << "AnimalCatogery" << "			" << "Weight" << "				" << "Price" << endl;
		cout << "		" << n;
		print();
		int d = -1;
		for (int c = 0; c != d; c++) {
			cout << endl << endl << "					Press 1 if Animal is Slaughtered" << endl;
			cout << "					Press 0 if animal is not slaughtered" << endl;
			cout << endl << endl << "						Enter Selected Number: ";
			string con;
			cin >> con;
			int w = isNumber(con);
			if (w == -1) {
				cout << "					Invalid Data Entered....Try Again!" << endl;
			}
			else if (w == 0) {
				slaughter = false;
				c = d - 1;
				cout << "					Slaughter Status is Updated Successfully!" << endl;
			}
			else if (w == 1) {
				c = d - 1;
				slaughter = true;
				cout << "					Slaughter Status is Updated Successfully!" << endl;
			}
			else
				cout << "					Invalid Data Entered....Try Again!" << endl;
		}
	}
	void changeDeliever() {
		int d = -1;
		for (int c = 0; c != d; c++) {
			cout << endl << "					Press 1 if Animal is Delievered" << endl;
			cout << "					Press 0 if animal is not Delievered" << endl;
			cout << endl << endl << "						Enter Selected Number: ";
			string con;
			cin >> con;
			int w = isNumber(con);
			if (w == -1) {
				cout << "					Invalid Data Entered....Try Again!" << endl;
			}
			else if (w == 0) {
				deliever = false;
				c = d - 1;
				cout << "					Deleivery Status is Updated Successfully!" << endl;
			}
			else if (w == 1) {
				c = d - 1;
				deliever = true;
				cout << "					Delievery Status is Updated Successfully!" << endl;
			}
			else
				cout << "					Invalid Data Entered....Try Again!" << endl;
		}
	}
	void updateSchedule(int n) {
		cout << endl << endl << "					....Making Schedule of Shortlisted Animal...." << endl;
		cout << "		S/N";
		cout << "			" << "AnimalCatogery" << "			" << "Weight" << "				" << "Price" << endl;
		cout << "		" << n;
		print();
		int d = -1;
		for (int c = 0; c != d; c++) {
			cout << endl << endl << "					Press 1 to select 1st Eid day" << endl;
			cout << "					Press 2 to select 2nd Eid day" << endl;
			cout << "					Press 3 to select 3rd Eid day" << endl;
			cout << endl << endl << "						Enter Selected Number: ";
			string con;
			cin >> con;
			int w = isNumber(con);
			if (w == -1) {
				cout << "					Invalid Data Entered....Try Again!" << endl;
			}
			else if (w > 0 && w < 4) {
				schedule = new Schedule;
				schedule->setDay(w);
				cout << endl << endl << "					Enter Slaughter Time: " << endl;
				string tim;
				cin >> tim;
				schedule->setTime(tim);
				c = d - 1;
				cout << "					Slaughter Schedule is Updated Successfully!" << endl;
			}
			else
				cout << "					Invalid Data Entered....Try Again!" << endl;
		}
	}
	void print() {
		cout << "			" << name;
		cout << "     	    	   	 " << weight;
		cout << "    		      		" << price << endl;
	}
	void AnimalDetail() {
		cout << endl << endl << "					....Showing Detail of Shortlisted Animal...." << endl;
		cout << "					Animal Category: " << name << endl;
		cout << "					Token Number: " << token_number << endl;
		cout << "					Weight = " << weight << endl;
		cout << "					Price = " << price << endl;
		cout << "					Slaughter Status: " << slaughter << endl;
		cout << "					Delievery Status: " << deliever << endl;
		if(schedule == nullptr)
			cout << "					schedule: Not Scheduled Yet" << endl;
		else
			cout << "					schedule: " << schedule->getDay() <<"	" << schedule->getTime() << endl;
	}
};

class SingleAnimal : public Animal {
	Customer* owner;
public:
	SingleAnimal() :Animal("", 0, 0) {
		owner = nullptr;
	}
	SingleAnimal(string animName, int w, int p) :Animal(animName, w, p) {
		owner = nullptr;
	}
	Customer* getOwner() {
		return owner;
	}
	void setOwner(Customer* c) {
		owner = new Customer(c->getPersonName(), c->getCon(), c->getLoc());
		owner->setID(c->getID());
	}
	void SADetail() {
		AnimalDetail();
		if (owner == nullptr)
			cout << "					Owner Name: Not Owned Yet" << endl;
		else
			cout << "					Owner Name: " << getOwner()->getPersonName() << endl;
	}
};

	class SharedAnimal : public Animal {
		sharedOwner owners[7];
		int size = 0;
	public:
		SharedAnimal() :Animal("", 0, 0) {
			size = 0;
		}
		SharedAnimal(string animName, int w, int p) :Animal(animName, w, p) {
			size = 0;
		}
		void setShare(Customer* c, int s) {
			owners[size].cust = c;
			owners[size++].sharehold = s;
		}
		sharedOwner* getOwnerList() {
			return owners;
		}
		Customer* getReqOwner(int n) {
			if (owners == nullptr)
				return nullptr;
			return owners[n].cust;
		}
		int getReqShare(int n) {
			return owners[n].sharehold;
		}
		int getSize() {
			return size;
		}
		void setsharedOwner(Customer* c) {
			int sh = 0;
			for (int i = 0; i < getSize(); i++) {
				sh += owners[i].sharehold;
			}
			sh = 7 - sh;
			int d = -1;
			for (int ci = 0; ci != d; ci++) {
				cout << endl << endl << "					Enter number of shares to reserve: ";
				string con;
				cin >> con;
				int w = isNumber(con);
				if (w == -1) {
					cout << "					Invalid Data Entered....Try Again!" << endl;
				}
				else if (w == 0) {
					ci = d - 1;
					cout << "					No Share is Reserved for value 0!" << endl;
				}
				else if (w  > 0 && w <= sh) {
					ci = d - 1;
					owners[size].cust = new Customer(c->getPersonName(), c->getCon(), c->getLoc());
					owners[size].sharehold = w;
					owners[size].cust->setID(c->getID());
					size++;
				}
				else
					cout << "					Invalid Data Entered....Try Again!" << endl;
			}
		}
		void ShADetail() {
			AnimalDetail();
			for (int i = 0; i < getSize(); i++){
				cout << "					Owner " << i + 1 << ": " << owners[i].cust->getPersonName();
				cout << "	Share: " << owners[i].sharehold;
			}
			if(getSize() == 0)
				cout << "					Owner Name: Not Owned Yet" << endl;
		}
	};

	class Management {
		char* system_name;
		Manager* admin;
		Salesman** salesman_list;
		int total_Salesmans;
		int current_Salesmans;
		SingleAnimal** singleAnimal_list;
		int total_singleAnimal;
		SharedAnimal** sharedAnimal_list;
		int total_sharedAnimal;
		Customer** customerList;
		int total_Customer;
	public:
		Management();
		Management(const char[]);
		Management(const Management& obj);
		void setSystemName(char[]);
		char* getSystemName();
		void setManager(char[], char[], int);
		Manager* getManager();
		void setTotalSalesmans(int);
		int getTotalSalesman();
		Salesman* getRequiredSalesman(int);
		void Add_SalesmansData(char[], char[]);
		void PassRecordSalesman(int, int);
		int getTotalSingle();
		void setTotalSingle(int);
		void AddSingleAnimal(string, int, int);
		int getTotalShared();
		void setTotalShared(int);
		void AddSharedAnimal(string, int, int);
		void AddNewSalesman(char[], char[], int);
		void UpdateData();
		void viewAllAnimals();
		void viewAvailableAnimals();
		int viewOwnedAnimals(int[]);
		void AddNewCustomer(char[], int, char[]);
		int getTotalCustomer();
		void setTotalCustomer(int);
		Customer* getCustomer(int);
		void changeStatus();
		void makeSchedule(int[], int);
		void reserveShare(int);
		void showAnimalDetail();
		int showTotalReservations(int);
		~Management();
	};

	int Salesman::Salesman_count = 0;
	int Animal::token_number = 0;

	Person::Person() {
		first_name = nullptr;
	}
	Person::Person(char first[]) {
		int len = 0;
		for (int i = 0; first[i] != '\0'; i++) {
			len++;
		}
		first_name = new char[len + 1];
		for (int i = 0; i <= len; i++) {
			first_name[i] = first[i];
		}

	}
	Person::Person(const Person& obj) {
		first_name = obj.first_name;
	}
	char* Person::getPersonName() {
		return first_name;
	}



	Management::Management() {
		system_name = nullptr;
		admin = nullptr;
		salesman_list = nullptr;
		total_Salesmans = 0;
		current_Salesmans = 0;
		total_singleAnimal = 0;
		total_sharedAnimal = 0;
		singleAnimal_list = nullptr;
		sharedAnimal_list = nullptr;
		total_Customer = 0;
		customerList = 0;
	}
	Management::Management(const char name[]) {
		total_singleAnimal = 0;
		total_sharedAnimal = 0;
		admin = nullptr;
		salesman_list = nullptr;
		total_Salesmans = 0;
		current_Salesmans = 0;
		singleAnimal_list = nullptr;
		sharedAnimal_list = nullptr;
		total_Customer = 0;
		customerList = nullptr;
		int len = 0;
		for (int i = 0; name[i] != '\0'; i++) {
			len++;
		}
		system_name = new char[len + 2];
		for (int i = 0; i <= len; i++) {
			system_name[i] = name[i];
		}
	}
	Management::Management(const Management& obj) {
		total_singleAnimal = obj.total_singleAnimal;
		total_sharedAnimal = obj.total_sharedAnimal;
		admin = obj.admin;
		salesman_list = obj.salesman_list;
		total_Salesmans = obj.total_Salesmans;
		current_Salesmans = obj.current_Salesmans;
		int len = 0;
		for (int i = 0; obj.system_name[i] != '\0'; i++) {
			len++;
		}
		system_name = new char[len + 2];
		for (int i = 0; i <= len; i++) {
			system_name[i] = obj.system_name[i];
		}
	}
	void Management::setSystemName(char name[]) {
		int len = 0;
		for (int i = 0; name[i] != '\0'; i++) {
			len++;
		}
		system_name = new char[len + 2];
		for (int i = 0; i <= len; i++) {
			system_name[i] = name[i];
		}
	}
	char* Management::getSystemName() {
		return system_name;
	}
	void Management::setManager(char idee[], char name[], int passw) {
		admin = new Manager(idee, name, passw);
	}
	Manager* Management::getManager() {
		return admin;
	}
	void Management::setTotalSalesmans(int n) {
		total_Salesmans = n;
		salesman_list = new Salesman * [total_Salesmans];
	}
	int Management::getTotalSalesman() {
		return total_Salesmans;
	}

	Salesman* Management::getRequiredSalesman(int n) {
		return salesman_list[n];
	}
	void Management::Add_SalesmansData(char idee[], char name[]) {
		salesman_list[current_Salesmans++] = new Salesman(idee, name);
	}
	void Management::PassRecordSalesman(int num, int pass) {
		getRequiredSalesman(num)->setPass(pass);
	}
	int Management::getTotalSingle() {
		return total_singleAnimal;
	}
	int Management::getTotalShared() {
		return total_sharedAnimal;
	}
	void Management::setTotalSingle(int n) {
		total_singleAnimal = n;
	}
	void Management::setTotalShared(int n) {
		total_sharedAnimal = n;
	}
	Customer* Management::getCustomer(int n) {
		return customerList[n];
	}
	void Management::AddSingleAnimal(string Aname, int w, int p) {
		int total = getTotalSingle();
		SingleAnimal** list = new SingleAnimal * [total];
		for (int i = 0; i < total; i++) {
			list[i] = singleAnimal_list[i];
		}
		singleAnimal_list = nullptr;
		setTotalSingle(total_singleAnimal + 1);
		singleAnimal_list = new SingleAnimal * [total_singleAnimal];
		for (int i = 0; i < total_singleAnimal - 1; i++) {
			singleAnimal_list[i] = list[i];
		}
		singleAnimal_list[total_singleAnimal - 1] = new SingleAnimal(Aname, w, p);
	}
	void Management::AddSharedAnimal(string Aname, int w, int p) {
		int total = getTotalShared();
		SharedAnimal** list = new SharedAnimal * [total];
		for (int i = 0; i < total; i++) {
			list[i] = sharedAnimal_list[i];
		}
		sharedAnimal_list = nullptr;
		setTotalShared(total_sharedAnimal + 1);
		sharedAnimal_list = new SharedAnimal * [total_sharedAnimal];
		for (int i = 0; i < total_sharedAnimal - 1; i++) {
			sharedAnimal_list[i] = list[i];
		}
		sharedAnimal_list[total_sharedAnimal - 1] = new SharedAnimal(Aname, w, p);
	}
	void Management::AddNewSalesman(char idee[], char name[], int pass) {
		int total = getTotalSalesman();
		Salesman** list = new Salesman * [total];
		for (int i = 0; i < total; i++) {
			list[i] = salesman_list[i];
		}
		salesman_list = nullptr;
		setTotalSalesmans(total_Salesmans + 1);
		salesman_list = new Salesman * [total_Salesmans];
		current_Salesmans++;
		for (int i = 0; i < total_Salesmans - 1; i++) {
			salesman_list[i] = list[i];
		}
		salesman_list[total_Salesmans - 1] = new Salesman(idee, name);
		salesman_list[total_Salesmans - 1]->setPass(pass);
	}
	void Management::UpdateData() {
		ofstream writes;
		writes.open("Passwords.txt");
		if (writes.is_open()) {
			writes << getSystemName() << endl;
			writes << "1" << endl;
			writes << getManager()->getEmployeeID() << ",";
			writes << getManager()->getPersonName() << ",";
			writes << getManager()->getPass() << endl;
			writes << getTotalSalesman() << endl;
			for (int k = 0; k < getTotalSalesman(); k++) {
				writes << getRequiredSalesman(k)->getEmployeeID() << ",";
				writes << getRequiredSalesman(k)->getPersonName() << ",";
				writes << getRequiredSalesman(k)->getPass() << endl;
			}
		}
		writes.close();
	}

	void Management::viewAllAnimals() {
		int count = 1;
		int total = getTotalSingle();
		for (int i = 0; i < total; i++) {
			cout << "		" << count++;
			singleAnimal_list[i]->print();
		}
		total = getTotalShared();
		for (int i = 0; i < total; i++) {
			cout << "		" << count++;
			sharedAnimal_list[i]->print();
		}

	}
	void Management::viewAvailableAnimals() {
		int count = 1;
		int total = getTotalSingle();
		for (int i = 0; i < total; i++) {
			if (singleAnimal_list[i]->getOwner() == nullptr) {
				cout << "		" << count++;
				singleAnimal_list[i]->print();
			}
		}
		total = getTotalShared();
		for (int i = 0; i < total; i++) {
			if (sharedAnimal_list[i]->getReqOwner(0) == nullptr) {
				cout << "		" << count++;
				sharedAnimal_list[i]->print();
			}
			else {
				int sum = 0;
				for (int j = 0; j < sharedAnimal_list[i]->getSize(); j++)
					sum += sharedAnimal_list[i]->getReqShare(j);
				if (sum < 8) {
					cout << "		" << count++;
					sharedAnimal_list[i]->print();
				}
			}
		}
	}
	int Management::viewOwnedAnimals(int index[]) {
		int count = 1;
		int total = getTotalSingle();
		for (int i = 0; i < total; i++) {
			if (singleAnimal_list[i]->getOwner() != nullptr) {
				index[count - 1] = i;
				cout << "		" << count++;
				singleAnimal_list[i]->print();
			}
		}
		index[count - 1] = -1;
		count++;
		total = getTotalShared();
		for (int i = 0; i < total; i++) {
			if (sharedAnimal_list[i]->getReqOwner(0) != nullptr) {
				index[count - 1] = i;
				cout << "		" << count - 1;
				count++;
				sharedAnimal_list[i]->print();
			}
		}
		return count - 1;
	}
	void Management::setTotalCustomer(int n) {
		total_Customer = n;
	}
	int Management::getTotalCustomer() {
		return total_Customer;
	}
	void Management::AddNewCustomer(char name[], int pho, char loc[]) {
		int total = getTotalCustomer();
		Customer** list = new Customer * [total];
		for (int i = 0; i < total; i++) {
			list[i] = customerList[i];
		}
		customerList = nullptr;
		setTotalCustomer(total_Customer + 1);
		customerList = new Customer * [total_Customer];
		for (int i = 0; i < total_Customer - 1; i++) {
			customerList[i] = list[i];
		}
		customerList[total_Customer - 1] = new Customer(name, pho, loc);
		customerList[total_Customer - 1]->setID(total_Customer);
	}
	void Management::changeStatus() {
		Management::viewAllAnimals();
		int d = -1;
		for (int c = 0; c != d; c++) {
			cout << endl << "				Select Serial Number of Animal to Change its Status: ";
			string con;
			cin >> con;
			int w = isNumber(con);
			if (w == -1) {
				cout << "					Invalid Data Entered....Try Again!" << endl;
			}
			else {
				int total = getTotalSingle() + getTotalShared();
				if (w <= total) {
					c = d - 1;
					if (w <= getTotalSingle()) {
						singleAnimal_list[w - 1]->changeSlaughter(w);
						singleAnimal_list[w - 1]->changeDeliever();
					}
					else {
						int index = w - getTotalSingle() - 1;
						sharedAnimal_list[index]->changeSlaughter(w);
						sharedAnimal_list[index]->changeDeliever();
					}
				}
			}
		}
	}
	void Management::makeSchedule(int index[], int size) {
		int d = -1;
		for (int c = 0; c != d; c++) {
			cout << endl << "				Select Serial Number of Animal to Make Its Schedule: ";
			string con;
			cin >> con;
			int w = isNumber(con);
			if (w == -1) {
				cout << "					Invalid Data Entered....Try Again!" << endl;
			}
			else {
				if (w <= size && index[size] != -1 && w != 0) {
					int half = 0;
					for (int i = 0; index[i] != -1; i++)
						half++;
					c = d - 1;
					if (w <= half) {
						singleAnimal_list[index[w - 1]]->updateSchedule(w);
					}
					else if (w > half + 1) {
						sharedAnimal_list[index[w - 1]]->updateSchedule(w);
					}
				}
			}
		}
	}
	void Management::reserveShare(int n) {
		int d = -1;
		for (int c = 0; c != d; c++) {
			cout << endl << endl << "					Press 0 to own single animal" << endl;
			cout << "					Press 1 to own shared animal" << endl;
			cout << endl << endl << "						Enter Selected Number: ";
			string con;
			cin >> con;
			int w = isNumber(con);
			if (w == -1) {
				cout << "					Invalid Data Entered....Try Again!" << endl;
			}
			else if (w == 0) {
				c = d - 1;
				int count = 1;
				cout << "		S/N";
				cout << "			" << "AnimalCatogery" << "			" << "Weight" << "				" << "Price" << endl;
				int total = getTotalSingle();
				for (int i = 0; i < total; i++) {
					if (singleAnimal_list[i]->getOwner() == nullptr) {
						cout << "		" << count++;
						singleAnimal_list[i]->print();
					}
				}
				int y = -1;
				for (int x = 0; x != y; x++) {
					cout << endl << endl << "						Enter Selected Number: ";
					string num;
					cin >> num;
					int t = isNumber(num);
					if (t == -1) {
						cout << "					Invalid Data Entered....Try Again!" << endl;
					}
					else if (t <= count) {
						x = y - 1;
						singleAnimal_list[t - 1]->setOwner(getCustomer(n - 1));
						cout << "					Single Animal is owned successfully!" << endl;
					}
				}
			}
			else if (w == 1) {
				c = d - 1;
				int count = 1;
				int sum = 0;
				cout << "	S/N" << "	" << "AvailableShares";
				cout << "		" << "AnimalCatogery" << "				" << "Weight" << "				" << "Price" << endl;

				int total = getTotalShared();
				for (int i = 0; i < total; i++) {
					sum = 0;
					if (sharedAnimal_list[i]->getReqOwner(0) == nullptr) {
						cout << "	" << count++;
						cout << "		" << 7 - sum;
						sharedAnimal_list[i]->print();
					}
					else {
						for (int j = 0; j < sharedAnimal_list[i]->getSize(); j++)
							sum += sharedAnimal_list[i]->getReqShare(j);
						if (sum < 8) {
							cout << "	" << count++;
							cout << "	" << 7 - sum;
							sharedAnimal_list[i]->print();
						}
					}
				}
				int y = -1;
				for (int x = 0; x != y; x++) {
					cout << endl << endl << "						Enter Selected Number: ";
					string num;
					cin >> num;
					int t = isNumber(num);
					if (t == -1) {
						cout << "					Invalid Data Entered....Try Again!" << endl;
					}
					else if (t <= count) {
						x = y - 1;
						sharedAnimal_list[t - 1]->setsharedOwner(getCustomer(n - 1));
						cout << "						Shared Animal is owned successfully!" << endl;
					}
				}
			}
			else
				cout << "					Invalid Data Entered....Try Again!" << endl;
		}
	}
	void Management::showAnimalDetail() {
		Management::viewAllAnimals();
		int d = -1;
		for (int c = 0; c != d; c++) {
			cout << endl << "				Select Serial Number of Animal to View Its Detail: ";
			string con;
			cin >> con;
			int w = isNumber(con);
			if (w == -1) {
				cout << "					Invalid Data Entered....Try Again!" << endl;
			}
			else {
				int total = getTotalSingle() + getTotalShared();
				if (w <= total) {
					c = d - 1;
					if (w <= getTotalSingle()) {
						singleAnimal_list[w - 1]->SADetail();
					}
					else {
						int index = w - getTotalSingle() - 1;
						sharedAnimal_list[index]->ShADetail();
					}
				}
			}
		}
	}
	int Management::showTotalReservations(int w) {
		int sum = 0;
		for (int i = 0; i < getTotalSingle(); i++){
			if (singleAnimal_list[i]->getOwner()->getID() == w) {
				sum += 1;
			}
	}
		for (int i = 0; i < getTotalShared(); i++) {
			bool check = true;
			for (int j = 0; check == true && j < sharedAnimal_list[i]->getSize(); j++) {
				if (sharedAnimal_list[i]->getReqOwner(j)->getID() == w) {
					check = false;
					sum += sharedAnimal_list[i]->getReqShare(j);
				}
			}
		}
		return sum;
	}
	Management::~Management() {
		delete[]system_name;
	}


