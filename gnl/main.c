#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256

int main(void) {
    FILE *file;
    char line[MAX_LINE_LENGTH];

    // Ouvre le fichier pour lecture
    file = fopen("mon_fichier.txt", "r");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return EXIT_FAILURE;
    }

    // Boucle pour lire et afficher une ligne à chaque pression sur Entrée
	while (fgets(line, sizeof(line), file)) {
		printf("%s", line);
		printf("Appuyez sur Entrée pour continuer...\n");
		getchar();
	}

	fclose(file);
	return EXIT_SUCCESS;
}
