#include "ed_vector_salleter.h"
#include <math.h>
#include <QDebug>
ed_vector_salleter::ed_vector_salleter()
{

}

vector_s ed_vector_salleter::et(double x, double y, double z, double vx, double vy, double vz)
{

    double rc[3];
    double v[3];
    double r;
    double er[3];
    double rv[3];
    double modrv;
    double en[3];
    double et[3];
    vector_s vec;
    rc[0]=x;
    rc[1]=y;
    rc[2]=z;

    v[0]=vx;
    v[1]=vy;
    v[2]=vz;

    r=sqrt(pow(rc[0],2)+pow(rc[1],2)+pow(rc[2],2));

    er[0]=rc[0]*(1/r);
    er[1]=rc[1]*(1/r);
    er[2]=rc[2]*(1/r);

    rv[0]=rc[1]*v[2]-rc[2]*v[1];
    rv[1]=rc[2]*v[0]-rc[0]*v[2];
    rv[2]=rc[0]*v[1]-rc[1]*v[0];

    modrv=sqrt(rv[0]*rv[0]+rv[1]*rv[1]+rv[2]*rv[2]);

    en[0]=rv[0]*(1/modrv);
    en[1]=rv[1]*(1/modrv);
    en[2]=rv[2]*(1/modrv);

    et[0]=en[1]*er[2]-en[2]*er[1];
    et[1]=en[2]*er[0]-en[0]*er[2];
    et[2]=en[0]*er[1]-en[1]*en[0];


    vec.x=et[0];
    vec.y=et[1];
    vec.z=et[2];

    return vec;
}
