#line 1 "..\\QZXing\\src\\zxing\\zxing\\BarcodeFormat.cpp"


















#line 1 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\zxing/BarcodeFormat.h"























namespace zxing {

class BarcodeFormat {
public:
  

  enum Value {
    NONE,
    AZTEC,
    CODABAR,
    CODE_39,
    CODE_93,
    CODE_128,
    DATA_MATRIX,
    EAN_8,
    EAN_13,
    ITF,
    MAXICODE,
    PDF_417,
    QR_CODE,
    RSS_14,
    RSS_EXPANDED,
    UPC_A,
    UPC_E,
    UPC_EAN_EXTENSION,
    ASSUME_GS1
  };

  BarcodeFormat(Value v) : value(v) {}  
  const Value value;
  operator Value () const {return value;}

  static char const* barcodeFormatNames[];
};

}

#line 62 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\zxing/BarcodeFormat.h"
#line 20 "..\\QZXing\\src\\zxing\\zxing\\BarcodeFormat.cpp"

const char* zxing::BarcodeFormat::barcodeFormatNames[] = {
  0,
  "AZTEC",
  "CODABAR",
  "CODE_39",
  "CODE_93",
  "CODE_128",
  "DATA_MATRIX",
  "EAN_8",
  "EAN_13",
  "ITF",
  "MAXICODE",
  "PDF_417",
  "QR_CODE",
  "RSS_14",
  "RSS_EXPANDED",
  "UPC_A",
  "UPC_E",
  "UPC_EAN_EXTENSION",
  "ASSUME_GS1"
};
