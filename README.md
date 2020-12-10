# Advent of Code 2020

## Python

The python solutions are my attempts to place on the leaderboard. Usually I
butcher day 1 when solving day 2. Sometimes I restore / tidy the code before
pushing to GitHub. Most of the time I won't. There's many better written python
solutions on the internet.

## C

The C solutions are compiled with gcc on OSX:

```
$ gcc --version
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/c++/4.2.1
Apple clang version 12.0.0 (clang-1200.0.26.2)
Target: x86_64-apple-darwin19.6.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

and compiled with `-Wall` (but not `-Werror`). In an effort to avoid the
5-character `stdin` token or format strings, I sometimes call `gets`, which is
deprecated in C99, removed in later editions of the C standard, and horribly
unsafe. Interestingly on OSX, using `gets` prints a runtime warning, but no
compile time warnings.

To compile a solution:
```
gcc -Wall -Werror -o day02.out day02.c
```

For the part 1 answer:
```
./day02.out < day02.in
```

For the part 2 answer:
```
./day02.out part2 < day02.in
```

In general, you can switch between part 1 and part 2 by passing any command line argument.

I don't have many strict rules for myself, but I'm trying to hold myself to this standard:
- Minimize spaces beyond the "hole" or between a type and identifier
- No manually editing the input file (this is unlikely to budge)
- No defines
- No implicit int declarations
- No external libraries (will definitely break if hashtables or hashing is strictly needed, but probably won't stray from [this list](https://gist.github.com/williewillus/07f534b706262ccc67119ddc70b2bd75))

I might break some of these "rules" as the days get harder.

## Notes on reducing token length

This isn't code golf: the goal is to use as many short tokens as possible, even
if you use a few bytes. Longer tokens are exponentially harder to work with
than short tokens. Here are some tricks I've found that can save some tokens:

String concatenation in C just works if you surround both parts with quotes,
with no operator in between. This adds several characters though, so try and avoid it.

```c
const char* s = "hello "
    "world";
```

For loops are much more manageable than while loops
```c
for(;<cond>;){
    // stuff
}
```

You can break up longer integer constants using math, but this will add more characters
```
assert(2020 == (99+2)*20)
```

Use integer literals instead of character literals. It makes the code less
readable, but was this ever readable?

There are also many different tricks to pad with extra characters as needed. For example:
```c
/* ADD 1 CHAR */
/* empty statements */
int x = 0;;

/* unary plus */
int x = +0;

/* ADD 2 CHAR */
/* extra scope blocks */
for (/**/) {{ }}

/* trailing comment slashes */
int x = 0;//

/* bonus parens */
int y = (5);

/* ref and deref */
int x = *&y;

/* identity for bools */
int x = !!x;

/* ADD 4+ CHAR */
/**/
```

It's best to re-arrange the code so the long tokens are at the beginning and
ends. Unavoidable long tokens are usually format strings, input parsing
functions like `scanf` and `gets`, and `printf`.

# Megathread Comments

- [Day 1](https://www.reddit.com/r/adventofcode/comments/k4e4lm/2020_day_1_solutions/geash89)
- [Day 2](https://www.reddit.com/r/adventofcode/comments/k52psu/2020_day_02_solutions/gecftlc)
- [Day 3](https://www.reddit.com/r/adventofcode/comments/k5qsrk/2020_day_03_solutions/gehy1od)
- [Day 4](https://www.reddit.com/r/adventofcode/comments/k6e8sw/2020_day_04_solutions/gelx4er)
- [Day 5](https://www.reddit.com/r/adventofcode/comments/k71h6r/2020_day_05_solutions/geq8cj8)
- [Day 6](https://www.reddit.com/r/adventofcode/comments/k7ndux/2020_day_06_solutions/gesc8cy)
- [Day 7](https://www.reddit.com/r/adventofcode/comments/k8a31f/2020_day_07_solutions/gex8luw)
- [Day 8](https://www.reddit.com/r/adventofcode/comments/k8xw8h/2020_day_08_solutions/gf15x3p)
- [Day 9](https://www.reddit.com/r/adventofcode/comments/k9lfwj/2020_day_09_solutions/gf59qvb)
