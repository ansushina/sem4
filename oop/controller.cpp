#include "controller.h"
#include "rc.h"
#include "functions.h"
#include <iostream>

void draw_model(figure_t fig, myscene_t scene)
{
    if (is_empty(fig))
        return;

    std::cout << "drawing"<<std::endl;

    for (size_t i = 0; i < get_fig_n(fig); i++)
    {
        draw_point_scene(scene,get_point(fig,i));
    }
    for (size_t i = 0; i < get_fig_n(fig); i++)
    {
        for (size_t j = 0; j < i + 1; j++)
        {
            if (get_matrix_el(fig,i,j) != 0)
            {
                //std::cout <<i <<std::endl;
               // std::cout <<get_point(fig,i).n<<"->"<<get_point(fig,j).n <<std::endl;
                draw_line_scene(scene,get_point(fig,i),get_point(fig,j));
            }
        }
    }
}

void controller(myscene_t scene, int act_number, action_t act)
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
        rc = clear_fig(fig);
    }
    else if (act_number == DRAW_NUMBER)
    {
        rc = draw_fig(fig, scene);
    }
    if (rc)
    {
        print_warning(rc);
    }
}
