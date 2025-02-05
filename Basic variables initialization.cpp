/* AUTHOR @Adams
   
   Best Pratices on C++ Basic Language features.
*/
#include<iostream>
#include<cstdint>
int main(){
    //Auto type deduction.
    auto varia{23};

   //list initialization uniform initialization across all types
    int varia1{2};//initialize at the time of creation

   // fixed-width integer types when size
   std::int32_t precise_int{42};

   //constexpr compile time constant
constexpr int max_size{100};

/* EXTRA
const int days_in_week{7}; //for Constant Values.
bool is_valid{false};      // initialize boolen values explicitly
*/

}