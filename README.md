# Theory of Algorithms project 

Implement the MD5 message-digest algorithm 

## Getting Started
This repo contains the MD5 message-digest algorithm fully implemented in the C language

### Prerequisites

You will need the following: </br>

1. A C compiler installed on your machine to run the code.</br>
2. An intermediate level knowlege of C.</br>
3. An understanding of how and why the MD5 message-digest algorithm works. </br>


For MacOs and other unix operating systems. My system is MacOS so this is what I used to check that the c compiler is installed.
```
gcc --version 
```

### Installing
Just clone this repository using git or else download the zip file.

```
git clone https://github.com/ross39/Theory-of-algorithms-project
```

## Deployment

Deployment of this is very simple. Just clone the repo and compile it using the command

```
gcc -o md5 -O3 -lm md5.c
```

Then you can run it one of two ways. To run it on a single piece of text you can use 

```
./MD5 xxxxx  => where xxxxx is the text you want to hash
```

or you can give it a text file.

```
./MD5 xxxxx.txt => where xxxxx.txt is the name of your text file
```

## Built With





## Versioning
Using git 
## Authors

* **Ross Heaney** 

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments and Refrences


