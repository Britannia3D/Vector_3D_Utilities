#include <iostream>
#include <sstream>

#include "VectorUtilities.h"

using namespace std;

//Euclidean distance
float Vector3DUtils::dist(float x1, float y1, float z1, float x2, float y2, float z2)
{
	return(sqrt(pow((float)(x2 - x1), (float)2) + pow((float)(y2 - y1), (float)2) + pow((float)(z2 - z1), (float)2)));
}

//Cross product of two vector array.
Vector3D Vector3DUtils::cross(const Vector3D& A, const Vector3D& B)
{
	Vector3D crossP(0, 0, 0);
	crossP.x = A.y * B.z - A.z * B.y;
	crossP.y = A.z * B.x - A.x * B.z;
	crossP.z = A.x * B.y - A.y * B.x;

	return crossP;
}

double Vector3DUtils::dot(Vector3D input1, const Vector3D& rhs)
{
	return input1.x * rhs.x + input1.y * rhs.y + input1.z * rhs.z;
}

Vector3D Vector3DUtils::intersectPoint(Vector3D rayVector, Vector3D rayPoint, Vector3D planeNormal, Vector3D planePoint)
{
	Vector3D diff = rayPoint - planePoint;
	double prod1 = dot(diff, planeNormal);
	double prod2 = dot(rayVector, planeNormal);
	double prod3 = prod1 / prod2;
	return rayPoint - rayVector * prod3;
}

//Get arbitrary 3d vector that is perpendicular to the parameter vector
//There are infinite such vectors, return one such
Vector3D Vector3DUtils::arbitrary_orthogonal(Vector3D vec)
{
	bool b0 = (vec.x < vec.y) && (vec.x < vec.z);
	bool b1 = (vec.y <= vec.x) && (vec.y < vec.z);
	bool b2 = (vec.z <= vec.x) && (vec.z <= vec.y);

	Vector3D op(0, 0, 0);
	op = cross(vec, Vector3D(int(b0), int(b1), int(b2)));

	return op;
}

//Use spherical coordinates to get a position
Vector3D Vector3DUtils::OrbitalPosition(float angle1, float angle2, Vector3D centroid)
{
	float sx = centroid.x;// -0.013;
	float sy = centroid.y;// 1.06;
	float sz = centroid.z;// 1.06;

	float Theta = angle1;
	float Phi = angle2;
	float radius = 0.3;
	float Y = radius * sin(Theta);
	float X = radius * cos(Theta) * cos(Phi);
	float Z = radius * cos(Theta) * sin(Phi);

	return Vector3D(X + sx, Y + sy, Z + sz);
}

//Set the length (magnitude) of a given vector
Vector3D Vector3DUtils::setVectorMagitude(Vector3D input, float newMag)
{
	float mag = sqrt(input.x * input.x + input.y * input.y + input.z * input.z);

	float new_x = input.x * newMag / mag;
	float new_y = input.y * newMag / mag;
	float new_z = input.z * newMag / mag;

	Vector3D op(new_x, new_y, new_z);
	return op;
}

double Vector3DUtils::length(Vector3D vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}

Vector3D Vector3DUtils::normalize(Vector3D vec)
{
	float op1 = pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2);
	op1 = sqrt(op1);

	Vector3D op;
	op.x = vec.x / op1;
	op.y = vec.y / op1;
	op.z = vec.z / op1;

	return op;
}