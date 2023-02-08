#include "corridor.h"


Mytissue::Mytissue(double c_x, double c_y, double c_z, double d_x, double d_y, double d_z)
{
    center_x = c_x;
    center_y = c_y;
    center_z = c_z;

    dimension_x = d_x;
    dimesnion_y = d_y;
    dimension_z = d_z;

    generate_points();
}

// compute intersection volume between a mesh and a axis-aligned tissue 
double Mytissue::compute_intersection_volume(Mymesh &mesh)
{
    double percentage = mesh.percentage_points_inside(points);
    double volume = percentage * dimension_x * dimension_y * dimension_z;
    
    return volume;
    
}


std::vector<Point> &Mytissue::generate_points(int resolution=10)
{

    double min_x = center_x - dimension_x/2, min_y = center_y - dimension_y/2, min_z = center_z - dimension_z/2;
    double max_x = center_x + dimension_x/2, max_y = center_y + dimension_y/2, max_z = center_z + dimension_z/2; 
    double delta_x = (max_x - min_x) / resolution, delta_y = (max_y - min_y) / resolution, delta_z = (max_z - min_z) / resolution;    
  

    for (int i = 0; i < resolution; i++)
        for (int j = 0; j < resolution; j++)
            for (int k = 0; k < resolution; k++)
            {
                double c_x = min_x + (i + 0.5) * delta_x;
                double c_y = min_y + (j + 0.5) * delta_y;
                double c_z = min_z + (k + 0.5) * delta_z;
                
                Point p(c_x, c_y, c_z);
                points.push_back(p); 
            }
    
    return points;
}


std::vector<Point> find_all_locations(Mymesh &my_mesh, Mytissue &example_tissue)
{

    std::vector<Point> center_path;

    double example_intersection_volume = example_tissue.compute_intersection_volume(my_mesh);
    double tolerance = 0.1;

    double step_x = example_tissue.dimension_x / 10;
    double step_y = example_tissue.dimension_y / 10;
    double step_z = example_tissue.dimension_z / 10;

    double example_d_x = example_tissue.dimension_x;
    double example_d_y = example_tissue.dimension_y;
    double example_d_z = example_tissue.dimension_z;

    Surface_mesh mesh = my_mesh.get_raw_mesh();
    CGAL::Bbox_3 bbox = PMP::bbox(mesh);

    double x_min = bbox.xmin();
    double y_min = bbox.ymin();
    double z_min = bbox.zmin();
    double x_max = bbox.xmax();
    double y_max = bbox.ymax();
    double z_max = bbox.zmax();

    for (double c_x = x_min - example_d_x / 2; c_x < x_max + example_d_x / 2; c_x += step_x)
        for (double c_y = y_min - example_d_y / 2; c_y < y_max + example_d_y / 2; c_y += step_y)
            for (double c_z = z_min - example_d_z / 2; c_z < z_max + example_d_z / 2; c_z += step_z)
            {
                Mytissue cur_tissue(c_x, c_y, c_z, example_d_x, example_d_y, example_d_z);
                double intersection_volume = cur_tissue.compute_intersection_volume(my_mesh);
                
                if (abs(intersection_volume - example_intersection_volume) <= tolerance * example_intersection_volume)
                    center_path.push_back(Point(c_x, c_y, c_z));

            }
    

}