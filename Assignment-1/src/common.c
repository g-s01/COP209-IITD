#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "common.h"

void setConstants() {
    HareRunLikeCrazyConstant = 100;
    ChangeTurlePositionConstant = 1;
    HareSleepConstant = 3;
    HareRunForAWhileDurationConstant = 10;
}

/*
    TODO: use ncurses
*/
void print(char* message) {
    printf("%s\n", message);
}

long int GetTurtlePosition(struct Turtle* turtle) {
    return turtle->position;
}

void TurtleMoveLeg1(struct Turtle* turtle) {
    print("Turtle is moving leg 1");
}

void TurtleMoveLeg2(struct Turtle* turtle) {
    print("Turtle is moving leg 2");
}

void TurtleMoveLeg3(struct Turtle* turtle) {
    print("Turtle is moving leg 3");
}

void TurtleMoveLeg4(struct Turtle* turtle) {
    print("Turtle is moving leg 4");
}

void DisplaceTurtle(struct Turtle* turtle, long int delta) {
    turtle->position += delta;
}

void SetTurtlePosition(struct Turtle* turtle, long int position) {
    turtle->position = position;
}

long int GetHarePosition(struct Hare* hare) {
    return hare->position;
}

void DisplaceHare(struct Hare* hare, long int delta) {
    hare->position += delta;
}

void SetHarePosition(struct Hare* hare, long int position) {
    hare->position = position;
}

void RunLikeCrazy(struct Hare* hare, long int duration) {
    print("Hare is running like crazy");
    DisplaceHare(hare, HareRunLikeCrazyConstant*duration);
}

void setFinish(long int value) {
    finish = value;
}

long int getFinish() {
    return finish;
}

void reposition(struct Hare* hare, struct Turtle* turtle, char animal) {
    // Initialize random number generator with a seed
    srand48(time(0));
    long int new_position = lrand48()%(getFinish()+1);
    if (animal == 'H') {
        SetHarePosition(hare, new_position);
    } else if(animal == 'T') {
        SetTurtlePosition(turtle, new_position);
    }
}

void* TurtleRace(struct Turtle turtle) {
    while (GetTurtlePosition(&turtle) < getFinish()) {
        TurtleMoveLeg1(&turtle);
        TurtleMoveLeg2(&turtle);
        TurtleMoveLeg3(&turtle);
        TurtleMoveLeg4(&turtle);
        DisplaceTurtle(&turtle, ChangeTurlePositionConstant);
    }
    return NULL;
}

void* HareRace(struct Hare hare, struct Turtle turtle) {
    srand48(time(0));
    if(GetHarePosition(&hare) >= 10*GetTurtlePosition(&turtle)) {
        sleep(HareSleepConstant);
    } else {
        long int duration = lrand48()%HareRunForAWhileDurationConstant+1;
        RunLikeCrazy(&hare, duration);
    }
    return NULL;
}

void* God() {
    char c;
    return NULL;
}

void* Report(struct Hare hare, struct Turtle turtle) {
    char turtlePosition[50], harePosition[50];
    sprintf(turtlePosition, "%ld", GetTurtlePosition(&turtle));
    sprintf(harePosition, "%ld", GetHarePosition(&hare)); 
    print(turtlePosition);
    print(harePosition);
    return NULL;
}