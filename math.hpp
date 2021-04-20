#include "includes.h"

D3DXVECTOR3 CalcAngle(register const D3DXVECTOR3& src, register const D3DXVECTOR3& dst)
{

	D3DXVECTOR3 angles;

	//getting delta between source and destination vectors
	D3DXVECTOR3 delta = src - dst;

	//finding the hypoteneuse using pythagoras theorem a squared + b squared = c squared
	//this gives us the vector to our enemy
	float hyp = sqrt(delta.x * delta.x + delta.y * delta.y);

	angles.x = asinf(delta.z / hyp) * (180.0f / M_PI);
	angles.y = atanf(delta.y / delta.x) * (180.0f / M_PI) + !((*(DWORD*)&delta.x) >> 31 & 1) * 180.0f;

	angles.z = 0.0f;

	return angles;
}
