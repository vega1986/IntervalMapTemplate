#include "testing.h"
#include "interval_map.h"


#include <iostream>


namespace testing
{


namespace
{


void TestAppendInEmpty ()
{
  using namespace im;
  Interval_map< int, int > w{};
  w.Append( 0, 7, 11 );

  std::cout << w;
}


void TestAppendLeft ()
{
  using namespace im;
  Interval_map< int, int > w {};
  w.Append( 0, 7, 11 );
  w.Append( 0, 1,  3 );

  std::cout << w;
}


void TestAppendLeftRight ()
{
  using namespace im;
  Interval_map< int, int > w {};
  w.Append( 0, 7, 11 );
  w.Append( 0, 1,  3 );
  w.Append( 0, 0, 12 ); 

  std::cout << w;
}


void TestAppendLeftBetween ()
{
  using namespace im;
  for ( int b : std::initializer_list< int >{ 5, 13, 27 } )
  {
    Interval_map< int, int > w {};
    w.Append ( 0,  1,  3 );
    w.Append ( 0,  7, 11 );
    w.Append ( 0, 14, 19 );
    w.Append ( 0, 35, 39 );

    std::cout << "befor append { 0, " << b << " }" << std::endl;
    std::cout << w;
    w.Append ( 0, 0, b );
    std::cout << "after append" << std::endl;
    std::cout << w;
    std::cout << std::endl;
  }
}


void TestAppendLeftInside ()
{
  using namespace im;
  for ( int b : std::initializer_list< int >{ 1, 2, 3, 7, 9, 11, 14, 17, 19, 35, 37, 39 } )
  {
    Interval_map< int, int > w {};
    w.Append ( 0, 1, 3 );
    w.Append ( 0, 7, 11 );
    w.Append ( 0, 14, 19 );
    w.Append ( 0, 35, 39 );

    std::cout << "befor append { 0, " << b << " }" << std::endl;
    std::cout << w;
    w.Append ( 0, 0, b );
    std::cout << "after append" << std::endl;
    std::cout << w;
    std::cout << std::endl;
  }
}


void TestAppendRight ()
{
  using namespace im;
  int a { 41 };
  for ( int b : std::initializer_list< int > { 47 } )
  {
    Interval_map< int, int > w {};
    w.Append ( 0, 1, 3 );
    w.Append ( 0, 7, 11 );
    w.Append ( 0, 14, 19 );
    w.Append ( 0, 35, 39 );

    std::cout << "befor append { " << a << ", " << b << " }" << std::endl;
    std::cout << w;
    w.Append ( 0, a, b );
    std::cout << "after append" << std::endl;
    std::cout << w;
    std::cout << std::endl;
  }
}


void TestAppendBetweenRight ()
{
  using namespace im;
  int b { 41 };
  for ( int a : std::initializer_list< int > { 5, 13, 27 } )
  {
    Interval_map< int, int > w {};
    w.Append ( 0, 1, 3 );
    w.Append ( 0, 7, 11 );
    w.Append ( 0, 14, 19 );
    w.Append ( 0, 35, 39 );

    std::cout << "befor append { " << a << ", " << b << " }" << std::endl;
    std::cout << w;
    w.Append ( 0, a, b );
    std::cout << "after append" << std::endl;
    std::cout << w;
    std::cout << std::endl;
  }
}


void TestAppendBetweenBetween ()
{
  using namespace im;
  for ( const auto seg : std::initializer_list< std::pair< int, int > >{ {  4,  5 },
                                                                         {  4, 12 },
                                                                         {  4, 27 },
                                                                         { 12, 13 },
                                                                         { 12, 27 },
                                                                         { 27, 28 } } )
  {
    int a = seg.first;
    int b = seg.second;
    Interval_map< int, int > w {};
    w.Append ( 0, 1, 3 );
    w.Append ( 0, 7, 11 );
    w.Append ( 0, 14, 19 );
    w.Append ( 0, 35, 39 );

    std::cout << "befor append { " << a << ", " << b << " }" << std::endl;
    std::cout << w;
    w.Append ( 0, a, b );
    std::cout << "after append" << std::endl;
    std::cout << w;
    std::cout << std::endl;
  }
}

void TestAppendBetweenInside ()
{
  using namespace im;
  for ( const auto seg : std::initializer_list< std::pair< int, int > > { {  5,  9 },
                                                                          {  5, 16 },
                                                                          {  5, 37 },
                                                                          { 12, 16 },
                                                                          { 12, 37 },
                                                                          { 27, 37 } } )
  {
    int a = seg.first;
    int b = seg.second;
    Interval_map< int, int > w {};
    w.Append ( 0, 1, 3 );
    w.Append ( 0, 7, 11 );
    w.Append ( 0, 14, 19 );
    w.Append ( 0, 35, 39 );

    std::cout << "befor append { " << a << ", " << b << " }" << std::endl;
    std::cout << w;
    w.Append ( 0, a, b );
    std::cout << "after append" << std::endl;
    std::cout << w;
    std::cout << std::endl;
  }
}


void TestAppendInsideRight ()
{
  using namespace im;
  int b { 47 };
  for ( const auto a : std::initializer_list< int > { 1, 2, 3, 7, 9, 11, 14, 16, 19, 35, 37, 39 } )
  {
    Interval_map< int, int > w {};
    w.Append ( 0, 1, 3 );
    w.Append ( 0, 7, 11 );
    w.Append ( 0, 14, 19 );
    w.Append ( 0, 35, 39 );

    std::cout << "befor append { " << a << ", " << b << " }" << std::endl;
    std::cout << w;
    w.Append ( 0, a, b );
    std::cout << "after append" << std::endl;
    std::cout << w;
    std::cout << std::endl;
  }
}

void TestAppendInsideBetween ()
{
  using namespace im;
  for ( const auto seg : std::initializer_list< std::pair< int, int > > { {  1,  4 },
                                                                          {  2,  4 },
                                                                          {  3,  4 },
                                                                          {  1, 12 },
                                                                          {  2, 12 },
                                                                          {  3, 12 },
                                                                          {  7, 12 },
                                                                          {  9, 12 },
                                                                          { 11, 12 } } )
  {
    int a = seg.first;
    int b = seg.second;
    Interval_map< int, int > w {};
    w.Append ( 0, 1, 3 );
    w.Append ( 0, 7, 11 );
    w.Append ( 0, 14, 19 );

    std::cout << "befor append { " << a << ", " << b << " }" << std::endl;
    std::cout << w;
    w.Append ( 0, a, b );
    std::cout << "after append" << std::endl;
    std::cout << w;
    std::cout << std::endl;
  }
}


void TestAppendInsideInside ()
{
  using namespace im;
  const auto il =
    std::initializer_list< std::pair< int, int > > {
      { 1,  2 },
      { 2,  3 },
      { 1,  3 },

      { 1,  7 },
      { 1,  9 },
      { 1, 11 },

      { 2,  7 },
      { 2,  9 },
      { 2, 11 },

      { 3,  7 },
      { 3,  9 },
      { 3, 11 },

      { 1, 14 },
      { 1, 17 },
      { 1, 19 },

      { 2, 14 },
      { 2, 17 },
      { 2, 19 },

      { 3, 14 },
      { 3, 17 },
      { 3, 19 },

      { 7,  9 },
      { 8,  9 },
      { 9, 11 },

      { 7, 14 },
      { 7, 17 },
      { 7, 19 },

      { 9, 14 },
      { 9, 17 },
      { 9, 19 },

      { 11, 14 },
      { 11, 17 },
      { 11, 19 },

      { 14, 17 },
      { 15, 19 },
      { 14, 19 } };

  for ( const auto seg : il )
  {
    int a = seg.first;
    int b = seg.second;
    Interval_map< int, int > w {};
    w.Append ( 0, 1, 3 );
    w.Append ( 0, 7, 11 );
    w.Append ( 0, 14, 19 );

    std::cout << "befor append { " << a << ", " << b << " }" << std::endl;
    std::cout << w;
    w.Append ( 0, a, b );
    std::cout << "after append" << std::endl;
    std::cout << w;
    std::cout << std::endl;
  }
}


}


void TestIntervalMap ()
{
  std::cout << "--- append in empty ---" << std::endl;
  TestAppendInEmpty();
  std::cout << std::endl << std::endl;

  std::cout << "--- append left ---" << std::endl;
  TestAppendLeft();
  std::cout << std::endl << std::endl;

  std::cout << "--- append left right ---" << std::endl;
  TestAppendLeftRight();
  std::cout << std::endl << std::endl;

  std::cout << "--- append left between ---" << std::endl;
  TestAppendLeftBetween();
  std::cout << std::endl << std::endl;

  std::cout << "--- append left inside ---" << std::endl;
  TestAppendLeftInside();
  std::cout << std::endl << std::endl;

  std::cout << "--- append right ---" << std::endl;
  TestAppendRight();
  std::cout << std::endl << std::endl;

  std::cout << "--- append between right ---" << std::endl;
  TestAppendBetweenRight();
  std::cout << std::endl << std::endl;

  std::cout << "--- append between between ---" << std::endl;
  TestAppendBetweenBetween();
  std::cout << std::endl << std::endl;

  std::cout << "--- append between inside ---" << std::endl;
  TestAppendBetweenInside();
  std::cout << std::endl << std::endl;

  std::cout << "--- append inside right ---" << std::endl;
  TestAppendInsideRight();
  std::cout << std::endl << std::endl;

  std::cout << "--- append inside between ---" << std::endl;
  TestAppendInsideBetween();
  std::cout << std::endl << std::endl;

  std::cout << "--- append inside inside ---" << std::endl;
  TestAppendInsideInside();
  std::cout << std::endl << std::endl;
}


}
