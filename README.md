# Note before use

This is a port of my own Ruby version of this code, hosted at http://github.com/cpowell/fuzzy-associative-memory. This is something of a work in progress while I explore the platform-specific compilation and packaging requirements (something one doesn't worry about in Ruby).

Currently the code and examples run under Mac OS X 10.8. Support for other platforms (e.g. Linux) is in the works.

# Fuzzy logic "Fuzzy Associative Memory"

A Fuzzy Associative Memory (FAM for short) is a Fuzzy Logic tool for decision
making. Fuzzy logic FAMs have a wide range of practical applications:

* Control systems, such as governing a fan to keep a room at the "just right" temperature
* Game AI, such as imbuing bots with human-like decision-making behavior
* Prediction systems, linking causes with effects

## How it works

A Fuzzy Associative Memory uses Fuzzy Sets to establish a set of rules that are linguistic in nature; examples might include:

* "If the room is a bit warm, turn the fan up a little bit"
* "If the orc's hit points are a little low, retreat from the enemy"
* "If the enemy is distant and my rocket ammo is low, the rocket launcher is a poor choice"
* "If the enemy is near and my shotgun ammo is okay, the shotgun is a very desirable choice"
* "If the ship is off course by a little bit, correct just a little to the right"
* "If the bird is much slower than the flock, speed it up a lot"

The linguistic rules, and the fuzzy sets they contain, are defined by a human "expert" (presumably, you). That is to say,
the rules *codify intelligence* and map this knowledge from the human domain to the digital.

After the rules are defined, a FAM is consulted to help your AI make a descision:
* The orc retreats, attacks, strafes.
* The ship launches long range missiles or fires short range guns.
* The control rods are lowered into the reactor or raised out of it.

As you can see, the fuzzy rules are deliberately vague and use qualifiers like "a little" and "a lot". Furthermore, the lines
between fuzzy sets are intentionally blurry. This is the nature of fuzzy sets; they capture such human fuzziness in a way that extracts highly natural behavior from the fuzzy rules.
When defining these rules, it helps to imagine interviewing a bona fide expert in the domain and writing down the skills necessary to be successful in the domain.

## Project status

This is working, functional software, suitable for use in your own game or application. It currently supports:
* Triangular & trapezoidal fuzzy sets for input/output
* Larsen Implication (scaling)
* Mamdani Implication (clipping)
* Atomic antecedent propositions (`if A then Z`)
* Composite antecedent propositions (`if A or B, then Z` / `if A and B, then Z`)

To do (in descending importance, roughly):
* Parameter validations to prevent bad shapes, improper FAM layout, etc.
* Other shapes for fuzzy sets
* Hedges ('very' and 'fairly')
* Additional examples

Watch the [changelog](http://github.com/cpowell/fuzzy-associative-memory-cplusplus/blob/master/CHANGELOG.md) for news.

## Building
You can open the package in XCode and build it that way. Targets aready exist for the library and the examples.

You can use cmake as follows:
```mkdir build && cd build && cmake .. && make```

You can use cmake + ninja as follows:
```mkdir build && cd build && cmake .. -GNinja && ninja```

(Ninja is a nice, new build tool from Google but 'old-school' make works just fine too.)

I recommend that you set your CXX environment variable appropriately; it will be used automatically during build. Mine is:
```export CXX=clang++-3.3 -std=c++11 -stdlib=libc++ -I/usr/local/lib/llvm-3.3/lib/c++/v1```

## Included examples

The source code contains the following examples:
* `hvac_example` illustrates how a FAM could govern an HVAC fan unit to maintain a constant, comfortable temperature
* `weapon_example` illustrates how a FAM could let a game bot intelligently decide which weapon to use

## References used in the creation of this software
* "Fuzzy Thinking: The New Science of Fuzzy Logic" by Bart Kosko [(Amazon link)](http://www.amazon.com/Fuzzy-Thinking-New-Science-Logic/dp/0006547133/)
* "Fuzzy Logic: The Revolutionary Computer Technology that is Changing the World" by Daniel McNeill & Paul Freiberger [(Amazon link)](http://www.amazon.com/Fuzzy-Logic-Revolutionary-Computer-Technology/dp/0671875353/)
* "Fuzzy Logic in Decision Making and Signal Processing" by Sujit Nath Pant & Keith E. Holbert [(Link)](http://enpub.fulton.asu.edu/powerzone/fuzzylogic/index.htm)
* "Programming Game AI by Example" by Mat Buckland [(Amazon link)](http://www.amazon.com/Programming-Game-Example-Mat-Buckland/dp/1556220782)


[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/cpowell/fuzzy-associative-memory-cplusplus/trend.png)](https://bitdeli.com/free "Bitdeli Badge")

