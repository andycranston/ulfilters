# ulfilters

UNIX / Linux filter programs - if you can replace any of them with a
sed/awk/...other pipe then let me know :-]

Seriously I am sure some of these C filter style programs can be replaced
with a shell pipe solution with standard tools like sed and awk so please
let me know.  People (including me!) may be in a situation when compiling
our own filter solution is not possible so a shell alternative will be
most welcome.

## The filters

They (currently) are:

### csvfold

Read two or more lines of stdin and output CSV format.

### linefold

Read two or more lines of stdin and output those lines joined together.

### linesafter

Read lines from stdin until a line contains a specified string and then output
the rest of the lines.

### linesbefore

Read lines from stdin and output them unless the line contains a specified
string. When/if the line with that specified string is read then stop.

### unfind

My favourite - the oldest bit of my code ever published on the Internet - see, it's right here:

[A pipe by Andy Cranston to remove name files and directories from stdin](http://www.lovelady.com/unixsrc/#unfind)

High five Dennis :-]

## More detail

OK below is more detail on using each of these filters.

First though a note that all the filters are standalone C programs so can
they be compiled with a single run of your C compiler.  For example to
compile the `unfind` filter on a Linux system you would do something like:

```
gcc -o unfind unfind.c
cp unfind $HOME/bin/unfind
chmod u=rwx,go=rx $HOME/bin/unfind
```

Do whatever you need for your system and environment.

### csvfold

Input is:

```

```



zzz

### linefold

zzz

### linesafter

zzz

### linesbefore

zzz

### unfind

zzz

-------------------------------------------------------------

End of file
