Test blake2b variations.

Have fun!


RESULT
======
See `NULL` and `d`.

Library supports only `NULL` or `0` as third argument if key is zero.

```
OK
   ...
   blake2s_init(&s2, 32, NULL, 0);
   blake2s_done(&s2, out1);
   ...

FAIL
   ...
   blake2s_init(&s2, 32, d, 0);
   blake2s_done(&s2, out1);
   ...

```
