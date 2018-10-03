#include "Queue.cpp"

template class Queue<int>;

void main ( )
{
	Queue<int> q ( 8 ) ;

	try
	{
		q.enQueue ( 5 );
		q.enQueue ( 6 );
		q.enQueue ( 7 );
		q.enQueue ( 8 );
		
		q.deQueue ( );
		//q.deQueue ( );

		q.enQueue ( 0 );
		//q.enQueue ( 0 );
		//q.enQueue ( 0 );
	//	q.enQueue ( 0 );


		cout << q.getElements ( ) << endl;

		//q.deQueue ( );
		//q.deQueue ( );
		//q.deQueue ( );
		//q.deQueue ( );

		//q.enQueue ( 8 );
		//q.enQueue ( 9 );
		//q.enQueue ( 9 );
		
		//while ( !q.isEmpty ( ) )
		//{
		//	cout << q.deQueue ( ) << endl;
		//}
	
	}

	catch ( exception & e )
	{
		cout << "exception occurred : " << e.what ( ) << endl;
	}
}