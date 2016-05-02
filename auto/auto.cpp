// extern to prevent inlining
extern auto void_test() -> void;
extern auto float_test() -> float;
extern auto double_test() -> double;
extern auto char_test() -> char;
extern auto uchar_test() -> unsigned char;
extern auto short_test() -> short;
extern auto ushort_test() -> unsigned short;
extern auto int_test() -> int;
extern auto uint_test() -> unsigned int;
extern auto long_test() -> long;
extern auto ulong_test() -> unsigned long;


auto main() -> int
{
    void_test();
    auto f = float_test();
    auto d = double_test();
    auto c = char_test();
    auto uc = uchar_test();
    auto s = short_test();
    auto us = ushort_test();
    auto i = int_test();
    auto ui = uint_test();
    auto l = long_test();
    auto ul = ulong_test();
    return 0;
}

