#pragma once

#include <valarray>

struct Vector2 {
    double X;
    double Y;

    Vector2() : X(0), Y(0) {}
    Vector2(double x, double y) : X(x), Y(y) {}

    Vector2 operator+(const Vector2& other) const {
        return {X + other.X, Y + other.Y};
    }

    Vector2 operator-(const Vector2& other) const {
        return {X - other.X, Y - other.Y};
    }

    Vector2 operator*(double scalar) const {
        return {X * scalar, Y * scalar};
    }

    Vector2 operator/(double scalar) const {
        return {X / scalar, Y / scalar};
    }

    Vector2& operator+=(const Vector2& other) {
        X += other.X;
        Y += other.Y;
        return *this;
    }

    Vector2& operator-=(const Vector2& other) {
        X -= other.X;
        Y -= other.Y;
        return *this;
    }

    Vector2& operator*=(double scalar) {
        X *= scalar;
        Y *= scalar;
        return *this;
    }

    Vector2& operator/=(double scalar) {
        X /= scalar;
        Y /= scalar;
        return *this;
    }

    bool operator==(const Vector2& other) const {
        return X == other.X && Y == other.Y;
    }

    bool operator!=(const Vector2& other) const {
        return X != other.X || Y != other.Y;
    }

    double Magnitude() const {
        return sqrt(X * X + Y * Y);
    }

    Vector2 Normalized() const {
        return *this / Magnitude();
    }

    double Dot(const Vector2& other) const {
        return X * other.X + Y * other.Y;
    }

    double Cross(const Vector2& other) const {
        return X * other.Y - Y * other.X;
    }

    double Distance(const Vector2& other) const {
        return (*this - other).Magnitude();
    }

    double Angle(const Vector2& other) const {
        return atan2(Cross(other), Dot(other));
    }

    Vector2 Rotate(double angle) const {
        return Vector2(X * cos(angle) - Y * sin(angle), X * sin(angle) + Y * cos(angle));
    }
};
