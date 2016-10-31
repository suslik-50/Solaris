#ifndef COMMAND_PARSER2_H
#define COMMAND_PARSER2_H

#include "main_module.h"
#include <setting.h>
#include<boost/program_options.hpp>
namespace po = boost::program_options;
class command_parser2
{
  main_module *module;
 // po::variables_map vm;
  public:command_parser2(main_module &man_m);
  public: QByteArray command(QString cmd);
};


#endif // COMMAND_PARSER2_H
