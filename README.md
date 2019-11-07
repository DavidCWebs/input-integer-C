Integer Input on Stdin in C
===========================
Learning notes and exercises on integer input in C.

There are probably lots of better ways to achieve this!

Objective: Get an Integer From Stdin
------------------------------------
At first glance, `scanf()` looks like a reasonable way to collect integer input. The function allows formatted input to be collected (it's name comes from the words "scan formatted").

To scan integer input, first declare an integer and pass a pointer to this to scanf:

```c
int input;
scanf("%d", &input);
```

However, because stdin is inherently unconstrained (users can type anything), `scanf()` [may not be the best choice][2]. You need to handle whitespace characters appropriately as well as clearing the input stream for subsequent input because `scanf()` doesn't read newlines.

Note that `fscanf()` which scans a `FILE` stream and `sscanf()` which scans a string are rational and useful choices because they operate on structured data.

fgets: Read the Entire Line
---------------------------
It may be better to read the whole line using `fgets()`, and then process the input as required:

* Use `fgets()` to read an entire line of stdin within a while loop.
* Check the length of the input buffer - even though `fgets()` discards extra input, the user should be informed if input has exceeded available space and allowed to re-enter the data.
* Convert input to an integer using `strtol()`.
* If input meets the length constraint and can be interpreted as an integer, the loop ends.


Example: Read Integer
---------------------
See [integer-input.h](integer-input.h) in this repo.

C++
---
Example for integer input in C++:

```c++
#include <iostream>
#include <typeinfo>
#include <limits>

int main()
{
	int input = 0;
	while (1) {
		std::cout << "Enter an int:\n";
	
		// Enter this block if taking input from cin has failed.
		if (!(std::cin >> input)) {
	
			// The error flag is set on std::cin - future attempts to
			// get input will fail unless the error is cleared.
			std::cin.clear();

			// The failed input is in the input buffer. The default for `ignore` is
			// to skip a single character. To be sure, remove the max streamsize
			// number of chars up until a newline is encountered
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}
	std::cout << "You entered: " << input << '\n';
	return 0;
}
```

References
----------
* [scanf() leaves newline in buffer][1]
* [Concise description][2] of `fgets()` vs `scanf()` (TLDR; use `fgets()`)
* [comp.lang.c list][3] - `scanf()` problems re: stdin
* [`scanf()` and whitespace][4]
* [Clean & compact description of `fgets()` and `strtol()`][5]

[1]: https://www.geeksforgeeks.org/problem-with-scanf-when-there-is-fgetsgetsscanf-after-it/
[2]: https://stackoverflow.com/a/3302594/3590673
[3]: http://c-faq.com/stdio/scanfprobs.html
[4]: http://c-faq.com/stdio/scanfhang.html
[5]: https://stackoverflow.com/a/26583890/3590673
