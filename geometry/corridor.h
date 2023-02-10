#pragma once

#include "algo.h"
#include "utils.h"
#include <cmath>

class Mytissue: public Mymesh {

    public:
        Mytissue() = default;
        Mytissue(double c_x, double c_y, double c_z, double d_x, double d_y, double d_z); 
        
        double center_x, center_y, center_z;
        double dimension_x, dimension_y, dimension_z;
    
    public:
        std::vector<Point> &get_points();
    
    private:
        std::vector<Point> &generate_points(int resolution);
        // Surface_mesh create_mesh();

    private:
        std::vector<Point> points;


};


std::vector<Point> find_all_locations(Mymesh &my_mesh, Mytissue &example_tissue, double intersection_percentage, double tolerance);

double compute_intersection_volume(Mymesh &AS, Mytissue &tissue);