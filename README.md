# CMake with generator example

This repository features how to use CMake to generate source from some definition files and have the generated source depend on the definition files.
This particular example uses C++ as the language, but the concept is the same for any language, so dig in!

## Example

The generator in this example takes a file and generates a C++ class with the same name as the file (except for extension). The generated C++ class offers a single method: To "speak" out the content of the definition file. For example the definition file `yoda.speak` containing

```text
Do or do not. There is no try
```

will result in a `Yoda.h` and `Yoda.cpp` containing the following

```c++
#ifndef YODA_H
#define YODA_H

class Yoda
{
    public:
        void speak() const;
};

#endif /* YODA_H */
```

and

```c++
#include "Yoda.h"
#include <stdio.h>

void Yoda::speak() const
{
    printf("Do or do not. There is no try\n");
}
```

Of course this is a naive generator, but it is sufficient for this example. The generated files are put in a folder named `speakers_generated_during_build` in the build tree and can be used like this

```c++
#include <speakers_generated_during_build/Yoda.h>

int main(int, char**)
{
    Yoda yoda;
    yoda.speak();
}
```

## Reading guide

To ease the learning curve, there are three examples in this repository
  1. super-simple
  2. as-a-macro
  3. list-and-destination-variable-name

and they should be studied in that order.

### super-simple
Hardcodes everything and focuses on how to actually run a generator and integrate the result in a build.

### as-a-macro
Wraps the code generation in a macro, but several things are still hardcoded. Still, while being a macro and polluting the variable scope, this solution allows to reuse the code and add more than one speaker.

### list-and-destination-variable-name
In this example, the macro is transformed into a function taking a list of sources and the name of a destination variable to store the list of generated sources in.

Experienced CMake users will frown upon the loop and there are most likely better ways to implement this, but the repository works and I am happy.

# Enjoy!