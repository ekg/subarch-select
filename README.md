# subarch-select

Pick an executable based on CPU capabilities.

## usage

Call `subarch-select` with argument pairs that list CPU features (as in /proc/cpuinfo "flags"), and a path to execute if the flags are all matched.
The first set of flags that match the system capabilities will select the given path.
Arguments to the program should be passed after `--`.

```
Usage: subarch-select [features] [path] ... [--] [program arguments]
Example: subarch-select avx2,sse4_2 /path/to/program-avx2 avx,sse2 /path/to/program-avx -- --arg1 --arg2 --arg3
```

## compilation

`make`

## dependencies

Google's [cpu_features](https://github.com/google/cpu_features/) library.
This is `libcpu-features-dev` on Debian/Ubuntu systems.

## author

Erik Garrison <erik.garrison@gmail.com>
Michael R. Crusoe <crusoe@debian.org>
