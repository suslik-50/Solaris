#include "command_parser.h"
#include <QStringList>
command_parser::command_parser(main_module &man_m)
{
    module=&man_m;
}
QByteArray command_parser::command(QString cmd)
{
    QStringList shortList = cmd.split(' ');
    QByteArray bytes;
    if (shortList.first()=="prognoz"){
        //расчет всех местоположения спутников от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
        //пример команды
        //prognoz pos_salleter_all 123456 678910
        if (shortList[1]=="pos_salleter_all"){
            if (shortList.count()==4){
                int timeT0;//'timeT0=123456
                int time_end; //time_end=678910
                if(shortList[2].toInt()){
                    timeT0=shortList[2].toInt();
                    if (shortList[3].toInt()){
                        time_end=shortList[3].toInt();
                        module->prognoz1(timeT0,time_end);
                    }
                }
            }
        }




        //расчет всех местоположения спутников от начального времни timeT0 , до конечного time_end шаг задается step
        //пример команды
        //prognoz pos_salleter_all 123456 678910 3
        if (shortList[1]=="pos_salleter_all"){
            if (shortList.count()==5){
                int timeT0; //timeT0=123456
                int time_end; //time_end=678910
                int step; //step=3
                if(shortList[2].toInt()){
                    timeT0=shortList[2].toInt();
                    if (shortList[3].toInt()){
                        time_end=shortList[3].toInt();
                        if (shortList[4].toInt()){
                            step=shortList[4].toInt();
                            module->prognoz2(timeT0,time_end,step);
                        }
                    }
                }
            }
        }

        //расчет всех местоположения спутников на время time
        //прмер команды
        //prognoz pos_salleter_all 123456

        if (shortList[1]=="pos_salleter_all"){
            if (shortList.count()==3){
                if (shortList[2].toInt()){
                    int time; // time=123456
                    time=shortList[2].toInt();
                    module->prognoz3(time);
                }
            }
        }



        //расчет местоположения спутника от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
        // пример команды
        // prognoz pos_salleter 12345 678910 salleter1
        if (shortList[1]=="pos_salleter"){
            int timeT0; //timeT0=12345
            int time_end; //time_end=678910
            QString name; //name=salleter1;
            if (shortList.count()==5){
                if (shortList[2].toInt()){
                    timeT0=shortList[2].toInt();
                    if (shortList[3].toInt()){
                        time_end=shortList[3].toInt();
                        name=shortList[4];
                        module->prognoz4(timeT0,time_end,name);
                    }
                }
            }
        }


        //расчет местоположения спутника от начального времни timeT0 , до конечного time_end шаг задается step
        // пример команды
        // prognoz pos_salleter 12345 678910  1 salleter2
        if (shortList[1]=="pos_salleter")
        {
            if (shortList.count()==6){
                int timeT0; //timeT0=12345
                int time_end; //time_end=678910
                QString name; //name=salleter2;
                int step; //step=1;
                if (shortList[2].toInt()){
                    timeT0=shortList[2].toInt();
                    if (shortList[3].toInt()){
                        time_end=shortList[3].toInt();
                        if (shortList[4].toInt()){
                            step=shortList[4].toInt();
                            name=shortList[5];
                            module->prognoz5(timeT0,time_end,name,step);
                        }

                    }
                }
            }
        }



        //расчет местоположения спутника на время time
        // пример команды
        // prognoz pos_salleter 12345 salleter2
        if (shortList[1]=="pos_salleter")
        {
            if (shortList.count()==4){
                int time;
                QString name;
                if (shortList[2].toInt()){
                    time=shortList[2].toInt();
                    name=shortList[3];
                    module->prognoz6(name,time);
                }
            }
        }

        //расчет для нескольких спутнкиков имена спутников задаются в QList<QString>
        //пример команды
        //prognoz grup_pos_salleter 12345 678910 1 sputnik1 sputnik2 sputnik3
        //или prognoz grup_pos_salleter 12345 678910 sputnik1 sputnik2 sputnik3
        //или prognoz grup_pos_salleter 12345 sputnik1 sputnik2 sputnik3
        if (shortList[1]=="grup_pos_salleter")
        {
            if (shortList.count()>=5){
                int  timeT0; //timeT0=12345
                int  time_end; //time_end=678910
                int  step;
                QList<QString> namesalleter;//<-sputnik1 sputnik2 sputnik3
                // prognoz grup_pos_salleter 12345 678910 1 sputnik1 sputnik2 sputnik3
                if (shortList[2].toInt() && shortList[3].toInt() &&shortList[4].toInt()){
                    timeT0=shortList[2].toInt();
                    time_end=shortList[3].toInt();
                    step=shortList[4].toInt();
                    //перед добавление в QList спутников проверять на существование таких  в бд
                    for(int i=5;i<shortList.count();i++){
                        namesalleter.append(shortList[i]);
                    }
                    module->prognoz8(timeT0,time_end,step,namesalleter);
                }else
                {
                    // prognoz grup_pos_salleter 12345 678910 sputnik1 sputnik2 sputnik3
                    if (shortList[2].toInt() && shortList[3].toInt())
                    {
                        timeT0=shortList[2].toInt();
                        time_end=shortList[3].toInt();
                        for(int i=4;i<shortList.count();i++){
                            namesalleter.append(shortList[i]);
                        }
                        module->prognoz7(timeT0,time_end,namesalleter);
                    }
                    else
                    {
                        // prognoz grup_pos_salleter 12345 sputnik1 sputnik2 sputnik3
                        if (shortList[2].toInt())
                        {
                            timeT0=shortList[2].toInt();
                            for(int i=3;i<shortList.count();i++){
                                namesalleter.append(shortList[i]);
                            }
                             module->prognoz9(timeT0,namesalleter);
                        }
                    }
                }
            }
        }
    }else
        if (shortList.first()=="start")
        {
            if (shortList.size()>1){
                if (shortList[1]=="all")
                {
                    if (shortList.size()>2){
                        if (shortList[2]=="salleter")
                        {
                            int otvet=module->start_all_salleter();
                            if (otvet==0){
                                bytes.append("Старт вычисления всех потоков спутника\r\n");
                            }
                            if(otvet==1){
                                bytes.append("Старт вычисления всех потоков спутник, данные взяты из памяти\r\n");
                            }
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
                        int otvet=module->start_salleter(shortList[2]);
                        if(otvet==0){
                            bytes.append("Старт вычеслений спутника "+shortList[2]+"r\n");
                        }
                        if(otvet==1){
                            bytes.append("Поток спутника не найден "+shortList[2]+"r\n");
                        }
                    }
                    else{
                        bytes.append("Введите имя спутника\r\n");
                    }
                }
                else if (shortList[1]=="sun")
                {
                    module->start_sun();
                    bytes.append("Поток вычисления местоположения солнца запущен\r\n");
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

                            int otvet =module->stop_all_salleter();
                            if (otvet==0){
                                bytes.append("Остановка вычисления всех потоков спутника\r\n");
                            }
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
                    bytes.append("Поток вычисления местоположения солнца остановлен\r\n");
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
                    bytes.append("Третие значение должно быть типа Integer\r\n");
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
            if (shortList.size()>2){
                if (shortList[1]=="record_drain"){
                    if (shortList[2]!=" "){

                        module->delete_record_drain(shortList[2]);
                        return bytes.append("Пул углов отчищен_\r\n");
                    }
                    else{
                        return bytes.append("Некоректное имя спутника\r\n");
                    }
                }
                else{
                    bytes.append("Команда не найдена\r\n");
                }
            }
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
                    if (shortList[3].toDouble()){
                        time_ut=shortList[3].toDouble();
                    }
                    else {
                        bytes.append("Неврно указынный параметр время, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[4].toDouble()){
                        a=shortList[4].toDouble();
                    }
                    else{
                        bytes.append("Неврно указынный параметр большая полуось, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[5].toDouble()){
                        e=shortList[5].toDouble();
                    }else
                    {
                        bytes.append("Неврно указынный параметр эксонтриситет, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[6].toDouble()){
                        i=shortList[6].toDouble();
                    }else
                    {
                        bytes.append("Неврно указынный параметр угол наклона орбиты, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[7].toDouble()){
                        ark_per=shortList[7].toDouble();
                    }else
                    {
                        bytes.append("Неврно указынный параметр аргумент перригея, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[8].toDouble()){
                        dolgot=shortList[8].toDouble();
                    }else{
                        bytes.append("Неврно указынный параметр долгота восходящего узла, необходим тип double\r\n");
                        return bytes;
                    }

                    int otvet=module->updata_salleter(a,e,i,dolgot,ark_per,time_ut,name);
                    if (otvet==0){
                        bytes.append("Спутник данные спутника "+name+" обновлены\r\n");
                    }else
                        if (otvet==1){
                            bytes.append("Спутник данные спутника "+name+" не найдены\r\n");
                        }
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
                if (shortList.size()>7 || shortList.size()==8 ){
                    QString name;
                    double time_ut,a,e,i,ark_per,dolgot;
                    name=shortList[2];
                    if (shortList[3].toDouble()){
                        time_ut=shortList[3].toDouble();
                    }
                    else {
                        bytes.append("Неврно указынный параметр время, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[4].toDouble()){
                        a=shortList[4].toDouble();
                    }
                    else{
                        bytes.append("Неврно указынный параметр большая полуось, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[5].toDouble()){
                        e=shortList[5].toDouble();
                    }else
                    {
                        bytes.append("Неврно указынный параметр эксонтриситет, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[6].toDouble()){
                        i=shortList[6].toDouble();
                    }else
                    {
                        bytes.append("Неврно указынный параметр угол наклона орбиты, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[7].toDouble()){
                        ark_per=shortList[7].toDouble();
                    }else
                    {
                        bytes.append("Неврно указынный параметр аргумент перригея, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[8].toDouble()){
                        dolgot=shortList[8].toDouble();
                    }else{
                        bytes.append("Неврно указынный параметр долгота восходящего узла, необходим тип double\r\n");
                        return bytes;
                    }

                    module->new_salleter(name,time_ut,a,e,i,ark_per,dolgot);
                    bytes.append("Спутник добавлен в бд и запущен\r\n");
                }
                else{
                    bytes.append("Недостаточно переменных\r\n");
                }
            } else   if (shortList[1]=="salleter_to_date_base")
            {
                if (shortList.size()>7 ||shortList.size()==8 ){
                    QString name;
                    double time_ut,a,e,i,ark_per,dolgot;
                    name=shortList[2];
                    if (shortList[3].toDouble()){
                        time_ut=shortList[3].toDouble();
                    }
                    else {
                        bytes.append("Неврно указынный параметр время, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[4].toDouble()){
                        a=shortList[4].toDouble();
                    }
                    else{
                        bytes.append("Неврно указынный параметр большая полуось, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[5].toDouble()){
                        e=shortList[5].toDouble();
                    }else
                    {
                        bytes.append("Неврно указынный параметр эксонтриситет, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[6].toDouble()){
                        i=shortList[6].toDouble();
                    }else
                    {
                        bytes.append("Неврно указынный параметр угол наклона орбиты, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[7].toDouble()){
                        ark_per=shortList[7].toDouble();
                    }else
                    {
                        bytes.append("Неврно указынный параметр аргумент перригея, необходим тип double\r\n");
                        return bytes;
                    }
                    if(shortList[8].toDouble()){
                        dolgot=shortList[8].toDouble();
                    }else{
                        bytes.append("Неврно указынный параметр долгота восходящего узла, необходим тип double\r\n");
                        return bytes;
                    }
                    int otvet=module->set_new_salleter_to_date_base(name,time_ut,a,e,i,ark_per,dolgot);
                    if (otvet==0){
                        bytes.append("Спутник добавлен в бд\r\n");
                    }else
                        if(otvet==1){
                            bytes.append("Спутник не добавлен в бд\r\n");
                        }
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
                    if (shortList.size()>2){
                        if(shortList[2].toInt()){
                            file_setting.Set_telnet_port(shortList[2].toInt());
                            bytes.append("Порт telnet изменен на "+shortList[2]+"\r\n");
                        }
                        else{
                            bytes.append("Третие значение должнобыть типа Integer, Порт\r\n");
                        }
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

        }else if (shortList.first()=="tcp")
        {
            if (shortList.size()>1){
                if (shortList[1]=="port")
                {
                    if (shortList.size()>2){
                        if(shortList[2].toInt()){
                            file_setting.Set_tcp_port(shortList[2].toInt());
                            bytes.append("Порт tcp изменен на "+shortList[2]+"\r\n");
                        }else{
                            bytes.append("Третие значение должнобыть типа Integer, Порт\r\n");
                        }
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
                    int otvet=module->delete_potoc_salleter(shortList[3]);
                    module->clean_record_drain();
                    if (otvet==0){
                        module->clean_record_drain();
                        bytes.append("Поток спутника "+shortList[3]+" отсановлен и удален из памяти\r\n");
                    }else
                        if(otvet==1){
                            bytes.append("Поток спутника "+shortList[3]+" не найден\r\n");
                        }
                }

                if (shortList[1]=="data" && shortList[2]=="salleter"){
                    int otvet=module->delete_salleter_form_dataBase(shortList[3]);
                    module->clean_record_drain();
                    if (otvet==0){
                        module->clean_record_drain();
                        bytes.append("Данные спутника "+shortList[3]+" удален \r\n");
                    }else
                        if(otvet==1){
                            bytes.append("Данные спутника "+shortList[3]+" не найдены \r\n");
                        }
                }

            }
            else{
                bytes.append("Команда не найдена--\r\n");
            }
        }
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
            bytes.append("tcp port <int>-Изменит порт подключения по tcp,изменения вступят всилу только после перезарузки программы \n\r");
        }
        else
        {
            bytes.append("Команда не найдена!!\r\n");
        }
    return bytes;
}
