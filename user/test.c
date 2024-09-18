#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    struct pstat stats;
    static char *states[] = { "unused", "used", "sleep ", "runble", "run   ", "zombie"};
    static char *color[] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "INDIGO", "VIOLET"};

    int pid_1 = fork();
    for(;;)
    {
        if(pid_1 == 0)
        {
            setColor(1);
            setTickets(30);
            int pid_2 = fork();

            if(pid_2 == 0)
            {
                setColor(2);
                setTickets(20);
                int pid_3 = fork();

                if(pid_3 == 0)
                {
                    setColor(3);
                    setTickets(10);

                    for(;;)
                    {
                        
                    }
                }
                else
                {
                    for(;;)
                    {
                        
                    }
                }
            }
            else
            {
                for(;;)
                {

                }
            }
        }
        else
        {
            sleep(10);
            getpinfo(&stats);

            printf("NAME\tSTATE\tINUSE\tTICKETS\t  PID\tCOLOR\tTICKS\n");
            for(int i = 0; i < NPROC; i++)
            {
                if(stats.state[i] != UNUSED)
                    printf("%s\t%s\t  %d\t  %d\t   %d\t %s\t%d\n", stats.name[i], states[stats.state[i]], stats.inuse[i], stats.tickets[i], stats.pid[i], color[stats.color[i]], stats.ticks[i]);
            }
            printf("====================================================\n");
        }
    
    }
    return 0;
}