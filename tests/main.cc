#include <iostream>
#include <cassert>

#include <vector-class/vector.h>
#include <vector-class/color.h>

int main()
{
	printf("start\n");

	//
	// construction
	//
	{
		Vector vec, vec1(1.0f, 0.0f, 2.0f), vec3(vec1), vec4(vec1.Base());
		CColor clr = { 1.0f, 0.0f, 0.0f, 1.0f };
		CColor clr1(clr);
		assert(clr1.r == 1.0f);

		// custom types
		Vector2DT<uint8_t> vT(0, 255);
		assert(vT.y == 255);

		// create floating-poiint color from integral type
		CColor clr_special = CColor::construct_from_integral<uint8_t>(255, 0, 0, 255);
		assert(clr_special.r == 1.0f && clr_special.g == 0.0f && clr_special.b == 0.0f && clr_special.a == 1.0f);

		CColor255 clr_special1 = CColor255::construct_from_floatingpoint(1.0f, 0.0f, 0.0f, 1.0f);
		assert(clr_special1.r == 255 && clr_special1.g == 0 && clr_special1.b == 0 && clr_special1.a == 255);

		CColor255T<unsigned long long> clr_special2 = CColor255T<uint64_t>::construct_from_floatingpoint(1.0f, 0.0f, 0.0f, 1.0f);
		assert(clr_special2.r == 255ull && clr_special2.g == 0ull && clr_special2.b == 0ull && clr_special2.a == 255ull);
	}

	//
	// TODO: more tests
	//

	printf("end\n");
}