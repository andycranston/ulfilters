# ulfilters

A range of UNIX/Linux filter programs written in C.

They are:

+ chars - display a count of each character that appears in stdin.

+ csvfold - read two or more lines of stdin and output in CSV format.

+ linefold - read two or more lines of stdin and output those lines joined together.

+ linesafter - read lines from stdin and when a line contains a specified string output the rest of the lines.

+ linesbefore - read lines from stdin and output them until the line contains a specified string.

+ trimws - read lines from stdin, remove any leading and trailing white space and then output them.

+ unfind - remove lines that match a path name and all subdirectories below that path name.

## Compiling

Use the make file as follows:

```
make
make userinstall
```

The `make` command compiles to the current directory.  The `make
userinstall` copies the compiled filters to `$HOME/bin`.

## More details

The following sections have more details for each filter program.

## chars

Input `file.txt`:

```
hello
```

Command line:

```
cat file.txt | chars
```

Output:

```
  10  \n 1
 101  e  1
 104  h  1
 108  l  2
 111  o  1
```

## csvfold

Input file `file.txt`:

```
7
Apple
Shop
10
Pear
Supermarket
25
Pineapple
Greengrocer
```

Command line:

```
cat file.txt | csvfold 3
```

Output:

```
"7","Apple","Shop"
"10","Pear","Supermarket"
"25","Pineapple","Greengrocer"
```

## linefold

Input file `file.txt`:

```
7
Apple
Shop
10
Pear
Supermarket
25
Pineapple
Greengrocer
```

Command line:

```
cat file.txt | linefold -n 3
```

Output:

```
7 Apple Shop
10 Pear Supermarket
25 Pineapple Greengrocer
```

Command line:

```
cat file.txt | linefold -n 3 -d :
```

Output:

```
7:Apple:Shop
10:Pear:Supermarket
25:Pineapple:Greengrocer
```

## linesafter

Input file `file.txt`:

```
Tree
Flower
Daisy
Bush
Grass
Barley
Thistle
```

Command line:

```
cat file.txt | linesafter Bush
```

Output:

```
Grass
Barley
Thistle
```

## linesbefore

Input file `file.txt`:

```
Tree
Flower
Daisy
Bush
Grass
Barley
Thistle
```

Command line:

```
cat file.txt | linesbefore Bush
```

Output:

```
Grass
Barley
Thistle
```

## trimws

Input file `file.txt`:

```
Tree
 Flower
	Daisy
        Bush
Grass
    Barley
Thistle
```

Command line:

```
cat file.txt | trimws
```

Output:

```
Tree
Flower
Daisy
Bush
Grass
Barley
Thistle
```

## unfind

Input file `file.txt`:

```
dir1
dir1/foo
dir1/stuff
dir2
dir2/filea
dir2/fileb
dir2/filec
file
exclude
```

Command line:

```
cat file.txt | unfind dir1 dir2/fileb exclude
```

Output:

```
dir2
dir2/filea
dir2/filec
file
```

-------------------------------------------------------------

End of file
