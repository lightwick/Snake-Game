# Changes Made
1. system("cls") to more efficient function; 
should just use system("cls") for simplicity 
because newly implemented method doesn't call 'cls' often.
2. does not call cls every loop, instead overwrite element that needs to be erased
with " ".
Leave alone where no changes are needed.
3. turned off blinking cursor