Made by Gian Cedrick Aug 22 10:21

### Simple profiling library for Zyklon and can be utilized by other programs as well

#### TODO:
- track memory allocations
- json chrome visualization
- timing and benchmarking
- spdlog logging

---
- add clang formatting
- add doxygen

- add custom targets for profiling like zyklon-profile (make-test)

---
- Cmake static lib windows support


### Issues:

Sep 5 11:23,
    I am still trying to figure out what parameters
should the comparison function should take, either a pointer
to the insance of.

Sep 8 12:57,
    I think there are some room for optimization, with PMS
memory management practices, but the profiler function can only
be evaluated at runtime while running. I'll look into more for
compile time optimization practices.