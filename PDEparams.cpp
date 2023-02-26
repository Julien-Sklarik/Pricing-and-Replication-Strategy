#include <iostream>
#include <cmath>
#include "PDEparams.h"

pde_params::pde_params(std::map<std::string, std::string> parameters){
  spatial_differencing_points = std::stof(parameters["spatial_differencing_points"]);
  temporal_differencing_points = std::stof(parameters["temporal_differencing_points"]);
}