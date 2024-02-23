#include "./mandaw/mandaw.h"

void my_update(Mandaw *mandaw, float delta_time, void *user_data);
void my_draw(Mandaw *mandaw, void *user_data);

int main()
{
    Mandaw mandaw;

    mandaw_init(&mandaw, "Mandaw", 800, 600);

    mandaw.at_update = my_update;
    mandaw.at_draw = my_draw;

    mandaw_run(&mandaw);

    return 0;
}

void my_update(Mandaw *mandaw, float delta_time, void *user_data)
{
    printf("delta time: %f\n", delta_time);
}

void my_draw(Mandaw *mandaw, void *user_data)
{

}