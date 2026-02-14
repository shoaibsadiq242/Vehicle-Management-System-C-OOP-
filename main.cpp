#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    int vehicleID;
    string name;
    string type;
    string status; // Available, Rented, Sold
    float price;

public:
    Vehicle() {
        vehicleID = 0;
        name = "";
        type = "";
        status = "Available";
        price = 0;
    }

    void setID(int id) {
        vehicleID = id;
    }

    int getID() {
        return vehicleID;
    }

    void inputDetails() {
        cin.ignore(); // flush newline
        cout << "Enter Vehicle Name: ";
        getline(cin, name);
        cout << "Enter Vehicle Type (Car/Bike/Truck): ";
        getline(cin, type);
        cout << "Enter Vehicle Price: ";
        cin >> price;
        status = "Available"; // default
    }

    void editDetails() {
        cin.ignore();
        cout << "Enter Vehicle Name: ";
        getline(cin, name);
        cout << "Enter Vehicle Type: ";
        getline(cin, type);
        cout << "Enter Vehicle Price: ";
        cin >> price;
    }

    void changeStatus(string newStatus) {
        status = newStatus;
    }

    void displayVehicle() {
        cout << "\n---------------------------\n";
        cout << "Vehicle ID   : " << vehicleID << endl;
        cout << "Name         : " << name << endl;
        cout << "Type         : " << type << endl;
        cout << "Price        : " << price << endl;
        cout << "Status       : " << status << endl;
        cout << "---------------------------\n";
    }
};

int main() {
    int capacity = 2;
    Vehicle* vehicles = new Vehicle[capacity];
    int count = 0;
    int choice;

    cout << "===== VEHICLE MANAGEMENT SYSTEM =====\n";

    while (true) {
        cout << "\n========= MENU =========\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search Vehicle by ID\n";
        cout << "4. Edit Vehicle\n";
        cout << "5. Change Vehicle Status\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "\nExiting program. Goodbye!\n";
            break;
        }

        else if (choice == 1) {
            int newID;
            cout << "\nEnter Vehicle ID: ";
            cin >> newID;

            // Check for unique ID
            bool idExists = false;
            for (int i = 0; i < count; i++) {
                if (vehicles[i].getID() == newID) {
                    cout << "\nVehicle ID already exists! Try again with a different ID.\n";
                    idExists = true;
                    break;
                }
            }
            if (idExists) continue;

            // Resize array if needed
            if (count >= capacity) {
                int newCapacity = capacity * 2;
                Vehicle* temp = new Vehicle[newCapacity];
                for (int i = 0; i < count; i++) {
                    temp[i] = vehicles[i];
                }
                delete[] vehicles;
                vehicles = temp;
                capacity = newCapacity;
                cout << "\nVehicle storage expanded to " << capacity << " slots.\n";
            }

            Vehicle newVehicle;
            newVehicle.setID(newID);
            newVehicle.inputDetails();
            vehicles[count] = newVehicle;
            count++;
            cout << "\nVehicle added successfully!\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "\nNo vehicles available.\n";
            }
            else {
                for (int i = 0; i < count; i++) {
                    vehicles[i].displayVehicle();
                }
            }
        }

        else if (choice == 3) {
            if (count == 0) {
                cout << "\nNo vehicles available.\n";
            }
            else {
                int id;
                cout << "\nEnter Vehicle ID to search: ";
                cin >> id;
                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (vehicles[i].getID() == id) {
                        cout << "\nVehicle Found!\n";
                        vehicles[i].displayVehicle();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\nVehicle not found.\n";
            }
        }

        else if (choice == 4) {
            if (count == 0) {
                cout << "\nNo vehicles available.\n";
            }
            else {
                int id;
                cout << "\nEnter Vehicle ID to edit: ";
                cin >> id;
                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (vehicles[i].getID() == id) {
                        cout << "\nEditing Vehicle ID " << id << ":\n";
                        vehicles[i].editDetails();
                        cout << "\nVehicle details updated successfully!\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\nVehicle not found.\n";
            }
        }

        else if (choice == 5) {
            if (count == 0) {
                cout << "\nNo vehicles available.\n";
            }
            else {
                int id;
                cout << "\nEnter Vehicle ID to change status: ";
                cin >> id;
                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (vehicles[i].getID() == id) {
                        cout << "\nEnter new status (Available/Rented/Sold): ";
                        string newStatus;
                        cin >> newStatus;
                        vehicles[i].changeStatus(newStatus);
                        cout << "\nVehicle status updated successfully!\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\nVehicle not found.\n";
            }
        }

        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }

    delete[] vehicles;
    return 0;
}
