/* INF2610 - TP1
/ 2061606 : 
/ 2071348 : 
*/
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h> 
#include <stdbool.h>


struct Wheel {
    int id;
    bool isRearWheel;
};

struct Wing {
    int *id; 
};

struct Plane {
    char *id; 
    char planeType[10];
    bool isAvailable;
    struct Wheel *wheels; 
    struct Wing *wings;   
};

struct Wheel* createWheels(int initialId) {
    int numberOfWheels = 7;
    struct Wheel* wheels = malloc(numberOfWheels * sizeof(wheels));

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



int main(int argc, char** argv) {
    printf("Hello\n");
    /* Remove comment once the code is completed for the given section to test */
    int id = 101;


    /* PARTIE 2 - [10 points] */

    /* Create wheel - [2 points] */
    struct Wheel* wheels = createWheels(id);

   for (int i = 0; i < 7; i++) {
        printf("Wheel %d: ID = %d, isRearWheel = %s\n", i + 1, wheels[i].id, wheels[i].isRearWheel ? "true" : "false");
    }


    /* Create wing - [4 points] */
    
    long longId = 123456;
   // Wing[] wings;
   
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

    printf("Wheel %d created with ID = %d\n", i, wheels[i].id);

    if (wheels == NULL) {
        printf("Memory allocation for wheels failed\n");
        exit(1); 
    }



    

    /* PARTIE 3 - [6 points] */

    /* Set availabilities - [1 point] */
    /*
    Plane plane = planes[0];
    setAvailability(plane, true);
    */

    /* Get available planes - [1 point] */
    /*
    getAvailablePlanes(planes, numberOfPlanes);
    */

    /* Classify planes - [2 points] */
    /*
    Plane plane = planes[1];
    setPlaneType(plane);
    */

    /* Return type specific planes - [2 points] */
    /*
    char planeType[] = "Small";
    getPlanesByType(planes, planeType,numberOfPlanes);
    */
}