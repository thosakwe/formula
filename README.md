# formula
Scientific formula parser + balancer. This program is a simple REPL.

# Building
Using CMake:

```bash
cmake . --build --target formula
```

# Grammar
Whitespace characters are ignored, of course.

```ebnf
equation = formula, "->", formula;
formula = [term, "+"], term;
term = [number], {term_member};

term_member =
    compound
    | element
    | ("(", term_member, ")")
;

compound = {element};
element = upper, [{lower}], [number];

number = ? all digits, from 0-10 ?;
upper = ? all uppercase letters ?;
lower = ? all lowercase letters ?;
```

# Examples
```
2H2 + O2 -> 2H2O
```
