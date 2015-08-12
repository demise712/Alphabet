/*****************************************************************************
 * FILE: tank.cpp.partial                                                    *
 * JRogers Jan/2001                                                          *
 * Modified Feb/2003 added block comments                                    *
 * CLASS PROVIDED: mixing_tank (part of namespace CS256_Asgn1)               *
 *    See tank.h for documentation                                           *
 *                                                                           *
 * LIBRARIES:  cassert for assert( )                                         *
 *                                                                           *
 * NAMESPACE  CS256_Asgn1                                                    *
 *                                                                           *
 *****************************************************************************/
#include <cassert>
#include "tank.h"

using namespace std;

namespace CS256_Asgn1
{
  
/*****************************************************************************
 * CONSTRUCTORS:                                                             *
 *****************************************************************************/

/*****************************************************************************
 *   mixing_tank( )                                                          *
 *    Preconditions: none                                                    *
 *    Postconditions:  The tank has capacity 100 and is empty                *
 *****************************************************************************/
  mixing_tank::mixing_tank( )
    { 
      quantity_a = 0.0;
      quantity_b = 0.0;
      q_capacity = 500;
    }
  
/*****************************************************************************
 *   mixing_tank( double capacity )                                          *
 *    Preconditions: capacity is non-negative                                *
 *    Postconditions: The tank has the specified capacity and is empty       *
 *****************************************************************************/
  mixing_tank::mixing_tank( double capacity)
    { 
      quantity_a = 0.0;
      quantity_b = 0.0;
      q_capacity = capacity;
    }
  
  
/*****************************************************************************
 *  MODIFICATION MEMBER FUNCTIONS                                            *
 *****************************************************************************/

/*****************************************************************************
 *   void add_A( double quantity )                                           *
 *     Preconditions: quantity is non-negative                               *
 *                    quantity is no greater than remaining capacity         *
 *     Postconditions: quantity of liquid `A' has been added to tank         *
 *****************************************************************************/
  void mixing_tank::add_A( double quantity )
    { 
      assert (quantity >= 0.0);
      assert (quantity <= get_space());
      quantity_a += quantity;
      
    }
  
  // etc. 
          
  void  mixing_tank::add_B( double quantity )
      {
        assert (quantity >= 0.0);
        assert (quantity <= get_space());
        quantity_b += quantity;
      }
      double  mixing_tank::draw( double quantity )
      {
        assert (quantity >= 0.0);
        double temp; // keeps track of what the volume is 
        temp = get_volume() - quantity;
        quantity_a -=  ((get_mix())*quantity);
        quantity_b =  temp - quantity_a;
        return quantity;
      }

      // CONSTANT MEMBER FUNCTIONS
      double  mixing_tank::get_space( ) const
      {
        return q_capacity - get_volume ();
      }

      double  mixing_tank::get_volume( ) const
      {
        return quantity_a + quantity_b;
      }

      double  mixing_tank::get_mix( ) const
      {
        assert (!is_empty());
        return ((quantity_a / get_volume ()));
      }

      bool  mixing_tank::is_empty( ) const
      {
        return get_volume() == 0.0;
      }

}
