#include <stdio.h>

void showDirectory(int level) {
    if (level == 0) return;
    for(int i=0; i<level; i++) printf("--");
    printf("Folder Level %d\n", level);
    showDirectory(level - 1); // Recursive call
}

int main() {
    printf("Root\n");
    showDirectory(3);
    return 0;
}
