#include "mario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ƒ}ƒŠƒI‚ÌŽÀ‘Ô
Mario MasterMario;


void ReloadMario(const char* path)
{
	if (path == nullptr) return ;

	FILE* fp = fopen(path, "r");
	if (fp == nullptr) return ;
	char s[256];
	size_t count = 0;
	while (fgets(s, sizeof(s), fp) != nullptr) {
		if (strncmp(s, "ON", 2) == 0) {
			count++;
		}
	}
	fseek(fp, 0, SEEK_SET);

	free(MasterMario.Infos);
	MasterMario.Infos = (MarioInfo*)malloc(sizeof(MarioInfo) * count);
	MasterMario.size = (int)count;

	MarioInfo* p = MasterMario.Infos;
	while (fgets(s, sizeof(s), fp) != nullptr) {
		if (strncmp(s, "ON", 2) == 0) {
			int n = sscanf(&s[3], "%[^,],%d,%d", p->name, &p->x, &p->y);
			p++;
		}
	}

	fclose(fp);
}
