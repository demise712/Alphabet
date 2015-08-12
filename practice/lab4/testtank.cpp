/*****************************************************************************
 * FILE:  testtank.cpp.partial                                               *
 * AUTHOR:  J. Rogers, Jan/2001                                              *
 *  Program for interactive testing of mixing_tank class                     *
 *  (Partial implementation)                                                 *
 *                                                                           *
 * Creates tank of capacity 500.  Allows addition of some quantity of A,     *
 *   addition of some quantity of B, and drawing of some quantity. Prints    *
 *   status of tank after each action:  empty?, current volume, percentage   *
 *   of volume that is A, and capacity left.                                 *
 *                                                                           *
 * LIBRARIES: iostream                                                       *
 *            cassert     for assert()                                       *
 *            cstdlib     for EXIT_SUCCESS                                   *
 *            tank.h      for mixing_tank                                    *
 *                                                                           *
 *****************************************************************************/
#include <iostream>
#include <cassert>
#include <cstdlib>
#include "tank.h"

using namespace std;
using namespace CS256_Asgn1;

void status( mixing_tank& t );
//   Writes status of t to cout                                              
// PRECONDITIONS: None                                                       
// POSTCONDITIONS: If t is empty has written "is empty"                      
//                 Otherwise has written                                    
//                  "Volume: v Percent A: p Space: s"                        
//                 where v, p, and s are volume, mix and space of t          
//                 Leaves output at beginning of line.                       


/*****************************************************************************
 * PROGRAM: testtank                                                         *
 *  Interactive exerciser for mixing_tank class                              *
 *                                                                           *
 *****************************************************************************/

int main( )
{
  char action;   // User's command

  mixing_tank t1(500);  // Tank under test
  
  // Print instructions
  // Precondition/Postcondition: Output at BOL
  cout << "Actions are:\tq -- quit\n"
       << "\t\ta -- add A\n"
       << "\t\tb -- add B\n"
       << "\t\td -- draw" << endl;

  // Print status
  // Precondition/Postcondition: Output at BOL
  cout << "t1: ";
  status( t1 );

  // Command loop
  // Preconditions: none
  // Postconditions:  User has entered 'q' or input has failed
  do
    {
      // Invariants:  User has not entered 'q'
      //              All user commands have been executed

      // Prompt for and get command
      // Preconditions: none
      // Postconditions: action has user's command
      cout << "Action: ";
      cin >> action;

      // Dispatch command
      // Preconditions:  action has command
      // Postconditions: command has been executed
      //                 output is at BOL
      switch ( action )
        {
          double much_a;      // how much the user wants from a
          double much_b;     // how much the user wants from b
          double drawn;     // drawn volume from the tank
        case 'a':
          cout <<"How much do you want to add?: "<<endl;
          cin >> much_a;
          //t1.add_A(much_a);
          if(much_a >= 0.0)
          {
            if(much_a <= t1.get_space())
              {
                t1.add_A(much_a);
              }
            else
              {
                cout <<"Too full "<<endl;
              }
          }
          else
            {
              cout <<"It can not be less than 0: "<<endl;
            }
         
          break;
        case 'b':
          cout <<"How much do you want to add?: " <<endl;
          cin >> much_b;
          //t1.add_B(much_b);
          if (much_b >= 0.0)
            {
              if (much_b <= t1.get_space())
            {
          t1.add_B(much_b);
            }
              else
                {
                  cout <<"Too full "<<endl;
                }
            }
          else
            {
              cout <<"It can not be less than 0: "<<endl;
            }
          break;
        case 'd':
          cout <<"How much do you want to add?: " <<endl;
          cin >> drawn;
        
          if(drawn >= t1.get_volume())
            drawn =  t1.get_volume();
          drawn = t1.draw(drawn);
          cout << "Drew "<< drawn <<endl;
          break;
        case 'q':
          break;
        default:
          cout << "Huh?" << endl;
        }
      
      // Print results
      // Precondition: none
      // Postconditions: output is at BOL
      cout << "t1: ";
      status( t1 );
    } while ( cin.good() && ( action != 'q' ) );

  exit(EXIT_SUCCESS);
}

/*****************************************************************************
 * FUNCTION: void status( mixing_tank& t )                                   *
 *   Writes status of t to cout                                              *
 * PRECONDITIONS: None                                                       *
 * POSTCONDITIONS: If t is empty has written "is empty"                      *
 *                 Otherwise has written                                     *
 *                  "Volume: v Percent A: p Space: s"                        *
 *                 where v, p, and s are volume, mix and space of t          *
 *                 Leaves output at beginning of line.                       *
 *                                                                           *
 *****************************************************************************/
void status( mixing_tank& t )
{
  if ( t.is_empty( ) )
    cout << "is empty";
  else
    {
      cout << "Volume: " << t.get_volume( );
      cout << " Percent A: " << (100* t.get_mix( ) );
      cout << " Space: " << t.get_space( );
    }
  cout << endl;
}
  
