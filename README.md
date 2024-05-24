# ft_printf

Write a library that contains ft_printf(), a
function that will mimic the original printf()

The task was quite straightforward, so the implementation was simple. Despite the simplicity, memory management was challenging, especially ensuring there are no leaks if the file descriptor returns an error midway through the program.

The bonus part required managing multiple file descriptors with a single static variable. The implementation was straightforward as I assumed there could be a maximum number of open file descriptors at once, so I used a static array of integers.

## Installation

Clone this repository and use the Makefile to compile the project:
```
git clone https://github.com/djelacik/ft_printf
```
Compile the project using the included Makefile:
```
cd ft_printf
make
```

## Usage

The ft_printf function can be used similarly to the standard printf. Here is an example of how to use it:

```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s!\n", "world");

    //Bonus part included flags '-0 ' & '# +'

    int number = -42;

    ft_printf("Default: %d\n", number); //Hello, world!
    ft_printf("Plus flag: %+d\n", number); // -42
    ft_printf("Space flag: % d\n", number); // -42
    ft_printf("Zero padding: %010d\n", number); // -42
    ft_printf("Left-justify with space padding: %-10dEnd\n", number); // -42       End
    ft_printf("Alternate form (hex): %#x\n", number); //0xffffffd6
    ft_printf("Multiple flags: %#4.8x\n", number); // -00000042
    return 0;
}

```

## Contributing

Don't copy the code as it is. Pdf of instructions is provided in the repo, so you can try writing your own code.

## Test your function

To test your ft_printf, you can use the following tester:
```
git clone https://github.com/xicodomingues/francinette
```
You can run the tester with following command:
`francinette`

Or for more rigorous tests which tests memory leaks:
`francinette -strict`
## Norminette

42 network schools need to follow the Norm, which provides rules for writing your code. The Norm will be provided in the repo. If you wish to write code like a real 42 student, you can download Norminette on your own computer:
```
https://github.com/42School/norminette
```
You can run Norminette with following command:
`norminette`

## License

This project is licensed under the MIT License
