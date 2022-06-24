#include<iostream>
#include<fstream>
#include"Header.h"
#include<stdlib.h>
#include <string>

using namespace std;

void PrintData(Person& p) {
	p.print();
}

int main() {
	char after_portal;
	system("cls");
	ifstream read;
	read.open("Data.txt");
	if (read.is_open()) {
		char system_name[50];
		Management management;
		ifstream read1;
		read1.open("Passwords.txt");
		//Read data from file "Passwords.txt" and store in Management object.
		//This file contain all data of previous file with passwords additionally
		if (read1.is_open()) {
			char system_name[50];
			read1.getline(system_name, 50);
			management.setSystemName(system_name);
			//cout << management.getSystemName() << endl;
			int manager_count;
			read1 >> manager_count;
			//cout << manager_count << endl;
			read1.ignore();
			char manager_id[50];
			read1.getline(manager_id, 50, ',');
			char manager_name[50];
			read1.getline(manager_name, 50, ',');
			int manager_pass;
			read1 >> manager_pass;
			management.setManager(manager_id, manager_name, manager_pass);
			//cout << management.getManager()->getEmployeeID() << " ";
			//cout << management.getManager()->getPersonName() << " ";
			//cout << management.getManager()->getPass() << endl;
			int totalSalesmans;
			read1 >> totalSalesmans;
			//cout << totalSalesmans;
			management.setTotalSalesmans(totalSalesmans);
			//cout<<management.getTotalSalesman() << endl;
			read1.ignore();
			for (int i = 0; i < totalSalesmans; i++) {
				char id[50];
				read1.getline(id, 50, ',');
				char name[50];
				read1.getline(name, 50, ',');
				management.Add_SalesmansData(id, name);
				int passw;
				read1 >> passw;
				management.PassRecordSalesman(i, passw);
				//cout << management.getRequiredSalesman(i)->getsalesID() << " ";
				//cout << management.getRequiredSalesman(i)->getPersonName() << " ";
				//cout << management.getRequiredSalesman(i)->getStuPass() << endl;
				read1.ignore();
			}

			//cout << endl;
		}
		read1.close();
		int x = -1;
		for (int k = 0; k != x; k++) {
			int b = -1;
			//displaying LogIn Page
			for (int a = 0; a != b; a++) {
				system("cls");
				cout << endl << endl << endl << endl;
				cout << " WELCOME TO:" << endl << endl << endl;
				cout << "				 _______________________________________________" << endl;
				cout << "				|___________";
				cout << management.getSystemName();
				cout << "___________|" << endl;
				if (a != 0) {
					cout << endl << "					Invalid ID or Password. Enter again!" << endl;
				}
				cout << endl << "					Enter Login_ID: ";
				try {
					//Check ID and opens portal according to entred data
					char login[4];
					int len = 0;
					cin >> login;
					for (int i = 0; login[i] != '\0'; i++) {
						len++;
					}
					if (len == 4 || len == 3) {
						//Opens specific portal
						throw login;
					}
					else {
						throw "hello";
					}
				}
				catch (char login[]) {
					int len = 0;
					for (int i = 0; login[i] != '\0'; i++) {
						len++;
					}
					//check whether the entered ID matches Management Saleman's IDs or not
					if (len == 4) {
						// Salesman Portal
						cout << endl << "					Enter Password: ";
						int pass;
						cin >> pass;
						int Salesmans = management.getTotalSalesman();
						for (int i = 0; i < Salesmans; i++) {
							Salesman* Salesman = management.getRequiredSalesman(i);
							char* id = Salesman->getEmployeeID();
							//check whether the entered ID matches Management Salesman's IDs or not
							if (login[0] == id[0] && login[1] == id[1] && login[2] == id[2] && login[3] == id[3] && Salesman->getPass() == pass) {
								int clock1 = -1;
								for (int clock = 0; clock != clock1; clock++) {
									system("cls");
									cout << endl << " ______________________________________________________________________________________________________________________" << endl;
									cout << "|_____________________________________________________SalesmanS' PORTAL_________________________________________________|" << endl;
									cout << endl << endl << " Salesman_Name = ";
									cout << Salesman->getPersonName() << endl;
									cout << " Salesman_ID  = " << id << endl;
									cout << endl << endl;
									cout << "					->Press 'Z' to View List of All Animals" << endl;
									cout << "					->Press 'C' to View List of Available Animals" << endl;
									cout << "					->Press 'G' to add a new Customer" << endl;
									cout << "					->Press 'H' to change Status of Animal" << endl;
									cout << "					->Press 'J' to view Detail of Animal" << endl;
									cout << "					->Press 'L' to reserve a share" << endl;
									cout << "					->Press 'Q' to view reservations of customer" << endl;
									cout << "					->Press 'X' to view Previous Page" << endl;
									a = b - 1;
									//cout << endl << endl << " Press 'B' to view previous page" << endl;
									cout << endl << "				  Press selected Alphabet then press ENTER__ ";
									//Input Alphabet to perform specific task of Saleman
									cin >> after_portal;
									try {
										if (after_portal == 'G' || after_portal == 'g') {
											throw 5;
										}
										if (after_portal == 'H' || after_portal == 'h') {
											//changing status of animal: slaughter, delievered
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_______________________________________________Changing Status of Animals___________________________________________|" << endl;
											cout << endl << endl << endl;
											cout << "		S/N";
											cout << "			" << "AnimalCatogery" << "			" << "Weight" << "				" << "Price" << endl;
											management.changeStatus();
											cout << endl << "					Status of Animal is Updates Successfully!" << endl;
											int null = -1;
											//return to main page
											for (int w = 0; w != null; w++) {
												cout << endl << "					 ->Press 'X' to veiw previous page__";
												char input;
												cin >> input;
												if (input == 'X' || input == 'x') {
													w = null - 1;
												}
												else {
													cout << "					wrong key is pressed...Try Again" << endl;
												}
											}
										}
										if (after_portal == 'J' || after_portal == 'j') {
											//Viewing Animal Detail
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_______________________________________________Viewing Detail of Animals___________________________________________|" << endl;
											cout << endl << endl << endl;
											cout << "		S/N";
											cout << "			" << "AnimalCatogery" << "			" << "Weight" << "				" << "Price" << endl;
											management.showAnimalDetail();
											cout << endl;
											int null = -1;
											//return to main page
											for (int w = 0; w != null; w++) {
												cout << endl << "					 ->Press 'X' to veiw previous page__";
												char input;
												cin >> input;
												if (input == 'X' || input == 'x') {
													w = null - 1;
												}
												else {
													cout << "					wrong key is pressed...Try Again" << endl;
												}
											}
										}
										if (after_portal == 'Z' || after_portal == 'z') {
											//Displaying record of All existing Animals
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_____________________________________________Record of All Available Animals___________________________________________|" << endl;
											cout << endl << endl << endl;
											cout << "		S/N";
											cout << "			" << "AnimalCatogery" << "			" << "Weight" << "				" << "Price" << endl;
											management.viewAllAnimals();
											int null = -1;
											//return to main page
											for (int w = 0; w != null; w++) {
												cout << endl << "					 ->Press 'X' to veiw previous page__";
												char input;
												cin >> input;
												if (input == 'X' || input == 'x') {
													w = null - 1;
												}
												else {
													cout << "					wrong key is pressed...Try Again" << endl;
												}
											}
										}
										if (after_portal == 'C' || after_portal == 'c') {
											//Displaying record of All Available Animals
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_____________________________________________Record of All Available Animals___________________________________________|" << endl;
											cout << endl << endl << endl;
											cout << "		S/N";
											cout << "			" << "AnimalCatogery" << "			" << "Weight" << "				" << "Price" << endl;
											management.viewAvailableAnimals();
											int null = -1;
											//return to main page
											for (int w = 0; w != null; w++) {
												cout << endl << "					 ->Press 'X' to veiw previous page__";
												char input;
												cin >> input;
												if (input == 'X' || input == 'x') {
													w = null - 1;
												}
												else {
													cout << "					wrong key is pressed...Try Again" << endl;
												}
											}
										}
										if (after_portal == 'L' || after_portal == 'l') {
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_____________________________________________Reserving A Share For Customer___________________________________________|" << endl;
											cout << endl << endl << endl;
											int d = -1;
											for (int c = 0; c != d; c++) {
												cout << endl << "				Enter ID of Customer to reserve his share: ";
												string con;
												cin >> con;
												int w = isNumber(con);
												if (w == -1 || w < 1 || w > management.getTotalCustomer()) {
													cout << "					Invalid Data Entered....Try Again!" << endl;
												}
												else {
													c = d - 1;
													cout << endl << endl << "					....Showing Personal Info of Customer...." << endl;
													cout << "		" << " Customer Name: " << management.getCustomer(w - 1)->getPersonName() << endl;
													management.getCustomer(w - 1)->print();
													management.reserveShare(w);
												}
											}
											int null = -1;
											//return to main page
											for (int w = 0; w != null; w++) {
												cout << endl << "					 ->Press 'X' to veiw previous page__";
												char input;
												cin >> input;
												if (input == 'X' || input == 'x') {
													w = null - 1;
												}
												else {
													cout << "					wrong key is pressed...Try Again" << endl;
												}
											}
										}
										if (after_portal == 'Q' || after_portal == 'q') {
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|___________________________________________Total Reservations of Customer_______________________________________|" << endl;
											cout << endl << endl << endl;
											int d = -1;
											for (int c = 0; c != d; c++) {
												cout << endl << "				Enter ID of Customer to reserve his share: ";
												string con;
												cin >> con;
												int w = isNumber(con);
												if (w == -1 || w < 1 || w > management.getTotalCustomer()) {
													cout << "					Invalid Data Entered....Try Again!" << endl;
												}
												else {
													c = d - 1;
													cout << endl << endl << "					....Showing Personal Info of Customer...." << endl;
													cout << "		" << " Customer Name: " << management.getCustomer(w - 1)->getPersonName() << endl;
													management.getCustomer(w - 1)->print();
													int res = management.showTotalReservations(w);
													cout << "					Total Reservations of Selected Customer = " << res << endl;

												}
											}
											int null = -1;
											//return to main page
											for (int w = 0; w != null; w++) {
												cout << endl << "					 ->Press 'X' to veiw previous page__";
												char input;
												cin >> input;
												if (input == 'X' || input == 'x') {
													w = null - 1;
												}
												else {
													cout << "					wrong key is pressed...Try Again" << endl;
												}
											}
										}
										if (after_portal == 'X' || after_portal == 'x')
											clock = clock1 - 1;
										else {
											throw "hello";
										}
									}
									catch (int n) {
										//create new account of Customer
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|_____________________________________________Add New Customer In System___________________________________________|" << endl;
										cout << endl << endl << endl;
										cout << "						Enter Name_";
										char name1[30];
										cin.ignore();
										cin.getline(name1, 30);
										int d = -1;
										for (int c = 0; c != d; c++) {
											cout << "						Enter Contact Number: ";
											bool check = false;
											string con;
											cin >> con;
											int w = isNumber(con);
											if (w == -1) {
												check = true;
												cout << "					Invalid Data Entered....Try Again!" << endl;
											}
											if (check == false) {
												c = d - 1;
												cout << endl << endl << "						Enter Location: ";
												char loc[60];
												cin.ignore();
												cin.getline(loc, 60);
												management.AddNewCustomer(name1, w, loc);
												cout << endl << "					     Customer Is Added Successfully!" << endl;
												int null = -1;
												//return to main page
												for (int w = 0; w != null; w++) {
													cout << endl << "					 ->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
										}
									}
									catch (...) {
										//cout << "You have pressed wrong key" << endl;
									}
								}
							}
						}
					}
					//check whether the entered ID matches Management Manager's IDs or not
					else if (len == 3) {
						//Admin Portal
						cout << endl << "					Enter Password: ";
						int pass;
						cin >> pass;
						Manager* manager = management.getManager();
						char* id = manager->getEmployeeID();
						if (login[0] == id[0] && login[1] == id[1] && login[2] == id[2] && manager->getPass() == pass) {
							int clock1 = -1;
							for (int clock = 0; clock != clock1; clock++) {
								system("cls");
								cout << endl << " ______________________________________________________________________________________________________________________" << endl;
								cout << "|_______________________________________________________ADMIN PORTAL__________________________________________________|" << endl;
								cout << endl << endl << " Manager_Name = ";
								cout << manager->getPersonName() << endl;
								cout << " Manager_ID  = " << id << endl;
								cout << endl << endl;
								cout << "					->Adding  New  Animal:" << endl;
								cout << "						<>Press 'A' to add New Sheep" << endl;
								cout << "						<>Press 'S' to add New Cow" << endl;
								cout << "						<>Press 'D' to add New Camel" << endl << endl;
								cout << "					->Press 'Z' to View List of All Animals" << endl;
								cout << "					->Press 'C' to View List of Available Animals" << endl;
								cout << "					->Press 'F' to add a new Salesman" << endl;
								cout << "					->Press 'G' to add a new Customer" << endl;
								cout << "					->Press 'H' to change Status of Animal" << endl;
								cout << "					->Press 'J' to view Detail of Animal" << endl;
								cout << "					->Press 'K' to make a Schedule" << endl;
								cout << "					->Press 'L' to reserve a share" << endl;
								cout << "					->Press 'Q' to view reservations of customer" << endl;
								cout << "					->Press 'X' to view Previous Page" << endl;
								a = b - 1;
								//cout << endl << endl << " Press 'B' to view previous page" << endl;
								cout << endl << "				  Press selected Alphabet then press ENTER__ ";
								//Input Alphabet to perform specific task of Manager
								cin >> after_portal;
								try {
									//Adding Sheep 
									if (after_portal == 'A' || after_portal == 'a') {
										throw 5;
									}
									if (after_portal == 'S' || after_portal == 's') {
										//Add animal (sheep, cow, camel)
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|______________________________________________Add Animal 'Cow' In System___________________________________________|" << endl;
										int d = -1;
										for (int c = 0; c != d; c++) {
											cout << endl << endl << endl;
											cout << endl << "					Enter Weight of Cow (in Kg) = ";
											bool check = false;
											string weight;
											cin >> weight;
											int w = isNumber(weight);
											if (w == -1) {
												check = true;
												cout << "					Invalid Data Entered....Try Again!" << endl;
											}
											if (check == false) {
												int y = -1;
												for (int z = 0; z != y; z++) {
													check = false;
													cout << endl << endl << endl;
													cout << endl << "					Enter Price of Cow (in Rupees) = ";
													string price;
													cin >> price;
													int p = isNumber(price);
													if (p == -1) {
														check = true;
														cout << "					Invalid Data Entered....Try Again!" << endl;
													}
													if (check == false) {
														z = y - 1;
														management.AddSharedAnimal("cow", w, p);
													}
												}
												c = d - 1;
												cout << endl << "				        Animal 'cow' is Added successfully!" << endl;
												//return to main page
												int null = -1;
												for (int w = 0; w != null; w++) {
													cout << endl << "					 ->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
										}
									}
									if (after_portal == 'D' || after_portal == 'd') {
										//Add animal (sheep, cow, camel)
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|______________________________________________Add Animal 'Camel' In System___________________________________________|" << endl;
										int d = -1;
										for (int c = 0; c != d; c++) {
											cout << endl << endl << endl;
											cout << endl << "					Enter Weight of Camel (in Kg) = ";
											bool check = false;
											string weight;
											cin >> weight;
											int w = isNumber(weight);
											if (w == -1) {
												check = true;
												cout << "					Invalid Data Entered....Try Again!" << endl;
											}
											if (check == false) {
												int y = -1;
												for (int z = 0; z != y; z++) {
													check = false;
													cout << endl << endl << endl;
													cout << endl << "					Enter Price of Camel (in Rupees) = ";
													string price;
													cin >> price;
													int p = isNumber(price);
													if (p == -1) {
														check = true;
														cout << "					Invalid Data Entered....Try Again!" << endl;
													}
													if (check == false) {
														z = y - 1;
														management.AddSharedAnimal("camel", w, p);
													}
												}
												c = d - 1;
												cout << endl << "				        Animal 'camel' is Added successfully!" << endl;
												//return to main page
												int null = -1;
												for (int w = 0; w != null; w++) {
													cout << endl << "					 ->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
										}
									}
									if (after_portal == 'F' || after_portal == 'f') {
										//create new account of Salesman
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|_____________________________________________Add New Salesman In System___________________________________________|" << endl;
										int d = -1;
										//check if ID is valid
										cout << endl << endl << endl;
										for (int c = 0; c != d; c++) {
											bool check = false;
											char tempid[25];
											cout << endl << "						Enter new ID = ";
											cin >> tempid;
											int length = 0;
											for (int j = 0; tempid[j] != '\0'; j++) {
												length++;
											}
											if (length > 4 || length < 4) {
												check = true;
												cout << "				ID must be a 4-digit number" << endl;
											}

											for (int a = 0; a < management.getTotalSalesman(); a++) {
												char* temp = management.getRequiredSalesman(a)->getEmployeeID();
												if (temp[0] == tempid[0] && temp[1] == tempid[1] && temp[2] == tempid[2] && temp[3] == tempid[3] && length == 4) {
													cout << "				Entered ID already exists...Create new data" << endl;
													a = management.getTotalSalesman();
													check = true;
												}
											}
											if (check == false) {
												c = d - 1;
												cout << "						Enter Name_";
												char name1[30];
												cin.ignore();
												cin.getline(name1, 30);
												cout << "						Enter password = ";
												int pass;
												cin >> pass;
												management.AddNewSalesman(tempid, name1, pass);
												management.UpdateData();
												cout << endl << "					     Salesman Account is created";
												int null = -1;
												//return to main page
												for (int w = 0; w != null; w++) {
													cout << endl << "					 ->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
										}
									}
									if (after_portal == 'G' || after_portal == 'g') {
										//create new account of Customer
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|_____________________________________________Add New Customer In System___________________________________________|" << endl;
										cout << endl << endl << endl;
										cout << "						Enter Name_";
										char name1[30];
										cin.ignore();
										cin.getline(name1, 30);
										int d = -1;
										for (int c = 0; c != d; c++) {
											cout << "						Enter Contact Number: ";
											bool check = false;
											string con;
											cin >> con;
											int w = isNumber(con);
											if (w == -1) {
												check = true;
												cout << "					Invalid Data Entered....Try Again!" << endl;
											}
											if (check == false) {
												c = d - 1;
												cout << endl << endl << "						Enter Location: ";
												char loc[60];
												cin.ignore();
												cin.getline(loc, 60);
												management.AddNewCustomer(name1, w, loc);
												cout << endl << "					     Customer Is Added Successfully!" << endl;
												int null = -1;
												//return to main page
												for (int w = 0; w != null; w++) {
													cout << endl << "					 ->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
										}
									}
									if (after_portal == 'H' || after_portal == 'h') {
										//changing status of animal: slaughter, delievered
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|_______________________________________________Changing Status of Animals___________________________________________|" << endl;
										cout << endl << endl << endl;
										cout << "		S/N";
										cout << "			" << "AnimalCatogery" << "			" << "Weight" << "				" << "Price" << endl; 
										management.changeStatus();
										cout << endl << "					Status of Animal is Updates Successfully!" << endl;
										int null = -1;
										//return to main page
										for (int w = 0; w != null; w++) {
											cout << endl << "					 ->Press 'X' to veiw previous page__";
											char input;
											cin >> input;
											if (input == 'X' || input == 'x') {
												w = null - 1;
											}
											else {
												cout << "					wrong key is pressed...Try Again" << endl;
											}
										}
									}
									if (after_portal == 'J' || after_portal == 'j') {
										//Viewing Animal Detail
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|_______________________________________________Viewing Detail of Animals___________________________________________|" << endl;
										cout << endl << endl << endl;
										cout << "		S/N";
										cout << "			" << "AnimalCatogery" << "			" << "Weight" << "				" << "Price" << endl;
										management.showAnimalDetail();
										cout << endl;
										int null = -1;
										//return to main page
										for (int w = 0; w != null; w++) {
											cout << endl << "					 ->Press 'X' to veiw previous page__";
											char input;
											cin >> input;
											if (input == 'X' || input == 'x') {
												w = null - 1;
											}
											else {
												cout << "					wrong key is pressed...Try Again" << endl;
											}
										}
									}
									if (after_portal == 'K' || after_portal == 'k') {
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|___________________________________________Making Schedule To Slaughter Animals_______________________________________|" << endl;
										cout << endl << endl << endl;
										int index[100];
										int total = management.viewOwnedAnimals(index);
										management.makeSchedule(index, total);
										cout << endl << "					Schedule of Animal is Updates Successfully!" << endl;
										int null = -1;
										//return to main page
										for (int w = 0; w != null; w++) {
											cout << endl << "					 ->Press 'X' to veiw previous page__";
											char input;
											cin >> input;
											if (input == 'X' || input == 'x') {
												w = null - 1;
											}
											else {
												cout << "					wrong key is pressed...Try Again" << endl;
											}
										}
									}
									if (after_portal == 'Z' || after_portal == 'z') {
										//Displaying record of All existing Animals
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|_____________________________________________Record of All Available Animals___________________________________________|" << endl;
										cout << endl << endl << endl;
										cout << "		S/N";
										cout << "			" << "AnimalCatogery" << "			" << "Weight" << "				" << "Price" << endl;
										management.viewAllAnimals();
										int null = -1;
										//return to main page
										for (int w = 0; w != null; w++) {
											cout << endl << "					 ->Press 'X' to veiw previous page__";
											char input;
											cin >> input;
											if (input == 'X' || input == 'x') {
												w = null - 1;
											}
											else {
												cout << "					wrong key is pressed...Try Again" << endl;
											}
										}
									}
									if (after_portal == 'C' || after_portal == 'c') {
										//Displaying record of All Available Animals
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|_____________________________________________Record of All Available Animals___________________________________________|" << endl;
										cout << endl << endl << endl;
										cout << "		S/N";
										cout << "			" << "AnimalCatogery" << "			" << "Weight" << "				" << "Price" << endl;
										management.viewAvailableAnimals();
										int null = -1;
										//return to main page
										for (int w = 0; w != null; w++) {
											cout << endl << "					 ->Press 'X' to veiw previous page__";
											char input;
											cin >> input;
											if (input == 'X' || input == 'x') {
												w = null - 1;
											}
											else {
												cout << "					wrong key is pressed...Try Again" << endl;
											}
										}
									}
									if (after_portal == 'L' || after_portal == 'l') {
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|_____________________________________________Reserving A Share For Customer___________________________________________|" << endl;
										cout << endl << endl << endl;
										int d = -1;
										for (int c = 0; c != d; c++) {
											cout << endl << "				Enter ID of Customer to reserve his share: ";
											string con;
											cin >> con;
											int w = isNumber(con);
											if (w == -1 || w < 1 || w > management.getTotalCustomer()) {
												cout << "					Invalid Data Entered....Try Again!" << endl;
											}
											else {
												c = d - 1;
												cout << endl << endl << "					....Showing Personal Info of Customer...." << endl;
												cout << "		" <<" Customer Name: " << management.getCustomer(w - 1)->getPersonName() << endl;
												management.getCustomer(w - 1)->print();
												management.reserveShare(w);
											}
										}
										int null = -1;
										//return to main page
										for (int w = 0; w != null; w++) {
											cout << endl << "					 ->Press 'X' to veiw previous page__";
											char input;
											cin >> input;
											if (input == 'X' || input == 'x') {
												w = null - 1;
											}
											else {
												cout << "					wrong key is pressed...Try Again" << endl;
											}
										}
									}
									if (after_portal == 'Q' || after_portal == 'q') {
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|___________________________________________Total Reservations of Customer_______________________________________|" << endl;
										cout << endl << endl << endl;
										int d = -1;
										for (int c = 0; c != d; c++) {
											cout << endl << "				Enter ID of Customer to reserve his share: ";
											string con;
											cin >> con;
											int w = isNumber(con);
											if (w == -1 || w < 1 || w > management.getTotalCustomer()) {
												cout << "					Invalid Data Entered....Try Again!" << endl;
											}
											else {
												c = d - 1;
												cout << endl << endl << "					....Showing Personal Info of Customer...." << endl;
												cout << "		" << " Customer Name: " << management.getCustomer(w - 1)->getPersonName() << endl;
												management.getCustomer(w - 1)->print();
												int res = management.showTotalReservations(w);
												cout << "					Total Reservations of Selected Customer = " << res << endl;

											}
										}
										int null = -1;
										//return to main page
										for (int w = 0; w != null; w++) {
											cout << endl << "					 ->Press 'X' to veiw previous page__";
											char input;
											cin >> input;
											if (input == 'X' || input == 'x') {
												w = null - 1;
											}
											else {
												cout << "					wrong key is pressed...Try Again" << endl;
											}
										}
									}
									if (after_portal == 'X' || after_portal == 'x')
										clock = clock1 - 1;
									else {
										throw "hello";
									}
								}
								catch (int n) {
									//Add animal (sheep, cow, camel)
									system("cls");
									cout << endl << " ______________________________________________________________________________________________________________________" << endl;
									cout << "|______________________________________________Add Animal 'Sheep' In System___________________________________________|" << endl;
									int d = -1;
									for (int c = 0; c != d; c++) {
										cout << endl << endl << endl;
										cout << endl << "					Enter Weight of Sheep (in Kg) = ";
										bool check = false;
										string weight;
										cin >> weight;
										int w = isNumber(weight);
										if (w == -1) {
											check = true;
											cout << "					Invalid Data Entered....Try Again!" << endl;
										}
										if (check == false) {
											int y = -1;
											for (int z = 0; z != y; z++) {
												check = false;
												cout << endl << endl << endl;
												cout << endl << "					Enter Price of Sheep (in Rupees) = ";
												string price;
												cin >> price;
												int p = isNumber(price);
												if (p == -1) {
													check = true;
													cout << "					Invalid Data Entered....Try Again!" << endl;
												}
												if (check == false) {
													z = y - 1;
													management.AddSingleAnimal("sheep", w, p);
												}
											}
											c = d - 1;
											cout << endl << "				        Animal 'sheep' is Added successfully!" << endl;
											//return to main page
											int null = -1;
											for (int w = 0; w != null; w++) {
												cout << endl << "					 ->Press 'X' to veiw previous page__";
												char input;
												cin >> input;
												if (input == 'X' || input == 'x') {
													w = null - 1;
												}
												else {
													cout << "					wrong key is pressed...Try Again" << endl;
												}
											}
										}
									}
								}
								catch (...) {
									//cout << "You have pressed wrong key" << endl;
								}
							}
							
						}
					}
				}
				catch (...) {
					//cout << endl << "					Invalid ID or Password";
				}
			}
			//opens login page again
		}
	}
	

	system("PAUSE");
	return 0;
}