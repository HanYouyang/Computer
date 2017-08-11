template <class T>
class CArray3D
{
public:
	template <class T1>
	class CArray2D
	{
	public:
		template <class T2>
		class CArray1D
		{
		public:
			CArray1D() { a = NULL; }
			void set(int l) { a = new T[l]; }
			T2 & operator [] (int index) { return a[index]; }
		private:
			T2 *a;
		};
		CArray2D() { a1 = NULL; }
		void set(int c, int l)
		{
			a1 = new CArray1D<T1>[c];
			for (int i = 0; i<c; i++)
				a1[i].set(l);
		}
		CArray1D<T1> & operator [] (int index) { return a1[index]; }
	private:
		CArray1D<T1> * a1;
	};
	CArray3D() { a2 = NULL; }
	CArray3D(int r, int c, int l)
	{
		a2 = new CArray2D<T>[r];
		for (int i = 0; i<r; i++)
			a2[i].set(c, l);
	}
	CArray2D<T> & operator [] (int index) { return a2[index]; }
private:
	CArray2D<T> * a2;
};