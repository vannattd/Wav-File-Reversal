#include <stdio.h>
#include <stdlib.h>
/*****************************************************************
This file holds the functions we use to read the file we want to
manipulate and write the new data to.
@author Dylan Vannatter
@version Winter 2020
*****************************************************************/ 
size_t read_file(char* filename, char** buffer);
size_t write_file(char* filename, char* buffer, size_t size);
