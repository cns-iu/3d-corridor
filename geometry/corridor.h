#pragma once

#include "algo.h"
#include "utils.h"

class Mytissue {

    public:
        Mytissue() = default;
        Mytissue(double c_x, double c_y, double c_z, double d_x, double d_y, double d_z); 
        
        double center_x, center_y, center_z;
        double dimension_x, dimension_y, dimension_z;

        double compute_intersection_volume(Mymesh &mesh);
    
    private:
        std::vector<Point> &generate_points();
        void create_mesh();

    private:
        Surface_mesh tissue_mesh;
        std::vector<Point> points;

}


std::vector<Point> find_all_locations(Mymesh &my_mesh, Mytissue &example_tissue);