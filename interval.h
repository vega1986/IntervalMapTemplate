#pragma once


#include <set>
#include <compare>


namespace im
{


enum class Pos : unsigned int
{
  begin = 0u,
  end = 1u,
};


template < typename T >
struct Point
{
  T t {};
  Pos pos { Pos::begin };
  auto operator<=>( const Point & b ) const
  {
    return ( t <=> b.t );
  }
};


enum class RelativePos : unsigned int
{
  ///<              a is ~ here:
  ///<                   |
  ///<                   v
  ///< -------------------------*******------****----*******-----******-------------------------
  outerLeft = 0u,

  ///<                                                                a is ~ here:
  ///<                                                                     |
  ///<                                                                     v
  ///< -------------------------*******------****----*******-----******-------------------------
  outerRight = 1u,

  ///<                                                   a is ~ here:
  ///<                                                        |
  ///<                                                        v
  ///< -------------------------*******------****----*******-----******-------------------------
  outerBetween = 2u,

  ///<                                            a is ~ here:
  ///<                                                 |
  ///<                                                 v
  ///< -------------------------*******------****----*******-----******-------------------------
  inside = 4u,
};


template< typename T >
using PointSet = std::set< Point< T > >;


template< typename T >
const RelativePos GetPosition ( const PointSet< T >& points, const T t )
{
  using enum RelativePos;
  RelativePos res { outerLeft };
  Point p { t };
  auto l = points.lower_bound ( p );
  auto u = points.upper_bound ( p );
  auto beg = points.begin ();
  auto end = points.end ();
  auto last = points.rbegin().base();
  if ( u == beg )
  {
    res = outerLeft;
  }
  else if ( l == end )
  {
    res = outerRight;
  }
  else if ( ( u != end ) and ( u->pos == Pos::begin ) and ( l == u ) )
  {
    res = outerBetween;
  }
  else
  {
    res = inside;
  }

  return res;
}


template< typename T >
auto GetBetweenRange ( const PointSet< T > & points, const T t )
{
  Point p { t };
  auto itr = points.upper_bound( p );
  auto itl = std::prev( itr );
  return std::pair { itl, itr };
}


template< typename T >
auto GetInsideRange ( const PointSet< T > & points, const T t )
{
  using It = PointSet< T >::const_iterator;
  std::pair< It, It > res {};
  Point p { t };
  auto l = points.lower_bound ( p );
  auto u = points.upper_bound( p );
  if ( l != u )
  {
    // exact in point
    if ( l->pos == Pos::begin )
    {
      res.first = l;
      res.second = u;
    }
    else
    {
      res.second = l;
      res.first = std::prev ( l );
    }
  }
  else
  {
    res.second = l;
    res.first = std::prev ( l );
  }

  return res;
}


}