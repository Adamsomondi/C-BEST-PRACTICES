/* 
Author @Adams

PART B TOPICS:Objects on the Heap.
             Memory Management Basics.
            
    SKIP ----TO----MAIN FUNCTION() TO SEE.

Prequisites
Basic Variables
Basic Functions
Classes and Objects Part A.

NOTE:We are still learning with  classes with Primitive types.
*/
#include<iostream>
#include<cstdint>
#include<memory>
class theOffice
{
    public:
    theOffice() : numEmployees(0), budget(0.0),  openStatus(false) {
        std::cout << "New office created with default values\n";
    }


//Parameterized Constructors.
   theOffice(int employees, double mbudget) 
        : numEmployees(0), budget(0.0), openStatus(false) 

        {

        /* Use setter methods to ensure validation
         If setNumEmployees() and setBudget() are declared after the constructor,
         the compiler will say "not declared in this scope" 
         because it hasn't seen them yet.
         But it will.
         */

        setnumEmployees(employees);
        setbudget(mbudget);
        openStatus = true;
        
    }

/*
Getters and Setters-Encapsulation and Data Integrity.
 Always define setter/getter functions
 before using them inside the constructor.
 Since getters and setters are usually simple, 
 writing them inside the class (interface) is the preferred modern C++ practice.
*/

// Setter methods with validation (Encapsulation)
    void setnumEmployees(int employees) {
        if (employees >= 0 && employees <= MAX_EMPLOYEES) {
            numEmployees = employees;

        } else {
            std::cout << "Invalid employee count. Must be between 0 and " 
                      << MAX_EMPLOYEES << "\n";
        }
    }

    void setbudget(double mbudget) {
        if (budget >= MIN_BUDGET) {
            mbudget = budget;
        } else {
            std::cout << "Budget must be at least $" << MIN_BUDGET << "\n";
        }
    }

    void setOpenStatus(bool status) {
        openStatus = status;
    }

 //Getter Methods.
    int getNumEmployees() const {
        return numEmployees;
    }

    double getBudget() const {
        return budget;
    }

    bool isOpen() const {
        return openStatus;
    }


void displayOfficeInfo() const {
        std::cout << "\n--- Office Information ---\n"
                  << "Status: " << (openStatus ? "Open" : "Closed") << "\n"
                  << "Total Employees: " << numEmployees << "\n"
                  << "Monthly Budget: $" << budget << "\n";
}

    private:
    static const int MAX_EMPLOYEES = 50;
    static constexpr double MIN_BUDGET = 10000.0;

    int numEmployees{0};           // Number of employees, default to 0
    double budget{0.0};            // Budget, default to 0.0
    bool openStatus{false};        // Defaults to closed

};

int main(){
    // Constructors on the FreeStore/HEAP
/*
theOffice* Vancerefrigeration{ new theOffice{ } };//Avoid Raw Pointers
*/

//SAFER
theOffice* VanceFrigeration { nullptr };//calling Default Constructor
VanceFrigeration = new theOffice {};
VanceFrigeration->displayOfficeInfo();

// … do something with the offices
delete VanceFrigeration;     


theOffice* DwightPaper{ nullptr };
DwightPaper =new theOffice { 15,200};
DwightPaper->displayOfficeInfo();

delete DwightPaper;

/*
//USE SMART POINTER
auto Vancefrigeration{make_unique<theOffice>( )}
//or
auto Vancefrigeration = std::make_unique<theOffice>(); 
*/
}