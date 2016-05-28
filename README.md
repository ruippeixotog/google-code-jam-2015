# Google Code Jam 2015

This repository contains my solutions to the problems from [Google Code Jam 2015][1] and [Distributed Google Code Jam 2015][2]. These solutions are provided "as is" - I give no guarantees that they will work as expected.

## Instructions

You can compile all Google Code Jam problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and identifier of the problem you want to compile (see section "Problems Solved" for the list of possible identifiers):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the identifier of the desired problem:

    $ ./<problem_id>

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

Distributed Google Code Jam problems should be compiled and run using the local testing tool described in the [guide][3]. An example would be:

    $ dcj test --source <round_name>/<problem_id>.cpp --nodes <number_of_nodes>

You'll need to have an input header file with the name `<problem_id>.h` in the same directory as the source file. You can download sample inputs from each problem's page.

## Problems Solved

The following is the list of the problems solved. Each problem identifier is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete or aren't efficient enough for the problem's limits.

### Qualification Round

* ✓ [A: Standing Ovation][qual1] (`standing-ovation`)
* ✓ [B: Infinite House of Pancakes][qual2] (`infinite-house-of-pancakes`)
* ✓ [C: Dijkstra][qual3] (`dijkstra`)
* ✓ [D: Ominous Omino][qual4] (`ominous-omino`)

### Round 1A

* ✓ [A: Mushroom Monster][round1a1] (`mushroom-monster`)
* ✓ [B: Haircut][round1a2] (`haircut`)
* ✓ [C: Logging][round1a3] (`logging`)

### Round 1B

* ✓ [A: Counter Culture][round1b1] (`counter-culture`)
* ✓ [B: Noisy Neighbors][round1b2] (`noisy-neighbors`)
* ✓ [C: Hiking Deer][round1b3] (`hiking-deer`)

### Round 1C

* ✓ [A: Brattleship][round1c1] (`brattleship`)
* ✓ [B: Typewriter Monkey][round1c2] (`typewriter-monkey`)
* ✓ [C: Less Money, More Problems][round1c3] (`less-money-more-problems`)

### Round 2

* ✓ [A: Pegman][round21] (`pegman`)
* ✗ [B: Kiddie Pool][round22] (`kiddie-pool`)

### Distributed Online Round

* ✓ [B: Almost Sorted][distribonline2] (`almost_sorted`)
* ✓ [C: Mutexes][distribonline3] (`mutexes`)
* ✗ [E: Highest Mountain][distribonline5] (`highest_mountain`)

[1]: https://code.google.com/codejam
[2]: https://code.google.com/codejam/distributed_index.html
[3]: https://code.google.com/codejam/distributed_guide.html
[qual1]: https://code.google.com/codejam/contest/6224486/dashboard#s=p0
[qual2]: https://code.google.com/codejam/contest/6224486/dashboard#s=p1
[qual3]: https://code.google.com/codejam/contest/6224486/dashboard#s=p2
[qual4]: https://code.google.com/codejam/contest/6224486/dashboard#s=p3
[round1a1]: https://code.google.com/codejam/contest/4224486/dashboard#s=p0
[round1a2]: https://code.google.com/codejam/contest/4224486/dashboard#s=p1
[round1a3]: https://code.google.com/codejam/contest/4224486/dashboard#s=p2
[round1b1]: https://code.google.com/codejam/contest/8224486/dashboard#s=p0
[round1b2]: https://code.google.com/codejam/contest/8224486/dashboard#s=p1
[round1b3]: https://code.google.com/codejam/contest/8224486/dashboard#s=p2
[round1c1]: https://code.google.com/codejam/contest/4244486/dashboard#s=p0
[round1c2]: https://code.google.com/codejam/contest/4244486/dashboard#s=p1
[round21]: https://code.google.com/codejam/contest/8234486/dashboard#s=p0
[round22]: https://code.google.com/codejam/contest/8234486/dashboard#s=p1
[distribonline2]: https://code.google.com/codejam/contest/8254486/dashboard#s=p1
[distribonline3]: https://code.google.com/codejam/contest/8254486/dashboard#s=p2
[distribonline5]: https://code.google.com/codejam/contest/8254486/dashboard#s=p4
