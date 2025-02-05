/* AUTHOR @Adams
   
   Best Practices on C++ reference type Language features
   1.2 Functions with Primitive types Only.

  Prequisites:
  Basic variables.

   
*/

#include<iostream>
#include<cstdint>

/*
Function Syntax
DataType Functionname(arguments){
  Statements;
    return expression; //when it returns a value
     }

*/

//Pass-by-value and Return by Value: the function receives a copy of the argument.
int add(int a, int b) {
    return a + b; // returns a copy of the result and only the copy can be modified.
}

//Use constexpr to evaluate at runtime
constexpr int square(int x) {
    return x * x;
}


//Use noexcept When Appropriate
int multiply(int a, int b) noexcept {
    return a * b;
}


/*
NOTE:
    For primitive types that are small i recommend pass by Value.
    Deploy Default Arguments when you know it.
    Pass by Reference is discussed with the reference types
*/

int main(){

    //Auto type deduction.
    auto varia{23};

   //list initialization uniform initialization across all types
    int varia1{2};//initialize at the time of creation

   // fixed-width integer types when size
   std::int32_t precise_int{42};

   //constexpr compile time constant
constexpr int msize{100};

/* EXTRA
const int days_in_week{7}; //for Constant Values.
bool is_valid{false};      // initialize boolen values explicitly
*/



//Function Call 
//calculate the sum of varia and varia1 variables
std::cout<<"the sum is"<<(varia,varia1)<<std::endl;

/*  
Return by value returns a new value
we can only work with new value not the original data.
*/

//Function call
//Multiply the values of varia and varia1 variables

std::cout<<"the multiplication is"<<(varia,varia1)<<std::endl;

// Use in a compile-time context:
//Calculate the square of msize
constexpr int result = square(msize); // evaluated at compile time.

};