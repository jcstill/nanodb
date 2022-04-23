# nanodb
nanodb is an extremely lightweight database management system

## Memory
Data in the program is simply a list of lists

```
+-+    +-------+----+    +-------+----+    +-------+----+    +-------+----+       
|0| -> |string |char| -> |string |char| -> |string |char| -> |string |char| -> ...
+-+    |colname|type|    |colname|type|    |colname|type|    |colname|type|       
 |     +-------+----+    +-------+----+    +-------+----+    +-------+----+       
 ▼                                                                                
+-+    +----+            +----+            +----+            +----+               
|1| -> |type|         -> |type|         -> |type|         -> |type|         -> ...
+-+    |DATA|            |DATA|            |DATA|            |DATA|               
 |     +----+            +----+            +----+            +----+               
 ▼                                                                                
+-+    +----+            +----+            +----+            +----+               
|2| -> |type|         -> |type|         -> |type|         -> |type|         -> ...
+-+    |DATA|            |DATA|            |DATA|            |DATA|               
 |     +----+            +----+            +----+            +----+               
 ▼                                                                                
+-+    +----+            +----+            +----+            +----+               
|3| -> |type|         -> |type|         -> |type|         -> |type|         -> ...
+-+    |DATA|            |DATA|            |DATA|            |DATA|               
       +----+            +----+            +----+            +----+               
```

## DB File (stored as binary data):

```
00000000: NONE
00000001: char
00000010: unsigned char
00000011: signed char
00000100: int
00000101: unsigned int
00000110: short
00000111: unsigned short
00001000: long
00001001: unsigned long
00001010: float
00001011: double
00001100: long double
00001101: bool
00001110: string (char array)
00001111: 

XXXXXXXX is a 1 byte representation of the column datatype
YY represents the DATA as it is seen in RAM

<number of columns><number of rows(excluding header)>
<COL1NAME AS ASCII>XXXXXXXX<COL2NAME AS ASCII>XXXXXXXX
YYYY...
YYYY...
.
.

```

## DB Example:

### list:
```
+-+    +--------+------+    +--------+--------------+    +------+--------+
|0| -> |"T or F"|"bool"| -> |"number"|"unsigned int"| -> |"name"|"string"|
+-+    +--------+------+    +--------+--------------+    +------+--------+
 ▼
+-+    +------+    +--+    +-------+
|1| -> |"TRUE"| -> |11| -> |"Alice"|
+-+    +------+    +--+    +-------+
 ▼
+-+    +-------+    +--+    +-------+
|2| -> |"FALSE"| -> |63| -> |"Jacob"|
+-+    +-------+    +--+    +-------+
 ▼
+-+    +------+    +---+    +-------+
|2| -> |"TRUE"| -> |172| -> |"Brett"|
+-+    +------+    +---+    +-------+
```
### file:
```
( int 3  cols   ) ( int 3  rows   ) 'T'      ' '      'o'      'r'     
00000000 00000011 00000000 00000011 01010100 00100000 01101111 01110010
' '      'F'      '\0'     bool     'n'      'u'      'm'      'b'       
00100000 01000110 00000000 00001101 01101110 01110101 01101101 01100010
'e'      'r'      '\0'     uns int  'n'      'a'      'm'      'e'       
01100101 01110010 00000000 00000101 01101110 01100001 01101101 01100101
'\0'     string   true     ( uns int 11    ) 'A'      'l'      'i'       
00000000 00001110 00000001 00000000 00001011 01000001 01101100 01101001
'c'      'e'      '\0'     false    ( uns int 63    ) 'J'      'a'       
01100011 01100101 00000000 00000000 00000000 00111111 01001010 01100001
'c'      'o'      'b'      '\0'     true     ( uns int 713   ) 'B'       
01100011 01101111 01100010 00000000 00000001 00000000 10101100 01000010
'r'      'e'      't'      't'      '\0'    
01110010 01100101 01110100 01110100 00000000
```
### or:
```
000000000  00 03 00 03 54 20 6F 72  20 46 00 0D 6E 75 6D 62  |....T or F..numb|
000000010  65 72 00 05 6E 61 6D 65  00 0E 01 00 0B 41 6C 69  |er..name.....Ali|
000000020  63 65 00 00 00 3F 4A 61  63 6F 62 00 01 00 AC 42  |ce....Jacob....B|
000000030  72 65 74 74 00                                    |rett.|
```
