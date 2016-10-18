#include "command_parser.h"
#include <QStringList>
command_parser::command_parser(main_module &man_m)
{
    module=&man_m;

}

QByteArray command_parser::command(QString cmd)
{
    QStringList shortList = cmd.split(' ');
    bytes="";
    if (shortList.first()=="start")
    {
        if (shortList.size()>1){
            if (shortList[1]=="all")
            {
                if (shortList.size()>2){
                    if (shortList[2]=="salleter")
                    {
                      //  bytes.append("Старт вычисления всех потоков спутника\r\n");
                        module->start_all_salleter();
                    }
                    else
                    {
                        bytes.append("Команда не найдена\r\n");

                    }
                }
                else
                {
                    bytes.append("Команда не найдена\r\n");

                }
            }
            else if (shortList[1]=="salleter")
            {
                if (shortList.size()>2){
                    bytes.append("Старт вычеслений спутника"+shortList[2]+"r\n");


                    module->start_salleter(shortList[2]);
                }
                else{
                    bytes.append("Введите имя спутника\r\n");
                }
            }
            else if (shortList[1]=="sun")
            {
                module->start_sun();
            }
            else
            {
                bytes.append("Команда не найдена\r\n");
            }
        }
        else
        {
            bytes.append("Команда не найдена\r\n");
        }
    }
    else if (shortList.first()=="stop")
    {
        if (shortList.size()>1){
            if (shortList[1]=="all" )
            {
                if (shortList.size()>2){
                    if (shortList[2]=="salleter")
                    {
                        bytes.append("Остановка вычисления всех потоков спутника\r\n");
                        module->stop_all_salleter();
                    }
                    else{
                        bytes.append("Команда не найдена\r\n");
                    }
                }
                else
                {
                    bytes.append("Команда не найдена\r\n");
                }
            }
            else if (shortList[1]=="salleter")
            {
                bytes.append("Остановка вычисления  потока спутника"+shortList[2]+"\r\n");
                module->stop_salleter(shortList[2]);
            }
            else if (shortList[1]=="sun")
            {

                module->stop_sun();
            }
            else
            {
                bytes.append("Команда не найдена\r\n");
            }
        }
        else{
            bytes.append("Команда не найдена\r\n");
        }
    }else if (shortList.first()=="replay")
    {
        if (shortList.size()>2){
            if (shortList[2].toInt()){
                if (shortList[1]=="salleter")
                {
                    bytes.append("Установлено повторение выичесление местоположения спутника каждые-"+shortList[2]+"сек.\r\n");
                    module->replay_salleter(shortList[2].toInt());

                }else if (shortList[1]=="sun"){
                    bytes.append("Установлено повторение выичесление местоположения солнца каждые-"+shortList[2]+"сек.\r\n");
                    module->replay_sun(shortList[2].toInt());
                }
                else
                {
                    bytes.append("Команда не найдена\r\n");
                }
            }
            else{
                bytes.append("Введите число\r\n");
            }
        }
        else{
            bytes.append("Команда не найдена\r\n");
        }
    }
    else if (shortList.first()=="debug")
    {
        if (shortList.size()>2){
            if (shortList[1]=="salleter")
            {
                if (shortList[2]=="false" || shortList[2]=="true")
                {
                    bytes.append("Установлен debug salleter ="+shortList[2]+"\r\n");
                    module->qdebug_salleter(shortList[2] == "true" ? true : false);
                }
                else{
                    bytes.append("Неверный параметр (true/false)\r\n");
                }
            }else if (shortList[1]=="sun")
            {
                if (shortList[2]=="false" || shortList[2]=="true")
                {
                    bytes.append("Установлен debug sun ="+shortList[2]+"\r\n");
                    module->qdebug_sun(shortList[2] == "true" ? true : false);
                }
                else{
                    bytes.append("Неверный параметр (true/false)\r\n");
                }
            }
            else if (shortList[1]=="corners_solar_battery")
            {
                if (shortList[2]=="false" || shortList[2]=="true")
                {
                    bytes.append("Установлен debug corners_solar_battery ="+shortList[2]+"\r\n");
                    module->qdebug_corners_solar_battery(shortList[2] == "true" ? true : false);
                }
                else{
                    bytes.append("Неверный параметр (true/false)\r\n");
                }
            }else if (shortList[1]=="module_modul"){
                if (shortList[2]=="false" || shortList[2]=="true")
                {
                    bytes.append("Установлен debug module_modul ="+shortList[2]+"\r\n");
                    file_setting.Set_qdebug_main_modul(shortList[2] == "true" ? true : false);
                }
                else
                {
                    bytes.append("Неверный параметр (true/false)\r\n");
                }
            }else{
                bytes.append("Команда не найдена\r\n");
            }
        }
    } else if (shortList.first()=="clean"){
        if (shortList.size()>1){
            if (shortList[1]=="record_drain")
            {
                bytes.append("Пул углов отчищен\r\n");
                module->clean_record_drain();
            }
            else{
                bytes.append("Команда не найдена\r\n");
            }
        }
        else{
            bytes.append("Команда не найдена\r\n");
        }
    } else if (shortList.first() == "get")
    {
        if (shortList.size()>1){
            if(shortList[1]=="count_record_drain")
            {
                int kol=module->get_count_record_drain();
                QString s;
                s.setNum(kol);
                bytes.append("Количество записей в в пуле значений = "+s+"\r\n");
            }
            else if (shortList[1]=="value_corners_salleter")
            {
                if (shortList.size()>2 && shortList[2]!=" "){
                    solar_battery_salleter s;
                    s=module->get_value_corners_salleter(shortList[2]);
                    QString a,b;
                    a.setNum(s.a);
                    b.setNum(s.b);
                    bytes.append("Углы спутника "+s.name+" a-"+a+", b-"+b+"\r\n");


                }
                else{
                    bytes.append("Имя спутника не задано\r\n");
                }
            }
            else {
                bytes.append("Команда не найдена\r\n");

            }
        }
        else
        {
            bytes.append("Команда не найдена\r\n");
        }
    } else if (shortList.first()=="update")
    {
        if (shortList[1]=="salleter"){
            if (shortList.size()>7 || shortList.size()==8 ){
                QString name;
                double time_ut,a,e,i,ark_per,dolgot;
                name=shortList[2];
                time_ut=shortList[3].toDouble();
                a=shortList[4].toDouble();
                e=shortList[5].toDouble();
                i=shortList[6].toDouble();
                ark_per=shortList[7].toDouble();
                dolgot=shortList[8].toDouble();
                module->updata_salleter(a,e,i,dolgot,ark_per,time_ut,name);
                bytes.append("Спутник данные спутника"+name+"обновлены\r\n");
            }

            else{
                bytes.append("Недостаточно переменных\r\n");
            }
        }
        else {
            bytes.append("Команда не найдена\r\n");
        }
    } else if(shortList.first()=="new")
    {  if (shortList[1]=="salleter")
        {
            if (shortList.size()>8 || shortList.size()==9 ){
                QString name;
                double time_ut,a,e,i,ark_per,dolgot,m;
                name=shortList[2];
                time_ut=shortList[3].toDouble();
                a=shortList[4].toDouble();
                e=shortList[5].toDouble();
                i=shortList[6].toDouble();
                ark_per=shortList[7].toDouble();
                dolgot=shortList[8].toDouble();
                m=shortList[9].toDouble();
                module->new_salleter(name,time_ut,a,e,i,ark_per,dolgot,m);
                bytes.append("Спутник добавлен в бд и запущен\r\n");
            }
            else{
                bytes.append("Недостаточно переменных\r\n");
            }
        } else   if (shortList[1]=="salleter_to_date_base")
        {
            if (shortList.size()>8 ||shortList.size()==9 ){
                QString name;
                double time_ut,a,e,i,ark_per,dolgot,m;
                name=shortList[2];
                time_ut=shortList[3].toDouble();
                a=shortList[4].toDouble();
                e=shortList[5].toDouble();
                i=shortList[6].toDouble();
                ark_per=shortList[7].toDouble();
                dolgot=shortList[8].toDouble();
                m=shortList[9].toDouble();
                module->set_new_salleter_to_date_base(name,time_ut,a,e,i,ark_per,dolgot,m);
                bytes.append("Спутник добавлен в бд и запущен\r\n");
            }
            else{
                bytes.append("Недостаточно переменных\r\n");


            }
        }
        else {
            bytes.append("Команда не найдена\r\n");
        }
    }else if (shortList.first()=="telnet")
    {
        if (shortList.size()>1){
            if (shortList[1]=="port")
            {
                if (shortList.size()>2 || shortList[2].toInt() ){
                    file_setting.Set_telnet_port(shortList[2].toInt());
                    bytes.append("Порт telnet изменен на "+shortList[2]+"\r\n");
                }
                else{
                    bytes.append("Команда не найдена\r\n");
                }
            }else
            {
                bytes.append("Команда не найдена\r\n");
            }
        }
        else{
            bytes.append("Команда не найдена\r\n");
        }
    } else if (shortList.first()=="delete"){
        if (shortList.size()>=4){
            if (shortList[1]=="potoc" && shortList[2]=="salleter"){
               module->delete_potoc_salleter(shortList[3]);
            }
            else{
                bytes.append("Команда не найдена++\r\n");
            }

        if (shortList[1]=="data" && shortList[2]=="salleter"){
            module->delete_potoc_salleter(shortList[3]);
        }
        else{
            bytes.append("Команда не найдена++\r\n");
        }
      }
        else{
            bytes.append("Команда не найдена--\r\n");
        }
     }
    ///
    else if (shortList.first()=="help")
    {
        bytes.append("Доступные команды\r\n");
        bytes.append("start all salleter - Запуск всех потоков спутника\r\n"); //+
        bytes.append("start salleter <name>- Запуск потока спутника\r\n"); //+
        bytes.append("start sun -Запуск потока вычисления мстоположения спутника\r\n"); //+
        bytes.append("stop all salleter - Остановка всех спутников\r\n"); //+
        bytes.append("stop salleter <name>-Остановка вычисление спутника \r\n"); //+
        bytes.append("stop san - Остановка потка вычислений солнца\r\n"); //+
        bytes.append("replay salleter <int>-Установка повтора вычислений для потоков спутников\n\r"); //+
        bytes.append("replay sun <int> - Установка повтора вычислений для потока солнца\n\r"); //+
        bytes.append("debug salleter <true/false> - Вывод  в терменал дополнительных данных из потоков спутнков\n\r"); //+
        bytes.append("debug sun <true/false> - Вывод  в терменал дополнительных данных из  потока солнца\n\r"); //+
        bytes.append("debug corners_solar_battery <true/false> - Вывод  в терменал дополнительных данных из пула значений\n\r"); //+
        bytes.append("debug main_modul <true/false> - Вывод  в терменал дополнительных данных из main_module\n\r");  //+
        bytes.append("clean record_drain -Отчиска пула значений углов\n\r"); //+
        bytes.append("get count_record_drain -Возращает количество значений в пуле\n\r"); //+
        bytes.append("get value_corners_salleter <name>-Возращает углы а,b спутника\n\r"); //+
        bytes.append("new salleter<name,time_ut,a,e,i,ark_per,dolgot,m>-добавление нового спутника в бд и запуск расчетов\n\r");
        bytes.append("new salleter_to_date_base<name,time_ut,a,e,i,ark_per,dolgot,m>-добавление нового спутника в бд\n\r");
        bytes.append("update sallete<name,time_ut,a,e,i,ark_per,dolgot,m>-обнавление данных спутника \n\r");
        bytes.append("delete potoc salleter <name>-удаление потока из памяти и удаление всех данных из оперативной памяти потока \n\r");
        bytes.append("delete data salleter <name>-удаление спутника из базы дынных\n\r");
        bytes.append("telnet port <int>-Изменит порт подключения по telnet,изменения вступят всилу только после перезарузки программы \n\r"); //+
    }
    else
    {
        bytes.append("Команда не найдена!!\r\n");
    }
    return bytes;
}
