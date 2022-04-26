# Bitwise quick notes of C/C++
The bitwise in Python can see [README](README.md)

## Bitwise Operators in C/C++

- & (bitwise AND): 當兩個位元為1，才返回1
- | (bitwise OR): 當兩個位元其中一個為1，就返回1
- ^ (bitwise XOR): 比對兩個位元，若不同，則返回1
- << (left shift): 按左移動位元
- \>> (right shift): 按右移動位元
- ~ (bitwise NOT): 將所有位元取反<p>

*see* *bit01.c*

## Examples

- 存在一組陣列，找出出現奇數次的數組，例如[12, 12, 14, 90, 14]，則返回90<p>
Tips: XOR相同數組，則為0; Bitwise具有鏈鎖率<p>
*see* *bit02.c*