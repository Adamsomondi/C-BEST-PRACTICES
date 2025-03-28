/* 
@Author Adams
          Topics:Standard Template Library(Vectors).
                Memory Management-std::allocators under the hood for vectors.
***Practice to write custom Allocators...
                 Iterators(Legacy and Modern).
                 More About Data Members-Static data Members.
                 More About Member Function-Static member functions.
        Notes on    CONST functions
                You can call const and non-const member functions on a non-const object. 
                However, you can only call const member functions on a const object 
                    PRIVATE HELPER MEMBER FUNCTIONS
                Can only  be called by another Functions that is member of its class
            
                Iterators in C++-Input legacy Iterator.
                                 -Output Legacy Iterator.
                                 -Foward Iterators.
                                 -Bidirectional Iterator.
                                 std::begin(value),std::end(value)
***Practice on how to write custom Iterators...
Prequisites:
Basic variables.
Basic Functions.
Classes and Objects PART A,B,C,D.
*/

#include<vector>
#include<iostream>
#include<memory>
class theOffice{
  public:

/*Previously, numEmployees and budget were scalar values (int and double),
so initializing them to 0 made sense.
Now that they are std::vector<int> and std::vector<double>
they start empty by default.
 */

theOffice() : openStatus(false){
     ++officeCount;
std::cout << "New office created with default values\n";
}
//parameterized Constructors.
//Pass by Reference.

theOffice( const std::vector<int>& employees, const std::vector<double>& Mbudget):
numEmployees(employees), budget(Mbudget), openStatus(true) {
       setNumEmployees(employees);//validation
        setBudget(Mbudget);//validation
        openStatus = true;
         ++officeCount;
        std::cout << "Office initialized with provided employees and budgets.\n";
    }

// Setter methods
    void setNumEmployees(const std::vector<int>& employees) {
        numEmployees = employees;
    }

    void setBudget(const std::vector<double>& Mbudgets) {
        budget = Mbudgets;
    }

    void setOpenStatus(bool status) {
        openStatus = status;
    }

    // Getter methods
    std::vector<int> getNumEmployees() const {
        return numEmployees;
    }

    std::vector<double> getBudget() const {
        return budget;
    }

    bool isOpen() const {
        return openStatus;
    }

 // Static member function to get the count of offices
    static int getOfficeCount() {
        return officeCount;
    }

    // Copy constructor
    theOffice(const theOffice &other) 
        : numEmployees(other.numEmployees), budget(other.budget), openStatus(other.openStatus) {
            ++officeCount;
        std::cout << "Copy constructor called.\n";
    }

    // Display method
   void displayOfficeInfo() const {
        std::cout << "\n--- Office Information ---\n"
                  << "Status: " << (openStatus ? "Open" : "Closed") << "\n";

        for (size_t i = 0; i < numEmployees.size(); ++i) {
            std::cout << "Department " << i + 1 << " - Employees: " << numEmployees[i]
                      << ", Budget: $" << budget[i] << "\n";
        }
    }

    /* Display method with range-based for loop-MODERN METHODS.
void displayOfficeInfo() const {
    std::cout << "\n--- Office Information ---\n"
              << "Status: " << (openStatus ? "Open" : "Closed") << "\n";

    int departmentNumber = 1;
    for (const auto& [employees, budget] : std::ranges::views::zip(numEmployees, budget)) {
        std::cout << "Department " << departmentNumber++ << " - Employees: " << employees
                  << ", Budget: $" << budget << "\n";
    }
}
*/
private:
/* 
Declaring a vector

std::vector<int> vec;
Initializing a Vector.
std::vector<int>	vec ={1,2,3,4,5};
or
std::vector<int>vec1;
 for	(int	i=	0;	i<5;	++i)	{	vec1.push_back(i);	}
or
 std::vector<int>	vec2(5,	10);//5 elements with tens
or 
std::vector<int> vec(10);//fills it with 10 zeros
or
std::vector<int> vec5(5);//Using Std::generate with Lambdas
int	value	=	0;

std::generate(vec5.begin(),	vec5.end(),
 [&value]()	{	return	value++;	});
 or
 	3,	4,	5};
 std::vector<int>	vec2(vec1);//copy inialization
*/

std::vector<int> numEmployees; //Automatically to 0
std::vector<double> budget; //Automatically to 0
bool openStatus;
static int officeCount;
};


int theOffice::officeCount = 0;//Static always initialized to zero explicitly



int main(){
 //Creating a default office.

    std::cout << "\n=== Creating Vance Refrigeration (Default Constructor) ===\n";
    auto VanceRefrigeration = std::make_unique<theOffice>();
    VanceRefrigeration->displayOfficeInfo();


//Calling the Parameterized Constructor
 std::cout << "\n=== Creating Dunder Mifflin Scranton (Parameterized Constructor) ===\n";
    std::vector<int> scranton_employees = {15, 30, 25, 10}; // Sales, Warehouse, Accounting, Management
    std::vector<double> scranton_budgets = {75000.0, 120000.0, 95000.0, 150000.0};
    auto DunderMifflin = std::make_unique<theOffice>(scranton_employees, scranton_budgets);//dunder mifflin is the Object
    DunderMifflin->displayOfficeInfo();

//reverse iterator
std::cout << "reverse iteration over DunderMifflin budgets: ";
for (auto it = scranton_employees.rbegin(); it != scranton_employees.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

//Random Acces Iterator
//you can do this with the at()method
 // Using iterator arithmetic to access the third element.
    auto it = scranton_budgets.begin();
    it += 2; // Advances the iterator to the third element.
    std::cout << "Using iterator arithmetic to do random access: " << *it << "\n";

//Using copy constructor to create a competing branch
    std::cout << "\n=== Creating Stamford Branch (Copy Constructor) ===\n";//stamford is the object
    theOffice StamfordBranch = *DunderMifflin;  // Copy constructor called
    

// Modifying the Stamford branch data the getters and setters.
    std::vector<int> stamford_employees = {20, 35, 28, 12};  // Different employee counts
    std::vector<double> stamford_budgets = {80000.0, 130000.0, 98000.0, 160000.0};
    StamfordBranch.setNumEmployees(stamford_employees);
    StamfordBranch.setBudget(stamford_budgets);
    StamfordBranch.displayOfficeInfo();

//Bidirectional Iterator
std::cout << "Backward iteration over Stamford budgets: ";
    // Note: budgets.end() points past the last element, so we decrement it first.
    for (auto it =stamford_budgets.end(); it != stamford_budgets.begin(); ) {
        --it;  // Move iterator to the previous element.
        std::cout << *it << " "<<std::endl;
    }
/*
ILLUSTRATING VECTOR OPERATION WITH VANCE REFRIGERATION
*/

//Expanding Vance Refrigeration
 std::cout << "\n=== Expanding Vance Refrigeration ===\n";
    std::vector<int> vance_employees = {8};  
    std::vector<double> vance_budget = {50000.0};
    VanceRefrigeration->setNumEmployees(vance_employees);
    VanceRefrigeration->setBudget(vance_budget);
    VanceRefrigeration->setOpenStatus(true);
    VanceRefrigeration->displayOfficeInfo();

 //Adding a new department to Vance Refrigeration
    std::cout << "\n=== Adding New Department to Vance Refrigeration ===\n";
    std::vector<int> updated_vance_employees = VanceRefrigeration->getNumEmployees();
    std::vector<double> updated_vance_budget = VanceRefrigeration->getBudget();
    
    updated_vance_employees.push_back(12);  // Add new department with 12 employees
    updated_vance_budget.push_back(65000.0);  // Add budget for new department

    // Vector member functions demonstrations
std::cout << "Number of departments: " << updated_vance_employees.size() << "\n";
std::cout << "First department employees: " << updated_vance_employees.front() << "\n";
std::cout << "Last department employees: " << updated_vance_employees.back() << "\n";

    // Accessing elements using at() (with bounds checking)
//Exception handling while accessing an array out of bonds.
try {
    std::cout << "Second department employees: " << updated_vance_employees.at(1) << "\n";
} catch (const std::out_of_range& e) {
    std::cout << "Department index out of range!\n";
}

if (!updated_vance_employees.empty()) {
    std::cout << "Vance Refrigeration has departments\n";
}

// Remove last department (pop_back)
if (!updated_vance_employees.empty()) {
    updated_vance_employees.pop_back();
    updated_vance_budget.pop_back();
}

/*
OTHER OPERATIONS ON VECTORS PRACTICE.
std::Erase() And Std::Erase if();//std::remove,std::remove if().
Capacity().
Clear().
resize().
Reserve().
shrink_to_fit()
Emplace_back().
*/
//Iterators
//input iterator
/*
	cbegin()	and	cend() for constant iterator
*/
 for(auto it = updated_vance_employees.begin();it	!=	updated_vance_employees.end();
 ++it)	{
 std::cout	<< "The employees are:  "<<	*it	<<	"	"<<std::endl;
 }

    VanceRefrigeration->setNumEmployees(updated_vance_employees);
    VanceRefrigeration->setBudget(updated_vance_budget);
    VanceRefrigeration->displayOfficeInfo();

/*output iterator
Example
  int	main()	{
 std::vector<int>	numbers;
 std::generate_n(std::back_inserter(numbers),	10,
 [n	=	0]()	mutable	{	return	++n;	});
 for	(auto	num	:	numbers)	{	std::cout	<<	num	<<	"	";	}
 std::cout	<<	"\n";
 return	0;
 }
 Notes:
 It allow you to push values in the basck of a vector.
 Do not use it to read.
/*
/*
Forward Iterator
Combine the capability Of both Input and Output Iterator.
Example
 int	main()	{
 std::forward_list<int>	flist	=	{10,	20,	30,	40,	50};
 std::cout	<<	"Original	list:	";
 for	(auto	it	=	flist.begin();	it	!=	flist.end();	++it)	{
 std::cout	<<	*it	<<	"	";
 }
 std::cout	<<	"\n";
 for	(auto	it	=	flist.begin();	it	!=	flist.end();	++it)	{
 (*it)++;
 }
 std::cout	<<	"Modified	list:	";
 for	(auto	it	=	flist.begin();	it	!=	flist.end();	++it)	{
 std::cout	<<	*it	<<	"	";
 }
 std::cout	<<	"\n";
 return	0;
 }
*/

//Display the total number of office objects created.
std::cout << "\nTotal offices created so far: " << theOffice::getOfficeCount() << "\n";

    return 0;

}