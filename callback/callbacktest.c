/* callacktest.c 
/   This program is a simple callback test.
/
/   Will use move_to and line_to as examples
*/

#include <stdio.h>

typedef struct vector_
{
    double x;
    double y;
}vector;

/* Create a structure of callbacks */
typedef struct
{
    void (*callbackMove)(vector);
    void (*callbackLine)(vector, vector);
}callbackFuncs;

void do_move(vector point)
{
    printf("Move to (%f, %f)\n", point.x, point.y);
}

void do_line(vector point, vector point1)
{
    printf("Line from (%f,%f) to (%f, %f)\n", point.x, point.y, point1.x, point1.y);
}

void draw(callbackFuncs *funcs)
{
    vector start, end;
    start.x = 0;
    start.y = 0;
    end.x = 0;
    end.y = 0;

    /* Move to the start */
    funcs->callbackMove(end);

    /* now make a line */
    start.x = end.x;
    start.y = end.y;
    end.x = 10;
    end.y = 10;
    funcs->callbackLine(start, end);

    return;
}
void main(void)
{

    callbackFuncs myCallbacks = 
    {
        &do_move,
        &do_line,
    };

    draw(&myCallbacks);

}