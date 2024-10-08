#include "source/exe/main_common.h"
#include <ostream>
#include <iostream>

#ifdef WIN32
#include "source/exe/service_base.h"
#endif

// NOLINT(namespace-envoy)

/**
 * Basic Site-Specific main()
 *
 * This should be used to do setup tasks specific to a particular site's
 * deployment such as initializing signal handling. It calls main_common
 * after setting up command line options.
 */
int main(int argc, char** argv) {
#ifdef WIN32
  Envoy::ServiceBase service;
  if (!Envoy::ServiceBase::TryRunAsService(service)) {
    return Envoy::MainCommon::main(argc, argv);
  }
  return EXIT_SUCCESS;
#endif
  std::cout << "this is the starting of the prog"  << std::endl;
  return Envoy::MainCommon::main(argc, argv);
}
