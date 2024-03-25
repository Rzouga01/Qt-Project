#line 1 "..\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\CurrentParsingState.cpp"
#line 1 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\CurrentParsingState.h"































namespace zxing {

namespace oned {

namespace rss {

class CurrentParsingState
{

public:
    enum State {
        NUMERIC,
        ALPHA,
        ISO_IEC_646
    };

    CurrentParsingState();

    int getPosition() const;

    void setPosition(int _position);

    void incrementPosition(int delta);

    bool isAlpha() const;

    bool isNumeric() const;

    bool isIsoIec646() const;

    void setNumeric();

    void setAlpha();

    void setIsoIec646();

private:
    int position;
    State encoding;

};

}
}
}

#line 79 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\CurrentParsingState.h"
#line 2 "..\\QZXing\\src\\zxing\\zxing\\oned\\rss\\expanded\\decoders\\CurrentParsingState.cpp"

namespace zxing {
namespace oned {
namespace rss {

CurrentParsingState::CurrentParsingState()
{
    position = 0;
    encoding = State::NUMERIC;
}

int CurrentParsingState::getPosition() const
{
    return position;
}

void CurrentParsingState::setPosition(int _position)
{
    position = _position;
}

void CurrentParsingState::incrementPosition(int delta)
{
    position += delta;
}

bool CurrentParsingState::isAlpha() const
{
    return encoding == State::ALPHA;
}

bool CurrentParsingState::isNumeric() const
{
    return encoding == State::NUMERIC;
}

bool CurrentParsingState::isIsoIec646() const
{
    return encoding == State::ISO_IEC_646;
}

void CurrentParsingState::setNumeric()
{
    encoding = State::NUMERIC;
}

void CurrentParsingState::setAlpha()
{
    encoding = State::ALPHA;
}

void CurrentParsingState::setIsoIec646()
{
    encoding = State::ISO_IEC_646;
}

}
}
}
