#include "controller.h"

typedef struct action action_t;

typedef int num_t;



rc_type download_model(figure_t &fig, action_t act);
rc_type perenos_fig(figure_t &fig, action_t act);
rc_type povorot_fig(figure_t &fig, action_t act);
rc_type mastab_fig(figure_t &fig, action_t act);
rc_type clear_fig(figure_t &fig, action_t act);
rc_type draw_fig(figure_t &fig, action_t act);



void controller(myscene_t scene, num_t act_number, action_t act)
{
    static figure_t fig = init_fig();
    rc_type rc = OK;
    if (act_number == DOWNLOAD)
    {
        rc = download_model(fig, act);
    }
    else if (act_number ==  PERENOS_NUMBER)
    {
        rc = perenos_fig(fig,act);
    }
    else if (act_number == POVOROT_NUMBER)
    {
        rc = povorot_fig(fig,act);
    }
    else if (act_number == MASTAB_NUMBER)
    {
        rc = mastab_fig(fig,act);
    }
    else if (act_number == DELETE_NUMBER)
    {
        rc = clear_fig(scene, fig);
    }
    else if (act_number == DRAW_NUMBER)
    {
        rc = draw_fig(scene, fig)
    }
    if (rc)
    {
        print_warning(rc);
    }
}
