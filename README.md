# Wordle Bot

## What it does:
This was a project inspired by [3Blue1Brown's video](https://www.youtube.com/watch?v=v68zYyaEmEA&ab_channel=3Blue1Brown "3B1B's video") on wordle.

## What I learned:
Information Theory - Used Extensively in this algorithm. The main use is to loop though all possible words and determine which would reduce the search pool most optimally.

## Next Steps:
The only things left to do are:
1. Fix behavior of double letters. The algorithm will remove every word with 'O' from the pool dues to the second grey 'O' in <span style="color:blue">*B*</span>.
2. Implement a lookup table.

---
```diff
+ B
+ O
# O
! K
! S
```

