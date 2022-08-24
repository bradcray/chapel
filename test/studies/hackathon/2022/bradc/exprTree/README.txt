Approach
========

* I made trees using:
  - owned and shared
  - non-nilable and nilable (but mostly non- because nil wasn't needed)
  - specialized/code clone classes vs. generic and/or inherited classes

* I think my favorite ended up being a case that used three classes:
  - an abstract class
  - a generic class for the leaf nodes
  - a generic class for the operator nodes
  - type aliases with instantiations of the previous for the user


Takeaways
=========

* This exercise ran me into similar errors as I hit with AoC day 18,
  most of which were due to:

  1) generic class fields leading to inscrutible (to me) error messages

     [arguably I didn't actually want to use a generic field; but,
     being lazy, I also didn't want to type more than necessary; and I
     remain a little disappointed that I couldn't ever get the generic
     field case working, nor better understand the error messages]
     
  2) my use of default intents rather than 'in' in initializers

     [this made me wonder whether the default intents in initializers
     should be different than they are; or whether the default intents
     for classes arguments to initializers should be different; or
     maybe we could just customize the error message for cases of
     owned class arguments being used as field initializers to suggest
     "probably you want 'in' intent?]

* It was also strictly easier than AoC day 18 because of the lack of
  need for nilability.  I'd encourage anyone who did this exercise to
  create the three for AoC day 18 as an exercise of nilability (if
  they didn't do other exercises that naturally led to it).

* I was pleased by how easy it was to write my first few codes.  I was
  expecting explosions and flames, yet everything worked the first
  time to my surprise (to a large part due to the previous bullet I
  think?]

* Things got harder once I refactored to use generics and inheritance,
  though addressing the two points in my first bullet made things much
  better behaved and avoided most subsequent errors.

* The internal error I hit in the compiler was concerning, and given
  that I generally got better (which is to say, user-facing) errors
  when removing it, I wonder whether we should simply do that.


Play-by-play
============

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


-------------------------------------------------------------------
So then I tried adding nilability, not because this pattern really
wants it or needs it, but just to get some experience with it which
led to...
-------------------------------------------------------------------

multioptree-generic-eval-owned-nilable-fail.chpl: I didn't actually
  expect this to work but was curious how readable the error message
  would be.  I'd say "not as good as it could be..." — specifically,
  it seems as though a method call can never be defined on a nilable
  type, so we could specialize the message really early saying
  something like "can't call method on nilable type" rather than using
  what seems to be a more generic unresolved error message (that
  eventually mentions '!' but after the point that my eyes glazed
  over.

multioptree-generic-eval-owned-nilable.chpl: This happily worked as
  expected



