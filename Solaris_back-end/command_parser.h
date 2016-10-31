#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H
#include "main_module.h"
#include <setting.h>



class command_parser
{
    main_module *module;
private:setting file_setting;
public: command_parser(main_module &man_m);
public: QByteArray command(QString cmd);
};

#endif // COMMAND_PARSER_H
