template<typename T>
class Vector3d {
public:
    Vector3d(T x, T y, T z) : x_(x), y_(y), z_(z){}

    Vector3d<T>& operator+=(const Vector3d<T>& rhs)
    {
        x_ += rhs.x_;
        y_ += rhs.y_;
        z_ += rhs.z_;
        return *this;
    }

    friend Vector3d<T>& operator+(Vector3d<T>& lhs, const Vector3d<T>& rhs)
    {
        lhs += rhs;
        return lhs;
    }
    friend Vector3d<T>& operator-(Vector3d<T>& lhs, const Vector3d<T>& rhs)
    {
        lhs -= rhs;
        return lhs;
    }
    friend Vector3d<T>& operator*(Vector3d<T>& lhs, const Vector3d<T>& rhs)
    {
        lhs *= rhs;
        return lhs;
    }
    friend Vector3d<T>& operator/(Vector3d<T>& lhs, const Vector3d<T>& rhs)
    {
        lhs /= rhs;
        return lhs;
    }
private:
    T x_;
    T y_;
    T z_;
};