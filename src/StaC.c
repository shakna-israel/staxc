#include "Cello.h"
#include "test.h"

void stax_push(var stax_Stack, var inti)
// Add a value to a given stack
{
  push_at(stax_Stack, copy(inti), $I(0));
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
    var x = copy(get(stax_Stack, $I(0)));
    push(stax_Stack, x);
  }
}

void stax_swap(var stax_Stack)
// Swap the top two values of the given stack
{
  bool long_enough = true;

  try
  {
    get(stax_Stack, $I(0));
    get(stax_Stack, $I(1));
  }
  catch (e in IndexOutOfBoundsError)
  {
    long_enough = false;
  }

  if(long_enough == true)
  {
    var x = copy(get(stax_Stack, $I(0)));
    var x2 = copy(get(stax_Stack, $I(1)));
    stax_drop(stax_Stack);
    stax_drop(stax_Stack);
    push(stax_Stack, x);
    push(stax_Stack, x2);
  }
}

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
int test()
{
  var stax_Stack = new(Array, Int);
  stax_push(stax_Stack, $I(1));
  if(test_assert(get(stax_Stack, $I(0)), $I(1)) != 0)
  {
    return 1;
  }

  return 0;
}

int main(int argc, char** argv)
{

  // Stack of Stacks

  var stax_Stack = new(Array, Int);
  
  return test();
}
