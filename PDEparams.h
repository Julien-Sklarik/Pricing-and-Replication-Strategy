#ifndef _PDEparams
#define _PDEparams

#include <iostream>
#include <map>
#include <string>

class pde_params 
{
      public:
        pde_params(std::map<std::string, std::string> parameters);
        double  spatial_differencing_points, temporal_differencing_points;
};

#endif