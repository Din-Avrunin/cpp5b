namespace itertools
{
	template <typename T, typename Z>
	class myChain
	{
		public:
		const T a;
		const Z b;
		myChain (const T& a,const Z& b):a(a),b(b){}
		myChain(){}
		class iterator
		{
			public:
			decltype (a.begin())  startingPosition;
			decltype (a.end())  endPosition;
			decltype (b.begin()) b_startPosition;
			decltype (b.end())  b_endPointer;
			iterator (const T& a,const Z& b): startingPosition(a.begin())
			,endPosition(a.end())
			,b_startPosition(b.begin())
			,b_endPointer(b.end()){}
			iterator (const T& a, const Z& b,int i): startingPosition (a.end())
			,endPosition(a.end()),
			b_startPosition(b.end())
			,b_endPointer(b.end()){}
			iterator(){}
			auto operator*() const
			{
				if (startingPosition != endPosition)
					return *startingPosition;
				else
					return *b_startPosition;
			}
			iterator& operator++() {
				if (startingPosition != endPosition)
					++startingPosition;
				else if (b_startPosition!= b_endPointer)
					++b_startPosition;
				return *this;
			}
			bool operator==(const iterator &it) const 
			{
		return (startingPosition == it.startingPosition || b_startPosition != it.b_startPosition);
			}
            bool operator!=(const iterator& it) const 
            {
                return (startingPosition!=it.startingPosition||b_startPosition!=it.b_startPosition);
            }
		};
		iterator begin() const
		{
			return iterator {a,b};
		}
		iterator end()const{
			return iterator { a,b,0};
		}
		
		int length() const 
		{
			auto itStartA = a.begin();
			auto itEndA = a.end();
			auto itStartB = b.begin();
			auto itEndB = b.end();
			int counter = 0;
			
			while (itStartA != itEndA)
			{
				counter++;
				itStartA++;
			}
			while (itStartB != itEndB)
			{
				counter++;
				itStartB++;
			}
			return counter;
		}
	};template <typename T, typename Z>
	myChain <T,Z> chain (T a,Z b)
	{
		return myChain<T,Z>(a,b);
	}
}
