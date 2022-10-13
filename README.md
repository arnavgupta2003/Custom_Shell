<H1 align = "center"> Custom Shell </H1>

## Introduction
<p align="Left">
  -> A Custom shell written in C language, supporting four internal and 5 external library commands<br> with Multithreaded and Multiprocessor Options. 
  <br> -> Use of standard C libraries, including Linux system calls such as
fork(),exec() family system calls and wait() family of system calls.
  <br>
</p>

## `Internal Commands Supported`
  <ul>
  <li>pwd</li>
   <li>cd</li>
   <li>echo</li>
  </ul>
  
## `External Commands Supported`
<ul>
  <li>ls</li>
   <li>cat</li>
   <li>date</li>
  <li>rm</li>
  <li>mkdir</li>
  </ul>

## Installation

```console
# clone the repo
$> git clone https://github.com/Custom_Shell_1.git

# change the working directory to src
$> cd src

# run the makefile
$> make -f MakeFile
       OR
$> make
```

## Usage

```console
$ [COMMAND] -h
Available commands.
      cd 
      pwd
      ls
      echo
      cat
      date
      rm
      mkdir
```
CST_Shell ASH (Version 1.1)

```console
cd optional arguments:
  -h, --help            show this help
  -v, --verbose         display information regarding changes
  -f,                   force changes
```
```console
pwd optional arguments:
  -h, --help            show this help
  -L, --cwd             print the value of $PWD if it names the current working directory
  -P, --physical        print the physical directory, without any symbolic links
```
```console
ls optional arguments:
  -h, --help            show this help
  -d, --directory       list directories themselves, not their contents
  -a, --all             do not ignore entries starting with .
```
```console
echo optional arguments:
  -h, --help            show this help
  -n,                   do not output the trailing new line
  -v, --verbose         Describe each event as it occurs
```
```console
cat optional arguments:
  -h, --help            show this help
  -E, --show-ends       display $ at end of each line
  -n, --number          number all output lines
```
```console
date optional arguments:
  -h, --help            show this help
  -t, --show-time       display only time
  -d, --show-date       display only date
```
```console
rm optional arguments:
  -h, --help            show this help
  -f, --force           ignore nonexistent files and arguments, never prompt
  -v, --verbos          Explain what is being done
```
```console
mkdir optional arguments:
  -h, --help            show this help
  -p, --parents         no error if existing, make parent directories as needed
  -v, --verbos          Explain what is being done
 ```
## License

MIT © Arnav Gupta 2022<br/>
Original Creator - [Arnav Gupta](https://github.com/arnavgupta2003)
<br><br>
MIT License

Copyright (c) 2022 Arnav Gupta

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
<br>


```console
EOF
```
