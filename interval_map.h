#pragma once


#include "interval.h"


#include <map>
#include <algorithm>
#include <ostream>


namespace im
{


template< typename KeyType, typename ValueType >
class Interval_map
{
public:
  Interval_map () = default;
  void Append ( const KeyType key, const ValueType t1, const ValueType t2 );
  
  template< typename K, typename V >
  friend std::ostream & operator << ( std::ostream & ost, const Interval_map< K, V > & c );
private:
  using Points = PointSet< ValueType >;

  std::map< KeyType, Points > data {};
};


template< typename KeyType, typename ValueType >
inline void Interval_map< KeyType, ValueType >::Append ( const KeyType key, const ValueType t1, const ValueType t2 )
{
  const auto a = std::min ( t1, t2 );
  const auto b = std::max ( t1, t2 );
  ///< null length segment does not allowed
  if ( a == b )
  {
    return;
  }

  if ( data.contains ( key ) )
  {
    auto & points = data[ key ];
    const auto apos = GetPosition( points, a );
    const auto bpos = GetPosition( points, b );

    using enum RelativePos;
    if ( apos == outerLeft )
    {
      if ( bpos == outerLeft )
      {
        ///< tested!
        points.insert( Point { a, Pos::begin } );
        points.insert( Point { b, Pos::end } );
      }
      else if ( bpos == outerRight )
      {
        ///< tested!
        points.clear();
        points.insert ( Point { a, Pos::begin } );
        points.insert ( Point { b, Pos::end   } );
      }
      else if ( bpos == outerBetween )
      {
        ///< tested!
        auto [ il, ir ] = GetBetweenRange ( points, b );
        auto ibeg = points.begin();
        points.erase( ibeg, ir );
        points.insert ( Point { a, Pos::begin } );
        points.insert ( Point { b, Pos::end   } );
      }
      else // inside
      {
        ///< tested!
        auto [ il, ir ] = GetInsideRange( points, b );
        auto ibeg = points.begin();
        points.erase( ibeg, ir );
        points.insert( Point { a, Pos::begin } );
      }
    }
    else if ( apos == outerRight )
    {
      ///< tested!
      points.insert( Point { a, Pos::begin } );
      points.insert( Point { b, Pos::end } );
    }
    else if ( apos == outerBetween )
    {
      if ( bpos == outerRight )
      {
        ///< tested!
        auto [il, ir] = GetBetweenRange ( points, a );
        auto iend = points.end();
        points.erase( ir, iend );
        points.insert( Point { a, Pos::begin } );
        points.insert( Point { b, Pos::end   } );
      }
      else if ( bpos == outerBetween )
      {
        ///< tested!
        auto [ ial, iar ] = GetBetweenRange( points, a );
        auto [ ibl, ibr ] = GetBetweenRange( points, b );
        points.erase( iar, ibr );
        points.insert( Point { a, Pos::begin } );
        points.insert( Point { b, Pos::end   } );
      }
      else // inside
      {
        ///< tested!
        auto [ ial, iar ] = GetBetweenRange( points, a );
        auto [ ibl, ibr ] = GetBetweenRange( points, b );
        points.erase( iar, ibr );
        points.insert( Point { a, Pos::begin } );
      }
    }
    else // inside
    {
      auto [ ial, iar ] = GetInsideRange ( points, a );
      if ( bpos == outerRight )
      {
        ///< tested!
        auto iend = points.end();
        points.erase( iar, iend );
        points.insert( Point { b, Pos::end } );
      }
      else if ( bpos == outerBetween )
      {
        ///< tested!
        auto [ ibl, ibr ] = GetBetweenRange( points, b );
        points.erase( iar, ibr );
        points.insert( Point { b, Pos::end } );
      }
      else // inside
      {
        ///< tested!
        auto [ ibl, ibr ] = GetInsideRange( points, b );
        points.erase( iar, ibr );
      }
    }
  }
  else
  {
    ///< tested!
    Points ps { Point { a, Pos::begin }, Point { b, Pos::end } };
    data[ key ] = std::move ( ps );
  }
}


template< typename K, typename V >
inline std::ostream & operator << ( std::ostream & ost, const Interval_map< K, V > & c )
{
  auto & d = c.data;
  for ( auto it { d.cbegin() }; it != d.cend(); ++it )
  {
    ost << it->first << ": ";
    auto & s = it->second;
    for ( auto jt { s.cbegin() }; jt != s.cend(); )
    {
      auto jtNext = std::next( jt );
      ost << "{ " << jt->t << ", " << jtNext->t << " }";
      jt = std::next( jtNext );
      if ( jt != s.cend() )
      {
        ost << "; ";
      }
    }
    ost << std::endl;
  }
  return ost;
}


}
