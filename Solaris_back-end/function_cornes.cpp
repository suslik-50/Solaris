#include "function_cornes.h"

solar_battery_salleter fun_cornes(vec san,vector_salleter salleter)
{

    vec er,en,et,zv,s;
    double zvm;
    //er
    double r=sqrt((salleter.x*salleter.x)+(salleter.y*salleter.y)+(salleter.z*salleter.z));

    er.x=salleter.x/r;
    er.y=salleter.y/r;
    er.z=salleter.z/r;
    //en
    zv.x=salleter.y*salleter.vz- salleter.z*salleter.vy;
    zv.y=salleter.z*salleter.vx- salleter.x*salleter.vz;
    zv.z=salleter.x*salleter.vy- salleter.y*salleter.vx;

    zvm=sqrt((zv.x*zv.x)+(zv.y*zv.y)+(zv.z*zv.z));

    en.x=zv.x/zvm;
    en.y=zv.y/zvm;
    en.z=zv.z/zvm;
    //eтау
    et.x=en.y*er.z-en.z*er.y;
    et.y=en.z*er.x-en.x*er.z;
    et.z=en.x*er.y-en.y*er.z;
    //  S ocк
    s.x=san.x*er.x+san.y*er.y+san.z*er.z;
    s.y=san.x*et.x+san.y*et.y+san.z*et.z;
    s.z=san.x*en.x+san.y*en.y+san.z*en.z;

    //a,b
    double sinA=s.x;
    double cosA=sqrt(1-(s.x*s.x));
    //
    if (cosA==0){
        cosA=0.00001;

    }
    double sinB=-(s.y/cosA);
    double cosB=s.z/cosA;

    // радианы
    double a=atan2(sinA,cosA);
    double b=atan2(sinB,cosB);

    solar_battery_salleter corne;
    corne.a=a*(45.0/atan(1)); // градусы
    corne.b=b*(45.0/atan(1)); //
    corne.name=salleter.name;
    corne.time=salleter.time;


    return corne;
}
