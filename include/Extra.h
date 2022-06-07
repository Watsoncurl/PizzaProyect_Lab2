
#ifndef EXTRA_H
#define EXTRA_H

#include <cstdio>

// Devolver cantidad de caracteres de archivo
inline int flength(FILE *file) {
	if(file == NULL) return -1;

	int filelength = 0, filepos = ftell(file);

	fseek(file, 0, SEEK_SET);
	while(fgetc(file) != EOF) {
		filelength++;
	}
	fseek(file, filepos, SEEK_SET);

	return filelength;
}

#endif // EXTRA_H
