#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "wav.h"
/*****************************************************************
The main function is where we call our functions to pass the file
in, parse it, reverse the bits and print out the file information
and then write it to a new file.
@param argc the number of parameters we are passing into program.
@param argv the parameters we are passing into the program.
*****************************************************************/ 
int main(int argc, char** argv){
	//place where we store the file data after read
	char* fileBuffer;
	//where we store the data after being put into a wav_file struct
	wav_file* parsedFile;
	//size of the whole file
	size_t size = read_file(argv[1], &fileBuffer);
	//parsing the file into a wav_file struct
	parsedFile = parse(fileBuffer);
	//printing the file data
	printf("Format is %s with a format data length of %d\n", parsedFile->fmt, parsedFile->frmtLen);
	printf("Format type is %d\n", parsedFile->frmtType);
	printf("%d channels with a sample rate of %d\n", parsedFile->numChannels, parsedFile->smpleRate);
	printf("%d byte rate, %d block alignment, %d bits per sample.\n", parsedFile->bytesPerSec, parsedFile->blockAlimnt, parsedFile->bitsPerSmple);
	printf("Data is %s and data size is %d\n", parsedFile->dataBeg, parsedFile->dataSize);
	//size of the sample
	int sampleInBytes = parsedFile-> dataSize;
	//number of bytes we have per sample
	int numOfBytes = (parsedFile->bitsPerSmple*parsedFile->numChannels)/8;
	//where we store the reversed data
    char* reversed = malloc(sampleInBytes);
    //current sample we are on
    int sampleId = 0;
    //where we are reversing the data using the number of samples
    for (int i = 0; i < sampleInBytes; i++){
        if (i != 0 && i % numOfBytes == 0){
            sampleId += 2 * numOfBytes;
        }
        int index = sampleInBytes - numOfBytes - sampleId + i ;
        reversed[i] = parsedFile->data[index];
    }
    //putting the reversed data into our file  
    parsedFile->data = reversed;
    memcpy(fileBuffer+44, parsedFile->data, parsedFile->dataSize);
    //writing the new data to a new file
    write_file(argv[2], fileBuffer, size);
    //freeing the memory we allocated
    free(reversed);
    free(parsedFile);
    free(fileBuffer);
}