namespace itertools
{
	template <typename T, typename T2>
	class myProduct
	{
		public:
		const T a;
		const T2 b;
		myProduct(T a,T2 b): a(a),b(b){}
		myProduct()
		{
		}
		class iterator
		{
			public:
			decltype (a.begin())  aStartingPosition;
			decltype (a.end()) aEndingPosition;
			decltype (b.begin()) bStartingPosition;
			decltype (b.end()) bEndingPosition;
			decltype (b.begin()) saveFirst;
			iterator (const T& a, const T2& b): aStartingPosition(a.begin())
			,saveFirst (b.begin())
			,aEndingPosition (a.end())
			,bStartingPosition(b.begin()),
			bEndingPosition(b.end()){}
			iterator (const T& a,const T2& b,int i): aStartingPosition(a.end())
			,aEndingPosition(a.end()),
			bStartingPosition(b.end())
			,bEndingPosition(b.end()) {}
			iterator(){}
			auto operator*() const
			{
				return std::make_pair(*aStartingPosition, *bStartingPosition);
			}
			iterator& operator++()
			{
				if (aStartingPosition!=aEndingPosition)
				{
					++bStartingPosition;
				}
				if (bStartingPosition==bEndingPosition)
				{
					bStartingPosition=saveFirst;
					++aStartingPosition;
			}
				return *this;
			}
			bool operator==(const iterator &it) const
			{
				return (aStartingPosition==it.aStartingPosition && bStartingPosition==it.bStartingPosition);
			}
			bool operator  !=(const iterator& it) const
			{
				return (aStartingPosition!=it.aStartingPosition && bStartingPosition!=it.bStartingPosition);
			}
		};
		iterator begin() const
		{
			return iterator{a,b};
		}
		iterator end() const
		{
			return iterator {a,b,10000};
		}
		int length()
		{
			return a.length()+b.length();
		}
	};
	template <typename T,typename T2>
	myProduct<T,T2> product(T a,T2 b)
	{
		return myProduct<T,T2>(a,b);
	}
}