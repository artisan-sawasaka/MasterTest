#include <stdio.h>
#include "master/mario.h"

int main()
{
	while (true) {
		ReloadMario("data.csv");
		for (int i = 0; i < MasterMario.size; ++i) {
			MarioInfo* p = &MasterMario.Infos[i];
			printf("%s %d %d\n", p->name, p->x, p->y);
		}
		getchar();
	}
}
