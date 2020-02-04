/*****************************************************************
This file holds the structue wav_file that we use to store the 
file we are manipulating. It also has the function we are using to
put the file into said structure.
@author Dylan Vannatter
@version Winter 2020
*****************************************************************/ 
typedef struct wav_file
{
	char riff[4];
	int fileSize;
	char wavCheck[4];
	char fmt[4];
	int frmtLen;
	short frmtType;
	short numChannels;
	int smpleRate;
	int bytesPerSec;
	short blockAlimnt;
	short bitsPerSmple;
	char dataBeg[4];
	int dataSize;
	char* data;
}wav_file;

wav_file* parse(char* contents);