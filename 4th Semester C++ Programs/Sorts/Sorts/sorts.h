
enum order
{
	ascending,
	descending
};

template <class T> void SelectionSort(T *_array, int n, order o = ascending)
{
	if(o == ascending)
	{
		for(int i = 0; i < n-1; i++)
		{
			int k = i;
			for(int j = i+1; j < n; j++)
			{
				if(_array[j] < _array[k])
					k = j;
			}

			T t = _array[i];
			_array[i] = _array[k];
			_array[k] = t;
		}
	}
	else
	{
		for(int i = 0; i < n-1; i++)
		{
			int k = i;
			for(int j = i+1; j < n; j++)
			{
				if(_array[j] > _array[k])
					k = j;
			}

			T t = _array[i];
			_array[i] = _array[k];
			_array[k] = t;
		}
	}
}

template <class T> void BubbleSort(T *_array, int n, order o = ascending)
{
	if(o = ascending)
	{
		for(int i = 0; i < n-1; i++)
		{
			bool isSorted = true;
			for(int j = 0; j < n-i-1; j++)
			{
				if(_array[j] > _array[j+1])
				{
					T t = _array[j];
					_array[j] = _array[j+1];
					_array[j+1] = t;
					isSorted = false;
				}
			}

			if(isSorted)
				break;
		}
	}
	else
	{
		for(int i = 0; i < n-1; i++)
		{
			bool isSorted = true;
			for(int j = 0; j < n-i-1; j++)
			{
				if(_array[j] < _array[j+1])
				{
					T t = _array[j];
					_array[j] = _array[j+1];
					_array[j+1] = t;
					isSorted = false;
				}
			}

			if(isSorted)
				break;
		}
	}
}

template <class T> void InsertionSort(T *_array, int n, order o = ascending)
{
	if(o = ascending)
	{
		for(int i = 1; i < n; i++)
		{
			T key = _array[i];
			int j = i-1;
	
			while(_array[j] > key && j >= 0)
			{
				_array[j+1] = _array[j];
				j--;
			}
			
			_array[j+1] = key;
		}
	}
	else
	{
		for(int i = 1; i < n; i++)
		{
			T key = _array[i];
			int j = i-1;
	
			while(_array[j] < key && j >= 0)
			{
				_array[j+1] = _array[j];
				j--;
			}
			
			_array[j+1] = key;
		}
	}
}

template <class T> void QuickSort(T *_array, int l, int r)
{
	int i, j, pv, t;
	
	if(l >= r)
		return;
	
	i = l;
	j = r-1;
	pv = _array[r];

	while(i <= j)
	{
		while(i <= j && pv >= _array[i])
		{
			i = i+1;
		}

		while(j >= i && pv <= _array[j])
		{
			j = j-1;
		}

		if(i < j)
		{
			t = _array[i];
			_array[i] = _array[j];
			_array[j] = t;
		}
	}

	t = _array[r];
	_array[r] = _array[i];
	_array[i] = t;

	QuickSort(_array, l, i-1);
	QuickSort(_array, i+1, r);
}