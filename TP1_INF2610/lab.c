/* INF2610 - TP1
/ 2061606  
/ 2071348 
*/
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include "lab.h"


struct Wheel* createWheels(int initialId) {
    int numberOfWheels = 7;
    struct Wheel* wheels = malloc(numberOfWheels * sizeof(struct Wheel));


    for (int i = 0; i < numberOfWheels; i++) {
        wheels[i].id = initialId + i;
        wheels[i].isRearWheel = (i >= 3);  
    }
    return wheels;
}


void populateWingAttributes(struct Wing *wing, int id) {
    for (int i = 8; i >= 0; --i) {
        wing->id[i] = id % 10;
        id /= 10;
    }
}

struct Wing* createWings(long id) {
    struct Wing *wings = malloc(2*sizeof(struct Wing));
    wings[0].id = malloc(9 * sizeof(int));
    wings[1].id = malloc(9 * sizeof(int)); 
    populateWingAttributes(&wings[0], (int)id);
    populateWingAttributes(&wings[1], (int)(id + 1));

    return wings;
}


void createPlanes(struct Plane *planes, char *id, int numPlanes) {
    for (int i = 0; i < numPlanes; i++) {
        planes[i].planeType[0] = '\0';
        planes[i].id = id;
        planes[i].isAvailable = true;
        planes[i].wheels = createWheels(i);
        planes[i].wings = (struct Wing *)malloc(sizeof(struct Wing));
        planes[i].wings->id = malloc(9 * sizeof(int)); // Supposant 9 entiers par aile

        populateWingAttributes(planes[i].wings, i);
    }
}


void setAvailability(struct Plane *plane, bool isAvailablePlane) {
    plane->isAvailable = isAvailablePlane;
}

void getAvailablePlanes(struct Plane *planes, int numPlanes) {
    printf("Available planes:\n");
    for (int i = 0; i < numPlanes; i++) {
        if (planes[i].isAvailable) {
            printf("Plane %s\n", planes[i].id);
        }
    }
}

void setPlaneType(struct Plane *plane){

    int firstWingNumber =  plane->wings->id[0];

    if(firstWingNumber>=0 && firstWingNumber<=2)
        printf("Small\n");

    else if(firstWingNumber >= 3 && firstWingNumber <= 6)
        printf("Medium\n");

    else if(firstWingNumber >= 7 && firstWingNumber <= 8)
        printf("Large\n");
}

void getPlanesByType(struct Plane *planes, const char *planeType, int numberOfPlanes){
    printf("The Plane's type is '%s':\n", planeType);
    for (int i = 0; i < numberOfPlanes; i++) {
        if (strcmp(planes[i].planeType, planeType) == 0) {
            printf("Plane %d\n", i + 1);
        }
    }
}


/*Nous avons fais cette fonction afin d'assigner des types d'avions différents
aux avions de notre instance à chaque fois que nous exécutons le code avec ./lab */

void assignRandomPlaneTypes(struct Plane *planes, int numPlanes) {
    const char *types[] = {"Small", "Medium", "Large"};
    int numTypes = 3;

    for (int i = 0; i < numPlanes; i++) {
        int typeIndex = rand() % numTypes; 
        strcpy(planes[i].planeType, types[typeIndex]);
    }
}





int main(int argc, char** argv) {
    srand(time(NULL));  

    printf("Hello\n");
    int id = 1;


    /* PARTIE 2 - [10 points] */

    /* Create wheel - [2 points] */
    struct Wheel* wheels = createWheels(id);

    for (int i = 0; i < 7; i++) {
        printf("Wheel %d: ID = %d, isRearWheel = %s\n", i + 1, wheels[i].id, wheels[i].isRearWheel ? "true" : "false");
        }


    /* Create wing - [4 points] */
    
    long longId = 123456;   
    struct Wing *wings = createWings(longId);

    for (int i = 0; i < 2; i++) {
        printf("Wing %d: ", i + 1);
        for (int j = 0; j < 9; j++) {
            printf("%d ", wings[i].id[j]);
        }
        printf("\n");
    }


    /* Create plane - [4 points] */
    char planeName[] = "MyPlane";
    
    int numberOfPlanes = 3;
    struct Plane* planes = malloc(sizeof(struct Plane) * numberOfPlanes);
    createPlanes(planes, planeName, 3);

    /* PARTIE 3 - [6 points] */

    assignRandomPlaneTypes(planes, numberOfPlanes);


    /* Set availabilities - [1 point] */
    
    struct Plane plane = planes[0];
    setAvailability(&plane, true);


    /* Get available planes - [1 point] */
    getAvailablePlanes(planes, numberOfPlanes);
    

    /* Classify planes - [2 points] */
    planes[1].wings->id[0] = 8; // Pour tester le code 
    struct Plane plane_wing = planes[1];

    setPlaneType(&plane_wing);
    
    /* Return type specific planes - [2 points] */
    for (int i = 0; i < numberOfPlanes; i++) {
        setPlaneType(&planes[i]);
        printf("Plane %d: Type = %s\n", i + 1, planes[i].planeType);
    }

    char planeType[] = "Small";


    getPlanesByType(planes, planeType, numberOfPlanes);

    for (int i = 0; i < numberOfPlanes; i++) {
        free(planes[i].wings->id);
        free(planes[i].wings);
        free(planes[i].wheels);


    }
    free(planes);
}
