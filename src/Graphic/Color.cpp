#include "Color.h"

namespace NAQH
{
    Color::Color()
    :r(0), g(0), b(0), a(1.0)
    { }

    Color::Color(float p_r, float p_g, float p_b, float p_a)
    :r(p_r), g(p_g), b(p_b), a(p_a)
    {
		r = (r > 255) ? 255 : r;
        r = (r < 0) ? 0 : r;
        r = (r > 1) ? r/255 : r;
		g = (g > 255) ? 255 : g;
        g = (g < 0) ? 0 : g;
        g = (g > 1) ? g/255 : g;
		b = (b > 255) ? 255 : b;
        b = (b < 0) ? 0 : b;
        b = (b > 1) ? b/255 : b;
		a = (a > 255) ? 255 : a;
        a = (a < 0) ? 0 : a;
        a = (a > 1) ? a/255 : a;
    }

	void Color::Set(float p_r, float p_g, float p_b, float p_a)
	{
		r = p_r;
		g = p_g;
		b = p_b;
		a = p_a;
	}
}