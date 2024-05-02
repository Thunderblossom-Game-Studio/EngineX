#pragma once

#include <valarray>

struct Vector2 {
    float X;
    float Y;

    Vector2() : X(0), Y(0) {}
    Vector2(float x, float y) : X(x), Y(y) {}

    Vector2 operator+(const Vector2& other) const {
        return Vector2(X + other.X, Y + other.Y);
    }

    Vector2 operator-(const Vector2& other) const {
        return Vector2(X - other.X, Y - other.Y);
    }

    Vector2 operator*(float scalar) const {
        return Vector2(X * scalar, Y * scalar);
    }

    Vector2 operator/(float scalar) const {
        return Vector2(X / scalar, Y / scalar);
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

    Vector2& operator*=(float scalar) {
        X *= scalar;
        Y *= scalar;
        return *this;
    }

    Vector2& operator/=(float scalar) {
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

    float Magnitude() const {
        return sqrt(X * X + Y * Y);
    }

    Vector2 Normalized() const {
        return *this / Magnitude();
    }

    float Dot(const Vector2& other) const {
        return X * other.X + Y * other.Y;
    }

    float Cross(const Vector2& other) const {
        return X * other.Y - Y * other.X;
    }

    float Distance(const Vector2& other) const {
        return (*this - other).Magnitude();
    }

    float Angle(const Vector2& other) const {
        return atan2(Cross(other), Dot(other));
    }

    Vector2 Rotate(float angle) const {
        return Vector2(X * cos(angle) - Y * sin(angle), X * sin(angle) + Y * cos(angle));
    }
};
