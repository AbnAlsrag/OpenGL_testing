#include "Math.h"

namespace NAQH{
	float Pow(float p_a, float p_b)
	{	
		float ans;
		ans = p_a;
 
		for (float i = 1; i < p_b; i++)
		{
			ans = ans * p_a;
		}	

		return ans;
	}

	float Clamp(float p_number, float p_max, float p_min)
	{
		if (p_number > p_max)
			return p_max;
		if (p_number < p_min)
			return p_min;

		return p_number; 
	}

	Vector2 Pow(Vector2 p_vector, float p_b)
	{	
		Vector2 ans;
		ans = p_vector;

		for (float i = 1; i < p_b; i++)
		{
			ans = ans * p_vector;
		}	

		return ans;
	}

	float Rad2Deg(float p_rad)
	{
		return p_rad/PI*180l;
	}

	float Deg2Rad(float p_deg)
	{
		return p_deg/180*PI;
	}

	//WIP
	float Lerp(float p_a, float p_b, float p_t)
	{	
		return p_a + p_t * (p_b - p_a);
	}

	float Sin(float p_angle)
	{
		return sinf(p_angle);
	}

	float Cos(float p_angle)
	{
		return cosf(p_angle);
	}

	float Tan(float p_angle)
	{
		return tanf(p_angle);
	}
	//WIP

	Vector2::Vector2()
	:x(0.0f), y(0.0f)
	{}

	Vector2::Vector2(float p_x, float p_y)
	:x(p_x), y(p_y)
	{}


	void Vector2::print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	void Vector2::Set(float p_x, float p_y)
	{
		x = p_x;
		y = p_y;
	}

	void Vector2::Normalize()
	{
		if(Magnitude() != 0)
		{
			x /= Magnitude();
			y /= Magnitude();
		}
	}

	float Vector2::DotProduct(Vector2& p_vector)
	{
		return (x * p_vector.x + y * p_vector.y);
	}

	Vector2 Vector2::Rotate(float p_angle)
	{
		float rad = Deg2Rad(p_angle);
		float cos = Cos(rad);
		float sin = Sin(rad);

		x = x * cos - y * sin;
		y = x * sin + y * cos;
		return Vector2(x * cos - y * sin, x * sin + y * cos);
	}

	float Vector2::Magnitude()
	{
		return sqrt(x * x + y * y);
	}

	float Vector2::Distance(Vector2& p_vector)
	{
		return sqrt(pow((x - p_vector.x), 2)) + sqrt(pow((y - p_vector.y), 2));
	}

	Vector2 Vector2::operator+(float p_number)
	{
		return Vector2(x + p_number, y + p_number);
	}

	Vector2 Vector2::operator+(Vector2& p_vector)
	{
		return Vector2(x + p_vector.x, y + p_vector.y);
	}

	Vector2 Vector2::operator-(float p_number)
	{
		return Vector2(x - p_number, y - p_number);
	}

	Vector2 Vector2::operator-(Vector2& p_vector)
	{
		return Vector2(x - p_vector.x, y - p_vector.y);
	}

	Vector2 Vector2::operator*(float p_number)
	{
		return Vector2(x * p_number, y * p_number);
	}

	Vector2 Vector2::operator*(Vector2& p_vector)
	{
		return Vector2(x * p_vector.x, y * p_vector.y);
	}

	Vector2 Vector2::operator/(float p_number)
	{
		if(p_number != 0)
			return Vector2(x / p_number, y / p_number);

		return *this;
	}

	Vector2 Vector2::operator/(Vector2& p_vector)
	{
		if(p_vector.x != 0 && p_vector.y != 0)
			return Vector2(x / p_vector.x, y / p_vector.y);

		return *this;
	}

	Vector2 Vector2::operator%(float& p_number)
	{
		return Vector2(fmod(x, p_number), fmod(y, p_number));
	}

	Vector2 Vector2::operator%(Vector2& p_vector)
	{
		return Vector2(fmod(x, p_vector.x), fmod(y, p_vector.y));
	}

	Vector2& Vector2::operator+=(Vector2& p_vector)
	{
		x = x + p_vector.x; 
		y = y + p_vector.y;

		return *this;
	}

	Vector2& Vector2::operator-=(Vector2& p_vector)
	{
		x = x - p_vector.x; 
		y = y - p_vector.y;

		return *this;
	}

	Vector2& Vector2::operator*=(Vector2& p_vector)
	{
		x = x * p_vector.x; 
		y = y * p_vector.y;

		return *this;
	}

	Vector2& Vector2::operator/=(Vector2& p_vector)
	{
		if(p_vector.x != 0 && p_vector.y != 0)
		{
			x = x / p_vector.x; 
			y = y / p_vector.y;
		}

		return *this;
	}

	Vector2& Vector2::operator%=(Vector2& p_vector)
	{
		x = fmod(x, p_vector.x);
		y = fmod(y, p_vector.y);
		return *this;
	}

	bool Vector2::operator==(Vector2& p_vector)
	{ 
		return (x == p_vector.x && y == p_vector.y) ? true : false;
	}

	bool Vector2::operator!=(Vector2& p_vector)
	{
		return (x != p_vector.x || y != p_vector.y) ? true : false;
	}

	Vector3::Vector3()
	:x(0.0f), y(0.0f), z(0.0f)
	{}

	Vector3::Vector3(float p_x, float p_y, float p_z)
	:x(p_x), y(p_y), z(p_z)
	{}

	void Vector3::print()
	{
		std::cout << x << ", " << y << ", " << z << std::endl;
	}

	void Vector3::Set(float p_x, float p_y, float p_z)
	{
		x = p_x;
		y = p_y;
		z = p_z;
	}

	void Vector3::Normalize()
	{
		if(Magnitude() != 0)
		{
			x /= Magnitude();
			y /= Magnitude();
			z /= Magnitude();
		}
	}

	float Vector3::DotProduct(Vector3& p_vector)
	{
		return (x * p_vector.x + y * p_vector.y + z * p_vector.z);
	}

	Vector3 Vector3::CrossProduct(Vector3& p_vector)
	{
		float m_x, m_y, m_z;

		m_x = y * p_vector.z - z * p_vector.y;
		m_y = z * p_vector.x - x * p_vector.z;
		m_z = x * p_vector.y - y * p_vector.x;

		return Vector3(m_x, m_y, m_z);
	}

	//WIP
	Vector3 Vector3::Rotate(Vector3 p_axis, float p_angle)
	{
		// float cos = Cos(-p_angle);
		// float sin = Sin(-p_angle);

		//return CrossProduct(p_axis * sin + *this * cos + p_axis * DotProduct(p_axis * 1 - cos));
		return *this;
	}
	//WIP

	float Vector3::Magnitude()
	{
		return sqrt(x * x + y * y + z * z);
	}

	Vector3 Vector3::operator+(float p_number)
	{
		return Vector3(x + p_number, y + p_number, z + p_number);
	}

	Vector3 Vector3::operator+(Vector3& p_vector)
	{
		return Vector3(x + p_vector.x, y + p_vector.y, z + p_vector.z);
	}

	Vector3 Vector3::operator-(float p_number)
	{
		return Vector3(x - p_number, y - p_number, z - p_number);
	}

	Vector3 Vector3::operator-(Vector3& p_vector)
	{
		return Vector3(x - p_vector.x, y - p_vector.y, z - p_vector.z);
	}

	Vector3 Vector3::operator*(float p_number)
	{
		return Vector3(x * p_number, y * p_number, z * p_number);
	}

	Vector3 Vector3::operator*(Vector3& p_vector)
	{
		return Vector3(x * p_vector.x, y * p_vector.y, z * p_vector.z);
	}

	Vector3 Vector3::operator/(float p_number)
	{
		if(p_number != 0)
			return Vector3(x / p_number, y / p_number, z / p_number);
		
		return *this;
	}

	Vector3 Vector3::operator/(Vector3& p_vector)
	{
		if(p_vector.x != 0 && p_vector.y != 0 && p_vector.z != 0)
			return Vector3(x / p_vector.x, y / p_vector.y, z / p_vector.z);

		return *this;
	}

	Vector3 Vector3::operator%(float p_number)
	{
		return Vector3(fmod(x, p_number), fmod(y, p_number), fmod(z, p_number));
	}

	Vector3 Vector3::operator%(Vector3& p_vector)
	{
		return Vector3(fmod(x, p_vector.x), fmod(y, p_vector.y), fmod(z, p_vector.z));
	}

	Vector3& Vector3::operator+=(Vector3& p_vector)
	{
		x = x + p_vector.x; 
		y = y + p_vector.y;
		z = z + p_vector.z;
		return *this;
	}

	Vector3& Vector3::operator-=(Vector3& p_vector)
	{
		x = x - p_vector.x; 
		y = y - p_vector.y;
		z = z - p_vector.z;
		return *this;
	}

	Vector3& Vector3::operator*=(Vector3& p_vector)
	{
		x = x * p_vector.x; 
		y = y * p_vector.y;
		z = z * p_vector.z;
		return *this;
	}

	Vector3& Vector3::operator/=(Vector3& p_vector)
	{
		if(p_vector.x != 0 && p_vector.y != 0 && p_vector.z != 0)
		{
			x = x / p_vector.x; 
			y = y / p_vector.y;
			z = z / p_vector.z;
		}
		return *this;
	}

	Vector3& Vector3::operator%=(Vector3& p_vector)
	{
		x = fmod(x, p_vector.x);
		y = fmod(y, p_vector.y);
		z = fmod(z, p_vector.z);
		return *this;
	}

	bool Vector3::operator==(Vector3& p_vector)
	{
		if (x == p_vector.x && y == p_vector.y && z == p_vector.z)
			return true;
		else
			return false;
	}

	bool Vector3::operator!=(Vector3& p_vector)
	{
		if (x != p_vector.x || y != p_vector.y || z != p_vector.z)
			return true;
		else
			return false;
	}

	//WIP
	Vector4::Vector4()
	:x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{}

	Vector4::Vector4(float p_x, float p_y, float p_z, float p_w)
	:x(p_x), y(p_y), z(p_z), w(p_w)
	{}

	void Vector4::print()
	{
		std::cout << x << ", " << y << ", " << z << ", " << w << std::endl;
	}

	Vector4 Vector4::operator+(Vector4& p_vector)
	{
		return Vector4(x + p_vector.x, y + p_vector.y, z + p_vector.z, w + p_vector.w);
	}

	Vector4 Vector4::operator-(Vector4& p_vector)
	{
		return Vector4(x - p_vector.x, y - p_vector.y, z - p_vector.z, w - p_vector.w);
	}

	Vector4 Vector4::operator*(Vector4& p_vector)
	{
		return Vector4(x * p_vector.x, y * p_vector.y, z * p_vector.z, w * p_vector.w);
	}

	Vector4 Vector4::operator/(Vector4& p_vector)
	{
		return Vector4(x / p_vector.x, y / p_vector.y, z / p_vector.z, w / p_vector.w);
	}

	Vector4 Vector4::operator%(Vector4& p_vector)
	{
		return Vector4(fmod(x, p_vector.x), fmod(y, p_vector.y), fmod(z, p_vector.z), fmod(w, p_vector.w));
	}

	bool Vector4::operator==(Vector4& p_vector)
	{
		if (x == p_vector.x && y == p_vector.y && z == p_vector.z && w == p_vector.w)
			return true;
		else
			return false;
	}

	bool Vector4::operator!=(Vector4& p_vector)
	{
		if (x != p_vector.x && y != p_vector.y && z != p_vector.z && w != p_vector.w)
			return true;
		else
			return false;
	}
	//WIP

	Quaternion::Quaternion()
	:x(0), y(0), z(0), w(0)
	{}

	Quaternion::Quaternion(float p_x, float p_y, float p_z, float p_w)
	:x(p_x), y(p_y), z(p_z), w(p_w)
	{}

	Quaternion::Quaternion(Vector4 p_vector)
	:x(p_vector.x), y(p_vector.y), z(p_vector.z), w(p_vector.w)
	{}

	void Quaternion::Set(float p_x, float p_y, float p_z, float p_w)
	{
		x = p_x;
		y = p_y;
		z = p_z;
		w = p_w;
	}

	void Quaternion::Set(Vector4 p_vector)
	{
		x = p_vector.x;
		y = p_vector.y;
		z = p_vector.z;
		w = p_vector.w;
	}

	float Quaternion::Magnitude()
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	Quaternion Quaternion::Normalize()
	{
		if(Magnitude() != 0)
		{
			x /= Magnitude();
			y /= Magnitude();
			z /= Magnitude();
			w /= Magnitude();

			return *this;
		}

		return *this;
	}

	Quaternion Quaternion::Conjugate()
	{
		return Quaternion(-x, -y, -z, w);
	}

	Quaternion Quaternion::operator*(Quaternion& p_quaternion)
	{
		float m_x, m_y, m_z, m_w;
		m_x = x * p_quaternion.w + w * p_quaternion.x + y * p_quaternion.z - z * p_quaternion.y;
		m_y = y * p_quaternion.w + w * p_quaternion.y + z * p_quaternion.x - x * p_quaternion.z;
		m_z = z * p_quaternion.w + w * p_quaternion.z + x * p_quaternion.w - y * p_quaternion.x;
		m_w = w * p_quaternion.w - x * p_quaternion.x - y * p_quaternion.y - z * p_quaternion.z;

		return Quaternion(m_x, m_y, m_z, m_w);
	}

	Quaternion Quaternion::operator*(Vector4& p_vector)
	{
		float m_x, m_y, m_z, m_w;
		m_x = x * p_vector.w + w * p_vector.x + y * p_vector.z - z * p_vector.y;
		m_y = y * p_vector.w + w * p_vector.y + z * p_vector.x - x * p_vector.z;
		m_z = z * p_vector.w + w * p_vector.z + x * p_vector.w - y * p_vector.x;
		m_w = w * p_vector.w - x * p_vector.x - y * p_vector.y - z * p_vector.z;

		return Quaternion(m_x, m_y, m_z, m_w);
	}

	Quaternion Quaternion::operator*(Vector3& p_vector)
	{
		float m_x, m_y, m_z, m_w;
		m_x = w * p_vector.x + y * p_vector.z - z * p_vector.y;
		m_y = w * p_vector.y + z * p_vector.x - x * p_vector.z;
		m_z = w * p_vector.z + x * p_vector.y - y * p_vector.x;
		m_w = -x * p_vector.x - y * p_vector.y - z * p_vector.z;

		return Quaternion(m_x, m_y, m_z, m_w);
	}

	Matrix4::Matrix4()
	{
		
	}

	void Matrix4::InitID()
	{
		matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0; matrix[0][3] = 0;
		matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0; matrix[1][3] = 0;
		matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1; matrix[2][3] = 0;
		matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0; matrix[3][3] = 1;
	}

	float Matrix4::Get(int p_x, int p_y)
	{
		return matrix[p_x][p_y];
	}

	float Matrix4::Get(Vector2 p_vector)
	{
		return matrix[(int)p_vector.x][(int)p_vector.y];
	}

	void Matrix4::set(int p_x, int p_y, float p_value)
	{
		matrix[p_x][p_y] = p_value;
	}

	void Matrix4::Set(Vector2 p_vector, float p_value)
	{
		matrix[(int)p_vector.x][(int)p_vector.y] = p_value;
	}

	Matrix4 Matrix4::operator*(Matrix4 p_matrix)
	{
		Matrix4 result;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				p_matrix.set(i, j, matrix[i][0] * p_matrix.Get(0, j) + 
									matrix[i][1] * p_matrix.Get(1, j) + 
									matrix[i][2] * p_matrix.Get(2, j) + 
									matrix[i][3] * p_matrix.Get(3, j));
			}
		}
		
		return result;
	}
}