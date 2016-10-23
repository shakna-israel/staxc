#include "Cello.h"

void stax_push(var stax_Stack, var inti)
// Add a value to a given stack
{
  push(stax_Stack, inti);
}

void stax_drop(var stax_Stack)
// Drop the first value from a given stack
{
  bool long_enough = true;

  try
  {
    get(stax_Stack, $I(0));
  }
  catch (e in IndexOutOfBoundsError)
  {
    long_enough = false;
  }

  if(long_enough == true)
  {
    pop(stax_Stack);
  }
}

void stax_dup(var stax_Stack)
// Duplicate the top value of the given stack
{
  bool long_enough = true;

  try
  {
    get(stax_Stack, $I(0));
  }
  catch (e in IndexOutOfBoundsError)
  {
    long_enough = false;
  }

  if(long_enough == true)
  {
    var x = get(stax_Stack, $I(0));
    push(stax_Stack, x);
  }
}

//swap
//rev
//out
//new
//add
//sub
//mul
//div
//inc
//dec
//parse (includes goto and :label)

// eval from stdin
// eval from file

// test function

int main(int argc, char** argv)
{

  // Stack of Stacks

  var stax_Stack = new(Array, Int);
  show(stax_Stack);
  stax_push(stax_Stack, $I(10));
  show(stax_Stack);
  stax_drop(stax_Stack);
  stax_drop(stax_Stack);
  stax_dup(stax_Stack);
  stax_push(stax_Stack, $I(10));
  stax_dup(stax_Stack);
  show(stax_Stack);
  return 0;
}
