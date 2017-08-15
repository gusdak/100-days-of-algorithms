#pragma  once
#include <string>

template<typename T>
class TVec3
{
public:
    TVec3() : x(0.0f), y(0.0f), z(0.0f) {};

    TVec3(T x, T y, T z) : x(x), y(y), z(z) {};

    TVec3(const TVec3& tVec3) : x(tVec3.x), y(tVec3.y), z(tVec3.z) {};
    T  x, y, z;
    friend TVec3 operator- (const TVec3& right, const TVec3& left)
    {
        return TVec3(right.x - left.x, right.y - left.y, right.z - left.z);
    }

    friend TVec3 operator+ (const TVec3& right, const TVec3& left)
    {
        return TVec3(right.x + left.x, right.y + left.y, right.z + left.z);
    }

    friend TVec3 operator* (const TVec3& right, float left)
    {
        return TVec3(right.x * left, right.y * left, right.z * left);
    }

    friend TVec3 operator* (float right, const TVec3& left)
    {
        return left * right;
    }

    friend std::ostream& operator<<(std::ostream& right, const TVec3& left)
    {
        right << left.x << " " << left.y << " " << left .z;
        return right;
    }
};
using Vec3 = TVec3<float>;

template<typename T>
inline TVec3<T> cross(const TVec3<T> &left, const TVec3<T> &right)
{
    return TVec3<T>(   left.y * right.z - left.z * right.y,
                       left.z * right.x - left.x * right.z,
                       left.x * right.y - left.y * right.x);
}

template<typename T>
inline T dot(const TVec3<T> &left, const TVec3<T> &right)
{
    return left.x * right.x + left.y * right.y + left.z * right.z;
}