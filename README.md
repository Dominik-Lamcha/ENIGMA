# Enigma Machine Simulator in C++
## Overview
This is a C++ implementation of the Enigma machine, a cipher device used for the encryption and decryption of secret messages. The Enigma machine was most famously used by Germany during World War II.

## Brief History of the Enigma Machine
The Enigma machine was invented by the German engineer Arthur Scherbius at the end of World War I. Initially designed for commercial use, it was adopted by the military and government of several countries. The machine's settings offered 150 million possible combinations, making it an incredibly secure method of communication at the time. However, it was eventually broken by Polish and British cryptanalysts, with Alan Turing playing a significant role in the decryption efforts. The breaking of the Enigma code was a turning point in World War II and is considered one of the earliest successes of computer science.

## Features

- Simulates the rotor and reflector mechanics of the Enigma machine
- Configurable rotor and reflector settings
- Turnover and notch settings for rotors
- more coming

## Original Enigma settings

### Rotor settings
| Rotor #  | ABCDEFGHIJKLMNOPQRSTUVWXYZ | Notch | Turnover |  Date Introduced |
|:--------:|:--------------------------:|:-----:|:--------:|------------------|
| I        | EKMFLGDQVZNTOWYHXUSPAIBRCJ |   Y   |    Q     | 1930             |
| II       | AJDKSIRUXBLHWTMCQGZNPYFVOE |   M   |    E     | 1930             |
| III      | BDFHJLCPRTXVZNYEIWGAKMUSQO |   D   |    V     | 1930             |
| IV       | ESOVPZJAYQUIRHXLNFTGKDCMWB |   R   |    J     | December 1938    |
| V        | VZBRGITYUPSDNHLXAWMJQOFECK |   H   |    Z     | December 1938    |
| VI       | JPGVOUMFYQBENHZRDKASXLICTW |  HU   |    ZM    | 1939             |
| VII      | NZJHGRCXMYSWBOUFAIVLPEKQDT |  HU   |    ZM    | 1939             |
| VIII     | FKQHTLXOCBJSPDZRAMEWNIUYGV |  HU   |    ZM    | 1939             |

### Reflecor settings
| Reflector #  | ABCDEFGHIJKLMNOPQRSTUVWXYZ |  Date Introduced |
|:------------:|:--------------------------:|------------------|
| UKW-A        | EJMZALYXVBWFCRQUONTSPIKHGD | 1930             |
| UKW-B        | YRUHQSLDPXNGOKMIEBFZCWVJAT | 1930             |
| UKW-C        | FVPJIAOYEDRZXWGCTKUQSBNMHL | 1930             |

## Testing

This project includes a suite of tests implemented using Google Test.

To run the tests:

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./TestExecutable
```

## Contributing

Feel free to contribute to this project by opening issues or submitting pull requests.
