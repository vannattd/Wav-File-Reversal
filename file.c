#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/*****************************************************************
This function takes the filename of the file we want to reverse
and then allocates the data from the file to a spot in memory.
@param filename the file we are opening and reading data from.
@param buffer the spot in memory where we are storing the data.
*****************************************************************/ 
size_t read_file(char* filename, char** buffer){
struct stat st;
stat(filename, &st);
//getting the size of the file
size_t size = st.st_size;
//creating space in memory for the data 
*buffer = malloc(size * sizeof(char));
FILE* fp;
fp = fopen(filename, "r");
//making sure the file exists 
if (fp == NULL){
	return -1; 
}
//reading the file into buffer
size_t readItems = fread(*buffer, sizeof(char), size, fp);
fclose(fp);
//Printing the size of file and the size of the read file
printf("File is %lu bytes. Read %lu bytes.\n", size, readItems-8);
return readItems;
}


/*****************************************************************
This function takes the filename of the file we want to write
to and then writes the data from buffer of a specfic size.
@param filename the file we are writing the data to.
@param buffer the memory where we are retrieving the data from.
@param size the size of the data we are writing.
*****************************************************************/ 
size_t write_file(char* filename, char* buffer, size_t size){
FILE* fp;
fp = fopen(filename,"w");
//making sure we have a valid pointer
if(fp == NULL)
	return -1;
//writing the data to the file
size_t writtenItems = fwrite(buffer, sizeof(char), size, fp);
fclose(fp);
return writtenItems;
}
