#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    struct pstat stats;
    getpinfo(&stats);

    static char *states[] = { "unused", "used", "sleep ", "runble", "run   ", "zombie"};
    static char *color[] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "INDIGO", "VIOLET"};

    printf("NAME\tSTATE\tINUSE\tTICKETS\t  PID\tCOLOR\tTICKS\n");
    for(int i = 0; i < NPROC; i++)
    {
        printf("%s\t%s\t  %d\t  %d\t   %d\t %s\t%d\n", stats.name[i], states[stats.state[i]], stats.inuse[i], stats.tickets[i], stats.pid[i], color[stats.color[i]], stats.ticks[i]);
    }
    
    return 0;
}