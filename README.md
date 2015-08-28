# Solutions to Google Code Jam 2015 problems

This repository contains solutions to the [Google Code Jam 2015][1] problems. These solutions are provided "as is". I give no guarantees that they will work as expected.

## Instructions

You can compile all the problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and id of the problem you want to compile (see section "Problems Solved" for the list of possible ids):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the id of the desired problem:

    $ ./<problem_id>

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

## Problems Solved

The following is the list of the problems solved. Each problem id is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete and/or aren't efficient enough.

### Qualification Round

* ✓ [A: Standing Ovation][qual1] (`standing-ovation`)
* ✓ [B: Infinite House of Pancakes][qual2] (`infinite-house-of-pancakes`)
* ✓ [C: Dijkstra][qual3] (`dijkstra`)
* ✗ [C: Ominous Omino][qual4] (`ominous-omino`)

### Round 1A

* ✓ [A: Mushroom Monster][round1a1] (`mushroom-monster`)
* ✓ [B: Haircut][round1a2] (`haircut`)
* ✗ [C: Logging][round1a3] (`logging`)

### Round 1B

* ✗ [A: Counter Culture][round1b1] (`counter-culture`)
* ✓ [B: Noisy Neighbors][round1b2] (`noisy-neighbors`)
* ✗ [C: Hiking Deer][round1b3] (`hiking-deer`)

### Round 2

* ✗ [A: Pegman][round21] (`pegman`)
* ✗ [B: Kiddie Pool][round22] (`kiddie-pool`)

[1]: https://code.google.com/codejam
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
[round21]: https://code.google.com/codejam/contest/8234486/dashboard#s=p0
[round22]: https://code.google.com/codejam/contest/8234486/dashboard#s=p1
