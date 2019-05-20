#include <iostream>

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"


using namespace std;
using namespace itertools;

template<typename Iterable>
string iterable_to_string( Iterable& iterable) {
    ostringstream ostr;
    for (decltype(*iterable.begin()) i: iterable)
        ostr << i << ",";
    return ostr.str();
}
int main() {

    badkan::TestCase testcase;
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {


/*
testing the range class
*/

        myRange<int> intRange(5, 8);
        myRange<int> intRange2(-6,-2);
        myRange<double> doubleRange(5.3,6.3);
        myRange<double> doubleRange2(12.2,15.2);
        myRange<char> charRange('g','l');
        myRange<char> charRange2('a','c');
        myRange<char> charRange3('e','i');

        auto startingPosition = intRange.begin();
        auto endingPosition = intRange.end();

        /*
testing the chain class
*/
        myChain<myRange<int>,myRange<int>> chain1(intRange,intRange2);
        myChain<myRange<char>,string> chain4(charRange,"abcd");
        myChain<string,myRange<char>> chain5("efgh",charRange2);
   /*
testing the zip class
*/
        myZip<myRange<int>,string> zip1(intRange,"cpp5");
        myZip<myRange<double>,string> zip2(doubleRange,"efg");
        myZip<myRange<char>,string> zip3(charRange,"hij");
        myZip<myZip<myRange<int>,string>,myZip<myRange<double>,string>> zipOfZip(zip1,zip2);
 /*
testing the product class
*/
        myProduct<myRange<int>,string> proudct1(intRange,"efg");
        myProduct<myRange<double>,string> proudct2(doubleRange,"hij");
        myProduct<string,string> proudct3("efg","hij");
     /*
testing the powerset class
*/
         myPowerSet<myRange<int>> powerSet1(intRange);
         myPowerSet<myRange<char>> powerSet2(charRange3);
        

        testcase.setname("TESTING RANGE")
                .CHECK_OUTPUT(iterable_to_string(intRange), "5,6,7,")
                .CHECK_OUTPUT(iterable_to_string(intRange2),"-6,-5,-4,-3,")
                .CHECK_OUTPUT (iterable_to_string(doubleRange),"5.3,")
                .CHECK_OUTPUT (iterable_to_string(doubleRange2),"12.2,13.2,14.2,")
                .CHECK_OUTPUT (iterable_to_string(charRange),"g,h,i,j,k,")
                .CHECK_OUTPUT (iterable_to_string(charRange2),"a,b,")
                .CHECK_OUTPUT (iterable_to_string(charRange3),"e,f,g,h,")
                .CHECK_EQUAL (startingPosition != endingPosition, true );

        testcase.setname("TESTING CHAIN")
                .CHECK_OUTPUT (iterable_to_string(chain1),"5,6,7,-6,-5,-4,-3,")
                .CHECK_OUTPUT (iterable_to_string(chain4),"g,h,i,j,k,a,b,c,d,")
                .CHECK_OUTPUT (iterable_to_string(chain5),"e,f,g,h,a,b,");

        testcase.setname("TESTING ZIP")
                .CHECK_OUTPUT (iterable_to_string(zip1),"5,c,6,p,7,p,")
                .CHECK_OUTPUT (iterable_to_string(zip2),"5.3,e,")
                .CHECK_OUTPUT (iterable_to_string(zip3),"g,h,h,i,i,j,")
                .CHECK_OUTPUT (iterable_to_string(zipOfZip),"5,c,5.3,e,");

        testcase.setname("TESTING PRODUCT")
                .CHECK_OUTPUT (iterable_to_string(proudct1),"5,e,5,f,5,g,6,e,6,f,6,g,7,e,7,f,7,g,")
                .CHECK_OUTPUT (iterable_to_string(proudct2),"5.3,h,5.3,i,5.3,j,")
                .CHECK_OUTPUT (iterable_to_string(proudct3),"e,h,e,i,e,j,f,h,f,i,f,j,g,h,g,i,g,j,");

        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: " << grade << endl;
    return 0;
}