#line 1 "..\\QZXing\\src\\zxing\\bigint\\BigUnsigned.cc"
#line 1 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\bigint\\BigUnsigned.hh"



#line 1 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\bigint\\NumberlikeArray.hh"






#line 8 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\bigint\\NumberlikeArray.hh"












template <class Blk>
class NumberlikeArray {
public:

	
	typedef unsigned int Index;
	
	static const unsigned int N;

	
	Index cap;
	
	Index len;
	
	Blk *blk;

	
	NumberlikeArray(Index c) : cap(c), len(0) { 
		blk = (cap > 0) ? (new Blk[cap]) : 0;
	}

	



	NumberlikeArray() : cap(0), len(0) {
		blk = 0;
	}

	
	~NumberlikeArray() {
		delete [] blk;
	}

	

	void allocate(Index c);

	

	void allocateAndCopy(Index c);

	
	NumberlikeArray(const NumberlikeArray<Blk> &x);

	
	void operator=(const NumberlikeArray<Blk> &x);

	
	NumberlikeArray(const Blk *b, Index blen);

	
	Index getCapacity()     const { return cap;      }
	Index getLength()       const { return len;      }
	Blk   getBlock(Index i) const { return blk[i];   }
	bool  isEmpty()         const { return len == 0; }

	


	bool operator ==(const NumberlikeArray<Blk> &x) const;

	bool operator !=(const NumberlikeArray<Blk> &x) const {
		return !operator ==(x);
	}
};




template <class Blk>
const unsigned int NumberlikeArray<Blk>::N = 8 * sizeof(Blk);

template <class Blk>
void NumberlikeArray<Blk>::allocate(Index c) {
	
	if (c > cap) {
		
		delete [] blk;
		
		cap = c;
		blk = new Blk[cap];
	}
}

template <class Blk>
void NumberlikeArray<Blk>::allocateAndCopy(Index c) {
	
	if (c > cap) {
		Blk *oldBlk = blk;
		
		cap = c;
		blk = new Blk[cap];
		
		Index i;
		for (i = 0; i < len; i++)
			blk[i] = oldBlk[i];
		
		delete [] oldBlk;
	}
}

template <class Blk>
NumberlikeArray<Blk>::NumberlikeArray(const NumberlikeArray<Blk> &x)
		: len(x.len) {
	
	cap = len;
	blk = new Blk[cap];
	
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = x.blk[i];
}

template <class Blk>
void NumberlikeArray<Blk>::operator=(const NumberlikeArray<Blk> &x) {
	

	if (this == &x)
		return;
	
	len = x.len;
	
	allocate(len);
	
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = x.blk[i];
}

template <class Blk>
NumberlikeArray<Blk>::NumberlikeArray(const Blk *b, Index blen)
		: cap(blen), len(blen) {
	
	blk = new Blk[cap];
	
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = b[i];
}

template <class Blk>
bool NumberlikeArray<Blk>::operator ==(const NumberlikeArray<Blk> &x) const {
	if (len != x.len)
		
		return false;
	else {
		
		Index i;
		for (i = 0; i < len; i++)
			if (blk[i] != x.blk[i])
				return false;
		
		return true;
	}
}

#line 178 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\bigint\\NumberlikeArray.hh"
#line 5 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\bigint\\BigUnsigned.hh"








class BigUnsigned : protected NumberlikeArray<unsigned long> {

public:
	
	enum CmpRes { less = -1, equal = 0, greater = 1 };

	
	typedef unsigned long Blk;

	typedef NumberlikeArray<Blk>::Index Index;
	using NumberlikeArray<Blk>::N;

protected:
	
	BigUnsigned(int, Index c) : NumberlikeArray<Blk>(0, c) {}

	
	void zapLeadingZeros() { 
		while (len > 0 && blk[len - 1] == 0)
			len--;
	}

public:
	
	BigUnsigned() : NumberlikeArray<Blk>() {}

	
	BigUnsigned(const BigUnsigned &x) : NumberlikeArray<Blk>(x) {}

	
	void operator=(const BigUnsigned &x) {
		NumberlikeArray<Blk>::operator =(x);
	}

	
	BigUnsigned(const Blk *b, Index blen) : NumberlikeArray<Blk>(b, blen) {
		
		zapLeadingZeros();
	}

	
	~BigUnsigned() {}
	
	
	BigUnsigned(unsigned long  x);
	BigUnsigned(         long  x);
	BigUnsigned(unsigned int   x);
	BigUnsigned(         int   x);
	BigUnsigned(unsigned short x);
	BigUnsigned(         short x);
protected:
	
	template <class X> void initFromPrimitive      (X x);
	template <class X> void initFromSignedPrimitive(X x);
public:

	


	unsigned long  toUnsignedLong () const;
	long           toLong         () const;
	unsigned int   toUnsignedInt  () const;
	int            toInt          () const;
	unsigned short toUnsignedShort() const;
	short          toShort        () const;
protected:
	
	template <class X> X convertToSignedPrimitive() const;
	template <class X> X convertToPrimitive      () const;
public:

	

	
	using NumberlikeArray<Blk>::getCapacity;
	using NumberlikeArray<Blk>::getLength;

	

	Blk getBlock(Index i) const { return i >= len ? 0 : blk[i]; }
	
	void setBlock(Index i, Blk newBlock);

	
	bool isZero() const { return NumberlikeArray<Blk>::isEmpty(); }

	


	Index bitLength() const;
	

	bool getBit(Index bi) const {
		return (getBlock(bi / N) & (Blk(1) << (bi % N))) != 0;
	}
	

	void setBit(Index bi, bool newBit);

	

	
	CmpRes compareTo(const BigUnsigned &x) const;

	
	bool operator ==(const BigUnsigned &x) const {
		return NumberlikeArray<Blk>::operator ==(x);
	}
	bool operator !=(const BigUnsigned &x) const {
		return NumberlikeArray<Blk>::operator !=(x);
	}
	bool operator < (const BigUnsigned &x) const { return compareTo(x) == less   ; }
	bool operator <=(const BigUnsigned &x) const { return compareTo(x) != greater; }
	bool operator >=(const BigUnsigned &x) const { return compareTo(x) != less   ; }
	bool operator > (const BigUnsigned &x) const { return compareTo(x) == greater; }

	













































	

	
	void add(const BigUnsigned &a, const BigUnsigned &b);
	void subtract(const BigUnsigned &a, const BigUnsigned &b);
	void multiply(const BigUnsigned &a, const BigUnsigned &b);
	void bitAnd(const BigUnsigned &a, const BigUnsigned &b);
	void bitOr(const BigUnsigned &a, const BigUnsigned &b);
	void bitXor(const BigUnsigned &a, const BigUnsigned &b);
	

	void bitShiftLeft(const BigUnsigned &a, int b);
	void bitShiftRight(const BigUnsigned &a, int b);

	





	void divideWithRemainder(const BigUnsigned &b, BigUnsigned &q);

	


	
	BigUnsigned operator +(const BigUnsigned &x) const;
	BigUnsigned operator -(const BigUnsigned &x) const;
	BigUnsigned operator *(const BigUnsigned &x) const;
	BigUnsigned operator /(const BigUnsigned &x) const;
	BigUnsigned operator %(const BigUnsigned &x) const;
	

	BigUnsigned operator &(const BigUnsigned &x) const;
	BigUnsigned operator |(const BigUnsigned &x) const;
	BigUnsigned operator ^(const BigUnsigned &x) const;
	BigUnsigned operator <<(int b) const;
	BigUnsigned operator >>(int b) const;

	
	void operator +=(const BigUnsigned &x);
	void operator -=(const BigUnsigned &x);
	void operator *=(const BigUnsigned &x);
	void operator /=(const BigUnsigned &x);
	void operator %=(const BigUnsigned &x);
	void operator &=(const BigUnsigned &x);
	void operator |=(const BigUnsigned &x);
	void operator ^=(const BigUnsigned &x);
	void operator <<=(int b);
	void operator >>=(int b);

	


	void operator ++(   );
	void operator ++(int);
	void operator --(   );
	void operator --(int);

	
	friend Blk getShiftedBlock(const BigUnsigned &num, Index x,
			unsigned int y);

	
	template <class X>
	friend X convertBigUnsignedToPrimitiveAccess(const BigUnsigned &a);
};





inline BigUnsigned BigUnsigned::operator +(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.add(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator -(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.subtract(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator *(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.multiply(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator /(const BigUnsigned &x) const {
	if (x.isZero()) throw "BigUnsigned::operator /: division by zero";
	BigUnsigned q, r;
	r = *this;
	r.divideWithRemainder(x, q);
	return q;
}
inline BigUnsigned BigUnsigned::operator %(const BigUnsigned &x) const {
	if (x.isZero()) throw "BigUnsigned::operator %: division by zero";
	BigUnsigned q, r;
	r = *this;
	r.divideWithRemainder(x, q);
	return r;
}
inline BigUnsigned BigUnsigned::operator &(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.bitAnd(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator |(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.bitOr(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator ^(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.bitXor(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator <<(int b) const {
	BigUnsigned ans;
	ans.bitShiftLeft(*this, b);
	return ans;
}
inline BigUnsigned BigUnsigned::operator >>(int b) const {
	BigUnsigned ans;
	ans.bitShiftRight(*this, b);
	return ans;
}

inline void BigUnsigned::operator +=(const BigUnsigned &x) {
	add(*this, x);
}
inline void BigUnsigned::operator -=(const BigUnsigned &x) {
	subtract(*this, x);
}
inline void BigUnsigned::operator *=(const BigUnsigned &x) {
	multiply(*this, x);
}
inline void BigUnsigned::operator /=(const BigUnsigned &x) {
	if (x.isZero()) throw "BigUnsigned::operator /=: division by zero";
	

	BigUnsigned q;
	divideWithRemainder(x, q);
	
	*this = q;
}
inline void BigUnsigned::operator %=(const BigUnsigned &x) {
	if (x.isZero()) throw "BigUnsigned::operator %=: division by zero";
	BigUnsigned q;
	
	divideWithRemainder(x, q);
}
inline void BigUnsigned::operator &=(const BigUnsigned &x) {
	bitAnd(*this, x);
}
inline void BigUnsigned::operator |=(const BigUnsigned &x) {
	bitOr(*this, x);
}
inline void BigUnsigned::operator ^=(const BigUnsigned &x) {
	bitXor(*this, x);
}
inline void BigUnsigned::operator <<=(int b) {
	bitShiftLeft(*this, b);
}
inline void BigUnsigned::operator >>=(int b) {
	bitShiftRight(*this, b);
}














template <class X>
void BigUnsigned::initFromPrimitive(X x) {
	if (x == 0)
		; 
	else {
		
		cap = 1;
		blk = new Blk[1];
		len = 1;
		blk[0] = Blk(x);
	}
}





template <class X>
void BigUnsigned::initFromSignedPrimitive(X x) {
	if (x < 0)
		throw "BigUnsigned constructor: "
			"Cannot construct a BigUnsigned from a negative number";
	else
		initFromPrimitive(x);
}






template <class X>
X BigUnsigned::convertToPrimitive() const {
	if (len == 0)
		
		return 0;
	else if (len == 1) {
		
		X x = X(blk[0]);
		
		if (Blk(x) == blk[0])
			
			return x;
		
	}
	throw "BigUnsigned::to<Primitive>: "
		"Value is too big to fit in the requested type";
}





template <class X>
X BigUnsigned::convertToSignedPrimitive() const {
	X x = convertToPrimitive<X>();
	if (x >= 0)
		return x;
	else
		throw "BigUnsigned::to(Primitive): "
			"Value is too big to fit in the requested type";
}

#line 419 "C:\\Users\\GAMING\\Documents\\GitHub\\Qt-Project\\QZXing\\src\\zxing\\bigint\\BigUnsigned.hh"
#line 2 "..\\QZXing\\src\\zxing\\bigint\\BigUnsigned.cc"






BigUnsigned::BigUnsigned(unsigned long  x) { initFromPrimitive      (x); }
BigUnsigned::BigUnsigned(unsigned int   x) { initFromPrimitive      (x); }
BigUnsigned::BigUnsigned(unsigned short x) { initFromPrimitive      (x); }
BigUnsigned::BigUnsigned(         long  x) { initFromSignedPrimitive(x); }
BigUnsigned::BigUnsigned(         int   x) { initFromSignedPrimitive(x); }
BigUnsigned::BigUnsigned(         short x) { initFromSignedPrimitive(x); }

unsigned long  BigUnsigned::toUnsignedLong () const { return convertToPrimitive      <unsigned long >(); }
unsigned int   BigUnsigned::toUnsignedInt  () const { return convertToPrimitive      <unsigned int  >(); }
unsigned short BigUnsigned::toUnsignedShort() const { return convertToPrimitive      <unsigned short>(); }
long           BigUnsigned::toLong         () const { return convertToSignedPrimitive<         long >(); }
int            BigUnsigned::toInt          () const { return convertToSignedPrimitive<         int  >(); }
short          BigUnsigned::toShort        () const { return convertToSignedPrimitive<         short>(); }



void BigUnsigned::setBlock(Index i, Blk newBlock) {
	if (newBlock == 0) {
		if (i < len) {
			blk[i] = 0;
			zapLeadingZeros();
		}
		
	} else {
		if (i >= len) {
			
			allocateAndCopy(i+1);
			
			for (Index j = len; j < i; j++)
				blk[j] = 0;
			len = i+1;
		}
		blk[i] = newBlock;
	}
}




BigUnsigned::Index BigUnsigned::bitLength() const {
	if (isZero())
		return 0;
	else {
		Blk leftmostBlock = getBlock(len - 1);
		Index leftmostBlockLen = 0;
		while (leftmostBlock != 0) {
			leftmostBlock >>= 1;
			leftmostBlockLen++;
		}
		return leftmostBlockLen + (len - 1) * N;
	}
}

void BigUnsigned::setBit(Index bi, bool newBit) {
	Index blockI = bi / N;
	Blk block = getBlock(blockI), mask = Blk(1) << (bi % N);
	block = newBit ? (block | mask) : (block & ~mask);
	setBlock(blockI, block);
}


BigUnsigned::CmpRes BigUnsigned::compareTo(const BigUnsigned &x) const {
	
	if (len < x.len)
		return less;
	else if (len > x.len)
		return greater;
	else {
		
		Index i = len;
		while (i > 0) {
			i--;
			if (blk[i] == x.blk[i])
				continue;
			else if (blk[i] > x.blk[i])
				return greater;
			else
				return less;
		}
		
		return equal;
	}
}

































void BigUnsigned::add(const BigUnsigned &a, const BigUnsigned &b) {
	if (this == &a || this == &b) { BigUnsigned tmpThis; tmpThis.add(a, b); *this = tmpThis; return; };
	
	if (a.len == 0) {
		operator =(b);
		return;
	} else if (b.len == 0) {
		operator =(a);
		return;
	}
	
	
	bool carryIn, carryOut;
	Blk temp;
	Index i;
	
	const BigUnsigned *a2, *b2;
	if (a.len >= b.len) {
		a2 = &a;
		b2 = &b;
	} else {
		a2 = &b;
		b2 = &a;
	}
	
	len = a2->len + 1;
	allocate(len);
	
	for (i = 0, carryIn = false; i < b2->len; i++) {
		
		temp = a2->blk[i] + b2->blk[i];
		
		
		carryOut = (temp < a2->blk[i]);
		
		if (carryIn) {
			temp++;
			carryOut |= (temp == 0);
		}
		blk[i] = temp; 
		carryIn = carryOut; 
	}
	
	
	for (; i < a2->len && carryIn; i++) {
		temp = a2->blk[i] + 1;
		carryIn = (temp == 0);
		blk[i] = temp;
	}
	
	
	for (; i < a2->len; i++)
		blk[i] = a2->blk[i];
	
	if (carryIn)
		blk[i] = 1;
	else
		len--;
}

void BigUnsigned::subtract(const BigUnsigned &a, const BigUnsigned &b) {
	if (this == &a || this == &b) { BigUnsigned tmpThis; tmpThis.subtract(a, b); *this = tmpThis; return; };
	if (b.len == 0) {
		
		operator =(a);
		return;
	} else if (a.len < b.len)
		
		throw "BigUnsigned::subtract: "
			"Negative result in unsigned calculation";
	
	bool borrowIn, borrowOut;
	Blk temp;
	Index i;
	
	len = a.len;
	allocate(len);
	
	for (i = 0, borrowIn = false; i < b.len; i++) {
		temp = a.blk[i] - b.blk[i];
		
		
		borrowOut = (temp > a.blk[i]);
		
		if (borrowIn) {
			borrowOut |= (temp == 0);
			temp--;
		}
		blk[i] = temp; 
		borrowIn = borrowOut; 
	}
	
	
	for (; i < a.len && borrowIn; i++) {
		borrowIn = (a.blk[i] == 0);
		blk[i] = a.blk[i] - 1;
	}
	


	if (borrowIn) {
		len = 0;
		throw "BigUnsigned::subtract: Negative result in unsigned calculation";
	} else
		
		for (; i < a.len; i++)
			blk[i] = a.blk[i];
	
	zapLeadingZeros();
}



























































inline BigUnsigned::Blk getShiftedBlock(const BigUnsigned &num,
	BigUnsigned::Index x, unsigned int y) {
	BigUnsigned::Blk part1 = (x == 0 || y == 0) ? 0 : (num.blk[x - 1] >> (BigUnsigned::N - y));
	BigUnsigned::Blk part2 = (x == num.len) ? 0 : (num.blk[x] << y);
	return part1 | part2;
}

void BigUnsigned::multiply(const BigUnsigned &a, const BigUnsigned &b) {
	if (this == &a || this == &b) { BigUnsigned tmpThis; tmpThis.multiply(a, b); *this = tmpThis; return; };
	
	if (a.len == 0 || b.len == 0) {
		len = 0;
		return;
	}
	






	
	Index i, j, k;
	unsigned int i2;
	Blk temp;
	bool carryIn, carryOut;
	
	len = a.len + b.len;
	allocate(len);
	
	for (i = 0; i < len; i++)
		blk[i] = 0;
	
	for (i = 0; i < a.len; i++) {
		
		for (i2 = 0; i2 < N; i2++) {
			if ((a.blk[i] & (Blk(1) << i2)) == 0)
				continue;
			












			for (j = 0, k = i, carryIn = false; j <= b.len; j++, k++) {
				



				temp = blk[k] + getShiftedBlock(b, j, i2);
				carryOut = (temp < blk[k]);
				if (carryIn) {
					temp++;
					carryOut |= (temp == 0);
				}
				blk[k] = temp;
				carryIn = carryOut;
			}
			
			
			for (; carryIn; k++) {
				blk[k]++;
				carryIn = (blk[k] == 0);
			}
		}
	}
	
	if (blk[len - 1] == 0)
		len--;
}












void BigUnsigned::divideWithRemainder(const BigUnsigned &b, BigUnsigned &q) {
	




	if (this == &q)
		throw "BigUnsigned::divideWithRemainder: Cannot write quotient and remainder into the same variable";
	

	if (this == &b || &q == &b) {
		BigUnsigned tmpB(b);
		divideWithRemainder(tmpB, q);
		return;
	}

	








	if (b.len == 0) {
		q.len = 0;
		return;
	}

	



	if (len < b.len) {
		q.len = 0;
		return;
	}

	

	



















	
	Index i, j, k;
	unsigned int i2;
	Blk temp;
	bool borrowIn, borrowOut;

	









	Index origLen = len; 
	

	allocateAndCopy(len + 1);
	len++;
	blk[origLen] = 0; 

	
	Blk *subtractBuf = new Blk[len];

	
	q.len = origLen - b.len + 1;
	q.allocate(q.len);
	
	for (i = 0; i < q.len; i++)
		q.blk[i] = 0;

	
	i = q.len;
	while (i > 0) {
		i--;
		
		
		q.blk[i] = 0;
		i2 = N;
		while (i2 > 0) {
			i2--;
			







			for (j = 0, k = i, borrowIn = false; j <= b.len; j++, k++) {
				temp = blk[k] - getShiftedBlock(b, j, i2);
				borrowOut = (temp > blk[k]);
				if (borrowIn) {
					borrowOut |= (temp == 0);
					temp--;
				}
				
				subtractBuf[k] = temp; 
				borrowIn = borrowOut;
			}
			
			
			for (; k < origLen && borrowIn; k++) {
				borrowIn = (blk[k] == 0);
				subtractBuf[k] = blk[k] - 1;
			}
			









			if (!borrowIn) {
				q.blk[i] |= (Blk(1) << i2);
				while (k > i) {
					k--;
					blk[k] = subtractBuf[k];
				}
			} 
		}
	}
	
	if (q.blk[q.len - 1] == 0)
		q.len--;
	
	zapLeadingZeros();
	
	
	delete [] subtractBuf;
}





void BigUnsigned::bitAnd(const BigUnsigned &a, const BigUnsigned &b) {
	if (this == &a || this == &b) { BigUnsigned tmpThis; tmpThis.bitAnd(a, b); *this = tmpThis; return; };
	
	len = (a.len >= b.len) ? b.len : a.len;
	allocate(len);
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = a.blk[i] & b.blk[i];
	zapLeadingZeros();
}

void BigUnsigned::bitOr(const BigUnsigned &a, const BigUnsigned &b) {
	if (this == &a || this == &b) { BigUnsigned tmpThis; tmpThis.bitOr(a, b); *this = tmpThis; return; };
	Index i;
	const BigUnsigned *a2, *b2;
	if (a.len >= b.len) {
		a2 = &a;
		b2 = &b;
	} else {
		a2 = &b;
		b2 = &a;
	}
	allocate(a2->len);
	for (i = 0; i < b2->len; i++)
		blk[i] = a2->blk[i] | b2->blk[i];
	for (; i < a2->len; i++)
		blk[i] = a2->blk[i];
	len = a2->len;
	
}

void BigUnsigned::bitXor(const BigUnsigned &a, const BigUnsigned &b) {
	if (this == &a || this == &b) { BigUnsigned tmpThis; tmpThis.bitXor(a, b); *this = tmpThis; return; };
	Index i;
	const BigUnsigned *a2, *b2;
	if (a.len >= b.len) {
		a2 = &a;
		b2 = &b;
	} else {
		a2 = &b;
		b2 = &a;
	}
	allocate(a2->len);
	for (i = 0; i < b2->len; i++)
		blk[i] = a2->blk[i] ^ b2->blk[i];
	for (; i < a2->len; i++)
		blk[i] = a2->blk[i];
	len = a2->len;
	zapLeadingZeros();
}

void BigUnsigned::bitShiftLeft(const BigUnsigned &a, int b) {
	if (this == &a) { BigUnsigned tmpThis; tmpThis.bitShiftLeft(a, b); *this = tmpThis; return; };
	if (b < 0) {
		if (b << 1 == 0)
			throw "BigUnsigned::bitShiftLeft: "
				"Pathological shift amount not implemented";
		else {
			bitShiftRight(a, -b);
			return;
		}
	}
	Index shiftBlocks = b / N;
	unsigned int shiftBits = b % N;
	
	len = a.len + shiftBlocks + 1;
	allocate(len);
	Index i, j;
	for (i = 0; i < shiftBlocks; i++)
		blk[i] = 0;
	for (j = 0, i = shiftBlocks; j <= a.len; j++, i++)
		blk[i] = getShiftedBlock(a, j, shiftBits);
	
	if (blk[len - 1] == 0)
		len--;
}

void BigUnsigned::bitShiftRight(const BigUnsigned &a, int b) {
	if (this == &a) { BigUnsigned tmpThis; tmpThis.bitShiftRight(a, b); *this = tmpThis; return; };
	if (b < 0) {
		if (b << 1 == 0)
			throw "BigUnsigned::bitShiftRight: "
				"Pathological shift amount not implemented";
		else {
			bitShiftLeft(a, -b);
			return;
		}
	}
	
	
	Index rightShiftBlocks = (b + N - 1) / N;
	unsigned int leftShiftBits = N * rightShiftBlocks - b;
	
	
	if (rightShiftBlocks >= a.len + 1) {
		
		
		len = 0;
		return;
	}
	
	
	len = a.len + 1 - rightShiftBlocks;
	allocate(len);
	Index i, j;
	for (j = rightShiftBlocks, i = 0; j <= a.len; j++, i++)
		blk[i] = getShiftedBlock(a, j, leftShiftBits);
	
	if (blk[len - 1] == 0)
		len--;
}




void BigUnsigned::operator ++() {
	Index i;
	bool carry = true;
	for (i = 0; i < len && carry; i++) {
		blk[i]++;
		carry = (blk[i] == 0);
	}
	if (carry) {
		
		allocateAndCopy(len + 1);
		len++;
		blk[i] = 1;
	}
}


void BigUnsigned::operator ++(int) {
	operator ++();
}


void BigUnsigned::operator --() {
	if (len == 0)
		throw "BigUnsigned::operator --(): Cannot decrement an unsigned zero";
	Index i;
	bool borrow = true;
	for (i = 0; borrow; i++) {
		borrow = (blk[i] == 0);
		blk[i]--;
	}
	
	if (blk[len - 1] == 0)
		len--;
}


void BigUnsigned::operator --(int) {
	operator --();
}
