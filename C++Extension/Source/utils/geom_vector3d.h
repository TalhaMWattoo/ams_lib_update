/*
 * ---------------------------------------------------------------------------------------------------------------------
 *
 * Copyright (C) 2018, Anton Synytsia
 *
 * ---------------------------------------------------------------------------------------------------------------------
 */

#ifndef GEOM_VECTOR3D_H
#define GEOM_VECTOR3D_H

#include "geom.h"


// Global friend operator declaration
// https://stackoverflow.com/questions/2207219/how-do-i-define-friends-in-global-namespace-within-another-c-namespace

bool operator == (const Geom::Vector3d& lhs, const Geom::Vector3d& rhs);
bool operator != (const Geom::Vector3d& lhs, const Geom::Vector3d& rhs);

Geom::Vector3d operator * (Geom::Vector3d v, treal scalar);
Geom::Vector3d operator / (Geom::Vector3d v, treal scalar);
Geom::Vector3d operator * (treal scalar, Geom::Vector3d v);
Geom::Vector3d operator + (Geom::Vector3d lhs, const Geom::Vector3d& rhs);
Geom::Vector3d operator - (Geom::Vector3d lhs, const Geom::Vector3d& rhs);

class Geom::Vector3d
{
public:
    // Variables
    treal m_x, m_y, m_z;

    // Constants
    static const Vector3d ORIGIN;
    static const Vector3d X_AXIS;
    static const Vector3d Y_AXIS;
    static const Vector3d Z_AXIS;

    // Constructors
    Vector3d();
    Vector3d(treal value);
    Vector3d(const Vector3d& other);
    Vector3d(treal x, treal y, treal z);
    Vector3d(const treal* values);

    // Operators
    friend bool (::operator ==) (const Geom::Vector3d& lhs, const Geom::Vector3d& rhs);
    friend bool (::operator !=) (const Geom::Vector3d& lhs, const Geom::Vector3d& rhs);

    friend Geom::Vector3d (::operator *) (Geom::Vector3d v, treal scalar);
    friend Geom::Vector3d (::operator /) (Geom::Vector3d v, treal scalar);
    friend Geom::Vector3d (::operator *) (treal scalar, Geom::Vector3d v);
    friend Geom::Vector3d (::operator +) (Geom::Vector3d lhs, const Geom::Vector3d& rhs);
    friend Geom::Vector3d (::operator -) (Geom::Vector3d lhs, const Geom::Vector3d& rhs);

    Vector3d& operator = (const Vector3d& other);
    treal& operator [] (const int index);
    const treal& operator [] (const int index) const;

    Vector3d& operator *= (treal scalar);
    Vector3d& operator /= (treal scalar);
    Vector3d& operator *= (const Vector3d& other);
    Vector3d& operator /= (const Vector3d& other);
    Vector3d& operator += (const Vector3d& other);
    Vector3d& operator -= (const Vector3d& other);

    // Functions
    treal get_length_squared() const;
    treal get_length() const;
    Vector3d& set_length(treal length);
    Vector3d& normalize_self();
    Vector3d normalize() const;
    Vector3d& scale_self(treal s);
    Vector3d scale(treal s) const;
    Vector3d& reverse_self();
    Vector3d reverse() const;
    void zero_out();
    void set_all(treal value);
    treal dot(const Vector3d& other) const;
    Vector3d cross(const Vector3d& other) const;
    Vector3d product(const Vector3d& other) const;
    Vector3d& product_self(const Vector3d& other);
    Vector3d transition_to(const Vector3d& other, treal ratio) const;
    Vector3d rotate_to(const Vector3d& other, treal ratio) const;
    Vector3d rotate_and_scale_to(const Vector3d& other, treal ratio) const;
    Vector3d rotate(const Vector3d& normal, treal angle) const;
    treal angle_between(const Vector3d& other) const;
    treal angle_between(const Vector3d& other, const Vector3d& normal) const;

    bool is_valid() const;
    bool is_parallel_to(const Vector3d& other) const;
    bool is_same_direction_as(const Vector3d& other) const;
    bool is_aniparallel_to(const Vector3d& other) const;
};

// Define inline functions here

inline treal& Geom::Vector3d::operator [] (const int index) {
    return (&m_x)[index];
}

inline const treal& Geom::Vector3d::operator [] (const int index) const {
    return (&m_x)[index];
}

inline bool operator == (const Geom::Vector3d& lhs, const Geom::Vector3d& rhs) {
    return (fabs(lhs.m_x - rhs.m_x) < M_EPSILON &&
        fabs(lhs.m_y - rhs.m_y) < M_EPSILON &&
        fabs(lhs.m_z - rhs.m_z) < M_EPSILON);
}

inline bool operator != (const Geom::Vector3d& lhs, const Geom::Vector3d& rhs) {
    return !(lhs == rhs);
}

inline bool Geom::Vector3d::is_valid() const {
    return m_x == m_x && m_y == m_y && m_z == m_z;
}

inline bool Geom::Vector3d::is_same_direction_as(const Vector3d& other) const {
    return normalize() == other.normalize();
}

inline bool Geom::Vector3d::is_aniparallel_to(const Vector3d& other) const {
    return normalize() == other.normalize().reverse();
}

inline Geom::Vector3d& Geom::Vector3d::normalize_self() {
    return set_length(1.0);
}

inline Geom::Vector3d Geom::Vector3d::scale(treal s) const {
    return Vector3d(m_x * s, m_y * s, m_z * s);
}

#endif /* GEOM_VECTOR3D_H */
