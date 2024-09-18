#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    struct pstat stat;
    getpinfo(&stat);

    static char *states[] = { "UNUSED", "USED", "SLEEPING", "RUNNABLE", "RUNNING ", "ZOMBIE"};
    static char *color[] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "INDIGO", "VIOLET"};

    printf("NAME\tPID\tSTATUS\t\tCOLOR\tTICKETS\n");
    for(int i = 0; i < NPROC; i++)
    {
        if(stat.state[i] != UNUSED)
          printf("%s\t%d\t%s\t%s\t%d\n", stat.name[i], stat.pid[i], states[stat.state[i]], color[stat.color[i]], stat.tickets[i]);
    }

    return 0;
}