# Languages • Chapter 5

Online read link: https://buildyourownlisp.com/chapter5_languages

### First question: Write down some more examples of strings the Doge language contains.

### Question 2: Why are there back slashes \ in front of the quote marks " in the grammar?

Because quote marks `"` is special character, so it need to have back slashes `\` before quote to make sure the language understands that it literally a quote

### Question 3: Why are there back slashes \ at the end of the line in the grammar?

It use for break a line, allow we define it in mutiple lines -> Better to see

### Question 4: Describe textually a grammar for decimal numbers such as 0.01 or 52.221.

```ruby
number = /[0-9]+/ # Number in range from 0 to 9
floating_point = /./ # Floating point dot
decimal_numbers ~ <number><floating_point><number> # Grammar for decimal numbers
```

### Question 5: Describe textually a grammar for web URLs such as http://www.buildyourownlisp.com.

```ruby
protocol = /(http|https)/ # Web protocol: http or https
world_wide_web = /www/ 
your_domain = /buildyourownlisp/
domain_extensions = /com/
url ~ <protocol>://<world_wide_web>.<your_domain>.<domain_extensions> # Web url grammar
```

### Question 6: Describe textually a grammar for simple English sentences such as the cat sat on the mat.

`the cat sat on the mat` ~ Is a complete sentence

In `the cat sat on the mat` 

- `the cat` is a **subj**, `the` is a **art** (art caan be `the`, `a` or `an`)
- `sat on` is a **verb**
- `the mat` is a **obj**
 
### Question 7: Describe more formally the above grammars. Use |, *, or any symbols of your own invention.

```
<sentence>  ::= <subj> <verb> <obj>
<subj>      ::= <art> <noun>
<art>       ::= the | a | an
<noun>      ::= dog | cat | man | women | *     // Any noun
<verb>      ::= *                               // Any verb
<obj>       ::= <art> <noun>
```

### Question 8: If you are familiar with JSON, textually describe a grammar for it.

JSON data is written as name/value pairs (aka key/value pairs).

In JSON, **keys must be strings**, written with double quotes

In JSON, values must be one of the following data types:
- a string
- a number
- an object (Wrap with `{}`)
- an array (Wrap with `[]`)
- a boolean (`True` or `False`)
- null