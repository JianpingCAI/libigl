#include <igl/readOFF.h>
#include <igl/viewer/Viewer.h>
#include <igl/jet.h>

Eigen::MatrixXd V;
Eigen::MatrixXi F;
Eigen::MatrixXd C;

int main(int argc, char *argv[])
{
  // Load a mesh in OFF format
  igl::readOFF("../shared/screwdriver.off", V, F);

  // Plot the mesh
  igl::viewer::Viewer viewer;
  viewer.data.set_mesh(V, F);

  // Use the z coordinate as a scalar field over the surface
  Eigen::VectorXd Z = V.col(2);

  // Compute per-vertex colors
  igl::jet(Z,true,C);

  // Add per-vertex colors
  viewer.data.set_colors(C);

  // Launch the viewer
  viewer.launch();
}
