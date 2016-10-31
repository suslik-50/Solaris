#include "command_parser2.h"


command_parser2::command_parser2(main_module &man_m)
{
    module=&man_m;
}

QByteArray command_parser2::command(QString cmd)
{
   // po::store(po::parse_command_line(),vm);
    //po::notify(vm);
}
