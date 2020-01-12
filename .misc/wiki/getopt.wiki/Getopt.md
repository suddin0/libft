# Getopt

## Introduction
<br>

### What is [<getopt.h>](https://en.wikipedia.org/wiki/Getopt) and why does it exists.
<br>

#### Command line options
When a program is executed in a [command line interface](https://en.wikipedia.org/wiki/Command-line_interface) it might require some options for various reasons, for example when you are on your [terminal](https://en.wikipedia.org/wiki/Computer_terminal) and you want to list information of a particular directory, you do as such :
```bash
ls <directry name>
```
or to delete a particular file you do:
```bash
rm <-options> <file name>
```
And by providing options, you can change the behavior of those programs (or your own programs). 

<br>
<br>

#### Why do we need [<getopt.h>](https://en.wikipedia.org/wiki/Getopt)
[C](https://en.wikipedia.org/wiki/C_(programming_language)) is a pretty low level programming language even though when you compare to [Assembly](https://en.wikipedia.org/wiki/Assembly_language) you might say that [C](https://en.wikipedia.org/wiki/C_(programming_language)) handles a **lot** of things for us, just like when you compare [C](https://en.wikipedia.org/wiki/C_(programming_language)) to a higher level programming language such as  [Python](https://en.wikipedia.org/wiki/Python_(programming_language)) and you realize how [Python](https://en.wikipedia.org/wiki/Python_(programming_language)) handles so many things for us.

Many higher level languages or language [interpreters](https://en.wikipedia.org/wiki/Interpreter_(computing)) might sometime manage those arguments for you in some way, but in C you have to mange your own arguments. And the [getopt](https://en.wikipedia.org/wiki/Getopt) library exists to help you manage the command line options.

<br>
<br>
<br>

## Library details

The [<getopt.h>](https://en.wikipedia.org/wiki/Getopt)  library provides the following three functions.

| | Function name     |  Used for|
|-|-------------------|-----------|
|1| `getopt`          | Get **ONLY** **`short`** options          |
|2| `getopt_long`     | Get **`short`** **AND** **`long`** options|
|3| `getopt_long_only`| Get **ONLY** **`long`** options           |

<br>

##### External variables
Before we start talking about those functions we must first acknowledge that the following external variables exists:

| |Variable name | Used for |
|-|-----------------|-----------|
|1|`extern char *optarg`| Stores the argument's index|
|-|`-`| -| - |
|2|`extern int optind,`| Contains the value of the index of `argv` that is currently being parsed|
|3|`extern int opterr,`| If this variable is set to `0` then no error message will be printed.|
|4|`extern int optopt`| Contains the erroneous `option`|

---
<br/>
<br/>
<br/>

### `getopt`

#### Library:
```C
#include <unistd.h>
```

#### Prototype:
```C
int getopt(int argc, char * const argv[], const char *optstring);
```

#### Function arguments :
|| Argument | Description|
|-|-------------|----------|
|1|`argc`     | The same argument count that was passed to `main` function |
|2| `argv`    | The same argument list  that was passed to `main` function|
|3| `opstring`| The `options` you want it to parse (ex: `antl:`)|


#### Description:
`getot` function parses **short** command line options. An option is considered any element of `argv` that starts with an initial `-` and doesn't follows by either an other `-` *(because a single `--` is considered as the end of option parsing and if `--<something else>` followed by anything else then getopt will consider it as a **long** option)*.

So for example you can passe your options as following :
```bash
ls -l -rRt -a -d 
```
In this example the `-rRt` is considered as `-r`,  `-R` and `-t`. In other words you can put a sequence of option in the same string.
<br/>

##### How getopt is used:
We normally call *getopt* in a loop. here is an example :
```C
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int flags, opt;
	int nsecs, tfnd;

	nsecs = 0;
	tfnd = 0;
	flags = 0;
	while ((opt = getopt(argc, argv, "nt:")) != -1)
	{
		switch (opt)
		{
			case 'n':
				flags = 1;
				break;
			case 't':
				nsecs = atoi(optarg);
				tfnd = 1;
				break;
			default: /* '?' */
				fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n", argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n", flags, tfnd, nsecs, optind);

	if (optind >= argc)
	{
		fprintf(stderr, "Expected argument after options\n");
		exit(EXIT_FAILURE);
	}
	printf("name argument = %s\n", argv[optind]);
	/* Other code omitted */

	exit(EXIT_SUCCESS);
}
```
<br/>

#### The *getopt* in loop:
at each iteration of the loop *getopt* returns the particular option it encountered. so if we take our example of ls above, at first iteration, it will return the `char` **`l`**, then in the second iteration it  will return the `char` **`r`** then during the third iteration it will return **`R`** and so on.

<br/>
<br/><br/>

#### The variable **`optind`**:
*getopt* uses the variable **`optind`** to store the index of `argv` that is currently being parsed, as shown in the example of **ls** above, you can pass multiple options in the same `string` and as *getopt* parses each characters at a time it might stay in the same index of some amount of time, so at the first iteration the variable  **`optind`**  will contain **1** and *getopt* will return **`l`**  then during the second iteration the variable **`optind`**  will contain **2** as in the second index of `argv` there is only **1** option to parse  and *getopt* will return **r** and during the third iteration the variable **`optind`**  will still contain **2**  as after the option **r** there are still other options to parse and *getopt* will return **R** and once the whole string is parsed and all the options of this index is treated, *getopt* will go to the next index and update the variable **`optind`** . 

<br/>

*getopt* uses a static variable called **`nextchar`** where it stores the index of the *next `char`*, so if we take our example of **ls** above we see the third index of `argv` contains multiple options `rRt` in the same `string` which means that during 3 iteration of our loop where we called *getopt*, the variable **`optind`** contain the same value, but the static variable **`nextchar`** changes. So for example when *getopt* returns the option **r** the **`nextchar`** will contain **1** to indicate where *getopt* stopped the last time in the current string. This helps *getopt* continue parsing the current string from the same place that it left the last time.

<br/>
<br/>

#### More about the variable  **`optind`**:
By default  **`optind`** is initialized to 1 (because command line arguments starts at the index 1) and this variable is incremented as *getopt* parses the `options`. The caller can reset it to **1** to make getopt start rescanning of the the same `argv` or when scanning a new argument vector. 

getopt will return **-1** if there are no option characters and the variable **`optind`** will indicate the index of the first non option argument in `argv` and with this you can start treating arguments that are not options.

> **Trick question:** If setting the variable **`optind`** let *getopt* restart scanning from a certain point then does the static variable  **`optind`** set itself to **0** so that it can restart from the beginning of the string ? or it start from the last character where it stopped ?

<br/>
<br/>

#### options with parameters:
*getopt* handles options with parameter. A parameter in command line can be passed in 2 different formats. Here is an example with [GCC compiler](https://gcc.gnu.org/) where you indicate the `headers` directory (let's assume it's called `incluide` for the sake of the example)  to the compiler with the **gcc** compiler option **`-I`**.
<br/>

##### In multiple strings:
```bash
gcc main.c -I include -o myProgram
```

<br/>

##### In a single string:
```bash
gcc main.c -Iinclude -o myProgram
```
<br/>

In the first example we see that second argument is **`-I`** which indicates that we are indicating an `include directory`. The third argument is **`include`** indicating the directory where the compiler can search for `hearder` files.

In the second example we see that the second argument is **`-Iinclude`** where the option `-I` and the parameter of the option `include` is in the same string / same argument.

<br/>
<br/>

#### The variable `opstring`
The *getopt* function argument `opstring` is where we indicate what option is supported, so if the program accepts the following options `-l` `-D` `-n` then the  `opstring` will be `lDn`

```C
getopt(argc, argv, "lDn");
```
<br/>

To indicate that an option needs a parameter we must put a `:` (colon) **after** the option. If we want to indicate that the option `-D` needs a parameter we do as following:
<br/>
```C
getopt(argc, argv, "lD:n");
```
<br/>

Once we execute our *getopt* in a loop and we come to an option that requires a parameter then *getopt* will return the option, in our example it's `D`  and the variable `optarg` will point to the parameter of the option.
<br/>
Here is an example of how `optarg` works:
```C
#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv)
{
	int c = 0;

	while((c = getopt(argc, argv, "al:")) != -1)
		if(c == 'l')
			printf("Retrurn of getopt : %c = [%s]\n", c, optarg);
	return 0;
}
```

If you execute the above code snippet with the argument `-l` and a parameter `Hello`, you will see that the variable `optarg`  points to the the `string` `Hello`.
<br/>
> **Note**: If you are re coding this function, remember that there are **2** ways to indicate an option parameter, one is in 2 different strings (ex `-I include`) and the other one is in the same string (ex `-Iinclude`). If the parameter is in a different string then the variable `optarg` will point to that particular string else if the parameter is in the same string then the variable `optarg` will point to the index where the parameter starts (ex. for the following case `-Iinclude` the variable `optarg` will point to the **3**rd index of the string where the parameter `include` starts

<br/>
<br/>

You can specify an `optional` parameter with `::` (double colons). If we take our example above and we want to specify that the option `-D` takes an optional parameter then we will write as following:

```C
getopt(argc, argv, "lD::n");
```
> **NOTE**: Parameters that are optional must be in the same string as the option itself. Before the option `-D` needed a mandatory option , if no option was provided then *getopt* would have returned **-1**. Also you could write your option either in the same string (ex: `-D<param>`) or in 2 separate strings (ex: `-D <Param>`) **BUT** to indicate an **optional parameter** of an option you must write the parameter in the same string as your option (ex: `-D<param>`), if you use 2 separate string to indicate the parameter then the string that you used as parameter will **NOT** be considered as a parameter and treated as an option.



> **Warning**: The option `-W` in *getopt* is **reserved** by `POSIX.2` for implementation extensions. This option is used to indicate a long  option, so for example if you write `-W foo` then *getopt** will consider `foo` as a long option (ex : `--foo`).

<br/>
<br/>

#### The variable **`opterror`**:

*getopt* can encounter two different kind of errors while parsing arguments:

**1.** Encounter an option that was not specified in the argument `optstring`
**2.** No parameter passed for an option that requires a parameter.

- Generally *getopt* prints an error message on the standard error, put the `erroneus option character` in the variable `optopt` and returns the the `char` `?` as the function results.
- If the caller has set the *global variable* `opterr` to `0` (zero) then *getopt* will **NOT** print an error message. The caller can still determine if there was an error by verifying the return value of *getopt* (which will be `?`). By default the value of the variable `opterr` has a `non zero` value.
- If a `:` (colon) is present after the option `+` OR `-` (those options are described below), to indicate that a `parameter` is missing for an option that require a `parameter`, *getopt* returns `:` (colon) instead of `?` and will not print any **error message**. This way the caller can distinguish between different type of errors.

#### `argv` modification by *getopt*:
By default *getopt* **permutes** the content of `argv` in such a way that eventually all `non option` arguments are found at the end of the array. Lets say the initial `argv` array looked like this:
```
    ----------------------------------------------
   | ./myProg | -l | AA | BB | CC | -f | DD | -na |
    ----------------------------------------------
``` 
<br/>

And let's say that our `optstring` that we pass to *getopt* looks like this :

```C
getopt(argc, argv, "l:naf");
```
<br/>

Once *getopt* finishes scanning `argv` the array looks like this:

```
    ----------------------------------------------
   | ./myProg | -l | AA | -f | -na | BB | CC | DD |
    ----------------------------------------------
``` 
<br/>

You can see that anything that is not related to an option is put at the end of the array.
> **NOTE**: If you verify the address of each elements of the array `argv` you will notice that the strings of the elements are not **copied** but the elements changed the addresses where they ware  **`Pointing`** to before *getopt* scanned the array.

There are **2** other modes :

1. If a **`+`** is present at the beginning of the string `optstring` or the environment variable **`POSIXLY_CORRECT`** is set then *getopt* will stop immediately once it encounters a `non option argument`.  This option preserve the order of elements in the array `argv`
2. If a **`-`** is preset at the beginning  the string `optstring`  then any `non option argument` will be treated as option `parameters` and *getopt* will return the number `1` instead of returning an option `char` (because it didn't encountered an option `char`). This option also preserve the order of elements in the array `argv`

##### Example:
```
    _________________________
   | ./myProg |-l | NN | PP |
    -------------------------
```
<br/>

So if we see the above example and we consider the following options for *getopt* :
```C
getopt(argc, argv, "+l");
```

Then *getopt* will stop as soon as it encounter `NN` because the `+` is present in the beginning of `optstring`.

<br/>

And if we consider the following options for *getopt*:

```C
getopt(argc, argv, "-l");
```
For the `option` `l` *getopt* will return `l` and and once *getopt* encounters `NN` then *getopt* will return `1` and the variable `optarg` will point to the string `NN` and same for `PP`.
<br/>

This options help the caller have the order `argv` as it was given to *getopt* function. This is used by programs that were written to expect options and other argv-elements in any order and that care about  the ordering of the two.

<br/>
<br/>
<br/>

#### Return:
| Return value | Return Condition|
|--------------|-----------------|
|`option character`  | If an option character is encountered|
| -1 |  If *getopt* finished parsing all `options` in `argv` |
| `?` | If encountered an `option` `char` that was not specified in `optstring`|
| `:` | If the first character of `optstring` is `:` (colon)|

---
<br/>
<br/>
<br/>

### `getopt_long`
<br/>

#### Library:
```C
#include <getopt.h>
```
<br/>

#### Prototype:
```C
int getopt_long(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);
```
<br/>

#### Function arguments :
|| Argument | Description|
|-|-------------|----------|
|1|`argc`     | The same argument count that was passed to `main` function |
|2| `argv`    | The same argument list  that was passed to `main` function|
|3| `opstring`| The `options` you want it to parse (ex: `antl:`)|
|4| `longopts`| An array of **`option`** structure that contains all `long options`|
|5| `longindex`| Address of an int where `getopt_long` will store the index of `long parameter` in ``longopts``)|

<br/>
<br/>

#### Description:
`getopt_long` behave the same way as `getopt` but adds extra options. `getopt_long` not only parses **short** options **BUT** also **long** options.

<br/>

#### Long options:
A long option is considered an argument that starts with 2 `--` (colons) and followed bu something. For example `--file` is considered as a long option.

<br/>

#### Long option with parameters
Just like short option `parameters`, long options accepts `parameters` in 2 different ways:

<br/>

##### Single string parameter:
```sh
gcc --include=include/libft.h ...
```
<br/>

##### Multi string parameters:
```sh
gcc --include include/libft.h ...
```
<br/>

If you wish to use single string parameter then you must separate the parameter from the option by a **`=`**.

<br/>

#### How `getopt_long` is used:
`getopt_long` is used same way as `getopt`, in a loop. `getopt_long` require 2 extra parameters then `getopt` and those are:
- longopts
- longindex

#### *longopts* parameter:
`longopts` is a structure that looks as following:
```C
struct option
{
    const char *name;
    int         has_arg;
    int        *flag;
    int         val;
};
```

|Structure elements | Description|
|-------------------|---------|
| name    | Contain the long argument |
| has_arg | Indicates if this `option` accepts any arguments or not. Following `defines` are used to indicate if the option needs an arguments or not : [**`no_argument`**](https://github.com/lattera/glibc/blob/master/posix/bits/getopt_ext.h#L62) (or **0**) , [**`required_argument`**](https://github.com/lattera/glibc/blob/master/posix/bits/getopt_ext.h#L63) (or **1**), [**`optional_argument`**](https://github.com/lattera/glibc/blob/master/posix/bits/getopt_ext.h#L64) (or **2**) |
| flag    | Specifies how results are returned for `long options`. If `flag` is set to **`NULL`** then `getopt_long` will return `val`. You might set flag to `NULL` and val to a `option` character, this way  `getopt_long` will return the `option` character that is an alias to the `long option`. For example, let's say you accept a long option called `--output` and a short option equivalent to it `-o` which does the same as `--output`, then you might want to set `FLAG` to `NULL` and `val` to `o` so that `getopt_long` returns `o` when `getopt_long` encounters the option `--output` and you treat the `long option` `--output` the same way as `-o`. **If** `flag` is not `NULL` then the value of `val` will be stored to the address indicated to `flag` if the option is found else the address indicated to `flag` will remain unchanged and `getopt_long` will return `0`.|
| val    | is the value to return, or to load into the variable pointed to by flag. |

> **NOTE**: The last element of the array must be filled with `0` (indicating the end of the list)

<br>

Here is an example of how we use the structure:
```C
struct option long_options[] =
{
    {"add",     required_argument, 0,  0 },
    {"append",  no_argument,       0,  0 },
    {"delete",  required_argument, 0,  0 },
    {"verbose", no_argument,       0,  0 },
    {"create",  required_argument, 0, 'c'},
    {"file",    required_argument, 0,  0 },
    {0,         0,                 0,  0 }
};
```

<br>
<br>

#### *longindex* parameter:
The `longindex` contain the index of the matching long argument in the array of `struct option` . So if we consider the example of structure above and assume that a user executed a program with the long option `--delete` then the variable `longindex` will contain the value **`2`** as `delete` is at the third index of the array of structures.
<br>
<br>

#### Return:
Same as `getopt` in addition if `flag` is null then returns `val` else returns `0`.

---
<br>
<br>
<br>

### `getopt_long_only`
#### Library:
```C
#include <getopt.h>
```
<br>

#### Prototype:
```C
int getopt_long_only(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);
```
<br>


#### Description:
`getopt_long_only`  is like `getopt_long`, but `-` as well as `--` can indicate a long option.  If an option that starts with `-` (not `--`) doesn't match a long option, but does match a short option, it is parsed as a short option instead.
<br>

#### Return:
The same as `getopt_long`

---
<br>
<br>

## Resources

- https://linux.die.net/man/3/getopt
- https://www.gnu.org/software/libc/manual/html_node/Getopt.html
- https://en.wikipedia.org/wiki/Getopt
- https://code.woboq.org/userspace/glibc/posix/getopt.c.html
