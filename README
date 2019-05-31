# Instruction

```
$ svn checkout https://svn.code.sf.net/p/lame/svn/trunk/lame lame-svn 
$ cd lame-svn
$ ./configure
$ make
$ cd ..
$ clang++ fuzzer-encoder.cpp -I fuzzing-headers/include/ -I lame-svn/include/ lame-svn/libmp3lame/.libs/libmp3lame.a -ldeepstate -o LAME
```
