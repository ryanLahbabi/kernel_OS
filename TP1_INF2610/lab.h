
#include <stdbool.h>

struct Wheel {
    int id;
    bool isRearWheel;
};

struct Wheel *createWheels(int initialId);

struct Wing {
    int *id; 
};


void populateWingAttributes(struct Wing *wing, int id);

struct Plane {
    char *id; 
    char planeType[10];
    bool isAvailable;
    struct Wheel *wheels; 
    struct Wing *wings;   
};

//Check setAvailability

void createPlanes(struct Plane *planes, char *id, int numPlanes);
void setAvailability(struct Plane *plane, bool isAvailablePlane);
void getAvailablePlanes(struct Plane *planes, int numPlanes);
void setPlaneType(struct Plane *plane);
void getPlanesByType(struct Plane *planes, const char* planeType, int numberOfPlanes);
void assignRandomPlaneTypes(struct Plane *planes, int numPlanes);


