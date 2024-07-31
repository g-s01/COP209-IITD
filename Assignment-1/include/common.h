#ifndef COMMON_H
#define COMMON_H

struct Hare {
    long int position;
};

struct Turtle {
    long int position;
};

extern long int finish;

/*
    constants
*/
extern long int HareRunLikeCrazyConstant;
extern long int ChangeTurlePositionConstant;
extern long int HareSleepConstant;
extern long int HareRunForAWhileDurationConstant;

/*
    Turtle functions
*/
void TurtleMoveLeg1(struct Turtle* turtle);
void TurtleMoveLeg2(struct Turtle* turtle);
void TurtleMoveLeg3(struct Turtle* turtle);
void TurtleMoveLeg4(struct Turtle* turtle);
long int GetTurtlePosition(struct Turtle* turtle);
void DisplaceTurtle(struct Turtle* turtle, long int delta);
void SetTurtlePosition(struct Turtle* turtle, long int position);

/*
    Hare functions
*/
long int GetHarePosition(struct Hare* hare);
void RunLikeCrazy(struct Hare* hare, long int durartion);
void DisplaceHare(struct Hare* hare, long int delta);
void SetHarePosition(struct Hare* hare, long int position);

/*
    Common functions
*/

void print(char* message);

void setFinish(long int value);

long int getFinish();

void reposition(struct Hare* hare, struct Turtle* turtle, char animal);

void* TurtleRace(struct Turtle turtle);
void* HareRace(struct Hare hare, struct Turtle turtle);
void* God();
void* Report(struct Hare hare, struct Turtle turtle);

void setConstants();

#endif // COMMON_H