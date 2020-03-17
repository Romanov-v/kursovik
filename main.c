#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#define LEN 256
#define CHUNK 200
#define assertmsg(x, msg) assert(((void) msg, x))
struct myString{
	int size;
	char* data;
};
typedef struct myString Struct;

Struct readinput()
{

	char* input = NULL;
	char tempbuf[CHUNK];
	size_t inputlen = 0, templen = 0;
	do {
		fgets(tempbuf, CHUNK, stdin);
		templen = strlen(tempbuf);
		input = realloc(input, inputlen+templen);
		strcpy(input+inputlen, tempbuf);
		inputlen += templen;
	} while (templen==CHUNK-1 && tempbuf[CHUNK-2]!='\n');

	Struct out;
	input[inputlen - 1] = 0;
	out.size = inputlen - 1;
	out.data = input;

	return out;
}
int writebyte(FILE *f, char* c){
	char buffer_out[1];
	buffer_out[0] = c;
	fwrite(buffer_out, 1, 1, f);
	fclose(f);
	return 0;
	}


int main (int argc, char** argv)
{
	assertmsg(argc > 1, "введите имя файла");
	assert( (access(argv[1], F_OK)) != -1 && "файла не существует") ;

	FILE * f;
	char* buffer;
	long filelen;

    f = fopen(argv[1], "w");
    fprintf(f, "abc");
    fclose(f);
    f = fopen(argv[1], "rb");
    fseek(f, 0, SEEK_END);
	filelen = ftell(f);
	rewind(f);

	buffer = (char*)malloc(filelen * sizeof(char));
	fread(buffer, filelen, 1, f);
	printf("%lx\n", filelen);
	for(int i = 0; i < filelen; i ++)
		printf("%hhx ", buffer[i]);
	fclose(f);
	// затирание
	f = fopen(argv[1], "w");
	writebyte(f, 0x55);
	writebyte(f, 0xAA);

	fclose(f);
	return 0;
}
.idea/
CMakeLists.txt
cmake-build-debug/
