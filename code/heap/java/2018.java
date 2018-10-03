package com.fresh.tree;

import java.lang.reflect.Array;
import java.util.List;

public class Heap<T extends Comparable<T>> extends Tree<T>
{
	int root = -1;
	int end = 1;
	private Class<T> tClass;
	T[] array;
	
	@SuppressWarnings("unchecked")
	public Heap(Class<T> Tclass, int initalSize)
	{
		tClass = Tclass;
		array = (T[]) Array.newInstance(tClass, initalSize);
	}

	@Override
	public boolean add(T data)
	{
		if (root == -1)
		{
			array[end++] = data;
			root = 1;
			return true;
		}
		else
		{
			return add(data, end);
		}
	}

	private boolean add(T data, int endpoint)
	{
		if (length() == end)
		{
			doubleArray();
		}
		array[end] = data;
		parentBalance(end++);
		return true;
	}

	@SuppressWarnings("unchecked")
	public void doubleArray()
	{
		T[] newArray = (T[]) Array.newInstance(tClass, length() * 2);
		for (int i = 0; i < length(); i++)
		{
			newArray[i] = array[i];
		}
		array = newArray;
	}

	@Override
	public boolean delete(T data)
	{
		return false;
	}

	@Override
	public boolean insert(T data)
	{
		return false;
	}

	@Override
	public boolean remove(T data)
	{
		return false;
	}
	
	public T peek()
	{
		return array[root];
	}

	public T pull()
	{
		T tmp = array[--end];
		array[end] = array[root];
		array[root] = tmp;
		childBalance(root);
		return array[end];
	}

	public int size()
	{
		return end;
	}
	
	public int length()
	{
		return array.length;
	}

	@Override
	public int height()
	{
		return size()/2;
	}

	@Override
	public int levels()
	{
		return height() - 1;
	}

	@SuppressWarnings("unchecked")
	@Override
	public void clear()
	{
		root = -1;
		end = 1;
		array = (T[]) Array.newInstance(tClass, 2);
	}

	@Override
	public void rebalance()
	{
	}

	private void parentBalance(int child)
	{
		int parent = child/2;
		if(parent >= root && child < end)
		{
			if(array[parent].compareTo(array[child]) < 0)
			{
				swap(parent, child);
			}
			if(parent > root)
			{
				parentBalance(parent);
			}
		}
	}
	
	private void childBalance(int parent)
	{
		int leftChild = parent*2;
		int rightChild = (parent*2) +1;
		if(leftChild < end && rightChild < end)
		{
			T leftData = array[leftChild];
			int swapIndex;
			if(rightChild <= end)
			{
				T rightData = array[rightChild];
				if(rightData.compareTo(leftData)>0)
				{
					swap(parent, rightChild);
					childBalance(rightChild);
				}
				else
				{
					swap(parent, leftChild);
					childBalance(leftChild);
				}
			}
			else
			{
				if(leftData.compareTo(array[parent])>0)
				{
					swap(parent, leftChild);
					childBalance(leftChild);
				}
			}
		}
	}
	private void swap(int parent, int end)
	{
		T parentData = array[parent];
		array[parent] = array[end];
		array[end] = parentData;
	}
	@Override
	public List<T> ancestors(T data)
	{
		return null;
	}

	@Override
	public boolean contains(T data)
	{
		return false;
	}

	@Override
	public List<T> preorder()
	{
		return null;
	}

	@Override
	public List<T> postorder()
	{
		return null;
	}

	@Override
	public List<T> inorder()
	{
		return null;
	}
}
