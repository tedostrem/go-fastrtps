# Go-FastRTPS

Golang bindings for eProsima FastRTPS.
Will generate golang bindings for publishers and subscribers out of *.idl files.


## Usage:
Will generate a debian package that can be installed containing header files
and a dynamic library to link your Go application against.

```
$ git clone https://github.com/tedostrem/go-fastrtps.git
$ cd go-fastrtps/fastrtps
$ cp <your .idl files> .
$ make
```

See example folder how to integrate with a Go application.
