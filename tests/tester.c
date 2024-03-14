#include "./../get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
void func()
{
    system("leaks a.out");
}
void one_char();
void empty();
void giant();
void multiple();
void oneline_nonl();
void onenl();
int main()
{
    // one_char();
    // empty();
    // giant();
    // oneline_nonl();
    // onenl();
    char *a =malloc(10);
        atexit(func);

}