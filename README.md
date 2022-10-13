## Introduction
<p align="Left">
  -> A Custom shell written in C language, supporting four internal and 5 external library commands<br> with Multithreaded and Multiprocessor Options. 
  <br> -> Use of standard C libraries, including Linux system calls such as
fork(),exec() family system calls and wait() family of system calls.
  <br><br>
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

CST_Shell ASH (Version 1.1)

cd optional arguments:
  -h, --help            show this help
  -v, --verbose         display information regarding changes
  -f,                   force changes
pwd optional arguments:
  -h, --help            show this help
  -L, --cwd             print the value of $PWD if it names the current working directory
  -P, --physical        print the physical directory, without any symbolic links
ls optional arguments:
  -h, --help            show this help
  -d, --directory       list directories themselves, not their contents
  -a, --all             do not ignore entries starting with .
echo optional arguments:
  -h, --help            show this help
  -n,                   do not output the trailing new line
  -v, --verbose         Describe each event as it occurs
cat optional arguments:
  -h, --help            show this help
  -E, --show-ends       display $ at end of each line
  -n, --number          number all output lines
date optional arguments:
  -h, --help            show this help
  -t, --show-time       display only time
  -d, --show-date       display only date
rm optional arguments:
  -h, --help            show this help
  -f, --force           ignore nonexistent files and arguments, never prompt
  -v, --verbos          Explain what is being done
mkdir optional arguments:
  -h, --help            show this help
  -p, --parents         no error if existing, make parent directories as needed
  -v, --verbos          Explain what is being done
 ```
## License

MIT © Arnav Gupta 2022<br/>
Original Creator - [Arnav Gupta](https://github.com/arnavgupta2003)

## Contributors
<a href = "https://github.com/Tanu-N-Prabhu/Python/graphs/contributors">
  <img src = "https://contrib.rocks/image?repo = arnavgupta2003/Custom_Shell_1"/>
</a>

