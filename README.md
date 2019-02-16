# Keylogger
A program that will track and log all the keystrokes of a user on a system.

## Requirements

### The included header files
```
#include <linux/input.h>
#include <sys/stat.h>
```

### Run Requirements
- Bash
- C
- keylogger folder must be placed on the Destop for *startsystemd.sh* to run properly
- startsystemd.sh must be run with UID 0 (sudo or root).

```
make
sudo ./startsysemd.sh
```

## Author
[Jonathan Jang](http://github.com/jwj3767)

## License
This project is licensed under the MIT License - see the [LICENSE.md](LINK HERE) file for details
