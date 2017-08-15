#pragma once
#include "math.h"


#define EPSILON 0.00001

bool traceRayMollerTrumbore(const Vec3& orig, const Vec3& dir,
                            const Vec3& t1, const Vec3& t2, const Vec3& t3,
                            Vec3& result)
{
    Vec3 first(t2 - t1);
    Vec3 second(t3 - t1);

    Vec3 pvec = cross(dir, second);

    auto det = dot(first, pvec);

    if (fabs(det) < EPSILON)
    {
        return false;
    }

    auto inv_det = 1.0 / det;

    Vec3 tvec(orig - t1);

    auto u = dot(tvec, pvec) * inv_det;

    if (u < 0.0 || u > 1.0)
    {
        return false;
    }

    Vec3 qvec = cross(tvec, first);

    auto v = dot(dir, qvec) * inv_det;

    if (v < 0.0 || u + v > 1.0)
    {
        return false;
    }

    auto t = dot(second, qvec) * inv_det;

    if(t < 0)
    {
        return false;
    }

    result =  orig + t * dir;

    return true;
}
