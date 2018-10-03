package kr.po1.webtechmobile;

import java.util.ArrayList;

import android.util.Log;

public class Stack
{
	private ArrayList<Object> data = new ArrayList<Object>();

	public void push(Object in)
	{
		data.add(in);
		Log.d("tag", data.toString());
	}

	public Object pop()
	{
		if(data.size() < 1)
			return null;

		int lastIndex = data.size() - 1;
		Object ret = data.get(lastIndex);
		data.remove(lastIndex);
		Log.d("tag", data.toString());

		return ret;
	}

	public void clean()
	{
		data = new ArrayList<Object>();
	}
}
