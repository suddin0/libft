# Build and library usage

**ft_getopt** uses many functions from `libft` and a function from `ft_printf_err`. `ft_getopt` do not contain `libft` nor `ft_printf_err` thus **you** must provide them.

If you look at the `Makefile` you will find the following variables:
```Makefile
# All LIB_FT stufs
LIBFT		?= $(P_LIB)/libft
LIBFT_INC	?= $(LIBFT)/include
LIBFT_LIB	?= $(LIBFT)/lib
LIBFT_A		?= $(LIBFT_LIB)/libft.a
FT_PRINTF_ERR_A	?= $(LIBFT_LIB)/libftprintferr.a
```

`libft` directory. In my case i have the following directory structure
```text
libft
├── include
├── lib
├── obj
└── src
    ├── ft_printf
    └── ft_printf_err
```
> Note:  As you can see `ft_printf` and `ft_printf_err` is part of `libft` in my case.

In my directory structure
- all`header` files are found in the directory **include**
- all source file are found in the directory **src** (some are organized on different directories such as  `ft_printf` and `ft_printf_err`)
- all objects compiled are found in the directory **obj**
- and all library files (***.a** files (ex: **libft.a**, **libprintf.a**) are found in the directory **lib**

The goal of this introduction to my **libft** directory structure is to show you how the libft path works in **my** **Makefile** so you can adapt to yours.

In my case all i have to do is to specify the path to **libft** and other variables are initialized depending on **that** part **BUT** you might have to specify more then just the path to your **libft**

If your structure is different then mine then do remember to specify the following paths:
- Path to your **libft** header files to the variable `LIBFT_INC`
- path to your **libft** libraries to the variable `LIBFT_A`
- path to your **ft_printf_error** libraries to the variable `FT_PRINTF_ERR_A`

In the **Makefile** you will also find the following variable
```Makefile
INC_LIB = -I $(P_INCLUDE) -I $(LIBFT_INC) -L $(LIBFT_LIB) -lft -lftprintferr
```

This variable is used to compile the library. Here you can specify your own libraries if you decide to add your own, such as a replacement for `ft_printf_err`.

## Build
to compile **getopt**:
```bash
# Here you specify the path to your libft library to the variable `LIBFT`
make LIBFT=$PWD/libft
```

## Library usage
link **getopt** to your project
```bash
# We assume you have the `getopt` library in a directory called `lib`
cc -I lib/getopt/include -L lib/getopt/lib -lgetopt $SRC
```
