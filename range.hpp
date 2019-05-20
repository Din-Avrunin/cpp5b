

namespace itertools
{
	using namespace std;
	template <typename T>
	class myRange
	{
		typedef T ptr3;
		public:
		const T a;
		const T b;
		myRange(const T& a, const T& b): a(a), b(b) {}
		public:
		class iterator{
			public: T ptr1;
			iterator(const ptr3 ptr1): ptr1(ptr1){}
			T operator *() const
			{
				return ptr1;
			}
			const iterator &operator++()
			{
				ptr1++;
				return *this;
			}
			
			const iterator operator++(int) 
			{
				iterator temp = *this;
				ptr1++;
				return temp;
			}
			bool operator==(const iterator &it) const
			{
				return ptr1==it.ptr1;
			}
			bool operator !=(const iterator &it) const
			{
				return !(ptr1==it.ptr1);
			}
		};
		public:
		iterator begin() const
		{
			return iterator {a};
		}
		iterator end() const
		{
			return iterator {b};
		}
		int  length() const
		{
			auto startPosition=a;
			auto endPosition=b;
			int count=0;
			while(startPosition!= endPosition)
			{
				count++;
				startPosition++;
			}
			return count;
		}
	};
	template <typename T>
	myRange<T> range (T a,T b)
	{
		return myRange<T> (a,b);
	}
}

			
			
			
		