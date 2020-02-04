#include "wav.h"
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
/*****************************************************************
This function takes a char* and passes it into our custom 
strucutre wav_file. We then malloc memeory for our file 
and pass in the first 44 bytes(header) of the wav file.
Then, we pass in our song bytes in and return the filled struct.
@param contents the file we are parsing into the wav_file struct.
*****************************************************************/ 
wav_file* parse(char* contents){
wav_file* file;
//making room in memory for the size of a wav_file
file = malloc(sizeof(wav_file));
//copying header from the contents to the wav_file struct apart from the data
memcpy(file,contents,44);
//copying the data from contents
file->data = contents+44;
return file;
}