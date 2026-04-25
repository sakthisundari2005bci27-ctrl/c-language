#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct package {
    char* id;
    int weight;
};

struct post_office {
    int min_weight;
    int max_weight;
    struct package* packages;
    int packages_count;
};

struct town {
    char* name;
    struct post_office* offices;
    int offices_count;
};

void print_all_packages(struct town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_packages(struct town* source, int source_office_index, struct town* target, int target_office_index) {
    struct post_office* src = &source->offices[source_office_index];
    struct post_office* tgt = &target->offices[target_office_index];

    // Arrays to temporarily hold accepted and rejected packages
    struct package* accepted = malloc(sizeof(struct package) * src->packages_count);
    struct package* rejected = malloc(sizeof(struct package) * src->packages_count);
    int a_count = 0, r_count = 0;

    for (int i = 0; i < src->packages_count; i++) {
        int w = src->packages[i].weight;
        if (w >= tgt->min_weight && w <= tgt->max_weight) {
            accepted[a_count++] = src->packages[i];
        } else {
            rejected[r_count++] = src->packages[i];
        }
    }

    // Update target office: append accepted packages to the tail
    tgt->packages = realloc(tgt->packages, sizeof(struct package) * (tgt->packages_count + a_count));
    for (int i = 0; i < a_count; i++) {
        tgt->packages[tgt->packages_count + i] = accepted[i];
    }
    tgt->packages_count += a_count;

    // Update source office: keep only rejected packages
    free(src->packages);
    src->packages = malloc(sizeof(struct package) * r_count);
    for (int i = 0; i < r_count; i++) {
        src->packages[i] = rejected[i];
    }
    src->packages_count = r_count;

    free(accepted);
    free(rejected);
}

struct town town_with_most_packages(struct town* towns, int towns_count) {
    int max_p = -1;
    int town_idx = 0;
    for (int i = 0; i < towns_count; i++) {
        int current_town_p = 0;
        for (int j = 0; j < towns[i].offices_count; j++) {
            current_town_p += towns[i].offices[j].packages_count;
        }
        if (current_town_p > max_p) {
            max_p = current_town_p;
            town_idx = i;
        }
    }
    return towns[town_idx];
}

struct town* find_town(struct town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            return &towns[i];
        }
    }
    return NULL;
}
