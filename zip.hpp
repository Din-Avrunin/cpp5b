
namespace itertools {
    template <typename T, typename T2>
    class myZip {

    public:
        const T a ;
        const T2 b;
        myZip(const T& a ,const T2& b):a(a),b(b){}
        myZip()    {}
    

        class iterator {
        public:

            decltype(a.begin()) aStartingPosition;
            decltype(a.end()) aEndingPosition;
            decltype(b.begin()) bStartingPosition;
            decltype(b.end()) bEndingPosition;
            iterator(const T& a,const  T2& b)
                    :aStartingPosition (a.begin()),
                     aEndingPosition(a.end()),
                     bStartingPosition (b.begin()),
                     bEndingPosition(b.end())   {}
         
            iterator(const T& a,const T2 & b,int i)
                    :aStartingPosition(a.end()),
                     aEndingPosition(a.end()),
                     bStartingPosition(b.end()),
                     bEndingPosition(b.end()){}
            
            iterator()     {}
       
            auto operator*() const {
                return std :: make_pair(*aStartingPosition, *bStartingPosition);
            }
            iterator& operator++() {
                if(aStartingPosition!=aEndingPosition)
                    ++aStartingPosition;
                ++bStartingPosition;
                return *this;
            }
            bool operator==(const iterator &it) const {
                return (aStartingPosition == it.aStartingPosition && bStartingPosition == it.bStartingPosition);
            }
            bool operator!=(const iterator& it) const {
                return (aStartingPosition != it.aStartingPosition && bStartingPosition != it.bStartingPosition);
            }
        };

        //end of class iterator

        iterator begin() const{
            return iterator{ a,b };
        }
        iterator end() const {
            return iterator{ a,b , 1};

        }

        int  length(){
            return  a.length() + b.length();
        }


    };

    template<typename T, typename T2>
    myZip<T, T2> zip(T a, T2 b) {        return myZip<T,T2>(a, b); }
    template<typename T, typename T2>
    std :: ostream& operator<<(std :: ostream &os, const std :: pair<T, T2>& pair) {
        os<<pair.first<<","<<pair.second;
        return os;
    }
}

