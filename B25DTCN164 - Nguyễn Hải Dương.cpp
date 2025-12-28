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
    Employee(int id = 0, string name = "", float salary = 0) 
        : id(id), name(name), salary(salary) {}
    
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setSalary(float salary) { this->salary = salary; }
    
    int getId() { return id; }
    string getName() { return name; }
    float getSalary() { return salary; }
    
    void display() {
        cout << "ID: " << id << " - Ten: " << name << " - Luong: " << salary << endl;
    }
};

class EmployeeManager {
private:
    vector<Employee> employees;
    int currentId;

public:
    EmployeeManager() : currentId(3001) {}
    
    void create() {
        string name;
        float salary;
        
        cout << "Nhap ten nhan vien: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap luong: ";
        cin >> salary;
        
        Employee e(currentId++, name, salary);
        employees.push_back(e);
        cout << "Da them nhan vien thanh cong!\n";
    }
    
    void read() {
        if (employees.empty()) {
            cout << "Danh sach trong!\n";
            return;
        }
        cout << "\nDanh sach nhan vien:\n";
        for (int i = 0; i < employees.size(); i++) {
            employees[i].display();
        }
    }
    
    void update() {
        int id;
        cout << "Nhap ID can cap nhat: ";
        cin >> id;
        
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].getId() == id) {
                float newSalary;
                cout << "Nhap luong moi: ";
                cin >> newSalary;
                employees[i].setSalary(newSalary);
                cout << "Da cap nhat luong!\n";
                return;
            }
        }
        cout << "Khong tim thay ID!\n";
    }
    
    void remove() {
        int id;
        cout << "Nhap ID can xoa: ";
        cin >> id;
        
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].getId() == id) {
                employees.erase(employees.begin() + i);
                cout << "Da xoa nhan vien!\n";
                return;
            }
        }
        cout << "Khong tim thay ID!\n";
    }
    
    void run() {
        int choice;
        do {
            cout << "\n===== QUAN LY NHAN VIEN =====\n";
            cout << "1. Them moi\n";
            cout << "2. Xem danh sach\n";
            cout << "3. Sua luong\n";
            cout << "4. Xoa\n";
            cout << "5. Thoat\n";
            cout << "==============================\n";
            cout << "Lua chon: ";
            cin >> choice;
            
            switch (choice) {
                case 1: create(); break;
                case 2: read(); break;
                case 3: update(); break;
                case 4: remove(); break;
                case 5: cout << "Ket thuc chuong trinh!\n"; break;
                default: cout << "Lua chon sai!\n";
            }
        } while (choice != 5);
    }
};

int main() {
    EmployeeManager mgr;
    mgr.run();
    return 0;
}
