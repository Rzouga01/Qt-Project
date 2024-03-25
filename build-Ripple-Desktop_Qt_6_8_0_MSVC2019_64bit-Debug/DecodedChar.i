#line 1 "..\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\DecodedChar.cpp"
#line 1 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\DecodedChar.h"































#line 1 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\DecodedObject.h"






























namespace zxing {

namespace oned {

namespace rss {

class DecodedObject
{

public:
    DecodedObject(int newPosition);

    int getNewPosition() const;

protected:
    int m_newPosition;
};

}
}
}
#line 53 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\DecodedObject.h"
#line 33 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\DecodedChar.h"

namespace zxing {

namespace oned {

namespace rss {

class DecodedChar : public DecodedObject
{

public:
    static const char FNC1 = '$'; 

    DecodedChar(int newPosition, char value);

    char getValue() const;

    bool isFNC1() const;

private:
    char m_value;

};

}
}
}

#line 62 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\DecodedChar.h"
#line 2 "..\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\DecodedChar.cpp"

namespace zxing {
namespace oned {
namespace rss {

DecodedChar::DecodedChar(int newPosition, char value)
    : DecodedObject (newPosition), m_value(value)
{

}

char DecodedChar::getValue() const
{
    return m_value;
}

bool DecodedChar::isFNC1() const
{
    return m_value == FNC1;
}

}
}
}
