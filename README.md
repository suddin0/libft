![Project header logo](.misc/images/libft_header.png)

## Description

**Libft** is a [42](https://en.wikipedia.org/wiki/42_(school)) project. The goal of this project is to create a [static library](https://en.wikipedia.org/wiki/Static_library) (c library) that will be used during the [42](https://en.wikipedia.org/wiki/42_(school)) course. **Libft** is meant to be similar to [libc](https://en.wikipedia.org/wiki/C_standard_library) library, where many different type of function are included to help with other `projects`.  To know more about `libft` **`api`** refer to the [wiki](https://github.com/suddin0/libft/wiki) section.

## Build the library

**Libft** is a static `C` library. A [`makefile`](https://fr.wikipedia.org/wiki/GNU_Make) is included to build the project. The follwing recipe can be used:

|recipe | Description|
|--------|-----------|
|all| Creates the library |
|clean| Remove all generated [object](https://en.wikipedia.org/wiki/Object_file) files|
|fclean| Calls the `clean` recipe and remove the [library]() file|
|re | Calls the `fclean` recipe and `all` recipe (recompile the library|

Once the compilation is finished a file called `libft.a` will be created in the directory `lib`

## Header files.

Current version of `libft` contains function from following libraries and each of them has their own header (`.h`) files:

|Library name| header file| status|
|--------------|-----|------------|
|`libft`| **libft.h**| finished |
|[printf](https://en.wikipedia.org/wiki/Printf_format_string)| **ft_printf.h**| finished|
|[getopt](https://en.wikipedia.org/wiki/Getopt)| **ft_getopt.h** | unfinished |
|`string` (not the standard ***strings.h***)|**ft_string.h** | unfinished|

## Including `libft` to a project

The library (`.a`) file is created in **`lib/`** directory and the header (`.h`) files can be found in the `include/` directory.

Assuming you have cloned the project (libft) to the root directory of your project. To use the libft on the project you would use as following

```bash
## before you do the following you must create the `libft.a`
## file in the libft project

cc -I libft/include -L libft/lib -lft <your source / object files> -o <output file>
```

## More information.
### For more information about about all the libraries and their api refer to the  [wiki](https://github.com/suddin0/libft/wiki) section.
