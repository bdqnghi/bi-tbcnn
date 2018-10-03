/**
 * @author Paul Sohier
 **/
public class stack
{
	private studentElement start;
	private int size;

	/**
	*
	**/
	public stack()
	{

	}

	/**
	* Voeg een student toe aan de stack
	* @param s Student
	**/
	public void push(student s)
	{
		studentElement last = new studentElement(s);
		studentElement prev;

		if (size != 0)
		{
			prev = getLast();
		}
		else
		{
			start = last;
			size++;
			return;
		}      
		try
		{
			prev.setVolgend(last);
		}
		catch(studentStackExistsException e)
		{
			System.out.println(e);
			return;
		}
		size++;
	}

	/**
	* Geef de grote terug van de stack
	* @return int grote
	**/
	public int getSize()
	{
		return size;
	}

	/**
	* Geeft de laatste student terug
	* @return student Laatste student
	**/
	public student pop()
	{
		studentElement last = getLast();
		studentElement tmp = start;

		for (int i = 0; i < size -2; i++) // size - 1 om het laatste element te krijgen.
		{
			tmp = tmp.getVolgend();
		}
		try
		{
			if (tmp != null)
			tmp.setVolgend(null);  // verwijder laatste element!
			size--;
		}
		catch (studentStackExistsException e)
		{
			System.out.println(e);
			return null;
		}

		if (last != null)
			return last.getStudent();
		else
			return null;
	}

	/**
	* Controleer of een bepaalde student met dat studentnummer al aanwezig is
	* @param s student om te controleren.
	* @return boolean True indien aanwezig, anders false.
	**/
	public boolean peek(student s)
	{
		studentElement tmp = start;
		for (int i = 0; i < getSize(); i++)
		{
			student t = tmp.getStudent();

			if (s.getStudent() == t.getStudent())
			{
				return true;
			}
			tmp = tmp.getVolgend();	     
		}

		return false;
	}

	/**
	* Print alle studenten
	**/
	public void printStack()
	{
		studentElement tmp = start;
		for (int i = 0; i < getSize(); i++)
		{
			tmp.getStudent().printStudent();
			tmp = tmp.getVolgend();
		}
	}

	/**
	* Print alle mannen
	**/
	public void printmen()
	{
		studentElement tmp = start;
		for (int i = 0; i < getSize(); i++)
		{
			if (tmp.getStudent().getGeslacht() == "m")
			{
				tmp.getStudent().printStudent();
			}
			tmp = tmp.getVolgend();
		}
	}
	/** 
	* Print alle vrouwen
	**/
	public void printwomen()
	{
		studentElement tmp = start;
		for (int i = 0; i < getSize(); i++)
		{
			if (tmp.getStudent().getGeslacht() == "f")
			{
				tmp.getStudent().printStudent();
			}
			tmp = tmp.getVolgend();
		}
	}
	/**
	* Haal het laatste studentElement op uit de stack
	* @return studentElement
	* @access private
	**/
	private studentElement getLast()
	{
		studentElement vorig = start;
		for (int i = 0; i < size; i++)
		{
			if (vorig.volgend())
			{
				vorig = vorig.getVolgend();
			}
			else
			{
				return vorig;
			}
		}
		System.out.println("ERROR!");
		return null;
	}
}
