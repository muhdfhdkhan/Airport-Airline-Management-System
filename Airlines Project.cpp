/* 
   Airline Management System - C++
   Created by Group Alpha (2024)
   Licensed under the MIT License
   You are free to use, modify, and distribute this software.
*/

#include<iostream>
#include<fstream>	//file handling
using namespace std;
// Global Variables
	int bseat=30;	//no of buisness seats
	int eseat=30;	//no of economy seats
	int tflight=1;	//no of total flights set default 1
	int bprice=1300;	//price of buisness class ticket
	int eprice=800;		//price of economy class ticket
	int tbooking=0;		//track total booking
	int tprofit=0;		//total profit

// String to store default password for privacy

	string adminp="snlf";		//admin password
	string passp="fls";			//passenger passworrd

//Arrays to store the destinations and initial point
	string dnn[20];			//array to store destination 
	string spp[20];			//array of store initial points
	int ddd[20];			//array of int to store distance according to destination index
	int pnum[20];			//array to store plane number
	int dcount=0;			//number of destination added

//seat tracking arrays
	int bstatus[30]={0}; 		//buisness seat status for allocation	
	int estatus[30]={0};		//economy seat status allocation

//function to save the detail of input data of passenger
void savefile(string name, string cnic, int pno,int planeno,string phno, string initial,string destination,string date,char ttype, int seatno, int amount ){
	ofstream outf("booking.txt");
	outf<<"Name: "<<name<<endl;
	outf<<"CNIC NO: "<<cnic<<endl;
	outf<<"Passport No: "<<pno<<endl;
	outf<<"Travel from:"<<initial<<" to "<<destination<<endl;
	outf<<"Seat no: "<<seatno<<endl;
	outf<<"Travel Type: "<<ttype<<endl;
	outf<<"Date: "<<date<<endl;
	outf<<"Contact info: "<<phno<<endl;
	outf<<"Plane no: "<<planeno<<endl;
	outf<<"Total Amount: PKR"<<amount<<endl;
}

//function to dispaly the ticket in main menu

void display(string name, string cnic, int pno,int planeno,string phno, string initial,string destination,string date,char ttype, int seatno, int amount ){
	cout<<"==============Ticket Detail============ \n";
	cout<<"Name: "<<name<<endl;
	cout<<"CNIC NO: "<<cnic<<endl;
	cout<<"Passport No: "<<pno<<endl;
	cout<<"Travel from:"<<initial<<" to "<<destination<<endl;
	cout<<"Seat no: "<<seatno<<endl;
	cout<<"Travel Type: "<<ttype<<endl;
	cout<<"Date: "<<date<<endl;
	cout<<"Contact info: "<<phno<<endl;
	cout<<"Plane no: "<<planeno<<endl;
	cout<<"Total Amount: PKR"<<amount<<endl;
	cout<<"======================================= \n";
	//after calling function of savefile it store data 
	savefile(name,cnic, pno, planeno, phno,initial, destination, date,ttype, seatno, amount );
}
//function to change the password
void cpass(string &password){
	string opass,newpass;
	cout<<"Enter OLD Password(****):";
	cin>>opass;
	if(opass==password){
		cout<<"Enter New Password: ";
		cin>>newpass;
		password=newpass;
		cout<<"Password change Succcessfully..!!! \n";
	}
	else{
		cout<<"!!!!..Wrong password...!!!!"<<endl;
		cout<<"``````Aceess Denied`````"<<endl;}
		
}
//function to add the destination
void addDestinations() {
    int count;
    cout << "How many destinations do you want to add? ";
    cin >> count;
    for (int i = 0; i < count; i++) {
    	cout<<	"Enter Initail Point Name: ";
    	cin>>spp[dcount];
        cout << "Enter Destination Name: ";
        cin >> dnn[dcount];
        cout << "Enter Distance (in miles): ";
        cin >> ddd[dcount];
        pnum[dcount] = 0; // Initialize plane number to 0
        dcount++;
    }
    cout << "Route added successfully!\n";
}
// function for admin  Menu
void adminMenu() {
    int choice;
    do {
        cout << "\n------------AIRLINE TICKET SYSTEM------------\n";
        cout << "\n========== Admin Panel ==========\n";
        cout << "1. Change Business Class Ticket Price\n";
        cout << "2. Change Economy Class Ticket Price\n";
        cout << "3. Change Business Class Seats\n";
        cout << "4. Change Economy Class Seats\n";
        cout << "5. View Total Bookings\n";
        cout << "6. View Total Profit\n";
        cout << "7. Change Admin Password\n";
        cout << "8. Add Plane for Destination\n";
        cout << "9. Add Destinations and Distances\n";
        cout << "10. Exit Admin Panel\n";
        cout << "Enter your choice: ";
        cin >> choice;

//switch case use to handle the Admin Menu

        switch(choice) {
            case 1:
                cout << "Enter new Business Class ticket price: ";
                cin >> bprice;
                cout << "Updated Business Class price to " << bprice << " PKR.\n";
                break;
            case 2:
                cout << "Enter new Economy Class ticket price: ";
                cin >> eprice;
                cout << "Updated Economy Class price to " << eprice << " PKR.\n";
                break;
            case 3:
                cout << "Enter new number of Business Class seats: ";
                cin >> bseat;
                cout << "Updated Business Class seats to " << bseat << ".\n";
                break;
            case 4:
                cout << "Enter new number of Economy Class seats: ";
                cin >> eseat;
                cout << "Updated Economy Class seats to " << eseat << ".\n";
                break;
       
            case 5:
                cout << "Total Bookings made: " << tbooking << endl;
                break;
            case 6:
                cout << "Total Profit from bookings: " << tprofit << " PKR\n";
                break;
    
            case 7:
                cpass(adminp);			//call the password change function where adminpass send as argument
                break;
            case 8:
                if (dcount == 0) {
                    cout << "No destinations available. Please add destinations first.\n";
                    break;
                }
                cout << "\nAvailable Destinations:\n";
                for (int i = 0; i < dcount; i++) {
                    cout << i+1 << ". " <<spp[i]<<" to "<< dnn[i] << endl;
                }
                int destChoice;
                cout << "Select Destination Number: ";
                cin >> destChoice;
                if(destChoice >=1 && destChoice <=dcount){		//when destchoice enter it -1 to match the index of array for select the destination to plane 
                    cout << "Enter Plane No for route " <<spp[destChoice-1] <<" to "<< dnn[destChoice-1] << ": ";
                    cin >> pnum[destChoice-1];
                    cout << "Plane assigned successfully.\n";
                } else {
                    cout << "Invalid Destination Selection.\n";
                }
                break;
            case 9:
                addDestinations();
                break;
            case 10:
                cout << "Exiting Admin Panel.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 10);
}
void passengerMenu() {
    int choice;
    do {
        cout << "\n------------AIRLINE TICKET SYSTEM------------\n";
        cout << "\n========== Passenger Menu ==========\n";
        cout << "1. Book a Ticket\n";
        cout << "2. Change Passenger Password\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
           
            if (dcount == 0) {
                cout << "No destinations available. Contact Admin.\n";
                return;
            }

            string name, cnic, destination, date, starting,contact;
            int passportNo,  destinationIndex = -1;
            char travelType;
            int distance, finalAmount = 0, seatNo = 0, planeNo = 0;

            cout << "\nAvailable Destinations:\n";
            for (int i = 0; i < dcount; i++) {
                cout << i+1 << ". " << spp[i] << " to "<< dnn[i] << endl;
            }
            cout << "Select Destination Number: ";
            cin >> destinationIndex;
            destinationIndex -= 1;		//dest..index = dest..index - 1 ----for -1 to match the index of arrays

            if (destinationIndex < 0 || destinationIndex >= dcount) {
                cout << "Invalid Destination Selection.\n";
                return;
            }
			starting= spp[destinationIndex];		//the same index saved in the starting
            destination = dnn[destinationIndex];		//the same index saved in the destination
            distance = ddd[destinationIndex];		//the same index saved in the distance
            planeNo = pnum[destinationIndex];		//the same index saved in the PlaneNo

            if (planeNo == 0) {
                cout << "No Plane assigned yet to this destination. Cannot book.\n";
                return;		//return send it back to the Menu
            }

            cout << "Enter Passenger Name: ";
            cin >> name;
            cout << "Enter CNIC No: ";
            cin >> cnic;
            cout << "Enter Date (dd/mm/yyyy): ";
            cin >> date;
            cout << "Enter Passport No (XXXXX): ";
            cin >> passportNo;
            cout<<"Contact NO:";
            cin>>contact;
            cout << "Select Travel Type (B. Business / E. Economy): ";
            cin >> travelType;

            if (travelType == 'b'||travelType == 'B') {
                cout << "Available Business Seats: ";
                for (int i = 0; i < 30; i++) {
                    if (bstatus[i] == 0)
                        cout << (i+1) << " ";
                }
                cout << "\nSelect Seat No: ";
                cin >> seatNo;
                if (seatNo < 1 || seatNo > 30 || bstatus[seatNo-1] == 1) {
                    cout << "Invalid or already booked seat!\n";
                    return;
                }
                bstatus[seatNo-1] = 1;
                bseat--;
                finalAmount = distance * bprice;
            } else if (travelType == 'E'||travelType == 'e') {
                cout << "Available Economy Seats: ";
                for (int i = 0; i < 30; i++) {
                    if (estatus[i] == 0)
                        cout << (i+1) << " ";
                }
                cout << "\nSelect Seat No: ";
                cin >> seatNo;
                if (seatNo < 1 || seatNo > 30 || estatus[seatNo-1] == 1) {
                    cout << "Invalid or already booked seat!\n";
                    return;
                }
                estatus[seatNo-1] = 1;
                eseat--;
                finalAmount = distance * eprice;
            } else {
                cout << "Invalid travel type entered!\n";
                return;
            }

            tprofit += finalAmount;			//total profit = how many booking dones and it automatically saved in global variable
            tbooking++;			//when booking done the incriment added to store the value globally

//function call to display the detail of ticket
            display(name, cnic, passportNo,planeNo,contact, starting,destination,date,travelType, seatNo,finalAmount);

        } 
		else if (choice == 2) {
            cpass(passp);
        } else if (choice == 3) {
            cout << "Returning to Main Menu...\n";
            return;
        } else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);
}
int main() {
    char role;
    do {
        cout << "\n------------AIRLINE TICKET SYSTEM------------\n";
        cout << "\n========== Main Menu ==========\n";
        cout << "A. Admin\n";
        cout << "P. Passenger\n";
        cout << "Q. Quit\n";
        cout << "Enter your role (A/P/Q): ";
        cin >> role;

        if (role == 'A' || role == 'a') {
            string password;
            cout << "Enter Admin Password: ";
            cin >> password;
            if (password == adminp) {
                adminMenu();
            } else {
                cout << "Incorrect password! Access denied.\n";
            }
        } else if (role == 'P' || role == 'p') {
            string password;
            cout << "Enter Passenger Password: ";
            cin >> password;
            if (password == passp) {
                passengerMenu();
            } else {
                cout << "Incorrect password! Access denied.\n";
            }
        } else if (role == 'Q' || role == 'q') {
            cout << "Exiting the system. Thank you!\n";
            break;
        } else {
            cout << "Invalid option, please try again!\n";
        }

    } while (role != 'Q' && role != 'q');

    return 0;
}

