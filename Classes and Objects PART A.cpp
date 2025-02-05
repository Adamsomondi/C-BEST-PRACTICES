
#include<iostream>
#include<cstdint>

/* Author @Adams
    PART A:Simple Concepts.

    Best Practices in Classes and Objects.
    With Primitive Type and Basic Functions.
    The office Design-I love the office Series.

   Prequisites:
   Basic variables.
   Basic functions.
   Theory in Class Design,Patterns,Principles.Bottom Up Approach Programming.

*/


class theOffice
{
   public:
   //Constructors

   /*
   Type of Constructors.
   Default constructor-Takes no parameters
                       Created automatically by compiler if no other constructor exists
                       Used when creating objects without specifying initial values
   Parameterized Constructors-Takes parameters to initialize object's attributes
                              Allows customization during object creation
                              Best Practice: Use member initialization lists for better performance
   Copy Constructor-Creates new object as copy of existing object
                    Called when passing objects by value or explicit copying
                    Best Practice: Implement when class manages resources

           
            Constructor initializers/ctor initializers
              - Provides Direct initialization at their creation.
              -Initializing Data Members in the constructor.

   */
 
 
//Default Constructor.
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


/*
Business logic
   You can write what you want to implement about the office Here.
   Dwight is my favourite Character.
   Michael Scott is the boss ever.

 */

 void displayOfficeInfo() const {
        std::cout << "\n--- Office Information ---\n"
                  << "Status: " << (openStatus ? "Open" : "Closed") << "\n"
                  << "Total Employees: " << numEmployees << "\n"
                  << "Monthly Budget: $" << budget << "\n";
                
 }

 private:
/*
Static members.
Belong to the class itself rather than individual objects.
Are shared by all instances of the class
Can be accessed without creating an object instance
*/
    static const int MAX_EMPLOYEES = 50;
    static constexpr double MIN_BUDGET = 10000.0;

    int numEmployees{0};           // Number of employees, default to 0
    double budget{0.0};            // Budget, default to 0.0
    bool openStatus{false};        // Defaults to closed

//private function.
//Private utility function (helper method).

    bool isValidGrade(char grade) const {
        return (grade == 'A' || grade == 'B' || grade == 'C');
    }

};

//Implementation
/*
#include "theOffice.h"
 Introduced in PART B
*/

int main()
{

    theOffice DunderMifflin;
    DunderMifflin.displayOfficeInfo();

    theOffice MichaelScottPaperCo(25, 75000.0);
    MichaelScottPaperCo.displayOfficeInfo();
    return 0;

    //Demonstration of Setters
    MichaelScottPaperCo.setnumEmployees(60); // Should show error message
    MichaelScottPaperCo.setbudget(5000.0); // Should show error message
  

}