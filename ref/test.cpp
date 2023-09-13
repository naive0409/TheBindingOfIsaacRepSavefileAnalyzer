#include "./TheBindingOfIsaacRepSavefileAnalyzer/myInclude.h"

int main()
{
    // u8 a = 1;
    // u16 b = 1;
    // u32 c = 1;
    // cout << static_cast<u32>(a << 16) << endl;

    // string s1 = "hello";
    // string s2 = "world";
    // s1 += s2;
    // cout << s1 << endl;
	u8 readU8(vector<u8>::iterator it)
	{

	}

	u16 readU16(vector<u8>::iterator it)
	{

	}

	u32 readU32(vector<u8>::iterator it)
	{
		u32 res = 0;
		for (int i = 0; i < 4; i++)
		{
			res += (*it++) << 8 * i;
		}
		return res;
	}
    string s ="";
    std::vector<u8> v = {73,83,65,65,67,78,71,83,65,86,69,48,57,82,32,32,93,150,51,254,1,0,0,0,126,2,0,0,126,2,0,0,0,1,1,1,1,1,1,1};
    vector<u8>::iterator iter = v.begin();
    for(int i = 0;i<16;i++)
    {
        s+= *(iter+i);
        cout << *(iter+i) << ',';
    }

    cout << s << '|' << endl;

    return 0;
}
