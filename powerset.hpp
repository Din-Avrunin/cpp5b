
#include "set"
#include <math.h>
namespace itertools {
    template<typename T>
    class myPowerSet {
    public:
        const T a;
        const int size = a.length();
        int count = pow(2, size);
        myPowerSet(const T& a)   : a(a) {}
        myPowerSet() 
        {}
        class iterator {
        public:
            decltype(a.begin()) aStartingPosition;
            decltype(a.end()) bStartingPosition;
            int size = 0;
            int length = 0;
            string myStr;
            iterator(const T& a) :
                    aStartingPosition(a.begin()),
                    bStartingPosition(a.end()),
                    size(a.length()),
                    length(pow(2, size)),
                    myStr("") {}
            iterator(const T& a, bool f) :
                    aStartingPosition(a.end())
                   , bStartingPosition(a.end())
                     {}
            iterator()
             {}
            auto operator*() const 
            {
                return myStr;
            }
            iterator& operator++()
             {
                for (int num1 = 0; num1 < length; num1++) {        
                for (int num2; num2 < length; num2++)
                {   
                myStr = "{ ";                      
                 for (int num3; num3 < size; num3++) {         
                     if ((num2 & (1 << num3)) != 0)                         
                    myStr += *aStartingPosition + ", ";
                        }
                    }
                    myStr += " }";
                    ++aStartingPosition;
                    return *this;
                }
            }
                bool operator==(const iterator &it) const {
                    return (aStartingPosition == bStartingPosition);

                }
                bool operator!=(const iterator &it) const {
                    return (aStartingPosition != bStartingPosition);
                }
        };
            iterator begin() const
            {
                return iterator(a);
            }
            iterator end() const {
                return iterator(a, false);
            }
        };
        template<typename T>
        myPowerSet<T> powerset( T a) 
        {
            return myPowerSet<T>(a);
        }
        template<typename T>
        std::ostream &operator<<(std::ostream &os, const set <T> &myStr) 
        {
            os << "{";
            for (auto i : myStr) 
            {
                os << i << ",";
            }
            os << "]";
            return os;
        }
    };



