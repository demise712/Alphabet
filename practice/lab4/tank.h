/*****************************************************************************
 * FILE: tank.h.partial                                                      *
 * CLASS PROVIDED: mixing_tank (part of namespace CS256_Asgn1)               *
 *  Author,  Mon/Year                                                        *
 *                                                                           *
 * CONSTRUCTORS:                                                             *
 *   mixing_tank( )                                                          *
 *    Preconditions: none                                                    *
 *    Postconditions:  The tank has capacity 100 and is empty                *
 *                                                                           *
 *   mixing_tank( double capacity )                                          *
 *    Preconditions: capacity is non-negative                                *
 *    Postconditions: The tank has the specified capacity and is empty       *
 *                                                                           *
 * MODIFICATION MEMBER FUNCTIONS:                                            *
 *   void add_A( double quantity )                                           *
 *     Preconditions: quantity is non-negative                               *
 *                    quantity is no greater than remaining space            *
 *     Postconditions: quantity of liquid `A' has been added to tank         *
 *                                                                           *
 *   void add_B( double quantity )                                           *
 *     Preconditions: quantity is non-negative                               *
 *                    quantity is no greater than remaining space            *
 *     Postconditions: quantity of liquid `A' has been added to tank         *
 *                                                                           *
 *   double draw( double quantity );                                         *
 *     Preconditions: quantity is non-negative                               *
 *     Postconditions: if quantity is no greater than the current volume     *
 *                       then quantity of the mixed liquid has been removed  *
 *                       from the tank.  Otherwise the tank has been emptied *
 *                                                                           *
 * CONSTANT MEMBER FUNCTIONS:                                                *
 *   double get_volume( )                                                    *
 *     Preconditions: None                                                   *
 *     Postconditions: 0 <= return value <= capacity of tank                 *
 *                     Return value is volume of mixed liquid in tank        *
 *                                                                           *
 *   double get_space( )                                                     *
 *     Preconditions: None                                                   *
 *     Postconditions: 0 <= return value <= capacity of tank                 *
 *                     Return value is remaining capacity of tank            *
 *                                                                           *
 *   double get_mix( )                                                       *
 *     Preconditions: tank is not empty                                      *
 *     Postconditions: 0.0 <= return value <= 1.0                            *
 *                     Return value is proportion of A in tank               *
 *                                                                           *
 *   bool is_empty( )                                                        *
 *     Preconditions: None                                                   *
 *     Postconditions: Returns true iff tank is empty                        *
 *                                                                           *
 * VALUE SEMANTICS                                                           *
 *  Assignments and copy constructor may be used with the mixing_tank class  *
 *  (via the automatic operators).                                           *
 *                                                                           *
 * LIBRARIES:  cassert for assert( )                                         *
 *                                                                           *
 * NAMESPACE  CS256_Asgn1                                                    *
 *                                                                           *
 *****************************************************************************/
#ifndef CS256_tank
#define CS256_tank

namespace CS256_Asgn1
{

  class mixing_tank
    {
    public:
      // CONSTRUCTORS
      mixing_tank( );
      mixing_tank( double capacity );
      // MODIFICATION MEMBER FUNCTIONS
      void add_A( double quantity );
      void add_B( double quantity );
      double draw( double quantity );
      // CONSTANT MEMBER FUNCTIONS
      double get_space( ) const;
      double get_volume( ) const;
      double get_mix( ) const;
      bool is_empty( ) const;
    private:
      double quantity_a;   // the quantity of a in a volume
      double quantity_b;   // the quantity of b in a volume
      double q_capacity;   // the capacity of a container
    };

}

#endif
