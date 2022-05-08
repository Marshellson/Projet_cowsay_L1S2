/*
 * @Author: ThearchyHelios
 * @Date: 2022-05-04 13:06:10
 * @LastEditTime: 2022-05-05 15:38:34
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /Projet_cowsay_L1S2/Tamagoshi-vache-refaire.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef int state;
typedef int condition;

#define STATENUM 4
#define STATE1 0
#define STATE2 1
#define STATE3 2
#define STATETRAP 3

#define CONDITIONS 2
#define CONDITION1 0
#define CONDITION2 1

typedef void (*actiontype)(state mystate, condition mycondition);
typedef struct
{
    state next;
    actiontype action;
} trasition, *ptrasition;

void action1(state mystate, condition myconditon);
void action2(state mystate, condition myconditon);
void action3(state mystate, condition myconditon);
void actiontrap(state mystate, condition myconditon);
trasition t1 = {
    STATE2, action1};
trasition t2 = {
    STATE3, action2};
trasition t3 = {
    STATE2, action3};
trasition tt = {
    STATETRAP, actiontrap};

void action1(state mystate, condition myconditon)
{
    printf("action1 one triggered\n");
}
void action2(state mystate, condition myconditon)
{
    printf("action2 one triggered\n");
}
void action3(state mystate, condition myconditon)
{
    printf("action3 one triggered\n");
}
void actiontrap(state mystate, condition myconditon)
{
    printf("actiontrap one triggered\n");
}

ptrasition transition_table[STATENUM][CONDITIONS] = {
    /*      c1,  c2*/
    /* s1 */ &t1,
    &tt,
    /* s2 */ &tt,
    &t2,
    /* s3 */ &t3,
    &tt,
    /* st */ &tt,
    &tt,
};
typedef struct
{
    state current;
} StateMachine, *pStateMachine;

state step(pStateMachine machine, condition mycondition)
{
    ptrasition t = transition_table[machine->current][mycondition];
    (*(t->action))(machine->current, mycondition);
    machine->current = t->next;
    printf("the current state is %d\n", t->next);
    return machine->current;
}
int main(int argc, char *argv[])
{
    StateMachine mymachine;
    mymachine.current = STATE1;
    int mycon;
    char ch;
    while (1)
    {
        scanf("%d", &mycon);
        step(&mymachine, mycon);
    }
    return 0;
}