#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

int main(int argc, char **argv) {
    // Replace "input.off" with the path to your OFF file
    //const char* inputPath = "/home/ubuntu/Desktop/project/ccf-tissue-block-annotation/model/plain_manifold_filling_hole_v1.4/VH_M_Kidney_L/VH_M_renal_papilla_L_a.off";
    //lcr-off-test
    //const char* inputPath = "lcr-off-test.off";

    if (argc < 2)
    {
      std::cout << "Please provide the inputPath and outputPath!" << std::endl;
      return 0;
    }

    const std::string inputPath = std::string(argv[1]);
    // Replace "output.glb" with the desired path for the GLB output file
    //const char* outputPath = "output.glb";
    const std::string outputPath = std::string(argv[2]);
    // Create an Assimp importer
    Assimp::Importer importer;

    // Read the OFF file
    const aiScene* scene = importer.ReadFile(inputPath, aiProcess_Triangulate); //| aiProcess_FlipUVs);

    // // If the import failed, report it
    // if (nullptr == scene) {
    //     DoTheErrorLogging( importer.GetErrorString());
    //     return false;
    // }


    // Check if the scene was successfully loaded
    if (scene) {
        // Create an Assimp exporter
        Assimp::Exporter exporter;

        // Export the scene to GLB format
        exporter.Export(scene, "glb2", outputPath); //aiProcess_Triangulate | aiProcess_FlipUVs);

        std::cout << "Conversion successful. GLB file saved to: " << outputPath << std::endl;
    } else {
        std::cerr << "Error loading the OFF file: " << importer.GetErrorString() << std::endl;
    }

    return 0;
}
