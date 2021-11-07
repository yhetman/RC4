# RC4
Implementation of stream cipher RC4
# kalyna


### Benchmarks

|      Standart    |     1 MB    |    10 MB    |   100 MB   |    1 GB        |
|       :---:      |    :----:   |     :---:   |     :--:   |    :---:       | 
|        RC4       |   0m0.033s  |   0m0.312s  |  0m3.283s  |   0m34.134s    |



### Compiling


```
git clone https://github.com/yhetman/RC4
cd RC4
make
```

To reocompile the code use:

```
make re
```

### Usage

```
./rc4 -i /path/input -o /path/output -k /path/key -e | -d
```

Several flags are available:
`-e` - to start encrypting process (is used by default);
`-d` - to start dencrypting process;
`-h` - display help message.
