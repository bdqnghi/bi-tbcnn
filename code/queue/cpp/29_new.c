#include <unittest++/UnitTest++.h>
#include <rotor/Queue.h>

SUITE( Queue ) {

  //----------------------------------------------------------------------------

  TEST( InsertionAndDeletion )
  {
    Rotor::Queue<int> queue;
    queue.push( 1 );
    CHECK_EQUAL( 1, queue.next() );
    queue.pop();
    queue.push( 2 );
    queue.push( 3 );
    queue.push( 4 );
    CHECK_EQUAL( 2, queue.next() );
    queue.pop();
    CHECK_EQUAL( 3, queue.next() );
    queue.pop();
    CHECK_EQUAL( 4, queue.next() );
    queue.pop();
  }

/*  TEST( BlockingBehavior )
  {
    Rotor::Queue<int> queue;
    // I don't know how to check this
    //queue.pop();
  }*/
}
