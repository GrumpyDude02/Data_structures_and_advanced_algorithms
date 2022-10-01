#include <stdio.h>
#include <stdlib.h>
typedef struct salarie
{
    char *full_name;
    struct identity
    {
        int matricul;
        char *CIN;
    } identity;

    struct experience
    {
        int salary;
        int anciente;
        char *pos;
    } experience;

} salarie;

int main()
{
    salarie emp1;
    emp1.full_name = "fullname";
    emp1.identity.CIN = "T31492";

    salarie *t_emp = calloc(50, sizeof(salarie));
    t_emp[0].identity.matricul = 999;
    printf("%d", t_emp[0].identity.matricul);
}