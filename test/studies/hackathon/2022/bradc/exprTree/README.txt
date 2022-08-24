---------------------------------------------------------------------
Things started well, as I wrote this series of programs that tried to
just support the simple + expression in the instructions:
---------------------------------------------------------------------

addtree.chpl: My first attempt at getting the first tree working,
  which was easier than anticipated relative to the AoC trees,
  primarily because it doesn't need to store any NULL pointers at the
  leaves of the tree.

addtree2.chpl: Changed from an explicit print() method to writeThis()
  to be able to use it with write and writeln.


------------------------------------------------------------
Then, I was happy to find that I could apply a little bit of
genericity to remove some redundancy:
------------------------------------------------------------

addtree3.chpl: Merged the IntExp and VarExp cases into a single class
  using generics and type aliases.


-------------------------------------------------------------
Then I did a simple but lame code clone to get the other ops:
-------------------------------------------------------------

multioptree.chpl: Lame code clone way of adding the '-' and '*'
  classes


----------------------------------------------------------------------
Then I tried to refactor the lame code using the same generic approach
as with int/val, but failed to land it:
----------------------------------------------------------------------

tree-generic-fail.chpl: Tried to similarly merge AddExp, SubExp,
  MultExp using a generic class, but got an error that wasn't
  particularly clear, presumably because the generic class OpExp
  includes vague fields of type Exp.

tree-generic-fail2.chpl: Tried adding an explicit initializer and got
  similarly challenging error messages.

tree-generic-fail3.chpl: Tried changing argument intents and got back
  to the previous error, presumably due to having reproduced the
  compiler-generated initializer.


---------------------------------------------------------------------
At this point, I thought that maybe generics were overkill for the
operator anyway, given the current code, so switched from generics to
inheritance.  That said, once I added the eval() capability below, it
felt like it could be nice to eliminate the execution-time
conditional, which suggests that maybe I should return to this...


So then I tried using inheritance to factor the commonality instead
---------------------------------------------------------------------

multioptree-inherit-fail.chpl: gives assertion error in compiler

/* At this point, I commented out that assertion error */

multioptree-inherit-fail2.chpl: same code, comment indicates error I
  got.

multioptree-inherit-fail3.chpl: tried changing the intents on my
  initializers to 'in' leading to a different error about
  '<temporary>'

multioptree-inherit-fail4.chpl: tried changing the formal types to
  'owned' leading to a slightly different error about '<temporary>'


---------------------------------------------------------------------
At this point I got some traction by moving away from generic fields:
---------------------------------------------------------------------

multioptree-inherit-owned.chpl: made the fields 'owned' as well, which
  was my first variant of this to work

multioptree-inherit-shared.chpl: changed 'owned' to 'shared' which
  works equally well, but requires more typing (and, I'd guess,
  overhead)

multioptree-inherit-owned2.chpl: found that if I just made the fields
  'owned', I could remove a bunch of the other 'owned' parts

multioptree-inherit-owned3-fail.chpl: tried to remove the 'in' intents,
  but that doesn't work

multioptree-inherit-owned4.chpl: tried removing the ': Exp' formal types
  (arguably a bad idea for an initializer, but I was curious), and that
  worked.  Not captured here (and not surprising), but removing the 'in's
  from this version also doesn't work.

multioptree-inherit-shared2.chpl: similar to the above, but using 'shared'
  rather than 'owned'


-------------------------------------------------------------------
At this point, I added the environment to one of my implementations
-------------------------------------------------------------------

multioptree-inherit-eval-owned.chpl: A version of
  multioptree-inherit-owned2.chpl with an environment and evaluation
  methods


------------------------------------------------------------------
So then I went back to trying to make it generic rather than using
inheritance and had better luck
------------------------------------------------------------------

multioptree-generic-eval-owned.chpl: A version of
  multioptree-inherit-eval-owned.chpl that switches back to the
  generic-based approach for representing the op rather than the
  inheritance-based approach.

multioptree-generic-eval-shared.chpl: Identical, but using 'shared'
