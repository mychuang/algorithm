# Bitwise quick notes of Python
Refer: https://realpython.com/python-bitwise-operators/
The bitwise in C can see [bitwise_c](bitwise_c.md)
## operator

| Operator | Example | Meaning    |
|----------|---------|------------|
|&         | a & b	 | Bitwise AND|
| \|	   | a \| b	 | Bitwise OR |
| ^        | a ^ b   | Bitwise XOR (exclusive OR)|
|~         | ~a	     | Bitwise NOT|
|<<	       | a << n	 | Bitwise left shift|
|>>	       | a >> n	 | Bitwise right shift|


## compound operator
| Operator | Example | Equivalent to |
|----------|---------|---------------|
| &=       | a &= b	 | a = a & b     |
| \|=	   | a \|= b | a = a \| b    |
| ^=       | a ^= b  | a = a ^ b     |
| <<=      | a <<= n | a = a << n    |
| >>=      | a >>= n | a = a >> n    |

## How Computers Use Binary
One way of knowing how to interpret this information is to designate fixed-length bit patterns for all characters. In modern computing, the smallest unit of information, called an **octet** or a **byte**, comprises eight bits that can store 256 distinct values.

| Character | Decimal Code Point | Binary Code Point |
|-----------|--------------------|-------------------|
| €         |        8364        | 00100000 10101100 |
| u         |         117        | 00000000 01110101 |
| r         |         114        | 00000000 01110010 |


## How Python Use Binary

- Decimal to Binary 

```python
bin(10)
# output: 0b1010
```
- Bit-length

```python
(10).bit_length()
# output: 4
```

- Ascii to Decimal

```python
[ord(character) for character in "Euro"]
# output: [69, 117, 114, 111]
```

## Bitwise AND
可以視為 "product of two bit values" <p>
 (a & b)<sub>i</sub> = a<sub>i</sub> X b<sub>i</sub>

For example:<p>
| Expression | Binary Value | Decimal Value|
|-----------|---------------|--------------|
| a         |  10011100     | 156          |
| b         |  00110100     | 52           |
| a & b     |  00010100     | 20           |

```python
a = 156
b = 52
print(bin(a&b)) # output: 0b10100
print(a&b) # output: 20
```

## Bitwise OR
進行 logical disjunction，如下公式 <p>
 (a | b)<sub>i</sub> = a<sub>i</sub> + b<sub>i</sub> - (a<sub>i</sub> X b<sub>i</sub>) <p>
 簡單來看，每個 bit values，若有至少一個為1，就返回1

For example:<p>
| Expression | Binary Value | Decimal Value|
|-----------|---------------|--------------|
| a         |  10011100     | 156          |
| b         |  00110100     | 52           |
| a & b     |  10111100     | 188          |

```python
a = 156
b = 52
print(bin(a|b)) # output: 0b10111100
print(a|b) # output: 188
```

## Bitwise XOR
返回互斥條件，即比對兩個位元，若不同，則返回1 <p>
 (a ^ b)<sub>i</sub> = (a<sub>i</sub> + b<sub>i</sub>) mod 2 <p>
 簡單來看，每個 bit values，若有至少一個為1，就返回1

For example:<p>
| Expression | Binary Value | Decimal Value|
|-----------|---------------|--------------|
| a         |  10011100     | 156          |
| b         |  00110100     | 52           |
| a ^ b     |  10101000     | 168          |

```python
# python doesn’t have (^), need write a function
def xor(a, b):
    return (a and not b) or (not a and b)
```

## Bitwise NOT
It performs logical negation on a given number by flipping all of its bits
 ~a<sub>i</sub> = 1 - a<sub>i</sub><p>
For example:<p>
| Expression | Binary Value | Decimal Value|
|------------|--------------|--------------|
| a          |  10011100    | 156          |
| ~a         |   1100011    | 99           |
```python
a = 156
print(bin(~a & 255)) # output: 0b1100011
print(~a & 255) # output: 99
```
Note: Python 沒有無符號整數，需要遮罩(&255)來完成此轉換

## Bitwise Shift Operators
常用作掩碼(遮罩)和提高數學運算
<p>

### Left Shift
left shift operator (<<) : 向左移動位數，並補零。<p>
Note: 每向左移動一位，便會加倍一次。
| Expression | Binary Value | Decimal Value|
|------------|--------------|--------------|
| a          |  100111      | 39           |
| a << 1     |  1001110     | 78           |
| a << 2     |  10011100    | 156          |
| a << 3     |  100111000   | 312          |

多數情況下，我們需要將length of a bit pattern限制在8，這是標準字節長度<p>
一樣能透過遮罩(&255)來完成此轉換<p>
```python
print(39 << 3) # Dec: 312
print((39 << 3) & 255) # Dec: 56
```
### Right Shift
right shift operator (>>) : 向右推進指定位數，最右邊的被丟棄。<p>
Note: 每向右移動一位，便會減半一次。
| Expression | Binary Value | Decimal Value|
|------------|--------------|--------------|
| a          |  100111000   | 312          |
| a >> 1     |  10011100    | 156          |
| a >> 2     |  1001110     | 78           |
| a >> 3     |  100111      | 39           |

```python
print(5 >> 1)  # Bitwise right shift: 2
print(5 // 2)  # Floor division (integer division): 2
print(5 / 2)   # Floating-point division: 2.5
```
Note: 正數右移最終為0，負數右移最終為-1

```python
print(2 >> 5)  # Dec: 0
print(-2 >> 5)  # Dec: -1
```

