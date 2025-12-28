#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    Employee() : id(0), name(""), salary(0) {}
    
    Employee(int id, string name, float salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }
    
    void input() {
        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap luong: ";
        cin >> salary;
    }
    
    void printInfo() {
        cout << "ID: " << id << " - Ten: " << name << " - Luong: " << salary << endl;
    }
    
    int getId() {
        return id;
    }
    
    void setSalary(float salary) {
        this->salary = salary;
    }
};

class EmployeeManager {
private:
    vector<Employee> list;
    int nextId;

public:
    EmployeeManager() {
        nextId = 3001;
    }
    
    void addEmployee() {
        Employee emp(nextId, "", 0);
        emp.input();
        list.push_back(emp);
        nextId++;
        cout << "Them nhan vien thanh cong!" << endl;
    }
    
    void showAll() {
        if (list.empty()) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        for (int i = 0; i < list.size(); i++) {
            list[i].printInfo();
        }
    }
    
    void updateSalaryById() {
        int id;
        cout << "Nhap ma nhan vien: ";
        cin >> id;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                float newSalary;
                cout << "Nhap luong moi: ";
                cin >> newSalary;
                list[i].setSalary(newSalary);
                cout << "Cap nhat thanh cong!" << endl;
                return;
            }
        }
        cout << "Khong tim thay nhan vien!" << endl;
    }
    
    void deleteById() {
        int id;
        cout << "Nhap ma nhan vien: ";
        cin >> id;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                list.erase(list.begin() + i);
                cout << "Xoa thanh cong!" << endl;
                return;
            }
        }
        cout << "Khong tim thay nhan vien!" << endl;
    }
    
    void menu() {
        int choice;
        do {
            cout << "\n----- MENU -----" << endl;
            cout << "1. Them nhan vien" << endl;
            cout << "2. Hien thi danh sach" << endl;
            cout << "3. Cap nhat luong" << endl;
            cout << "4. Xoa nhan vien" << endl;
            cout << "5. Thoat" << endl;
            cout << "----------------" << endl;
            cout << "Chon: ";
            cin >> choice;
            
            if (choice == 1) {
                addEmployee();
            } else if (choice == 2) {
                showAll();
            } else if (choice == 3) {
                updateSalaryById();
            } else if (choice == 4) {
                deleteById();
            } else if (choice == 5) {
                cout << "Tam biet!" << endl;
            } else {
                cout << "Lua chon khong hop le!" << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    EmployeeManager manager;
    manager.menu();
    return 0;
}