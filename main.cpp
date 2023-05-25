#include "corridor.h"
#include <time.h>

int main(int argc, char **argv)
{
    srand( (unsigned)time( NULL ) );
    // std::string file_path = std::string(argv[1]);
    // double intersection_percentage = std::stod(argv[2]);
    // double tolerance = std::stod(argv[3]);
    
    // Mymesh AS(file_path);
    // AS.create_aabb_tree();

    // Mytissue example_tissue(0.0, 0.0, 0.0, 0.005, 0.005, 0.005);

    // std::vector<Point> center_path = find_all_locations(AS, example_tissue, intersection_percentage, tolerance);

    std::string file_path_1 = std::string(argv[1]);
    std::string file_path_2 = std::string(argv[2]);
    double tolerance = std::stod(argv[3]);

    std::vector<Mymesh> meshes;
    meshes.push_back(Mymesh(file_path_1));
    meshes.push_back(Mymesh(file_path_2));
    std::cout << "mesh number: " << meshes.size() << std::endl;
    for (Mymesh &mesh: meshes) mesh.create_aabb_tree();

    std::vector<double> intersection_percnts{0.500, 0.500};
    Mytissue example_tissue(0.0, 0.0, 0.0, 0.005, 0.005, 0.005);

    // std::vector<Point> center_path = create_point_cloud_corridor_for_multiple_AS(meshes, example_tissue, intersection_percnts, tolerance);
    // std::cout << "number of points: " << center_path.size() << std::endl;

    // // std::string output_file_path = "center_path_" + std::to_string(intersection_percentage[0]) + "_" + std::to_string(tolerance) + ".off"; 
    
    // std::string output_file_path = "center_path_multiple_AS.off";
    // std::ofstream center_path_off(output_file_path);
    // Surface_mesh center_path_mesh;
    // for (Point &p: center_path) center_path_mesh.add_vertex(p);
    // center_path_off << center_path_mesh; 

    Surface_mesh corridor_mesh = create_corridor(meshes, example_tissue, intersection_percnts, tolerance);
    std::string corridor_file_path = "corridor_pyramid_a.off";
    std::ofstream corridor_output(corridor_file_path);
    corridor_output << corridor_mesh;

}