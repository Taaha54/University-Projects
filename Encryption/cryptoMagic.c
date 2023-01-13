#include <stdio.h>
#include <string.h>

int encrypt(char *fname, char * mfname);
int decrypt(char *fname, char * mfname);
char conv_hex(int hex[2]);
int raise_to_exp(int x, int y);


int main(int arg_num, char *arg[]) {

	int counter = 0, complete, exti = -1;
	char mfname[255],fname[255], efilext[5] = { '.', 'c', 'r', 'p' }, dfilext[5] = { '.', 't', 'x', 't' };

	strcpy(fname,arg[arg_num-1]); // Sets the file name based on whether -encrypt/-decrypt was passed or not
	if (arg_num > 3) { 
		printf("error too many arguments passed");
		return 0;
	}

	while (fname[counter] != '\0') { // Gets rid of file extension if one exists
		mfname[counter] = fname[counter];
		if (fname[counter] == '.'){
			exti = counter;
		}
		counter++;
	}
	if (exti == -1){
	mfname[counter] = '\0';
	}
	else{
		mfname[exti] = '\0';
	}

	if (strcmp(arg[1], "-decrypt") == 0)
	{
		strcat(mfname, dfilext);
		complete = decrypt(fname, mfname);
	}
	else {
		strcat(mfname, efilext);
		complete = encrypt(fname, mfname);
	}
	if (complete == 0){
		printf("Proccess complete");
	}
	getchar();
	return 0;
}

int encrypt(char * fname, char * mfname)
// Encrypts a file passed and prints encrypted info into another text file encrypt(str, str) -> int
{
	FILE *f;
	FILE *mf;
     

	f = fopen(fname, "r");
	mf = fopen(mfname, "w");
    
	if (f == NULL || mf == NULL) {
		printf("Error couldnt open file %s and/or encrypted file %s", fname, mfname);
		return 1;
	}
	int counter = 0, outChar;
	char buff[121];

	while (fgets(buff, 121, f) != NULL) { // Read file
		counter = 0;
		while (buff[counter] != '\0') { //iterate through file
			if ((int)buff[counter] == 9) { // seperate operation for special characters
				fprintf(mf, "TT");
				counter++;
			}
			else if (buff[counter] == '\n') {// seperate operation for special characters
				fprintf(mf, "\n");
				counter++;
			}
			else { // Encrypt characters
				outChar = (int)buff[counter] - 16;
				if (outChar < 32) {
					outChar = outChar - 32 + 144;
				}
				fprintf(mf, "%x", outChar);
				counter++;
			}
		}
	}
	fclose(f);
	fclose(mf);
	return 0;
}


int decrypt(char *fname, char * mfname) {
	// decrypt(str, str) -> int
	// decrypts a file following the decryption of char
	FILE *f;
	FILE *mf;

	f = fopen(fname, "r");
	mf = fopen(mfname, "w");

	int counter = 0, inChar[2];
	char buff[256], outChar;

	if (f == NULL || mf == NULL) {
		printf("Error couldnt open file %s and/or decrypted file %s", fname, mfname);
		return 1;
	}

	while (fgets(buff, 256, f) != NULL) { //Read File
		counter = 0;
		while (buff[counter] != '\0') {  // Iterate through string
			if (buff[counter] == 'T') { // seperate operation for special characters
				fprintf(mf, "\t");
				counter = counter + 2;
			}
			else if (buff[counter] == '\n') { // seperate operation for special characters
				fprintf(mf, "\n");
				counter++;
			}
			else {
			for (int i = 0; i < 2; i++) {
				switch (buff[counter]) { // Convert hex characters to their decimal num
				case '0':
					inChar[i] = 0;
					break;
				case '1':
					inChar[i] = 1;
					break;
				case '2':
					inChar[i] = 2;
					break;
				case '3':
					inChar[i] = 3;
					break;
				case '4':
					inChar[i] = 4;
					break;
				case '5':
					inChar[i] = 5;
					break;
				case '6':
					inChar[i] = 6;
					break;
				case '7':
					inChar[i] = 7;
					break;
				case '8':
					inChar[i] = 8;
					break;
				case '9':
					inChar[i] = 9;
					break;
				case 'a':
					inChar[i] = 10;
					break;
				case 'b':
					inChar[i] = 11;
					break;
				case 'c':
					inChar[i] = 12;
					break;
				case 'd':
					inChar[i] = 13;
					break;
				case 'e':
					inChar[i] = 14;
					break;
				case 'f':
					inChar[i] = 15;
					break;
				}
				counter++;
			}
			outChar = conv_hex(inChar); // converts hex -> char
			fprintf(mf, "%c",outChar);
			}
		}

	}
	fclose(f);
	fclose(mf);
	return 0;
}

char conv_hex(int hex[2]) {
	// Converts encrypted hexidecimal to its character version
	int outChar, i, n=0 ;
	for (i = 1; i >= 0; i--) {
		hex[i] = hex[i] * raise_to_exp(16, n);
		n++;
	}
	outChar = hex[0] + hex[1];
	outChar += 16; // reverses encryption scheme on the integer
	if (outChar > 127) { 
		outChar = (outChar - 144) + 32;
	}
	return (char)outChar;
}

int raise_to_exp(int x, int y) {
	// raises x to a power y
	int result = x;

	if (y == 0) {
		return 1;
	}
	for (int i = 0; i < y-1; i++) {
		result = result * x;
	}
	return result;
}
