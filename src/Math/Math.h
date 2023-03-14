#pragma once
#define PI 3.1415926535
#include <iostream>
#include <math.h>

namespace NAQH{
	float Pow(float p_a, float p_b);

	float Clamp(float p_number, float p_max, float p_min);

	float Rad2Deg(float p_rad);

	float Deg2Rad(float p_deg);

	float Lerp(float p_a, float p_b, float p_t);

	float Sin(float p_angle);

	float Cos(float p_angle);

	float Tan(float p_angle);

	class Vector2
	{
	public:
		Vector2();
		Vector2(float p_x, float p_y);
		void print();
		void Set(float p_x, float p_y);
		void Normalize();
		float DotProduct(Vector2& p_vector);
		Vector2 Rotate(float p_angle);
		float Magnitude();
		float Distance(Vector2& p_vector);
		Vector2 operator+(float p_number);
		Vector2 operator+(Vector2& p_vector);
		Vector2 operator-(float p_number);
		Vector2 operator-(Vector2& p_vector);
		Vector2 operator*(float p_number);
		Vector2 operator*(Vector2& p_vector);
		Vector2 operator/(float p_number);
		Vector2 operator/(Vector2& p_vector);
		Vector2 operator%(float& p_number);
		Vector2 operator%(Vector2& p_vector);
		Vector2& operator+=(Vector2& p_vector);
		Vector2& operator-=(Vector2& p_vector);
		Vector2& operator*=(Vector2& p_vector);
		Vector2& operator/=(Vector2& p_vector);
		Vector2& operator%=(Vector2& p_vector);
		bool operator==(Vector2& p_vector);
		bool operator!=(Vector2& p_vector);

		float x, y;
	};

	class Vector3
	{
	public:
		Vector3();
		Vector3(float p_x, float p_y, float p_z);
		void print();
		void Set(float p_x, float p_y, float p_z);
		void Normalize();
		float DotProduct(Vector3& p_vector);
		Vector3 CrossProduct(Vector3& p_vector);
		Vector3 Rotate(Vector3 p_axis, float p_angle);
		float Magnitude();
		Vector3 operator+(float p_number);
		Vector3 operator+(Vector3& p_vector);
		Vector3 operator-(float p_number);
		Vector3 operator-(Vector3& p_vector);
		Vector3 operator*(float p_number);
		Vector3 operator*(Vector3& p_vector);
		Vector3 operator/(float p_number);
		Vector3 operator/(Vector3& p_vector);
		Vector3 operator%(float p_number);
		Vector3 operator%(Vector3& p_vector);
		Vector3& operator+=(Vector3& p_vector);
		Vector3& operator-=(Vector3& p_vector);
		Vector3& operator*=(Vector3& p_vector);
		Vector3& operator/=(Vector3& p_vector);
		Vector3& operator%=(Vector3& p_vector);
		bool operator==(Vector3& p_vector);
		bool operator!=(Vector3& p_vector);
		float x, y, z;
	};

	//WIP
	class Vector4
	{
	public:
		Vector4();
		Vector4(float p_x, float p_y, float p_z, float p_w);
		void print();
		Vector4 operator+(Vector4& p_vector);
		Vector4 operator-(Vector4& p_vector);
		Vector4 operator*(Vector4& p_vector);
		Vector4 operator/(Vector4& p_vector);
		Vector4 operator%(Vector4& p_vector);
		bool operator==(Vector4& p_vector);
		bool operator!=(Vector4& p_vector);

		float x, y, z, w;
	};
	//WIP

	class Quaternion
	{
	public:
		Quaternion();
		Quaternion(float p_x, float p_y, float p_z, float p_w);
		Quaternion(Vector4 p_vector);
		void Set(float p_x, float p_y, float p_z, float p_w);
		void Set(Vector4 p_vector);
		float Magnitude();
		Quaternion Normalize();
		Quaternion Conjugate();
		Quaternion operator*(Quaternion& p_quaternion);
		Quaternion operator*(Vector4& p_vector);
		Quaternion operator*(Vector3& p_vector);

		float x, y, z, w;
	private:
	};

	class Matrix4
	{
	public:
		Matrix4();
		void InitID();
		float Get(int p_x, int p_y);
		float Get(Vector2 p_vector);
		void set(int p_x, int p_y, float p_value);
		void Set(Vector2 p_vector, float p_value);
		Matrix4 operator*(Matrix4 p_matrix);
		
		float matrix[4][4];
	private:
	};

	//WIP
	class Transform
	{
	public:
		Transform();
		
		Transform parent();
		Matrix4 parentMatrix;

		Vector3 localPosition, position;
		Quaternion localRotation, rotation;
		Vector3 localScale, scale;
	private:
	};
	//WIP

}