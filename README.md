# ft_printf

## Description
`ft_printf` is a custom implementation of the standard C `printf` function, created as a project at 42 School. This function provides formatted output conversion and is designed to replicate the behavior of `printf` for specified formats.

## Features
This implementation of `ft_printf` supports the following format specifiers:
- `%c` - Character
- `%s` - String
- `%p` - Pointer address
- `%d` - Decimal integer
- `%i` - Integer
- `%u` - Unsigned decimal integer
- `%x` - Hexadecimal (lowercase)
- `%X` - Hexadecimal (uppercase)
- `%%` - Percent sign

## Usage
To use `ft_printf` in your project:

1. Compile `ft_printf` along with your project files. For example:
    ```bash
    cc main.c ft_printf.c -o my_program
    ```

2. In your code, simply call `ft_printf` as you would with `printf`:
    ```c
    ft_printf("Hello, %s! Your score is %d.\n", "User", 42);
    ```

## Example Output
```c
ft_printf("Character: %c\n", 'A');
ft_printf("String: %s\n", "Hello");
ft_printf("Pointer: %p\n", &variable);
ft_printf("Decimal: %d\n", 123);
ft_printf("Hexadecimal: %x\n", 255);
```
