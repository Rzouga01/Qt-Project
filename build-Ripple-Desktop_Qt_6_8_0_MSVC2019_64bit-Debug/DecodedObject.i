#line 1 "..\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\DecodedObject.cpp"
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
#line 2 "..\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\DecodedObject.cpp"

namespace zxing {
namespace oned {
namespace rss {

DecodedObject::DecodedObject(int newPosition)
    : m_newPosition(newPosition)
{

}

int DecodedObject::getNewPosition() const
{
    return m_newPosition;
}

}
}
}
